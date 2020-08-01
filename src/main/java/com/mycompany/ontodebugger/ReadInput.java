/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.ontodebugger;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Reader;
import java.io.StringReader;
import java.io.StringWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.xpath.XPath;
import javax.xml.xpath.XPathConstants;
import javax.xml.xpath.XPathFactory;
import org.apache.jena.query.Dataset;
import org.apache.jena.query.ReadWrite;
import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.tdb.TDBFactory;
import org.apache.jena.tdb.TDBLoader;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

/**
 *
 * @author aidb
 */
public class ReadInput {

    static String prefix = null;
    static void readSettings() {
        String s = null;
        String s1 = null;
        try {
            Document doc = getXMLDocument("src/main/resources/settings.xml");

            XPath xpath = XPathFactory.newInstance().newXPath();

            String expression;
            String settingInputBackup = Settings.settingsInput;
            //expression = "//input[starts-with(@id,'" + "sed_scale" + "')]/dataFile";
            if(Settings.settingsInput.startsWith("sed_scale"))
                Settings.settingsInput = "sed_scale";
                //expression = "//input[@id='" + "sed_scale" + "']/dataFile";
            //else
                expression = "//input[@id='" + Settings.settingsInput + "']/dataFile";
            //String expression = "//input[@id='" + Settings.settingsInput + "']/dataFile";
            Node node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            Settings.dataFile = node.getTextContent().trim();
            
            expression = "//input[@id='" + Settings.settingsInput + "']/cFile";
            node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            Settings.cFile = node.getTextContent().trim();
            
          /*  if(Settings.preProcessingRun){
                Settings.originalFile = Settings.cFile;
                Settings.cFile = Settings.cFile.replaceAll(".c$", "_nobraces.c");
            }
            */
            Settings.sparqlDebugCommandsFile = Settings.dataFile.replaceAll(".ttl$", "_commands.debug");
            Settings.instrumentedFile = Settings.dataFile.replaceAll(".ttl$", "_instrumented.c");
            
            expression = "//input[@id='" + Settings.settingsInput + "']/trace";
            node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            if(node == null)
                Settings.traceFile = Settings.dataFile.replaceAll(".ttl$", "_trace.ttl");
           
            expression = "//input[@id='" + Settings.settingsInput + "']/executableFile";
            node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            if(node != null)
            Settings.executableFile = node.getTextContent().trim();
            
            Settings.instrumentedExecutableFile = Settings.executableFile + "_instrumented";
           
            expression = "//input[@id='" + Settings.settingsInput + "']/cfgFile";
            node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            if(node != null)
            Settings.cfgFile = node.getTextContent().trim();
            
             expression = "//input[@id='" + Settings.settingsInput + "']/inputFile";
            node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            if(node != null)
            Settings.inputFile = node.getTextContent().trim();
            
         /*    expression = "//input[@id='" + Settings.settingsInput + "']/gdbDebugCommandsFile";
            NodeList nodes = (NodeList) xpath.evaluate(expression, doc, XPathConstants.NODESET);
            if(nodes != null)
            Settings.gdbDebugCommandsFile = nodes.item(Settings.debugFileId).getNodeValue();
*/
             expression = "//input[@id='" + Settings.settingsInput + "']/instrumentationHeaderDecl";
            node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            if(node != null)
            Settings.instrumentationHeaderDecl = (Integer.parseInt(node.getTextContent().trim()));
           
            expression = "//input[@id='" + Settings.settingsInput + "']/instrumentationHeaderInit";
            node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            if(node != null)
            Settings.instrumentationHeaderInit = (Integer.parseInt(node.getTextContent().trim()));
           
            
            /* Settings.inferredFile = Settings.dataFile.replaceAll(".ttl$", "_inferred.ttl");

           
            expression = "//inputgroup[input/@id='" + Settings.settingsInput + "']/queryFile";
            node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            if(node == null){
            expression = "//queryFile[@id='" + Settings.analysisInput + "']";
            node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            }
            Settings.queryFile = node.getTextContent().trim();
*/
            expression = "//input[@id='" + Settings.settingsInput + "']/prefix";
            node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            if(node != null)
            s = node.getTextContent().trim();
            Settings.prefix = s;

            prefix = readPrefixQuery();
            if (prefix != null && s != null) {
                prefix = prefix.replace("zzz", s);
            }
            
            Settings.settingsInput = settingInputBackup;

        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    static Document getXMLDocument(String xmlFile) throws IOException, ParserConfigurationException, SAXException {
        File inputFile = new File(xmlFile);
        DocumentBuilderFactory dbFactory
                = DocumentBuilderFactory.newInstance();
        DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
        Document doc = dBuilder.parse(inputFile);
        doc.getDocumentElement().normalize();
        System.out.println("Root element :"
                + doc.getDocumentElement().getNodeName());
        return doc;
    }
    
      public static String readInstrumentationQuery(String ip) {
        String s = null;
        String s1 = null;
        try {
            File inputFile = new File("src/main/resources/instrumentation.xml");
            DocumentBuilderFactory dbFactory
                    = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.parse(inputFile);
            doc.getDocumentElement().normalize();
            System.out.println("Root element :"
                    + doc.getDocumentElement().getNodeName());

            XPath xpath = XPathFactory.newInstance().newXPath();

            String expression = "//query[@id='" + ip + "']";
            Node node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            s = node.getTextContent().trim();
            
        } catch (Exception e) {
            e.printStackTrace();
        }
        return prefix + s;
    }
      
    public static String readPrefixQuery() {
        String s = null;
        String s1 = null;
        try {
            File inputFile = new File("src/main/resources/prefixQuery.xml");
            DocumentBuilderFactory dbFactory
                    = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.parse(inputFile);
            doc.getDocumentElement().normalize();
            System.out.println("Root element :"
                    + doc.getDocumentElement().getNodeName());

            XPath xpath = XPathFactory.newInstance().newXPath();

            String expression = "//query[@id='" + "0" + "']";
            Node node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            s1 = node.getTextContent().trim(); //to get prefixes

        } catch (Exception e) {
            e.printStackTrace();
        }
        return s1;
    }
    
    
     public static List<String> readDefaultTests() {
        String s = null;
        String s1 = null;
        List<String> testcases = new ArrayList<>();
        try {
            File inputFile = new File("src/main/resources/automatedTests.xml");
            DocumentBuilderFactory dbFactory
                    = DocumentBuilderFactory.newInstance();
            DocumentBuilder dBuilder = dbFactory.newDocumentBuilder();
            Document doc = dBuilder.parse(inputFile);
            doc.getDocumentElement().normalize();
            
            XPath xpath = XPathFactory.newInstance().newXPath();

            String expression = "//query";
             NodeList nodes = (NodeList) xpath.evaluate(expression, doc, XPathConstants.NODESET);
            for (int i = 0; i < nodes.getLength(); i++) {
        Node node = nodes.item(i);
        testcases.add(node.getTextContent());
            }
           
        } catch (Exception e) {
            e.printStackTrace();
        }
        return testcases;
    }
    
     static Model getRawModel() throws Exception {
        // create a basic RAW model that can do no inferencing

        Model rawModel = ModelFactory.createDefaultModel();
        rawModel.read(Settings.dataFile);
        if (Settings.cfgFile != null ) {
            Model cfgModel = ModelFactory.createDefaultModel();
            cfgModel.read(Settings.cfgFile);
            rawModel.add(cfgModel);
        }
        
        //System.out.println("Triples size:" + rawModel.size());
       if(Settings.runTrace ){
            Model traceModel = ModelFactory.createDefaultModel();
            normalize(Settings.traceFile);
            traceModel.read(Settings.traceFile);
            rawModel.add(traceModel);
            
        }
       
        return rawModel;
    }
     
     static Model getTraceModel() {
        // create a basic RAW model that can do no inferencing

       
       if(Settings.runTrace ){
            Model traceModel = ModelFactory.createDefaultModel();
            traceModel.read(Settings.traceFile);
            return traceModel;
        }
       
        return null;
    }
     
     static Model getRawModelInTDB() {
        // create a basic RAW model that can do no inferencing
  

      /*  Model rawModel = ModelFactory.createDefaultModel();
        rawModel.read(Settings.dataFile);
        if (Settings.cfgFile != null ) {
            Model cfgModel = ModelFactory.createDefaultModel();
            cfgModel.read(Settings.cfgFile);
            rawModel.add(cfgModel);
        }
       if(Settings.runTrace ){
            Model traceModel = ModelFactory.createDefaultModel();
            traceModel.read(Settings.traceFile);
            rawModel.add(traceModel);
        }
       */
         Dataset dataset = TDBFactory.createDataset("/home/aidb/tdb");
          //dataset.begin(ReadWrite.READ) ;
    Model model = dataset.getDefaultModel();
   TDBLoader.loadModel(model, Settings.dataFile );
   if(Settings.cfgFile != null)
       TDBLoader.loadModel(model, Settings.cfgFile );
    if(Settings.runTrace)
   TDBLoader.loadModel(model, Settings.traceFile );
       //dataset.commit();
        return model;
    }

    static String readQueryWithParameters(String query, SpanCommandList scl) {
        String origQuery = readInstrumentationQuery(query);
        //StringBuffer modQuery = new StringBuffer(origQuery);
        /*for(int i=1; i<= par.length;  ++i){
            origQuery = origQuery.replaceAll("zz" +i, (par[i-1]));
        }*/
       /* String s1 = origQuery.replaceAll("zz_fromTime", scl.fromTime);
        String s2 = s1.replaceAll("zz_toTime", scl.toTime);
        String s3 = s2.replaceAll("zz_st", scl.stsInSpanString);
        return s3;
*/
        
           
       if(scl.containsTime()){
           origQuery = origQuery.replaceAll("zz_fromTime", scl.fromTime);
           origQuery = origQuery.replaceAll("zz_toTime", scl.toTime);
       }
       origQuery= origQuery.replaceAll("zz_var", scl.varsInSpanString.replaceAll(",", " "));
       origQuery= origQuery.replaceAll("zz_st", scl.stsInSpanString.replaceAll(",", " "));
           return origQuery;
    }

    static String readSessionSparqlQuery(String queryCmdId, String xmlFile) {
          String s1 = null;
        try {
            Document doc = getXMLDocument(xmlFile);
            XPath xpath = XPathFactory.newInstance().newXPath();

            String expression = "//query[@id='" + queryCmdId + "']";
            Node node = (Node) xpath.evaluate(expression, doc, XPathConstants.NODE);
            if(node != null)
            s1 = node.getTextContent().trim(); //to get prefixes
            else
                 return null;

        } catch (Exception e) {
            e.printStackTrace();
        }
        return prefix + s1;
    }

    private static void normalize(String file) throws IOException {
         List<String> cLines = Files.readAllLines(Paths.get(file));
          int i =0; int replaceLine;
          boolean isAlreadyNormalized = true;
              while(i< cLines.size()){
                  String curLine = cLines.get(i++);
                  if(curLine.startsWith("file0") || curLine.startsWith("@") || curLine.startsWith("#")){}
                  else{
                   cLines.set(i-1, "# "+curLine);
                   isAlreadyNormalized = false;
                  }
              }
              
               if(isAlreadyNormalized) return;
               
       StringWriter codeFileWriter = Utils.createDebugCommandsFile(cLines);
          
      /* PrintWriter pw = new PrintWriter(new FileWriter(file));
        String verify;
        Reader inputString = new StringReader(codeFileWriter.toString());
        BufferedReader br = new BufferedReader(inputString);
        while ((verify = br.readLine()) != null) {
                     pw.println(verify);
            
        }
        br.close();
        pw.close();
*/
       try (FileOutputStream outputStream = new FileOutputStream(file)) {
           outputStream.write(codeFileWriter.toString().getBytes());
        }

    }

}
