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

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author aidb
 */
public class Experiments {
     public static void main(String[] args) throws Exception{
         List<String> sirBenchMarks = new ArrayList<String>();
       //  sirBenchMarks.add("flex");
        sirBenchMarks.add("grep");
        sirBenchMarks.add("print_tokens");
        sirBenchMarks.add("print_tokens2");
        sirBenchMarks.add("schdeule");
        sirBenchMarks.add("sed");
        sirBenchMarks.add("space");
        sirBenchMarks.add("tot_info");
        
        getAbstractionTimings(sirBenchMarks);
        
        
    }
     static int iterations = 1;
     static long queryTime;
     static long abstractionTime;
     static long reasoningTime;
    static void getAbstractionTimings( List<String> sirBenchMarks) throws Exception {
        
        for(String benchmark: sirBenchMarks){
            Settings.settingsInput = benchmark;
            AutomatedReasoningTests.csvList.clear();
            queryTime = 0;
            abstractionTime = 0;
            for(int i =1; i <=iterations; ++i ){
            Main.main(null);
            queryTime += Settings.netTimeForQuery;
            abstractionTime += Settings.netTime;
           }
            
            System.out.println("--------------------------------------------");
            System.out.println("--------------ssss--------------------------");
            System.out.println(benchmark);
            long avgQueryTime = queryTime / iterations;
            long avgAbstractionTime = abstractionTime / iterations;
            System.out.println("Timings:" + avgQueryTime + "  " + avgAbstractionTime);

        }
    }
}
