package com.mycompany.ontodebugger;

import java.util.List;
import org.apache.jena.query.Query;
import org.apache.jena.query.QueryExecution;
import org.apache.jena.query.QueryExecutionFactory;
import org.apache.jena.query.QueryFactory;
import org.apache.jena.query.QuerySolution;
import org.apache.jena.query.ResultSet;
import org.apache.jena.query.ResultSetFormatter;
import org.apache.jena.rdf.model.Model;

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
/**
 *
 * @author aidb
 */
import com.google.common.collect.Table;
import com.google.common.collect.HashBasedTable;
import com.google.common.collect.TreeBasedTable;
import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collection;
import org.apache.jena.query.ResultSetFactory;
import org.apache.jena.sparql.resultset.ResultsFormat;


/* trash*/
public class Sparql_hash {

    static Table<String, String, List<VariableState>> table = HashBasedTable.create();

    public static void init() {
        String query = ReadInput.readInstrumentationQuery("getTraceInformation");
        List<QuerySolution> results = Sparql.executeQuery(query, Settings.modelWithProgramAndTrace);
           Sparql.executeQueryAndPrint(query, Settings.modelWithProgramAndTrace);
        String prevSt = null, st = null, prevVar = null, var = null;
        List<VariableState> vsList = new ArrayList<>();
        for (QuerySolution qs : results) {
            var = qs.get("?var").toString();
            st = qs.get("?st").toString();
            VariableState vs = new VariableState(var, st, qs.get("?time"),
                     qs.get("?val"));

            if (prevVar != null && prevSt != null) {
                if (!(var.equals(prevVar) && st.equals(prevSt))) {
                    //System.out.println(prevVar + " " + prevSt + " " +vsList.size());
                    table.put(prevVar, prevSt, vsList);
                    vsList = new ArrayList<>();
                } 
            } 
            vsList.add(vs);

            prevVar = var;
            prevSt = st;
        }
        //System.out.println(var + " " + st + " " +vsList.size());
        table.put(prevVar, prevSt, vsList);
        getVirtualSparqlResult();
       /* System.out.println(table.size());
        //System.out.println(table.toString());
        query = ReadInput.readInstrumentationQuery("getTraceInformation_test");
        results = Sparql.executeQuery(query, Settings.modelWithProgramAndTrace);
        System.out.println(results.size());
        Sparql.executeQueryAndPrint(query, Settings.modelWithProgramAndTrace);
        */
        

    }
    
    public static void getVirtualSparqlResult(){
        Collection<List<VariableState>> values = table.values();
        StringBuilder sb = new StringBuilder();
        sb.append("var, st, val, time").append("\n");
        for(List<VariableState> vsList : values){
            for(VariableState vs: vsList){
                sb.append(vs.getCSVString()).append("\n");
            }
        }
        
        InputStream is = new ByteArrayInputStream( sb.toString().getBytes() );
        ResultSet resultSet = ResultSetFactory.load(is, ResultsFormat.FMT_RS_CSV);
        List<QuerySolution> resultList = ResultSetFormatter.toList(resultSet);
        
    }



/*  public static void main(String[] args){
        Table<String,String,Integer> table = TreeBasedTable.create();
table.put("r1","c1",20);
table.put("r1","c1",30);
       
        table.row("r1");
System.out.println(table.cellSet().size());
    }
 */
}
