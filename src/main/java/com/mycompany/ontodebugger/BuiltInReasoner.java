/*
 * Copyright (c) 2019, aidb
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
package com.mycompany.ontodebugger;

import com.google.common.collect.Ordering;
import java.io.FileOutputStream;
import java.io.StringWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Spliterator;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.stream.Collectors;
import java.util.stream.LongStream;
import java.util.stream.Stream;
import one.util.streamex.StreamEx;
import org.apache.commons.lang3.RandomStringUtils;
import org.apache.jena.ext.com.google.common.collect.Comparators;
import org.apache.jena.graph.Triple;
import org.apache.jena.graph.impl.LiteralLabelFactory;
import org.apache.jena.rdf.model.InfModel;
import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.rdf.model.Property;
import org.apache.jena.rdf.model.RDFList;
import org.apache.jena.rdf.model.RDFNode;
import org.apache.jena.rdf.model.Resource;
import org.apache.jena.rdf.model.ResourceFactory;
import org.apache.jena.rdf.model.Statement;
import org.apache.jena.rdf.model.StmtIterator;
import org.apache.jena.rdf.model.impl.StmtIteratorImpl;
import org.apache.jena.reasoner.Reasoner;
import org.apache.jena.reasoner.rulesys.GenericRuleReasonerFactory;
import org.apache.jena.shared.PrefixMapping;
import org.apache.jena.shared.impl.PrefixMappingImpl;
import org.apache.jena.util.PrintUtil;
import org.apache.jena.util.iterator.ExtendedIterator;
import org.apache.jena.util.iterator.Filter;
import org.apache.jena.vocabulary.RDF;
import org.apache.jena.vocabulary.ReasonerVocabulary;
import org.semanticweb.owlapi.model.EntityType;
import org.semanticweb.owlapi.model.IRI;
import org.swrlapi.factory.LiteralFactory;

/**
 *
 * @author aidb
 */
public class BuiltInReasoner {

    static List<VariableState> listToBeReasoned;
    static void process(List<Triple> triples, String spanName, List<String> variables, List<VariableState> stateInfo) {

        // Settings.modelOnlyWithSpans.add(createTriples(triples, spanName, variables, stateInfo));// add timings to nodes
    }

    /*static void reason() {
        Model modelWithSpanProperties = processAsRDFRules(Settings.swrlRulesFile, Settings.modelOnlyWithSpans);
        Settings.modelOnlyWithSpans.add(modelWithSpanProperties);

        try {
            Settings.startTime4 = System.currentTimeMillis();
            saveIntoFile(Settings.modelOnlyWithSpans, Settings.tempFile);
            if (OntologyProcessor.ontology == null) {
                OntologyProcessor.init();
            }
            Settings.endTime4 = System.currentTimeMillis();
            Settings.netTime4 = Settings.endTime4 - Settings.startTime4;

            OntologyProcessor.loadTTLIntoOntology(Settings.tempFile);
        } catch (Exception ex) {
            Logger.getLogger(BuiltInReasoner.class.getName()).log(Level.SEVERE, null, ex);
        }
    }*/

    static void reason2() {
        Settings.netTime4 = 0;
        //Iterator<Map.Entry<String, List<VariableState>>> iterator = CommandProcessor.spanLists.entrySet().iterator();

        IRI[] variables = new IRI[CommandProcessor.spanLists.keySet().size()];
        variables = CommandProcessor.spanLists.keySet().toArray(variables);

        for (int i = 0;  i < variables.length && variables[i] != null; ++i) {
            IRI headIRI = variables[i];
            List<VariableState> span = CommandProcessor.spanLists.get(headIRI);
            //Increasing, Dec, Non-inc, Non-dec

            List<Double> valuesInStream = span.stream().mapToDouble(p -> p.value).boxed().collect(Collectors.toList());

            boolean ordered = Ordering.<Double>natural().isOrdered(valuesInStream);
            boolean strictlyOrdered = Ordering.<Double>natural().isStrictlyOrdered(valuesInStream);
            Ordering<Double> reverse = Ordering.<Double>natural().reverse();
            boolean revOrdered = reverse.isOrdered(valuesInStream);
            boolean revStrictlyOrdered = reverse.isStrictlyOrdered(valuesInStream);
            
            
//List with +ve,-ve,zero, non-versions
            boolean hasPosElement = valuesInStream.stream().anyMatch(p -> p.longValue() > 0);
            boolean hasNegElement = valuesInStream.stream().anyMatch(p -> p.longValue() < 0);
            boolean hasZeroElement = valuesInStream.stream().anyMatch(p -> p.longValue() == 0);
            boolean hasNonPosElement = valuesInStream.stream().anyMatch(p -> p.longValue() <= 0);
            boolean hasNonNegElement = valuesInStream.stream().anyMatch(p -> p.longValue() >= 0);
            boolean hasNonZeroElement = valuesInStream.stream().anyMatch(p -> p.longValue() != 0);
            //List with two distict
            boolean twoDistinct = valuesInStream.stream().distinct().count() >= 2;
            
            if(ordered)
                OntologyProcessor.addClassAssertionAxiom(Settings.DBKeywords.NonDecreasingSpan.iri(), headIRI); 
            if(strictlyOrdered)
                OntologyProcessor.addClassAssertionAxiom(Settings.DBKeywords.IncreasingSpan.iri(), headIRI); 
            if(revOrdered)
                OntologyProcessor.addClassAssertionAxiom(Settings.DBKeywords.NonIncreasingSpan.iri(), headIRI); 
            if(revStrictlyOrdered)
                OntologyProcessor.addClassAssertionAxiom(Settings.DBKeywords.NonDecreasingSpan.iri(), headIRI); 

            
            if(hasPosElement)
                OntologyProcessor.addClassAssertionAxiom(Settings.DBKeywords.SpanWithPositiveElement.iri(), headIRI); 
            if(hasNegElement)
                OntologyProcessor.addClassAssertionAxiom(Settings.DBKeywords.SpanWithNegativeElement.iri(), headIRI); 
            if(hasZeroElement)
                OntologyProcessor.addClassAssertionAxiom(Settings.DBKeywords.SpanWithZeroElement.iri(), headIRI); 
            if(hasNonPosElement)
                OntologyProcessor.addClassAssertionAxiom(Settings.DBKeywords.SpanWithNonPositiveElement.iri(), headIRI); 
            if(hasNonNegElement)
                OntologyProcessor.addClassAssertionAxiom(Settings.DBKeywords.SpanWithNonNegativeElement.iri(), headIRI); 
            if(hasNonZeroElement)
                OntologyProcessor.addClassAssertionAxiom(Settings.DBKeywords.SpanWithNonZeroElement.iri(), headIRI); 
            if(twoDistinct)
                OntologyProcessor.addClassAssertionAxiom(Settings.DBKeywords.SpanWithTwoDistinctElements.iri(), headIRI); 
                
        }
        
        //beforeSpanOf, notEqualSpanOf (6 variations)
        for (int i = 0; i < variables.length && variables[i] != null; ++i) {
            IRI headIRI1 = variables[i];
            List<VariableState> span1 = CommandProcessor.spanLists.get(headIRI1);
            List<Double> valuesInStream1 = span1.stream().mapToDouble(p -> p.value).boxed().collect(Collectors.toList());


            for (int j = 0; j < i; ++j) {
                IRI headIRI2 = variables[j];
                List<VariableState> span2 = CommandProcessor.spanLists.get(headIRI2);
                List<Double> valuesInStream2 = span2.stream().mapToDouble(p -> p.value).boxed().collect(Collectors.toList());

                boolean leq = true, eq = true, neq = true, lt = true, gt = true, geq = true;
                // && l<  valuesInStream2.size() not required because
                //both are equal size
                if (valuesInStream1.size() == valuesInStream2.size()) {
                    for (int k = 0; k < valuesInStream1.size(); ++k) {
                        double e1 = valuesInStream1.get(k);
                        double e2 = valuesInStream2.get(k);
                        if (lt && (!(e1 < e2))) {
                            lt = false;
                        }
                        if (leq && (!(e1 <= e2))) {
                            leq = false;
                        }

                        if (gt && (!(e1 > e2))) {
                            gt = false;
                        }
                        if (geq && (!(e1 >= e2))) {
                            geq = false;
                        }

                        if (eq && (!(e1 == e2))) {
                            eq = false;
                        }

                        if (neq && (!(e1 != e2))) {
                            neq = false;
                        }

                    }
                } else {
                    leq = lt = geq = gt = eq = neq = true;
                }
                //make assertions here
                if(!leq)
                   OntologyProcessor. addPropertyAssertionAxiom(Settings.DBKeywords.notLessThanOrEqualSpanOf.iri(), EntityType.OBJECT_PROPERTY, headIRI1.toString(),headIRI2.toString(),null);   
                if(!lt)
                    OntologyProcessor. addPropertyAssertionAxiom(Settings.DBKeywords.notLessThanSpanOf.iri(), EntityType.OBJECT_PROPERTY, headIRI1.toString(),headIRI2.toString(),null);  
                if(!geq)
                    OntologyProcessor. addPropertyAssertionAxiom(Settings.DBKeywords.notGreaterThanOrEqualSpanOf.iri(), EntityType.OBJECT_PROPERTY, headIRI1.toString(),headIRI2.toString(),null);  
                if(!gt)
                    OntologyProcessor. addPropertyAssertionAxiom(Settings.DBKeywords.notGreaterThanSpanOf.iri(), EntityType.OBJECT_PROPERTY, headIRI1.toString(),headIRI2.toString(),null);  
                if(!eq)
                    OntologyProcessor. addPropertyAssertionAxiom(Settings.DBKeywords.notEqualSpanOf.iri(), EntityType.OBJECT_PROPERTY, headIRI1.toString(),headIRI2.toString(),null);  
                if(!neq)
                    OntologyProcessor. addPropertyAssertionAxiom(Settings.DBKeywords.notNonEqualSpanOf.iri(), EntityType.OBJECT_PROPERTY, headIRI1.toString(),headIRI2.toString(),null);  
            }
            
            
        }
        
        //before span code
        if(CommandProcessor.spanLists.keySet().size() >=2)
        for (int i = 0; i < variables.length; ++i) {
            
            IRI headIRI1 = variables[i];
            List<VariableState> span1 = CommandProcessor.spanLists.get(headIRI1);
            List<Long> timeInStream1 = span1.stream().mapToLong(p -> p.time).boxed().collect(Collectors.toList());
            
            
            for (int j = 0; j < i; ++j) {
                IRI headIRI2 = variables[j];
                List<VariableState> span2 = CommandProcessor.spanLists.get(headIRI2);
                List<Long> timeInStream2 = span2.stream().mapToLong(p -> p.time).boxed().collect(Collectors.toList());
boolean bs = true;
                // && l<  valuesInStream2.size() not required because
                //both are equal size
                if (timeInStream1.size() == timeInStream2.size()) {
                    for (int k = 0; k < timeInStream1.size(); ++k) {
                        long e1 = timeInStream1.get(k);
                        long e2 = timeInStream2.get(k);
                        if (bs && (!(e1 < e2))) {
                            bs = false;
                        }
                        
                    }
                } else {
                    bs = false;
                }
                
                //make assertions here
            if(bs)
                OntologyProcessor. addPropertyAssertionAxiom(Settings.DBKeywords.beforeSpanOf.iri(), EntityType.OBJECT_PROPERTY, headIRI1.toString(),headIRI2.toString(),null);  
       
            }
             }
        
    }

    static Model createTriples(List<Triple> triples, String spanName, List<String> variables, List<VariableState> stateInfo) {
        // Span(?spanName), hasItem(?spanName,?item), correspondsTo(?item,?var),
        //filteredItemFromTime(?item, ?fromTime), filteredItemEndsAtTime(?item, ?toTime).
        Model model = ModelFactory.createDefaultModel();
        triples.add(Utils.createTriple(spanName, RDF.type.getURI(), Settings.DBKeywords.Span.uri()));

        for (String var : variables) {

            /*  List<RDFNode> oneVarStates = sparqlResult.stream().filter(p -> p.get(varQueryVariable).toString().equals(var)).
            sorted((o1, o2) -> Integer.compare(o1.get(timeQueryVariable).asLiteral().getInt(), o2.get(timeQueryVariable).asLiteral().getInt())).
            map(p -> p.get(valQueryVariable)).
            collect(Collectors.toList());
             */
            List<VariableState> collect = stateInfo.stream().distinct().filter(p -> p.var.equals(var) && p.valueNode != null).
                    sorted((o1, o2) -> Integer.compare(o1.time, o2.time)).collect(Collectors.toList());

            //  List<RDFNode> oneVarStates = collect.stream().map(p-> p.valueNode).collect(Collectors.toList());
            //  addPrefix(oneVarStates);
            RDFList oneVarStateList = createList(collect.iterator(), Settings.prefix + "#", model, spanName);
            // addNodeProperties(oneVarStates,collect);
            Resource headOfList = oneVarStateList.getHead().asResource();
            String headOfListURI = headOfList.toString();

            // triples.add(Utils.createTriple(spanName, Settings.DBKeywords.hasItem.uri(), headOfListURI));
            triples.add(Utils.createTriple(headOfListURI, Settings.DBKeywords.correspondsTo.uri(), var));
            //  triples.add(Utils.createTriple(spanURI, DBKeywords.filteredItemBeginsAtTime.uri(),Integer.parseInt(fromTime)));
            //  triples.add(Utils.createTriple(spanURI, DBKeywords.filteredItemEndsAtTime.uri(), Integer.parseInt(toTime)));
            boolean hasDuplicates = Utils.containsDuplicates(collect);
            if (hasDuplicates) {
                triples.add(Utils.createTriple(headOfListURI, RDF.type.getURI(), Settings.DBKeywords.SpanWithDuplicates.uri()));
            } else {
                triples.add(Utils.createTriple(headOfListURI, RDF.type.getURI(), Settings.DBKeywords.SpanWithoutDuplicates.uri()));
            }

            model.add(oneVarStateList.getModel());

        }
        for (Triple tr : triples) {
            model.add(model.asStatement(tr));
        }

        return model;
    }

    private static void addNodeProperties(List<RDFNode> oneVarStates, List<VariableState> collect) {

    }

    private static void addPrefix(List<RDFNode> oneVarStates) {

    }

    static RDFList createList(Iterator<VariableState> members, String nameSpace, Model model, String spanName) {
        //if (!members.hasNext())
        //  return createList();

        Property tsResource = ResourceFactory.createProperty(Settings.DBKeywords.timestamp.uri());
        VariableState nextvs = members.next();
        RDFNode next = nextvs.valueNode;

        //Resource tempRoot = new ResourceImpl(nameSpace, localName);
        //Resource root = createResource(tempRoot.toString());
        //Resource root = model.createResource(nameSpace + RandomStringUtils.random(8, "0123456789abcdef"));
        //model.createResource(nameSpace)
        Resource root = model.getResource(spanName);

        root.addProperty(RDF.type, RDF.List);
        root.addProperty(RDF.first, next.asLiteral().getLexicalForm());
        root.addProperty(tsResource, LiteralLabelFactory.createTypedLiteral(nextvs.time).toString());

        //Resource root = createResource().addProperty(RDF.first, members.next());
        Resource last = root;
        while (members.hasNext()) {
            // Resource rest = createResource().addProperty(RDF.first, members.next());
            Resource rest = model.createResource(nameSpace + RandomStringUtils.random(8, "0123456789abcdef"));
            rest.addProperty(RDF.type, RDF.List);

            nextvs = members.next();
            next = nextvs.valueNode;

            rest.addProperty(RDF.first, next.asLiteral().getLexicalForm());
            rest.addProperty(tsResource, LiteralLabelFactory.createTypedLiteral(nextvs.time).toString());

            last.addProperty(RDF.rest, rest);
            last = rest;
        }
        last.addProperty(RDF.rest, RDF.nil);

        return root.as(RDFList.class);
    }

    static Model processAsRDFRules(String fileloc, Model modelIn) {
        // create a simple model; create a resource  and add rules from a file 
//Settings.startTimeForQuery = System.currentTimeMillis();
        Model m = ModelFactory.createDefaultModel();
        Resource configuration = m.createResource();
        configuration.addProperty(ReasonerVocabulary.PROPruleSet, fileloc);
        configuration.addProperty(ReasonerVocabulary.PROPruleMode, "forwardRETE");

        // Create an instance of a reasoner 
        Reasoner reasoner
                = GenericRuleReasonerFactory.theInstance().create(configuration);

        // reasoner.setParameter(ReasonerVocabulary.PROPtraceOn, true);
        // Now with the rawdata model & the reasoner, create an InfModel 
        InfModel infmodel = ModelFactory.createInfModel(reasoner, modelIn);
        /*   System.out.println( "inferred size"+ infmodel.size());
         Settings.endTimeForQuery = System.currentTimeMillis();
        Settings.netTimeForQuery = Settings.endTimeForQuery - Settings.startTimeForQuery;
        System.out.println( "\n RDF reasoner time" + Settings.netTimeForQuery + " milliseconds");
         */
        return infmodel;
    }

    public static void printInferredStatements(final Model baseModel, Model inferred) {

        // An iterator over the statements of pModel that *aren't* in the base model.
        ExtendedIterator<Statement> stmts = inferred.listStatements().filterDrop(new Filter<Statement>() {
            @Override
            public boolean accept(Statement o) {
                return baseModel.contains(o);
            }
        });

//ExtendedIterator<Statement> stmts = null;
        Model deductions = ModelFactory.createDefaultModel().add(new StmtIteratorImpl(stmts));

        //PrintUtil.registerPrefix("x", "http://www.codesupreme.com/#"); 
        for (StmtIterator i = deductions.listStatements(); i.hasNext();) {
            Statement stmt = i.nextStatement();
            System.out.println(PrintUtil.print(stmt));
        }
        System.out.println("count:" + deductions.listStatements().toList().size());
    }

    private static void saveIntoFile(Model modelOnlyWithSpans, String tempFile) throws Exception {
        PrefixMapping pm = new PrefixMappingImpl();
        modelOnlyWithSpans.setNsPrefixes(PrefixMapping.Standard);
        modelOnlyWithSpans.setNsPrefix("xsd", "http://www.w3.org/2001/XMLSchema#");
        modelOnlyWithSpans.setNsPrefix("c", "http://www.semanticweb.org/yzhao30/ontologies/2015/7/c#");
        //modelOnlyWithSpans.setNsPrefix("pa", "http://www.w3.org/2001/XMLSchema#");
        modelOnlyWithSpans.setNsPrefix("pdo", "http://www.semanticweb.org/aidb/ontologies/ProgramDebuggingOntology#");
        modelOnlyWithSpans.setNsPrefix("file0", Settings.prefix + "#");
        Map<String, String> nsPrefixMap = modelOnlyWithSpans.getNsPrefixMap();
        pm.setNsPrefixes(nsPrefixMap);

        // modelOnlyWithSpans.t
        List<String> tripleLines = new ArrayList<>();
        StmtIterator sts = modelOnlyWithSpans.listStatements();
        String s, s2;
        /*  while(sts.hasNext()){
             Triple tr = sts.next().asTriple();
             s = tr.toString(pm);
             String[] split = s.split("\\s");
             StringBuilder sb = new StringBuilder();
             if(tr.getSubject().isBlank())
             sb.append("file0:" + split[0]);
             else
                 sb.append(split[0]);
             sb.append(" ").append(split[1].replaceAll("rdf:", "pdo:rdf").replaceAll("@", ""))
                     .append(" ");
             if(tr.getObject().isBlank())
                 sb.append("file0:" + split[2]);
             else
                 sb.append(split[2]);
            
             tripleLines.add(sb.toString() + " .");
         }*/

        //PrintUtil.registerPrefix("xsd", "http://www.w3.org/2001/XMLSchema#");
        while (sts.hasNext()) {

            s = PrintUtil.print(sts.next()).replaceAll("^\\(|\\)$", "");
            // s = sts.next().asTriple().toString();
            //s = sts.next().asTriple().toString(pm);
            s2 = s.replaceAll("(rdf):(first|rest|List|nil)", "<" + Settings.dbPrefix + "$1$2>").replaceAll("@", "");
            String s3 = s2.replaceAll("'", "\"").replaceAll("http://www.w3.org/2001/XMLSchema#", "xsd:");

            tripleLines.add(s3 + " .");
        }

        StringWriter codeFileWriter = Utils.createDebugCommandsFile(tripleLines);

        try (FileOutputStream outputStream = new FileOutputStream(tempFile)) {
            // outputStream.write(Utils.getHeaderWithFile0().getBytes());
            outputStream.write(codeFileWriter.toString().trim().getBytes());
        }

    }

    static void reasonWithoutOntology(CommandList commands) {
       // Settings.netTime4 = 0;
        
        Command reasoningCmd = commands.get(0);
        Settings.ReasoningFunctors reasoningCommandEnum = reasoningCmd.reasoningFuncEnum;
        //CommandProcessor.variableStateLists
        IRI firstIRI , secondIRI ;
        List<VariableState> span1, span2;
        List<Double> valuesInStream1, valuesInStream2;
        if(reasoningCmd.argsWithURI.size() == 1){
        firstIRI = IRI.create(reasoningCmd.argsWithURI.get(0));
        //span1 = CommandProcessor.spanLists.keySet().stream().filter(p -> p.equals(firstIRI)).findFirst().get();
        span1 = CommandProcessor.spanLists.get(firstIRI);
        valuesInStream1 = span1.stream().mapToDouble(p -> p.value).boxed().collect(Collectors.toList());
        }
        else {
            firstIRI = IRI.create(reasoningCmd.argsWithURI.get(0));
            secondIRI = IRI.create(reasoningCmd.argsWithURI.get(1));
        span1 = CommandProcessor.spanLists.get(firstIRI);
        span2 = CommandProcessor.spanLists.get(secondIRI);
        valuesInStream1 = span1.stream().mapToDouble(p -> p.value).boxed().collect(Collectors.toList());
        valuesInStream2 = span2.stream().mapToDouble(p -> p.value).boxed().collect(Collectors.toList());
        }
        
     boolean propertyStatus = verifyPropertyForBuiltInReasoner(valuesInStream1, reasoningCommandEnum);
        System.out.println(reasoningCommandEnum + " " + propertyStatus);
        
       
    }

    static boolean verifyPropertyForBuiltInReasoner(List<Double> valuesInStream1, Settings.ReasoningFunctors reasoningCommandEnum) {
        Ordering<Double> reverse = Ordering.<Double>natural().reverse();
        boolean hasDuplicates = !valuesInStream1.stream().allMatch(new HashSet<>()::add);
        if(reasoningCommandEnum == Settings.ReasoningFunctors.NonDecreasingSpan)
            return Ordering.<Double>natural().isOrdered(valuesInStream1);
        else if(reasoningCommandEnum == Settings.ReasoningFunctors.IncreasingSpan)
            return Ordering.<Double>natural().isStrictlyOrdered(valuesInStream1);
        else if(reasoningCommandEnum == Settings.ReasoningFunctors.NonIncreasingSpan)
            return reverse.isOrdered(valuesInStream1);
        else if(reasoningCommandEnum == Settings.ReasoningFunctors.DecreasingSpan)
            return reverse.isStrictlyOrdered(valuesInStream1);
        else if(reasoningCommandEnum == Settings.ReasoningFunctors.AllDistinctSpan)
            return !hasDuplicates;
        else if(reasoningCommandEnum == Settings.ReasoningFunctors.AllNonZeroSpan)
            return !valuesInStream1.contains(0);
        else if(reasoningCommandEnum == Settings.ReasoningFunctors.AllPostiveSpan)
            return !valuesInStream1.stream().noneMatch(p -> p <= 0);
        else if(reasoningCommandEnum == Settings.ReasoningFunctors.AllNegativeSpan)
            return !valuesInStream1.stream().noneMatch(p -> p >= 0);
        else if(reasoningCommandEnum == Settings.ReasoningFunctors.AllNonPositiveSpan)
            return !valuesInStream1.stream().noneMatch(p -> p < 0);
        else if(reasoningCommandEnum == Settings.ReasoningFunctors.AllNonNegativeSpan)
            return !valuesInStream1.stream().noneMatch(p -> p > 0);
        else if(reasoningCommandEnum == Settings.ReasoningFunctors.notEqualSpanOf){
        }
        
        
        
        return false;
    }

    static void reasonForDefaultAbstractions(CommandList commands) {
        Command reasoningCmd = commands.get(0);
        String span1Name = reasoningCmd.args.get(0);
        String span2Name = reasoningCmd.args.get(1);
        Settings.ReasoningFunctors reasoningCommandEnum = reasoningCmd.reasoningFuncEnum;
        
       SessionSpan span1 = Session.sessionSpans.stream().
               filter(p -> p.spanNameShort.equals(span1Name)).findFirst().get();
       
       SessionSpan span2 = Session.sessionSpans.stream().
               filter(p -> p.spanNameShort.equals(span2Name)).findFirst().get();
       
       boolean returnValue = false;
       if(reasoningCommandEnum == Settings.ReasoningFunctors.anyExistsAfterTime){
           returnValue = anyExists(span1,span2);
       } else if(reasoningCommandEnum == Settings.ReasoningFunctors.exactlyOneExists){
           returnValue = exactlyOneExists(span1,span2);
       } else if(reasoningCommandEnum == Settings.ReasoningFunctors.contiguousCells){
           returnValue = contiguousCells(span1,span2);
       } else if(reasoningCommandEnum == Settings.ReasoningFunctors.anyExistsBeforeTime){
           returnValue = anyExistsBeforeTime(span1,span2);
       }
       
       System.out.println(reasoningCommandEnum + " " + span1Name + " " + span2Name + 
                   "\n" + returnValue);
    }

    private static boolean anyExists(SessionSpan span1, SessionSpan span2) {
        boolean  ret = true;
        for(int i=0; i < span1.stateInfo.size(); ++i){
            VariableState vs = span1.stateInfo.get(i);
            if(!span2.stateInfo.stream().anyMatch(p -> p.var.equals(vs.var) 
                    && p.value.longValue() == vs.value.longValue()
                    && vs.time < p.time)){
                System.out.println("Match not found:" + vs.var + ":" + vs.st);
                ret = false;
            }
        }
        return ret;
    }

    private static boolean exactlyOneExists(SessionSpan span1, SessionSpan span2) {
       boolean  ret = true;
        for(int i=0; i < span1.stateInfo.size(); ++i){
            VariableState vs = span1.stateInfo.get(i);
            if(span2.stateInfo.stream().filter(p -> p.var.equals(vs.var) 
                    && p.value.longValue() == vs.value.longValue()
                    && vs.time < p.time).count() != 1){
                System.out.println("Match not found:" + vs.var + ":" + vs.st);
                ret = false;
            }
        }
        return ret;
    }

    private static boolean contiguousCells(SessionSpan span1, SessionSpan span2) {
        boolean  ret = true;
        for(int i=0; i < span1.stateInfo.size() - 1; ++i){
            VariableState vs1 = span1.stateInfo.get(i);
            VariableState vs2 = span1.stateInfo.get(i+1);
            if(!span2.stateInfo.stream().anyMatch(p -> p.var.equals(vs1.var) 
                    && p.value.longValue() == vs1.value.longValue() && p.var.equals(vs2.var) &&
                    p.value.longValue() == vs2.value.longValue() && p.time > vs1.time && p.time < vs2.time) ){
                System.out.println("Match not found:" + vs1.var + ":" + vs1.st);
                ret = false;
            }
        }
        return ret;
    }

    private static boolean anyExistsBeforeTime(SessionSpan span1, SessionSpan span2) {
        boolean  ret = true;
        for(int i=0; i < span1.stateInfo.size(); ++i){
            VariableState vs = span1.stateInfo.get(i);
            if(!span2.stateInfo.stream().anyMatch(p -> p.var.equals(vs.var) 
                    && p.value.longValue() == vs.value.longValue()
                    && vs.time > p.time)){
                System.out.println("Match not found:" + vs.var + ":" + vs.st);
                ret = false;
            }
        }
        return ret;
    }

}
