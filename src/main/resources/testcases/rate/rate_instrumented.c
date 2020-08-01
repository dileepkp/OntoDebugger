#include <stdio.h>

FILE *yyfp = fopen("/home/aidb/Dropbox/testcases/rate_instrumented.c","w");
int yyseq = 1;

int main(){
int i;
float x[] = {1,10,20,40,60};
 fprintf( yyfp, "zzzfile0:4_1_4_9-%d pa:beforeStatement file0:4_1_4_9\n", yyseq);
 fprintf( yyfp, "zzzfile0:4_1_4_9-%d pa:timeStamp %d\n" , yyseq, yyseq);

float y[] = {0.013,0.092,0.23,0.51,0.8};
 fprintf( yyfp, "zzzfile0:5_1_5_9-%d pa:beforeStatement file0:5_1_5_9\n", yyseq);
 fprintf( yyfp, "zzzfile0:5_1_5_9-%d pa:timeStamp %d\n" , yyseq, yyseq);

float z[] = {0.072,0.14,0.17,0.23,0.28};
 fprintf( yyfp, "zzzfile0:6_1_6_9-%d pa:beforeStatement file0:6_1_6_9\n", yyseq);
 fprintf( yyfp, "zzzfile0:6_1_6_9-%d pa:timeStamp %d\n" , yyseq, yyseq);


for(i = 1; i<=4; ++i)
 fprintf( yyfp, "zzzfile0:8_12_8_15-%d pa:beforeStatement file0:8_12_8_15\n", yyseq);
 fprintf( yyfp, "zzzfile0:8_12_8_15-%d pa:timeStamp %d\n" , yyseq, yyseq);
 fprintf( yyfp, "zzzfile0:3_1_3_5 pa:hasState file0:3_1_3_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:3_1_3_5_state-%d pa:hasValue %d\n", yyseq, i);
 fprintf( yyfp, "zzzfile0:3_1_3_5_state-%d pa:atProgramPoint file0:8_12_8_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:4_1_4_9 pa:hasState file0:4_1_4_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:4_1_4_9_state-%d pa:hasValue %f\n", yyseq, x[i-1]);
 fprintf( yyfp, "zzzfile0:4_1_4_9_state-%d pa:atProgramPoint file0:8_12_8_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:6_1_6_9 pa:hasState file0:6_1_6_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:6_1_6_9_state-%d pa:hasValue %f\n", yyseq, z[i-1]);
 fprintf( yyfp, "zzzfile0:6_1_6_9_state-%d pa:atProgramPoint file0:8_12_8_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:4_1_4_9 pa:hasState file0:4_1_4_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:4_1_4_9_state-%d pa:hasValue %f\n", yyseq, x[i]);
 fprintf( yyfp, "zzzfile0:4_1_4_9_state-%d pa:atProgramPoint file0:8_12_8_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:6_1_6_9 pa:hasState file0:6_1_6_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:6_1_6_9_state-%d pa:hasValue %f\n", yyseq, z[i]);
 fprintf( yyfp, "zzzfile0:6_1_6_9_state-%d pa:atProgramPoint file0:8_12_8_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:5_1_5_9 pa:hasState file0:5_1_5_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:5_1_5_9_state-%d pa:hasValue %f\n", yyseq, y[i-1]);
 fprintf( yyfp, "zzzfile0:5_1_5_9_state-%d pa:atProgramPoint file0:8_12_8_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:5_1_5_9 pa:hasState file0:5_1_5_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:5_1_5_9_state-%d pa:hasValue %f\n", yyseq, y[i]);
 fprintf( yyfp, "zzzfile0:5_1_5_9_state-%d pa:atProgramPoint file0:8_12_8_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;

printf("%d ,%.4f,%.4f\n",((int)x[i]), (y[i] - y[i-1]) / (x[i] - x[i-1]), (z[i] - z[i-1]) / (x[i] - x[i-1]));
 fprintf( yyfp, "zzzfile0:9_1_9_108-%d pa:beforeStatement file0:9_1_9_108\n", yyseq);
 fprintf( yyfp, "zzzfile0:9_1_9_108-%d pa:timeStamp %d\n" , yyseq, yyseq);
 fprintf( yyfp, "zzzfile0:3_1_3_5 pa:hasState file0:3_1_3_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:3_1_3_5_state-%d pa:hasValue %d\n", yyseq, i);
 fprintf( yyfp, "zzzfile0:3_1_3_5_state-%d pa:atProgramPoint file0:9_1_9_108-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;


printf("\n\n");
return 0;
}

