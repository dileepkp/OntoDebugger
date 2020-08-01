/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.ontodebugger;

import com.mycompany.ontodebugger.Settings.AbstractionFunctors;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import org.apache.commons.lang3.StringUtils;
import org.apache.jena.datatypes.RDFDatatype;
import org.apache.jena.graph.Node;
import org.apache.jena.graph.NodeFactory;
import org.apache.jena.graph.Triple;
import org.apache.jena.graph.impl.LiteralLabel;
import org.apache.jena.graph.impl.LiteralLabelFactory;
import org.apache.jena.rdf.model.Literal;
import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.rdf.model.Property;
import org.apache.jena.rdf.model.Resource;
import org.apache.jena.rdf.model.Statement;
import org.apache.jena.rdf.model.impl.LiteralImpl;
import org.apache.jena.rdf.model.impl.PropertyImpl;
import org.apache.jena.rdf.model.impl.ResourceImpl;
import org.apache.jena.rdf.model.impl.StatementImpl;
import org.apache.jena.reasoner.rulesys.Functor;

/**
 *
 * @author aidb
 */
public class Command {

    String command;
    String commandWithURI;
    String functorName;
    List<String> args;
    List<String> argsWithURI;
    AbstractionFunctors abstractionFuncEnum;
    Settings.ReasoningFunctors reasoningFuncEnum;
     Settings.QueryFunctors queryFuncEnum;

    public Command(String c) {
        command = c;
        args = new ArrayList<>();
        argsWithURI = new ArrayList<>();
        parse();
        setFunctor();
    }
    
    private void parse() {
         String funcPattern = "(\\b+)";
       String argsPattern = "([a-zA-Z0-9]+)[,)]";
       commandWithURI = command.replaceAll("file0:", Settings.prefix+"#");
       
      String modifiedCommand = replaceLast(command.replaceFirst("\\(", ","), "\\)" , ",");
     // StringUtils.reverse(modifiedCommand).replaceFirst(")", ",");
      Scanner in = new Scanner(modifiedCommand);
      // in.useDelimiter("[(]|,|[)]");
      in.useDelimiter(",");
       functorName = in.next();
       
       while(in.hasNext())
           args.add(in.next());
       
        String modifiedCommandWithURI = replaceLast(commandWithURI.replaceFirst("\\(", ","), "\\)" , ",");
       in = new Scanner(modifiedCommandWithURI);
       //in.useDelimiter("[(]|,|[)]");
       in.useDelimiter(",");
       in.next();
       while(in.hasNext())
           argsWithURI.add(in.next());
       
    }

    

    public Statement getStatement() {

        Model m = ModelFactory.createDefaultModel();
        Node literal1 = NodeFactory.createLiteral(LiteralLabelFactory.createTypedLiteral(1));
        Node[] args = getArgs();
        Node functor = Functor.makeFunctorNode(functorName, args);
        Triple tr = new Triple(literal1, literal1, functor);

        return m.asStatement(tr);

    }

    private Node[] getArgs() {
       String funcPattern = "(\\b+)";
       String argsPattern = "([a-zA-Z0-9]+)[,)]";
       String modifiedCommand;
       modifiedCommand = command.replaceAll("file0:", Settings.prefix+"#");
       Node[] args = new Node[10];
       
       Scanner in = new Scanner(modifiedCommand);
       //in.useDelimiter("[(]|,|[)]");
       in.useDelimiter(",");
       //if(in.hasNext())
       functorName = in.next();
       
       int i;
       for( i=0; in.hasNext(); ++i){
           args[i] = NodeFactory.createLiteral(in.next());
       }
       Node[] finalArgs = new Node[i];// to know the count of number of args.
       for(int j=0; j<i; ++j){
           finalArgs[j] = args[j];
       }
       return finalArgs;
    }

    private void setFunctor() {
       /* if(functorName.equals("CreateSpan"))
            abstractionFuncEnum = AbstractionFunctors.CreateSpan;
        else if (functorName.equals("Exit"))
            abstractionFuncEnum = AbstractionFunctors.Exit;
         else if (functorName.equals("VarsInSpan"))
            abstractionFuncEnum = AbstractionFunctors.VariablesInTheSpan;
         else if (functorName.equals("StsInSpan"))
            abstractionFuncEnum = AbstractionFunctors.StsInSpan;
*/
        queryFuncEnum = null;
        abstractionFuncEnum = null;
       reasoningFuncEnum = null;
       if(Session.abstractionFunctorStringMap.containsKey(functorName)){
           abstractionFuncEnum = Session.abstractionFunctorStringMap.get(functorName);
       
    }
       
          if(Session.queryFunctorStringMap.containsKey(functorName)){
           queryFuncEnum = Session.queryFunctorStringMap.get(functorName);
      
    }
    
    if(Session.reasoningFunctorStringMap.containsKey(functorName)){
           reasoningFuncEnum = Session.reasoningFunctorStringMap.get(functorName);
       
    }
     
    }

    private String replaceLast(String text, String regex, String replace) {
        return text.replaceFirst("(?s)(.*)" + regex, "$1" + replace);
    }
    

}
