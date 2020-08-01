/*
	tot_info -- combine information statistics for multiple tables

	last edit:	89/02/06	D A Gwyn

	SCCS ID:	@(#)tot_info.c	1.1 (edited for publication)
*/

#include	<ctype.h>
#include	<stdio.h>


#ifndef	VLD_STD_H_
#define	VLD_STD_H_			/* once-only latch */

/* Extended data types */

typedef int	bool;			/* Boolean data */
#define 	false	0
#define 	true	1

/* ANSI C definitions */

/* Defense against some silly systems defining __STDC__ to random things. */
#ifdef STD_C
#undef STD_C
#endif
#ifdef __STDC__
#if __STDC__ > 0
#define	STD_C	__STDC__		/* use this instead of __STDC__ */
#endif
#endif

#ifdef STD_C
typedef void	*pointer;		/* generic pointer */
#else
typedef char	*pointer;		/* generic pointer */
#define	const		/* nothing */	/* ANSI C type qualifier */
/* There really is no substitute for the following, but these might work: */
#define	signed		/* nothing */	/* ANSI C type specifier */
#define	volatile	/* nothing */	/* ANSI C type qualifier */
#endif

#ifndef EXIT_SUCCESS
#define	EXIT_SUCCESS	0
#endif

#ifndef EXIT_FAILURE
#define	EXIT_FAILURE	1
#endif

#ifndef NULL
#define NULL	0			/* null pointer constant, all types */
#endif

/* Universal constants */

#define DEGRAD	57.2957795130823208767981548141051703324054724665642
					/* degrees per radian */
#define	E	2.71828182845904523536028747135266249775724709369996
					/* base of natural logs */
#define	GAMMA	0.57721566490153286061
					/* Euler's constant */
#define LOG10E	0.43429448190325182765112891891660508229439700580367
					/* log of e to the base 10 */
#define PHI	1.618033988749894848204586834365638117720309180
					/* golden ratio */
#define PI	3.14159265358979323846264338327950288419716939937511
					/* ratio of circumf. to diam. */

/* Useful macros */

/*
	The comment "UNSAFE" means that the macro argument(s) may be evaluated
	more than once, so the programmer must realize that the macro doesn't
	quite act like a genuine function.  This matters only when evaluating
	an argument produces "side effects".
*/

/* arbitrary numerical arguments and value: */
#define Abs( x )	((x) < 0 ? -(x) : (x))			/* UNSAFE */
#define Max( a, b )	((a) > (b) ? (a) : (b))			/* UNSAFE */
#define Min( a, b )	((a) < (b) ? (a) : (b))			/* UNSAFE */

/* floating-point arguments and value: */
#define Round( d )	(floor( (d) + 0.5 ))		/* requires <math.h> */

/* arbitrary numerical arguments, integer value: */
#define	Sgn( x )	((x) == 0 ? 0 : (x) > 0 ? 1 : -1)	/* UNSAFE */

/* string arguments, boolean value: */
#ifdef gould	/* UTX-32 2.0 compiler has problems with "..."[] */
#define	StrEq( a, b )	(strcmp( a, b ) == 0)			/* UNSAFE */
#else
#define	StrEq( a, b )	(*(a) == *(b) && strcmp( a, b ) == 0)	/* UNSAFE */
#endif

/* array argument, integer value: */
#define	Elements( a )	(sizeof a / sizeof a[0])

/* integer (or character) arguments and value: */
#define fromhostc( c )	(c)		/* map host char set to ASCII */
#define tohostc( c )	(c)		/* map ASCII to host char set */
#define tonumber( c )	((c) - '0')	/* convt digit char to number */
#define todigit( n )	((n) + '0')	/* convt digit number to char */

/* Kludges for deficient C implementations */

/*#define	strchr	index		/* 7th Edition UNIX, 4.2BSD */
/*#define	strrchr	rindex		/* 7th Edition UNIX, 4.2BSD */
/*#define	void	int		/* K&R Appendix A followers */

#endif	/* VLD_STD_H_ */


#ifdef __STDC__
extern double	ChiSqTbl( int r, int c, const long *f, int *pdf );
extern double	InfoTbl( int r, int c, const long *f, int *pdf );
#else
extern double	ChiSqTbl();
extern double	InfoTbl();
#endif

#ifdef __STDC__
extern double	Gamma( double z ), LGamma( double z ),
		Factorial( int n ), LFactorial( int n ),
		BCoeff( int n, int k ),
		Beta( double z, double w ),
		PGamma( double a, double x ), QGamma( double a, double x ),
		Erf( double x ), Erfc( double x ),
		CPoisson( double x, int k ),
		PChiSq( double chisq, int nu ), QChiSq( double chisq, int nu );
#else
extern double	Gamma(), LGamma(), Factorial(), LFactorial(),
		BCoeff(), Beta(), PGamma(), QGamma(), Erf(), Erfc(),
		CPoisson(), PChiSq(), QChiSq();
#endif


#define	MAXLINE	256


#ifndef MAXTBL
#define	MAXTBL	1000
#endif

static char	line[MAXLINE];		/* row/column header input line */
static long	f[MAXTBL];		/* frequency tallies */
static int	r;			/* # of rows */
static int	c;			/* # of columns */

#define	x(i,j)	f[(i)*c+(j)]		/* convenient way to access freqs */

#define	COMMENT	'#'			/* comment character */


#ifndef NULL
#define NULL 0
#endif

/*ARGSUSED*/
int
main( 
	int		argc,
	char		*argv[])
	{
	char	*p;		/* input line scan location */
	int	i;		/* row index */
	int	j;		/* column index */
	double		info;		/* computed information measure */
	int		infodf;		/* degrees of freedom for information */
	double		totinfo = 0.0;	/* accumulated information */
	int		totdf;	/* accumulated degrees of freedom */
 
        totdf = 0;

	while ( fgets( line, MAXLINE, stdin ) != NULL )	/* start new table */
		{
		for ( p = line; *p != '\0' && isspace( (int)*p ); ++p )
			;

		if ( *p == '\0' )
			continue;	/* skip blank line */

		if ( *p == COMMENT )
			{		/* copy comment through */
			(void)fputs( line, stdout );
			continue;
			}

		if ( sscanf( p, "%d %d\n", &r, &c ) != 2 )
			{
			(void)fputs( "* invalid row/column line *\n", stdout );
			return EXIT_FAILURE;
			}

		if ( r * c > MAXTBL )
			{
			(void)fputs( "* table too large *\n", stdout );
			return EXIT_FAILURE;
			}

		/* input tallies */

		for ( i = 0; i < r; ++i )
			for ( j = 0; j < c; ++j )
				if ( scanf( " %ld", &x(i,j) ) != 1 )
					{
					(void)fputs( "* EOF in table *\n",
						     stdout
						   );
					return EXIT_FAILURE;
					}

		/* compute statistic */

		info = InfoTbl( r, c, f, &infodf );

		/* print results */

		if ( info >= 0.0 )
			{
			(void)printf( "2info = %5.2f\tdf = %2d\tq = %7.4f\n",
				      info, infodf,
				      QChiSq( info, infodf )
				    );
			totinfo = info; /* removed + before = */
			totdf += infodf;
			}
		else
			(void)fputs( info < -3.5 ? "out of memory\n"
				   : info < -2.5 ? "table too small\n"
				   : info < -1.5 ? "negative freq\n"
				   : "table all zeros\n",
				     stdout
				   );
		}

	if ( totdf <= 0 )
		{
		(void)fputs( "\n*** no information accumulated ***\n", stdout );
		return EXIT_FAILURE;
		}

	(void)printf( "\ntotal 2info = %5.2f\tdf = %2d\tq = %7.4f\n",
		      totinfo, totdf,
		      QChiSq( totinfo, totdf )
		    );
	return EXIT_SUCCESS;
	}


/*  -*- Last-Edit:  Tue Dec 15 14:48:14 1992 by Tarak S. Goradia; -*- */

/*
	Gamma -- gamma and related functions

	last edit:	88/09/09	D A Gwyn

	SCCS ID:	@(#)gamma.c	1.1 (edited for publication)

Acknowledgement:
	Code based on that found in "Numerical Methods in C".
*/

#include	<math.h>
#include        <stdio.h>

//#include	"std.h"

double
LGamma( 
	double			x)
	{
	static const double	cof[6] =
		{
		76.18009173,	-86.50532033,	24.01409822,
		-1.231739516,	0.120858003e-2,	-0.536382e-5
		};
	double			tmp, ser;
	int		j;


	if ( --x < 0.0 )	/* use reflection formula for accuracy */
		{
		double	pix = PI * x;

		return log( pix / sin( pix ) ) - LGamma( 1.0 - x );
		}

	tmp = x + 5.5;
	tmp -= (x + 0.5) * log( tmp );

	ser = 1.0;

	for ( j = 0; j < 6; ++j )
		ser += cof[j] / ++x;

	return -tmp + log( 2.50662827465 * ser );
	}

#define	ITMAX	100
#define	EPS	3.0e-7

static double
gser( 
	double		a, double x)
	{
	double		ap, del, sum;
	int	n;


	if ( x <= 0.0 )
		return 0.0;

	del = sum = 1.0 / (ap = a);

	for ( n = 1; n <= ITMAX; ++n )
		{
		sum += del *= x / ++ap;

		if ( Abs( del ) < Abs( sum ) * EPS )
			return sum * exp( -x + a * log( x ) - LGamma( a ) );
		}

	/*NOTREACHED*/
	}

static double
gcf(
	double		a, double x)
	{
	int	n;
	double		gold = 0.0, fac = 1.0, b1 = 1.0,
			b0 = 0.0, a0 = 1.0, a1 = x;

	for ( n = 1; n <= ITMAX; ++n )
		{
		double	anf;
		double	an = (double)n;
		double	ana = an - a;

		a0 = (a1 + a0 * ana) * fac;
		b0 = (b1 + b0 * ana) * fac;
		anf = an * fac;
		b1 = x * b0 + anf * b1;
		a1 = x * a0 + anf * a1;

		if ( a1 != 0.0 )
			{		/* renormalize */
			double	g = b1 * (fac = 1.0 / a1);

			gold = g - gold;

			if ( Abs( gold ) < EPS * Abs( g ) )
				return exp( -x + a * log( x ) - LGamma( a ) ) * g;

			gold = g;
			}
		}

	/*NOTREACHED*/
	}

double
QGamma( 
	double	a, double x)
	{

	return x < a + 1.0 ? 1.0 - gser( a, x ) : gcf( a, x );
	}

double
QChiSq( 
	double	chisq,
	int	df)
	{
	return QGamma( (double)df / 2.0, chisq / 2.0 );
	}


/*
	InfoTbl -- Kullback's information measure for a 2-way contingency table

	last edit:	88/09/19	D A Gwyn

	SCCS ID:	@(#)info.c	1.1 (edited for publication)

	Special return values:
		-1.0	entire table consisted of 0 entries
		-2.0	invalid table entry (frequency less than 0)
		-3.0	invalid table dimensions (r or c less than 2)
		-4.0	unable to allocate enough working storage
*/

#include	<math.h>		/* for log() */
#if __STDC__
#include	<stdlib.h>		/* malloc, free */

//#include	"std.h"
//#else
//#include	"std.h"

extern pointer	malloc();
extern void	free();
#endif

#ifndef NULL
#define NULL 0
#endif

#define	x(i,j)	f[(i)*c+(j)]		/* convenient way to access freqs */

double
InfoTbl( 
	int		r,		/* # rows in table */
	int		c,		/* # columns in table */
	const long	*f,		/* -> r*c frequency tallies */
	int		*pdf)		/* -> return # d.f. for chi-square */
	{
	int	i;		/* row index */
	int	j;		/* column index */
	double		N;		/* (double)n */
	double		info;		/* accumulates information measure */
	double		*xi;		/* row sums */
	double		*xj;		/* col sums */
	int		rdf = r - 1;	/* row degrees of freedom */
	int		cdf = c - 1;	/* column degrees of freedom */

	if ( rdf <= 0 || cdf <= 0 )
		{
		info = -3.0;
		goto ret3;
		}

	*pdf = rdf * cdf;		/* total degrees of freedom */

	if ( (xi = (double *)malloc( r * sizeof(double) )) == NULL )
		{
		info = -4.0;
		goto ret3;
		}

	if ( (xj = (double *)malloc( c * sizeof(double) )) == NULL )
		{
		info = -4.0;
		goto ret2;
		}

	/* compute row sums and total */

	N = 0.0;

	for ( i = 0; i < r; ++i )
		{
		double	sum = 0.0;	/* accumulator */

		for ( j = 0; j < c; ++j )
			{
			long	k = x(i,j);

			if ( k < 0L )
				{
				info = -2.0;
				goto ret1;
				}

			sum += (double)k;
			}

		N += xi[i] = sum;
		}

	if ( N <= 0.0 )
		{
		info = -1.0;
		goto ret1;
		}

	/* compute column sums */

	for ( j = 0; j < c; ++j )
		{
		double	sum = 0.0;	/* accumulator */

		for ( i = 0; i < r; ++i )
			sum += (double)x(i,j);

		xj[j] = sum;
		}

	/* compute information measure (four parts) */

	info = N * log( N );					/* part 1 */

	for ( i = 0; i < r; ++i )
		{
		double	pi = xi[i];	/* row sum */

		if ( pi > 0.0 )
			info -= pi * log( pi );			/* part 2 */

		for ( j = 0; j < c; ++j )
			{
			double	pij = (double)x(i,j);

			if ( pij > 0.0 )
				info += pij * log( pij );	/* part 3 */
			}
		}

	for ( j = 0; j < c; ++j )
		{
		double	pj = xj[j];	/* column sum */

		if ( pj > 0.0 )
			info -= pj * log( pj );			/* part 4 */
		}

	info *= 2.0;			/* for comparability with chi-square */

    ret1:
	free( (pointer)xj );
    ret2:
	free( (pointer)xi );
    ret3:
	return info;
	}
