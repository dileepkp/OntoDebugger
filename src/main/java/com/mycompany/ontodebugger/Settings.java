/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.ontodebugger;

import org.apache.jena.rdf.model.Model;
//import org.apache.jena.vocabulary.PA;
import org.semanticweb.owlapi.model.IRI;

/**
 *
 * @author aidb
 */
public class Settings {

    static long startTime4;
    static long endTime4;
    static long netTime4;
    static long startTimeForDefaultAbstractions;
    static long endTimeForDefaultAbstractions;
    static long totalTimeForDefaultAbstractions;
    static long indexingBeginTime;
    static long indexingEndTime;
    static long indexingNetTime;

    
    
    enum WorkingModel{
        listSWRL, setSWRL, listOWLRL, simulationMode, reasoningWithoutOntology,
        libraryAbstractions;
    }
    
    static boolean userInteractionMode = false;
    static String[] experimentSettings = {"tot_info", "space", "sed", 
       /*3 */ "schdeule","print_tokens2", "print_tokens", 
       /*6 */"grep", "flex",
    /*8 */ "schdeule_ontology"};
    static String settingsInput = experimentSettings[0];
        
    static boolean instrumentCode = false;
    //    static boolean preProcessingRun = false;
   // static boolean createTrace = false; // create an execution trace of the program
    
        static boolean runTrace = true; // create a debugging session
        
        static WorkingModel workingModel = WorkingModel.simulationMode;
        //static boolean owlReasoner = true; // create a debugging session
     //static boolean runCompleteExe = false;
       //  static boolean runExeForDebugging = false;
        // static int debugFileId = 0;
     
         
    static String originalFile;

     //static String settingsInputOriginal;
    static String prefix;
    static String cFile;
    static String executableFile;
    static String dataFile;
    static String cfgFile;
    static String sparqlDebugCommandsFile;
    static String gdbDebugCommandsFile;
    static String traceFile;
    static Model modelWithProgramAndTrace;
    //static Model inferredModel;
    
    static String rulesFile = "src/main/resources/ForwardChaining/main.txt";
    static String swrlRulesFile = "src/main/resources/ForwardChaining/rdfSWRLRules.txt";
    static String programDebugWorkingOntology = "src/main/resources/ProgramDebuggingOntology.owl";
    static String programDebugOriginalOntology_ListModel = "src/main/resources/ProgramProperties.owl";
    static String programDebugOriginalOntology_SetModel  = "src/main/resources/ProgramProperties_SetModel.owl";
    static String programDebugOriginalOntology_ListRDFRulesModel  = "src/main/resources/ProgramProperties_RDFRules.owl";
    static String tempFile ="src/main/resources/testcases/tempFile.ttl";
  // static String programDebugWorkingOntology = "/home/aidb/Dropbox/BugFinderJena/src/main/resources/PAOntology.owl";
    //static String inferredFile;
    //static String queryFile;
 
    static long startTime;
    static long endTime;
    static long inferenceTime;
    
    static String rdfPrefix ="http://www.w3.org/1999/02/22-rdf-syntax-ns#";
    static String paPrefix ="http://www.semanticweb.org/aidb/ontologies/ProgramAnalysisOntology#";
    static String dbPrefix ="http://www.semanticweb.org/aidb/ontologies/ProgramDebuggingOntology#";
    static long time1;
    static Model modelOnlyWithSpans;
    static String inputFile = "";
    static String instrumentedExecutableFile;
    static String instrumentedFile;
    static int instrumentationHeaderDecl;
    static int instrumentationHeaderInit;
// main() function line number
    static String swrlbPrefix ="http://www.w3.org/2003/11/swrlb#";
    static long netTimeForQuery = 0;
    static long startTimeForQuery;
    static long endTimeForQuery;
    static long startTimeForAbstraction;
    static long endTimeForAbstraction;
    static long netTimeForAbstraction;
    static long startTimeForSimulationSession;
    static long endTimeForSimulationSession;
    static long netTimeForSimulationSession;
    static long startTime3;
    static long endTime3;
    static long netTime3;
    static long netTime;
    static long startimeReasonerLoad;
    static long endTimeReasonerLoad;
    static long netTimeReasonerLoad;
    static long startTimeTotalReasoning;
    static long endTimeTotalReasoning;
    static long netTimeTotalReasoning;
    
    


    enum QueryFunctors{
         getExecutionPathInFunction,break1,run,print;
    }
    
    
    enum AbstractionFunctors{
         CreateSpan, VariablesInTheSpan, Exit, 
         SpanTiming, StsInSpan, //CreateSpanWithFilter, CreateSpanWithMap
         SpanTimeInstant, timeInstantForAGivenState, st_var, st_var_sparql,
         CreateSpanSet
         ;
    }
    
    
    
    enum ReasoningFunctors{
         Span, IncreasingSpan,AllDistinctSpan,   AllNonZeroSpan, AllNonNegativeSpan, 
         SpanWithZeroElement, NegativeSpan, ListWithZeroElement, rdfList, AllNonZeroList, AllSameSpan,
         beforeSpanOf, distinctSpanOf, SpanWithNonZeroElement, notEqualSpanOf, 
         notNonEqualSpanOf, notNonEqualListOf, notBeforeSpanOf, NonDecreasingSpan, AllZeroSpan, NonIncreasingSpan, DecreasingSpan, 
         AllPostiveSpan, AllNegativeSpan, AllNonPositiveSpan, anyExistsAfterTime, exactlyOneExists, contiguousCells, anyExistsBeforeTime;
         public String uri() {
             
          return dbPrefix + this.toString().replaceAll("Non", "Non-");
      }
      
      public IRI iri() {
          return  IRI.create(uri());
      }
    
    }
    
    enum Abstractions{
        ValueSpan, ProgStateSpan,
        Tree, Graph, SpanWithFilter, SpanWithMap, SimulationSession;
    }
    
    public enum RDFKeywords {
    type,list,first,rest,nil;

    public String uri() {
        switch(this) {
            case type: return rdfPrefix + "type";
            case list: return rdfPrefix + "list";
            case first: return rdfPrefix + "first";
            case rest: return rdfPrefix + "rest";
            case nil: return rdfPrefix + "nil";
            
        }
        throw new RuntimeException("Case not implemented");
    }
    }
    
     // ValueSpan(?sliceName), hasItem(?sliceName,?item), correspondsTo(?item,?var), filteredItemBeginsAtTime(?item, ?fromTime), filteredItemEndsAtTime(?item, ?toTime).
    
    public enum PAKeywords {
    slice;
    
}
    
       public enum DBKeywords {
           rdfList,rdffirst,rdfrest,rdfnil,
    Span, hasItem, correspondsTo, filteredItemBeginsAtTime,
    filteredItemEndsAtTime, SpanWithDuplicates, SpanWithoutDuplicates,
    hasSpanCell, hasValue, index, timestamp, SpanCell,
    IncreasingSpan,NonIncreasingSpan,DecreasingSpan,NonDecreasingSpan,
    SpanWithPositiveElement,SpanWithNonPositiveElement, SpanWithNegativeElement,
    SpanWithNonNegativeElement,SpanWithZeroElement,SpanWithNonZeroElement,
    SpanWithTwoDistinctElements, beforeSpanOf,
    notEqualSpanOf,notNonEqualSpanOf, notGreaterThanSpanOf, notGreaterThanOrEqualSpanOf,
    notLessThanSpanOf,notLessThanOrEqualSpanOf;
    
    /*private String label;
      DBKeywords(String l){
         label = l;
     }

   /* public String uri() {
        switch(this) {
            case span: return  paPrefix + "ValueSpan";
            case hasItem: return  paPrefix + "hasItem";
            case correspondsTo: return  paPrefix + "correspondsTo";
            case filteredItemBeginsAtTime: return  paPrefix + "filteredItemBeginsAtTime";
            case filteredItemEndsAtTime: return  paPrefix + "filteredItemEndsAtTime";
        }
        throw new RuntimeException("Case not implemented");
    }
*/
      public String uri() {
          return dbPrefix + this.toString().replaceAll("Non", "Non-");
      }
      
      public IRI iri() {
          return  IRI.create(uri());
      }
    
}
    
}
