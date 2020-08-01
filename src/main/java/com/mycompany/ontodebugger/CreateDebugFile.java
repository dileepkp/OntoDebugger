/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.ontodebugger;

import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.StringReader;
import java.io.StringWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;
import org.apache.jena.query.QuerySolution;

/**
 *
 * @author aidb
 */
public class CreateDebugFile {

   
private static void writeProgramPointToVarMapping(PrintWriter debugFileWriter, CEntity var, CStatementLocation csl) {
        debugFileWriter.println(" printf " + "\"zzz" + var.getShortEntityDeclaration() + "_state" + "-" + "%d" + " pa:atProgramPoint " + csl.getShortStatement() + "-" +"%d" + "\\n\"" + ", $seq, $seq");
       // debugFileWriter.println(" printf " + "\"zzz" + csl.getShortStatement() + "-" + "%d" + " pa:beforeStatement " + csl.getShortStatement() + "\\n\", " + "$seq");
       // debugFileWriter.println(" printf " + "\"zzz" + csl.getShortStatement() + "-" + "%d" + " pa:timeStamp %d\\n\", " + "$seq, " + "$seq");
    }
    private static void writeProgramPoint(PrintWriter debugFileWriter, CStatementLocation csl) {
        //debugFileWriter.println(" printf " + "\"zzz" + var.getShortEntityDeclaration() + "_state" + "-" + "%d" + " pa:atProgramPoint " + csl.getShortStatement() + "-" +"%d" + "\\n\"" + ", $seq, $seq");
        debugFileWriter.println(" printf " + "\"zzz" + csl.getShortStatement() + "-" + "%d" + " pa:beforeStatement " + csl.getShortStatement() + "\\n\", " + "$seq");
        debugFileWriter.println(" printf " + "\"zzz" + csl.getShortStatement() + "-" + "%d" + " pa:timeStamp %d\\n\", " + "$seq, " + "$seq");
    }

    static void writePrintToDebugFile(PrintWriter debugFileWriter, CStatementLocation csl) {
         if(!csl.varList.isEmpty())
            writeProgramPoint(debugFileWriter, csl);
        
        for (CEntity var : csl.varList) {
            if(Utils.isArrayMemberAccess(var.rdfType)){
                //writeStateAndValueOfArrayMember(debugFileWriter, var, csl);
                //zzz: Write code to handle array indices
                writeStateAndValueOfScalar(debugFileWriter, var, csl);
                writeProgramPointToVarMapping(debugFileWriter, var, csl);
                debugFileWriter.println("set $seq = $seq + 1");
            } else if (Utils.isScalarType(var.cType) || Utils.isPointerToSimpleType(var.cType,var.baseType)) {
                writeStateAndValueOfScalar(debugFileWriter, var, csl);
                writeProgramPointToVarMapping(debugFileWriter, var, csl);
                debugFileWriter.println("set $seq = $seq + 1");
            } else if (Utils.isArrayType(var.cType)){
              /*  writeStateAndValueOfArray(debugFileWriter, var, csl);
                writeProgramPoint(debugFileWriter, var, csl);
                debugFileWriter.println("set $seq = $seq + 1");
*/
            }
            else if (Utils.isPointerToComplexType(var.cType,var.baseType)){
               writeStateAndValueOfStruct(debugFileWriter, var, csl);
                writeProgramPointToVarMapping(debugFileWriter, var, csl);
                debugFileWriter.println("set $seq = $seq + 1");
            }
        }
        
       
    }

    static void writeEnableBP(PrintWriter debugFileWriter, CStatementLocation csl, List<CStatementLocation> stsWithLineNumbers) {
        if (Utils.bpDependencies.stream().anyMatch((Pair p) -> p.predecessor.equals(csl.statement))) {
            debugFileWriter.println(" disable; " + csl.bpNumber);
            //debugFileWriter.println(" enable; " + csl.bpNumber);
        }
    }

     private static void writeStateAndValueOfArray(PrintWriter debugFileWriter, CEntity var, CStatementLocation csl) {
        //String formatType;
        debugFileWriter.println(" printf " + "\"zzz" + var.getShortEntityDeclaration() + " pa:hasArrayState " + var.getShortEntityDeclaration() + "_state" + "-" + "%d" + " \\n\"," + "$seq");
        //formatType = Utils.getFormatType(var);
        debugFileWriter.println(" print \"zzArrayBegin\"" );
        String s = var.getCCode();
        debugFileWriter.println(" print " + var.getCCode());
        debugFileWriter.println(" printf " + "\"zzz" + var.getShortEntityDeclaration() + "_state" + "-" + "%d" + " pa:hasValue zzArrayEnd" + "\", " + "$seq " );
        
    }
    private static void writeStateAndValueOfScalar(PrintWriter debugFileWriter, CEntity var, CStatementLocation csl) {
       String formatType;
        debugFileWriter.println(" printf " + "\"zzz" + var.getShortEntityDeclaration() + " pa:hasState " + var.getShortEntityDeclaration() + "_state" + "-" + "%d" + " \\n\"," + "$seq");
        formatType = Utils.getFormatType(var);
        if(formatType != null)
        debugFileWriter.println(" printf " + "\"zzz" + var.getShortEntityDeclaration() + "_state" + "-" + "%d" + " pa:hasValue " + formatType + "\\n\", " + "$seq, " + var.getCCode());
        
    }
    
    private static void writeStateAndValueOfStruct(PrintWriter debugFileWriter, CEntity var, CStatementLocation csl) {
        writeStateAndValueOfScalar(debugFileWriter, var, csl);
        debugFileWriter.println(" printf " + "\"zzz" + var.getShortEntityDeclaration() + " pa:hasStructDeclRef " + var.structDeclRef + " \\n\"" );
    }

    static StringWriter createDebugCommandsFile(List<QuerySolution> instrumentationInfo) throws IOException {
        // BufferedWriter debugFileWriter = new BufferedWriter(new FileWriter(Settings.sparqlDebugCommandsFile));
        StringWriter sw = new StringWriter();
        PrintWriter debugFileWriter = new PrintWriter(sw);
        for (QuerySolution qs : instrumentationInfo) {
            addVarToSt(qs);
        }
        addSuccessorStToList();
        Collections.sort(Main.stsWithLineNumbers, Comparator.comparingInt((CStatementLocation l) -> l.beginLine).thenComparingInt((CStatementLocation l1) -> l1.beginCol));
        debugFileWriter.println("set $seq = 1");
        for (int i = 0; i < Main.stsWithLineNumbers.size(); ++i) {
            CStatementLocation csl = Main.stsWithLineNumbers.get(i);
            if(csl.isExitStatement && !isIgnoreExitSt(csl))
                continue;//zzz: temporary hack: fix it in  future
            csl.bpNumber = Main.breakPointNumber++;
            debugFileWriter.println("#" + csl.getShortStatement() + " : " + csl.bpNumber);
            debugFileWriter.println("break " + Settings.cFile + ":" + csl.getStatementLine());
            debugFileWriter.println("commands");
            debugFileWriter.println(" " + "silent");
            //debugFileWriter.println(" " + "printf ");
            CreateDebugFile.writePrintToDebugFile(debugFileWriter, csl);
            //CreateDebugFile.writeEnableBP(debugFileWriter, csl, Main.stsWithLineNumbers);
            debugFileWriter.println(" " + "continue ");
            debugFileWriter.println("end");
            debugFileWriter.println();
        }
        writeIgnoreBP(debugFileWriter,  Main.stsWithLineNumbers);
        debugFileWriter.print("run");
        if(!Settings.inputFile.isEmpty())
        debugFileWriter.println(" < " + Settings.inputFile);
        //debugFileWriter.flush();
        debugFileWriter.close();
        return sw;
    }
    
    static StringWriter createDebugFileWithNoCommands() throws IOException {
        // BufferedWriter debugFileWriter = new BufferedWriter(new FileWriter(Settings.sparqlDebugCommandsFile));
        StringWriter sw = new StringWriter();
        PrintWriter debugFileWriter = new PrintWriter(sw);
        debugFileWriter.print("run");
        if(!Settings.inputFile.isEmpty())
        debugFileWriter.println(" < " + Settings.inputFile);
        //debugFileWriter.flush();
        debugFileWriter.close();
        return sw;
    }

    private static void addVarToSt(QuerySolution qs) {
        CStatementLocation csl = new CStatementLocation(qs.get("nextSt").toString());
        CStatementLocation definiteCsl;
        definiteCsl = addStToList(csl);
        /*
        if (!stsWithLineNumbers.contains(csl)) {
        stsWithLineNumbers.add(csl);
        definiteCsl = csl;
        } else {
        CStatementLocation csl2 = stsWithLineNumbers.stream().filter(p -> p.statement.equals(csl.statement)).findFirst().get();
        definiteCsl = csl2;
        //stsWithLineNumbers.lastIndexOf(csl);
        }
         */
        //We are allowed to have only one break point at each statement.
        CEntity ce = new CEntity();
        ce.entityExpression = qs.get("entityExpression").toString();
        if (qs.contains("rdfType")) {
            ce.rdfType = qs.get("rdfType").toString();
        }
        if (qs.contains("entityDeclaration")) {
            ce.entityDeclaration = qs.get("entityDeclaration").toString();
        }
        if (qs.contains("entityName")) {
            ce.entityName = qs.get("entityName").toString().replaceAll("\"", "");
        }
        if (qs.contains("cType")) {
            ce.cType = qs.get("cType").toString().replaceAll("http://www.semanticweb.org/yzhao30/ontologies/2015/7/c#", "c:");
        }
        if (qs.contains("baseType")) {
            ce.baseType = qs.get("baseType").toString().replaceAll("http://www.semanticweb.org/yzhao30/ontologies/2015/7/c#", "c:");
        }
        if (qs.contains("structDeclRef")) {
            ce.structDeclRef = qs.get("structDeclRef").toString().replaceAll("http://www.semanticweb.org/yzhao30/ontologies/2015/7/c#", "c:");
        }
        if (ce.getCCode() != null && !definiteCsl.varList.stream().anyMatch((CEntity p) -> p.getCCode() != null && p.getCCode().equals(ce.getCCode()))) {
            definiteCsl.varList.add(ce);
            //        definiteCsl.varList.add(new CEntity(qs.get("varName").toString(), qs.get("type").toString()));
        }
    }

    private static CStatementLocation addStToList(CStatementLocation csl) {
        CStatementLocation definiteCsl;
        Optional<CStatementLocation> existingCsl = Main.stsWithLineNumbers.stream().
                //filter((CStatementLocation p) -> p.statement.equals(csl.statement)).
                filter((CStatementLocation p) -> p.beginLine == csl.beginLine).
                findFirst();
        if (existingCsl.isPresent()) {
            definiteCsl = existingCsl.get();
        } else {
            Main.stsWithLineNumbers.add(csl);
            definiteCsl = csl;
        }
        return definiteCsl;
    }

    //Is predecessor, successor combination unique? No, for example, the branch statements
    //Is predecessor and successor part of stsWithLineNumbers?
    //Predecessor is always part of stsWithLineNumbers
    //In some cases, successor is definitely not part of stsWithLineNumbers.  How to handle that?
    private static List<Integer> getSuccessorBreakPoint(int predecessorBreakPoint) {
        Optional<CStatementLocation> predecessorOpt = Main.stsWithLineNumbers.stream().filter((CStatementLocation p) -> p.bpNumber == predecessorBreakPoint).findFirst();
        if (!predecessorOpt.isPresent()) {
            return null;
        }
        CStatementLocation predecessor = predecessorOpt.get();
        //String successorString = Utils.bpDependencies.get(predecessor.statement);
        List<Pair> successorStrings = Utils.bpDependencies.stream().filter((Pair p) -> p.predecessor.equals(predecessor.statement)).collect(Collectors.toList());
        if (successorStrings == null) {
            return null;
        }
        List<Integer> bpList = new ArrayList<>();
        for (Pair pair : successorStrings) {
            CStatementLocation csl = Main.stsWithLineNumbers.stream().filter((CStatementLocation p) -> p.statement.equals(pair.successor)).findFirst().get();
            bpList.add(csl.bpNumber);
        }
        /* for(CStatementLocation csl : successorOpt){
        if(csl.isExitStatement){
        String s = Utils.exitStToNextSt.get(csl.statement);
        CStatementLocation temp = new CStatementLocation(s);
        int nonExitLine = temp.getStatementLine();
        CStatementLocation nonExitCsl = stsWithLineNumbers.stream().filter(p -> p.getStatementLine() == nonExitLine).findFirst().get();
        bpList.add(nonExitCsl.bpNumber);
        }
        //bpList.add(csl.bpNumber);
        }*/
        return bpList;
    }

    static void editDebugCommandsFile(StringWriter debugCommandsFileWriter) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(Settings.sparqlDebugCommandsFile));
        String verify;
        /*   File file = new File(Settings.sparqlDebugCommandsFile);
        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);
         */
        Reader inputString = new StringReader(debugCommandsFileWriter.toString());
        BufferedReader br = new BufferedReader(inputString);
        while ((verify = br.readLine()) != null) {
            //***editted
            //**deleted**verify = br.readLine();**
            if (verify.contains("disable")) {
                //***edited
                String[] split = verify.split(";");
                int predecessorBreakPoint = Integer.parseInt(split[1].trim());
                List<Integer> successorBreakPoint = getSuccessorBreakPoint(predecessorBreakPoint);
                for (int sbp : successorBreakPoint) {
                    pw.println(" enable " + sbp);
                }
            } else {
                pw.println(verify);
            }
        }
        br.close();
        pw.close();
    }

    /*     private static List<Integer> getSuccessorBreakPoint_backup(int predecessorBreakPoint) {
    Optional<CStatementLocation> predecessorOpt = stsWithLineNumbers.stream().filter(p -> p.bpNumber== predecessorBreakPoint).findFirst();
    if(!predecessorOpt.isPresent())
    return null;
    CStatementLocation predecessor = predecessorOpt.get();
    String successorString = Utils.bpDependencies.get(predecessor.statement);
    if(successorString == null)
    return null;
    List<CStatementLocation> successorOpt = stsWithLineNumbers.stream().filter(p -> p.statement.equals(successorString)).collect(Collectors.toList());
    List<Integer> bpList = new ArrayList<>();
    for(CStatementLocation csl : successorOpt){
    /*  if(csl.isExitStatement){
    String s = Utils.exitStToNextSt.get(csl.statement);
    CStatementLocation temp = new CStatementLocation(s);
    int nonExitLine = temp.getStatementLine();
    CStatementLocation nonExitCsl = stsWithLineNumbers.stream().filter(p -> p.getStatementLine() == nonExitLine).findFirst().get();
    bpList.add(nonExitCsl.bpNumber);
    }
    bpList.add(csl.bpNumber);
    }
    return bpList;
    }
     */
    private static void addSuccessorStToList() {
        //for(String s : Utils.bpDependencies.forEach(p ))
        Utils.bpDependencies.forEach((Pair p) -> {
            CStatementLocation csl = new CStatementLocation(p.predecessor);
            addStToList(csl);
        });
    }

    private static void writeStateAndValueOfArrayMember(PrintWriter debugFileWriter, CEntity var, CStatementLocation csl) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    private static void writeIgnoreBP(PrintWriter debugFileWriter, List<CStatementLocation> stsWithLineNumbers) {
        //zzz: after all testcases complete the following development
        if(Settings.settingsInput.equals("rate"))
          debugFileWriter.println("ignore 4 1");  
    }

    private static boolean isIgnoreExitSt(CStatementLocation csl) {
        if(Settings.settingsInput.equals("bin_tree"))
          if (csl.statement.endsWith("40_6_43_41_exit"))
              return true;
       /* if(Settings.settingsInput.equals("space"))
          if (csl.statement.endsWith("5228_15_5228_20"))
              return true;
        */
        
        return false;
    }

    
    
}
