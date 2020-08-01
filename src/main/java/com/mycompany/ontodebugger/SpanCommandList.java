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

import java.util.ArrayList;
import java.util.List;
import org.apache.jena.query.QuerySolution;

/**
 *
 * @author aidb
 */
public class SpanCommandList extends CommandList {

    Command createSpanCmd;
    Command variablesInTheSpanCmd;
    Command timingCmd;
    Command statementsInSpanCmd;
    
    List<String> varsInSpan = new ArrayList<>();
    String varsInSpanString;
    String spanName;
    String fromTime;
    String toTime;
   // String timeInstant;
   List<String> stsInSpanList= new ArrayList<>();
    String stsInSpanString;
    Boolean hasFilter;
    Boolean expression;
    String filter;
    String map;
    Command timingInstantCmd;
    Command queryCmd;
    String relativeTime;
    List<Integer> timeList = new ArrayList<>();
    boolean reuseTimingQueryResult = false;
    List<QuerySolution> timingQueryResult;

    void setSpanProperties() {
        setVariables();
        spanName = createSpanCmd.args.get(0);
        
        setTimings();
        setStatements();
        if(hasFilter) setFilter();
        if(expression) setMap();
        if(queryCmd != null) processQuery();
        if(timingInstantCmd != null){
            relativeTime = timingInstantCmd.args.get(1);
            if(relativeTime.endsWith("equal"))
                reuseTimingQueryResult = true;
        }
    }
    
    void setVariables(){
        /*
         List<String> VarsInSpan = null;
        Command command = getCommand(Settings.AbstractionFunctors.VariablesInTheSpan);
        if(command != null){
            
            VarsInSpanCommand = _varsInSpan.get();
            String varSetName = VarsInSpanCommand.args.get(1);
            VarsInSpan = this.stream().
                    filter(p -> p.abstractionFuncEnum == Settings.AbstractionFunctors.HasItem && p.args.get(0).equals(varSetName)).
                    map(p -> p.args.get(1)).collect(Collectors.toList());

        }
        else{
            //zzz: write sparql query to get all the variables at what? 
            //to do in future
            //Note that fromTime and toTime can be in different functions
        }
        return VarsInSpan;
         }
*/
        StringBuilder sb = new StringBuilder();
        
        
        if(variablesInTheSpanCmd != null){
            varsInSpan.add(variablesInTheSpanCmd.args.get(1));
                sb.append(variablesInTheSpanCmd.args.get(1));
            for (int i = 2; i < variablesInTheSpanCmd.args.size(); ++i){
                varsInSpan.add(variablesInTheSpanCmd.args.get(i));
                sb.append(",").append(variablesInTheSpanCmd.args.get(i));
            }
        }
        
        varsInSpanString = sb.toString();
    }        

    private void setTimings() {
        if(timingCmd != null ){
            if(timingCmd.args.size() == 3){
                fromTime = timingCmd.args.get(1);
                toTime = timingCmd.args.get(2);
            } else if(timingCmd.args.size() == 2){
               // timeInstant = timingCmd.args.get(1);
               fromTime = timingCmd.args.get(1);
                toTime = "100000";
            }
                
        }
    }

    private void setStatements() {
        StringBuilder sb = new StringBuilder();
        if(statementsInSpanCmd != null){
            stsInSpanList.add(statementsInSpanCmd.args.get(1));
            sb.append(statementsInSpanCmd.args.get(1));
           for (int i = 2; i < statementsInSpanCmd.args.size(); ++i){
                stsInSpanList.add(statementsInSpanCmd.args.get(i));
               sb.append(",").append(statementsInSpanCmd.args.get(i));
               }
        }
        stsInSpanString = sb.toString();

       
      /*  if(statementsInSpanCmd != null){
           for (int i = 1; i < statementsInSpanCmd.args.size(); ++i){
                stsInSpanList.add(statementsInSpanCmd.args.get(i));
               }
        }*/
    }
    
    public boolean containsTime(){
        if(timingCmd != null) 
            return true;
        return false;
    }
    
    public boolean containsStatements(){
        if(statementsInSpanCmd != null) 
            return true;
        return false;
    }

    private void setFilter() {
        filter = createSpanCmd.args.get(1);
    }

    private void setMap() {
        map = createSpanCmd.args.get(1);
        //throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    private void processQuery() {
        //Session.processDirectQuery(queryCmd);
        timingQueryResult = Session.getTimingForState_Query(queryCmd);
        timingQueryResult.stream().forEach(p -> 
                timeList.add(p.get("?time").asLiteral().getInt()));
    }
    
}
