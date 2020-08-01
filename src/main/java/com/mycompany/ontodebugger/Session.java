/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.ontodebugger;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Pattern;
import java.util.stream.Collectors;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathFactory;
import org.apache.jena.query.QuerySolution;
import org.apache.jena.rdf.model.InfModel;
import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.rdf.model.Resource;
import org.apache.jena.rdf.model.Statement;
import org.apache.jena.reasoner.Reasoner;
import org.apache.jena.reasoner.rulesys.GenericRuleReasonerFactory;
import org.apache.jena.vocabulary.ReasonerVocabulary;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

/**
 *
 * @author aidb
 */
public class Session {

    static List<String> SessionSparqlQueries = new ArrayList<>();
    static Map<String, Settings.QueryFunctors> queryFunctorStringMap = new HashMap<>();
    static Map<String, Settings.AbstractionFunctors> abstractionFunctorStringMap = new HashMap<>();
    static Map<String, Settings.ReasoningFunctors> reasoningFunctorStringMap = new HashMap<>();
    static List<BreakPoint> breakPoints = new ArrayList<>();
    //static StringBuffer stParameter = new StringBuffer();
    static List<String> stParameter = new ArrayList<String>();
    static List<String> varParameter = new ArrayList<String>();
    static List<SessionSpan> sessionSpans = new ArrayList<>();
        

    static void createSession() {
       queryFunctorStringMap.put("getExecutionPathInFunction", Settings.QueryFunctors.getExecutionPathInFunction);
       queryFunctorStringMap.put("break1", Settings.QueryFunctors.break1);
       queryFunctorStringMap.put("run", Settings.QueryFunctors.run);
       queryFunctorStringMap.put("print", Settings.QueryFunctors.print);
        
       abstractionFunctorStringMap.put("CreateSpan", Settings.AbstractionFunctors.CreateSpan);
      // abstractionFunctorStringMap.put("CreateSpanWithFilter", Settings.AbstractionFunctors.CreateSpanWithFilter);
      // abstractionFunctorStringMap.put("CreateSpanWithMap", Settings.AbstractionFunctors.CreateSpanWithMap);
       abstractionFunctorStringMap.put("Exit", Settings.AbstractionFunctors.Exit);
       abstractionFunctorStringMap.put("VarsInSpan", Settings.AbstractionFunctors.VariablesInTheSpan);
       abstractionFunctorStringMap.put("StsInSpan", Settings.AbstractionFunctors.StsInSpan);
       abstractionFunctorStringMap.put("SpanTimeInstant", Settings.AbstractionFunctors.SpanTimeInstant);
        abstractionFunctorStringMap.put("SpanTiming", Settings.AbstractionFunctors.SpanTiming);
       abstractionFunctorStringMap.put("timeInstantForAGivenState", Settings.AbstractionFunctors.timeInstantForAGivenState);
       abstractionFunctorStringMap.put("st_var", Settings.AbstractionFunctors.st_var);
       abstractionFunctorStringMap.put("st_var_sparql", Settings.AbstractionFunctors.st_var_sparql);
       abstractionFunctorStringMap.put("CreateSpanSet", Settings.AbstractionFunctors.CreateSpanSet);
       
       reasoningFunctorStringMap.put("IsAllDistinctSpan", Settings.ReasoningFunctors.AllDistinctSpan);
       reasoningFunctorStringMap.put("IsAllSameSpan", Settings.ReasoningFunctors.AllSameSpan);
       reasoningFunctorStringMap.put("IsIncreasingSpan", Settings.ReasoningFunctors.IncreasingSpan);
       reasoningFunctorStringMap.put("IsNonDecreasingSpan", Settings.ReasoningFunctors.NonDecreasingSpan);
       reasoningFunctorStringMap.put("IsAllNonZeroSpan", Settings.ReasoningFunctors.AllNonZeroSpan);
       reasoningFunctorStringMap.put("IsAllZeroSpan", Settings.ReasoningFunctors.AllZeroSpan);
       reasoningFunctorStringMap.put("IsSpanWithNon-ZeroElement", Settings.ReasoningFunctors.SpanWithNonZeroElement);
       reasoningFunctorStringMap.put("IsAllNonNegativeSpan", Settings.ReasoningFunctors.AllNonNegativeSpan);
       reasoningFunctorStringMap.put("IsZeroSpan", Settings.ReasoningFunctors.SpanWithZeroElement);
       reasoningFunctorStringMap.put("IsZeroList", Settings.ReasoningFunctors.ListWithZeroElement);
       reasoningFunctorStringMap.put("IsAllNonZeroList", Settings.ReasoningFunctors.AllNonZeroList);
       reasoningFunctorStringMap.put("IsNegativeSpan", Settings.ReasoningFunctors.NegativeSpan);
       reasoningFunctorStringMap.put("IsBeforeSpanOf", Settings.ReasoningFunctors.beforeSpanOf);
       reasoningFunctorStringMap.put("IsEqualSpanOf", Settings.ReasoningFunctors.notEqualSpanOf);
       reasoningFunctorStringMap.put("anyExistsAfterTime", Settings.ReasoningFunctors.anyExistsAfterTime);
       reasoningFunctorStringMap.put("anyExistsBeforeTime", Settings.ReasoningFunctors.anyExistsBeforeTime);
       reasoningFunctorStringMap.put("exactlyOneExists", Settings.ReasoningFunctors.exactlyOneExists);
       reasoningFunctorStringMap.put("interleaved", Settings.ReasoningFunctors.contiguousCells);
       
        System.out.println("Enter your commands below seperated by . and press return key");
        displayPrompt();
    }

    //static int counter = 0;
    //static String[] autoCommands = {"CreateSlice(file0:S1,3,4).","exit."};
    static String getCmdLine() {
        if (Settings.userInteractionMode) {
            Scanner scan = new Scanner(System.in);
            return scan.nextLine();
        } else {
            if(Settings.workingModel == Settings.WorkingModel.simulationMode)
                return AutomatedQueryTests.getNextCommand();
            else if(Settings.workingModel == Settings.WorkingModel.libraryAbstractions)
                return AutomatedTestcases.getNextCommand();
            else
            return AutomatedReasoningTests.getNextCommand();
        }
    }

    private static void displayPrompt() {
        System.out.print(">");
    }

    static List<Statement> parseCmds(String cmd) {
        List<Statement> stList = new ArrayList<>();
        Scanner scan = new Scanner(cmd);
        scan.useDelimiter("[.]");
        //System.out.println(scan.hasNext());
        Pattern pattern = Pattern.compile("[^)]+\\)$");

        while (scan.hasNext()) {
            // check if the token consists of declared pattern
            //System.out.println(scan.hasNext());
            //if (scan.hasNext(pattern)) {
            Command c = new Command(scan.next());
            Statement s = c.getStatement();
            stList.add(s);
            /*}
            else{
                //write code for error in syntax
            }
             */
        }
        return stList;
    }

    static CommandList parseCmds2(String cmd) {
        //List<Command> stList = new ArrayList<>();
        CommandList stList = new CommandList();
        //Scanner scan = new Scanner(cmd);
        //scan.useDelimiter(";");
        String[] split = cmd.split(";");
        Pattern pattern = Pattern.compile("[^)]+\\)$");

       /* while (scan.hasNext()) {
           Command c = new Command(scan.next());
            stList.add(c);
         }
        */
       for(int i =0; i< split.length; ++i){
           Command c = new Command(split[i]);
            stList.add(c);
       }
        return stList;
    }

    public static Model processRules(String fileloc, Model modelIn) {
        // create a simple model; create a resource  and add rules from a file 

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

        return infmodel;

    }

    static Boolean processDirectQuery(Command c) {

        //Command c = commands.get(0);
        String args = null;
        if(c.args != null && c.args.size() > 0)
            args = c.args.get(0);
        return processQuery(c.functorName, args , null,
                "src/main/resources/directQuery.xml",
                Settings.modelWithProgramAndTrace);

    }

   /* static Boolean processReasoningQuery(CommandList commands) {
        Command c = commands.get(0);
        return processQuery(c.functorName,  c.args.get(1),"src/main/resources/reasoningQuery.xml", 
                Settings.modelOnlyWithSpans);

    }
    */
    
    static Boolean processDebugCommandQuery(BreakPointCommandList bpcl) {
       return processQuery(bpcl.breakPointCmd.functorName, bpcl.breakPointCmd.args.get(0),
                bpcl.variablesToBePrinted(),
                "src/main/resources/directQuery.xml",
                Settings.modelWithProgramAndTrace);
        
        
    }

    private static Boolean processQuery(String queryId, String par, List<String> variables, String xmlFile, Model model) {
        /*  if(SessionSparqlQueries.isEmpty()){
        Document doc = ReadInput.getXMLDocument("src/main/resources/session_sparql.xml");
        XPath xpath = XPathFactory.newInstance().newXPath();
        
        String expression = "//query/@id";
        NodeList nodes = (NodeList) xpath.evaluate(expression, doc, XPathConstants.NODESET);
        for (int j = 0; j < nodes.getLength(); j++)
        SessionSparqlQueries.add(nodes.item(j).getTextContent());
        }
        
        Optional<Command> findAny = commands.stream().filter(p -> SessionSparqlQueries.contains(p.functorName)).findAny();
        if(findAny.isPresent())
        return findAny.get().command;
        return null;
         */
        
        int nextIndex = 0;
        boolean runMode =false;
        if(queryId.equals("run")){
            
            /*zzz:sparql_approach 
            LinkedHashSet<String> varParameterHash = new LinkedHashSet(varParameter);
            String varParameterString = String.join(",", varParameterHash);
            LinkedHashSet<String> stParameterHash = new LinkedHashSet(stParameter);
             String stParameterString = String.join(",", stParameterHash);
             String newQuery = getModifiedQuery("break1", xmlFile, stParameterString,varParameterString);
              List<QuerySolution> valuesAtBreakPoint = Sparql.executeQuery(newQuery, Settings.modelWithProgramAndTrace);
           */
              List<QuerySolution> valuesAtBreakPoint = Sparql.executeQueryUsingHashing(
                      varParameter.stream().distinct().collect(Collectors.toList()),stParameter);
              
              System.out.println(valuesAtBreakPoint);
            //breakPoints.add(new BreakPoint(par, valuesAtBreakPoint));
            valuesAtBreakPoint.forEach( p -> {
               // if(variables.contains(p.get("var").toString()))
                breakPoints.add(new BreakPoint(p.get("?st").toString(), p.get("?var").toString(),
                p.get("?val").toString(), p.get("?time").toString()));
            }
            );
            Collections.sort(breakPoints, Comparator.comparingInt(c -> c.time));
            //simulationTime = 1;
           // runMode = true;
           while(true){
            BreakPoint nextBPInfo = breakPoints.get(nextIndex);
            //System.out.println(nextBPInfo.executionInfo);
            for(;nextIndex <= breakPoints.size() &&
                    breakPoints.get(nextIndex).st.equals(nextBPInfo.st); nextIndex++){
                System.out.println("var:" + Utils.shortURI(breakPoints.get(nextIndex).var) + " " +
                        "st:" + Utils.shortURI(breakPoints.get(nextIndex).st)+ " "+
                        "val:" + breakPoints.get(nextIndex).val);
                if(breakPoints.size() - 1 == nextIndex){
                      Settings.endTimeForSimulationSession = System.currentTimeMillis();
        Settings.netTimeForSimulationSession = Settings.endTimeForSimulationSession - 
                Settings.startTimeForSimulationSession ;
         System.out.println("Debug session total time: " + Settings.netTimeForSimulationSession +" milliseconds");
                    return true;
                }
            }
           }
        }
        
        if(queryId.equals("continue")){
           
        }
        
        if(queryId.equals("getExecutionPathInFunction") || queryId.startsWith("break")){

        
        
        if(queryId.equals("getExecutionPathInFunction")){
            String newQuery = getModifiedQuery(queryId, xmlFile, par);
         Settings.startTimeForQuery = System.currentTimeMillis();
        Sparql.executeQueryAndPrint(newQuery, Settings.modelWithProgramAndTrace);
        Settings.endTimeForQuery = System.currentTimeMillis();
        Settings.netTimeForQuery += Settings.endTimeForQuery - Settings.startTimeForQuery;
       System.out.println("Query time1: " + Settings.netTimeForQuery +" milliseconds");
        }
        
        else{
            //if(stParameter.length() == 0)
          //stParameter.append(par);
            //else
                //stParameter.append(",").append(par);
            stParameter.add(par);
          
          varParameter.addAll(variables);
         
        }
        return true;
        }
        return true;
    }

    static String getModifiedQuery(String queryId, String xmlFile, String par) {
        String sessionQuery = ReadInput.readSessionSparqlQuery(queryId, xmlFile);
        if (sessionQuery == null) {
            System.out.println("give correct queryId");
        }
        String newQuery = sessionQuery.replaceAll("zz_st", par);
       // System.out.println(newQuery);
        return newQuery;
    }

    static String getModifiedQuery(String queryId, String xmlFile, String par, String varPar) {
        String sessionQuery = ReadInput.readSessionSparqlQuery(queryId, xmlFile);
        if (sessionQuery == null) {
            System.out.println("give correct queryId");
            System.exit(0);
        }
        String newQuery = sessionQuery.replaceAll("zz_st", par).replaceAll("zz_var", varPar);
        System.out.println(newQuery);
        return newQuery;
    }

    static List<QuerySolution> getTimingForState_Query(Command queryCmd) {
        String queryId = queryCmd.functorName;
                String par = queryCmd.args.get(1);
                String xmlFile = "src/main/resources/directQuery.xml"; 
                Model model = Settings.modelWithProgramAndTrace;
        
                String sessionQuery = ReadInput.readSessionSparqlQuery(queryId, xmlFile);
        if (sessionQuery == null) {
            return null;
        }
        String newQuery = sessionQuery.replaceAll("}", "filter (" + par +")}");
        // System.out.println(newQuery);
        // Sparql.executeQueryAndPrint(newQuery, Settings.modelWithProgramAndTrace);
           Settings.startTimeForQuery = System.currentTimeMillis();
          // Sparql.executeQueryAndPrint(newQuery, Settings.modelWithProgramAndTrace,true);
        List<QuerySolution> queryResult = Sparql.executeQuery(newQuery, model);
        
          Settings.endTimeForQuery = System.currentTimeMillis();
        Settings.netTimeForQuery += Settings.endTimeForQuery - Settings.startTimeForQuery;
       System.out.println("Query time1: " + Settings.netTimeForQuery +" milliseconds");
        return queryResult;
    }

    

}
