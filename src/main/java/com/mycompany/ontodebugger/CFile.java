/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.ontodebugger;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author aidb
 */
public class CFile {

    static List<String> cLines;
    static List<String> cLinesReadOnly;
    
    static void readFile() throws IOException {
        cLines = Files.readAllLines(Paths.get(Settings.cFile));
        cLinesReadOnly = Files.readAllLines(Paths.get(Settings.cFile));
        
    }
    
    static String getCode(int line, int bc, int ec){
     /*   String curLine = cLines.get(line - 1);
        int index = curLine.indexOf("\n");
        if(index != -1)
            curLine = curLine.substring(index+1);
         // return  curLine.substring(index + 1).substring(bc-1, ec);
       // else
            return curLine.substring(bc-1, ec);
        // - 1 because list indices begin from zero
*/
     try{
     return cLinesReadOnly.get(line-1).substring(bc-1, ec);
     }catch(Exception ex){
         if(line -1 >= 0)
         System.out.println("exception" + cLinesReadOnly.get(line-1) 
                 + "zzzz  bc-1=" + Integer.toString(bc-1) + "ec=" + Integer.toString(ec));
         else
             System.out.println("exception");
     }
     return "";
    }
    
    static String getCode(int bl, int bc, int el, int ec){
        StringBuilder sb = new StringBuilder();
        sb.append(cLinesReadOnly.get(bl - 1).substring(bc-1));
        for(int i = bl + 1; i< el; ++i)
           sb.append(cLinesReadOnly.get(i - 1));
        sb.append(cLinesReadOnly.get(el - 1).substring(0, ec));
        return sb.toString();
    }
    
    static void setFirstCharcterBefore(int bl, int bc, CStatementLocation csl){
        int line = bl-1;
        int col = bc-1;
        while(true){
            
            String code = cLines.get(line);
            if(col > 0){
             String before = code.substring(0, col).trim();
             if(before.length() > 0){
                 if(isLeftBraceRequired(before,line)){
                 cLines.set(line, code + "{"); 
//                 adjustCodeInLine(line,code2,csl.beginLine);
                     setFirstCharcterAfter(csl.endLine, csl.endCol,csl);
                 }
             return;
             }
            }
            line--;
            col = cLines.get(line).length();
        }
    }

    private static boolean isLeftBraceRequired(String before,int line) {
       /* if(before.replace(" ", "").equals("for(")){
            if(cLines.get(line-1).trim().endsWith("{"))
                return false;
        }*/
        if(before.charAt(before.length()-1) != '{')
            return true;
        
        return false;
    }
    
     static void setFirstCharcterAfter(int el, int ec, CStatementLocation csl){
        int line = el-1;
        int col = ec;
        while(true){
            
            String code = cLines.get(line);
            //if(col > 0){
             String after = code.substring(col).trim();
             if(after.length() > 0){
                 //if(after.charAt(0) != '}')
                 if(col != 0){
                 String before = code.substring(0, col);
                     cLines.set(line, before + "\n}\n" + after );
                   //  cLines.add(line + 1, "}" + after);
                 //    csl.newLineInInstrumentedCode = "}" + after;
                // Utils.newLinesInstrumentedCode.put(csl.beginLine, "}" + after);
                 }
                 else 
                     cLines.set(line, "}\n" + code);
                      
                  
                 
             return;
           //  }
            }
            line++;
            col = 0;
        }
    }

    private static void adjustCodeInLine(int line, String code,int bl) {
        if(!Utils.newLinesInstrumentedCode.containsKey(bl))
        cLines.set(line, code + "{"); 
        else{
            String pre = Utils.newLinesInstrumentedCode.get(bl);
            Utils.newLinesInstrumentedCode.remove(bl);
            Utils.newLinesInstrumentedCode.put(bl, pre +"{");
        }
    }

    static void setFirstCharcterBefore2_backup(CStatementLocation csl){
        int line = csl.beginLine-1;
        int col = csl.beginCol-1;
      /*  while(true){
            
            String code2 = cLines.get(line);
            if(col > 0){
             String before = code2.substring(0, col).trim();
             if(before.length() > 0){
 
                 cLines.set(line, code2 + "{"); 
//                 adjustCodeInLine(line,code2,csl.beginLine);
                     setFirstCharcterAfter2(csl.endLine, csl.endCol,csl);
                 
             return;
             }
            }
            line--;
            col = cLines.get(line).length();
        }*/
     String code = cLines.get(line);
      String before;
      if(col == 0)
          before = "";
      else before = code.substring(0, col);
      String after; //= code2.substring(col);
      
      if(csl.beginLine != csl.endLine){
          after = code.substring(col);
      cLines.set(line, before + "{\n" + after );
        setFirstCharcterAfter2(csl.endLine, csl.endCol,csl);
        return;
      } 
      
     // after = code2.substring(csl.endCol-3);
      String beforeEndl = code.substring(col, csl.endCol);
      String afterEndl;
      if(code.length() > csl.endCol)
      afterEndl = code.substring(csl.endCol +1);
      else
          afterEndl = "";
      cLines.set(line, before + "{\n" +  beforeEndl + "\n}\n" + afterEndl );
    }
     
    private static void keepLeftBraceInBetween(CStatementLocation csl) {
        
          int line = csl.beginLine-1;
        int col = csl.beginCol-1;
              String code2 = cLines.get(csl.beginLine-1);
      String before;
      if(col == 0)
          before = "";
      else before = code2.substring(0, csl.beginCol-1);
      String after; //= code2.substring(col);
      
     
     
     
      String beforeEndl = code2.substring(csl.beginCol-1, csl.endCol);
      String afterEndl;
      if(code2.length() > csl.endCol)
      afterEndl = code2.substring(csl.endCol +1);
      else
          afterEndl = "";
      cLines.set(line, before + "{\n" +  beforeEndl + "\n}\n" + afterEndl );
 
    }
    static void setFirstCharcterBefore2(CStatementLocation csl){
        int line = csl.beginLine-1;
        int col = csl.beginCol-1;
         if((csl.beginLine == csl.endLine && col == 0) ||
                 (csl.beginLine != csl.endLine && col == 0)){
        while(true){
            
            String code = cLines.get(line);
            if(col > 0){
             String before = code.substring(0, col).trim();
             if(before.length() > 0){
                
                 cLines.set(line, code + "{"); 
                 setFirstCharcterAfter2(csl.endLine, csl.endCol,csl);
                 
             return;
             }
            }
            do{
            line--;
            }while(skip(cLines.get(line)));
            col = cLines.get(line).length();
        }
        }
                 else{
                     //keepLeftBraceInBetween(csl);
                 
         
      String code2 = cLines.get(csl.beginLine-1);
      String before;
      if(col == 0)
          before = "";
      else before = code2.substring(0, csl.beginCol-1);
      String after = code2.substring(col);
      
      if(csl.beginLine != csl.endLine){
          
      cLines.set(line, before + "{\n" + after );
        setFirstCharcterAfter2(csl.endLine, csl.endCol,csl);
        return;
      }  else if( col != 0){
           cLines.set(line, before + "{\n" + after + "\n}" );
        return;
      }
     
                     }
    /*
      String beforeEndl = code2.substring(csl.beginCol-1, csl.endCol);
      String afterEndl;
      if(code2.length() > csl.endCol)
      afterEndl = code2.substring(csl.endCol +1);
      else
          afterEndl = "";
      cLines.set(line, before + "{\n" +  beforeEndl + "\n}\n" + afterEndl );
 */
    }
    
      static void setFirstCharcterAfter2(int el, int ec, CStatementLocation csl){
        int line = el-1;
        int col = ec ;
        
            
            String code = cLines.get(line);
            //if(col > 0){
             String after = code.substring(col).trim();
             if(after.length() >= 0){
                 //if(after.charAt(0) != '}')
                 if(col != 0){
                 String before = code.substring(0, col);
                 
                  cLines.set(line, before + "\n}\n" + after );
                  /* if(csl.beginCol == csl.endLine)
                     cLines.set(line, code + "\n}\n" );
                   else
                     cLines.set(line, before + "\n}\n" + after );
*/
                 
                 }
                 else 
                     cLines.set(line, "}\n" + code);
                      
                  
                 
             return;
           //  }
            }
        
    }

    private static boolean skip(String line) {
        if(line.startsWith("#") )
            return true;
        return false;
    }

    
    
}
