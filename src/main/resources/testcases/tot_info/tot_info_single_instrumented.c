
/*
tot_info -- combine information statistics for multiple tables
last edit: 89/02/06 D A Gwyn
SCCS ID: @(#)tot_info.c 1.1 (edited for publication)
*/
#include <ctype.h>
#include <stdio.h>
#ifndef VLD_STD_H_
#define VLD_STD_H_ /* once-only latch */
/* Extended data types */
typedef int bool; /* Boolean data */
#define  false 0
#define  true 1
/* ANSI C definitions */
/* Defense against some silly systems defining __STDC__ to random things. */
#ifdef STD_C
#undef STD_C
#endif
#ifdef __STDC__
#if __STDC__ > 0
#define STD_C __STDC__ /* use this instead of __STDC__ */
#endif
#endif
#ifdef STD_C
typedef void *pointer; /* generic pointer */
#else
typedef char *pointer; /* generic pointer */
#define const /* nothing */ /* ANSI C type qualifier */
/* There really is no substitute for the following, but these might work: */
#define signed /* nothing */ /* ANSI C type specifier */
#define volatile /* nothing */ /* ANSI C type qualifier */
#endif
#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif
#ifndef EXIT_FAILURE
#define EXIT_FAILURE 1
#endif
#ifndef NULL
#define NULL 0 /* null pointer constant, all types */
#endif
/* Universal constants */
#define DEGRAD 57.2957795130823208767981548141051703324054724665642
/* degrees per radian */
#define E 2.71828182845904523536028747135266249775724709369996
/* base of natural logs */
#define GAMMA 0.57721566490153286061
/* Euler's constant */
#define LOG10E 0.43429448190325182765112891891660508229439700580367
/* log of e to the base 10 */
#define PHI 1.618033988749894848204586834365638117720309180
/* golden ratio */
#define PI 3.14159265358979323846264338327950288419716939937511
/* ratio of circumf. to diam. */
/* Useful macros */
/*
The comment "UNSAFE" means that the macro argument(s) may be evaluated
more than once, so the programmer must realize that the macro doesn't
quite act like a genuine function.  This matters only when evaluating
an argument produces "side effects".
*/
/* arbitrary numerical arguments and value: */
#define Abs( x ) ((x) < 0 ? -(x) : (x)) /* UNSAFE */
#define Max( a, b ) ((a) > (b) ? (a) : (b)) /* UNSAFE */
#define Min( a, b ) ((a) < (b) ? (a) : (b)) /* UNSAFE */
/* floating-point arguments and value: */
#define Round( d ) (floor( (d) + 0.5 )) /* requires <math.h> */
/* arbitrary numerical arguments, integer value: */
#define Sgn( x ) ((x) == 0 ? 0 : (x) > 0 ? 1 : -1) /* UNSAFE */
/* string arguments, boolean value: */
#ifdef gould /* UTX-32 2.0 compiler has problems with "..."[] */
#define StrEq( a, b ) (strcmp( a, b ) == 0) /* UNSAFE */
#else
#define StrEq( a, b ) (*(a) == *(b) && strcmp( a, b ) == 0) /* UNSAFE */
#endif
/* array argument, integer value: */
#define Elements( a ) (sizeof a / sizeof a[0])
/* integer (or character) arguments and value: */
#define fromhostc( c ) (c) /* map host char set to ASCII */
#define tohostc( c ) (c) /* map ASCII to host char set */
#define tonumber( c ) ((c) - '0') /* convt digit char to number */
#define todigit( n ) ((n) + '0') /* convt digit number to char */
/* Kludges for deficient C implementations */
/*#define strchr index /* 7th Edition UNIX, 4.2BSD */
/*#define strrchr rindex /* 7th Edition UNIX, 4.2BSD */
/*#define void int /* K&R Appendix A followers */
#endif /* VLD_STD_H_ */
#ifdef __STDC__
extern double ChiSqTbl( int r, int c, const long *f, int *pdf );
extern double InfoTbl( int r, int c, const long *f, int *pdf );
#else
extern double ChiSqTbl();
extern double InfoTbl();
#endif
#ifdef __STDC__
extern double Gamma( double z ), LGamma( double z ),
Factorial( int n ), LFactorial( int n ),
BCoeff( int n, int k ),
Beta( double z, double w ),
PGamma( double a, double x ), QGamma( double a, double x ),
Erf( double x ), Erfc( double x ),
CPoisson( double x, int k ),
PChiSq( double chisq, int nu ), QChiSq( double chisq, int nu );
#else
extern double Gamma(), LGamma(), Factorial(), LFactorial(),
BCoeff(), Beta(), PGamma(), QGamma(), Erf(), Erfc(),
CPoisson(), PChiSq(), QChiSq();
#endif
#define MAXLINE 256
#ifndef MAXTBL
#define MAXTBL 1000
#endif
static char line[MAXLINE]; /* row/column header input line */
static long f[MAXTBL]; /* frequency tallies */
static int r; /* # of rows */
static int c; /* # of columns */
#define x(i,j) f[(i)*c+(j)] /* convenient way to access freqs */
#define COMMENT '#' /* comment character */
#ifndef NULL
#define NULL 0
#endif

FILE *yyfp;

int yyseq = 1; int ppseq = 1;

/*ARGSUSED*/
int main(int argc,char *argv[]) {

char *p; /* input line scan location */

int i; /* row index */

int j; /* column index */

double info; /* computed information measure */

int infodf; /* degrees of freedom for information */

double totinfo = 0.0; /* accumulated information */

int totdf; /* accumulated degrees of freedom */

yyfp = fopen("/home/aidb/Dropbox/testcases/tot_info/tot_info_single_trace.ttl","w");
 fprintf( yyfp, "@prefix c: <http://www.semanticweb.org/yzhao30/ontologies/2015/7/c#> .\n@prefix file0: <ftp://home/demo/Dropbox/testcases/tot_info/tot_info_single.c#> .\n@prefix owl: <http://www.w3.org/2002/07/owl#> .\n@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .\n@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .\n@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .\n@prefix pa: <http://www.semanticweb.org/aidb/ontologies/BugFindingOntology#> .\n@prefix pdo: <http://www.semanticweb.org/aidb/ontologies/ProgramDebuggingOntology#> .\n\n\n\n");
totdf = 0;
 fprintf( yyfp, "file0:131_1_131_9 pa:hasState file0:131_1_131_9_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:131_1_131_9_state-%d pa:hasValue %d .\n", yyseq, totdf);
 fprintf( yyfp, "file0:131_1_131_9_state-%d pa:atProgramPoint file0:132_1_132_10-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:132_1_132_10-%d pa:afterStatement file0:132_1_132_10. \n", ppseq);
 fprintf( yyfp, "file0:132_1_132_10-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

while ( fgets( line, MAXLINE, stdin ) != NULL ) /* start new table */

{
for ( p = line; *p != '\0' && isspace( (int)*p ); ++p ){
 fprintf( yyfp, "file0:125_1_125_7 pa:hasState file0:125_1_125_7_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:125_1_125_7_state-%d pa:atProgramPoint file0:135_51_135_53-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:135_51_135_53-%d pa:afterStatement file0:135_51_135_53. \n", ppseq);
 fprintf( yyfp, "file0:135_51_135_53-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

;
}

if ( *p == '\0' ){
continue;
}
 fprintf( yyfp, "file0:125_1_125_7 pa:hasState file0:125_1_125_7_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:125_1_125_7_state-%d pa:atProgramPoint file0:139_1_141_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:139_1_141_1-%d pa:afterStatement file0:139_1_141_1. \n", ppseq);
 fprintf( yyfp, "file0:139_1_141_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

/* skip blank line */
if ( *p == COMMENT ){ /* copy comment through */
(void)fputs( line, stdout );

continue;
}
 fprintf( yyfp, "file0:125_1_125_7 pa:hasState file0:125_1_125_7_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:125_1_125_7_state-%d pa:atProgramPoint file0:143_1_146_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:143_1_146_1-%d pa:afterStatement file0:143_1_146_1. \n", ppseq);
 fprintf( yyfp, "file0:143_1_146_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

if ( sscanf( p, "%d %d\n", &r, &c ) != 2 ){
(void)fputs( "* invalid row/column line *\n", stdout );

return EXIT_FAILURE;
}
 fprintf( yyfp, "file0:117_1_117_12 pa:hasState file0:117_1_117_12_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:117_1_117_12_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:117_1_117_12_state-%d pa:atProgramPoint file0:147_1_150_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:116_1_116_12 pa:hasState file0:116_1_116_12_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:116_1_116_12_state-%d pa:hasValue %d .\n", yyseq, r);
 fprintf( yyfp, "file0:116_1_116_12_state-%d pa:atProgramPoint file0:147_1_150_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:125_1_125_7 pa:hasState file0:125_1_125_7_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:125_1_125_7_state-%d pa:atProgramPoint file0:147_1_150_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:147_1_150_1-%d pa:afterStatement file0:147_1_150_1. \n", ppseq);
 fprintf( yyfp, "file0:147_1_150_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

if ( r * c > MAXTBL ){
(void)fputs( "* table too large *\n", stdout );

return EXIT_FAILURE;
}
 fprintf( yyfp, "file0:117_1_117_12 pa:hasState file0:117_1_117_12_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:117_1_117_12_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:117_1_117_12_state-%d pa:atProgramPoint file0:151_1_154_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:116_1_116_12 pa:hasState file0:116_1_116_12_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:116_1_116_12_state-%d pa:hasValue %d .\n", yyseq, r);
 fprintf( yyfp, "file0:116_1_116_12_state-%d pa:atProgramPoint file0:151_1_154_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:151_1_154_1-%d pa:afterStatement file0:151_1_154_1. \n", ppseq);
 fprintf( yyfp, "file0:151_1_154_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

/* input tallies */
for ( i = 0; i < r; ++i ){
 fprintf( yyfp, "file0:126_1_126_5 pa:hasState file0:126_1_126_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:126_1_126_5_state-%d pa:hasValue %d .\n", yyseq, i);
 fprintf( yyfp, "file0:126_1_126_5_state-%d pa:atProgramPoint file0:156_21_156_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:116_1_116_12 pa:hasState file0:116_1_116_12_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:116_1_116_12_state-%d pa:hasValue %d .\n", yyseq, r);
 fprintf( yyfp, "file0:116_1_116_12_state-%d pa:atProgramPoint file0:156_21_156_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:156_21_156_23-%d pa:afterStatement file0:156_21_156_23. \n", ppseq);
 fprintf( yyfp, "file0:156_21_156_23-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

for ( j = 0; j < c; ++j ){
 fprintf( yyfp, "file0:127_1_127_5 pa:hasState file0:127_1_127_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:127_1_127_5_state-%d pa:hasValue %d .\n", yyseq, j);
 fprintf( yyfp, "file0:127_1_127_5_state-%d pa:atProgramPoint file0:157_21_157_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:117_1_117_12 pa:hasState file0:117_1_117_12_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:117_1_117_12_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:117_1_117_12_state-%d pa:atProgramPoint file0:157_21_157_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:157_21_157_23-%d pa:afterStatement file0:157_21_157_23. \n", ppseq);
 fprintf( yyfp, "file0:157_21_157_23-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

if ( scanf( " %ld", &(f[(i)*c+(j)]) ) != 1 ){
(void)fputs( "* EOF in table *\n",
stdout
);

return EXIT_FAILURE;
}}}
 fprintf( yyfp, "f[(i)*c+(j)]_state-%d pa:atProgramPoint file0:158_1_163_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:117_1_117_12 pa:hasState file0:117_1_117_12_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:117_1_117_12_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:117_1_117_12_state-%d pa:atProgramPoint file0:158_1_163_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:127_1_127_5 pa:hasState file0:127_1_127_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:127_1_127_5_state-%d pa:hasValue %d .\n", yyseq, j);
 fprintf( yyfp, "file0:127_1_127_5_state-%d pa:atProgramPoint file0:158_1_163_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:126_1_126_5 pa:hasState file0:126_1_126_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:126_1_126_5_state-%d pa:hasValue %d .\n", yyseq, i);
 fprintf( yyfp, "file0:126_1_126_5_state-%d pa:atProgramPoint file0:158_1_163_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:158_1_163_1-%d pa:afterStatement file0:158_1_163_1. \n", ppseq);
 fprintf( yyfp, "file0:158_1_163_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

/* compute statistic */
info = InfoTbl( r, c, f, &infodf );
 fprintf( yyfp, "file0:117_1_117_12 pa:hasState file0:117_1_117_12_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:117_1_117_12_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:117_1_117_12_state-%d pa:atProgramPoint file0:165_1_165_35-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:116_1_116_12 pa:hasState file0:116_1_116_12_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:116_1_116_12_state-%d pa:hasValue %d .\n", yyseq, r);
 fprintf( yyfp, "file0:116_1_116_12_state-%d pa:atProgramPoint file0:165_1_165_35-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:129_1_129_10 pa:hasState file0:129_1_129_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:129_1_129_10_state-%d pa:hasValue %d .\n", yyseq, infodf);
 fprintf( yyfp, "file0:129_1_129_10_state-%d pa:atProgramPoint file0:165_1_165_35-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:128_1_128_11 pa:hasState file0:128_1_128_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:128_1_128_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:128_1_128_11_state-%d pa:atProgramPoint file0:165_1_165_35-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:165_1_165_35-%d pa:afterStatement file0:165_1_165_35. \n", ppseq);
 fprintf( yyfp, "file0:165_1_165_35-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

/* print results */
if ( info >= 0.0 ){
(void)printf( "2info = %5.2f\tdf = %2d\tq = %7.4f\n",
info, infodf,
QChiSq( info, infodf )
);
 fprintf( yyfp, "file0:128_1_128_11 pa:hasState file0:128_1_128_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:128_1_128_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:128_1_128_11_state-%d pa:atProgramPoint file0:168_1_171_2-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:129_1_129_10 pa:hasState file0:129_1_129_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:129_1_129_10_state-%d pa:hasValue %d .\n", yyseq, infodf);
 fprintf( yyfp, "file0:129_1_129_10_state-%d pa:atProgramPoint file0:168_1_171_2-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:168_1_171_2-%d pa:afterStatement file0:168_1_171_2. \n", ppseq);
 fprintf( yyfp, "file0:168_1_171_2-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

totinfo = info; /* removed + before = */
 fprintf( yyfp, "file0:128_1_128_11 pa:hasState file0:128_1_128_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:128_1_128_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:128_1_128_11_state-%d pa:atProgramPoint file0:172_1_172_15-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:130_1_130_14 pa:hasState file0:130_1_130_14_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:130_1_130_14_state-%d pa:hasValue %f .\n", yyseq, totinfo);
 fprintf( yyfp, "file0:130_1_130_14_state-%d pa:atProgramPoint file0:172_1_172_15-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:172_1_172_15-%d pa:afterStatement file0:172_1_172_15. \n", ppseq);
 fprintf( yyfp, "file0:172_1_172_15-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

totdf += infodf;
 fprintf( yyfp, "file0:129_1_129_10 pa:hasState file0:129_1_129_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:129_1_129_10_state-%d pa:hasValue %d .\n", yyseq, infodf);
 fprintf( yyfp, "file0:129_1_129_10_state-%d pa:atProgramPoint file0:173_1_173_16-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:131_1_131_9 pa:hasState file0:131_1_131_9_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:131_1_131_9_state-%d pa:hasValue %d .\n", yyseq, totdf);
 fprintf( yyfp, "file0:131_1_131_9_state-%d pa:atProgramPoint file0:173_1_173_16-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:173_1_173_16-%d pa:afterStatement file0:173_1_173_16. \n", ppseq);
 fprintf( yyfp, "file0:173_1_173_16-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

}
else
{
(void)fputs( info < -3.5 ? "out of memory\n"
: info < -2.5 ? "table too small\n"
: info < -1.5 ? "negative freq\n"
: "table all zeros\n",
stdout
);
 fprintf( yyfp, "file0:128_1_128_11 pa:hasState file0:128_1_128_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:128_1_128_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:128_1_128_11_state-%d pa:atProgramPoint file0:177_1_182_2-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:177_1_182_2-%d pa:afterStatement file0:177_1_182_2. \n", ppseq);
 fprintf( yyfp, "file0:177_1_182_2-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

}
 fprintf( yyfp, "file0:128_1_128_11 pa:hasState file0:128_1_128_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:128_1_128_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:128_1_128_11_state-%d pa:atProgramPoint file0:167_1_183_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:129_1_129_10 pa:hasState file0:129_1_129_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:129_1_129_10_state-%d pa:hasValue %d .\n", yyseq, infodf);
 fprintf( yyfp, "file0:129_1_129_10_state-%d pa:atProgramPoint file0:167_1_183_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:130_1_130_14 pa:hasState file0:130_1_130_14_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:130_1_130_14_state-%d pa:hasValue %f .\n", yyseq, totinfo);
 fprintf( yyfp, "file0:130_1_130_14_state-%d pa:atProgramPoint file0:167_1_183_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:131_1_131_9 pa:hasState file0:131_1_131_9_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:131_1_131_9_state-%d pa:hasValue %d .\n", yyseq, totdf);
 fprintf( yyfp, "file0:131_1_131_9_state-%d pa:atProgramPoint file0:167_1_183_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:167_1_183_1-%d pa:afterStatement file0:167_1_183_1. \n", ppseq);
 fprintf( yyfp, "file0:167_1_183_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;


}
if ( totdf <= 0 ){
(void)fputs( "\n*** no information accumulated ***\n", stdout );

return EXIT_FAILURE;
}
 fprintf( yyfp, "file0:131_1_131_9 pa:hasState file0:131_1_131_9_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:131_1_131_9_state-%d pa:hasValue %d .\n", yyseq, totdf);
 fprintf( yyfp, "file0:131_1_131_9_state-%d pa:atProgramPoint file0:186_1_189_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:186_1_189_1-%d pa:afterStatement file0:186_1_189_1. \n", ppseq);
 fprintf( yyfp, "file0:186_1_189_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

(void)printf( "\ntotal 2info = %5.2f\tdf = %2d\tq = %7.4f\n",
totinfo, totdf,
QChiSq( totinfo, totdf )
);
 fprintf( yyfp, "file0:131_1_131_9 pa:hasState file0:131_1_131_9_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:131_1_131_9_state-%d pa:hasValue %d .\n", yyseq, totdf);
 fprintf( yyfp, "file0:131_1_131_9_state-%d pa:atProgramPoint file0:190_1_193_2-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:130_1_130_14 pa:hasState file0:130_1_130_14_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:130_1_130_14_state-%d pa:hasValue %f .\n", yyseq, totinfo);
 fprintf( yyfp, "file0:130_1_130_14_state-%d pa:atProgramPoint file0:190_1_193_2-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:190_1_193_2-%d pa:afterStatement file0:190_1_193_2. \n", ppseq);
 fprintf( yyfp, "file0:190_1_193_2-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

return EXIT_SUCCESS;
}
/*  -*- Last-Edit:  Tue Dec 15 14:48:14 1992 by Tarak S. Goradia; -*- */
/*
Gamma -- gamma and related functions
last edit: 88/09/09 D A Gwyn
SCCS ID: @(#)gamma.c 1.1 (edited for publication)
Acknowledgement:
Code based on that found in "Numerical Methods in C".
*/
#include <math.h>
#include        <stdio.h>
//#include "std.h"
double
LGamma( 
double x)

{
static const double cof[6] =

{
76.18009173, -86.50532033, 24.01409822,
-1.231739516, 0.120858003e-2, -0.536382e-5
};
double tmp, ser;

int j;

if ( --x < 0.0 ) /* use reflection formula for accuracy */{
double pix = PI * x;
 fprintf( yyfp, "file0:209_8_209_8 pa:hasState file0:209_8_209_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:209_8_209_8_state-%d pa:hasValue %f .\n", yyseq, x);
 fprintf( yyfp, "file0:209_8_209_8_state-%d pa:atProgramPoint file0:219_1_219_10-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:219_1_219_10-%d pa:afterStatement file0:219_1_219_10. \n", ppseq);
 fprintf( yyfp, "file0:219_1_219_10-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

return log( pix / sin( pix ) ) - LGamma( 1.0 - x );
}
 fprintf( yyfp, "file0:209_8_209_8 pa:hasState file0:209_8_209_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:209_8_209_8_state-%d pa:hasValue %f .\n", yyseq, x);
 fprintf( yyfp, "file0:209_8_209_8_state-%d pa:atProgramPoint file0:218_1_221_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:218_1_221_1-%d pa:afterStatement file0:218_1_221_1. \n", ppseq);
 fprintf( yyfp, "file0:218_1_221_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

tmp = x + 5.5;
 fprintf( yyfp, "file0:216_1_216_10 pa:hasState file0:216_1_216_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:216_1_216_10_state-%d pa:hasValue %f .\n", yyseq, tmp);
 fprintf( yyfp, "file0:216_1_216_10_state-%d pa:atProgramPoint file0:222_1_222_14-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:209_8_209_8 pa:hasState file0:209_8_209_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:209_8_209_8_state-%d pa:hasValue %f .\n", yyseq, x);
 fprintf( yyfp, "file0:209_8_209_8_state-%d pa:atProgramPoint file0:222_1_222_14-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:222_1_222_14-%d pa:afterStatement file0:222_1_222_14. \n", ppseq);
 fprintf( yyfp, "file0:222_1_222_14-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

tmp -= (x + 0.5) * log( tmp );
 fprintf( yyfp, "file0:216_1_216_10 pa:hasState file0:216_1_216_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:216_1_216_10_state-%d pa:hasValue %f .\n", yyseq, tmp);
 fprintf( yyfp, "file0:216_1_216_10_state-%d pa:atProgramPoint file0:223_1_223_30-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:209_8_209_8 pa:hasState file0:209_8_209_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:209_8_209_8_state-%d pa:hasValue %f .\n", yyseq, x);
 fprintf( yyfp, "file0:209_8_209_8_state-%d pa:atProgramPoint file0:223_1_223_30-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:223_1_223_30-%d pa:afterStatement file0:223_1_223_30. \n", ppseq);
 fprintf( yyfp, "file0:223_1_223_30-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

ser = 1.0;
 fprintf( yyfp, "file0:216_1_216_15 pa:hasState file0:216_1_216_15_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:216_1_216_15_state-%d pa:hasValue %f .\n", yyseq, ser);
 fprintf( yyfp, "file0:216_1_216_15_state-%d pa:atProgramPoint file0:224_1_224_10-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:224_1_224_10-%d pa:afterStatement file0:224_1_224_10. \n", ppseq);
 fprintf( yyfp, "file0:224_1_224_10-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

for ( j = 0; j < 6; ++j ){
 fprintf( yyfp, "file0:217_1_217_5 pa:hasState file0:217_1_217_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:217_1_217_5_state-%d pa:hasValue %d .\n", yyseq, j);
 fprintf( yyfp, "file0:217_1_217_5_state-%d pa:atProgramPoint file0:225_21_225_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:225_21_225_23-%d pa:afterStatement file0:225_21_225_23. \n", ppseq);
 fprintf( yyfp, "file0:225_21_225_23-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

ser += cof[j] / ++x;
 fprintf( yyfp, "cof[j]_state-%d pa:atProgramPoint file0:226_1_226_20-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:209_8_209_8 pa:hasState file0:209_8_209_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:209_8_209_8_state-%d pa:hasValue %f .\n", yyseq, x);
 fprintf( yyfp, "file0:209_8_209_8_state-%d pa:atProgramPoint file0:226_1_226_20-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:217_1_217_5 pa:hasState file0:217_1_217_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:217_1_217_5_state-%d pa:hasValue %d .\n", yyseq, j);
 fprintf( yyfp, "file0:217_1_217_5_state-%d pa:atProgramPoint file0:226_1_226_20-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:216_1_216_15 pa:hasState file0:216_1_216_15_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:216_1_216_15_state-%d pa:hasValue %f .\n", yyseq, ser);
 fprintf( yyfp, "file0:216_1_216_15_state-%d pa:atProgramPoint file0:226_1_226_20-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:226_1_226_20-%d pa:afterStatement file0:226_1_226_20. \n", ppseq);
 fprintf( yyfp, "file0:226_1_226_20-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

}

return -tmp + log( 2.50662827465 * ser );
}
#define ITMAX 100
#define EPS 3.0e-7
static double
gser( 
double a, double x)

{
double ap, del, sum;

int n;

if ( x <= 0.0 ){
return 0.0;
}
 fprintf( yyfp, "file0:235_18_235_18 pa:hasState file0:235_18_235_18_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:235_18_235_18_state-%d pa:hasValue %f .\n", yyseq, x);
 fprintf( yyfp, "file0:235_18_235_18_state-%d pa:atProgramPoint file0:239_1_241_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:239_1_241_1-%d pa:afterStatement file0:239_1_241_1. \n", ppseq);
 fprintf( yyfp, "file0:239_1_241_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;


del = sum = 1.0 / (ap = a);
 fprintf( yyfp, "file0:237_1_237_14 pa:hasState file0:237_1_237_14_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:237_1_237_14_state-%d pa:hasValue %f .\n", yyseq, del);
 fprintf( yyfp, "file0:237_1_237_14_state-%d pa:atProgramPoint file0:243_1_243_27-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:237_1_237_19 pa:hasState file0:237_1_237_19_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:237_1_237_19_state-%d pa:hasValue %f .\n", yyseq, sum);
 fprintf( yyfp, "file0:237_1_237_19_state-%d pa:atProgramPoint file0:243_1_243_27-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:237_1_237_9 pa:hasState file0:237_1_237_9_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:237_1_237_9_state-%d pa:hasValue %f .\n", yyseq, ap);
 fprintf( yyfp, "file0:237_1_237_9_state-%d pa:atProgramPoint file0:243_1_243_27-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:235_8_235_8 pa:hasState file0:235_8_235_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:235_8_235_8_state-%d pa:hasValue %f .\n", yyseq, a);
 fprintf( yyfp, "file0:235_8_235_8_state-%d pa:atProgramPoint file0:243_1_243_27-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:243_1_243_27-%d pa:afterStatement file0:243_1_243_27. \n", ppseq);
 fprintf( yyfp, "file0:243_1_243_27-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

for ( n = 1; n <= ITMAX; ++n ){
 fprintf( yyfp, "file0:238_1_238_5 pa:hasState file0:238_1_238_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:238_1_238_5_state-%d pa:hasValue %d .\n", yyseq, n);
 fprintf( yyfp, "file0:238_1_238_5_state-%d pa:atProgramPoint file0:244_26_244_28-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:244_26_244_28-%d pa:afterStatement file0:244_26_244_28. \n", ppseq);
 fprintf( yyfp, "file0:244_26_244_28-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;


sum += del *= x / ++ap;
 fprintf( yyfp, "file0:237_1_237_9 pa:hasState file0:237_1_237_9_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:237_1_237_9_state-%d pa:hasValue %f .\n", yyseq, ap);
 fprintf( yyfp, "file0:237_1_237_9_state-%d pa:atProgramPoint file0:246_1_246_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:235_18_235_18 pa:hasState file0:235_18_235_18_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:235_18_235_18_state-%d pa:hasValue %f .\n", yyseq, x);
 fprintf( yyfp, "file0:235_18_235_18_state-%d pa:atProgramPoint file0:246_1_246_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:237_1_237_14 pa:hasState file0:237_1_237_14_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:237_1_237_14_state-%d pa:hasValue %f .\n", yyseq, del);
 fprintf( yyfp, "file0:237_1_237_14_state-%d pa:atProgramPoint file0:246_1_246_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:237_1_237_19 pa:hasState file0:237_1_237_19_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:237_1_237_19_state-%d pa:hasValue %f .\n", yyseq, sum);
 fprintf( yyfp, "file0:237_1_237_19_state-%d pa:atProgramPoint file0:246_1_246_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:246_1_246_23-%d pa:afterStatement file0:246_1_246_23. \n", ppseq);
 fprintf( yyfp, "file0:246_1_246_23-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

if ( Abs( del ) < Abs( sum ) * EPS ){
return sum * exp( -x + a * log( x ) - LGamma( a ) );
}
 fprintf( yyfp, "file0:235_8_235_8 pa:hasState file0:235_8_235_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:235_8_235_8_state-%d pa:hasValue %f .\n", yyseq, a);
 fprintf( yyfp, "file0:235_8_235_8_state-%d pa:atProgramPoint file0:247_1_249_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:235_18_235_18 pa:hasState file0:235_18_235_18_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:235_18_235_18_state-%d pa:hasValue %f .\n", yyseq, x);
 fprintf( yyfp, "file0:235_18_235_18_state-%d pa:atProgramPoint file0:247_1_249_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:237_1_237_19 pa:hasState file0:237_1_237_19_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:237_1_237_19_state-%d pa:hasValue %f .\n", yyseq, sum);
 fprintf( yyfp, "file0:237_1_237_19_state-%d pa:atProgramPoint file0:247_1_249_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:237_1_237_14 pa:hasState file0:237_1_237_14_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:237_1_237_14_state-%d pa:hasValue %f .\n", yyseq, del);
 fprintf( yyfp, "file0:237_1_237_14_state-%d pa:atProgramPoint file0:247_1_249_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:247_1_249_1-%d pa:afterStatement file0:247_1_249_1. \n", ppseq);
 fprintf( yyfp, "file0:247_1_249_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;


}
/*NOTREACHED*/
}
static double
gcf(
double a, double x)

{
int n;

double gold = 0.0, fac = 1.0, b1 = 1.0,
b0 = 0.0, a0 = 1.0, a1 = x;
 fprintf( yyfp, "file0:256_18_256_18 pa:hasState file0:256_18_256_18_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:256_18_256_18_state-%d pa:hasValue %f .\n", yyseq, x);
 fprintf( yyfp, "file0:256_18_256_18_state-%d pa:atProgramPoint file0:259_1_260_22-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_260_22-%d pa:afterStatement file0:259_1_260_22. \n", ppseq);
 fprintf( yyfp, "file0:259_1_260_22-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

for ( n = 1; n <= ITMAX; ++n ){
 fprintf( yyfp, "file0:258_1_258_5 pa:hasState file0:258_1_258_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:258_1_258_5_state-%d pa:hasValue %d .\n", yyseq, n);
 fprintf( yyfp, "file0:258_1_258_5_state-%d pa:atProgramPoint file0:261_14_261_19-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:261_14_261_19-%d pa:afterStatement file0:261_14_261_19. \n", ppseq);
 fprintf( yyfp, "file0:261_14_261_19-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;


double anf;

double an = (double)n;
 fprintf( yyfp, "file0:258_1_258_5 pa:hasState file0:258_1_258_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:258_1_258_5_state-%d pa:hasValue %d .\n", yyseq, n);
 fprintf( yyfp, "file0:258_1_258_5_state-%d pa:atProgramPoint file0:264_1_264_9-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:264_1_264_9-%d pa:afterStatement file0:264_1_264_9. \n", ppseq);
 fprintf( yyfp, "file0:264_1_264_9-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

double ana = an - a;
 fprintf( yyfp, "file0:264_1_264_9 pa:hasState file0:264_1_264_9_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:264_1_264_9_state-%d pa:hasValue %f .\n", yyseq, an);
 fprintf( yyfp, "file0:264_1_264_9_state-%d pa:atProgramPoint file0:265_1_265_10-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:256_8_256_8 pa:hasState file0:256_8_256_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:256_8_256_8_state-%d pa:hasValue %f .\n", yyseq, a);
 fprintf( yyfp, "file0:256_8_256_8_state-%d pa:atProgramPoint file0:265_1_265_10-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:265_1_265_10-%d pa:afterStatement file0:265_1_265_10. \n", ppseq);
 fprintf( yyfp, "file0:265_1_265_10-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

a0 = (a1 + a0 * ana) * fac;
 fprintf( yyfp, "file0:259_1_260_12 pa:hasState file0:259_1_260_12_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_260_12_state-%d pa:hasValue %f .\n", yyseq, a0);
 fprintf( yyfp, "file0:259_1_260_12_state-%d pa:atProgramPoint file0:266_1_266_27-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_260_22 pa:hasState file0:259_1_260_22_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_260_22_state-%d pa:hasValue %f .\n", yyseq, a1);
 fprintf( yyfp, "file0:259_1_260_22_state-%d pa:atProgramPoint file0:266_1_266_27-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:265_1_265_10 pa:hasState file0:265_1_265_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:265_1_265_10_state-%d pa:hasValue %f .\n", yyseq, ana);
 fprintf( yyfp, "file0:265_1_265_10_state-%d pa:atProgramPoint file0:266_1_266_27-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_259_22 pa:hasState file0:259_1_259_22_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_259_22_state-%d pa:hasValue %f .\n", yyseq, fac);
 fprintf( yyfp, "file0:259_1_259_22_state-%d pa:atProgramPoint file0:266_1_266_27-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:266_1_266_27-%d pa:afterStatement file0:266_1_266_27. \n", ppseq);
 fprintf( yyfp, "file0:266_1_266_27-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

b0 = (b1 + b0 * ana) * fac;
 fprintf( yyfp, "file0:259_1_260_2 pa:hasState file0:259_1_260_2_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_260_2_state-%d pa:hasValue %f .\n", yyseq, b0);
 fprintf( yyfp, "file0:259_1_260_2_state-%d pa:atProgramPoint file0:267_1_267_27-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:265_1_265_10 pa:hasState file0:265_1_265_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:265_1_265_10_state-%d pa:hasValue %f .\n", yyseq, ana);
 fprintf( yyfp, "file0:265_1_265_10_state-%d pa:atProgramPoint file0:267_1_267_27-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_259_32 pa:hasState file0:259_1_259_32_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_259_32_state-%d pa:hasValue %f .\n", yyseq, b1);
 fprintf( yyfp, "file0:259_1_259_32_state-%d pa:atProgramPoint file0:267_1_267_27-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_259_22 pa:hasState file0:259_1_259_22_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_259_22_state-%d pa:hasValue %f .\n", yyseq, fac);
 fprintf( yyfp, "file0:259_1_259_22_state-%d pa:atProgramPoint file0:267_1_267_27-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:267_1_267_27-%d pa:afterStatement file0:267_1_267_27. \n", ppseq);
 fprintf( yyfp, "file0:267_1_267_27-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

anf = an * fac;
 fprintf( yyfp, "file0:259_1_259_22 pa:hasState file0:259_1_259_22_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_259_22_state-%d pa:hasValue %f .\n", yyseq, fac);
 fprintf( yyfp, "file0:259_1_259_22_state-%d pa:atProgramPoint file0:268_1_268_15-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:263_1_263_10 pa:hasState file0:263_1_263_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:263_1_263_10_state-%d pa:hasValue %f .\n", yyseq, anf);
 fprintf( yyfp, "file0:263_1_263_10_state-%d pa:atProgramPoint file0:268_1_268_15-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:264_1_264_9 pa:hasState file0:264_1_264_9_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:264_1_264_9_state-%d pa:hasValue %f .\n", yyseq, an);
 fprintf( yyfp, "file0:264_1_264_9_state-%d pa:atProgramPoint file0:268_1_268_15-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:268_1_268_15-%d pa:afterStatement file0:268_1_268_15. \n", ppseq);
 fprintf( yyfp, "file0:268_1_268_15-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

b1 = x * b0 + anf * b1;
 fprintf( yyfp, "file0:259_1_259_32 pa:hasState file0:259_1_259_32_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_259_32_state-%d pa:hasValue %f .\n", yyseq, b1);
 fprintf( yyfp, "file0:259_1_259_32_state-%d pa:atProgramPoint file0:269_1_269_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:256_18_256_18 pa:hasState file0:256_18_256_18_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:256_18_256_18_state-%d pa:hasValue %f .\n", yyseq, x);
 fprintf( yyfp, "file0:256_18_256_18_state-%d pa:atProgramPoint file0:269_1_269_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_260_2 pa:hasState file0:259_1_260_2_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_260_2_state-%d pa:hasValue %f .\n", yyseq, b0);
 fprintf( yyfp, "file0:259_1_260_2_state-%d pa:atProgramPoint file0:269_1_269_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:263_1_263_10 pa:hasState file0:263_1_263_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:263_1_263_10_state-%d pa:hasValue %f .\n", yyseq, anf);
 fprintf( yyfp, "file0:263_1_263_10_state-%d pa:atProgramPoint file0:269_1_269_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:269_1_269_23-%d pa:afterStatement file0:269_1_269_23. \n", ppseq);
 fprintf( yyfp, "file0:269_1_269_23-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

a1 = x * a0 + anf * a1;
 fprintf( yyfp, "file0:259_1_260_22 pa:hasState file0:259_1_260_22_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_260_22_state-%d pa:hasValue %f .\n", yyseq, a1);
 fprintf( yyfp, "file0:259_1_260_22_state-%d pa:atProgramPoint file0:270_1_270_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_260_12 pa:hasState file0:259_1_260_12_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_260_12_state-%d pa:hasValue %f .\n", yyseq, a0);
 fprintf( yyfp, "file0:259_1_260_12_state-%d pa:atProgramPoint file0:270_1_270_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:256_18_256_18 pa:hasState file0:256_18_256_18_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:256_18_256_18_state-%d pa:hasValue %f .\n", yyseq, x);
 fprintf( yyfp, "file0:256_18_256_18_state-%d pa:atProgramPoint file0:270_1_270_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:263_1_263_10 pa:hasState file0:263_1_263_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:263_1_263_10_state-%d pa:hasValue %f .\n", yyseq, anf);
 fprintf( yyfp, "file0:263_1_263_10_state-%d pa:atProgramPoint file0:270_1_270_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:270_1_270_23-%d pa:afterStatement file0:270_1_270_23. \n", ppseq);
 fprintf( yyfp, "file0:270_1_270_23-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

if ( a1 != 0.0 ){ /* renormalize */
double g = b1 * (fac = 1.0 / a1);
 fprintf( yyfp, "file0:259_1_259_22 pa:hasState file0:259_1_259_22_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_259_22_state-%d pa:hasValue %f .\n", yyseq, fac);
 fprintf( yyfp, "file0:259_1_259_22_state-%d pa:atProgramPoint file0:272_1_272_8-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_259_32 pa:hasState file0:259_1_259_32_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_259_32_state-%d pa:hasValue %f .\n", yyseq, b1);
 fprintf( yyfp, "file0:259_1_259_32_state-%d pa:atProgramPoint file0:272_1_272_8-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_260_22 pa:hasState file0:259_1_260_22_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_260_22_state-%d pa:hasValue %f .\n", yyseq, a1);
 fprintf( yyfp, "file0:259_1_260_22_state-%d pa:atProgramPoint file0:272_1_272_8-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:272_1_272_8-%d pa:afterStatement file0:272_1_272_8. \n", ppseq);
 fprintf( yyfp, "file0:272_1_272_8-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

gold = g - gold;
 fprintf( yyfp, "file0:272_1_272_8 pa:hasState file0:272_1_272_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:272_1_272_8_state-%d pa:hasValue %f .\n", yyseq, g);
 fprintf( yyfp, "file0:272_1_272_8_state-%d pa:atProgramPoint file0:273_1_273_16-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_259_11 pa:hasState file0:259_1_259_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_259_11_state-%d pa:hasValue %f .\n", yyseq, gold);
 fprintf( yyfp, "file0:259_1_259_11_state-%d pa:atProgramPoint file0:273_1_273_16-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:273_1_273_16-%d pa:afterStatement file0:273_1_273_16. \n", ppseq);
 fprintf( yyfp, "file0:273_1_273_16-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

if ( Abs( gold ) < EPS * Abs( g ) ){
return exp( -x + a * log( x ) - LGamma( a ) ) * g;
}
 fprintf( yyfp, "file0:256_18_256_18 pa:hasState file0:256_18_256_18_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:256_18_256_18_state-%d pa:hasValue %f .\n", yyseq, x);
 fprintf( yyfp, "file0:256_18_256_18_state-%d pa:atProgramPoint file0:274_1_276_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_259_11 pa:hasState file0:259_1_259_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_259_11_state-%d pa:hasValue %f .\n", yyseq, gold);
 fprintf( yyfp, "file0:259_1_259_11_state-%d pa:atProgramPoint file0:274_1_276_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:272_1_272_8 pa:hasState file0:272_1_272_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:272_1_272_8_state-%d pa:hasValue %f .\n", yyseq, g);
 fprintf( yyfp, "file0:272_1_272_8_state-%d pa:atProgramPoint file0:274_1_276_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:256_8_256_8 pa:hasState file0:256_8_256_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:256_8_256_8_state-%d pa:hasValue %f .\n", yyseq, a);
 fprintf( yyfp, "file0:256_8_256_8_state-%d pa:atProgramPoint file0:274_1_276_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:274_1_276_1-%d pa:afterStatement file0:274_1_276_1. \n", ppseq);
 fprintf( yyfp, "file0:274_1_276_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;


gold = g;
 fprintf( yyfp, "file0:259_1_259_11 pa:hasState file0:259_1_259_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_259_11_state-%d pa:hasValue %f .\n", yyseq, gold);
 fprintf( yyfp, "file0:259_1_259_11_state-%d pa:atProgramPoint file0:278_1_278_9-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:272_1_272_8 pa:hasState file0:272_1_272_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:272_1_272_8_state-%d pa:hasValue %f .\n", yyseq, g);
 fprintf( yyfp, "file0:272_1_272_8_state-%d pa:atProgramPoint file0:278_1_278_9-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:278_1_278_9-%d pa:afterStatement file0:278_1_278_9. \n", ppseq);
 fprintf( yyfp, "file0:278_1_278_9-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

}
 fprintf( yyfp, "file0:256_18_256_18 pa:hasState file0:256_18_256_18_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:256_18_256_18_state-%d pa:hasValue %f .\n", yyseq, x);
 fprintf( yyfp, "file0:256_18_256_18_state-%d pa:atProgramPoint file0:271_1_279_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_259_22 pa:hasState file0:259_1_259_22_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_259_22_state-%d pa:hasValue %f .\n", yyseq, fac);
 fprintf( yyfp, "file0:259_1_259_22_state-%d pa:atProgramPoint file0:271_1_279_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_259_11 pa:hasState file0:259_1_259_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_259_11_state-%d pa:hasValue %f .\n", yyseq, gold);
 fprintf( yyfp, "file0:259_1_259_11_state-%d pa:atProgramPoint file0:271_1_279_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:256_8_256_8 pa:hasState file0:256_8_256_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:256_8_256_8_state-%d pa:hasValue %f .\n", yyseq, a);
 fprintf( yyfp, "file0:256_8_256_8_state-%d pa:atProgramPoint file0:271_1_279_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_259_32 pa:hasState file0:259_1_259_32_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_259_32_state-%d pa:hasValue %f .\n", yyseq, b1);
 fprintf( yyfp, "file0:259_1_259_32_state-%d pa:atProgramPoint file0:271_1_279_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:259_1_260_22 pa:hasState file0:259_1_260_22_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:259_1_260_22_state-%d pa:hasValue %f .\n", yyseq, a1);
 fprintf( yyfp, "file0:259_1_260_22_state-%d pa:atProgramPoint file0:271_1_279_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:271_1_279_1-%d pa:afterStatement file0:271_1_279_1. \n", ppseq);
 fprintf( yyfp, "file0:271_1_279_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

}
/*NOTREACHED*/
}
double
QGamma( 
double a, double x)

{
return x < a + 1.0 ? 1.0 - gser( a, x ) : gcf( a, x );
}
double
QChiSq( 
double chisq,

int df)

{
return QGamma( (double)df / 2.0, chisq / 2.0 );
}
/*
InfoTbl -- Kullback's information measure for a 2-way contingency table
last edit: 88/09/19 D A Gwyn
SCCS ID: @(#)info.c 1.1 (edited for publication)
Special return values:
-1.0 entire table consisted of 0 entries
-2.0 invalid table entry (frequency less than 0)
-3.0 invalid table dimensions (r or c less than 2)
-4.0 unable to allocate enough working storage
*/
#include <math.h> /* for log() */
#if __STDC__
#include <stdlib.h> /* malloc, free */
//#include "std.h"
//#else
//#include "std.h"
extern pointer malloc();
extern void free();
#endif
#ifndef NULL
#define NULL 0
#endif
#define x(i,j) f[(i)*c+(j)] /* convenient way to access freqs */
double
InfoTbl( 
int r, /* # rows in table */

int c, /* # columns in table */

const long *f, /* -> r*c frequency tallies */

int *pdf) /* -> return # d.f. for chi-square */

{
int i; /* row index */

int j; /* column index */

double N; /* (double)n */

double info; /* accumulates information measure */

double *xi; /* row sums */

double *xj; /* col sums */

int rdf = r - 1; /* row degrees of freedom */
 fprintf( yyfp, "file0:321_5_321_5 pa:hasState file0:321_5_321_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:321_5_321_5_state-%d pa:hasValue %d .\n", yyseq, r);
 fprintf( yyfp, "file0:321_5_321_5_state-%d pa:atProgramPoint file0:332_1_332_7-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:332_1_332_7-%d pa:afterStatement file0:332_1_332_7. \n", ppseq);
 fprintf( yyfp, "file0:332_1_332_7-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

int cdf = c - 1; /* column degrees of freedom */
 fprintf( yyfp, "file0:322_5_322_5 pa:hasState file0:322_5_322_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:atProgramPoint file0:333_1_333_7-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:333_1_333_7-%d pa:afterStatement file0:333_1_333_7. \n", ppseq);
 fprintf( yyfp, "file0:333_1_333_7-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

if ( rdf <= 0 || cdf <= 0 ){
info = -3.0;
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:335_1_335_12-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:335_1_335_12-%d pa:afterStatement file0:335_1_335_12. \n", ppseq);
 fprintf( yyfp, "file0:335_1_335_12-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

goto ret3;
}
 fprintf( yyfp, "file0:332_1_332_7 pa:hasState file0:332_1_332_7_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:332_1_332_7_state-%d pa:hasValue %d .\n", yyseq, rdf);
 fprintf( yyfp, "file0:332_1_332_7_state-%d pa:atProgramPoint file0:334_1_337_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:333_1_333_7 pa:hasState file0:333_1_333_7_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:333_1_333_7_state-%d pa:hasValue %d .\n", yyseq, cdf);
 fprintf( yyfp, "file0:333_1_333_7_state-%d pa:atProgramPoint file0:334_1_337_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:334_1_337_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:334_1_337_1-%d pa:afterStatement file0:334_1_337_1. \n", ppseq);
 fprintf( yyfp, "file0:334_1_337_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

*pdf = rdf * cdf; /* total degrees of freedom */
 fprintf( yyfp, "file0:333_1_333_7 pa:hasState file0:333_1_333_7_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:333_1_333_7_state-%d pa:hasValue %d .\n", yyseq, cdf);
 fprintf( yyfp, "file0:333_1_333_7_state-%d pa:atProgramPoint file0:338_1_338_17-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:332_1_332_7 pa:hasState file0:332_1_332_7_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:332_1_332_7_state-%d pa:hasValue %d .\n", yyseq, rdf);
 fprintf( yyfp, "file0:332_1_332_7_state-%d pa:atProgramPoint file0:338_1_338_17-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:324_6_324_8 pa:hasState file0:324_6_324_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:324_6_324_8_state-%d pa:hasValue %d .\n", yyseq, pdf);
 fprintf( yyfp, "file0:324_6_324_8_state-%d pa:atProgramPoint file0:338_1_338_17-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:338_1_338_17-%d pa:afterStatement file0:338_1_338_17. \n", ppseq);
 fprintf( yyfp, "file0:338_1_338_17-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

if ( (xi = (double *)malloc( r * sizeof(double) )) == NULL ){

info = -4.0;
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:341_1_341_12-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:341_1_341_12-%d pa:afterStatement file0:341_1_341_12. \n", ppseq);
 fprintf( yyfp, "file0:341_1_341_12-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

goto ret3;
}
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:339_1_343_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:330_1_330_10 pa:hasState file0:330_1_330_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:330_1_330_10_state-%d pa:hasValue %f .\n", yyseq, xi);
 fprintf( yyfp, "file0:330_1_330_10_state-%d pa:atProgramPoint file0:339_1_343_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:321_5_321_5 pa:hasState file0:321_5_321_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:321_5_321_5_state-%d pa:hasValue %d .\n", yyseq, r);
 fprintf( yyfp, "file0:321_5_321_5_state-%d pa:atProgramPoint file0:339_1_343_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:339_1_343_1-%d pa:afterStatement file0:339_1_343_1. \n", ppseq);
 fprintf( yyfp, "file0:339_1_343_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

if ( (xj = (double *)malloc( c * sizeof(double) )) == NULL ){

info = -4.0;
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:346_1_346_12-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:346_1_346_12-%d pa:afterStatement file0:346_1_346_12. \n", ppseq);
 fprintf( yyfp, "file0:346_1_346_12-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

goto ret2;
}
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:344_1_348_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:322_5_322_5 pa:hasState file0:322_5_322_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:atProgramPoint file0:344_1_348_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:331_1_331_10 pa:hasState file0:331_1_331_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:331_1_331_10_state-%d pa:hasValue %f .\n", yyseq, xj);
 fprintf( yyfp, "file0:331_1_331_10_state-%d pa:atProgramPoint file0:344_1_348_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:344_1_348_1-%d pa:afterStatement file0:344_1_348_1. \n", ppseq);
 fprintf( yyfp, "file0:344_1_348_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

/* compute row sums and total */
N = 0.0;
 fprintf( yyfp, "file0:328_1_328_8 pa:hasState file0:328_1_328_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:328_1_328_8_state-%d pa:hasValue %f .\n", yyseq, N);
 fprintf( yyfp, "file0:328_1_328_8_state-%d pa:atProgramPoint file0:350_1_350_8-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:350_1_350_8-%d pa:afterStatement file0:350_1_350_8. \n", ppseq);
 fprintf( yyfp, "file0:350_1_350_8-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

for ( i = 0; i < r; ++i ){
 fprintf( yyfp, "file0:326_1_326_5 pa:hasState file0:326_1_326_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:hasValue %d .\n", yyseq, i);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:atProgramPoint file0:351_21_351_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:321_5_321_5 pa:hasState file0:321_5_321_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:321_5_321_5_state-%d pa:hasValue %d .\n", yyseq, r);
 fprintf( yyfp, "file0:321_5_321_5_state-%d pa:atProgramPoint file0:351_21_351_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:351_21_351_23-%d pa:afterStatement file0:351_21_351_23. \n", ppseq);
 fprintf( yyfp, "file0:351_21_351_23-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;


double sum = 0.0; /* accumulator */

for ( j = 0; j < c; ++j ){
 fprintf( yyfp, "file0:327_1_327_5 pa:hasState file0:327_1_327_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:hasValue %d .\n", yyseq, j);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:atProgramPoint file0:354_21_354_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:322_5_322_5 pa:hasState file0:322_5_322_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:atProgramPoint file0:354_21_354_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:354_21_354_23-%d pa:afterStatement file0:354_21_354_23. \n", ppseq);
 fprintf( yyfp, "file0:354_21_354_23-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;


long k = f[(i)*c+(j)];
 fprintf( yyfp, "file0:327_1_327_5 pa:hasState file0:327_1_327_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:hasValue %d .\n", yyseq, j);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:atProgramPoint file0:356_1_356_6-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:323_13_323_13 pa:hasState file0:323_13_323_13_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:323_13_323_13_state-%d pa:hasValue %li .\n", yyseq, f);
 fprintf( yyfp, "file0:323_13_323_13_state-%d pa:atProgramPoint file0:356_1_356_6-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:322_5_322_5 pa:hasState file0:322_5_322_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:atProgramPoint file0:356_1_356_6-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "f[(i)*c+(j)]_state-%d pa:atProgramPoint file0:356_1_356_6-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:326_1_326_5 pa:hasState file0:326_1_326_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:hasValue %d .\n", yyseq, i);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:atProgramPoint file0:356_1_356_6-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:356_1_356_6-%d pa:afterStatement file0:356_1_356_6. \n", ppseq);
 fprintf( yyfp, "file0:356_1_356_6-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

if ( k < 0L ){

info = -2.0;
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:359_1_359_12-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:359_1_359_12-%d pa:afterStatement file0:359_1_359_12. \n", ppseq);
 fprintf( yyfp, "file0:359_1_359_12-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

goto ret1;
}
 fprintf( yyfp, "file0:356_1_356_6 pa:hasState file0:356_1_356_6_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:356_1_356_6_state-%d pa:hasValue %li .\n", yyseq, k);
 fprintf( yyfp, "file0:356_1_356_6_state-%d pa:atProgramPoint file0:357_1_361_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:357_1_361_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:357_1_361_1-%d pa:afterStatement file0:357_1_361_1. \n", ppseq);
 fprintf( yyfp, "file0:357_1_361_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

sum += (double)k;
 fprintf( yyfp, "file0:353_1_353_10 pa:hasState file0:353_1_353_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:353_1_353_10_state-%d pa:hasValue %f .\n", yyseq, sum);
 fprintf( yyfp, "file0:353_1_353_10_state-%d pa:atProgramPoint file0:362_1_362_17-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:356_1_356_6 pa:hasState file0:356_1_356_6_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:356_1_356_6_state-%d pa:hasValue %li .\n", yyseq, k);
 fprintf( yyfp, "file0:356_1_356_6_state-%d pa:atProgramPoint file0:362_1_362_17-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:362_1_362_17-%d pa:afterStatement file0:362_1_362_17. \n", ppseq);
 fprintf( yyfp, "file0:362_1_362_17-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

}
N += xi[i] = sum;
 fprintf( yyfp, "file0:330_1_330_10 pa:hasState file0:330_1_330_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:330_1_330_10_state-%d pa:hasValue %f .\n", yyseq, xi);
 fprintf( yyfp, "file0:330_1_330_10_state-%d pa:atProgramPoint file0:364_1_364_17-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:328_1_328_8 pa:hasState file0:328_1_328_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:328_1_328_8_state-%d pa:hasValue %f .\n", yyseq, N);
 fprintf( yyfp, "file0:328_1_328_8_state-%d pa:atProgramPoint file0:364_1_364_17-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:326_1_326_5 pa:hasState file0:326_1_326_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:hasValue %d .\n", yyseq, i);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:atProgramPoint file0:364_1_364_17-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "xi[i]_state-%d pa:atProgramPoint file0:364_1_364_17-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:353_1_353_10 pa:hasState file0:353_1_353_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:353_1_353_10_state-%d pa:hasValue %f .\n", yyseq, sum);
 fprintf( yyfp, "file0:353_1_353_10_state-%d pa:atProgramPoint file0:364_1_364_17-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:364_1_364_17-%d pa:afterStatement file0:364_1_364_17. \n", ppseq);
 fprintf( yyfp, "file0:364_1_364_17-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

}
if ( N <= 0.0 ){

info = -1.0;
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:368_1_368_12-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:368_1_368_12-%d pa:afterStatement file0:368_1_368_12. \n", ppseq);
 fprintf( yyfp, "file0:368_1_368_12-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

goto ret1;
}
 fprintf( yyfp, "file0:328_1_328_8 pa:hasState file0:328_1_328_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:328_1_328_8_state-%d pa:hasValue %f .\n", yyseq, N);
 fprintf( yyfp, "file0:328_1_328_8_state-%d pa:atProgramPoint file0:366_1_370_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:366_1_370_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:366_1_370_1-%d pa:afterStatement file0:366_1_370_1. \n", ppseq);
 fprintf( yyfp, "file0:366_1_370_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

/* compute column sums */
for ( j = 0; j < c; ++j ){
 fprintf( yyfp, "file0:327_1_327_5 pa:hasState file0:327_1_327_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:hasValue %d .\n", yyseq, j);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:atProgramPoint file0:372_21_372_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:322_5_322_5 pa:hasState file0:322_5_322_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:atProgramPoint file0:372_21_372_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:372_21_372_23-%d pa:afterStatement file0:372_21_372_23. \n", ppseq);
 fprintf( yyfp, "file0:372_21_372_23-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;


double sum = 0.0; /* accumulator */

for ( i = 0; i < r; ++i ){
 fprintf( yyfp, "file0:326_1_326_5 pa:hasState file0:326_1_326_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:hasValue %d .\n", yyseq, i);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:atProgramPoint file0:375_14_375_18-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:321_5_321_5 pa:hasState file0:321_5_321_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:321_5_321_5_state-%d pa:hasValue %d .\n", yyseq, r);
 fprintf( yyfp, "file0:321_5_321_5_state-%d pa:atProgramPoint file0:375_14_375_18-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:375_14_375_18-%d pa:afterStatement file0:375_14_375_18. \n", ppseq);
 fprintf( yyfp, "file0:375_14_375_18-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

sum += (double)f[(i)*c+(j)];
 fprintf( yyfp, "f[(i)*c+(j)]_state-%d pa:atProgramPoint file0:376_1_376_28-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:323_13_323_13 pa:hasState file0:323_13_323_13_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:323_13_323_13_state-%d pa:hasValue %li .\n", yyseq, f);
 fprintf( yyfp, "file0:323_13_323_13_state-%d pa:atProgramPoint file0:376_1_376_28-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:374_1_374_10 pa:hasState file0:374_1_374_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:374_1_374_10_state-%d pa:hasValue %f .\n", yyseq, sum);
 fprintf( yyfp, "file0:374_1_374_10_state-%d pa:atProgramPoint file0:376_1_376_28-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:322_5_322_5 pa:hasState file0:322_5_322_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:atProgramPoint file0:376_1_376_28-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:327_1_327_5 pa:hasState file0:327_1_327_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:hasValue %d .\n", yyseq, j);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:atProgramPoint file0:376_1_376_28-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:326_1_326_5 pa:hasState file0:326_1_326_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:hasValue %d .\n", yyseq, i);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:atProgramPoint file0:376_1_376_28-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:376_1_376_28-%d pa:afterStatement file0:376_1_376_28. \n", ppseq);
 fprintf( yyfp, "file0:376_1_376_28-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

}

xj[j] = sum;
 fprintf( yyfp, "file0:327_1_327_5 pa:hasState file0:327_1_327_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:hasValue %d .\n", yyseq, j);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:atProgramPoint file0:379_1_379_12-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "xj[j]_state-%d pa:atProgramPoint file0:379_1_379_12-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:331_1_331_10 pa:hasState file0:331_1_331_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:331_1_331_10_state-%d pa:hasValue %f .\n", yyseq, xj);
 fprintf( yyfp, "file0:331_1_331_10_state-%d pa:atProgramPoint file0:379_1_379_12-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:374_1_374_10 pa:hasState file0:374_1_374_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:374_1_374_10_state-%d pa:hasValue %f .\n", yyseq, sum);
 fprintf( yyfp, "file0:374_1_374_10_state-%d pa:atProgramPoint file0:379_1_379_12-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:379_1_379_12-%d pa:afterStatement file0:379_1_379_12. \n", ppseq);
 fprintf( yyfp, "file0:379_1_379_12-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

}
/* compute information measure (four parts) */
info = N * log( N ); /* part 1 */
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:382_1_382_20-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:328_1_328_8 pa:hasState file0:328_1_328_8_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:328_1_328_8_state-%d pa:hasValue %f .\n", yyseq, N);
 fprintf( yyfp, "file0:328_1_328_8_state-%d pa:atProgramPoint file0:382_1_382_20-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:382_1_382_20-%d pa:afterStatement file0:382_1_382_20. \n", ppseq);
 fprintf( yyfp, "file0:382_1_382_20-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

for ( i = 0; i < r; ++i ){
 fprintf( yyfp, "file0:326_1_326_5 pa:hasState file0:326_1_326_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:hasValue %d .\n", yyseq, i);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:atProgramPoint file0:383_21_383_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:321_5_321_5 pa:hasState file0:321_5_321_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:321_5_321_5_state-%d pa:hasValue %d .\n", yyseq, r);
 fprintf( yyfp, "file0:321_5_321_5_state-%d pa:atProgramPoint file0:383_21_383_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:383_21_383_23-%d pa:afterStatement file0:383_21_383_23. \n", ppseq);
 fprintf( yyfp, "file0:383_21_383_23-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;


double pi = xi[i]; /* row sum */
 fprintf( yyfp, "file0:326_1_326_5 pa:hasState file0:326_1_326_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:hasValue %d .\n", yyseq, i);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:atProgramPoint file0:385_1_385_9-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:330_1_330_10 pa:hasState file0:330_1_330_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:330_1_330_10_state-%d pa:hasValue %f .\n", yyseq, xi);
 fprintf( yyfp, "file0:330_1_330_10_state-%d pa:atProgramPoint file0:385_1_385_9-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "xi[i]_state-%d pa:atProgramPoint file0:385_1_385_9-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:385_1_385_9-%d pa:afterStatement file0:385_1_385_9. \n", ppseq);
 fprintf( yyfp, "file0:385_1_385_9-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

if ( pi > 0.0 ){
info -= pi * log( pi );
 fprintf( yyfp, "file0:385_1_385_9 pa:hasState file0:385_1_385_9_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:385_1_385_9_state-%d pa:hasValue %f .\n", yyseq, pi);
 fprintf( yyfp, "file0:385_1_385_9_state-%d pa:atProgramPoint file0:387_1_387_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:387_1_387_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:387_1_387_23-%d pa:afterStatement file0:387_1_387_23. \n", ppseq);
 fprintf( yyfp, "file0:387_1_387_23-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

}
 fprintf( yyfp, "file0:385_1_385_9 pa:hasState file0:385_1_385_9_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:385_1_385_9_state-%d pa:hasValue %f .\n", yyseq, pi);
 fprintf( yyfp, "file0:385_1_385_9_state-%d pa:atProgramPoint file0:386_1_388_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:386_1_388_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:386_1_388_1-%d pa:afterStatement file0:386_1_388_1. \n", ppseq);
 fprintf( yyfp, "file0:386_1_388_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

/* part 2 */
for ( j = 0; j < c; ++j ){
 fprintf( yyfp, "file0:327_1_327_5 pa:hasState file0:327_1_327_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:hasValue %d .\n", yyseq, j);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:atProgramPoint file0:390_21_390_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:322_5_322_5 pa:hasState file0:322_5_322_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:atProgramPoint file0:390_21_390_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:390_21_390_23-%d pa:afterStatement file0:390_21_390_23. \n", ppseq);
 fprintf( yyfp, "file0:390_21_390_23-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;


double pij = (double)f[(i)*c+(j)];
 fprintf( yyfp, "file0:322_5_322_5 pa:hasState file0:322_5_322_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:atProgramPoint file0:392_1_392_10-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "f[(i)*c+(j)]_state-%d pa:atProgramPoint file0:392_1_392_10-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:323_13_323_13 pa:hasState file0:323_13_323_13_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:323_13_323_13_state-%d pa:hasValue %li .\n", yyseq, f);
 fprintf( yyfp, "file0:323_13_323_13_state-%d pa:atProgramPoint file0:392_1_392_10-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:327_1_327_5 pa:hasState file0:327_1_327_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:hasValue %d .\n", yyseq, j);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:atProgramPoint file0:392_1_392_10-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:326_1_326_5 pa:hasState file0:326_1_326_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:hasValue %d .\n", yyseq, i);
 fprintf( yyfp, "file0:326_1_326_5_state-%d pa:atProgramPoint file0:392_1_392_10-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:392_1_392_10-%d pa:afterStatement file0:392_1_392_10. \n", ppseq);
 fprintf( yyfp, "file0:392_1_392_10-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

if ( pij > 0.0 ){
info += pij * log( pij );
 fprintf( yyfp, "file0:392_1_392_10 pa:hasState file0:392_1_392_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:392_1_392_10_state-%d pa:hasValue %f .\n", yyseq, pij);
 fprintf( yyfp, "file0:392_1_392_10_state-%d pa:atProgramPoint file0:394_1_394_25-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:394_1_394_25-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:394_1_394_25-%d pa:afterStatement file0:394_1_394_25. \n", ppseq);
 fprintf( yyfp, "file0:394_1_394_25-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

}
 fprintf( yyfp, "file0:392_1_392_10 pa:hasState file0:392_1_392_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:392_1_392_10_state-%d pa:hasValue %f .\n", yyseq, pij);
 fprintf( yyfp, "file0:392_1_392_10_state-%d pa:atProgramPoint file0:393_1_395_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:393_1_395_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:393_1_395_1-%d pa:afterStatement file0:393_1_395_1. \n", ppseq);
 fprintf( yyfp, "file0:393_1_395_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

/* part 3 */
}
}
for ( j = 0; j < c; ++j ){
 fprintf( yyfp, "file0:327_1_327_5 pa:hasState file0:327_1_327_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:hasValue %d .\n", yyseq, j);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:atProgramPoint file0:399_7_399_12-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:322_5_322_5 pa:hasState file0:322_5_322_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:hasValue %d .\n", yyseq, c);
 fprintf( yyfp, "file0:322_5_322_5_state-%d pa:atProgramPoint file0:399_7_399_12-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:399_7_399_12-%d pa:afterStatement file0:399_7_399_12. \n", ppseq);
 fprintf( yyfp, "file0:399_7_399_12-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;


double pj = xj[j]; /* column sum */
 fprintf( yyfp, "file0:331_1_331_10 pa:hasState file0:331_1_331_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:331_1_331_10_state-%d pa:hasValue %f .\n", yyseq, xj);
 fprintf( yyfp, "file0:331_1_331_10_state-%d pa:atProgramPoint file0:401_1_401_9-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "xj[j]_state-%d pa:atProgramPoint file0:401_1_401_9-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:327_1_327_5 pa:hasState file0:327_1_327_5_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:hasValue %d .\n", yyseq, j);
 fprintf( yyfp, "file0:327_1_327_5_state-%d pa:atProgramPoint file0:401_1_401_9-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:401_1_401_9-%d pa:afterStatement file0:401_1_401_9. \n", ppseq);
 fprintf( yyfp, "file0:401_1_401_9-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

if ( pj > 0.0 ){
info -= pj * log( pj );
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:403_1_403_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:401_1_401_9 pa:hasState file0:401_1_401_9_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:401_1_401_9_state-%d pa:hasValue %f .\n", yyseq, pj);
 fprintf( yyfp, "file0:401_1_401_9_state-%d pa:atProgramPoint file0:403_1_403_23-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:403_1_403_23-%d pa:afterStatement file0:403_1_403_23. \n", ppseq);
 fprintf( yyfp, "file0:403_1_403_23-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

}
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:402_1_404_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:401_1_401_9 pa:hasState file0:401_1_401_9_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:401_1_401_9_state-%d pa:hasValue %f .\n", yyseq, pj);
 fprintf( yyfp, "file0:401_1_401_9_state-%d pa:atProgramPoint file0:402_1_404_1-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:402_1_404_1-%d pa:afterStatement file0:402_1_404_1. \n", ppseq);
 fprintf( yyfp, "file0:402_1_404_1-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

/* part 4 */
}
info *= 2.0; /* for comparability with chi-square */
 fprintf( yyfp, "file0:329_1_329_11 pa:hasState file0:329_1_329_11_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:hasValue %f .\n", yyseq, info);
 fprintf( yyfp, "file0:329_1_329_11_state-%d pa:atProgramPoint file0:407_1_407_12-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:407_1_407_12-%d pa:afterStatement file0:407_1_407_12. \n", ppseq);
 fprintf( yyfp, "file0:407_1_407_12-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

ret1:
free( (pointer)xj );
 fprintf( yyfp, "file0:331_1_331_10 pa:hasState file0:331_1_331_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:331_1_331_10_state-%d pa:hasValue %f .\n", yyseq, xj);
 fprintf( yyfp, "file0:331_1_331_10_state-%d pa:atProgramPoint file0:409_1_409_20-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:409_1_409_20-%d pa:afterStatement file0:409_1_409_20. \n", ppseq);
 fprintf( yyfp, "file0:409_1_409_20-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

ret2:
free( (pointer)xi );
 fprintf( yyfp, "file0:330_1_330_10 pa:hasState file0:330_1_330_10_state-%d .\n",yyseq);
 fprintf( yyfp, "file0:330_1_330_10_state-%d pa:hasValue %f .\n", yyseq, xi);
 fprintf( yyfp, "file0:330_1_330_10_state-%d pa:atProgramPoint file0:411_1_411_20-%d. \n", yyseq, ppseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "file0:411_1_411_20-%d pa:afterStatement file0:411_1_411_20. \n", ppseq);
 fprintf( yyfp, "file0:411_1_411_20-%d pa:timeStamp %d .\n" , ppseq, ppseq);
ppseq = ppseq + 1;

ret3:
return info;
}
