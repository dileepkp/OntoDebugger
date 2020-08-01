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

import static com.mycompany.ontodebugger.OntologyProcessor.mgr;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import org.semanticweb.owlapi.apibinding.OWLManager;
import org.semanticweb.owlapi.model.IRI;
import org.semanticweb.owlapi.model.OWLEntity;
import org.semanticweb.owlapi.model.OWLOntology;
import org.semanticweb.owlapi.model.OWLOntologyCreationException;
import org.semanticweb.owlapi.model.OWLOntologyIRIMapper;
import org.semanticweb.owlapi.model.OWLOntologyManager;
import org.semanticweb.owlapi.model.SWRLArgument;
import org.semanticweb.owlapi.model.SWRLAtom;
import org.semanticweb.owlapi.model.SWRLPredicate;
import org.semanticweb.owlapi.model.SWRLRule;
import org.semanticweb.owlapi.util.PriorityCollection;
import org.semanticweb.owlapi.util.SimpleIRIMapper;
import org.swrlapi.builtins.arguments.SWRLLiteralBuiltInArgument;
import org.swrlapi.builtins.arguments.SWRLVariableBuiltInArgument;
import org.swrlapi.core.SWRLAPIRule;
import org.swrlapi.core.SWRLRuleEngine;
import org.swrlapi.factory.SWRLAPIFactory;
import uk.ac.manchester.cs.owl.owlapi.SWRLClassAtomImpl;
import uk.ac.manchester.cs.owl.owlapi.SWRLVariableImpl;
import uk.ac.manchester.cs.owl.owlapi.SWRLIndividualArgumentImpl;
import uk.ac.manchester.cs.owl.owlapi.SWRLObjectPropertyAtomImpl;
/**
 *
 * @author aidb
 */
public class SWRLToPrologRules {

   
     //String srcpath = "/home/aidb/Dropbox/OntoDebugger/src/main/resources";
   static  String destPath = "src/main/resources/ForwardChaining/prologRules.txt";
    
   static IRI debugIRI = IRI.create("http://www.semanticweb.org/aidb/ontologies/ProgramDebuggingOntology");
   static IRI paIRI = IRI.create("http://www.semanticweb.org/aidb/ontologies/ProgramAnalysisOntology");
   static IRI cIRI = IRI.create("http://www.semanticweb.org/yzhao30/ontologies/2015/7/c/1.0.0");
        
    
    static OWLOntologyManager mgr;
    static OWLOntology ontology;
    private static boolean function = false;
    static Map<String, String> swrlFuncToRDFFunc = new HashMap<>();
    
    public static void main(String[] args) throws OWLOntologyCreationException, Exception{
       
          StringBuilder sb = new StringBuilder();
          sb.append(Utils.getHeader());
        preprocess();
        ontology = loadOntology();
        
        SWRLRuleEngine ruleEngine = SWRLAPIFactory.createSWRLRuleEngine(ontology);
        Set<SWRLAPIRule> swrlRules = ruleEngine.getSWRLRules();
        Iterator<SWRLAPIRule> rule = swrlRules.iterator();
        
        while(rule.hasNext()){
            String s = processRule(rule.next());
            sb.append(s);
        }
        writeToFile(sb.toString());
    }

    private static void preprocess() {
        swrlFuncToRDFFunc.put("lessThan","lessThan");
        swrlFuncToRDFFunc.put("greaterThan","greaterThan");
        swrlFuncToRDFFunc.put("lessThanOrEqual","le");
        swrlFuncToRDFFunc.put("greaterThanOrEqual","ge");
        swrlFuncToRDFFunc.put("notEqual","notEqual");
        swrlFuncToRDFFunc.put("equal","equal");
    }
    
    private static OWLOntology loadOntology() throws OWLOntologyCreationException {
        File debugFile = new File(Settings.programDebugOriginalOntology_ListModel);
        File paFile = new File("src/main/resources/PAOntology.owl");
        File cFile = new File("src/main/resources/c.owl");
        
        
        mgr = OWLManager.createOWLOntologyManager();
        mgr.getIRIMappers().add(new SimpleIRIMapper(paIRI,IRI.create(paFile)));
        mgr.getIRIMappers().add(new SimpleIRIMapper(cIRI,IRI.create(cFile)));
        mgr.getIRIMappers().add(new SimpleIRIMapper(debugIRI,IRI.create(debugFile)));
        
        PriorityCollection<OWLOntologyIRIMapper> iriMappers = mgr.getIRIMappers();
        
        return mgr.loadOntologyFromOntologyDocument(debugFile);
    }

    private static String processRule(SWRLRule rule) {
        StringBuilder sb = new StringBuilder();
        

        Set<SWRLAtom> head = rule.getHead();
        Set<SWRLAtom> body = rule.getBody();
        
        Iterator<SWRLAtom> iterator = body.iterator();
        String b = processHeadAndBody(iterator);
       // System.out.println(b);
        
        iterator = head.iterator();
        String b1 = processHeadAndBody(iterator);
        //System.out.println(b);
        
        sb.append("[\n").append(b).append("\n->\n");
        sb.append(b1).append("\n]\n\n");
       String replaceRdf = sb.toString().replaceAll("pdo:rdf", "rdf:");
       // System.out.println(replaceRdf);
       return replaceRdf.toString();
              
    }

    private static String processHeadAndBody(Iterator<SWRLAtom> iterator) {
        StringBuilder sb = new StringBuilder();
        List<String> argList = new  ArrayList<>();
        int i = 0;
        while(iterator.hasNext()){
            SWRLAtom atom = iterator.next();
            
            
            //SWRLVariableBuiltInArgument gd;
            
            
            Collection<SWRLArgument> allArguments = atom.getAllArguments();
            Iterator<SWRLArgument> iterator1 = allArguments.iterator();
            while(iterator1.hasNext()){
                SWRLArgument arg = iterator1.next();
                
                if(arg instanceof SWRLVariableImpl){
                    SWRLVariableImpl var = (SWRLVariableImpl) arg;
                   // System.out.println(var.getIRI().getShortForm());
                    argList.add("?" + var.getIRI().getShortForm());
                } else if(arg instanceof SWRLVariableBuiltInArgument){
                    SWRLVariableBuiltInArgument tt = (SWRLVariableBuiltInArgument) arg;
                   // System.out.println(tt.getVariableName());
                     argList.add("?" + tt.getVariableName());
                } else if(arg instanceof SWRLIndividualArgumentImpl){
                    SWRLIndividualArgumentImpl tt = (SWRLIndividualArgumentImpl) arg;
                    //System.out.println(tt.getIndividual().asOWLNamedIndividual().getIRI());
                   argList.add(getShortForm(tt.getIndividual().toString()));
                } else if (arg instanceof SWRLLiteralBuiltInArgument){
                    SWRLLiteralBuiltInArgument tt = (SWRLLiteralBuiltInArgument) arg;
                    argList.add(Integer.toString(tt.getLiteral().parseInteger()));
                            }
                
                //System.out.println(arg + arg.getClass().toGenericString());
            }
            
            SWRLPredicate predicate = atom.getPredicate();
            
            //System.out.println(predicate);
            String predString = getShortForm(predicate.toString());
            
            if(!function){
            sb.append("(");
            if(argList.size() == 1){
                sb.append(argList.get(0));
                sb.append(" rdf:type ");
                sb.append(predString);
            } else if(argList.size()== 2 ){
                sb.append(argList.get(0)).append(" ");
                sb.append(predString).append(" ");
                sb.append(argList.get(1));
            }
            }else {
                predString = swrlFuncToRDFFunc.get(predString);
                sb.append(predString).append("(");
                sb.append(argList.get(0)).append(",");
                sb.append(argList.get(1));
            }
            sb.append(")\n");
            argList.clear();
        }
        
        return sb.toString();
    }

    private static String getShortForm(String iri1) {
        function = false;
        String iri = iri1.replaceAll("(<|>)", "");
        if(iri.startsWith(Settings.dbPrefix))
            return iri.replaceAll(Settings.dbPrefix, "pdo:");
        if(iri.startsWith(Settings.rdfPrefix))
            return iri.replaceAll(Settings.rdfPrefix, "rdf:");
        if(iri.startsWith(Settings.swrlbPrefix)){
            function = true;
            return iri.replaceAll(Settings.swrlbPrefix, "");
        }
                    return null;
    }
    
    
    
     private static void writeToFile(String output) throws Exception {
       try (FileOutputStream outputStream = new FileOutputStream(destPath)) {
           outputStream.write(output.getBytes());
        }
    }
    
}
