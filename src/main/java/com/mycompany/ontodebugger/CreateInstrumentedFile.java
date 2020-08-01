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
public class CreateInstrumentedFile {

    private static void writeProgramPointToVarMapping(PrintWriter debugFileWriter, CEntity var, CStatementLocation csl) {
        debugFileWriter.println(" fprintf( yyfp, " + "\"" + var.getShortEntityDeclaration() + "_state" + "-" + "%d" + " pa:atProgramPoint " + csl.getShortStatement() + "-" + "%d" + ". \\n\"" + ", yyseq, ppseq);");
        // debugFileWriter.println(" printf " + "\"" + csl.getShortStatement() + "-" + "%d" + " pa:beforeStatement " + csl.getShortStatement() + "\\n\", " + "yyseq");
        // debugFileWriter.println(" printf " + "\"" + csl.getShortStatement() + "-" + "%d" + " pa:timeStamp %d\\n\", " + "yyseq, " + "yyseq");
    }

    private static void writeProgramPoint(PrintWriter debugFileWriter, CStatementLocation csl) {
        final String shortStatement = csl.getShortStatement();
        if(!shortStatement.startsWith("file0"))
            return;
        //debugFileWriter.println(" printf " + "\"" + var.getShortEntityDeclaration() + "_state" + "-" + "%d" + " pa:atProgramPoint " + csl.getShortStatement() + "-" +"%d" + "\\n\"" + ", yyseq, yyseq");
        debugFileWriter.println(" fprintf( yyfp, " + "\"" + shortStatement + "-" + "%d" + " pa:afterStatement " + shortStatement + ". \\n\", " + "ppseq);");
        debugFileWriter.println(" fprintf( yyfp, " + "\"" + shortStatement + "-" + "%d" + " pa:timeStamp %d .\\n\" , " + "ppseq, " + "ppseq);");
    }

    static void writePrintToDebugFile(PrintWriter debugFileWriter, CStatementLocation csl) {

        boolean isVarWritten = false;
        for (CEntity var : csl.varList) {
            if (Utils.isArrayMemberAccess(var.rdfType)) {
                //writeStateAndValueOfArrayMember(debugFileWriter, var, csl);
                //zzz: Write code to handle array indices
                writeStateAndValueOfScalar(debugFileWriter, var, csl);
                writeProgramPointToVarMapping(debugFileWriter, var, csl);
                debugFileWriter.println("yyseq = yyseq + 1;");
                isVarWritten = true;
            } else if (Utils.isScalarType(var.cType) || Utils.isPointerToSimpleType(var.cType, var.baseType)) {
                writeStateAndValueOfScalar(debugFileWriter, var, csl);
                writeProgramPointToVarMapping(debugFileWriter, var, csl);
                debugFileWriter.println("yyseq = yyseq + 1;");
                isVarWritten = true;
            } else if (Utils.isArrayType(var.cType)) {
                /*  writeStateAndValueOfArray(debugFileWriter, var, csl);
                writeProgramPoint(debugFileWriter, var, csl);
                debugFileWriter.println("yyseq = yyseq + 1");
                 */
            } else if (Utils.isPointerToComplexType(var.cType, var.baseType)) {
                writeStateAndValueOfStruct(debugFileWriter, var, csl);
                writeProgramPointToVarMapping(debugFileWriter, var, csl);
                debugFileWriter.println("yyseq = yyseq + 1;");
                isVarWritten = true;
            }
        }

        if (isVarWritten) {
            writeProgramPoint(debugFileWriter, csl);
            debugFileWriter.println("ppseq = ppseq + 1;");
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
        debugFileWriter.println(" fprintf( yyfp, " + "\"" + var.getShortEntityDeclaration() + " pa:hasArrayState " + var.getShortEntityDeclaration() + "_state" + "-" + "%d" + " .\\n\"," + "yyseq);");
        //formatType = Utils.getFormatType(var);
        debugFileWriter.println(" fprintf( yyfp, \"zzArrayBegin\");");
        String s = var.getCCode();
        debugFileWriter.println(" fprintf( yyfp,\" " + var.getCCode() + "\");");
        debugFileWriter.println(" fprintf( yyfp, " + "\"" + var.getShortEntityDeclaration() + "_state" + "-" + "%d" + " pa:hasValue zzArrayEnd" + "\", " + "yyseq) ");

    }

    private static void writeStateAndValueOfScalar(PrintWriter debugFileWriter, CEntity var, CStatementLocation csl) {
        String formatType; 
        final String shortEntityDeclaration = var.getShortEntityDeclaration();
        if(!shortEntityDeclaration.startsWith("file0"))
            return;
        debugFileWriter.println(" fprintf( yyfp, " + "\"" + shortEntityDeclaration + " pa:hasState " + shortEntityDeclaration + "_state" + "-" + "%d" + " .\\n\"," + "yyseq);");
        formatType = Utils.getFormatType(var);
       /* if (formatType != null) {
            if(var.structDeclName != null){
                debugFileWriter.print("if("+ var.structDeclName +" != 0 )");
                debugFileWriter.println(" fprintf( yyfp, " + "\"" + shortEntityDeclaration + "_state" + "-" + "%d" + " pa:hasValue " + formatType + " .\\n\", " + "yyseq, " + var.getCCode() + ");");
            } else{
                debugFileWriter.println(" fprintf( yyfp, " + "\"" + shortEntityDeclaration + "_state" + "-" + "%d" + " pa:hasValue " + formatType + " .\\n\", " + "yyseq, " + var.getCCode() + ");");
            }
            
        }
        */
       if (formatType != null) {
            if(var.structDeclName != null)
                debugFileWriter.print("if("+ var.structDeclName +" != 0 )");
            if(formatType.equals("%c"))
                debugFileWriter.println(" fprintf( yyfp, " + "\"" + shortEntityDeclaration + "_state" + "-" + "%d" + " pa:hasValue " + "%d" + " .\\n\", " + "yyseq, " + var.getCCode() + ");");
            else if(!formatType.equals("%s"))
                debugFileWriter.println(" fprintf( yyfp, " + "\"" + shortEntityDeclaration + "_state" + "-" + "%d" + " pa:hasValue " + formatType + " .\\n\", " + "yyseq, " + var.getCCode() + ");");
           // else
            //    debugFileWriter.println(" fprintf( yyfp, " + "\"" + shortEntityDeclaration + "_state" + "-" + "%d" + " pa:hasValue \\\"" + formatType + "\\\" .\\n\", " + "yyseq, " + var.getCCode() + ");");
            }
        
    }

    private static void writeStateAndValueOfStruct(PrintWriter debugFileWriter, CEntity var, CStatementLocation csl) {
        writeStateAndValueOfScalar(debugFileWriter, var, csl);
        if(var.structDeclRef != null)
        debugFileWriter.println(" fprintf( yyfp, " + "\"" + var.getShortEntityDeclaration() + " pa:hasStructDeclRef " + var.getShortStructDeclRef() + " .\\n\");");
    }

    static StringWriter createDebugCommandsFile(List<QuerySolution> instrumentationInfo) throws IOException {
        // BufferedWriter debugFileWriter = new BufferedWriter(new FileWriter(Settings.sparqlDebugCommandsFile));

        List<String> cCodeLines = CFile.cLines;
        int prevLine = 0;

        StringWriter sw = new StringWriter();
        PrintWriter debugFileWriter = new PrintWriter(sw);
        for (QuerySolution qs : instrumentationInfo) {
            if (isIgnoreSt(qs.get("st").toString())) {
                continue;
            }
            addVarToSt(qs);
        }
        addSuccessorStToList();

        Collections.sort(Main.stsWithLineNumbers, Comparator.comparingInt((CStatementLocation l) -> l.endLine).thenComparingInt((CStatementLocation l1) -> l1.endCol).
                thenComparingInt((CStatementLocation p) -> p.isExitStatement == false ? 0 : 1));
        // debugFileWriter.println("yyseq = 1");
        for (int i = 0; i < Main.stsWithLineNumbers.size(); ++i) {
            CStatementLocation csl = Main.stsWithLineNumbers.get(i);
            if (csl.isExitStatement && !isIgnoreExitSt(csl)) {
                continue;//zzz: temporary hack: fix it in  future
            }
            csl.bpNumber = Main.breakPointNumber++;

            //  if(csl.isExitStatement)
            //     continue;
            for (; prevLine < csl.getStatementLine(); ++prevLine) {
                if (Settings.instrumentationHeaderDecl - 1 == prevLine) {
                    //debugFileWriter.println( "\nFILE *yyfp = fopen(\"" + Settings.instrumentedFile + "\",\"w\");" );
                    debugFileWriter.println("\nFILE *yyfp;\n");
                    debugFileWriter.println("int yyseq = 1; int ppseq = 1;\n");
                    debugFileWriter.println(cCodeLines.get(prevLine));
                  //  debugFileWriter.println("yyfp = fopen(\"" + Settings.traceFile + "\",\"w\");");
                    continue;
                }

                if (Settings.instrumentationHeaderInit - 1 == prevLine) {

                    debugFileWriter.println("yyfp = fopen(\"" + Settings.traceFile + "\",\"w\");");
                    debugFileWriter.println(" fprintf( yyfp, " + "\"" + Utils.getHeaderWithFile0().replaceAll("\n", "\\\\n") + "\\n\"" +  ");");
                    debugFileWriter.println(cCodeLines.get(prevLine));
                    continue;
                }
                
                if(cCodeLines.get(prevLine).startsWith("#define rose 1"))
                    continue;
                
                 if (cCodeLines.get(prevLine).startsWith("/*if(!rose){")) {
            debugFileWriter.println("if(!rose){");
           continue;
        }
        if (cCodeLines.get(prevLine).startsWith("}if(!rose);*/")) {
            debugFileWriter.println("}if(!rose);");
            continue;
        }

                debugFileWriter.println(cCodeLines.get(prevLine));
                //debugFileWriter.println( "yyfp = fopen(\"" + Settings.instrumentedFile + "\",\"w\");" );
            }

            if (csl.isExitStatement) { // debug info comes after exit statement
                String nextLineForNewLines = cCodeLines.get(prevLine);
                int lastIndexOf = nextLineForNewLines.lastIndexOf("\n");
                debugFileWriter.println(nextLineForNewLines.substring(0, lastIndexOf));
                cCodeLines.set(prevLine, nextLineForNewLines.substring(lastIndexOf + 1));
            }
            CreateInstrumentedFile.writePrintToDebugFile(debugFileWriter, csl);
            //CreateDebugFile.writeEnableBP(debugFileWriter, csl, Main.stsWithLineNumbers);
            //debugFileWriter.println(" " + "continue ");
            //debugFileWriter.println("end");
            debugFileWriter.println();

            //    if(Utils.newLinesInstrumentedCode.containsKey(csl.beginLine))
            //            debugFileWriter.println(Utils.newLinesInstrumentedCode.get(csl.beginLine));
        }

        //writeIgnoreBP(debugFileWriter,  Main.stsWithLineNumbers);
        //debugFileWriter.print("run");
        //if(!Settings.inputFile.isEmpty())
        //debugFileWriter.println(" < " + Settings.inputFile);
        for (; prevLine < cCodeLines.size(); ++prevLine) {
            debugFileWriter.println(cCodeLines.get(prevLine));
        }

        debugFileWriter.flush();

        debugFileWriter.close();
        return sw;
    }

      static StringWriter createDebugCommandsFile2(List<QuerySolution> instrumentationInfo) throws IOException {
        // BufferedWriter debugFileWriter = new BufferedWriter(new FileWriter(Settings.sparqlDebugCommandsFile));

        List<String> cCodeLines = CFile.cLines;
        int prevLine = 0;

        StringWriter sw = new StringWriter();
        PrintWriter debugFileWriter = new PrintWriter(sw);
        for (QuerySolution qs : instrumentationInfo) {
            if (isIgnoreSt(qs.get("st").toString())) {
                continue;
            }
            addVarToSt(qs);
        }
        addSuccessorStToList();

        Collections.sort(Main.stsWithLineNumbers, Comparator.comparingInt((CStatementLocation l) -> l.endLine).thenComparingInt((CStatementLocation l1) -> l1.endCol).
                thenComparingInt((CStatementLocation p) -> p.isExitStatement == false ? 0 : 1));
        // debugFileWriter.println("yyseq = 1");
        for (int i = 0; i < Main.stsWithLineNumbers.size(); ++i) {
            CStatementLocation csl = Main.stsWithLineNumbers.get(i);
            if (csl.isExitStatement && !isIgnoreExitSt(csl)) {
                continue;//zzz: temporary hack: fix it in  future
            }
            csl.bpNumber = Main.breakPointNumber++;

            //  if(csl.isExitStatement)
            //     continue;
            for (; prevLine < csl.getStatementLine() - 1; ++prevLine) {
                if (Settings.instrumentationHeaderDecl - 1 == prevLine) {
                    //debugFileWriter.println( "\nFILE *yyfp = fopen(\"" + Settings.instrumentedFile + "\",\"w\");" );
                    debugFileWriter.println("\nFILE *yyfp;\n");
                    debugFileWriter.println("int yyseq = 1;\n");
                    debugFileWriter.println(cCodeLines.get(prevLine));
                  //  debugFileWriter.println("yyfp = fopen(\"" + Settings.traceFile + "\",\"w\");");
                    continue;
                }

                if (Settings.instrumentationHeaderInit - 1 == prevLine) {

                    debugFileWriter.println("yyfp = fopen(\"" + Settings.traceFile + "\",\"w\");");
                    debugFileWriter.println(cCodeLines.get(prevLine));
                    continue;
                }
                
                

                debugFileWriter.println(cCodeLines.get(prevLine));
                //debugFileWriter.println( "yyfp = fopen(\"" + Settings.instrumentedFile + "\",\"w\");" );
            }

            if (csl.isExitStatement) { // debug info comes after exit statement
                String nextLineForNewLines = cCodeLines.get(prevLine);
                int lastIndexOf = nextLineForNewLines.lastIndexOf("\n");
                debugFileWriter.println(nextLineForNewLines.substring(0, lastIndexOf));
                cCodeLines.set(prevLine, nextLineForNewLines.substring(lastIndexOf + 1));
            }
            CreateInstrumentedFile.writePrintToDebugFile(debugFileWriter, csl);
            //CreateDebugFile.writeEnableBP(debugFileWriter, csl, Main.stsWithLineNumbers);
            //debugFileWriter.println(" " + "continue ");
            //debugFileWriter.println("end");
            debugFileWriter.println();

            //    if(Utils.newLinesInstrumentedCode.containsKey(csl.beginLine))
            //            debugFileWriter.println(Utils.newLinesInstrumentedCode.get(csl.beginLine));
        }

        //writeIgnoreBP(debugFileWriter,  Main.stsWithLineNumbers);
        //debugFileWriter.print("run");
        //if(!Settings.inputFile.isEmpty())
        //debugFileWriter.println(" < " + Settings.inputFile);
        for (; prevLine < cCodeLines.size(); ++prevLine) {
            debugFileWriter.println(cCodeLines.get(prevLine));
        }

        debugFileWriter.flush();

        debugFileWriter.close();
        return sw;
    }

  
    static StringWriter createDebugFileWithNoCommands() throws IOException {
        // BufferedWriter debugFileWriter = new BufferedWriter(new FileWriter(Settings.sparqlDebugCommandsFile));
        StringWriter sw = new StringWriter();
        PrintWriter debugFileWriter = new PrintWriter(sw);
        debugFileWriter.print("run");
        if (!Settings.inputFile.isEmpty()) {
            debugFileWriter.println(" < " + Settings.inputFile);
        }
        //debugFileWriter.flush();
        debugFileWriter.close();
        return sw;
    }

    private static void addVarToSt(QuerySolution qs) {
        CStatementLocation csl = new CStatementLocation(qs.get("st").toString());
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
         if (qs.contains("varScope")) {
            ce.scope = qs.get("varScope").toString();
            if(!csl.isInScope(ce.scope))
                return;
        }
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
        if (qs.contains("structDeclName")) {
            ce.structDeclName = qs.get("structDeclName").toString().replaceAll("\"", "");
        }
        if (isEntityDeclaredAfter(ce.entityDeclaration, csl.statement)) {
            return;
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

    static void editDebugCommandsFile(StringWriter debugCommandsFileWriter, String fileName) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(fileName));
        String verify;
        /*   File file = new File(Settings.sparqlDebugCommandsFile);
        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);
         */
        Reader inputString = new StringReader(debugCommandsFileWriter.toString());
        BufferedReader br = new BufferedReader(inputString);
        while ((verify = br.readLine()) != null) {
            /*if (verify.contains("disable")) {
            
                String[] split = verify.split(";");
                int predecessorBreakPoint = Integer.parseInt(split[1].trim());
                List<Integer> successorBreakPoint = getSuccessorBreakPoint(predecessorBreakPoint);
                for (int sbp : successorBreakPoint) {
                    pw.println(" enable " + sbp);
                }
            } else {
                pw.println(verify);
            }*///commented on Aug 3, 2019 as it causes problem in sed
           
            pw.println(verify);
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
        if (Settings.settingsInput.equals("rate")) {
            debugFileWriter.println("ignore 4 1");
        }
    }

    private static boolean isIgnoreExitSt(CStatementLocation csl) {
        /*   if(Settings.settingsInput.equals("bin_tree")){
          if (csl.statement.endsWith("37_1_40_35_exit"))
              return true;
          if (csl.statement.endsWith("39_1_40_35_exit"))
              return true;
        }
        
       /* if(Settings.settingsInput.equals("space"))
          if (csl.statement.endsWith("5228_15_5228_20"))
              return true;
         */

        return false;
    }

    private static boolean isIgnoreSt(String statement) {
        if (Settings.settingsInput.equals("bin_tree")) {
            if (statement.endsWith("31_1_31_30")) {
                return true;
            }
        }

        /* if(Settings.settingsInput.equals("space"))
          if (csl.statement.endsWith("5228_15_5228_20"))
              return true;
         */
        return false;
    }

    private static boolean isEntityDeclaredAfter(String entityDeclaration, String entityExpression) {
        if (entityDeclaration != null && entityExpression != null) {
            CStatementLocation decl = new CStatementLocation(entityDeclaration);
            CStatementLocation ref = new CStatementLocation(entityExpression);
            if (decl.beginLine >= ref.beginLine) {
                return true;
            }
        }
        return false;

    }

}
