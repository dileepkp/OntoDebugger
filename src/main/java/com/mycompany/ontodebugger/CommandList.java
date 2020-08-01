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

import com.mycompany.ontodebugger.Settings.AbstractionFunctors;
import com.mycompany.ontodebugger.Settings.Abstractions;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.stream.Collectors;

/**
 *
 * @author aidb
 */
public class CommandList extends ArrayList<Command> {
    
    Abstractions abstraction;
    CommandList cl = null;
    BreakPointCommandList bpcl = null;
    public CommandList(){
        
        
    }
    
   

    Command getFilteredSliceCmd() {
        return getCommandWithFuntor(AbstractionFunctors.CreateSpan);
    }

    private Command getCommandWithFuntor(AbstractionFunctors functor) {
        Optional<Command> findFirst = this.stream().
                filter(p -> p.abstractionFuncEnum == functor).findFirst(); //.get();
        if(findFirst.isPresent())
            return findFirst.get();
        else return null;
    }

    Abstractions process() {
         
        Boolean hasFilter = false;
        Boolean hasExpression = false;
        Command createSpan = getCommand(AbstractionFunctors.CreateSpan);
        Command st_var = getCommand(AbstractionFunctors.st_var);
        if(createSpan != null && st_var == null){
            abstraction = Abstractions.ValueSpan;
            if(createSpan.args.size() == 2 && createSpan.args.get(1).endsWith("expression"))
                hasExpression = true;
            
             //abstraction = Abstractions.ValueSpan;
            SpanCommandList scl = new SpanCommandList();
            scl.createSpanCmd = createSpan;
            scl.variablesInTheSpanCmd = getCommand(AbstractionFunctors.VariablesInTheSpan);
            scl.timingCmd = getCommand(AbstractionFunctors.SpanTiming);
            scl.statementsInSpanCmd = getCommand(AbstractionFunctors.StsInSpan);
            scl.hasFilter = hasFilter;
            scl.expression = hasExpression;
            scl.timingInstantCmd = getCommand(AbstractionFunctors.SpanTimeInstant);
            scl.queryCmd = getCommand(AbstractionFunctors.timeInstantForAGivenState);
           // if(scl.statementsInSpanCmd == null)
            //    scl.statementsInSpanCmd = getCommand(AbstractionFunctors.StatementSetInTheSpan);
            scl.setSpanProperties();
            cl = scl;
                    return abstraction;
        } 
        else if(createSpan != null && st_var!=null){
            abstraction = Abstractions.ProgStateSpan;
           ProgStateSpanCommandList scl = new ProgStateSpanCommandList();
                   
            scl.createSpanCmd = createSpan;
            scl.st_varCmd = getCommand(AbstractionFunctors.st_var);
            scl.setSpanProperties();
            cl = scl;
        }
        
        /*else {
        
        createSpan = getCommand(AbstractionFunctors.CreateSpanWithFilter);
        if(createSpan != null){
            abstraction = Abstractions.SpanWithFilter;
            hasFilter = true;
        }  else {
             createSpan = getCommand(AbstractionFunctors.CreateSpanWithMap);
        if(createSpan != null){
            abstraction = Abstractions.SpanWithMap;
            expression = true;
        }
        }
        }*/
        
        Command breakPointCommand = getCommand(Settings.QueryFunctors.break1);
        if(breakPointCommand != null) {
            abstraction = Abstractions.SimulationSession;
            bpcl = new BreakPointCommandList();
            bpcl.breakPointCmd = breakPointCommand;
            bpcl.printCmd = getCommand(Settings.QueryFunctors.print);
            //bpcl.setProperties();
            
        }
        
       
        
        return abstraction;
        

    
    }
    
    
    
    Command getCommand(AbstractionFunctors functor){
         Optional<Command> _absType = this.stream().
                filter(p -> p.abstractionFuncEnum == functor).
                findFirst();
        if(_absType.isPresent()){
            return _absType.get();
        }
        return null;
    }
    
    Command getCommand(Settings.QueryFunctors functor){
         Optional<Command> _absType = this.stream().
                filter(p -> p.functorName.equals(functor.toString())).
                findFirst();
        if(_absType.isPresent()){
            return _absType.get();
        }
        return null;
    }
    
    List<Command> getCommands(Settings.QueryFunctors functor){
        List<Command> _commands = this.stream().
                filter(p -> p.functorName.equals(functor.toString())).
                collect(Collectors.toList());
        
        return _commands;
    }
}
