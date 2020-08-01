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
import imop.Main;
import imop.ast.node.external.FunctionDefinition;
import imop.ast.node.external.Node;
import imop.ast.node.external.Statement;
import imop.ast.node.internal.PreCallNode;
import imop.lib.analysis.flowanalysis.Cell;
import imop.lib.analysis.flowanalysis.Symbol;
import imop.lib.transform.updater.InsertImmediateSuccessor;
import imop.lib.transform.updater.sideeffect.SideEffect;
import imop.lib.util.Misc;
import imop.parser.FrontEnd;
import imop.parser.Program;
import java.io.FileNotFoundException;
import java.util.List;
/**
 *
 * @author aidb
 */
public class IMOPTest {
    public static void main(String[] args) throws FileNotFoundException, InterruptedException{
        //System.out.println("test");
       //Main.main(args);
         String args2[] = {"-f", "/home/aidb/NetBeansProjects/imop-maven/output-dump/rate2.i"};
       Program.parseNormalizeInput(args2); // Program.getRoot()
		for (FunctionDefinition fd : Program.getRoot().getInfo().getAllFunctionDefinitions()) {
			for (Node n : fd.getInfo().getCFGInfo().getIntraTaskCFGLeafContents()) {
				System.out.println(n + "  " + Misc.getLineNum(n));
				for (Cell c : n.getInfo().getAccesses()) {
					if (c instanceof Symbol) {
						Symbol s = (Symbol) c;
						System.out.println(s.getName());
						Statement stmt = FrontEnd.parseAndNormalize(
								"printf(\"%s %d\"," + "\"" + s.getName() + "\"," + s.getName() + ");", Statement.class);
						System.out.println(stmt);

						List<SideEffect> sideEffects;
						if(n instanceof PreCallNode)
							sideEffects = InsertImmediateSuccessor.insert(n.getParent(), stmt);
						else 
							sideEffects = InsertImmediateSuccessor.insert(n, stmt);
						if (!Misc.changePerformed(sideEffects))
							System.out.println(n);
					}
				}

			}
		}
		System.out.println(Program.getRoot());

		// demo1("L1");
		// demo2();
		// demo3();
		// demo4();
		// demo5ab();
		// demo6();
		// demo7();
		// demo8();
		// demo9();
		// demo11();
		System.exit(0);
    }
}
