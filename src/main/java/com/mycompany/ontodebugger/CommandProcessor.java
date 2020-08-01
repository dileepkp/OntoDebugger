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

import org.apache.jena.reasoner.rulesys.Util.*;
import com.mycompany.ontodebugger.Settings.DBKeywords;
import com.mycompany.ontodebugger.Settings.RDFKeywords;
import com.mycompany.ontodebugger.Settings.WorkingModel;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.UUID;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.stream.Collectors;
import org.apache.jena.graph.Node;
import org.apache.jena.graph.NodeFactory;
import org.apache.jena.graph.Triple;
import org.apache.jena.query.Query;
import org.apache.jena.query.QuerySolution;
import org.apache.jena.rdf.model.Literal;
import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.rdf.model.RDFList;
import org.apache.jena.rdf.model.RDFNode;
import org.apache.jena.rdf.model.Resource;
import org.apache.jena.rdf.model.impl.PropertyImpl;
import org.apache.jena.rdf.model.impl.ResourceImpl;
//import org.semarglproject.vocab.RDF;
import org.apache.jena.vocabulary.*;
import org.semanticweb.owlapi.model.AddAxiom;
import org.semanticweb.owlapi.model.EntityType;
import org.semanticweb.owlapi.model.IRI;
import org.semanticweb.owlapi.model.OWLAxiom;
import org.semanticweb.owlapi.model.OWLClass;
import org.semanticweb.owlapi.model.OWLDataFactory;
import org.semanticweb.owlapi.model.OWLIndividual;
import org.semanticweb.owlapi.model.OWLLiteral;
import org.semanticweb.owlapi.model.OWLObjectProperty;
import org.semanticweb.owlapi.model.OWLOntology;
import org.semanticweb.owlapi.model.OWLOntologyManager;
import org.semanticweb.owlapi.vocab.OWLRDFVocabulary;
import org.apache.commons.lang3.RandomStringUtils;
import org.apache.jena.query.ResultSetFormatter;
import org.apache.jena.reasoner.rulesys.Util;
import org.apache.xerces.impl.xpath.regex.REUtil;
/**
 *
 * @author aidb
 */
public class CommandProcessor {
    
      static String varQueryVariable = "?var";
        static String valQueryVariable = "?val";
        static String timeQueryVariable = "?time";
        static String spaceQueryVariable = "?st";

    //1. First process hasItem -> getVariables
    //2. Process CreateSlice/CreateFilteredSlice
    //3. Process CreateFilter
    static Boolean process(CommandList commands) {
        
      /*  Model model = ModelFactory.createDefaultModel();
        List<String> variables = commands.getVariables(); 
        Command cmd = commands.getFilteredSliceCmd();
         if(cmd==null) return ModelFactory.createDefaultModel();
       CreateFilteredSlice2(model,cmd,variables);
        return model;
        */
      
      
      Settings.Abstractions ab = commands.process();
      if(ab == Settings.Abstractions.ValueSpan){
          createValueSpan((SpanCommandList)commands.cl);
     }else if (ab == Settings.Abstractions.ProgStateSpan){
         
          createProgStateSpan((ProgStateSpanCommandList)commands.cl);
     }else if (ab == Settings.Abstractions.SimulationSession){
         
         return Session.processDebugCommandQuery((BreakPointCommandList)commands.bpcl);// There can be atmost 1 sparql queries
     }
      /*else if(ab == Settings.Abstractions.SpanWithFilter){
          createValueSpan(commands.scl,model);
     }
      else return ModelFactory.createDefaultModel();
      return model;*/
        return true;
    }
    
    private static void createProgStateSpan(ProgStateSpanCommandList scl) {
         List<String> variables = null;
         String spanName = scl.spanName.replaceAll("file0:", Settings.prefix+"#");
         if(Session.sessionSpans.stream().anyMatch(p -> p.spanNameShort.equals(scl.spanName)))
                 return;
         
      List<VariableState> stateInfo = new ArrayList<>();
       List<QuerySolution> sparqlResult;
        String origQuery = ReadInput.readInstrumentationQuery(scl.queryIdInXML);
        origQuery= origQuery.replaceAll("zz_pos", scl.position);
       origQuery= origQuery.replaceAll("zz_st", scl.funcName);
       //System.out.println(origQuery);
       //Sparql.executeQueryAndPrint(origQuery, Settings.modelWithProgramAndTrace,true);
          sparqlResult = Sparql.executeQuery(origQuery, Settings.modelWithProgramAndTrace);
           //List<VariableState> stateInfoTemp = new ArrayList<>();
        
        sparqlResult.stream().forEach( p-> stateInfo.add(
                new VariableState(p.get(varQueryVariable).toString(),
                        p.get(spaceQueryVariable).toString(), p.get(timeQueryVariable),
                        p.get(valQueryVariable))));
         Collections.sort(stateInfo, Comparator.comparingInt((VariableState l) -> l.time));
         VariableState.process(stateInfo);
         //for(VariableState vs: stateInfo){
           //  System.out.println(vs.var +":" + vs.value.toString() +":" + Integer.toString(vs.time));
         //}
         Session.sessionSpans.add(new SessionSpan(scl.spanName,stateInfo));
    }

    
    private static void createValueSpan(SpanCommandList scl) {
        List<String> variables = null;
       // List<Triple> triples = new ArrayList<>();
        String spanName = scl.spanName.replaceAll("file0:", Settings.prefix+"#");;
       // String fromTime = scl.fromTime;
       // String toTime = scl.toTime;
        
       // String progStateQuery = null;
      /*  if(scl.containsTime() && scl.containsStatements())
            progStateQuery= ReadInput.readQueryWithParameters("constructSpanBasedOnTimeAndSpace", scl);
        else if(scl.containsTime())
            progStateQuery= ReadInput.readQueryWithParameters("constructSpanBasedOnTime", scl);
        else if(scl.containsStatements())
            progStateQuery= ReadInput.readQueryWithParameters("constructSpanBasedOnSpace", scl);
        */
      List<VariableState> stateInfo;
       List<QuerySolution> sparqlResult;
        sparqlResult = executeQueryForSpan(scl);
        //ResultSetFormatter.out(sparqlResult);
        
        stateInfo = getStateInformationForSpan(sparqlResult,scl);
        
        // for(VariableState vs: stateInfo)
          //  System.out.println(vs.value + " " + vs.time);
      // stateInfo.forEach(p -> System.out.println(p.var+":"+ p.st + ":" + p.value.toString()));
        if(variables == null)
            variables = sparqlResult.stream().map(p -> p.get(varQueryVariable).toString()).
                    distinct().collect(Collectors.toList());

       /* if(Settings.workingModel == WorkingModel.listOWLRL){
            RDFRulesProcessor.process(triples, spanName, variables, stateInfo);
        }
        else{*/
            
            
            try {
                   Settings.startTime3 = System.currentTimeMillis();
          
                if(OntologyProcessor.ontology == null)
                OntologyProcessor.init();
                  Settings.endTime3 = System.currentTimeMillis();
        Settings.netTime3 += Settings.endTime3 - Settings.startTime3;
        
       // System.out.println("Before" + OntologyProcessor.ontology.getAxiomCount());
            if(Settings.workingModel == WorkingModel.listSWRL || 
                    Settings.workingModel == WorkingModel.listOWLRL ||
                    Settings.workingModel == WorkingModel.reasoningWithoutOntology)
                createTriplesInOWL( spanName, variables, stateInfo);
            else  if(Settings.workingModel == WorkingModel.setSWRL)
                createTriplesInOWL_SetModel( spanName, variables, stateInfo);
         //   else if (Settings.workingModel == WorkingModel.reasoningWithoutOntology)
          //      createListsForBuiltInReasoning(variables,stateInfo);
            
            //    System.out.println("After" + OntologyProcessor.ontology.getAxiomCount());
            } catch (Exception ex) {
                Logger.getLogger(CommandProcessor.class.getName()).log(Level.SEVERE, null, ex);
            }
        //}
        //    createTriplesInOWL
    }

    static List<VariableState> getStateInformationForSpan(List<QuerySolution> sparqlResult,   SpanCommandList scl) {
        // for(QuerySolution qs : sparqlResult)
        //    System.out.println(qs.get(valQueryVariable));
        List<VariableState> stateInfoTemp = new ArrayList<>();
        List<VariableState> stateInfo = new ArrayList<>();
       
        sparqlResult.stream().forEach( p-> stateInfoTemp.add(
                new VariableState(p.get(varQueryVariable).toString(),
                        p.get(spaceQueryVariable).toString(), 
                        p.get(timeQueryVariable).toString(),
                        p.get(valQueryVariable).toString())));
        VariableState.process(stateInfoTemp);
        //VariableState.print(stateInfoTemp);
        List<VariableState> stateInfoTemp2;
        if(scl.reuseTimingQueryResult)
            stateInfoTemp2 = stateInfoTemp;
        else if(scl.containsStatements())
            stateInfoTemp2 = stateInfoTemp.stream().filter(p -> scl.stsInSpanList.contains(Utils.shortURI(p.st))
                    && scl.varsInSpan.contains(Utils.shortURI(p.var))).collect(Collectors.toList());
        else //if(scl.containsTime())
            stateInfoTemp2 = stateInfoTemp.stream().filter(p ->
                    scl.varsInSpan.contains(Utils.shortURI(p.var))).collect(Collectors.toList());
        //stateInfoTemp.forEach(p -> System.out.println(p.var+":"+ p.st + ":" + p.value.toString()));
        
        /*if(scl.hasFilter){
        VariableState.applyFilter(stateInfoTemp2,scl.filter);
        stateInfo = stateInfoTemp2.stream().filter(p -> !p.removeAfterFilter).collect(Collectors.toList());
        }
        else*/
        if (scl.expression){
            VariableState.applyMap(stateInfoTemp2,scl.map);
        } else if(!scl.reuseTimingQueryResult && scl.timingInstantCmd != null){
            stateInfo = VariableState.adjustBasedOnTimeInstant(stateInfoTemp2, scl.timeList,scl.timingInstantCmd.args.get(1));
        }
        else stateInfo = stateInfoTemp2;
        return stateInfo;
    }

    static List<QuerySolution> executeQueryForSpan(SpanCommandList scl) {
        List<QuerySolution> sparqlResult;
        String progStateQuery;
        if(scl.reuseTimingQueryResult){
            sparqlResult = scl.timingQueryResult;
        }
        else{
            
            Settings.startTimeForQuery = System.currentTimeMillis();
           /* if(scl.containsTime())
                progStateQuery= ReadInput.readQueryWithParameters("constructSpanBasedOnTime", scl);
            else progStateQuery= ReadInput.readQueryWithParameters("constructSpanBasedOnVarsAndSpace", scl);
            
            sparqlResult = Sparql.executeQuery(progStateQuery, Settings.modelWithProgramAndTrace);
            //System.out.println(progStateQuery);
            //Sparql.executeQueryAndPrint(progStateQuery, Settings.modelWithProgramAndTrace,true);
            */
           if(scl.containsTime()){
               sparqlResult = Sparql.executeQueryUsingHashing(scl.varsInSpan, scl.fromTime,scl.toTime);
           }else{
               sparqlResult = Sparql.executeQueryUsingHashing(scl.varsInSpan, scl.stsInSpanList);
           }
            Settings.endTimeForQuery = System.currentTimeMillis();
            Settings.netTimeForQuery += Settings.endTimeForQuery - Settings.startTimeForQuery;
            System.out.println( "\n Query time (this is cumulative query time)" + Settings.netTimeForQuery + " milliseconds");
            
            // Sparql.executeQueryAndPrint(progStateQuery,Settings.modelWithProgramAndTrace);
        }return sparqlResult;
    }

    
   private static void createTriplesInOWL_SetModel(String spanName, List<String> variables, List<VariableState> stateInfo) {
        IRI spanIRI = IRI.create(spanName);
       // if(spanName.endsWith("1"))
       // OntologyProcessor.addClassAssertionAxiom(DBKeywords.ValueSpan.iri(), spanIRI );
         
        for(String var: variables){
            
            List<VariableState> collect = stateInfo.stream().filter(p -> p.var.equals(var) && p.valueNode != null).filter(Utils.distinctByKey(p -> p.time)).
                    sorted((o1,o2) -> Integer.compare(o1.time, o2.time)).collect(Collectors.toList());
                       
              OntologyProcessor.createSet(collect.iterator(),spanIRI);
              OntologyProcessor.addPropertyAssertionAxiom(DBKeywords.correspondsTo.iri(),EntityType.OBJECT_PROPERTY, spanIRI.toString(), var,null);
            
        }
        //if(spanName.endsWith("2"))
        OntologyProcessor.addClassAssertionAxiom(DBKeywords.Span.iri(), spanIRI );
         
    }
   public static Map<IRI,List<VariableState>> spanLists = new HashMap<>();
   public static Map<String,List<VariableState>> variableStateLists = new HashMap<>();
     private static void createTriplesInOWL( String spanName, List<String> variables, List<VariableState> stateInfo) {
        // ValueSpan(?spanName), hasItem(?spanName,?item), correspondsTo(?item,?var),
        //filteredItemFromTime(?item, ?fromTime), filteredItemEndsAtTime(?item, ?toTime).
        //triples.add(Utils.createTriple(spanName, RDF.type.getURI(), DBKeywords.ValueSpan.uri()));
         
        OntologyProcessor.addClassAssertionAxiom(DBKeywords.Span.iri(), IRI.create(spanName));
         
        for(String var: variables){
            
            
            /*  List<RDFNode> oneVarStates = sparqlResult.stream().filter(p -> p.get(varQueryVariable).toString().equals(var)).
            sorted((o1, o2) -> Integer.compare(o1.get(timeQueryVariable).asLiteral().getInt(), o2.get(timeQueryVariable).asLiteral().getInt())).
            map(p -> p.get(valQueryVariable)).
            collect(Collectors.toList());
            */
            List<VariableState> collect = stateInfo.stream().filter(p -> p.var.equals(var) && p.valueNode != null).filter(Utils.distinctByKey(p -> p.time)).
                    sorted((o1,o2) -> Integer.compare(o1.time, o2.time)).collect(Collectors.toList());
            
            //List<RDFNode> oneVarStates = collect.stream().map(p-> p.valueNode).collect(Collectors.toList());
            //addPrefix(oneVarStates);
         // System.out.println("Size of span:" + collect.size());
            
            /* 
            RDFList oneVarStateList = createList(oneVarStates.iterator(),Settings.prefix +"#",model);
            addNodeProperties(oneVarStates,collect);
            Resource headOfList = oneVarStateList.getHead().asResource();
            String spanURI =  headOfList.toString();
            
            triples.add(Utils.createTriple(spanName, DBKeywords.hasItem.uri(), spanURI));
            triples.add(Utils.createTriple(spanURI, DBKeywords.correspondsTo.uri(),var));
            */
            //collect.forEach(p -> System.out.println(p.var+":"+ p.st + ":" + p.time +":" + p.value.toString()));
             String headOfListURI =  OntologyProcessor.createList(collect.iterator(),spanName);
              OntologyProcessor.addPropertyAssertionAxiom(DBKeywords.correspondsTo.iri(),EntityType.OBJECT_PROPERTY, headOfListURI, var,null);
              boolean hasDuplicates = Utils.containsDuplicates(collect);
              if(hasDuplicates){
                OntologyProcessor.addClassAssertionAxiom(Settings.DBKeywords.SpanWithDuplicates.iri(), IRI.create(headOfListURI)); 
              }else
                  OntologyProcessor.addClassAssertionAxiom(Settings.DBKeywords.SpanWithoutDuplicates.iri(), IRI.create(headOfListURI)); 
              
           //   if(Settings.workingModel == WorkingModel.listOWLRL)
           //       addPrimitiveConcepts(collect,IRI.create(headOfListURI) );
              spanLists.put(IRI.create(headOfListURI), collect);
              
            //OntologyProcessor.addPropertyAssertionAxiom(DBKeywords.hasItem.iri(),EntityType.OBJECT_PROPERTY, spanName, spanURI,null);
           
            
           // OWLLiteral fromTimeURI= OntologyProcessor.owlDataFactory.getOWLLiteral((fromTime), OntologyProcessor.owlDataFactory.getIntegerOWLDatatype());
           // OWLLiteral toTimeURI= OntologyProcessor.owlDataFactory.getOWLLiteral((toTime), OntologyProcessor.owlDataFactory.getIntegerOWLDatatype());
           // OntologyProcessor.addPropertyAssertionAxiom(DBKeywords.filteredItemBeginsAtTime.iri(),EntityType.DATA_PROPERTY, spanURI, fromTime.toString(),fromTimeURI);
           // OntologyProcessor.addPropertyAssertionAxiom(DBKeywords.filteredItemEndsAtTime.iri(),EntityType.DATA_PROPERTY, spanURI, toTime.toString(),toTimeURI);
            
            
          //  model.add(oneVarStateList.getModel());
            
        }
        //System.out.println(OntologyProcessor.reasoner.isConsistent());
        //for(Triple tr: triples )
          //  model.add(model.asStatement(tr));
    }

   
   
  

     
     
     // CreateFIlteredSpan(?spanName, pa:values, ?fromTime, ?toTime)
 /*   private static void CreateFilteredSlice2(Model model, Command cmd, List<String> variables) {
        List<Triple> triples = new ArrayList<>();
        String spanName = cmd.args.get(0);
        String fromTime = ( cmd.args.get(2).trim());
        String toTime = ( cmd.args.get(3).trim());
        
        
      //   String progStateQuery = ReadInput.readQueryWithParameters("progStateInSpan", new String[] {fromTime,toTime});
            String progStateQuery =  null;
            System.out.println(progStateQuery);
        List<QuerySolution> sparqlResult = Sparql.executeQuery(progStateQuery, Settings.modelWithProgramAndTrace);
        Sparql.executeQueryAndPrint(progStateQuery,Settings.modelWithProgramAndTrace);
        
        
        
        String varQueryVariable = "?var";
        String valQueryVariable = "?val";
        String timeQueryVariable = "?time";
        
        if(variables == null)
            variables = sparqlResult.stream().map(p -> p.get(varQueryVariable).toString()).
                    distinct().collect(Collectors.toList());

        
        // ValueSpan(?spanName), hasItem(?spanName,?item), correspondsTo(?item,?var), 
        //filteredItemFromTime(?item, ?fromTime), filteredItemEndsAtTime(?item, ?toTime).
       triples.add(Utils.createTriple(spanName, RDF.type.getURI(), DBKeywords.ValueSpan.uri()));
       
       
        
        for(String var: variables){
            
            List<RDFNode> oneVarStates = sparqlResult.stream().filter(p -> p.get(varQueryVariable).toString().equals(var)).
                    sorted((o1, o2) -> Integer.compare(o1.get(timeQueryVariable).asLiteral().getInt(), o2.get(timeQueryVariable).asLiteral().getInt())).
                    map(p -> p.get(valQueryVariable)).
                    collect(Collectors.toList());
            
            
            //String spanURI = Settings.paPrefix + "test1";
            
            RDFList oneVarStateList = model.createList(oneVarStates.iterator());
            Resource headOfList = oneVarStateList.getHead().asResource();
            String spanURI =  headOfList.toString();
         
        triples.add(Utils.createTriple(spanName, DBKeywords.hasItem.uri(), spanURI));
        triples.add(Utils.createTriple(spanURI, DBKeywords.correspondsTo.uri(),var));
         triples.add(Utils.createTriple(spanURI, DBKeywords.filteredItemBeginsAtTime.uri(),Integer.parseInt(fromTime)));
         triples.add(Utils.createTriple(spanURI, DBKeywords.filteredItemEndsAtTime.uri(), Integer.parseInt(toTime)));

            
            model.add(oneVarStateList.getModel());
            
        }
        for(Triple tr: triples )
           model.add(model.asStatement(tr));
        
//return triples;
    }
   
     private static void CreateFilteredSlice(OWLOntologyManager mgr, OWLOntology ont, Command cmd, List<String> variables) {
        //List<Triple> triples = new ArrayList<>();
        String sliceName = cmd.args.get(0);
        String fromTime = ( cmd.args.get(2).trim());
        String toTime = ( cmd.args.get(3).trim());
        
        
        String progStateQuery =null;// ReadInput.readQueryWithParameters("progStateInSpan", new String[] {fromTime,toTime});
         
        System.out.println(progStateQuery);
        List<QuerySolution> varStates = Sparql.executeQuery(progStateQuery, Settings.modelWithProgramAndTrace);
        Sparql.executeQueryAndPrint(progStateQuery,Settings.modelWithProgramAndTrace);
        
        
        
        String varQueryVariable = "?var";
        String valQueryVariable = "?val";
        String timeQueryVariable = "?time";
        
        if(variables == null)
            variables = varStates.stream().map(p -> p.get(varQueryVariable).toString()).
                    distinct().collect(Collectors.toList());

        
        // ValueSpan(?spanName), hasItem(?spanName,?item), correspondsTo(?item,?var), 
        //filteredItemFromTime(?item, ?fromTime), filteredItemEndsAtTime(?item, ?toTime).
       //triples.add(Utils.createTriple(spanName, RDF.type.getURI(), DBKeywords.ValueSpan.uri()));
        OntologyProcessor.addClassAssertionAxiom(DBKeywords.ValueSpan.iri(), IRI.create(sliceName));
      
        
        for(String var: variables){
            
            List<RDFNode> oneVarStates = varStates.stream().filter(p -> p.get(varQueryVariable).toString().equals(var)).
                    sorted((o1, o2) -> Integer.compare(o1.get(timeQueryVariable).asLiteral().getInt(), o2.get(timeQueryVariable).asLiteral().getInt())).
                    map(p -> p.get(valQueryVariable)).
                    collect(Collectors.toList());
            
          //  Model model;
           // RDFList oneVarStateList = model.createList(oneVarStates.iterator());
           // Resource headOfList = oneVarStateList.getHead().asResource();
           // String spanURI =  headOfList.toString();
            
        String spanURI =  OntologyProcessor.createList(oneVarStates.iterator());
            OntologyProcessor.addPropertyAssertionAxiom(DBKeywords.hasItem.iri(),EntityType.OBJECT_PROPERTY, sliceName, spanURI,null);
            OntologyProcessor.addPropertyAssertionAxiom(DBKeywords.correspondsTo.iri(),EntityType.OBJECT_PROPERTY, spanURI, var,null);
            
            OWLLiteral fromTimeURI= OntologyProcessor.owlDataFactory.getOWLLiteral((fromTime), OntologyProcessor.owlDataFactory.getIntegerOWLDatatype());
            OWLLiteral toTimeURI= OntologyProcessor.owlDataFactory.getOWLLiteral((toTime), OntologyProcessor.owlDataFactory.getIntegerOWLDatatype());
            OntologyProcessor.addPropertyAssertionAxiom(DBKeywords.filteredItemBeginsAtTime.iri(),EntityType.DATA_PROPERTY, spanURI, fromTime.toString(),fromTimeURI);
            OntologyProcessor.addPropertyAssertionAxiom(DBKeywords.filteredItemEndsAtTime.iri(),EntityType.DATA_PROPERTY, spanURI, toTime.toString(),toTimeURI);
            
            
            
       // triples.add(Utils.createTriple(spanName, DBKeywords.hasItem.uri(), spanURI));
       // triples.add(Utils.createTriple(spanURI, DBKeywords.correspondsTo.uri(),var));
        // triples.add(Utils.createTriple(spanURI, DBKeywords.filteredItemBeginsAtTime.uri(),Integer.parseInt(fromTime)));
        // triples.add(Utils.createTriple(spanURI, DBKeywords.filteredItemEndsAtTime.uri(), Integer.parseInt(toTime)));


            
           // model.add(oneVarStateList.getModel());
            
        }
       // for(Triple tr: triples )
        //   model.add(model.asStatement(tr));
        
//return triples;
    }
*/

    static boolean isValidAbstractionCommand(CommandList commands) {
        List<Settings.AbstractionFunctors> abstractionList = Arrays.asList(Settings.AbstractionFunctors.values());
        return commands.stream().anyMatch(p -> abstractionList.contains(p.abstractionFuncEnum));
    }
    
     static boolean isValidReasoningCommand(CommandList commands) {
        List<Settings.ReasoningFunctors> abstractionList = Arrays.asList(Settings.ReasoningFunctors.values());
        return commands.stream().anyMatch(p -> abstractionList.contains(p.reasoningFuncEnum));
    }

    static boolean isValidQueryCommand(CommandList commands) {
        List<Settings.QueryFunctors> abstractionList = Arrays.asList(Settings.QueryFunctors.values());
        return commands.stream().anyMatch(p -> abstractionList.contains(p.queryFuncEnum));
    }

     

    private static void addPrimitiveConcepts(List<VariableState> spanList, IRI spanIRI) {
        
    }

    private static void createListsForBuiltInReasoning(List<String> variables, List<VariableState> stateInfo) {
         for(String var: variables){
            
                       
            List<VariableState> collect = stateInfo.stream().filter(p -> p.var.equals(var) && p.valueNode != null).filter(Utils.distinctByKey(p -> p.time)).
                    sorted((o1,o2) -> Integer.compare(o1.time, o2.time)).collect(Collectors.toList());
            variableStateLists.put(var,collect);
         }
    }

    
    
   
}
