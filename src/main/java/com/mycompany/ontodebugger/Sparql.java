/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.ontodebugger;

import com.google.common.collect.HashBasedTable;
import com.google.common.collect.Table;
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import org.apache.jena.query.Query;
import org.apache.jena.query.QueryExecution;
import org.apache.jena.query.QueryExecutionFactory;
import org.apache.jena.query.QueryFactory;
import org.apache.jena.query.QuerySolution;
import org.apache.jena.query.ResultSet;
import org.apache.jena.query.ResultSetFactory;
import org.apache.jena.query.ResultSetFormatter;
import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.sparql.resultset.ResultsFormat;

/**
 *
 * @author aidb
 */
public class Sparql {

    
    static Table<String, String, List<VariableState>> table = HashBasedTable.create();
    static HashMap<String,TreeMap<Integer,VariableState>> tree =new HashMap<>();;

    public static void init() {
        String query = ReadInput.readInstrumentationQuery("getTraceInformation");
        //System.out.println(query);
        List<QuerySolution> results = Sparql.executeQuery(query, Settings.modelWithProgramAndTrace);
         //  Sparql.executeQueryAndPrint(query, Settings.modelWithProgramAndTrace);
        String prevSt = null, st = null, prevVar = null, var = null;
        List<VariableState> vsList = new ArrayList<>();
        for (QuerySolution qs : results) {
            //if(qs.get("?var") == null){
             //   var="0_0_0_0";
            //} else 
            var = qs.get("?var").toString();
            st = qs.get("?st").toString();
            VariableState vs = new VariableState(var, st, qs.get("?time"),
                     qs.get("?val"));
            
            TreeMap<Integer, VariableState> treeMapOfVariable = getTreeMapOfVariable(Utils.shortURI(var));
            treeMapOfVariable.put(Integer.valueOf(qs.get("?time").asLiteral().getInt()), vs);
          
            
            //table data structure code
            if (prevVar != null && prevSt != null) {
                if (!(var.equals(prevVar) && st.equals(prevSt))) {
                    //System.out.println(prevVar + " " + prevSt + " " +vsList.size());
                    table.put(Utils.shortURI(prevVar), Utils.shortURI(prevSt), vsList);
                    vsList = new ArrayList<>();
                } 
            } 
            vsList.add(vs);

            prevVar = var;
            prevSt = st;
        }
        //System.out.println(var + " " + st + " " +vsList.size());
        table.put(prevVar, prevSt, vsList);
        //Sparql.executeQueryUsingHashing(table.values());
       /* System.out.println(table.size());
        //System.out.println(table.toString());
        query = ReadInput.readInstrumentationQuery("getTraceInformation_test");
        results = Sparql.executeQuery(query, Settings.modelWithProgramAndTrace);
        System.out.println(results.size());
        Sparql.executeQueryAndPrint(query, Settings.modelWithProgramAndTrace);
        */
        

    }
    
    private static TreeMap<Integer, VariableState> getTreeMapOfVariable(String var) {
        if(tree.containsKey(var))
            return tree.get(var);
        else{
            TreeMap<Integer, VariableState> treeMap = new TreeMap<>();
            tree.put(var, treeMap);
            return treeMap;
                }
    }
    
    static List<QuerySolution> executeQueryUsingHashing(List<String> varParameter, List<String> stParameter) {
        Collection<List<VariableState>> vsLists = new ArrayList<>() ;
        
        for(String var: varParameter){
            for(String st: stParameter){
                List<VariableState> result = table.get(var, st);
                if(result == null){ // happens when the value of the variable at that statement isn't stored
                    /* List<VariableState> temp = new ArrayList<>();
                    //Collection<List<VariableState>> values = table.column(st).values();
                    Stream<String> flatMap = table.column(st).values().stream().flatMap(p -> p.stream().map(q -> q.timeURI)).distinct();
                    List<String> collect = flatMap.collect(Collectors.toList());
                    collect.forEach(
                    q-> {
                    VariableState vs = new VariableState(Utils.longURI(var), Utils.longURI(st), q, null);
                    temp.add(vs);
                    }
                    );
                    table.put(var, st, temp);
                    //temp.clear();
                    vsLists.addAll(table.row(var).values());
                     */
                    List<VariableState> temp = new ArrayList<>();
                    
                    //time instants at which the statement is executed
                    List<Integer> timeSought = table.column(st).values().stream().flatMap(p -> p.stream().map(q -> q.time))
                            .distinct().collect(Collectors.toList());
                    for(Integer ts: timeSought){
                        VariableState vs = tree.get(var).floorEntry(ts).getValue();
                        
                    temp.add(new VariableState(var, st,
                            ModelFactory.createDefaultModel().createTypedLiteral(ts), 
                            vs.valueNode));
                    }
                    
                    
                    //table.put(var, st, temp );
                    vsLists.add(temp);
                   
                } else{
                vsLists.add(result);
                }
            }
        }
        return executeQueryUsingHashing(vsLists);
    }
    
    static List<QuerySolution> executeQueryUsingHashing(List<String> varsInSpan, String fromTime, String toTime) {
        int ft = Integer.getInteger(fromTime);
        int tt = Integer.getInteger(toTime);
        Collection<List<VariableState>> vsLists = new ArrayList<>() ;
        for(String var: varsInSpan){
            vsLists.addAll(table.row(var).values());
        }
        List<QuerySolution> interimResults = executeQueryUsingHashing(vsLists);
        List<QuerySolution> finalResults = interimResults.stream().filter(p -> p.get("?time").asLiteral().getInt() >= ft &&
                p.get("?time").asLiteral().getInt() <= tt).collect(Collectors.toList());
        return finalResults;
    }
    
    public static List<QuerySolution> executeQueryUsingHashing(Collection<List<VariableState>> values ){
        StringBuilder sb = new StringBuilder();
        sb.append("var,st,val,time").append("\n");
        for(List<VariableState> vsList : values){
          //  Stream<VariableState> distinct = vsList.stream().distinct();
            //distinct.forEach(p -> sb.append(p.getCSVString()).append("\n"));
            for(VariableState vs: vsList ){
                sb.append(vs.getCSVString()).append("\n");
            }
        }
        
        InputStream is = new ByteArrayInputStream( sb.toString().getBytes() );
        ResultSet resultSet = ResultSetFactory.load(is, ResultsFormat.FMT_RS_CSV);
        //ResultSetFormatter.out(resultSet);
        List<QuerySolution> resultList = ResultSetFormatter.toList(resultSet);
        return resultList;
    }

    
    
    
    public static List<QuerySolution> executeQuery(String sparqlQuery, Model model) {

        Query query = QueryFactory.create(sparqlQuery);
        QueryExecution qe = QueryExecutionFactory.create(sparqlQuery, model);
        ResultSet results2 = qe.execSelect();
        // ResultSet results = ResultSetFactory.copyResults( results2 );
        //ResultSetFormatter.out(System.out, results2, query) ;
        //
        //results.
        
        java.util.List<QuerySolution> qs = ResultSetFormatter.toList(results2);
        
        return qs;
    }

    public static void executeQueryAndPrint(String sparqlQuery, Model model) {

        Query query = QueryFactory.create(sparqlQuery);
        QueryExecution qe = QueryExecutionFactory.create(sparqlQuery, model);
        ResultSet results2 = qe.execSelect();
        // ResultSet results = ResultSetFactory.copyResults( results2 );
        ResultSetFormatter.out(System.out, results2, query);
        //ResultSetFormatter.out(results2);
       // ResultSetFormatter.outputAsCSV(results2);

    }
    
    public static void executeQueryAndPrint(String sparqlQuery, Model model, boolean measureTime) {

        Query query = QueryFactory.create(sparqlQuery);
        Settings.startTime = System.currentTimeMillis();
        QueryExecution qe = QueryExecutionFactory.create(sparqlQuery, model);
        
        ResultSet results2 = qe.execSelect();
                    

        ResultSet results = ResultSetFactory.copyResults( results2 );
        
         Settings.endTime = System.currentTimeMillis();
       Settings.inferenceTime = Settings.endTime - Settings.startTime;
       ResultSetFormatter.out(System.out, results, query);
        System.out.println("\nBackward chaining time:" + Settings.inferenceTime + " milliseconds");
        //
        //results.

    }

    
    public static InputStream runDebugCommandsFile(String commandFile, String msg) {

        Process proc = null;

        try {
           // runShellScript("src/main/resources/compile.sh",dataFile);
            Settings.startTime = System.currentTimeMillis();
            proc = runShellScript("src/main/resources/run.sh",commandFile);
           
    
             /*         BufferedReader reader = new BufferedReader(new InputStreamReader(proc.getInputStream()));
                        String line = "";                       
                        StringBuffer output = new StringBuffer();
                        while ((line = reader.readLine())!= null) {
                                output.append(line + "\n");
                        }
                        System.out.println("### " + output);
            */               Settings.endTime = System.currentTimeMillis();
            Settings.inferenceTime = Settings.endTime - Settings.startTime;
           
                         System.out.println( "\n "+ msg +":1xxyy" + Settings.inferenceTime + " milliseconds");
            
        } catch (Throwable t) {
            t.printStackTrace();
        }
        return proc.getInputStream();

//        System.out.print(al.size() + ",");
 //       return al;

    }

    static Process runShellScript(String loc,String arg) throws IOException {
        
        try {
            //String target = new String(loc);
            Runtime rt = Runtime.getRuntime();
            Process proc = rt.exec(loc + " " + Settings.executableFile + " " + arg);
            proc.waitFor();
            return proc;
        } catch (InterruptedException ex) {
            Logger.getLogger(Sparql.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }

    

    

    

}
