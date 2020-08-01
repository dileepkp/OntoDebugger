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

import com.clarkparsia.pellet.owlapiv3.PelletReasoner;
import com.clarkparsia.pellet.owlapiv3.PelletReasonerFactory;
import com.google.common.base.Optional;
import com.google.common.collect.Multimap;
import static com.mycompany.ontodebugger.SWRLToRDFRules.ontology;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import org.apache.commons.io.FileUtils;
import org.apache.jena.rdf.model.InfModel;
import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.rdf.model.RDFNode;
import org.apache.jena.rdf.model.Resource;
//import org.apache.jena.reasoner.Reasoner;
import org.apache.jena.vocabulary.RDF;
import org.apache.jena.vocabulary.ReasonerVocabulary;
//import org.semanticweb.HermiT.Configuration;
import org.semanticweb.owlapi.apibinding.OWLManager;
import org.semanticweb.owlapi.dlsyntax.renderer.DLSyntaxObjectRenderer;
import org.semanticweb.owlapi.io.OWLObjectRenderer;
import org.semanticweb.owlapi.io.ReaderDocumentSource;
import org.semanticweb.owlapi.model.AddAxiom;
import org.semanticweb.owlapi.model.EntityType;
import org.semanticweb.owlapi.model.IRI;
import org.semanticweb.owlapi.model.NodeID;
import org.semanticweb.owlapi.model.OWLAnonymousIndividual;
import org.semanticweb.owlapi.model.OWLAxiom;
import org.semanticweb.owlapi.model.OWLClass;
import org.semanticweb.owlapi.model.OWLDataFactory;
import org.semanticweb.owlapi.model.OWLDataProperty;
import org.semanticweb.owlapi.model.OWLDataPropertyExpression;
import org.semanticweb.owlapi.model.OWLDatatype;
import org.semanticweb.owlapi.model.OWLDifferentIndividualsAxiom;
import org.semanticweb.owlapi.model.OWLEntity;
import org.semanticweb.owlapi.model.OWLImportsDeclaration;
import org.semanticweb.owlapi.model.OWLIndividual;
import org.semanticweb.owlapi.model.OWLLiteral;
import org.semanticweb.owlapi.model.OWLNamedIndividual;
import org.semanticweb.owlapi.model.OWLObjectHasValue;
import org.semanticweb.owlapi.model.OWLObjectProperty;
import org.semanticweb.owlapi.model.OWLObjectSomeValuesFrom;
import org.semanticweb.owlapi.model.OWLOntology;
import org.semanticweb.owlapi.model.OWLOntologyCreationException;
import org.semanticweb.owlapi.model.OWLOntologyIRIMapper;
import org.semanticweb.owlapi.model.OWLOntologyLoaderConfiguration;
import org.semanticweb.owlapi.model.OWLOntologyManager;
import org.semanticweb.owlapi.model.OWLOntologyStorageException;
import org.semanticweb.owlapi.model.OWLProperty;
import org.semanticweb.owlapi.model.RemoveImport;
import org.semanticweb.owlapi.model.SWRLArgument;
import org.semanticweb.owlapi.model.SWRLAtom;
import org.semanticweb.owlapi.model.SWRLPredicate;
import org.semanticweb.owlapi.model.SWRLRule;
import org.semanticweb.owlapi.model.parameters.Imports;
import org.semanticweb.owlapi.rdf.turtle.parser.TurtleOntologyParser;
import org.semanticweb.owlapi.reasoner.InferenceType;
import org.semanticweb.owlapi.util.AutoIRIMapper;
import org.semanticweb.owlapi.util.PriorityCollection;
import org.semanticweb.owlapi.util.SimpleIRIMapper;
import org.semanticweb.owlapi.vocab.OWL2Datatype;
import org.semanticweb.owlapi.vocab.OWLRDFVocabulary;
import org.swrlapi.core.SWRLRuleEngine;
import org.swrlapi.factory.SWRLAPIFactory;
//import org.semanticweb.HermiT.Reasoner;
//import org.semanticweb.HermiT.Reasoner.ReasonerFactory;
import org.semanticweb.owlapi.reasoner.OWLReasoner;
import org.semanticweb.owlapi.reasoner.OWLReasonerFactory;
import org.semanticweb.owlapi.reasoner.SimpleConfiguration;
import org.semanticweb.owlapi.search.EntitySearcher;
import org.semanticweb.owlapi.util.InferredAxiomGenerator;
import org.semanticweb.owlapi.util.InferredClassAssertionAxiomGenerator;
import org.semanticweb.owlapi.util.InferredDisjointClassesAxiomGenerator;
import org.semanticweb.owlapi.util.InferredEquivalentClassAxiomGenerator;
import org.semanticweb.owlapi.util.InferredEquivalentDataPropertiesAxiomGenerator;
import org.semanticweb.owlapi.util.InferredEquivalentObjectPropertyAxiomGenerator;
import org.semanticweb.owlapi.util.InferredInverseObjectPropertiesAxiomGenerator;
import org.semanticweb.owlapi.util.InferredObjectPropertyCharacteristicAxiomGenerator;
import org.semanticweb.owlapi.util.InferredOntologyGenerator;
import org.semanticweb.owlapi.util.InferredPropertyAssertionGenerator;
import org.semanticweb.owlapi.util.InferredSubClassAxiomGenerator;
import org.semanticweb.owlapi.util.InferredSubDataPropertyAxiomGenerator;
import org.semanticweb.owlapi.util.InferredSubObjectPropertyAxiomGenerator;
import org.swrlapi.core.SWRLAPIRule;
import org.swrlapi.factory.LiteralFactory;
//import org.semanticweb.HermiT.Reasoner;

/**
 *
 * @author aidb
 */
public class OntologyProcessor {

    static OWLOntologyManager mgr;
    static OWLOntology ontology = null;
    static private OWLClass listClass;
    static private OWLObjectProperty typeObjectProperty;
    static OWL2Datatype intDataType;
    static OWLDataFactory owlDataFactory;
  static  OWLReasonerFactory reasonerFactory;
 static OWLReasoner reasoner;
 
   /*       
    static void processSWRLRules() throws Exception {
        
    Settings.startTimeForQuery = System.currentTimeMillis(); 
       SWRLRuleEngine ruleEngine = SWRLAPIFactory.createSWRLRuleEngine(ontology);
      
       ruleEngine.infer();
        Settings.endTimeForQuery = System.currentTimeMillis();
        Settings.time1 = Settings.endTimeForQuery - Settings.startTimeForQuery;
        System.out.println( "\n swrl time:" + Settings.time1 + " milliseconds");
     
      // ontology.saveOntology();
      
       System.out.println("After swrl rules" + ontology.getAxiomCount());
     

    }
  
    static void process2() throws Exception {
        
    Settings.startTimeForQuery = System.currentTimeMillis(); 
       SWRLRuleEngine ruleEngine = SWRLAPIFactory.createSWRLRuleEngine(ontology);
       Settings.endTimeForQuery = System.currentTimeMillis();
        Settings.time1 = Settings.endTimeForQuery - Settings.startTimeForQuery;
        System.out.println( "\n swrl time:" + Settings.time1 + " milliseconds");
     
       ruleEngine.infer();
       ontology.saveOntology();
       
       System.out.println("After swrl rules" + ontology.getAxiomCount());
     
       
       

    }*/

    
static void init() throws Exception {
           //create a backup of program debug ontology
           if(Settings.workingModel == Settings.workingModel.listSWRL)
        FileUtils.copyFile(new File(Settings.programDebugOriginalOntology_ListModel), new File(Settings.programDebugWorkingOntology));
           else if(Settings.workingModel == Settings.workingModel.setSWRL)
        FileUtils.copyFile(new File(Settings.programDebugOriginalOntology_SetModel), new File(Settings.programDebugWorkingOntology));
           else if(Settings.workingModel == Settings.workingModel.listOWLRL)
        FileUtils.copyFile(new File(Settings.programDebugOriginalOntology_ListRDFRulesModel), new File(Settings.programDebugWorkingOntology));
           
        File debugFile = new File(Settings.programDebugWorkingOntology);
    //    File paFile = new File("/home/aidb/Dropbox/OntoDebugger/src/main/resources/PAOntology.owl");
        File cFile = new File("src/main/resources/c.owl");
        
        IRI debugIRI = IRI.create("http://www.semanticweb.org/aidb/ontologies/ProgramDebuggingOntology");
     //   IRI paIRI = IRI.create("http://www.semanticweb.org/aidb/ontologies/ProgramAnalysisOntology");
      //  IRI cIRI = IRI.create("http://www.semanticweb.org/yzhao30/ontologies/2015/7/c/1.0.0");
        
        mgr = OWLManager.createOWLOntologyManager();
       // mgr.getIRIMappers().add(new SimpleIRIMapper(paIRI,IRI.create(paFile)));
       // mgr.getIRIMappers().add(new SimpleIRIMapper(cIRI,IRI.create(cFile)));
        mgr.getIRIMappers().add(new SimpleIRIMapper(debugIRI,IRI.create(debugFile)));
        
        PriorityCollection<OWLOntologyIRIMapper> iriMappers = mgr.getIRIMappers();
        ontology = mgr.loadOntologyFromOntologyDocument(debugFile);
        
        //loadTTLIntoOntology(Settings.tempFile);
     //  RemoveImport rm = new RemoveImport(ontology, mgr.getOWLDataFactory().getOWLImportsDeclaration(paIRI));
     //  mgr.applyChange(rm);
     //  ontology.saveOntology();
      
        
        createConstants();
        reasonerFactory = PelletReasonerFactory.getInstance();
         
          //System.out.println("status" + reasoner.isConsistent());

    }
 /*   static void init2() throws Exception {
           //create a backup of program debug ontology
        FileUtils.copyFile(new File(Settings.programDebugOriginalOntology_ListModel), new File(Settings.programDebugWorkingOntology));
        
        File debugFile = new File(Settings.programDebugWorkingOntology);
        File paFile = new File("/home/aidb/Dropbox/OntoDebugger/src/main/resources/PAOntology.owl");
        File cFile = new File("/home/aidb/Dropbox/OntoDebugger/src/main/resources/c.owl");
        
        IRI debugIRI = IRI.create("http://www.semanticweb.org/aidb/ontologies/ProgramDebuggingOntology");
        IRI paIRI = IRI.create("http://www.semanticweb.org/aidb/ontologies/ProgramAnalysisOntology");
        IRI cIRI = IRI.create("http://www.semanticweb.org/yzhao30/ontologies/2015/7/c/1.0.0");
        
        mgr = OWLManager.createOWLOntologyManager();
        mgr.getIRIMappers().add(new SimpleIRIMapper(paIRI,IRI.create(paFile)));
        mgr.getIRIMappers().add(new SimpleIRIMapper(cIRI,IRI.create(cFile)));
        mgr.getIRIMappers().add(new SimpleIRIMapper(debugIRI,IRI.create(debugFile)));
        
        PriorityCollection<OWLOntologyIRIMapper> iriMappers = mgr.getIRIMappers();
        ontology = mgr.loadOntologyFromOntologyDocument(debugFile);
        
        //loadTTLIntoOntology(Settings.tempFile);
       RemoveImport rm = new RemoveImport(ontology, mgr.getOWLDataFactory().getOWLImportsDeclaration(paIRI));
       mgr.applyChange(rm);
       ontology.saveOntology();
      
        
        createConstants();

    }*/
    
    static void loadTTLIntoOntology(String traceFile) throws Exception{
        
        
         FileReader fr = new FileReader(traceFile); 
     
       ReaderDocumentSource rds = new ReaderDocumentSource(fr);
       OWLOntologyLoaderConfiguration config = new OWLOntologyLoaderConfiguration();
       
       TurtleOntologyParser top = new TurtleOntologyParser();
       
    //   System.out.println("Before" + ontology.getAxiomCount());
       top.parse(rds, ontology, config);
     //  System.out.println("After" + ontology.getAxiomCount());
        ontology.saveOntology();
    }

    static void addClassAssertionAxiom(IRI className, IRI ind) {
      
        OWLIndividual owlSliceName = owlDataFactory.getOWLNamedIndividual(ind);
        addClassAssertionAxiom(className, owlSliceName);
        
    }
    
     static void addClassAssertionAxiom(IRI className, OWLIndividual owlSliceName) {
      
        
        OWLClass owlSpanType = owlDataFactory.getOWLClass(className);
        OWLAxiom axiom = owlDataFactory.getOWLClassAssertionAxiom(owlSpanType, owlSliceName);
       AddAxiom addAxiom = new AddAxiom(ontology, axiom);// Use the manager to apply the change
       mgr.applyChange(addAxiom);
      //System.out.println(axiom.toString());
    }
    
    static void addPropertyAssertionAxiom(IRI propName, EntityType propType, String _ind1Name, String _ind2Name,OWLLiteral ind2Lit) {
      
    
        IRI ind1Name = IRI.create(_ind1Name);
        IRI ind2Name = IRI.create(_ind2Name);
        
        OWLIndividual ind1;
        if(ind1Name.asAnonymousIndividual().isPresent())
            ind1 = owlDataFactory.getOWLAnonymousIndividual(_ind1Name);
        else
            ind1 = owlDataFactory.getOWLNamedIndividual(ind1Name);
        
        OWLIndividual ind2;
       // OWLLiteral ind2Lit;
        
        OWLProperty prop;
        OWLAxiom axiom = null;
        if(propType == EntityType.OBJECT_PROPERTY){
            prop = owlDataFactory.getOWLObjectProperty(propName);
            //ind2 = owlDataFactory.getOWLNamedIndividual(ind2Name);
            if(ind2Name.asAnonymousIndividual().isPresent())
            ind2 = owlDataFactory.getOWLAnonymousIndividual(_ind2Name);
            else
            ind2 = owlDataFactory.getOWLNamedIndividual(ind2Name);
        
            axiom = owlDataFactory.getOWLObjectPropertyAssertionAxiom((OWLObjectProperty)prop, ind1, ind2);
        } else if(propType == EntityType.DATA_PROPERTY){
            prop = owlDataFactory.getOWLDataProperty(propName);
            //ind2Lit = ind2Name.asLiteral().get();
            
            axiom = owlDataFactory.getOWLDataPropertyAssertionAxiom((OWLDataProperty)prop, ind1, ind2Lit);
        } 
       AddAxiom addAxiom = new AddAxiom(ontology, axiom);// Use the manager to apply the change
      // System.out.println(axiom.toString());
       mgr.applyChange(addAxiom);
    }
    
  
    

    private static void createConstants() {
        owlDataFactory = mgr.getOWLDataFactory();
       listClass = owlDataFactory.getOWLClass(Settings.DBKeywords.rdfList.iri());
     typeObjectProperty = owlDataFactory.getOWLObjectProperty(OWLRDFVocabulary.RDF_TYPE.getIRI());
      //  intDataType = 
    }

    static void createSet(Iterator<VariableState> members, IRI spanIRI) {
       
      //  VariableState nextvs = members.next();
      //  RDFNode next = nextvs.valueNode;
        //String root = spanIRI.toString();
        VariableState nextvs;
        RDFNode next;
         OWLLiteral nextLiteral;
         OWLLiteral timeLiteral, indexLiteral;
         
         int index = 0;
         
         while (members.hasNext())
        {
            String spanCell = IRI.create(Settings.prefix + "#" +NodeID.nextAnonymousIRI().substring(2)).toString();
        nextvs = members.next();
        next = nextvs.valueNode;
        
         // nextLiteral = owlDataFactory.getOWLLiteral(next.asLiteral().getInt());
         nextLiteral = owlDataFactory.getOWLLiteral(next.asLiteral().getLexicalForm(), getOWLDataType(next.asLiteral().getDatatypeURI()));
    //   timeLiteral = owlDataFactory.getOWLLiteral(Integer.toString(nextvs.time),OWL2Datatype.XSD_LONG);
    //   indexLiteral = owlDataFactory.getOWLLiteral(Integer.toString(index++),OWL2Datatype.XSD_LONG);
        timeLiteral = owlDataFactory.getOWLLiteral(nextvs.time);
        indexLiteral = owlDataFactory.getOWLLiteral(index++);
        
         addClassAssertionAxiom(Settings.DBKeywords.SpanCell.iri(), IRI.create(spanCell));
          addPropertyAssertionAxiom(Settings.DBKeywords.hasSpanCell.iri(), EntityType.OBJECT_PROPERTY, spanIRI.toString(),spanCell,null);  
        
          addPropertyAssertionAxiom(Settings.DBKeywords.hasValue.iri(), EntityType.DATA_PROPERTY, spanCell,nextLiteral.getLiteral(),nextLiteral);
       addPropertyAssertionAxiom(Settings.DBKeywords.timestamp.iri(), EntityType.DATA_PROPERTY, spanCell,timeLiteral.getLiteral(),timeLiteral);
       addPropertyAssertionAxiom(Settings.DBKeywords.index.iri(), EntityType.DATA_PROPERTY, spanCell,indexLiteral.getLiteral(),indexLiteral);
      
        
        }
         
        
    }
    static String createList(Iterator<VariableState> members,String spanName) {
        
        /*if (!members.hasNext())
        return createList();
        Resource root = createResource();
        root.addProperty(RDF.type, RDF.List);
        root.addProperty(RDF.first, members.next());
         */
        VariableState nextvs = members.next();
        RDFNode next = nextvs.valueNode;
        //OWLIndividual root = owlDataFactory.getOWLAnonymousIndividual();
       // String root = IRI.create(Settings.prefix + "#" +NodeID.nextAnonymousIRI().substring(2)).toString();
        String root = IRI.create(spanName).toString();
        
        OWLLiteral nextLiteral = owlDataFactory.getOWLLiteral(next.asLiteral().getLexicalForm(), getOWLDataType(next.asLiteral().getDatatypeURI()));
        OWLLiteral timeLiteral = owlDataFactory.getOWLLiteral(nextvs.time);
        // = owlDataFactory.getOWLLiteral(nextvs.time, OWL2Datatype.XSD_LONG));
        addClassAssertionAxiom(Settings.DBKeywords.rdfList.iri(), IRI.create(root));
        addPropertyAssertionAxiom(Settings.DBKeywords.rdffirst.iri(), EntityType.DATA_PROPERTY, root,nextLiteral.toString(),nextLiteral);
        addPropertyAssertionAxiom(Settings.DBKeywords.timestamp.iri(), EntityType.DATA_PROPERTY, root,timeLiteral.toString(),timeLiteral);
        
                //Resource last = root;
                String last = root;
        while (members.hasNext())
        {
           /*
             Resource spanCell = createResource();
             spanCell.addProperty(RDF.type, RDF.List);
             spanCell.addProperty(RDF.first, members.next());
            last.addProperty(RDF.spanCell, spanCell);
            last = spanCell;
*/
        String rest = IRI.create(Settings.prefix + "#" +NodeID.nextAnonymousIRI().substring(2)).toString();
        nextvs = members.next();
        next = nextvs.valueNode;
       // nextLiteral = owlDataFactory.getOWLLiteral(next.asLiteral().getLexicalForm(), next.asLiteral().getDatatypeURI().replaceAll("xmlschema", "XMLSchema"));
       
       nextLiteral = owlDataFactory.getOWLLiteral(next.asLiteral().getLexicalForm(), getOWLDataType(next.asLiteral().getDatatypeURI()));
       timeLiteral = owlDataFactory.getOWLLiteral(nextvs.time);
        addClassAssertionAxiom(Settings.DBKeywords.rdfList.iri(), IRI.create(rest));
        addPropertyAssertionAxiom(Settings.DBKeywords.rdffirst.iri(), EntityType.DATA_PROPERTY, rest,nextLiteral.getLiteral(),nextLiteral);
        addPropertyAssertionAxiom(Settings.DBKeywords.timestamp.iri(), EntityType.DATA_PROPERTY, rest,timeLiteral.getLiteral(),timeLiteral);
        addPropertyAssertionAxiom(Settings.DBKeywords.rdfrest.iri(), EntityType.OBJECT_PROPERTY, last,rest,null);  
        last = rest;
        }
        //last.addProperty(RDF.spanCell, RDF.nil);
        addPropertyAssertionAxiom(Settings.DBKeywords.rdfrest.iri(), EntityType.OBJECT_PROPERTY, last, Settings.DBKeywords.rdfnil.uri(),null  );  
        return root;

    }

    private static OWL2Datatype getOWLDataType(String datatypeURI) {
        if(datatypeURI.endsWith("integer") || datatypeURI.endsWith("long"))
            return OWL2Datatype.XSD_LONG;
        else if (datatypeURI.endsWith("decimal"))
            return OWL2Datatype.XSD_DECIMAL;
        else if (datatypeURI.endsWith("double"))
            return OWL2Datatype.XSD_DOUBLE;
        return null;
    }

   
static void reason(CommandList commands) throws Exception {
        //PelletReasoner reasoner = PelletReasonerFactory.getInstance().createReasoner( ontology );
        //process();
        //  owlDataFactory = mgr.getOWLDataFactory();
        // ontology.saveOntology();
        /*Settings.startimeReasonerLoad = System.currentTimeMillis();
        Settings.endTimeReasonerLoad = System.currentTimeMillis();
        Settings.netTimeReasonerLoad = Settings.endTimeReasonerLoad - Settings.startimeReasonerLoad;
        System.out.println( "\n Reasoner load time" + Settings.netTimeReasonerLoad + " milliseconds");
         */
       
        if(!Settings.settingsInput.equals("schdeule") && Settings.workingModel == Settings.WorkingModel.setSWRL){
        OWLDifferentIndividualsAxiom owlDifferentIndividualsAxiom = owlDataFactory.getOWLDifferentIndividualsAxiom(ontology.getIndividualsInSignature(Imports.INCLUDED));
        AddAxiom ax = new AddAxiom(ontology, owlDifferentIndividualsAxiom);
        mgr.applyChange(ax);
        }
        
        if(Settings.workingModel == Settings.WorkingModel.listOWLRL ||  Settings.workingModel == Settings.WorkingModel.listSWRL){
        OWLDifferentIndividualsAxiom owlDifferentIndividualsAxiom = owlDataFactory.getOWLDifferentIndividualsAxiom(ontology.getIndividualsInSignature(Imports.INCLUDED));
        AddAxiom ax = new AddAxiom(ontology, owlDifferentIndividualsAxiom);
        mgr.applyChange(ax);
        }
        
    // processSWRLRules();
    //     System.out.println(reasoner.isConsistent());
   //  ontology.saveOntology();
        reasoner = reasonerFactory.createReasoner(ontology, new SimpleConfiguration());
     Command c = commands.get(0);

     
     OWLNamedIndividual spanInstance = owlDataFactory.getOWLNamedIndividual(IRI.create(c.argsWithURI.get(0)));
     if(c.args.size() == 1){

     OWLClass testClass = owlDataFactory.getOWLClass(c.reasoningFuncEnum.iri());
     
            //   System.out.println(testClass.toString());
            //  for(OWLNamedIndividual c1: ontology.getIndividualsInSignature())
            //      System.out.println(c1.toString());
            // System.out.println("instance count" + reasoner.getInstances(testClass,false).getFlattened().size());
            Set<OWLNamedIndividual> resultIndividuals = reasoner.getInstances(testClass, false).getFlattened();
            
      for (OWLNamedIndividual ind : resultIndividuals) {
           // System.out.println( testClass.toString() + ":" + ind.toString());
           if(ind.toString().equals(spanInstance.toString())){
               System.out.println("true");
               return;
           }
        }
      System.out.println("false");
      
     }
     else{
        OWLNamedIndividual firstInd = owlDataFactory.getOWLNamedIndividual(IRI.create(c.argsWithURI.get(0)));
  OWLObjectProperty testProperty = owlDataFactory.getOWLObjectProperty(c.reasoningFuncEnum.iri());
       //owlDataFactory.getOWLObjectSomeValuesFrom(testProperty, listClass)
       
        Set<OWLNamedIndividual> reasonerResults = reasoner.getObjectPropertyValues(firstInd, testProperty).getFlattened();
        if(reasonerResults.size() == 0){
            System.out.println("false");
               return;
        }
     for (OWLNamedIndividual ind : reasonerResults ) {
           // System.out.println( testClass.toString() + ":" + ind.toString());
           if(ind.toStringID().equals(c.argsWithURI.get(1))){
               System.out.println("false");
               return;
           }
        }
      System.out.println("true");
     }
     
     
   /*  else{
        OWLNamedIndividual secondInd = owlDataFactory.getOWLNamedIndividual(IRI.create(c.argsWithURI.get(1)));
  OWLObjectProperty testProperty = owlDataFactory.getOWLObjectProperty(c.reasoningFuncEnum.iri());
         OWLClass tempClass = owlDataFactory.getOWLClass(IRI.create("Span"));
        OWLObjectHasValue owlObjectHasValue = owlDataFactory.getOWLObjectHasValue(testProperty, secondInd);
         
         
         addClassAssertionAxiom(IRI.create("Span"), secondInd);
         OWLObjectSomeValuesFrom owlObjectSomeValuesFrom = owlDataFactory.getOWLObjectSomeValuesFrom(testProperty, tempClass);
         
        ontology.saveOntology();
        Set<OWLNamedIndividual> reasonerResults = reasoner.getInstances(owlObjectSomeValuesFrom.getFiller(),false).getFlattened();
        Set<OWLNamedIndividual> reasonerResults2 = reasoner.getInstances(owlObjectHasValue,false).getFlattened();
       // Set<OWLNamedIndividual> reasonerResults = reasoner.getObjectPropertyValues(secondInd, testProperty).getFlattened();
     for (OWLNamedIndividual ind : reasonerResults ) {
           // System.out.println( testClass.toString() + ":" + ind.toString());
           if(ind.toStringID().equals(c.argsWithURI.get(0))){
               System.out.println("true");
               return;
           }
        }
      System.out.println("false");
     }*/
     /* OWLClass testClass2 = owlDataFactory.getOWLClass(Settings.ReasoningFunctors.Span.iri());
     
      
      System.out.println("instance count" + reasoner.getInstances(testClass2,false).getFlattened().size());
      for (OWLNamedIndividual ind : reasoner.getInstances(testClass2, false).getFlattened()) {
            System.out.println( testClass2.toString() + ":" + ind.toString());
           
        }
      */
      
     //   listAllDataPropertyValues(spanInstance, ontology, reasoner);
     
    // System.out.println("Before reasoning:" +ontology.getAxiomCount());
     //temp();
     // reasoner.getKB().realize();
     //System.out.println("Before reasoning:" +ontology.get); 
       
       // InferredOntologyGenerator gen = new InferredOntologyGenerator(reasoner);
       // OWLOntology newOntology = mgr.createOntology();
       // gen.fillOntology(owlDataFactory, newOntology);
     
    // ontology.saveOntology();
     //System.out.println("After reasoning:" +ontology.getAxiomCount());
 //System.out.println(reasoner.isConsistent());
 
 
    }

 static void listAllDataPropertyValues(OWLNamedIndividual individual, OWLOntology ontology, OWLReasoner reasoner) {
        OWLObjectRenderer renderer = new DLSyntaxObjectRenderer();
        Multimap<OWLDataPropertyExpression, OWLLiteral> assertedValues = EntitySearcher.getDataPropertyValues(individual, ontology);
        for (OWLDataProperty dataProp : ontology.getDataPropertiesInSignature(Imports.INCLUDED)) {
            for (OWLLiteral literal : reasoner.getDataPropertyValues(individual, dataProp)) {
                Collection<OWLLiteral> literalSet = assertedValues.get(dataProp);
                boolean asserted = (literalSet != null && literalSet.contains(literal));
                System.out.println((asserted ? "asserted" : "inferred") + " data property for " + renderer.render(individual) + " : "
                        + renderer.render(dataProp) + " -> " + renderer.render(literal));
            }
        }
}
    private static void temp() {
     /*   List<InferredAxiomGenerator<? extends OWLAxiom>> gens = new ArrayList<>();
         gens.add(new InferredSubClassAxiomGenerator());  
         gens.add(new InferredClassAssertionAxiomGenerator());
         gens.add( new InferredDisjointClassesAxiomGenerator());
         gens.add( new InferredEquivalentClassAxiomGenerator());
         gens.add( new InferredEquivalentDataPropertiesAxiomGenerator());
         gens.add( new InferredEquivalentObjectPropertyAxiomGenerator());
         gens.add( new InferredInverseObjectPropertiesAxiomGenerator());
         gens.add( new InferredObjectPropertyCharacteristicAxiomGenerator());
         gens.add( new InferredPropertyAssertionGenerator());
         gens.add( new InferredSubDataPropertyAxiomGenerator());
         gens.add( new InferredSubObjectPropertyAxiomGenerator());

         InferredOntologyGenerator iog = new InferredOntologyGenerator(reasoner, gens);
         OWLOntology infOnt = manager.createOntology();
         iog.fillOntology(datafactory, infOnt);
         manager.saveOntology(infOnt,new RDFXMLDocumentFormat(),IRI.create(new File("D://file.owl"))); 
*/
    }

    

    
    
    
}
