/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.ontodebugger;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.StringReader;
import java.io.StringWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;
import org.apache.jena.graph.Triple;
import org.apache.jena.query.QuerySolution;
import org.apache.jena.rdf.model.InfModel;
import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.rdf.model.Resource;
import org.apache.jena.rdf.model.Statement;
import org.apache.jena.rdf.model.StmtIterator;
import org.apache.jena.rdf.model.impl.StatementImpl;
import org.apache.jena.rdf.model.impl.StmtIteratorImpl;
import org.apache.jena.reasoner.Reasoner;
import org.apache.jena.reasoner.rulesys.GenericRuleReasonerFactory;
import org.apache.jena.shared.PrefixMapping;
import org.apache.jena.shared.impl.PrefixMappingImpl;
import org.apache.jena.util.PrintUtil;
import org.apache.jena.util.iterator.ExtendedIterator;
import org.apache.jena.util.iterator.Filter;
import org.apache.jena.vocabulary.ReasonerVocabulary;
import org.semanticweb.owlapi.model.OWLOntologyCreationException;

/**
 *
 * @author aidb
 */
public class Main {

    static List<CStatementLocation> stsWithLineNumbers = new ArrayList<>();
    static int breakPointNumber = 1;

    public static void main(String[] args) throws Exception, OWLOntologyCreationException {
//       System.out.println(args.length);
        ReadInput.readSettings();
        Settings.modelWithProgramAndTrace = ReadInput.getRawModel();
        CFile.readFile();

        /*   if(Settings.runCompleteExe){
            StringWriter debugCommandsFileWriter = CreateDebugFile.createDebugFileWithNoCommands();
            CreateDebugFile.editDebugCommandsFile(debugCommandsFileWriter);
            InputStream traceStream = Sparql.runDebugCommandsFile(Settings.sparqlDebugCommandsFile, "Full Exe run time");
        }

        if(Settings.runExeForDebugging){
           // StringWriter debugCommandsFileWriter = CreateDebugFile.createDebugFileWithNoCommands();
         //   CreateDebugFile.editDebugCommandsFile(debugCommandsFileWriter);
            InputStream traceStream = Sparql.runDebugCommandsFile(Settings.gdbDebugCommandsFile, "gdb debug commands run time");
        }
         */
       /* if (Settings.preProcessingRun) {
            Auxiliary.getNoBraceStatements();
            // Auxiliary.printNotSingleLineStatements();
            // Auxiliary.printTwoStatementsOnSameLine();
            System.exit(0);
        }
        */

        if (Settings.instrumentCode) {
            Utils.initialize();
            String instrumentationQuery = ReadInput.readInstrumentationQuery("varsAfterEachStatement");
            // System.out.println(instrumentationQuery);
            List<QuerySolution> instrumentationInfo = Sparql.executeQuery(instrumentationQuery, Settings.modelWithProgramAndTrace);
            Sparql.executeQueryAndPrint(instrumentationQuery, Settings.modelWithProgramAndTrace);

            //Expected fields in instrumentationInfo:  nextSt, entity | expression (for array index), type
            StringWriter debugCommandsFileWriter = CreateInstrumentedFile.createDebugCommandsFile(instrumentationInfo);
            CreateInstrumentedFile.editDebugCommandsFile(debugCommandsFileWriter, Settings.instrumentedFile);

            System.exit(0);
        }
//Settings.sparqlDebugCommandsFile
        /*    if (Settings.createTrace) {
            
           InputStream traceStream = Sparql.runDebugCommandsFile(Settings.sparqlDebugCommandsFile,"Trace generation time");
            createTraceFile(traceStream);
            // System.out.println(Settings.modelWithProgramAndTrace.size()+ "test1" );
            Settings.modelWithProgramAndTrace = ReadInput.getRawModel();
            //System.out.println(Settings.modelWithProgramAndTrace.size()+ "test2" );

        }
         */
        if(Settings.workingModel != Settings.WorkingModel.libraryAbstractions &&
                Settings.workingModel != Settings.workingModel.simulationMode)
        OntologyProcessor.init();
        
        Session.createSession();
        
        Settings.indexingBeginTime = System.currentTimeMillis();
        Sparql.init();
        Settings.indexingEndTime = System.currentTimeMillis();
        Settings.indexingNetTime = Settings.indexingEndTime - Settings.indexingBeginTime;
        System.out.println("\n Indexing time" + Settings.indexingNetTime + " milliseconds");
        
        //return;
        if(Settings.workingModel == Settings.WorkingModel.libraryAbstractions){
            List<String> testcases = ReadInput.readDefaultTests();
            
            for(String tc: testcases){
            Settings.startTimeForDefaultAbstractions = System.currentTimeMillis();    
                int noOfCmdLines = AutomatedTestcases.init(tc);
                for(int i =0 ; i < noOfCmdLines ; ++i){
                String cmdString = Session.getCmdLine();
                //System.out.println(cmdString);
                processCmdString(cmdString, false);
                }
                Settings.endTimeForDefaultAbstractions = System.currentTimeMillis();
                Settings.totalTimeForDefaultAbstractions += Settings.endTimeForDefaultAbstractions -
                        Settings.startTimeForDefaultAbstractions;
                System.out.println("\n Default Abstraction time" + Settings.totalTimeForDefaultAbstractions + " milliseconds");
                
            }
            
            return;
        }
        
        // OntologyProcessor. init();
        Settings.modelOnlyWithSpans = ModelFactory.createDefaultModel();
        AutomatedReasoningTests.init();//make automated testcases ready
        AutomatedQueryTests.init();
        boolean simulationMode = false;
        if (Settings.runTrace) {
            //String storeTrace = Utils.storeTrace();
            // OntologyProcessor. init(storeTrace);
            //String queryCmdId = null;
            while (true) {//User can input exactly one processable command. 
                //The below statement correpsonds to one or more user commands.
                String cmdString = Session.getCmdLine();
                if (cmdString.startsWith("exit")) {
                    break;
                }

                if (cmdString.startsWith("set SimulationMode on")) {
                    Settings.startTimeForSimulationSession = System.currentTimeMillis();
                    simulationMode = true;
                    continue;
                }

                if (cmdString.startsWith("set SimulationMode off")) {
                    simulationMode = false;
                    continue;
                }

                if (processCmdString(cmdString, simulationMode)) continue;
            }// infinite loop
//System.out.println(Settings.modelWithProgramAndTrace.size());
//System.out.println(Sparql.table.size());

        }

    }

    static boolean processCmdString(String cmdString, boolean simulationMode) throws Exception {
        CommandList commands = Session.parseCmds2(cmdString);
        if (simulationMode || CommandProcessor.isValidQueryCommand(commands)) {
            if (commands.size() == 1) {
                Boolean isDirectQuery = Session.processDirectQuery(commands.get(0));// There can be atmost 1 sparql queries
                if (isDirectQuery) {
                    return true;
                }
            } else {
                Boolean result = CommandProcessor.process(commands); // useful for simulation session
                if (result) {
                    return true;                    
                }
            }
        }
        if (CommandProcessor.isValidAbstractionCommand(commands)) {
            Settings.startTimeForAbstraction = System.currentTimeMillis();
            CommandProcessor.process(commands);
            //  Settings.modelOnlyWithSpans.add(CommandProcessor.process(commands));
            //  if(!Settings.userInteractionMode)
            //     printInferredStatements(Settings.modelWithProgramAndTrace, Settings.modelOnlyWithSpans);
            Settings.endTimeForAbstraction = System.currentTimeMillis();
            Settings.netTimeForAbstraction += Settings.endTimeForAbstraction - Settings.startTimeForAbstraction;
            return true;
        }
        //run the reasoner
        Settings.netTime = Settings.netTimeForAbstraction;// - Settings.netTime3;
        System.out.println("\n Abstraction time (including query time)" + Settings.netTime + " milliseconds");
        if (CommandProcessor.isValidReasoningCommand(commands)) {
            
            Settings.startTimeTotalReasoning = System.currentTimeMillis();
            if (Settings.workingModel == Settings.WorkingModel.listOWLRL) {
                BuiltInReasoner.reason2();
            }
            if (Settings.workingModel == Settings.WorkingModel.reasoningWithoutOntology ) {
                BuiltInReasoner.reasonWithoutOntology(commands);
            } else if (Settings.workingModel == Settings.WorkingModel.libraryAbstractions ) {
                BuiltInReasoner.reasonForDefaultAbstractions(commands);
            } else {
                OntologyProcessor.reason(commands);
            }
            Settings.endTimeTotalReasoning = System.currentTimeMillis();
            Settings.netTimeTotalReasoning = Settings.endTimeTotalReasoning
                    - Settings.startTimeTotalReasoning;
          /*  if (Settings.workingModel == Settings.WorkingModel.listOWLRL) {
                Settings.netTimeTotalReasoning -= Settings.netTime4;
            }
*/
            System.out.println("\n Reasoning time" + Settings.netTimeTotalReasoning + " milliseconds");
            
            if(Settings.workingModel != Settings.WorkingModel.libraryAbstractions)
            System.out.println("Ind count:" + OntologyProcessor.ontology.getIndividualsInSignature().size());
            // Session.processReasoningQuery(commands);
            
        }
        return false;
    }

    private static void createTraceFile(InputStream traceStream) throws IOException {

        String arrayValues;
        PrintWriter pw = new PrintWriter(new FileWriter(Settings.traceFile));
        pw.write(Utils.prefixInTTLFile(ReadInput.prefix));
        pw.write("\n\n\n");

        BufferedReader reader = new BufferedReader(new InputStreamReader(traceStream));
        String line = "";
        while ((line = reader.readLine()) != null) {
            if (line.startsWith("zzz")) {
                pw.write(line.substring(3) + " .\n");
            } else if (line.contains("zzArrayBegin")) {
                arrayValues = Utils.getArrayValues(reader.readLine());
                String nextLine = reader.readLine();
                pw.write(nextLine.replace("zzArrayEnd", arrayValues));
            }
        }
        reader.close();
        pw.close();

    }

}
