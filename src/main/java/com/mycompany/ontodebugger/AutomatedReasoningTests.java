/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.mycompany.ontodebugger;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author aidb
 */
public class AutomatedReasoningTests {

    static List<List<String>> csvList = new ArrayList<List<String>>();
    static String[] csvStrings = new String[]{
        "CreateFilteredSpan(file0:S1, pa:values, 3, 4).IsIncreasingList.exit.",
        /*sed*/     "CreateSpan(file0:S1);VarsInSpan(file0:S1,file0:2508_1_2508_36);StsInSpan(file0:S1,file0:3501_1_3501_30,file0:3503_1_3503_15).IsAllDistinctSpan(file0:S1).exit.",
        /*space*/   "CreateSpan(file0:S1);VarsInSpan(file0:S1,file0:2658_1_2658_32);StsInSpan(file0:S1,file0:2671_1_2671_15).IsAllDistinctSpan(file0:S1).exit.",
        /*tot_info*/"CreateSpan(file0:S1);VarsInSpan(file0:S1,file0:130_1_130_14);StsInSpan(file0:S1,file0:172_1_172_15)."+
            "IsIncreasingSpan(file0:S1).exit.",
            
        /*schdeule*/"CreateSpan(file0:S1);VarsInSpan(file0:S1,file0:654_1_654_5);StsInSpan(file0:S1,file0:660_1_660_32)."+
            "IsAllNonZeroSpan(file0:S1).exit.", 
        
        
       /*print_tokens*/"CreateSpan(file0:S1);VarsInSpan(file0:S1,file0:717_1_717_14);StsInSpan(file0:S1,file0:1000_11_1000_46)." +
            "CreateSpan(file0:S2);SpanTimeInstant(file0:S2, pa:after, t2);timeInstantForAGivenState(t2, ?st in (file0:1000_11_1000_46));VarsInSpan(file0:S2,file0:717_1_717_14);StsInSpan(file0:S2,file0:1028_1_1028_17)." +
"IsEqualSpanOf(file0:S1,file0:S2).exit.",

/*print_tokens2*/
"CreateSpan(file0:S2);SpanTimeInstant(file0:S2, pa:after, t2);timeInstantForAGivenState(t2, ?var in(file0:986_1_986_7) && ?st in (file0:1006_4_1006_10) && ?val in (59));VarsInSpan(file0:S2,file0:986_1_986_7);StsInSpan(file0:S2,file0:1016_1_1016_10)." + 
"IsAllSameSpan(file0:S2).exit.",

///*print_tokens2*/"CreateSpan(file0:S1);SpanTimeInstant(file0:S1, pa:equal, t);timeInstantForAGivenState(t, ?var in (file0:986_1_986_7) && ?st in (file0:1006_4_1006_10) && ?val in (59))." + 
//"CreateSpan(file0:S2);SpanTimeInstant(file0:S2, pa:after, t2);timeInstantForAGivenState(t2, ?var in(file0:986_1_986_7) && ?st in (file0:1006_4_1006_10) && ?val in (59));VarsInSpan(file0:S2,file0:986_1_986_7);StsInSpan(file0:S2,file0:1016_1_1016_10)." + 
//"IsAllSameSpan(file0:S2).exit.",
            //"IsSpanWithNon-ZeroElement(file0:S2).exit.",



/*grep*/"CreateSpan(file0:S1);VarsInSpan(file0:S1,file0:4068_1_4068_17);StsInSpan(file0:S1,file0:4069_8_4069_106).IsAllNonNegativeSpan(file0:S1).exit.",
        /*flex*/"getExecutionPathInFunction(file0:4913_1_4913_43).exit.",
        
        /*sed_scale*/"CreateSpan(file0:S1);VarsInSpan(file0:S1,file0:2505_1_2505_13);" +
            "SpanTiming(file0:S1,20,zzz).IsAllZeroSpan(file0:S1).exit.",
        
        "CreateBinaryTreeAfterAStatement(file0:T1, file0:40_6_43_41_exit, 43, 105)." +
 "AddTreeElement(file0:T1, file0:32_37_32_37, file0:7_6_7_22, file0:8_6_8_23)"

    };
    
    /*print_tokens2*///"CreateSpanWithFilter(file0:S1, e1 == 59);VarsInSpan(file0:S1,file0:986_1_986_7);StsInSpan(file0:S1,file0:1006_4_1006_10)."
            //+"CreateSpanWithFilter(file0:S2, e1 == 10);VarsInSpan(file0:S2,file0:986_1_986_7);StsInSpan(file0:S2,file0:1016_1_1016_10).IsBeforeListOf(file0:S1,file0:S2).exit.",

    
    static int testIndex = 0; // test case index
    static int counter = 0;

    public static void init() {
       
        
        if(Settings.settingsInput.startsWith("sed_scale")){
            Integer scalingSize = Integer.parseInt(Settings.settingsInput.substring(9));
            
            testIndex = 9;
            csvStrings[testIndex] = csvStrings[testIndex].replaceAll("zzz", scalingSize.toString());
        }
        else if(Settings.settingsInput.equals("flex"))
            testIndex = 8;
        else if(Settings.settingsInput.equals("grep"))
            testIndex = 7;
        else if(Settings.settingsInput.equals("print_tokens2"))
            testIndex = 6;
        else if(Settings.settingsInput.equals("print_tokens"))
            testIndex = 5;
        else if(Settings.settingsInput.equals("schdeule"))
            testIndex = 4;
        else if(Settings.settingsInput.equals("tot_info"))
            testIndex = 3;
        else if(Settings.settingsInput.equals("space"))
            testIndex = 2;
        else if(Settings.settingsInput.equals("sed"))
            testIndex = 1;
        //else if(Settings.settingsInput.equals("sed"))
          //  testIndex = 0;
        //write the CSV back out to the console
        /* for(List<String> csv : csvList)
        {
            //dumb logic to place the commas correctly
            if(!csv.isEmpty())
            {
                System.out.print(csv.get(0));
                for(int i=1; i < csv.size(); i++)
                {
                    System.out.print("," + csv.get(i));
                }
            }
            System.out.print("\n");
        }
         */
        
         //sample CSV strings...pretend they came from a file

        //pretend you're looping through lines in a file here
        if (csvList.isEmpty()) {
            counter = 0;
            for (String line : csvStrings) {
                String[] linePieces = line.split("\\.");
                List<String> csvPieces = new ArrayList<String>(linePieces.length);
                for (String piece : linePieces) {
                    csvPieces.add(piece);
                }
                csvList.add(csvPieces);
            }
        }
    }

    public static String getNextCommand() {

        if(csvList.isEmpty())
            init();
        List<String> csv = csvList.get(testIndex);
        return csv.get(counter++);
    }
}
