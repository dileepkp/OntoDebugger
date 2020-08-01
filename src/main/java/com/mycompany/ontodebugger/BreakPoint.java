/*
 * Copyright (c) 2020, aidb
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

import java.util.List;
import org.apache.jena.query.QuerySolution;

/**
 *
 * @author aidb
 */
public class BreakPoint {
    String st;
    List<QuerySolution> executionInfo;
    String var;
    String val;
    int time;
    int nextIndex;
   /* public BreakPoint(String _st, List<QuerySolution> _executionInfo){
        st = _st;
        executionInfo = _executionInfo;
        executionInfo.forEach(p -> {
        var = p.get("var").toString();
        val = p.get("var").toString();
        time = p.get("time").asLiteral().getInt();
        });
    }
*/
    public BreakPoint(String _st, String _var, String _val, String _timeURI) {
        st = _st;
        var = _var;
        val = _val;
         if(_timeURI.endsWith("integer") || _timeURI.endsWith("int")){
            int index = _timeURI.indexOf('^');
            time = Integer.parseInt(_timeURI.substring(0, index));
        } else{
           System.out.println("Error in VariableState constructor");
            System.exit(0);
        }
        
        //time = _time;
    }
}
