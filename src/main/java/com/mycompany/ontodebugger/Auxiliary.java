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

import static com.mycompany.ontodebugger.Utils.createDebugCommandsFile;
import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.StringReader;
import java.io.StringWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import org.apache.jena.query.QuerySolution;
import org.semanticweb.owlapi.model.OWLOntologyCreationException;

/**
 *
 * @author aidb
 */
public class Auxiliary {
    
     static void printNotSingleLineStatements() {
        String instrumentationQuery = ReadInput.readInstrumentationQuery("notSingleLineStatements");
       List<QuerySolution> notSingleLineStatements = Sparql.executeQuery(instrumentationQuery, Settings.modelWithProgramAndTrace);
       //Sparql.executeQueryAndPrint(instrumentationQuery, Settings.modelWithProgramAndTrace);
       System.out.println();
       System.out.println("printNotSingleLineStatements");
       for(QuerySolution qs: notSingleLineStatements){
            String st = qs.get("st").toString();
            String type = qs.get("type").toString();
             CStatementLocation csl = new CStatementLocation(st);
             if(csl.beginLine != csl.endLine)
                 System.out.println(csl.statement + " " + type);
       }
    }
     
      static void printTwoStatementsOnSameLine() {
        String instrumentationQuery = ReadInput.readInstrumentationQuery("twoStatementsOnSameLine");
       List<QuerySolution> twoStatementsOnSameLine = Sparql.executeQuery(instrumentationQuery, Settings.modelWithProgramAndTrace);
       //Sparql.executeQueryAndPrint(instrumentationQuery, Settings.modelWithProgramAndTrace);
       System.out.println();
       System.out.println("printTwoStatementsOnSameLine");
       CStatementLocation prev= null;
       for(QuerySolution qs: twoStatementsOnSameLine){
            String st = qs.get("st").toString();
            CStatementLocation csl = new CStatementLocation(st);
             if(prev!= null && csl.beginLine != prev.beginLine)
                 System.out.println(csl.statement + " " + prev.statement);
             prev = csl;
       }
    }
     
       static void getNoBraceStatements() throws Exception {
       String instrumentationQuery = ReadInput.readInstrumentationQuery("noBracesStatements");
      // System.out.println(instrumentationQuery);
       List<QuerySolution> singleStBlockInfo = Sparql.executeQuery(instrumentationQuery, Settings.modelWithProgramAndTrace);
     //  Sparql.executeQueryAndPrint(instrumentationQuery, Settings.modelWithProgramAndTrace);
        for(QuerySolution qs: singleStBlockInfo){
            String next = qs.get("next").toString();
             CStatementLocation csl = new CStatementLocation(next);
             CFile.setFirstCharcterBefore2(csl);
                
       }
        StringWriter codeFileWriter = Utils.createDebugCommandsFile(CFile.cLines);
      editDebugCommandsFile2(codeFileWriter,Settings.originalFile);
      }
      
       //used to create .c file for instrumentation
        static void editDebugCommandsFile2(StringWriter debugCommandsFileWriter, String fileName) throws IOException {
        PrintWriter pw = new PrintWriter(new FileWriter(fileName));
        String verify;
        /*   File file = new File(Settings.sparqlDebugCommandsFile);
        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);
         */
        Reader inputString = new StringReader(debugCommandsFileWriter.toString());
        BufferedReader br = new BufferedReader(inputString);
        while ((verify = br.readLine()) != null) {
            // if(verify.startsWith("#define rose"))
             //       continue;
          // if(roseSettings(verify, pw) )continue;
                pw.println(verify);
            
        }
        br.close();
        pw.close();
    }

    private static boolean roseSettings(String verify, PrintWriter pw) {
        if (verify.startsWith("/*if(!rose){")) {
            pw.println("if(!rose){");
            return true;
        }
        if (verify.startsWith("}if(!rose);*/")) {
            pw.println("}if(!rose);");
            return true;
        }
        return false;
    }
      public static void main(String[] args) throws Exception, OWLOntologyCreationException {
       //Settings.preProcessingRun = true;
       ReadInput.readSettings();
       preprocessCFile();
       
      }
      private static void preprocessCFile() throws Exception {
     
       String temp  = Settings.originalFile.replaceAll(".c$", "_original_preprocessed.c");
         replaceCode(temp,Settings.cFile);
         normalizeCode(Settings.cFile);
  
       
     }
      
        public static String replaceCode(String input, String output) throws Exception {

        String data = "";
         byte[] readAllBytes = Files.readAllBytes(Paths.get(input));
            data = new String(readAllBytes);

           /* String data2 = data.replaceAll("rdf:(\\S*)", "<http://www.w3.org/1999/02/22-rdf-syntax-ns#$1>");
            String data3 = data2.replaceAll("file0:(\\S*)", "<file.c#$1>");
            String data4 = data3.replaceAll("c:(\\S*)", "<c#$1>");
            String data5 = data4.replaceAll("(\\s)([0-9\\.]+)(\\s*)(\\.)", "$1\"$2\"$3$4");
            String data6 = data5.replaceAll("\\s(\\.)(\\n)", "$1$2");
            String data7 = data6.replaceAll("\"(\\d)\"([\\.0-9e+\\-]+)(\\.)(\\n)", "\"$1$2\"$3$4");
            String data8 = data7.replaceAll("(\\d+)([\\.0-9e+\\-]+)\\s*(\\.)(\\n)", "\"$1$2\"$3$4");
            String data9 = data8.replaceAll("@prefix.*\\n", "");
*/
           
                   
           String data2 = Pattern.compile("^(\\s*)",Pattern.MULTILINE).matcher(data).replaceAll("") ;
            String data3 = Pattern.compile("(\\t+)",Pattern.MULTILINE).matcher(data2).replaceAll(" ") ;
            String data4 = Pattern.compile("(^if.*[^{]\\s*$)(\\n)(^\\{$)",Pattern.MULTILINE).matcher(data3).replaceAll("$1$3") ;
            String data5 = Pattern.compile("(^for.*[^{]\\s*$)(\\n)(^\\{$)",Pattern.MULTILINE).matcher(data4).replaceAll("$1$3") ;
            String data6 = Pattern.compile("(^else.*[^{]\\s*$)(\\n)(^\\{$)",Pattern.MULTILINE).matcher(data5).replaceAll("$1$3") ;
            String data7 = applyPatternFixpoint(data6, "(^[^#\\n].+[^{/};:)]\\s*$)(\\n)(^[^}].*;\\s*$)","$1 $3" );//combine lines with ; at the end
              //String data7 = Pattern.compile("(^[^#\\n].+[^{/};:)]\\s*$)(\\n)(^[^}].*;\\s*$)",Pattern.MULTILINE).matcher(data6).replaceAll("$1 $3") ;
            //String data5 = data4.replaceAll("(^for.*[^{]\\s*$)(\\n)(^{$)", "$1$3");
            
            /*String data6 = data5.replaceAll("\\s(\\.)(\\n)", "$1$2");
            String data7 = data6.replaceAll("\"(\\d)\"([\\.0-9e+\\-]+)(\\.)(\\n)", "\"$1$2\"$3$4");
            String data8 = data7.replaceAll("(\\d+)([\\.0-9e+\\-]+)\\s*(\\.)(\\n)", "\"$1$2\"$3$4");
            String data9 = data8.replaceAll("@prefix.*\\n", "");
            */
            String dataFinal = data7;
            Matcher headers = Pattern.compile("^(#\\s*)(\\d+)(\\s*\".*)$(\\n)",Pattern.MULTILINE).matcher(dataFinal);
           
           // String headers = Pattern.compile("^(#\\s*)(\\d+)(\\s*\".*)$",Pattern.MULTILINE).matcher(dataFinal).toString();
            String restOfFile = Pattern.compile("^(#\\s*)(\\d+)(\\s*\".*)$",Pattern.MULTILINE).matcher(dataFinal).replaceAll("");
           // String normalizedFile = normalizeCFile(restOfFile);
        try (FileOutputStream outputStream = new FileOutputStream(output)) {
        
            while(headers.find())         
            outputStream.write(headers.group().getBytes());
        
            outputStream.write(restOfFile.getBytes());

        }
        return data;
    }

    private static String applyPatternFixpoint(String input, String pattern, String replace) {
        String temp=input;
        String temp2;
        while(true){
        temp2 = Pattern.compile(pattern,Pattern.MULTILINE).matcher(temp).replaceAll(replace);
        if(temp.equals(temp2))
            return temp2;
        else temp = temp2;
        }
    }

    private static void normalizeCode(String file) throws IOException {
        //StringBuilder sb = new StringBuilder();
       // Matcher data1 = Pattern.compile("^for.*?;.*?;[^;{]*?(; | \\{)",Pattern.MULTILINE).matcher(input) ;
        //Matcher data2 = Pattern.compile("^([^;:{}]*?)(:| ;| \\{| \\})$",Pattern.MULTILINE).matcher(input) ;
       // while(data1.find()){
       //     sb.append(data1.group().replaceAll("\\n", " "));
       // }
     /*   while(data2.find()){
            sb.append(data2.group().replaceAll("\\n", " "));
        }
*/
          List<String> cLines = Files.readAllLines(Paths.get(file));
          int i =0; int replaceLine;
              while(i< cLines.size()){
                  String curLine = cLines.get(i++);
                 /* if(curLine.startsWith("#") && (curLine.contains("sed_single_rose_original.c") ||
                         curLine.contains("rx.h") || curLine.contains("getopt.h") )){
                      cLines.set(i-1, "//" + curLine);
                      continue;
                  }*/
                 if(i< Settings.instrumentationHeaderDecl)
                     continue;
                  if(curLine.startsWith("#") || curLine.trim().equals(""))
                      continue;
                  if(curLine.matches("^for\\s*\\(")){//for loop
                      replaceLine = i -1;
                  while(!curLine.matches("^for[^;]*;[^;]*;(;|\\{)")){
                      curLine += " " + cLines.get(i++);
                      cLines.set(i-1, "");
                  }
                  cLines.set(replaceLine, curLine.replaceAll("\\n", " ") );
                  twoBranchStatementsInALine(curLine, cLines, replaceLine);
                  continue;
                  }
                  
                      replaceLine = i -1;
                  while(!curLine.matches("^.*(;|:|\\{|\\})$")){
                      curLine += " "+ cLines.get(i++);
                      cLines.set(i-1, "");
                  }
                  cLines.set(replaceLine, curLine.replaceAll("\\n", " ") );
                  twoBranchStatementsInALine(curLine, cLines, replaceLine);
              }
              
              StringWriter codeFileWriter = Utils.createDebugCommandsFile(cLines);
          
              PrintWriter pw = new PrintWriter(new FileWriter(file));
        String verify;
        /*   File file = new File(Settings.sparqlDebugCommandsFile);
        FileReader fr = new FileReader(file);
        BufferedReader br = new BufferedReader(fr);
         */
        Reader inputString = new StringReader(codeFileWriter.toString());
        BufferedReader br = new BufferedReader(inputString);
       // pw.println("#define rose");
        while ((verify = br.readLine()) != null) {
           //   if(verify.startsWith("#define rose 1"))
            //        continue;
             if(verify.startsWith("if(!rose){") ){
                 pw.println("/*if(!rose){");
                 continue;
             }
              if(verify.startsWith("}if(!rose);") ){
                 pw.println("}if(!rose);*/");
                 continue;
             }
              
                     pw.println(verify);
            
        }
        br.close();
        pw.close();
              
              
        return ;
    }

    private static void twoBranchStatementsInALine(String curLine, List<String> cLines, int replaceLine) {
        String forRegex = "(for\\s*\\(.*\\))";
        String ifRegex = "(if\\s*\\(.*\\))";
        String whileRegex = "(while\\s*\\(.*\\))";
        String elseRegex = "(else)";
        String spaceRegex = "(\\s*)";
        
        List<String> usefulRegexes = new ArrayList<>();
        usefulRegexes.add(forRegex + spaceRegex + forRegex);
        usefulRegexes.add(forRegex + spaceRegex + ifRegex);
        usefulRegexes.add(whileRegex + spaceRegex + ifRegex);
        usefulRegexes.add(ifRegex + spaceRegex + ifRegex);
        usefulRegexes.add(elseRegex + spaceRegex + ifRegex);
        
        String data = curLine;
        String temp;
        while(true){
            String dataFixpoint = data;
            for(String regex: usefulRegexes){
                temp = data.replaceAll(regex, "$1\n$3");
                data = temp;
            }
            if(dataFixpoint.equals(data)){
                cLines.set(replaceLine, dataFixpoint );
                return;
            }
                
        }
        
          }

   
}
