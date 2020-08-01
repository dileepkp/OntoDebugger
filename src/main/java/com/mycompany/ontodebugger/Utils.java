/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.ontodebugger;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.StringReader;
import java.io.StringWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.function.Function;
import java.util.function.Predicate;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.apache.jena.graph.Node;
import org.apache.jena.graph.NodeFactory;
import org.apache.jena.graph.Triple;
import org.apache.jena.graph.impl.LiteralLabelFactory;
import org.apache.jena.query.QuerySolution;
import org.apache.jena.rdf.model.Literal;
import org.apache.jena.riot.RDFDataMgr;
import org.apache.jena.riot.RDFFormat;
import org.semarglproject.vocab.RDF;

/**
 *
 * @author aidb
 */
public class Utils {

    static Map<String, String> scalarDataTypes = new HashMap<>();
    static Map<String, String> exitStToNextSt = new HashMap<>();
    //static Map<String, String> bpDependencies = new HashMap<>();
    static List<Pair> bpDependencies = new ArrayList<>();
    static List<CStatementLocation> statementsForBraces = new ArrayList<>();
static Map<Integer, String> newLinesInstrumentedCode = new HashMap<>();
// new lines in instrumented code because of ;else statments

    static void initialize() throws Exception {
        intializeDataTypes();
        initializeExitStatementInfo();
      //  initializeSingleStatmentBlock();
      
    }

    private static void intializeDataTypes() {
        scalarDataTypes.put("c:char", "%c");
        scalarDataTypes.put("c:wchar", "%c");
        scalarDataTypes.put("c:float", "%f");
        scalarDataTypes.put("c:double", "%f");
        scalarDataTypes.put("c:long_double", "%Lf");
        scalarDataTypes.put("c:int", "%d");
        scalarDataTypes.put("c:short", "%d");
        scalarDataTypes.put("c:long_long", "%lld");
        scalarDataTypes.put("c:long", "%li");
        scalarDataTypes.put("c:signed_char", "%c");
        scalarDataTypes.put("c:signed_int", "%d");
        scalarDataTypes.put("c:signed_long", "%li");
        scalarDataTypes.put("c:signed_long_long", "%lld");
        scalarDataTypes.put("c:signed_short", "%d");
        scalarDataTypes.put("c:unsigned_char", "%c");
        scalarDataTypes.put("c:unsigned_long", "%lu");
        scalarDataTypes.put("c:unsigned_long_long", "%llu");
        scalarDataTypes.put("c:unsigned_short", "%hu");
        scalarDataTypes.put("c:unsigned_int", "%u");
        //scalarDataTypes.put("c:pointer_type", "%lu");
    }

    
//http://www.semanticweb.org/yzhao30/ontologies/2015/7/c#int

    static String getFormatType(CEntity var) {
        
      //  if(var.cType == null)
        //    System.out.print(var);

        if (var.cType!= null && isCharType(var.cType) && var.baseType != null &&var.baseType.equals("c:array_type")) {
            return "%s";
        } else if (var.cType!= null && var.cType.equals("c:pointer_type") && var.baseType != null 
                && isCharType(var.baseType)) {
            return "%s";
        } else if (var.cType!= null && var.cType.equals("c:pointer_type") ) {
            if( !isScalarType(var.baseType))
            return "%lu";
            else return scalarDataTypes.get(var.baseType);
        }{
            return scalarDataTypes.get(var.cType);
        }
        
    }
    
    
    static boolean isCharType(String type){
        if(type.equals("c:char") || type.equals("c:unsigned_char")  )
            return true;
        return false;
    }
     
      
         static StringWriter createDebugCommandsFile(List<String> input) throws IOException {
        // BufferedWriter debugFileWriter = new BufferedWriter(new FileWriter(Settings.sparqlDebugCommandsFile));
         
        List<String> cCodeLines = input;
        int prevLine = 0;
        
        StringWriter sw = new StringWriter();
        PrintWriter debugFileWriter = new PrintWriter(sw);
            debugFileWriter.println();
       
        for(; prevLine < cCodeLines.size(); ++prevLine)
                debugFileWriter.println(cCodeLines.get(prevLine));
            
        debugFileWriter.flush();
        
        debugFileWriter.close();
        return sw;
    }
 
      
 /*    private static void initializeSingleStatmentBlock() {
        String instrumentationQuery = ReadInput.readInstrumentationQuery("singleStatementBlocks");
        System.out.println(instrumentationQuery);
        List<QuerySolution> singleStBlockInfo = Sparql.executeQuery(instrumentationQuery, Settings.modelWithProgramAndTrace);
       Sparql.executeQueryAndPrint(instrumentationQuery, Settings.modelWithProgramAndTrace);
 
       
       for(QuerySolution qs: singleStBlockInfo){
            String ifTrueSt = qs.get("trueSt").toString();
            String ifFalseSt = qs.get("falseSt").toString();
           addBraces(ifTrueSt);
           addBraces(ifFalseSt);
       }
       
    } */
     
        private static void addBraces(String st) {
        CStatementLocation csl = new CStatementLocation(st);
        if(csl.isExitStatement) 
            return;
        CFile.setFirstCharcterBefore(csl.beginLine, csl.beginCol,csl);
        //CFile.setFirstCharcterAfter(csl.endLine, csl.endCol);
    }

   


    private static void initializeExitStatementInfo() {
        String instrumentationQuery = ReadInput.readInstrumentationQuery("exitStatementInfo");
       // System.out.println(instrumentationQuery);
        List<QuerySolution> instrumentationInfo = Sparql.executeQuery(instrumentationQuery, Settings.modelWithProgramAndTrace);
      // Sparql.executeQueryAndPrint(instrumentationQuery, Settings.modelWithProgramAndTrace);
       int prevCount = -1;

       while(true){
        for (QuerySolution qs : instrumentationInfo) {
            String exitSt = qs.get("exitSt").toString();
            String nextSt = qs.get("nextSt").toString();
            if(!nextSt.endsWith("exit"))
            exitStToNextSt.put(exitSt, nextSt);
            else{
                String nextSt2 = Utils.exitStToNextSt.get(nextSt);
                if(nextSt2 != null && !nextSt2.endsWith("exit"))
            exitStToNextSt.put(exitSt, nextSt2);
            
            }
        }
        if(prevCount == Utils.exitStToNextSt.size())
            break;
        else prevCount = Utils.exitStToNextSt.size();
       }
       
       //System.out.println((Utils.exitStToNextSt));

    }

  /*  private static void initializeBreakPointDependencies() {
        String instrumentationQuery = ReadInput.readInstrumentationQuery("breakPointDependencies");
      //  System.out.println(instrumentationQuery);
        List<QuerySolution> instrumentationInfo = Sparql.executeQuery(instrumentationQuery, Settings.modelWithProgramAndTrace);
       // Sparql.executeQueryAndPrint(instrumentationQuery, Settings.modelWithProgramAndTrace);

       // if(!instrumentationInfo.isEmpty())
        for (QuerySolution qs : instrumentationInfo) {
            String predSt = qs.get("predSt").toString();
            String succSt = qs.get("succSt").toString();
            bpDependencies.add(new Pair(predSt, succSt));
        }

    }
*/    
    static boolean isScalarType(String cType) {
        return scalarDataTypes.containsKey(cType);
    }

    static boolean isArrayMemberAccess(String rdfType) {
        if(rdfType != null && rdfType.endsWith("ArraySub"))
            return true;
        return false;
    }

    static boolean isArrayType(String cType) {
        if(cType != null && cType.endsWith("array_type"))
            return true;
        return false;
    }
    
    static boolean isPointerToComplexType(String cType, String baseType) {
    //     if(cType != null && cType.endsWith("pointer_type") && !isScalarType(baseType))
         if(cType != null && cType.endsWith("pointer_type"))
            return true;
        return false;
    }
    
    static boolean isPointerToSimpleType(String cType, String baseType) {
        if(cType != null && cType.endsWith("pointer_type") && isScalarType(baseType))
            return true;
        return false;
    }

static boolean isPointerToSimpleTypeExceptChar(String cType, String baseType) {
        if(cType != null && baseType!= null && !baseType.endsWith("char") && cType.endsWith("pointer_type") && isScalarType(baseType))
            return true;
        return false;
    }
    static String getArrayValues(String line) {
        int bi = line.indexOf('{');
        int ei = line.indexOf('}');
        return line.substring(bi, ei);
        
    }

    static String prefixInTTLFile(String prefix) {
        return prefix.replaceAll("PREFIX", "@prefix");
    }

    static String storeTrace() {
        FileOutputStream fout = null;
        String file = "src/main/resources/testcases/temp.ttl";
        try {
            fout = new FileOutputStream(file);
            RDFDataMgr.write(fout, Settings.modelWithProgramAndTrace,RDFFormat.TURTLE_FLAT) ;
            
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Utils.class.getName()).log(Level.SEVERE, null, ex);
        } 
        return file;
             
    }
    
    static Triple createTriple(String s, String p, String o){
        Node subject = NodeFactory.createURI(s);
        Node pred = NodeFactory.createURI(p);
        Node obj = NodeFactory.createURI(o);
        Triple tr = new Triple(subject,pred, obj);
        return tr;
    }

    static Triple createTriple(String s, String p, int o) {
        Node subject = NodeFactory.createURI(s);
        Node pred = NodeFactory.createURI(p);
        Node obj = NodeFactory.createLiteral(LiteralLabelFactory.createTypedLiteral(o));
        Triple tr = new Triple(subject,pred, obj);
        return tr;
    }

    static List<Triple> createRDFList(String rdfListURI, List<Literal> oneVarStates) {
        List<Triple> triples = new ArrayList<>();
        triples.add(createTriple(rdfListURI,RDF.TYPE,RDF.LIST));
        
        return triples;
    }

 
public static String getHeader() {
       String s = "@prefix c: <http://www.semanticweb.org/yzhao30/ontologies/2015/7/c#> .\n"+
"@prefix owl: <http://www.w3.org/2002/07/owl#> .\n"+
"@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .\n"+
"@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n"+
"@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .\n"+
"@prefix pa: <http://www.semanticweb.org/aidb/ontologies/BugFindingOntology#> .\n"+
"@prefix pdo: <http://www.semanticweb.org/aidb/ontologies/ProgramDebuggingOntology#> .\n"+
               "\n\n";
       return s;
    }    

    static String getHeaderWithFile0() {
       String s = "@prefix c: <http://www.semanticweb.org/yzhao30/ontologies/2015/7/c#> .\n"+
               "@prefix file0: <" + Settings.prefix +"#> .\n"+
"@prefix owl: <http://www.w3.org/2002/07/owl#> .\n"+
"@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .\n"+
"@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n"+
"@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .\n"+
"@prefix pa: <http://www.semanticweb.org/aidb/ontologies/BugFindingOntology#> .\n"+
"@prefix pdo: <http://www.semanticweb.org/aidb/ontologies/ProgramDebuggingOntology#> .\n"+
               "\n\n";
       return s;
    }

    static String shortURI(String st) {
        String s = st.replaceAll(Settings.prefix + "#", "file0:");
        return s;
    }
    
    static String longURI(String st) {
        String s = st.replaceAll( "file0:", Settings.prefix + "#");
        return s;
    }
    
    public static <T> Predicate<T> distinctByKey(Function<? super T, Object> keyExtractor)
{
    Map<Object, Boolean> map = new ConcurrentHashMap<>();
    return t -> map.putIfAbsent(keyExtractor.apply(t), Boolean.TRUE) == null;
}
    
    static boolean containsDuplicates(List<VariableState> members) {
        // List<VariableState> collect = stateInfo.stream().filter(p -> p.var.equals(var) && p.valueNode != null).filter(Utils.distinctByKey(p -> p.time)).
          //          sorted((o1,o2) -> Integer.compare(o1.time, o2.time)).collect(Collectors.toList());
            
       return !members.stream().map(p -> p.value).allMatch(new HashSet<>()::add);
    }

}
