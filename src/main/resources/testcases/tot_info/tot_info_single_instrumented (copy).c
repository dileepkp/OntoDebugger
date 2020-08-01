
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

int yyseq = 1;

/*ARGSUSED*/


int main(int argc,char *argv[]) {
yyfp = fopen("/home/aidb/Dropbox/testcases/tot_info/tot_info_single_trace.ttl","w");
char *p; /* input line scan location */

int i; /* row index */

int j; /* column index */

double info; /* computed information measure */

int infodf; /* degrees of freedom for information */

double totinfo = 0.0; /* accumulated information */

int totdf; /* accumulated degrees of freedom */

totdf = 0;
 fprintf( yyfp, "zzzfile0:131_1_131_9 pa:hasState file0:131_1_131_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:131_1_131_9_state-%d pa:hasValue %d\n", yyseq, totdf);
 fprintf( yyfp, "zzzfile0:131_1_131_9_state-%d pa:atProgramPoint file0:133_9_133_42-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:133_9_133_42-%d pa:beforeStatement file0:133_9_133_42\n", yyseq);
 fprintf( yyfp, "zzzfile0:133_9_133_42-%d pa:timeStamp %d\n" , yyseq, yyseq);

while ( fgets( line, MAXLINE, stdin ) != NULL ) /* start new table */
{
 fprintf( yyfp, "zzzfile0:125_1_125_7 pa:hasState file0:125_1_125_7_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:125_1_125_7_state-%d pa:hasValue %s\n", yyseq, p);
 fprintf( yyfp, "zzzfile0:125_1_125_7_state-%d pa:atProgramPoint file0:135_17_135_31-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:135_17_135_31-%d pa:beforeStatement file0:135_17_135_31\n", yyseq);
 fprintf( yyfp, "zzzfile0:135_17_135_31-%d pa:timeStamp %d\n" , yyseq, yyseq);

for ( p = line; *p != '\0' && isspace( (int)*p ); ++p )
{
 fprintf( yyfp, "zzzfile0:125_1_125_7 pa:hasState file0:125_1_125_7_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:125_1_125_7_state-%d pa:hasValue %s\n", yyseq, p);
 fprintf( yyfp, "zzzfile0:125_1_125_7_state-%d pa:atProgramPoint file0:137_1_137_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:137_1_137_1-%d pa:beforeStatement file0:137_1_137_1\n", yyseq);
 fprintf( yyfp, "zzzfile0:137_1_137_1-%d pa:timeStamp %d\n" , yyseq, yyseq);

;
}

if ( *p == '\0' )
{
 fprintf( yyfp, "zzzfile0:125_1_125_7 pa:hasState file0:125_1_125_7_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:125_1_125_7_state-%d pa:hasValue %s\n", yyseq, p);
 fprintf( yyfp, "zzzfile0:125_1_125_7_state-%d pa:atProgramPoint file0:142_1_142_9-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:142_1_142_9-%d pa:beforeStatement file0:142_1_142_9\n", yyseq);
 fprintf( yyfp, "zzzfile0:142_1_142_9-%d pa:timeStamp %d\n" , yyseq, yyseq);

continue;
}
/* skip blank line */
if ( *p == COMMENT )
{ /* copy comment through */
 fprintf( yyfp, "zzzfile0:125_1_125_7 pa:hasState file0:125_1_125_7_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:125_1_125_7_state-%d pa:hasValue %s\n", yyseq, p);
 fprintf( yyfp, "zzzfile0:125_1_125_7_state-%d pa:atProgramPoint file0:147_1_147_28-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:147_1_147_28-%d pa:beforeStatement file0:147_1_147_28\n", yyseq);
 fprintf( yyfp, "zzzfile0:147_1_147_28-%d pa:timeStamp %d\n" , yyseq, yyseq);

(void)fputs( line, stdout );

continue;
}
if ( sscanf( p, "%d %d\n", &r, &c ) != 2 )
{
 fprintf( yyfp, "zzzfile0:116_1_116_12 pa:hasState file0:116_1_116_12_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:116_1_116_12_state-%d pa:hasValue %d\n", yyseq, r);
 fprintf( yyfp, "zzzfile0:116_1_116_12_state-%d pa:atProgramPoint file0:152_1_152_55-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:125_1_125_7 pa:hasState file0:125_1_125_7_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:125_1_125_7_state-%d pa:hasValue %s\n", yyseq, p);
 fprintf( yyfp, "zzzfile0:125_1_125_7_state-%d pa:atProgramPoint file0:152_1_152_55-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:117_1_117_12 pa:hasState file0:117_1_117_12_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:117_1_117_12_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:117_1_117_12_state-%d pa:atProgramPoint file0:152_1_152_55-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:152_1_152_55-%d pa:beforeStatement file0:152_1_152_55\n", yyseq);
 fprintf( yyfp, "zzzfile0:152_1_152_55-%d pa:timeStamp %d\n" , yyseq, yyseq);

(void)fputs( "* invalid row/column line *\n", stdout );

return EXIT_FAILURE;
}
if ( r * c > MAXTBL )
{
 fprintf( yyfp, "zzzfile0:117_1_117_12 pa:hasState file0:117_1_117_12_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:117_1_117_12_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:117_1_117_12_state-%d pa:atProgramPoint file0:157_1_157_47-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:116_1_116_12 pa:hasState file0:116_1_116_12_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:116_1_116_12_state-%d pa:hasValue %d\n", yyseq, r);
 fprintf( yyfp, "zzzfile0:116_1_116_12_state-%d pa:atProgramPoint file0:157_1_157_47-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:157_1_157_47-%d pa:beforeStatement file0:157_1_157_47\n", yyseq);
 fprintf( yyfp, "zzzfile0:157_1_157_47-%d pa:timeStamp %d\n" , yyseq, yyseq);

(void)fputs( "* table too large *\n", stdout );

return EXIT_FAILURE;
}
/* input tallies */
 fprintf( yyfp, "zzzfile0:126_1_126_5 pa:hasState file0:126_1_126_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:126_1_126_5_state-%d pa:hasValue %d\n", yyseq, i);
 fprintf( yyfp, "zzzfile0:126_1_126_5_state-%d pa:atProgramPoint file0:161_14_161_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:116_1_116_12 pa:hasState file0:116_1_116_12_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:116_1_116_12_state-%d pa:hasValue %d\n", yyseq, r);
 fprintf( yyfp, "zzzfile0:116_1_116_12_state-%d pa:atProgramPoint file0:161_14_161_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:161_14_161_18-%d pa:beforeStatement file0:161_14_161_18\n", yyseq);
 fprintf( yyfp, "zzzfile0:161_14_161_18-%d pa:timeStamp %d\n" , yyseq, yyseq);

for ( i = 0; i < r; ++i ){
 fprintf( yyfp, "zzzfile0:127_1_127_5 pa:hasState file0:127_1_127_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:127_1_127_5_state-%d pa:hasValue %d\n", yyseq, j);
 fprintf( yyfp, "zzzfile0:127_1_127_5_state-%d pa:atProgramPoint file0:162_14_162_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:117_1_117_12 pa:hasState file0:117_1_117_12_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:117_1_117_12_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:117_1_117_12_state-%d pa:atProgramPoint file0:162_14_162_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:116_1_116_12 pa:hasState file0:116_1_116_12_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:116_1_116_12_state-%d pa:hasValue %d\n", yyseq, r);
 fprintf( yyfp, "zzzfile0:116_1_116_12_state-%d pa:atProgramPoint file0:162_14_162_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:126_1_126_5 pa:hasState file0:126_1_126_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:126_1_126_5_state-%d pa:hasValue %d\n", yyseq, i);
 fprintf( yyfp, "zzzfile0:126_1_126_5_state-%d pa:atProgramPoint file0:162_14_162_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:162_14_162_18-%d pa:beforeStatement file0:162_14_162_18\n", yyseq);
 fprintf( yyfp, "zzzfile0:162_14_162_18-%d pa:timeStamp %d\n" , yyseq, yyseq);

for ( j = 0; j < c; ++j )
{
if ( scanf( " %ld", &(f[(i)*c+(j)]) ) != 1 )
{
 fprintf( yyfp, "zzzfile0:117_1_117_12 pa:hasState file0:117_1_117_12_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:117_1_117_12_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:117_1_117_12_state-%d pa:atProgramPoint file0:166_1_168_2-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:115_1_115_21 pa:hasState file0:115_1_115_21_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:115_1_115_21_state-%d pa:hasValue %li\n", yyseq, f[(i)*c+(j)]);
 fprintf( yyfp, "zzzfile0:115_1_115_21_state-%d pa:atProgramPoint file0:166_1_168_2-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:127_1_127_5 pa:hasState file0:127_1_127_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:127_1_127_5_state-%d pa:hasValue %d\n", yyseq, j);
 fprintf( yyfp, "zzzfile0:127_1_127_5_state-%d pa:atProgramPoint file0:166_1_168_2-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:126_1_126_5 pa:hasState file0:126_1_126_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:126_1_126_5_state-%d pa:hasValue %d\n", yyseq, i);
 fprintf( yyfp, "zzzfile0:126_1_126_5_state-%d pa:atProgramPoint file0:166_1_168_2-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:166_1_168_2-%d pa:beforeStatement file0:166_1_168_2\n", yyseq);
 fprintf( yyfp, "zzzfile0:166_1_168_2-%d pa:timeStamp %d\n" , yyseq, yyseq);

(void)fputs( "* EOF in table *\n",
stdout
);

return EXIT_FAILURE;
}
}}

/* compute statistic */
info = InfoTbl( r, c, f, &infodf );
/* print results */
if ( info >= 0.0 )
{
 fprintf( yyfp, "zzzfile0:128_1_128_11 pa:hasState file0:128_1_128_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:128_1_128_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:128_1_128_11_state-%d pa:atProgramPoint file0:178_1_181_2-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:129_1_129_10 pa:hasState file0:129_1_129_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:129_1_129_10_state-%d pa:hasValue %d\n", yyseq, infodf);
 fprintf( yyfp, "zzzfile0:129_1_129_10_state-%d pa:atProgramPoint file0:178_1_181_2-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:131_1_131_9 pa:hasState file0:131_1_131_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:131_1_131_9_state-%d pa:hasValue %d\n", yyseq, totdf);
 fprintf( yyfp, "zzzfile0:131_1_131_9_state-%d pa:atProgramPoint file0:178_1_181_2-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:130_1_130_14 pa:hasState file0:130_1_130_14_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:130_1_130_14_state-%d pa:hasValue %f\n", yyseq, totinfo);
 fprintf( yyfp, "zzzfile0:130_1_130_14_state-%d pa:atProgramPoint file0:178_1_181_2-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:178_1_181_2-%d pa:beforeStatement file0:178_1_181_2\n", yyseq);
 fprintf( yyfp, "zzzfile0:178_1_181_2-%d pa:timeStamp %d\n" , yyseq, yyseq);

(void)printf( "2info = %5.2f\tdf = %2d\tq = %7.4f\n",
info, infodf,
QChiSq( info, infodf )
);
 fprintf( yyfp, "zzzfile0:129_1_129_10 pa:hasState file0:129_1_129_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:129_1_129_10_state-%d pa:hasValue %d\n", yyseq, infodf);
 fprintf( yyfp, "zzzfile0:129_1_129_10_state-%d pa:atProgramPoint file0:182_1_182_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:128_1_128_11 pa:hasState file0:128_1_128_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:128_1_128_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:128_1_128_11_state-%d pa:atProgramPoint file0:182_1_182_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:182_1_182_15-%d pa:beforeStatement file0:182_1_182_15\n", yyseq);
 fprintf( yyfp, "zzzfile0:182_1_182_15-%d pa:timeStamp %d\n" , yyseq, yyseq);

totinfo = info; /* removed + before = */
 fprintf( yyfp, "zzzfile0:128_1_128_11 pa:hasState file0:128_1_128_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:128_1_128_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:128_1_128_11_state-%d pa:atProgramPoint file0:183_1_183_16-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:130_1_130_14 pa:hasState file0:130_1_130_14_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:130_1_130_14_state-%d pa:hasValue %f\n", yyseq, totinfo);
 fprintf( yyfp, "zzzfile0:130_1_130_14_state-%d pa:atProgramPoint file0:183_1_183_16-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:183_1_183_16-%d pa:beforeStatement file0:183_1_183_16\n", yyseq);
 fprintf( yyfp, "zzzfile0:183_1_183_16-%d pa:timeStamp %d\n" , yyseq, yyseq);

totdf += infodf;
}
else
{
 fprintf( yyfp, "zzzfile0:128_1_128_11 pa:hasState file0:128_1_128_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:128_1_128_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:128_1_128_11_state-%d pa:atProgramPoint file0:187_1_192_2-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:129_1_129_10 pa:hasState file0:129_1_129_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:129_1_129_10_state-%d pa:hasValue %d\n", yyseq, infodf);
 fprintf( yyfp, "zzzfile0:129_1_129_10_state-%d pa:atProgramPoint file0:187_1_192_2-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:131_1_131_9 pa:hasState file0:131_1_131_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:131_1_131_9_state-%d pa:hasValue %d\n", yyseq, totdf);
 fprintf( yyfp, "zzzfile0:131_1_131_9_state-%d pa:atProgramPoint file0:187_1_192_2-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:130_1_130_14 pa:hasState file0:130_1_130_14_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:130_1_130_14_state-%d pa:hasValue %f\n", yyseq, totinfo);
 fprintf( yyfp, "zzzfile0:130_1_130_14_state-%d pa:atProgramPoint file0:187_1_192_2-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:187_1_192_2-%d pa:beforeStatement file0:187_1_192_2\n", yyseq);
 fprintf( yyfp, "zzzfile0:187_1_192_2-%d pa:timeStamp %d\n" , yyseq, yyseq);

 fprintf( yyfp, "zzzfile0:116_1_116_12 pa:hasState file0:116_1_116_12_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:116_1_116_12_state-%d pa:hasValue %d\n", yyseq, r);
 fprintf( yyfp, "zzzfile0:116_1_116_12_state-%d pa:atProgramPoint file0:176_1_193_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:128_1_128_11 pa:hasState file0:128_1_128_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:128_1_128_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:128_1_128_11_state-%d pa:atProgramPoint file0:176_1_193_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:117_1_117_12 pa:hasState file0:117_1_117_12_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:117_1_117_12_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:117_1_117_12_state-%d pa:atProgramPoint file0:176_1_193_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:129_1_129_10 pa:hasState file0:129_1_129_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:129_1_129_10_state-%d pa:hasValue %d\n", yyseq, infodf);
 fprintf( yyfp, "zzzfile0:129_1_129_10_state-%d pa:atProgramPoint file0:176_1_193_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:131_1_131_9 pa:hasState file0:131_1_131_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:131_1_131_9_state-%d pa:hasValue %d\n", yyseq, totdf);
 fprintf( yyfp, "zzzfile0:131_1_131_9_state-%d pa:atProgramPoint file0:176_1_193_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:176_1_193_1-%d pa:beforeStatement file0:176_1_193_1\n", yyseq);
 fprintf( yyfp, "zzzfile0:176_1_193_1-%d pa:timeStamp %d\n" , yyseq, yyseq);

(void)fputs( info < -3.5 ? "out of memory\n"
: info < -2.5 ? "table too small\n"
: info < -1.5 ? "negative freq\n"
: "table all zeros\n",
stdout
);
}

}
if ( totdf <= 0 )
{
 fprintf( yyfp, "zzzfile0:131_1_131_9 pa:hasState file0:131_1_131_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:131_1_131_9_state-%d pa:hasValue %d\n", yyseq, totdf);
 fprintf( yyfp, "zzzfile0:131_1_131_9_state-%d pa:atProgramPoint file0:198_1_198_64-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:198_1_198_64-%d pa:beforeStatement file0:198_1_198_64\n", yyseq);
 fprintf( yyfp, "zzzfile0:198_1_198_64-%d pa:timeStamp %d\n" , yyseq, yyseq);

(void)fputs( "\n*** no information accumulated ***\n", stdout );

return EXIT_FAILURE;
}
(void)printf( "\ntotal 2info = %5.2f\tdf = %2d\tq = %7.4f\n",
totinfo, totdf,
QChiSq( totinfo, totdf )
);
 fprintf( yyfp, "zzzfile0:130_1_130_14 pa:hasState file0:130_1_130_14_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:130_1_130_14_state-%d pa:hasValue %f\n", yyseq, totinfo);
 fprintf( yyfp, "zzzfile0:130_1_130_14_state-%d pa:atProgramPoint file0:205_1_205_20-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:131_1_131_9 pa:hasState file0:131_1_131_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:131_1_131_9_state-%d pa:hasValue %d\n", yyseq, totdf);
 fprintf( yyfp, "zzzfile0:131_1_131_9_state-%d pa:atProgramPoint file0:205_1_205_20-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:205_1_205_20-%d pa:beforeStatement file0:205_1_205_20\n", yyseq);
 fprintf( yyfp, "zzzfile0:205_1_205_20-%d pa:timeStamp %d\n" , yyseq, yyseq);

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
if ( --x < 0.0 ) /* use reflection formula for accuracy */
{
 fprintf( yyfp, "zzzfile0:220_8_220_8 pa:hasState file0:220_8_220_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:220_8_220_8_state-%d pa:hasValue %f\n", yyseq, x);
 fprintf( yyfp, "zzzfile0:220_8_220_8_state-%d pa:atProgramPoint file0:231_1_231_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:231_1_231_10-%d pa:beforeStatement file0:231_1_231_10\n", yyseq);
 fprintf( yyfp, "zzzfile0:231_1_231_10-%d pa:timeStamp %d\n" , yyseq, yyseq);

double pix = PI * x;
 fprintf( yyfp, "zzzfile0:220_8_220_8 pa:hasState file0:220_8_220_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:220_8_220_8_state-%d pa:hasValue %f\n", yyseq, x);
 fprintf( yyfp, "zzzfile0:220_8_220_8_state-%d pa:atProgramPoint file0:232_1_232_51-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:232_1_232_51-%d pa:beforeStatement file0:232_1_232_51\n", yyseq);
 fprintf( yyfp, "zzzfile0:232_1_232_51-%d pa:timeStamp %d\n" , yyseq, yyseq);

return log( pix / sin( pix ) ) - LGamma( 1.0 - x );
}
tmp = x + 5.5;
 fprintf( yyfp, "zzzfile0:220_8_220_8 pa:hasState file0:220_8_220_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:220_8_220_8_state-%d pa:hasValue %f\n", yyseq, x);
 fprintf( yyfp, "zzzfile0:220_8_220_8_state-%d pa:atProgramPoint file0:235_1_235_30-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:227_1_227_10 pa:hasState file0:227_1_227_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:227_1_227_10_state-%d pa:hasValue %f\n", yyseq, tmp);
 fprintf( yyfp, "zzzfile0:227_1_227_10_state-%d pa:atProgramPoint file0:235_1_235_30-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:235_1_235_30-%d pa:beforeStatement file0:235_1_235_30\n", yyseq);
 fprintf( yyfp, "zzzfile0:235_1_235_30-%d pa:timeStamp %d\n" , yyseq, yyseq);

tmp -= (x + 0.5) * log( tmp );
 fprintf( yyfp, "zzzfile0:220_8_220_8 pa:hasState file0:220_8_220_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:220_8_220_8_state-%d pa:hasValue %f\n", yyseq, x);
 fprintf( yyfp, "zzzfile0:220_8_220_8_state-%d pa:atProgramPoint file0:236_1_236_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:227_1_227_10 pa:hasState file0:227_1_227_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:227_1_227_10_state-%d pa:hasValue %f\n", yyseq, tmp);
 fprintf( yyfp, "zzzfile0:227_1_227_10_state-%d pa:atProgramPoint file0:236_1_236_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:236_1_236_10-%d pa:beforeStatement file0:236_1_236_10\n", yyseq);
 fprintf( yyfp, "zzzfile0:236_1_236_10-%d pa:timeStamp %d\n" , yyseq, yyseq);

ser = 1.0;
 fprintf( yyfp, "zzzfile0:228_1_228_5 pa:hasState file0:228_1_228_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:228_1_228_5_state-%d pa:hasValue %d\n", yyseq, j);
 fprintf( yyfp, "zzzfile0:228_1_228_5_state-%d pa:atProgramPoint file0:237_21_237_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:222_1_222_26 pa:hasState file0:222_1_222_26_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:222_1_222_26_state-%d pa:atProgramPoint file0:237_21_237_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:227_1_227_15 pa:hasState file0:227_1_227_15_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:227_1_227_15_state-%d pa:hasValue %f\n", yyseq, ser);
 fprintf( yyfp, "zzzfile0:227_1_227_15_state-%d pa:atProgramPoint file0:237_21_237_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:220_8_220_8 pa:hasState file0:220_8_220_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:220_8_220_8_state-%d pa:hasValue %f\n", yyseq, x);
 fprintf( yyfp, "zzzfile0:220_8_220_8_state-%d pa:atProgramPoint file0:237_21_237_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:237_21_237_23-%d pa:beforeStatement file0:237_21_237_23\n", yyseq);
 fprintf( yyfp, "zzzfile0:237_21_237_23-%d pa:timeStamp %d\n" , yyseq, yyseq);

for ( j = 0; j < 6; ++j )
{
 fprintf( yyfp, "zzzfile0:228_1_228_5 pa:hasState file0:228_1_228_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:228_1_228_5_state-%d pa:hasValue %d\n", yyseq, j);
 fprintf( yyfp, "zzzfile0:228_1_228_5_state-%d pa:atProgramPoint file0:239_1_239_20-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:239_1_239_20-%d pa:beforeStatement file0:239_1_239_20\n", yyseq);
 fprintf( yyfp, "zzzfile0:239_1_239_20-%d pa:timeStamp %d\n" , yyseq, yyseq);

ser += cof[j] / ++x;
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
if ( x <= 0.0 )
{
 fprintf( yyfp, "zzzfile0:248_18_248_18 pa:hasState file0:248_18_248_18_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:248_18_248_18_state-%d pa:hasValue %f\n", yyseq, x);
 fprintf( yyfp, "zzzfile0:248_18_248_18_state-%d pa:atProgramPoint file0:254_1_254_11-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:254_1_254_11-%d pa:beforeStatement file0:254_1_254_11\n", yyseq);
 fprintf( yyfp, "zzzfile0:254_1_254_11-%d pa:timeStamp %d\n" , yyseq, yyseq);

 fprintf( yyfp, "zzzfile0:248_18_248_18 pa:hasState file0:248_18_248_18_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:248_18_248_18_state-%d pa:hasValue %f\n", yyseq, x);
 fprintf( yyfp, "zzzfile0:248_18_248_18_state-%d pa:atProgramPoint file0:252_1_255_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:252_1_255_1-%d pa:beforeStatement file0:252_1_255_1\n", yyseq);
 fprintf( yyfp, "zzzfile0:252_1_255_1-%d pa:timeStamp %d\n" , yyseq, yyseq);

return 0.0;
}

del = sum = 1.0 / (ap = a);
 fprintf( yyfp, "zzzfile0:250_1_250_9 pa:hasState file0:250_1_250_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:250_1_250_9_state-%d pa:hasValue %f\n", yyseq, ap);
 fprintf( yyfp, "zzzfile0:250_1_250_9_state-%d pa:atProgramPoint file0:258_7_258_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:251_1_251_5 pa:hasState file0:251_1_251_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:251_1_251_5_state-%d pa:hasValue %d\n", yyseq, n);
 fprintf( yyfp, "zzzfile0:251_1_251_5_state-%d pa:atProgramPoint file0:258_7_258_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:250_1_250_14 pa:hasState file0:250_1_250_14_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:250_1_250_14_state-%d pa:hasValue %f\n", yyseq, del);
 fprintf( yyfp, "zzzfile0:250_1_250_14_state-%d pa:atProgramPoint file0:258_7_258_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:248_8_248_8 pa:hasState file0:248_8_248_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:248_8_248_8_state-%d pa:hasValue %f\n", yyseq, a);
 fprintf( yyfp, "zzzfile0:248_8_248_8_state-%d pa:atProgramPoint file0:258_7_258_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:250_1_250_19 pa:hasState file0:250_1_250_19_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:250_1_250_19_state-%d pa:hasValue %f\n", yyseq, sum);
 fprintf( yyfp, "zzzfile0:250_1_250_19_state-%d pa:atProgramPoint file0:258_7_258_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:258_7_258_12-%d pa:beforeStatement file0:258_7_258_12\n", yyseq);
 fprintf( yyfp, "zzzfile0:258_7_258_12-%d pa:timeStamp %d\n" , yyseq, yyseq);

for ( n = 1; n <= ITMAX; ++n )
{
 fprintf( yyfp, "zzzfile0:251_1_251_5 pa:hasState file0:251_1_251_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:251_1_251_5_state-%d pa:hasValue %d\n", yyseq, n);
 fprintf( yyfp, "zzzfile0:251_1_251_5_state-%d pa:atProgramPoint file0:260_1_260_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:260_1_260_23-%d pa:beforeStatement file0:260_1_260_23\n", yyseq);
 fprintf( yyfp, "zzzfile0:260_1_260_23-%d pa:timeStamp %d\n" , yyseq, yyseq);

sum += del *= x / ++ap;
if ( Abs( del ) < Abs( sum ) * EPS )
{
 fprintf( yyfp, "zzzfile0:248_8_248_8 pa:hasState file0:248_8_248_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:248_8_248_8_state-%d pa:hasValue %f\n", yyseq, a);
 fprintf( yyfp, "zzzfile0:248_8_248_8_state-%d pa:atProgramPoint file0:263_1_263_52-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:250_1_250_19 pa:hasState file0:250_1_250_19_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:250_1_250_19_state-%d pa:hasValue %f\n", yyseq, sum);
 fprintf( yyfp, "zzzfile0:250_1_250_19_state-%d pa:atProgramPoint file0:263_1_263_52-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:250_1_250_14 pa:hasState file0:250_1_250_14_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:250_1_250_14_state-%d pa:hasValue %f\n", yyseq, del);
 fprintf( yyfp, "zzzfile0:250_1_250_14_state-%d pa:atProgramPoint file0:263_1_263_52-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:248_18_248_18 pa:hasState file0:248_18_248_18_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:248_18_248_18_state-%d pa:hasValue %f\n", yyseq, x);
 fprintf( yyfp, "zzzfile0:248_18_248_18_state-%d pa:atProgramPoint file0:263_1_263_52-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:263_1_263_52-%d pa:beforeStatement file0:263_1_263_52\n", yyseq);
 fprintf( yyfp, "zzzfile0:263_1_263_52-%d pa:timeStamp %d\n" , yyseq, yyseq);

return sum * exp( -x + a * log( x ) - LGamma( a ) );
}

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
 fprintf( yyfp, "zzzfile0:271_18_271_18 pa:hasState file0:271_18_271_18_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:271_18_271_18_state-%d pa:hasValue %f\n", yyseq, x);
 fprintf( yyfp, "zzzfile0:271_18_271_18_state-%d pa:atProgramPoint file0:276_7_276_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:273_1_273_5 pa:hasState file0:273_1_273_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:273_1_273_5_state-%d pa:hasValue %d\n", yyseq, n);
 fprintf( yyfp, "zzzfile0:273_1_273_5_state-%d pa:atProgramPoint file0:276_7_276_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:276_7_276_12-%d pa:beforeStatement file0:276_7_276_12\n", yyseq);
 fprintf( yyfp, "zzzfile0:276_7_276_12-%d pa:timeStamp %d\n" , yyseq, yyseq);

for ( n = 1; n <= ITMAX; ++n )
{
 fprintf( yyfp, "zzzfile0:273_1_273_5 pa:hasState file0:273_1_273_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:273_1_273_5_state-%d pa:hasValue %d\n", yyseq, n);
 fprintf( yyfp, "zzzfile0:273_1_273_5_state-%d pa:atProgramPoint file0:278_1_278_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:278_1_278_10-%d pa:beforeStatement file0:278_1_278_10\n", yyseq);
 fprintf( yyfp, "zzzfile0:278_1_278_10-%d pa:timeStamp %d\n" , yyseq, yyseq);

double anf;

double an = (double)n;
 fprintf( yyfp, "zzzfile0:273_1_273_5 pa:hasState file0:273_1_273_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:273_1_273_5_state-%d pa:hasValue %d\n", yyseq, n);
 fprintf( yyfp, "zzzfile0:273_1_273_5_state-%d pa:atProgramPoint file0:280_1_280_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:280_1_280_10-%d pa:beforeStatement file0:280_1_280_10\n", yyseq);
 fprintf( yyfp, "zzzfile0:280_1_280_10-%d pa:timeStamp %d\n" , yyseq, yyseq);

double ana = an - a;
 fprintf( yyfp, "zzzfile0:279_1_279_9 pa:hasState file0:279_1_279_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:279_1_279_9_state-%d pa:hasValue %f\n", yyseq, an);
 fprintf( yyfp, "zzzfile0:279_1_279_9_state-%d pa:atProgramPoint file0:281_1_281_27-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:271_8_271_8 pa:hasState file0:271_8_271_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:271_8_271_8_state-%d pa:hasValue %f\n", yyseq, a);
 fprintf( yyfp, "zzzfile0:271_8_271_8_state-%d pa:atProgramPoint file0:281_1_281_27-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:281_1_281_27-%d pa:beforeStatement file0:281_1_281_27\n", yyseq);
 fprintf( yyfp, "zzzfile0:281_1_281_27-%d pa:timeStamp %d\n" , yyseq, yyseq);

a0 = (a1 + a0 * ana) * fac;
 fprintf( yyfp, "zzzfile0:280_1_280_10 pa:hasState file0:280_1_280_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:280_1_280_10_state-%d pa:hasValue %f\n", yyseq, ana);
 fprintf( yyfp, "zzzfile0:280_1_280_10_state-%d pa:atProgramPoint file0:282_1_282_27-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:274_1_275_22 pa:hasState file0:274_1_275_22_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_275_22_state-%d pa:hasValue %f\n", yyseq, a1);
 fprintf( yyfp, "zzzfile0:274_1_275_22_state-%d pa:atProgramPoint file0:282_1_282_27-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:274_1_275_12 pa:hasState file0:274_1_275_12_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_275_12_state-%d pa:hasValue %f\n", yyseq, a0);
 fprintf( yyfp, "zzzfile0:274_1_275_12_state-%d pa:atProgramPoint file0:282_1_282_27-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:274_1_274_22 pa:hasState file0:274_1_274_22_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_274_22_state-%d pa:hasValue %f\n", yyseq, fac);
 fprintf( yyfp, "zzzfile0:274_1_274_22_state-%d pa:atProgramPoint file0:282_1_282_27-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:282_1_282_27-%d pa:beforeStatement file0:282_1_282_27\n", yyseq);
 fprintf( yyfp, "zzzfile0:282_1_282_27-%d pa:timeStamp %d\n" , yyseq, yyseq);

b0 = (b1 + b0 * ana) * fac;
 fprintf( yyfp, "zzzfile0:274_1_274_32 pa:hasState file0:274_1_274_32_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_274_32_state-%d pa:hasValue %f\n", yyseq, b1);
 fprintf( yyfp, "zzzfile0:274_1_274_32_state-%d pa:atProgramPoint file0:283_1_283_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:274_1_275_2 pa:hasState file0:274_1_275_2_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_275_2_state-%d pa:hasValue %f\n", yyseq, b0);
 fprintf( yyfp, "zzzfile0:274_1_275_2_state-%d pa:atProgramPoint file0:283_1_283_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:274_1_274_22 pa:hasState file0:274_1_274_22_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_274_22_state-%d pa:hasValue %f\n", yyseq, fac);
 fprintf( yyfp, "zzzfile0:274_1_274_22_state-%d pa:atProgramPoint file0:283_1_283_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:280_1_280_10 pa:hasState file0:280_1_280_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:280_1_280_10_state-%d pa:hasValue %f\n", yyseq, ana);
 fprintf( yyfp, "zzzfile0:280_1_280_10_state-%d pa:atProgramPoint file0:283_1_283_15-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:283_1_283_15-%d pa:beforeStatement file0:283_1_283_15\n", yyseq);
 fprintf( yyfp, "zzzfile0:283_1_283_15-%d pa:timeStamp %d\n" , yyseq, yyseq);

anf = an * fac;
 fprintf( yyfp, "zzzfile0:278_1_278_10 pa:hasState file0:278_1_278_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:278_1_278_10_state-%d pa:hasValue %f\n", yyseq, anf);
 fprintf( yyfp, "zzzfile0:278_1_278_10_state-%d pa:atProgramPoint file0:284_1_284_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:279_1_279_9 pa:hasState file0:279_1_279_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:279_1_279_9_state-%d pa:hasValue %f\n", yyseq, an);
 fprintf( yyfp, "zzzfile0:279_1_279_9_state-%d pa:atProgramPoint file0:284_1_284_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:274_1_274_22 pa:hasState file0:274_1_274_22_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_274_22_state-%d pa:hasValue %f\n", yyseq, fac);
 fprintf( yyfp, "zzzfile0:274_1_274_22_state-%d pa:atProgramPoint file0:284_1_284_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:284_1_284_23-%d pa:beforeStatement file0:284_1_284_23\n", yyseq);
 fprintf( yyfp, "zzzfile0:284_1_284_23-%d pa:timeStamp %d\n" , yyseq, yyseq);

b1 = x * b0 + anf * b1;
 fprintf( yyfp, "zzzfile0:274_1_275_2 pa:hasState file0:274_1_275_2_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_275_2_state-%d pa:hasValue %f\n", yyseq, b0);
 fprintf( yyfp, "zzzfile0:274_1_275_2_state-%d pa:atProgramPoint file0:285_1_285_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:271_18_271_18 pa:hasState file0:271_18_271_18_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:271_18_271_18_state-%d pa:hasValue %f\n", yyseq, x);
 fprintf( yyfp, "zzzfile0:271_18_271_18_state-%d pa:atProgramPoint file0:285_1_285_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:278_1_278_10 pa:hasState file0:278_1_278_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:278_1_278_10_state-%d pa:hasValue %f\n", yyseq, anf);
 fprintf( yyfp, "zzzfile0:278_1_278_10_state-%d pa:atProgramPoint file0:285_1_285_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:274_1_274_32 pa:hasState file0:274_1_274_32_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_274_32_state-%d pa:hasValue %f\n", yyseq, b1);
 fprintf( yyfp, "zzzfile0:274_1_274_32_state-%d pa:atProgramPoint file0:285_1_285_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:285_1_285_23-%d pa:beforeStatement file0:285_1_285_23\n", yyseq);
 fprintf( yyfp, "zzzfile0:285_1_285_23-%d pa:timeStamp %d\n" , yyseq, yyseq);

a1 = x * a0 + anf * a1;
if ( a1 != 0.0 )
{ /* renormalize */
 fprintf( yyfp, "zzzfile0:274_1_274_22 pa:hasState file0:274_1_274_22_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_274_22_state-%d pa:hasValue %f\n", yyseq, fac);
 fprintf( yyfp, "zzzfile0:274_1_274_22_state-%d pa:atProgramPoint file0:288_1_288_8-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:271_18_271_18 pa:hasState file0:271_18_271_18_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:271_18_271_18_state-%d pa:hasValue %f\n", yyseq, x);
 fprintf( yyfp, "zzzfile0:271_18_271_18_state-%d pa:atProgramPoint file0:288_1_288_8-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:274_1_275_22 pa:hasState file0:274_1_275_22_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_275_22_state-%d pa:hasValue %f\n", yyseq, a1);
 fprintf( yyfp, "zzzfile0:274_1_275_22_state-%d pa:atProgramPoint file0:288_1_288_8-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:271_8_271_8 pa:hasState file0:271_8_271_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:271_8_271_8_state-%d pa:hasValue %f\n", yyseq, a);
 fprintf( yyfp, "zzzfile0:271_8_271_8_state-%d pa:atProgramPoint file0:288_1_288_8-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:274_1_274_11 pa:hasState file0:274_1_274_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_274_11_state-%d pa:hasValue %f\n", yyseq, gold);
 fprintf( yyfp, "zzzfile0:274_1_274_11_state-%d pa:atProgramPoint file0:288_1_288_8-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:274_1_274_32 pa:hasState file0:274_1_274_32_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_274_32_state-%d pa:hasValue %f\n", yyseq, b1);
 fprintf( yyfp, "zzzfile0:274_1_274_32_state-%d pa:atProgramPoint file0:288_1_288_8-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:288_1_288_8-%d pa:beforeStatement file0:288_1_288_8\n", yyseq);
 fprintf( yyfp, "zzzfile0:288_1_288_8-%d pa:timeStamp %d\n" , yyseq, yyseq);

double g = b1 * (fac = 1.0 / a1);
 fprintf( yyfp, "zzzfile0:274_1_274_22 pa:hasState file0:274_1_274_22_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_274_22_state-%d pa:hasValue %f\n", yyseq, fac);
 fprintf( yyfp, "zzzfile0:274_1_274_22_state-%d pa:atProgramPoint file0:289_1_289_16-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:274_1_274_32 pa:hasState file0:274_1_274_32_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_274_32_state-%d pa:hasValue %f\n", yyseq, b1);
 fprintf( yyfp, "zzzfile0:274_1_274_32_state-%d pa:atProgramPoint file0:289_1_289_16-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:274_1_275_22 pa:hasState file0:274_1_275_22_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_275_22_state-%d pa:hasValue %f\n", yyseq, a1);
 fprintf( yyfp, "zzzfile0:274_1_275_22_state-%d pa:atProgramPoint file0:289_1_289_16-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:289_1_289_16-%d pa:beforeStatement file0:289_1_289_16\n", yyseq);
 fprintf( yyfp, "zzzfile0:289_1_289_16-%d pa:timeStamp %d\n" , yyseq, yyseq);

gold = g - gold;
if ( Abs( gold ) < EPS * Abs( g ) )
{
 fprintf( yyfp, "zzzfile0:271_18_271_18 pa:hasState file0:271_18_271_18_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:271_18_271_18_state-%d pa:hasValue %f\n", yyseq, x);
 fprintf( yyfp, "zzzfile0:271_18_271_18_state-%d pa:atProgramPoint file0:292_1_292_50-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:271_8_271_8 pa:hasState file0:271_8_271_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:271_8_271_8_state-%d pa:hasValue %f\n", yyseq, a);
 fprintf( yyfp, "zzzfile0:271_8_271_8_state-%d pa:atProgramPoint file0:292_1_292_50-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:288_1_288_8 pa:hasState file0:288_1_288_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:288_1_288_8_state-%d pa:hasValue %f\n", yyseq, g);
 fprintf( yyfp, "zzzfile0:288_1_288_8_state-%d pa:atProgramPoint file0:292_1_292_50-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:274_1_274_11 pa:hasState file0:274_1_274_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:274_1_274_11_state-%d pa:hasValue %f\n", yyseq, gold);
 fprintf( yyfp, "zzzfile0:274_1_274_11_state-%d pa:atProgramPoint file0:292_1_292_50-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:292_1_292_50-%d pa:beforeStatement file0:292_1_292_50\n", yyseq);
 fprintf( yyfp, "zzzfile0:292_1_292_50-%d pa:timeStamp %d\n" , yyseq, yyseq);

return exp( -x + a * log( x ) - LGamma( a ) ) * g;
}

gold = g;
}
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
 fprintf( yyfp, "zzzfile0:338_5_338_5 pa:hasState file0:338_5_338_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:hasValue %d\n", yyseq, r);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:atProgramPoint file0:350_1_350_7-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:350_1_350_7-%d pa:beforeStatement file0:350_1_350_7\n", yyseq);
 fprintf( yyfp, "zzzfile0:350_1_350_7-%d pa:timeStamp %d\n" , yyseq, yyseq);

int cdf = c - 1; /* column degrees of freedom */
if ( rdf <= 0 || cdf <= 0 )
{
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:353_1_353_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:350_1_350_7 pa:hasState file0:350_1_350_7_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:350_1_350_7_state-%d pa:hasValue %d\n", yyseq, cdf);
 fprintf( yyfp, "zzzfile0:350_1_350_7_state-%d pa:atProgramPoint file0:353_1_353_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:349_1_349_7 pa:hasState file0:349_1_349_7_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:349_1_349_7_state-%d pa:hasValue %d\n", yyseq, rdf);
 fprintf( yyfp, "zzzfile0:349_1_349_7_state-%d pa:atProgramPoint file0:353_1_353_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:353_1_353_12-%d pa:beforeStatement file0:353_1_353_12\n", yyseq);
 fprintf( yyfp, "zzzfile0:353_1_353_12-%d pa:timeStamp %d\n" , yyseq, yyseq);

info = -3.0;
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:354_1_354_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:354_1_354_10-%d pa:beforeStatement file0:354_1_354_10\n", yyseq);
 fprintf( yyfp, "zzzfile0:354_1_354_10-%d pa:timeStamp %d\n" , yyseq, yyseq);

goto ret3;
}
*pdf = rdf * cdf; /* total degrees of freedom */
if ( (xi = (double *)malloc( r * sizeof(double) )) == NULL )
{
 fprintf( yyfp, "zzzfile0:338_5_338_5 pa:hasState file0:338_5_338_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:hasValue %d\n", yyseq, r);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:atProgramPoint file0:359_1_359_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:359_1_359_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:347_1_347_10 pa:hasState file0:347_1_347_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:347_1_347_10_state-%d pa:hasValue %f\n", yyseq, xi);
 fprintf( yyfp, "zzzfile0:347_1_347_10_state-%d pa:atProgramPoint file0:359_1_359_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:359_1_359_12-%d pa:beforeStatement file0:359_1_359_12\n", yyseq);
 fprintf( yyfp, "zzzfile0:359_1_359_12-%d pa:timeStamp %d\n" , yyseq, yyseq);

info = -4.0;
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:360_1_360_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:360_1_360_10-%d pa:beforeStatement file0:360_1_360_10\n", yyseq);
 fprintf( yyfp, "zzzfile0:360_1_360_10-%d pa:timeStamp %d\n" , yyseq, yyseq);

 fprintf( yyfp, "zzzfile0:350_1_350_7 pa:hasState file0:350_1_350_7_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:350_1_350_7_state-%d pa:hasValue %d\n", yyseq, cdf);
 fprintf( yyfp, "zzzfile0:350_1_350_7_state-%d pa:atProgramPoint file0:357_1_361_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:349_1_349_7 pa:hasState file0:349_1_349_7_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:349_1_349_7_state-%d pa:hasValue %d\n", yyseq, rdf);
 fprintf( yyfp, "zzzfile0:349_1_349_7_state-%d pa:atProgramPoint file0:357_1_361_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:338_5_338_5 pa:hasState file0:338_5_338_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:hasValue %d\n", yyseq, r);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:atProgramPoint file0:357_1_361_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:357_1_361_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:341_6_341_8 pa:hasState file0:341_6_341_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:341_6_341_8_state-%d pa:hasValue %d\n", yyseq, pdf);
 fprintf( yyfp, "zzzfile0:341_6_341_8_state-%d pa:atProgramPoint file0:357_1_361_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:347_1_347_10 pa:hasState file0:347_1_347_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:347_1_347_10_state-%d pa:hasValue %f\n", yyseq, xi);
 fprintf( yyfp, "zzzfile0:347_1_347_10_state-%d pa:atProgramPoint file0:357_1_361_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:357_1_361_1-%d pa:beforeStatement file0:357_1_361_1\n", yyseq);
 fprintf( yyfp, "zzzfile0:357_1_361_1-%d pa:timeStamp %d\n" , yyseq, yyseq);

goto ret3;
}
if ( (xj = (double *)malloc( c * sizeof(double) )) == NULL )
{
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:364_1_364_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:339_5_339_5 pa:hasState file0:339_5_339_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:atProgramPoint file0:364_1_364_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:348_1_348_10 pa:hasState file0:348_1_348_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:348_1_348_10_state-%d pa:hasValue %f\n", yyseq, xj);
 fprintf( yyfp, "zzzfile0:348_1_348_10_state-%d pa:atProgramPoint file0:364_1_364_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:364_1_364_12-%d pa:beforeStatement file0:364_1_364_12\n", yyseq);
 fprintf( yyfp, "zzzfile0:364_1_364_12-%d pa:timeStamp %d\n" , yyseq, yyseq);

info = -4.0;
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:365_1_365_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:365_1_365_10-%d pa:beforeStatement file0:365_1_365_10\n", yyseq);
 fprintf( yyfp, "zzzfile0:365_1_365_10-%d pa:timeStamp %d\n" , yyseq, yyseq);

goto ret2;
}
/* compute row sums and total */
N = 0.0;
for ( i = 0; i < r; ++i )
{
 fprintf( yyfp, "zzzfile0:338_5_338_5 pa:hasState file0:338_5_338_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:hasValue %d\n", yyseq, r);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:atProgramPoint file0:371_1_371_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:343_1_343_5 pa:hasState file0:343_1_343_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:343_1_343_5_state-%d pa:hasValue %d\n", yyseq, i);
 fprintf( yyfp, "zzzfile0:343_1_343_5_state-%d pa:atProgramPoint file0:371_1_371_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:371_1_371_10-%d pa:beforeStatement file0:371_1_371_10\n", yyseq);
 fprintf( yyfp, "zzzfile0:371_1_371_10-%d pa:timeStamp %d\n" , yyseq, yyseq);

double sum = 0.0; /* accumulator */
 fprintf( yyfp, "zzzfile0:344_1_344_5 pa:hasState file0:344_1_344_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:hasValue %d\n", yyseq, j);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:atProgramPoint file0:372_21_372_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:339_5_339_5 pa:hasState file0:339_5_339_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:atProgramPoint file0:372_21_372_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:371_1_371_10 pa:hasState file0:371_1_371_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:371_1_371_10_state-%d pa:hasValue %f\n", yyseq, sum);
 fprintf( yyfp, "zzzfile0:371_1_371_10_state-%d pa:atProgramPoint file0:372_21_372_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:372_21_372_23-%d pa:beforeStatement file0:372_21_372_23\n", yyseq);
 fprintf( yyfp, "zzzfile0:372_21_372_23-%d pa:timeStamp %d\n" , yyseq, yyseq);

for ( j = 0; j < c; ++j )
{
 fprintf( yyfp, "zzzfile0:344_1_344_5 pa:hasState file0:344_1_344_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:hasValue %d\n", yyseq, j);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:atProgramPoint file0:374_1_374_6-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:339_5_339_5 pa:hasState file0:339_5_339_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:atProgramPoint file0:374_1_374_6-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:374_1_374_6-%d pa:beforeStatement file0:374_1_374_6\n", yyseq);
 fprintf( yyfp, "zzzfile0:374_1_374_6-%d pa:timeStamp %d\n" , yyseq, yyseq);

long k = f[(i)*c+(j)];
if ( k < 0L )
{
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:377_1_377_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:374_1_374_6 pa:hasState file0:374_1_374_6_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:374_1_374_6_state-%d pa:hasValue %li\n", yyseq, k);
 fprintf( yyfp, "zzzfile0:374_1_374_6_state-%d pa:atProgramPoint file0:377_1_377_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:377_1_377_12-%d pa:beforeStatement file0:377_1_377_12\n", yyseq);
 fprintf( yyfp, "zzzfile0:377_1_377_12-%d pa:timeStamp %d\n" , yyseq, yyseq);

info = -2.0;
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:378_1_378_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:378_1_378_10-%d pa:beforeStatement file0:378_1_378_10\n", yyseq);
 fprintf( yyfp, "zzzfile0:378_1_378_10-%d pa:timeStamp %d\n" , yyseq, yyseq);

 fprintf( yyfp, "zzzfile0:340_13_340_13 pa:hasState file0:340_13_340_13_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:340_13_340_13_state-%d pa:hasValue %li\n", yyseq, f);
 fprintf( yyfp, "zzzfile0:340_13_340_13_state-%d pa:atProgramPoint file0:375_1_379_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:375_1_379_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:344_1_344_5 pa:hasState file0:344_1_344_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:hasValue %d\n", yyseq, j);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:atProgramPoint file0:375_1_379_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:343_1_343_5 pa:hasState file0:343_1_343_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:343_1_343_5_state-%d pa:hasValue %d\n", yyseq, i);
 fprintf( yyfp, "zzzfile0:343_1_343_5_state-%d pa:atProgramPoint file0:375_1_379_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:374_1_374_6 pa:hasState file0:374_1_374_6_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:374_1_374_6_state-%d pa:hasValue %li\n", yyseq, k);
 fprintf( yyfp, "zzzfile0:374_1_374_6_state-%d pa:atProgramPoint file0:375_1_379_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:339_5_339_5 pa:hasState file0:339_5_339_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:atProgramPoint file0:375_1_379_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:340_13_340_13 pa:hasState file0:340_13_340_13_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:340_13_340_13_state-%d pa:hasValue %li\n", yyseq, f[(i)*c+(j)]);
 fprintf( yyfp, "zzzfile0:340_13_340_13_state-%d pa:atProgramPoint file0:375_1_379_1-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:375_1_379_1-%d pa:beforeStatement file0:375_1_379_1\n", yyseq);
 fprintf( yyfp, "zzzfile0:375_1_379_1-%d pa:timeStamp %d\n" , yyseq, yyseq);

goto ret1;
}
sum += (double)k;
}
N += xi[i] = sum;
}
if ( N <= 0.0 )
{
 fprintf( yyfp, "zzzfile0:345_1_345_8 pa:hasState file0:345_1_345_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:345_1_345_8_state-%d pa:hasValue %f\n", yyseq, N);
 fprintf( yyfp, "zzzfile0:345_1_345_8_state-%d pa:atProgramPoint file0:386_1_386_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:386_1_386_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:386_1_386_12-%d pa:beforeStatement file0:386_1_386_12\n", yyseq);
 fprintf( yyfp, "zzzfile0:386_1_386_12-%d pa:timeStamp %d\n" , yyseq, yyseq);

info = -1.0;
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:387_1_387_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:387_1_387_10-%d pa:beforeStatement file0:387_1_387_10\n", yyseq);
 fprintf( yyfp, "zzzfile0:387_1_387_10-%d pa:timeStamp %d\n" , yyseq, yyseq);

goto ret1;
}
/* compute column sums */
 fprintf( yyfp, "zzzfile0:344_1_344_5 pa:hasState file0:344_1_344_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:hasValue %d\n", yyseq, j);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:atProgramPoint file0:390_14_390_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:348_1_348_10 pa:hasState file0:348_1_348_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:348_1_348_10_state-%d pa:hasValue %f\n", yyseq, xj);
 fprintf( yyfp, "zzzfile0:348_1_348_10_state-%d pa:atProgramPoint file0:390_14_390_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:339_5_339_5 pa:hasState file0:339_5_339_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:atProgramPoint file0:390_14_390_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:348_1_348_10 pa:hasState file0:348_1_348_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:348_1_348_10_state-%d pa:hasValue %f\n", yyseq, xj[j]);
 fprintf( yyfp, "zzzfile0:348_1_348_10_state-%d pa:atProgramPoint file0:390_14_390_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:390_14_390_18-%d pa:beforeStatement file0:390_14_390_18\n", yyseq);
 fprintf( yyfp, "zzzfile0:390_14_390_18-%d pa:timeStamp %d\n" , yyseq, yyseq);

for ( j = 0; j < c; ++j )
{
 fprintf( yyfp, "zzzfile0:339_5_339_5 pa:hasState file0:339_5_339_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:atProgramPoint file0:392_1_392_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:344_1_344_5 pa:hasState file0:344_1_344_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:hasValue %d\n", yyseq, j);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:atProgramPoint file0:392_1_392_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:392_1_392_10-%d pa:beforeStatement file0:392_1_392_10\n", yyseq);
 fprintf( yyfp, "zzzfile0:392_1_392_10-%d pa:timeStamp %d\n" , yyseq, yyseq);

double sum = 0.0; /* accumulator */
for ( i = 0; i < r; ++i )
{
 fprintf( yyfp, "zzzfile0:343_1_343_5 pa:hasState file0:343_1_343_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:343_1_343_5_state-%d pa:hasValue %d\n", yyseq, i);
 fprintf( yyfp, "zzzfile0:343_1_343_5_state-%d pa:atProgramPoint file0:395_1_395_28-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:338_5_338_5 pa:hasState file0:338_5_338_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:hasValue %d\n", yyseq, r);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:atProgramPoint file0:395_1_395_28-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:395_1_395_28-%d pa:beforeStatement file0:395_1_395_28\n", yyseq);
 fprintf( yyfp, "zzzfile0:395_1_395_28-%d pa:timeStamp %d\n" , yyseq, yyseq);

sum += (double)f[(i)*c+(j)];
}

xj[j] = sum;
}
/* compute information measure (four parts) */
info = N * log( N ); /* part 1 */
 fprintf( yyfp, "zzzfile0:345_1_345_8 pa:hasState file0:345_1_345_8_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:345_1_345_8_state-%d pa:hasValue %f\n", yyseq, N);
 fprintf( yyfp, "zzzfile0:345_1_345_8_state-%d pa:atProgramPoint file0:402_7_402_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:343_1_343_5 pa:hasState file0:343_1_343_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:343_1_343_5_state-%d pa:hasValue %d\n", yyseq, i);
 fprintf( yyfp, "zzzfile0:343_1_343_5_state-%d pa:atProgramPoint file0:402_7_402_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:402_7_402_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:338_5_338_5 pa:hasState file0:338_5_338_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:hasValue %d\n", yyseq, r);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:atProgramPoint file0:402_7_402_12-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:402_7_402_12-%d pa:beforeStatement file0:402_7_402_12\n", yyseq);
 fprintf( yyfp, "zzzfile0:402_7_402_12-%d pa:timeStamp %d\n" , yyseq, yyseq);

for ( i = 0; i < r; ++i )
{
 fprintf( yyfp, "zzzfile0:338_5_338_5 pa:hasState file0:338_5_338_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:hasValue %d\n", yyseq, r);
 fprintf( yyfp, "zzzfile0:338_5_338_5_state-%d pa:atProgramPoint file0:404_1_404_9-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:343_1_343_5 pa:hasState file0:343_1_343_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:343_1_343_5_state-%d pa:hasValue %d\n", yyseq, i);
 fprintf( yyfp, "zzzfile0:343_1_343_5_state-%d pa:atProgramPoint file0:404_1_404_9-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:404_1_404_9-%d pa:beforeStatement file0:404_1_404_9\n", yyseq);
 fprintf( yyfp, "zzzfile0:404_1_404_9-%d pa:timeStamp %d\n" , yyseq, yyseq);

double pi = xi[i]; /* row sum */
if ( pi > 0.0 )
{
 fprintf( yyfp, "zzzfile0:404_1_404_9 pa:hasState file0:404_1_404_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:404_1_404_9_state-%d pa:hasValue %f\n", yyseq, pi);
 fprintf( yyfp, "zzzfile0:404_1_404_9_state-%d pa:atProgramPoint file0:407_1_407_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:407_1_407_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:407_1_407_23-%d pa:beforeStatement file0:407_1_407_23\n", yyseq);
 fprintf( yyfp, "zzzfile0:407_1_407_23-%d pa:timeStamp %d\n" , yyseq, yyseq);

info -= pi * log( pi );
}
/* part 2 */
 fprintf( yyfp, "zzzfile0:344_1_344_5 pa:hasState file0:344_1_344_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:hasValue %d\n", yyseq, j);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:atProgramPoint file0:410_14_410_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:339_5_339_5 pa:hasState file0:339_5_339_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:atProgramPoint file0:410_14_410_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:410_14_410_18-%d pa:beforeStatement file0:410_14_410_18\n", yyseq);
 fprintf( yyfp, "zzzfile0:410_14_410_18-%d pa:timeStamp %d\n" , yyseq, yyseq);

for ( j = 0; j < c; ++j )
{
 fprintf( yyfp, "zzzfile0:339_5_339_5 pa:hasState file0:339_5_339_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:atProgramPoint file0:412_1_412_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:344_1_344_5 pa:hasState file0:344_1_344_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:hasValue %d\n", yyseq, j);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:atProgramPoint file0:412_1_412_10-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:412_1_412_10-%d pa:beforeStatement file0:412_1_412_10\n", yyseq);
 fprintf( yyfp, "zzzfile0:412_1_412_10-%d pa:timeStamp %d\n" , yyseq, yyseq);

double pij = (double)f[(i)*c+(j)];
if ( pij > 0.0 )
{
 fprintf( yyfp, "zzzfile0:412_1_412_10 pa:hasState file0:412_1_412_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:412_1_412_10_state-%d pa:hasValue %f\n", yyseq, pij);
 fprintf( yyfp, "zzzfile0:412_1_412_10_state-%d pa:atProgramPoint file0:415_1_415_25-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:415_1_415_25-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:415_1_415_25-%d pa:beforeStatement file0:415_1_415_25\n", yyseq);
 fprintf( yyfp, "zzzfile0:415_1_415_25-%d pa:timeStamp %d\n" , yyseq, yyseq);

info += pij * log( pij );
}
/* part 3 */
}
}
 fprintf( yyfp, "zzzfile0:344_1_344_5 pa:hasState file0:344_1_344_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:hasValue %d\n", yyseq, j);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:atProgramPoint file0:420_14_420_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:339_5_339_5 pa:hasState file0:339_5_339_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:atProgramPoint file0:420_14_420_18-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:420_14_420_18-%d pa:beforeStatement file0:420_14_420_18\n", yyseq);
 fprintf( yyfp, "zzzfile0:420_14_420_18-%d pa:timeStamp %d\n" , yyseq, yyseq);

for ( j = 0; j < c; ++j )
{
 fprintf( yyfp, "zzzfile0:344_1_344_5 pa:hasState file0:344_1_344_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:hasValue %d\n", yyseq, j);
 fprintf( yyfp, "zzzfile0:344_1_344_5_state-%d pa:atProgramPoint file0:422_1_422_9-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:339_5_339_5 pa:hasState file0:339_5_339_5_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:hasValue %d\n", yyseq, c);
 fprintf( yyfp, "zzzfile0:339_5_339_5_state-%d pa:atProgramPoint file0:422_1_422_9-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:422_1_422_9-%d pa:beforeStatement file0:422_1_422_9\n", yyseq);
 fprintf( yyfp, "zzzfile0:422_1_422_9-%d pa:timeStamp %d\n" , yyseq, yyseq);

double pj = xj[j]; /* column sum */
if ( pj > 0.0 )
{
 fprintf( yyfp, "zzzfile0:422_1_422_9 pa:hasState file0:422_1_422_9_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:422_1_422_9_state-%d pa:hasValue %f\n", yyseq, pj);
 fprintf( yyfp, "zzzfile0:422_1_422_9_state-%d pa:atProgramPoint file0:425_1_425_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:425_1_425_23-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:425_1_425_23-%d pa:beforeStatement file0:425_1_425_23\n", yyseq);
 fprintf( yyfp, "zzzfile0:425_1_425_23-%d pa:timeStamp %d\n" , yyseq, yyseq);

info -= pj * log( pj );
}
/* part 4 */
}
info *= 2.0; /* for comparability with chi-square */
 fprintf( yyfp, "zzzfile0:346_1_346_11 pa:hasState file0:346_1_346_11_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:hasValue %f\n", yyseq, info);
 fprintf( yyfp, "zzzfile0:346_1_346_11_state-%d pa:atProgramPoint file0:430_1_430_5-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:430_1_430_5-%d pa:beforeStatement file0:430_1_430_5\n", yyseq);
 fprintf( yyfp, "zzzfile0:430_1_430_5-%d pa:timeStamp %d\n" , yyseq, yyseq);

ret1:
free( (pointer)xj );
 fprintf( yyfp, "zzzfile0:348_1_348_10 pa:hasState file0:348_1_348_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:348_1_348_10_state-%d pa:hasValue %f\n", yyseq, xj);
 fprintf( yyfp, "zzzfile0:348_1_348_10_state-%d pa:atProgramPoint file0:432_1_432_5-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:432_1_432_5-%d pa:beforeStatement file0:432_1_432_5\n", yyseq);
 fprintf( yyfp, "zzzfile0:432_1_432_5-%d pa:timeStamp %d\n" , yyseq, yyseq);

ret2:
free( (pointer)xi );
 fprintf( yyfp, "zzzfile0:347_1_347_10 pa:hasState file0:347_1_347_10_state-%d \n",yyseq);
 fprintf( yyfp, "zzzfile0:347_1_347_10_state-%d pa:hasValue %f\n", yyseq, xi);
 fprintf( yyfp, "zzzfile0:347_1_347_10_state-%d pa:atProgramPoint file0:434_1_434_5-%d\n", yyseq, yyseq);
yyseq = yyseq + 1;
 fprintf( yyfp, "zzzfile0:434_1_434_5-%d pa:beforeStatement file0:434_1_434_5\n", yyseq);
 fprintf( yyfp, "zzzfile0:434_1_434_5-%d pa:timeStamp %d\n" , yyseq, yyseq);

ret3:
return info;
}
