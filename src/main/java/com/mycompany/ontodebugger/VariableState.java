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

import static com.mycompany.ontodebugger.CommandProcessor.timeQueryVariable;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Optional;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import one.util.streamex.StreamEx;
import org.apache.jena.graph.Node;
import org.apache.jena.graph.NodeFactory;
import org.apache.jena.rdf.model.Model;
import org.apache.jena.rdf.model.ModelFactory;
import org.apache.jena.rdf.model.RDFNode;
import org.apache.jena.rdf.model.ResourceFactory;
import org.apache.jena.reasoner.rulesys.Util;
import org.nfunk.jep.JEP;
import org.nfunk.jep.ParseException;

/**
 *
 * @author aidb
 */
public class VariableState {

    static void process(List<VariableState> stateInfo) {
      //  List<VariableState> stateInfo2 = stateInfo;
        for(VariableState vs : stateInfo){
          //  System.out.println(vs.var);
            if(vs.value  == null){
                List<VariableState> collect = stateInfo.stream().filter(p -> p.var.equals(vs.var) && !p.st.equals(vs.st) && p.value != null && p.time <= vs.time ).collect(Collectors.toList());
                if(collect.size() > 0){
                VariableState max = collect.stream().max(Comparator.comparing(VariableState::getTime)).get();
                     vs.value = max.value; 
                     vs.valueNode=max.valueNode;
                     
                }
            }
        }
    }

    static void applyFilter(List<VariableState> stateInfo, String filter) {
        JEP mathParser = new JEP();
        
        
        for(VariableState vs : stateInfo){
            try {
                mathParser.addVariable("e1", vs.value);
                org.nfunk.jep.Node n1 = mathParser.parse(filter);
                Double result = (Double) mathParser.evaluate(n1);
//System.out.println(expression + " = " + result);
                vs.removeAfterFilter = result.equals(0.0d);
            } catch (Exception ex) {
                Logger.getLogger(VariableState.class.getName()).log(Level.SEVERE, null, ex);
            }
           
        }
    }

    static void applyMap(List<VariableState> stateInfo, String map) {
        JEP mathParser = new JEP();
        
        for(VariableState vs : stateInfo){
            mathParser.addVariable("e1", vs.value);
            mathParser.parseExpression(map);
            vs.oldValue = vs.value;
            vs.value = (double) mathParser.getValue();
            mathParser.removeVariable("e1");
            vs.valueNode = ResourceFactory.createTypedLiteral(vs.value);
        }
    }

    static List<VariableState>  adjustBasedOnTimeInstant(List<VariableState> stateInfo, List<Integer> timeList, String relative) {
        List<VariableState> newStateInfo = new ArrayList<>();
        if(relative.endsWith("after")){
        for(Integer time: timeList){
            VariableState min = stateInfo.stream().filter(p -> p.time >= time ).min(Comparator.comparing(VariableState::getTime)).get();
                 newStateInfo.add(min);
        }
        }
        else if (relative.endsWith("equal")){
        for(Integer time: timeList){
            VariableState min = stateInfo.stream().filter(p -> p.time == time ).min(Comparator.comparing(VariableState::getTime)).get();
                 newStateInfo.add(min);
        }
        }
        
        return newStateInfo;
    }

    static void print(List<VariableState> stateInfo) {
        for(VariableState vs: stateInfo){
            System.out.println(vs.var + ":" + vs.st +":" + vs.time);
        }
    }
    String st;
    String var;
    int time;
    Double value = null;
    RDFNode valueNode;
    private Double oldValue;
     Boolean removeAfterFilter;
    String timeURI;
    
    public VariableState( String _var,String _st, RDFNode _timeURI, RDFNode _val ){
        st = _st;
        var = _var;
        timeURI = _timeURI.toString();
        time = _timeURI.asLiteral().getInt();
        valueNode = _val;
        if(_val != null)
        value = _val.asLiteral().getDouble();//Integer.parseInt(_val.toString());
        removeAfterFilter = false;
    }
    
    public VariableState( String _var,String _st, String _timeURI, String _val ){
        st = _st;
        var = _var;
        timeURI = _timeURI;
        
        if(_timeURI.endsWith("integer") || _timeURI.endsWith("int")){
            int index = _timeURI.indexOf('^');
            time = Integer.parseInt(_timeURI.substring(0, index));
        } else{
           System.out.println("Error in VariableState constructor");
            System.exit(0);
        }
        
        if(_val != null && !_val.isEmpty()){
        if(_val.endsWith("long") || _val.endsWith("integer") || _val.endsWith("decimal") ){
            int index = _val.indexOf('^');
            value = Double.parseDouble(_val.substring(0, index));
             
        } else{
            System.out.println("Error in VariableState constructor");
            System.exit(0);
            
            //value = (long)0;
        }
        }
        
        Model temp = ModelFactory.createDefaultModel();
            valueNode = temp.createTypedLiteral(value);
        removeAfterFilter = false;
    }
    
   
    
    //Util.makeIntNode(Integer.parseInt(p.get(timeQueryVariable))),
          
    public int getTime(){
        return time;
    }

    StreamEx<Object> valueCompare(VariableState b, String i) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    String getCSVString() {
        StringBuilder sb = new StringBuilder();
        sb.append(var).append(",");
         sb.append(st).append(",");
         if(valueNode != null)
         sb.append(valueNode.toString()).append(",");
         else sb.append(",");
         sb.append(timeURI);
        return sb.toString();
        
    }
    
}
