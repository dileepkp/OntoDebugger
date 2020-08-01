# 1 "flex_single_original.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "flex_single_original.c"
# 30 "flex_single_original.c"
char copyright[] =
"@(#) Copyright (c) 1990 The Regents of the University of California.\n All rights reserved.\n";






# 1 "flexdef.h" 1
# 31 "flexdef.h"
# 1 "/usr/include/stdio.h" 1 3 4
# 27 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/features.h" 1 3 4
# 367 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 1 3 4
# 410 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 411 "/usr/include/x86_64-linux-gnu/sys/cdefs.h" 2 3 4
# 368 "/usr/include/features.h" 2 3 4
# 391 "/usr/include/features.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 1 3 4
# 10 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/gnu/stubs-64.h" 1 3 4
# 11 "/usr/include/x86_64-linux-gnu/gnu/stubs.h" 2 3 4
# 392 "/usr/include/features.h" 2 3 4
# 28 "/usr/include/stdio.h" 2 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4

# 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 34 "/usr/include/stdio.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;







typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
# 121 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/typesizes.h" 1 3 4
# 122 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4


typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef int __key_t;


typedef int __clockid_t;


typedef void * __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;


typedef long int __fsword_t;

typedef long int __ssize_t;


typedef long int __syscall_slong_t;

typedef unsigned long int __syscall_ulong_t;



typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef long int __intptr_t;


typedef unsigned int __socklen_t;
# 36 "/usr/include/stdio.h" 2 3 4
# 44 "/usr/include/stdio.h" 3 4
struct _IO_FILE;



typedef struct _IO_FILE FILE;





# 64 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 74 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 31 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 15 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 16 "/usr/include/_G_config.h" 2 3 4




# 1 "/usr/include/wchar.h" 1 3 4
# 82 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {

    unsigned int __wch;



    char __wchb[4];
  } __value;
} __mbstate_t;
# 21 "/usr/include/_G_config.h" 2 3 4
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 32 "/usr/include/libio.h" 2 3 4
# 49 "/usr/include/libio.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h" 1 3 4
# 40 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 50 "/usr/include/libio.h" 2 3 4
# 144 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;





typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 173 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 241 "/usr/include/libio.h" 3 4
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 289 "/usr/include/libio.h" 3 4
  __off64_t _offset;







  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;

  size_t __pad5;
  int _mode;

  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 333 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
     size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);
# 385 "/usr/include/libio.h" 3 4
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
# 429 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));

extern int _IO_peekc_locked (_IO_FILE *__fp);





extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
# 459 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);

extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
# 75 "/usr/include/stdio.h" 2 3 4




typedef __gnuc_va_list va_list;
# 90 "/usr/include/stdio.h" 3 4
typedef __off_t off_t;
# 102 "/usr/include/stdio.h" 3 4
typedef __ssize_t ssize_t;







typedef _G_fpos_t fpos_t;




# 164 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/stdio_lim.h" 1 3 4
# 165 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));

extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));




extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));








extern FILE *tmpfile (void) ;
# 209 "/usr/include/stdio.h" 3 4
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;





extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;
# 227 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 252 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 266 "/usr/include/stdio.h" 3 4






extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes) ;




extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
# 295 "/usr/include/stdio.h" 3 4

# 306 "/usr/include/stdio.h" 3 4
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__)) ;
# 319 "/usr/include/stdio.h" 3 4
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) ;




extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__)) ;






extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));





extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));


extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));








extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);




extern int printf (const char *__restrict __format, ...);

extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));





extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);




extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);

extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));





extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

# 412 "/usr/include/stdio.h" 3 4
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));








extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;




extern int scanf (const char *__restrict __format, ...) ;

extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
# 443 "/usr/include/stdio.h" 3 4
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf")

                               ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf")
                              ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__))

                      ;
# 463 "/usr/include/stdio.h" 3 4








extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;





extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;


extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
# 494 "/usr/include/stdio.h" 3 4
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")



     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")

     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))



     __attribute__ ((__format__ (__scanf__, 2, 0)));
# 522 "/usr/include/stdio.h" 3 4









extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 550 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 561 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);











extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);





extern int putchar (int __c);

# 594 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream);


extern int putw (int __w, FILE *__stream);








extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
# 640 "/usr/include/stdio.h" 3 4

# 665 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;







extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;








extern int fputs (const char *__restrict __s, FILE *__restrict __stream);





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;




extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);

# 737 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream) ;




extern void rewind (FILE *__stream);

# 773 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream) ;
# 792 "/usr/include/stdio.h" 3 4






extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);




extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 815 "/usr/include/stdio.h" 3 4

# 824 "/usr/include/stdio.h" 3 4


extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;

extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;




extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;








extern void perror (const char *__s);






# 1 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 1 3 4
# 26 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern const char *const sys_errlist[];
# 854 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;




extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
# 872 "/usr/include/stdio.h" 3 4
extern FILE *popen (const char *__command, const char *__modes) ;





extern int pclose (FILE *__stream);





extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__));
# 912 "/usr/include/stdio.h" 3 4
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));



extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;


extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
# 942 "/usr/include/stdio.h" 3 4

# 32 "flexdef.h" 2
# 1 "/usr/include/ctype.h" 1 3 4
# 28 "/usr/include/ctype.h" 3 4

# 39 "/usr/include/ctype.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 36 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 2 3 4
# 60 "/usr/include/endian.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 29 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4






# 1 "/usr/include/x86_64-linux-gnu/bits/byteswap-16.h" 1 3 4
# 36 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 2 3 4
# 44 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
static __inline unsigned int
__bswap_32 (unsigned int __bsx)
{
  return __builtin_bswap32 (__bsx);
}
# 108 "/usr/include/x86_64-linux-gnu/bits/byteswap.h" 3 4
static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
# 61 "/usr/include/endian.h" 2 3 4
# 40 "/usr/include/ctype.h" 2 3 4






enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
# 79 "/usr/include/ctype.h" 3 4
extern const unsigned short int **__ctype_b_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_tolower_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern const __int32_t **__ctype_toupper_loc (void)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 104 "/usr/include/ctype.h" 3 4






extern int isalnum (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha (int) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit (int) __attribute__ ((__nothrow__ , __leaf__));
extern int islower (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint (int) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit (int) __attribute__ ((__nothrow__ , __leaf__));



extern int tolower (int __c) __attribute__ ((__nothrow__ , __leaf__));


extern int toupper (int __c) __attribute__ ((__nothrow__ , __leaf__));








extern int isblank (int) __attribute__ ((__nothrow__ , __leaf__));


# 150 "/usr/include/ctype.h" 3 4
extern int isascii (int __c) __attribute__ ((__nothrow__ , __leaf__));



extern int toascii (int __c) __attribute__ ((__nothrow__ , __leaf__));



extern int _toupper (int) __attribute__ ((__nothrow__ , __leaf__));
extern int _tolower (int) __attribute__ ((__nothrow__ , __leaf__));
# 257 "/usr/include/ctype.h" 3 4
# 1 "/usr/include/xlocale.h" 1 3 4
# 27 "/usr/include/xlocale.h" 3 4
typedef struct __locale_struct
{

  struct __locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;


typedef __locale_t locale_t;
# 258 "/usr/include/ctype.h" 2 3 4
# 271 "/usr/include/ctype.h" 3 4
extern int isalnum_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isalpha_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int iscntrl_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isdigit_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int islower_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isgraph_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isprint_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int ispunct_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isspace_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isupper_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));
extern int isxdigit_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));

extern int isblank_l (int, __locale_t) __attribute__ ((__nothrow__ , __leaf__));



extern int __tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int tolower_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));


extern int __toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern int toupper_l (int __c, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
# 347 "/usr/include/ctype.h" 3 4

# 33 "flexdef.h" 2

# 1 "config.h" 1
# 35 "flexdef.h" 2
# 51 "flexdef.h"
# 1 "/usr/include/string.h" 1 3 4
# 27 "/usr/include/string.h" 3 4





# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 33 "/usr/include/string.h" 2 3 4









extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));






extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));





extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 92 "/usr/include/string.h" 3 4
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 123 "/usr/include/string.h" 3 4


extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));

extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

# 162 "/usr/include/string.h" 3 4
extern int strcoll_l (const char *__s1, const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));

extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));




extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));






extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
# 206 "/usr/include/string.h" 3 4

# 231 "/usr/include/string.h" 3 4
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 258 "/usr/include/string.h" 3 4
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


# 277 "/usr/include/string.h" 3 4



extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 310 "/usr/include/string.h" 3 4
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 337 "/usr/include/string.h" 3 4
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));




extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
# 392 "/usr/include/string.h" 3 4


extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));





extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));

# 422 "/usr/include/string.h" 3 4
extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__))

                        __attribute__ ((__nonnull__ (2)));
# 440 "/usr/include/string.h" 3 4
extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));





extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));



extern void bcopy (const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 484 "/usr/include/string.h" 3 4
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
# 512 "/usr/include/string.h" 3 4
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));




extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 529 "/usr/include/string.h" 3 4
extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
# 552 "/usr/include/string.h" 3 4
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));




extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));


extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));



extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
# 658 "/usr/include/string.h" 3 4

# 52 "flexdef.h" 2





# 1 "/usr/include/x86_64-linux-gnu/sys/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4






typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;
# 60 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;
# 98 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __pid_t pid_t;





typedef __id_t id_t;
# 115 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 132 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 57 "/usr/include/time.h" 3 4


typedef __clock_t clock_t;



# 73 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 91 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 103 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 133 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4
# 146 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 147 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 194 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
# 219 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/sys/select.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/select.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/select.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 23 "/usr/include/x86_64-linux-gnu/bits/select.h" 2 3 4
# 31 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/bits/sigset.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/sigset.h" 3 4
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 34 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4



typedef __sigset_t sigset_t;





# 1 "/usr/include/time.h" 1 3 4
# 120 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    __syscall_slong_t tv_nsec;
  };
# 44 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4

# 1 "/usr/include/x86_64-linux-gnu/bits/time.h" 1 3 4
# 30 "/usr/include/x86_64-linux-gnu/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 46 "/usr/include/x86_64-linux-gnu/sys/select.h" 2 3 4


typedef __suseconds_t suseconds_t;





typedef long int __fd_mask;
# 64 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
typedef struct
  {






    __fd_mask __fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];


  } fd_set;






typedef __fd_mask fd_mask;
# 96 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4

# 106 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
# 118 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);
# 131 "/usr/include/x86_64-linux-gnu/sys/select.h" 3 4

# 220 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4


# 1 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 1 3 4
# 24 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 3 4


__extension__
extern unsigned int gnu_dev_major (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned int gnu_dev_minor (unsigned long long int __dev)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__
extern unsigned long long int gnu_dev_makedev (unsigned int __major,
            unsigned int __minor)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
# 58 "/usr/include/x86_64-linux-gnu/sys/sysmacros.h" 3 4

# 223 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4





typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 270 "/usr/include/x86_64-linux-gnu/sys/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 1 3 4
# 21 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 22 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 2 3 4
# 60 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
typedef unsigned long int pthread_t;


union pthread_attr_t
{
  char __size[56];
  long int __align;
};

typedef union pthread_attr_t pthread_attr_t;





typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
# 90 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
typedef union
{
  struct __pthread_mutex_s
  {
    int __lock;
    unsigned int __count;
    int __owner;

    unsigned int __nusers;



    int __kind;

    short __spins;
    short __elision;
    __pthread_list_t __list;
# 125 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
  } __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;




typedef union
{
  struct
  {
    int __lock;
    unsigned int __futex;
    __extension__ unsigned long long int __total_seq;
    __extension__ unsigned long long int __wakeup_seq;
    __extension__ unsigned long long int __woken_seq;
    void *__mutex;
    unsigned int __nwaiters;
    unsigned int __broadcast_seq;
  } __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;



typedef unsigned int pthread_key_t;



typedef int pthread_once_t;





typedef union
{

  struct
  {
    int __lock;
    unsigned int __nr_readers;
    unsigned int __readers_wakeup;
    unsigned int __writer_wakeup;
    unsigned int __nr_readers_queued;
    unsigned int __nr_writers_queued;
    int __writer;
    int __shared;
    signed char __rwelision;




    unsigned char __pad1[7];


    unsigned long int __pad2;


    unsigned int __flags;

  } __data;
# 220 "/usr/include/x86_64-linux-gnu/bits/pthreadtypes.h" 3 4
  char __size[56];
  long int __align;
} pthread_rwlock_t;

typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;





typedef volatile int pthread_spinlock_t;




typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;

typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;
# 271 "/usr/include/x86_64-linux-gnu/sys/types.h" 2 3 4



# 58 "flexdef.h" 2



# 1 "/usr/include/malloc.h" 1 3 4
# 23 "/usr/include/malloc.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 149 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4
typedef long int ptrdiff_t;
# 328 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4
typedef int wchar_t;
# 426 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
# 24 "/usr/include/malloc.h" 2 3 4
# 35 "/usr/include/malloc.h" 3 4



extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;


extern void *calloc (size_t __nmemb, size_t __size)
__attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;






extern void *realloc (void *__ptr, size_t __size)
__attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));


extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));


extern void cfree (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));


extern void *memalign (size_t __alignment, size_t __size)
__attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;


extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;



extern void *pvalloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;



extern void *(*__morecore) (ptrdiff_t __size);


extern void *__default_morecore (ptrdiff_t __size)
__attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__));



struct mallinfo
{
  int arena;
  int ordblks;
  int smblks;
  int hblks;
  int hblkhd;
  int usmblks;
  int fsmblks;
  int uordblks;
  int fordblks;
  int keepcost;
};


extern struct mallinfo mallinfo (void) __attribute__ ((__nothrow__ , __leaf__));
# 121 "/usr/include/malloc.h" 3 4
extern int mallopt (int __param, int __val) __attribute__ ((__nothrow__ , __leaf__));



extern int malloc_trim (size_t __pad) __attribute__ ((__nothrow__ , __leaf__));



extern size_t malloc_usable_size (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));


extern void malloc_stats (void) __attribute__ ((__nothrow__ , __leaf__));


extern int malloc_info (int __options, FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));


extern void *malloc_get_state (void) __attribute__ ((__nothrow__ , __leaf__));



extern int malloc_set_state (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));




extern void (*volatile __malloc_initialize_hook) (void)
__attribute__ ((__deprecated__));

extern void (*volatile __free_hook) (void *__ptr,
                                                   const void *)
__attribute__ ((__deprecated__));
extern void *(*volatile __malloc_hook)(size_t __size,
                                                     const void *)
__attribute__ ((__deprecated__));
extern void *(*volatile __realloc_hook)(void *__ptr,
                                                      size_t __size,
                                                      const void *)
__attribute__ ((__deprecated__));
extern void *(*volatile __memalign_hook)(size_t __alignment,
                                                       size_t __size,
                                                       const void *)
__attribute__ ((__deprecated__));
extern void (*volatile __after_morecore_hook) (void);


extern void __malloc_check_init (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__deprecated__));



# 62 "flexdef.h" 2



# 1 "/usr/include/stdlib.h" 1 3 4
# 32 "/usr/include/stdlib.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 33 "/usr/include/stdlib.h" 2 3 4








# 1 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 1 3 4
# 50 "/usr/include/x86_64-linux-gnu/bits/waitflags.h" 3 4
typedef enum
{
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;
# 42 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 1 3 4
# 66 "/usr/include/x86_64-linux-gnu/bits/waitstatus.h" 3 4
union wait
  {
    int w_status;
    struct
      {

 unsigned int __w_termsig:7;
 unsigned int __w_coredump:1;
 unsigned int __w_retcode:8;
 unsigned int:16;







      } __wait_terminated;
    struct
      {

 unsigned int __w_stopval:8;
 unsigned int __w_stopsig:8;
 unsigned int:16;






      } __wait_stopped;
  };
# 43 "/usr/include/stdlib.h" 2 3 4
# 67 "/usr/include/stdlib.h" 3 4
typedef union
  {
    union wait *__uptr;
    int *__iptr;
  } __WAIT_STATUS __attribute__ ((__transparent_union__));
# 95 "/usr/include/stdlib.h" 3 4


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;







__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;


# 139 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;




extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;

extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;





extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));




__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

# 305 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;


extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
# 321 "/usr/include/stdlib.h" 3 4
extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));


extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));





extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));



extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));

extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));






extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));

extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));




extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));







extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;

  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));









extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;

extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;










extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));

extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));




extern void cfree (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));



# 1 "/usr/include/alloca.h" 1 3 4
# 24 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 25 "/usr/include/alloca.h" 2 3 4







extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));






# 493 "/usr/include/stdlib.h" 2 3 4





extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;




extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (2))) ;




extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));







extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));





extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));







extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));






extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;

# 578 "/usr/include/stdlib.h" 3 4
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));





extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));






extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
# 606 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
# 619 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
# 641 "/usr/include/stdlib.h" 3 4
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
# 662 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 711 "/usr/include/stdlib.h" 3 4





extern int system (const char *__command) ;

# 733 "/usr/include/stdlib.h" 3 4
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;






typedef int (*__compar_fn_t) (const void *, const void *);
# 751 "/usr/include/stdlib.h" 3 4



extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;







extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
# 774 "/usr/include/stdlib.h" 3 4
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;



__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;







extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;




__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;

# 811 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;




extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));

extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));






extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));


extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));

extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));








extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
# 898 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
# 950 "/usr/include/stdlib.h" 3 4
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


# 1 "/usr/include/x86_64-linux-gnu/bits/stdlib-float.h" 1 3 4
# 955 "/usr/include/stdlib.h" 2 3 4
# 967 "/usr/include/stdlib.h" 3 4

# 66 "flexdef.h" 2
# 323 "flexdef.h"

# 323 "flexdef.h"
struct hash_entry
 {
 struct hash_entry *prev, *next;
 char *name;
 char *str_val;
 int int_val;
 } ;

typedef struct hash_entry **hash_table;





extern struct hash_entry *ndtbl[101];
extern struct hash_entry *sctbl[101];
extern struct hash_entry *ccltab[101];
# 387 "flexdef.h"
extern int printstats, syntaxerror, eofseen, ddebug, trace, nowarn, spprdflt;
extern int interactive, caseins, lex_compat, do_yylineno;
extern int useecs, fulltbl, usemecs, fullspd;
extern int gen_line_dirs, performance_report, backing_up_report;
extern int C_plus_plus, long_align, use_read, yytext_is_array, do_yywrap;
extern int csize;
extern int yymore_used, reject, real_reject, continued_action, in_rule;

extern int yymore_really_used, reject_really_used;
# 430 "flexdef.h"
extern int datapos, dataline, linenum, out_linenum;
extern FILE *skelfile, *yyin, *backing_up_file;
extern const char *skel[];
extern int skel_ind;
extern char *infilename, *outfilename;
extern int did_outfilename;
extern char *prefix, *yyclass;
extern int do_stdinit, use_stdout;
extern char **input_files;
extern int num_input_files;
extern char *program_name;

extern char *action_array;
extern int action_size;
extern int defs1_offset, prolog_offset, action_offset, action_index;
# 455 "flexdef.h"
extern int onestate[500], onesym[500];
extern int onenext[500], onedef[500], onesp;
# 488 "flexdef.h"
extern int current_mns, current_max_rules;
extern int num_rules, num_eof_rules, default_rule, lastnfa;
extern int *firstst, *lastst, *finalst, *transchar, *trans1, *trans2;
extern int *accptnum, *assoc_rule, *state_type;
extern int *rule_type, *rule_linenum, *rule_useful;
# 502 "flexdef.h"
extern int current_state_type;
# 511 "flexdef.h"
extern int variable_trailing_context_rules;
# 526 "flexdef.h"
extern int numtemps, numprots, protprev[50], protnext[50], prottbl[50];
extern int protcomst[50], firstprot, lastprot, protsave[2000];
# 545 "flexdef.h"
extern int numecs, nextecm[256 + 1], ecgroup[256 + 1], nummecs;






extern int tecfwd[256 + 1], tecbck[256 + 1];
# 565 "flexdef.h"
extern int lastsc, *scset, *scbol, *scxclu, *sceof;
extern int current_max_scs;
extern char **scname;
# 600 "flexdef.h"
extern int current_max_dfa_size, current_max_xpairs;
extern int current_max_template_xpairs, current_max_dfas;
extern int lastdfa, *nxt, *chk, *tnxt;
extern int *base, *def, *nultrans, NUL_ec, tblend, firstfree, **dss, *dfasiz;
extern union dfaacc_union
 {
 int *dfaacc_set;
 int dfaacc_state;
 } *dfaacc;
extern int *accsiz, *dhash, numas;
extern int numsnpairs, jambase, jamstate;
extern int end_of_buffer_state;
# 625 "flexdef.h"
extern int lastccl, *cclmap, *ccllen, *cclng, cclreuse;
extern int current_maxccls, current_max_ccl_tbl_size;
extern unsigned char *ccltbl;
# 650 "flexdef.h"
extern char nmstr[2048];
extern int sectnum, nummt, hshcol, dfaeql, numeps, eps2, num_reallocs;
extern int tmpuses, totnst, peakpairs, numuniq, numdup, hshsave;
extern int num_backing_up, bol_needed;

void *allocate_array (int, size_t);
void *reallocate_array (void*, int, size_t);

void *flex_alloc (size_t);
void *flex_realloc (void*, size_t);
void flex_free (void*);
# 704 "flexdef.h"
extern int yylval;







extern void ccladd (int, int);
extern int cclinit (void);
extern void cclnegate (int);


extern void list_character_set (FILE*, int[]);





extern void check_for_backing_up (int, int[]);


extern void check_trailing_context (int*, int, int*, int);


extern int *epsclosure (int*, int*, int[], int*, int*);


extern void increase_max_dfas (void);

extern void ntod (void);


extern int snstods (int[], int, int[], int, int, int*);





extern void ccl2ecl (void);


extern int cre8ecs (int[], int[], int);


extern void mkeccl (unsigned char[], int, int[], int[], int, int);


extern void mkechar (int, int[], int[]);




extern void do_indent (void);


extern void gen_backing_up (void);


extern void gen_bu_action (void);


extern void genctbl (void);


extern void gen_find_action (void);

extern void genftbl (void);


extern void gen_next_compressed_state (char*);


extern void gen_next_match (void);


extern void gen_next_state (int);


extern void gen_NUL_trans (void);


extern void gen_start_state (void);


extern void gentabs (void);


extern void indent_put2s (char[], char[]);


extern void indent_puts (char[]);

extern void make_tables (void);




extern void check_options (void);
extern void flexend (int);
extern void usage (void);





extern void action_define ( char *defname, int value );


extern void add_action ( char *new_text );


extern int all_lower (register char *);


extern int all_upper (register char *);


extern void bubble (int [], int);


extern void check_char (int c);


extern unsigned char clower (int);


extern char *copy_string (register const char *);


extern unsigned char *copy_unsigned_string (register unsigned char *);


extern void cshell (unsigned char [], int, int);


extern void dataend (void);


extern void dataflush (void);


extern void flexerror (const char[]);


extern void flexfatal (const char[]);


extern int htoi (unsigned char[]);


extern void lerrif (const char[], int);


extern void lerrsf (const char[], const char[]);


extern void line_directive_out (FILE*, int);




extern void mark_defs1 (void);


extern void mark_prolog (void);


extern void mk2data (int);

extern void mkdata (int);


extern int myctoi (char []);


extern unsigned char myesc (unsigned char[]);


extern int otoi (unsigned char [] );


extern void out (const char []);
extern void out_dec (const char [], int);
extern void out_dec2 (const char [], int, int);
extern void out_hex (const char [], unsigned int);
extern void out_line_count (const char []);
extern void out_str (const char [], const char []);
extern void out_str3
 (const char [], const char [], const char [], const char []);
extern void out_str_dec (const char [], const char [], int);
extern void outc (int);
extern void outn (const char []);




extern char *readable_form (int);


extern void skelout (void);


extern void transition_struct_out (int, int);


extern void *yy_flex_xmalloc ( int );


extern void zero_out (char *, size_t);





extern void add_accept (int, int);


extern int copysingl (int, int);


extern void dumpnfa (int);


extern void finish_rule (int, int, int, int);


extern int link_machines (int, int);




extern void mark_beginning_as_normal (register int);


extern int mkbranch (int, int);

extern int mkclos (int);
extern int mkopt (int);


extern int mkor (int, int);


extern int mkposcl (int);

extern int mkrep (int, int, int);


extern int mkstate (int);

extern void new_rule (void);





extern void build_eof_action (void);


extern void format_pinpoint_message (char[], char[]);


extern void pinpoint_message (char[]);


extern void line_warning ( char[], int );


extern void line_pinpoint ( char[], int );


extern void format_synerr (char [], char[]);
extern void synerr (char []);
extern void format_warn (char [], char[]);
extern void warn (char []);
extern void yyerror (char []);
extern int yyparse (void);





extern int flexscan (void);


extern void set_input_file (char*);


extern int yywrap (void);





extern int addsym (register char[], char*, int, hash_table, int);


extern void cclinstal (unsigned char [], int);


extern int ccllookup (unsigned char []);


extern struct hash_entry *findsym (register char[], hash_table, int );

extern void ndinstal (char[], unsigned char[]);
extern unsigned char *ndlookup (char[]);


extern void scextend (void);
extern void scinstal (char[], int);


extern int sclookup (char[]);





extern void bldtbl (int[], int, int, int, int);

extern void cmptmps (void);
extern void expand_nxt_chk (void);

extern int find_table_space (int*, int);
extern void inittbl (void);

extern void mkdeftbl (void);




extern void mk1tbl (int, int, int, int);


extern void place_state (int*, int, int);


extern void stack1 (int, int, int, int);




extern int yylex (void);
# 39 "flex_single_original.c" 2
# 1 "version.h" 1
# 40 "flex_single_original.c" 2

# 1 "parse.h" 1
# 30 "parse.h"
extern int yylval;
# 42 "flex_single_original.c" 2
# 1 "FaultSeeds.h" 1
# 43 "flex_single_original.c" 2

static char flex_version[] = "2.5.3";




void flexinit (int, char**);
void readin (void);
void set_up_initial_allocations (void);







int printstats, syntaxerror, eofseen, ddebug, trace, nowarn, spprdflt;
int interactive, caseins, lex_compat, do_yylineno, useecs, fulltbl, usemecs;
int fullspd, gen_line_dirs, performance_report, backing_up_report;
int C_plus_plus, long_align, use_read, yytext_is_array, do_yywrap, csize;
int yymore_used, reject, real_reject, continued_action, in_rule;
int yymore_really_used, reject_really_used;
int datapos, dataline, linenum, out_linenum;
FILE *skelfile = 
# 66 "flex_single_original.c" 3 4
                ((void *)0)
# 66 "flex_single_original.c"
                    ;


FILE *err = 
# 69 "flex_single_original.c" 3 4
           ((void *)0)
# 69 "flex_single_original.c"
               ;


int skel_ind = 0;
char *action_array;
int action_size, defs1_offset, prolog_offset, action_offset, action_index;
char *infilename = 
# 75 "flex_single_original.c" 3 4
                  ((void *)0)
# 75 "flex_single_original.c"
                      , *outfilename = 
# 75 "flex_single_original.c" 3 4
                                       ((void *)0)
# 75 "flex_single_original.c"
                                           ;
int did_outfilename;
char *prefix, *yyclass;
int do_stdinit, use_stdout;
int onestate[500], onesym[500];
int onenext[500], onedef[500], onesp;
int current_mns, current_max_rules;
int num_rules, num_eof_rules, default_rule, lastnfa;
int *firstst, *lastst, *finalst, *transchar, *trans1, *trans2;
int *accptnum, *assoc_rule, *state_type;
int *rule_type, *rule_linenum, *rule_useful;
int current_state_type;
int variable_trailing_context_rules;
int numtemps, numprots, protprev[50], protnext[50], prottbl[50];
int protcomst[50], firstprot, lastprot, protsave[2000];
int numecs, nextecm[256 + 1], ecgroup[256 + 1], nummecs, tecfwd[256 + 1];
int tecbck[256 + 1];
int lastsc, *scset, *scbol, *scxclu, *sceof;
int current_max_scs;
char **scname;
int current_max_dfa_size, current_max_xpairs;
int current_max_template_xpairs, current_max_dfas;
int lastdfa, *nxt, *chk, *tnxt;
int *base, *def, *nultrans, NUL_ec, tblend, firstfree, **dss, *dfasiz;
union dfaacc_union *dfaacc;
int *accsiz, *dhash, numas;
int numsnpairs, jambase, jamstate;
int lastccl, *cclmap, *ccllen, *cclng, cclreuse;
int current_maxccls, current_max_ccl_tbl_size;
unsigned char *ccltbl;
char nmstr[2048];
int sectnum, nummt, hshcol, dfaeql, numeps, eps2, num_reallocs;
int tmpuses, totnst, peakpairs, numuniq, numdup, hshsave;
int num_backing_up, bol_needed;
FILE *backing_up_file;
int end_of_buffer_state;
char **input_files;
int num_input_files;




char *program_name = "flex";


static char *outfile_template = "lex.%s.%s";
static char *backing_name = "lex.backup";
# 135 "flex_single_original.c"
static char outfile_path[2048];
static int outfile_created = 0;
static char *skelname = 
# 137 "flex_single_original.c" 3 4
                       ((void *)0)
# 137 "flex_single_original.c"
                           ;


int main( argc, argv )
int argc;
char **argv;
 {
 int i;
# 154 "flex_single_original.c"
        if(--argc >0){
                err = fopen( *++argv, "w" );
                --argv; ++argc;
        }


 flexinit( argc, argv );

 readin();

 ntod();

 for ( i = 1; i <= num_rules; ++i )
  if ( ! rule_useful[i] && i != default_rule )
   line_warning( ("rule cannot be matched"),
     rule_linenum[i] );

 if ( spprdflt && ! reject && rule_useful[default_rule] )
  line_warning(
   ("-s option given but default rule can be matched"),
   rule_linenum[default_rule] );


 make_tables();




 flexend( 0 );

 return 0;
 }




void check_options()
 {
 int i;

 if ( lex_compat )
  {
  if ( C_plus_plus )
   flexerror( ("Can't use -+ with -l option") );

  if ( fulltbl || fullspd )
   flexerror( ("Can't use -f or -F with -l option") );




  yymore_really_used = reject_really_used = 1;

  yytext_is_array = 1;
  do_yylineno = 1;
  use_read = 0;
  }

 if ( do_yylineno )

  reject_really_used = 1;

 if ( csize == -1 )
  {
  if ( (fulltbl || fullspd) && ! useecs )
   csize = 128;
  else
   csize = 256;
  }

 if ( interactive == -1 )
  {
  if ( fulltbl || fullspd )
   interactive = 0;
  else
   interactive = 1;
  }

 if ( fulltbl || fullspd )
  {
  if ( usemecs )
   flexerror(
   ("-Cf/-CF and -Cm don't make sense together") );

  if ( interactive )
   flexerror( ("-Cf/-CF and -I are incompatible") );

  if ( lex_compat )
   flexerror(
  ("-Cf/-CF are incompatible with lex-compatibility mode") );

  if ( do_yylineno )
   flexerror(
   ("-Cf/-CF and %option yylineno are incompatible") );

  if ( fulltbl && fullspd )
   flexerror( ("-Cf and -CF are mutually exclusive") );
  }

 if ( C_plus_plus && fullspd )
  flexerror( ("Can't use -+ with -CF option") );

 if ( C_plus_plus && yytext_is_array )
  {
  warn( ("%array incompatible with -+ option") );
  yytext_is_array = 0;
  }

 if ( useecs )
  {




  ecgroup[1] = 0;

  for ( i = 2; i <= csize; ++i )
   {
   ecgroup[i] = i - 1;
   nextecm[i - 1] = i;
   }

  nextecm[csize] = 0;
  }

 else
  {

  for ( i = 1; i <= csize; ++i )
   {
   ecgroup[i] = i;
   nextecm[i] = -32767;
   }
  }

 if ( ! use_stdout )
  {
  FILE *prev_stdout;

  if ( ! did_outfilename )
   {
   char *suffix;

   if ( C_plus_plus )
    suffix = "cc";
   else
    suffix = "c";

   sprintf( outfile_path, outfile_template,
    prefix, suffix );

   outfilename = outfile_path;
   }

  prev_stdout = freopen( outfilename, "w", 
# 308 "flex_single_original.c" 3 4
                                          stdout 
# 308 "flex_single_original.c"
                                                 );

  if ( prev_stdout == 
# 310 "flex_single_original.c" 3 4
                     ((void *)0) 
# 310 "flex_single_original.c"
                          )
   lerrsf( ("could not create %s"), outfilename );

  outfile_created = 1;
  }

 if ( skelname && (skelfile = fopen( skelname, "r" )) == 
# 316 "flex_single_original.c" 3 4
                                                        ((void *)0) 
# 316 "flex_single_original.c"
                                                             )
  lerrsf( ("can't open skeleton file %s"), skelname );

 if ( strcmp( prefix, "yy" ) )
  {

  if ( C_plus_plus )
   out_str3( "#define yy%s %s%s\n", "FlexLexer", prefix, "FlexLexer" );
  else
   {
   out_str3( "#define yy%s %s%s\n", "_create_buffer", prefix, "_create_buffer" );
   out_str3( "#define yy%s %s%s\n", "_delete_buffer", prefix, "_delete_buffer" );
   out_str3( "#define yy%s %s%s\n", "_scan_buffer", prefix, "_scan_buffer" );
   out_str3( "#define yy%s %s%s\n", "_scan_string", prefix, "_scan_string" );
   out_str3( "#define yy%s %s%s\n", "_scan_bytes", prefix, "_scan_bytes" );
   out_str3( "#define yy%s %s%s\n", "_flex_debug", prefix, "_flex_debug" );
   out_str3( "#define yy%s %s%s\n", "_init_buffer", prefix, "_init_buffer" );
   out_str3( "#define yy%s %s%s\n", "_flush_buffer", prefix, "_flush_buffer" );
   out_str3( "#define yy%s %s%s\n", "_load_buffer_state", prefix, "_load_buffer_state" );
   out_str3( "#define yy%s %s%s\n", "_switch_to_buffer", prefix, "_switch_to_buffer" );
   out_str3( "#define yy%s %s%s\n", "in", prefix, "in" );
   out_str3( "#define yy%s %s%s\n", "leng", prefix, "leng" );
   out_str3( "#define yy%s %s%s\n", "lex", prefix, "lex" );
   out_str3( "#define yy%s %s%s\n", "out", prefix, "out" );
   out_str3( "#define yy%s %s%s\n", "restart", prefix, "restart" );
   out_str3( "#define yy%s %s%s\n", "text", prefix, "text" );

   if ( do_yylineno )
    out_str3( "#define yy%s %s%s\n", "lineno", prefix, "lineno" );
   }

  if ( do_yywrap )
   out_str3( "#define yy%s %s%s\n", "wrap", prefix, "wrap" );

  outn( "" );
  }

 if ( did_outfilename )
  line_directive_out( 
# 354 "flex_single_original.c" 3 4
                     stdout
# 354 "flex_single_original.c"
                           , 0 );

 skelout();
 }
# 366 "flex_single_original.c"
void flexend( exit_status )
int exit_status;

 {
 int tblsiz;
 int unlink();

 if ( skelfile != 
# 373 "flex_single_original.c" 3 4
                 ((void *)0) 
# 373 "flex_single_original.c"
                      )
  {
  if ( ferror( skelfile ) )
   lerrsf( ("input error reading skeleton file %s"),
    skelname );

  else if ( fclose( skelfile ) )
   lerrsf( ("error closing skeleton file %s"),
    skelname );
  }

 if ( exit_status != 0 && outfile_created )
  {
  if ( ferror( 
# 386 "flex_single_original.c" 3 4
              stdout 
# 386 "flex_single_original.c"
                     ) )
   lerrsf( ("error writing output file %s"),
    outfilename );

  else if ( fclose( 
# 390 "flex_single_original.c" 3 4
                   stdout 
# 390 "flex_single_original.c"
                          ) )
   lerrsf( ("error closing output file %s"),
    outfilename );

  else if ( unlink( outfilename ) )
   lerrsf( ("error deleting output file %s"),
    outfilename );
  }

 if ( backing_up_report && backing_up_file )
  {
  if ( num_backing_up == 0 )
   fprintf( backing_up_file, ("No backing up.\n") );
  else if ( fullspd || fulltbl )
   fprintf( backing_up_file,
    ("%d backing up (non-accepting) states.\n"),
    num_backing_up );
  else
   fprintf( backing_up_file,
    ("Compressed tables always back up.\n") );

  if ( ferror( backing_up_file ) )
   lerrsf( ("error writing backup file %s"),
    backing_name );

  else if ( fclose( backing_up_file ) )
   lerrsf( ("error closing backup file %s"),
    backing_name );
  }

 if ( printstats )
  {
  fprintf( err, ("%s version %s usage statistics:\n"),
   program_name, flex_version );

  fprintf( err, ("  scanner options: -") );

  if ( C_plus_plus )
   
# 428 "flex_single_original.c" 3 4
  _IO_putc (
# 428 "flex_single_original.c"
  '+'
# 428 "flex_single_original.c" 3 4
  , 
# 428 "flex_single_original.c"
  err
# 428 "flex_single_original.c" 3 4
  )
# 428 "flex_single_original.c"
                  ;
  if ( backing_up_report )
   
# 430 "flex_single_original.c" 3 4
  _IO_putc (
# 430 "flex_single_original.c"
  'b'
# 430 "flex_single_original.c" 3 4
  , 
# 430 "flex_single_original.c"
  err
# 430 "flex_single_original.c" 3 4
  )
# 430 "flex_single_original.c"
                  ;
  if ( ddebug )
   
# 432 "flex_single_original.c" 3 4
  _IO_putc (
# 432 "flex_single_original.c"
  'd'
# 432 "flex_single_original.c" 3 4
  , 
# 432 "flex_single_original.c"
  err
# 432 "flex_single_original.c" 3 4
  )
# 432 "flex_single_original.c"
                  ;
  if ( caseins )
   
# 434 "flex_single_original.c" 3 4
  _IO_putc (
# 434 "flex_single_original.c"
  'i'
# 434 "flex_single_original.c" 3 4
  , 
# 434 "flex_single_original.c"
  err
# 434 "flex_single_original.c" 3 4
  )
# 434 "flex_single_original.c"
                  ;
  if ( lex_compat )
   
# 436 "flex_single_original.c" 3 4
  _IO_putc (
# 436 "flex_single_original.c"
  'l'
# 436 "flex_single_original.c" 3 4
  , 
# 436 "flex_single_original.c"
  err
# 436 "flex_single_original.c" 3 4
  )
# 436 "flex_single_original.c"
                  ;
  if ( performance_report > 0 )
   
# 438 "flex_single_original.c" 3 4
  _IO_putc (
# 438 "flex_single_original.c"
  'p'
# 438 "flex_single_original.c" 3 4
  , 
# 438 "flex_single_original.c"
  err
# 438 "flex_single_original.c" 3 4
  )
# 438 "flex_single_original.c"
                  ;
  if ( performance_report > 1 )
   
# 440 "flex_single_original.c" 3 4
  _IO_putc (
# 440 "flex_single_original.c"
  'p'
# 440 "flex_single_original.c" 3 4
  , 
# 440 "flex_single_original.c"
  err
# 440 "flex_single_original.c" 3 4
  )
# 440 "flex_single_original.c"
                  ;
  if ( spprdflt )
   
# 442 "flex_single_original.c" 3 4
  _IO_putc (
# 442 "flex_single_original.c"
  's'
# 442 "flex_single_original.c" 3 4
  , 
# 442 "flex_single_original.c"
  err
# 442 "flex_single_original.c" 3 4
  )
# 442 "flex_single_original.c"
                  ;
  if ( use_stdout )
   
# 444 "flex_single_original.c" 3 4
  _IO_putc (
# 444 "flex_single_original.c"
  't'
# 444 "flex_single_original.c" 3 4
  , 
# 444 "flex_single_original.c"
  err
# 444 "flex_single_original.c" 3 4
  )
# 444 "flex_single_original.c"
                  ;
  if ( printstats )
   
# 446 "flex_single_original.c" 3 4
  _IO_putc (
# 446 "flex_single_original.c"
  'v'
# 446 "flex_single_original.c" 3 4
  , 
# 446 "flex_single_original.c"
  err
# 446 "flex_single_original.c" 3 4
  )
# 446 "flex_single_original.c"
                  ;
  if ( nowarn )
   
# 448 "flex_single_original.c" 3 4
  _IO_putc (
# 448 "flex_single_original.c"
  'w'
# 448 "flex_single_original.c" 3 4
  , 
# 448 "flex_single_original.c"
  err
# 448 "flex_single_original.c" 3 4
  )
# 448 "flex_single_original.c"
                  ;
  if ( interactive == 0 )
   
# 450 "flex_single_original.c" 3 4
  _IO_putc (
# 450 "flex_single_original.c"
  'B'
# 450 "flex_single_original.c" 3 4
  , 
# 450 "flex_single_original.c"
  err
# 450 "flex_single_original.c" 3 4
  )
# 450 "flex_single_original.c"
                  ;
  if ( interactive == 1 )
   
# 452 "flex_single_original.c" 3 4
  _IO_putc (
# 452 "flex_single_original.c"
  'I'
# 452 "flex_single_original.c" 3 4
  , 
# 452 "flex_single_original.c"
  err
# 452 "flex_single_original.c" 3 4
  )
# 452 "flex_single_original.c"
                  ;
  if ( ! gen_line_dirs )
   
# 454 "flex_single_original.c" 3 4
  _IO_putc (
# 454 "flex_single_original.c"
  'L'
# 454 "flex_single_original.c" 3 4
  , 
# 454 "flex_single_original.c"
  err
# 454 "flex_single_original.c" 3 4
  )
# 454 "flex_single_original.c"
                  ;
  if ( trace )
   
# 456 "flex_single_original.c" 3 4
  _IO_putc (
# 456 "flex_single_original.c"
  'T'
# 456 "flex_single_original.c" 3 4
  , 
# 456 "flex_single_original.c"
  err
# 456 "flex_single_original.c" 3 4
  )
# 456 "flex_single_original.c"
                  ;

  if ( csize == -1 )




   csize = 256;

  if ( csize == 128 )
   
# 466 "flex_single_original.c" 3 4
  _IO_putc (
# 466 "flex_single_original.c"
  '7'
# 466 "flex_single_original.c" 3 4
  , 
# 466 "flex_single_original.c"
  err
# 466 "flex_single_original.c" 3 4
  )
# 466 "flex_single_original.c"
                  ;
  else
   
# 468 "flex_single_original.c" 3 4
  _IO_putc (
# 468 "flex_single_original.c"
  '8'
# 468 "flex_single_original.c" 3 4
  , 
# 468 "flex_single_original.c"
  err
# 468 "flex_single_original.c" 3 4
  )
# 468 "flex_single_original.c"
                  ;

  fprintf( err, " -C" );

  if ( long_align )
   
# 473 "flex_single_original.c" 3 4
  _IO_putc (
# 473 "flex_single_original.c"
  'a'
# 473 "flex_single_original.c" 3 4
  , 
# 473 "flex_single_original.c"
  err
# 473 "flex_single_original.c" 3 4
  )
# 473 "flex_single_original.c"
                  ;
  if ( fulltbl )
   
# 475 "flex_single_original.c" 3 4
  _IO_putc (
# 475 "flex_single_original.c"
  'f'
# 475 "flex_single_original.c" 3 4
  , 
# 475 "flex_single_original.c"
  err
# 475 "flex_single_original.c" 3 4
  )
# 475 "flex_single_original.c"
                  ;
  if ( fullspd )
   
# 477 "flex_single_original.c" 3 4
  _IO_putc (
# 477 "flex_single_original.c"
  'F'
# 477 "flex_single_original.c" 3 4
  , 
# 477 "flex_single_original.c"
  err
# 477 "flex_single_original.c" 3 4
  )
# 477 "flex_single_original.c"
                  ;
  if ( useecs )
   
# 479 "flex_single_original.c" 3 4
  _IO_putc (
# 479 "flex_single_original.c"
  'e'
# 479 "flex_single_original.c" 3 4
  , 
# 479 "flex_single_original.c"
  err
# 479 "flex_single_original.c" 3 4
  )
# 479 "flex_single_original.c"
                  ;
  if ( usemecs )
   
# 481 "flex_single_original.c" 3 4
  _IO_putc (
# 481 "flex_single_original.c"
  'm'
# 481 "flex_single_original.c" 3 4
  , 
# 481 "flex_single_original.c"
  err
# 481 "flex_single_original.c" 3 4
  )
# 481 "flex_single_original.c"
                  ;
  if ( use_read )
   
# 483 "flex_single_original.c" 3 4
  _IO_putc (
# 483 "flex_single_original.c"
  'r'
# 483 "flex_single_original.c" 3 4
  , 
# 483 "flex_single_original.c"
  err
# 483 "flex_single_original.c" 3 4
  )
# 483 "flex_single_original.c"
                  ;

  if ( did_outfilename )
   fprintf( err, " -o%s", outfilename );

  if ( skelname )
   fprintf( err, " -S%s", skelname );

  if ( strcmp( prefix, "yy" ) )
   fprintf( err, " -P%s", prefix );

  
# 494 "flex_single_original.c" 3 4
 _IO_putc (
# 494 "flex_single_original.c"
 '\n'
# 494 "flex_single_original.c" 3 4
 , 
# 494 "flex_single_original.c"
 err
# 494 "flex_single_original.c" 3 4
 )
# 494 "flex_single_original.c"
                  ;

  fprintf( err, ("  %d/%d NFA states\n"),
   lastnfa, current_mns );
  fprintf( err, ("  %d/%d DFA states (%d words)\n"),
   lastdfa, current_max_dfas, totnst );
  fprintf( err, ("  %d rules\n"),
  num_rules + num_eof_rules - 1 );

  if ( num_backing_up == 0 )
   fprintf( err, ("  No backing up\n") );
  else if ( fullspd || fulltbl )
   fprintf( err,
   ("  %d backing-up (non-accepting) states\n"),
    num_backing_up );
  else
   fprintf( err,
    ("  Compressed tables always back-up\n") );

  if ( bol_needed )
   fprintf( err,
    ("  Beginning-of-line patterns used\n") );

  fprintf( err, ("  %d/%d start conditions\n"), lastsc,
   current_max_scs );
  fprintf( err,
   ("  %d epsilon states, %d double epsilon states\n"),
   numeps, eps2 );

  if ( lastccl == 0 )
   fprintf( err, ("  no character classes\n") );
  else
   fprintf( err,
("  %d/%d character classes needed %d/%d words of storage, %d reused\n"),
    lastccl, current_maxccls,
    cclmap[lastccl] + ccllen[lastccl],
    current_max_ccl_tbl_size, cclreuse );

  fprintf( err, ("  %d state/nextstate pairs created\n"),
   numsnpairs );
  fprintf( err, ("  %d/%d unique/duplicate transitions\n"),
   numuniq, numdup );

  if ( fulltbl )
   {
   tblsiz = lastdfa * numecs;
   fprintf( err, ("  %d table entries\n"), tblsiz );
   }

  else
   {
   tblsiz = 2 * (lastdfa + numtemps) + 2 * tblend;

   fprintf( err,
    ("  %d/%d base-def entries created\n"),
    lastdfa + numtemps, current_max_dfas );
   fprintf( err,
   ("  %d/%d (peak %d) nxt-chk entries created\n"),
    tblend, current_max_xpairs, peakpairs );
   fprintf( err,
  ("  %d/%d (peak %d) template nxt-chk entries created\n"),
    numtemps * nummecs,
    current_max_template_xpairs,
    numtemps * numecs );
   fprintf( err, ("  %d empty table entries\n"),
    nummt );
   fprintf( err, ("  %d protos created\n"),
    numprots );
   fprintf( err,
    ("  %d templates created, %d uses\n"),
    numtemps, tmpuses );
   }

  if ( useecs )
   {
   tblsiz = tblsiz + csize;
   fprintf( err,
    ("  %d/%d equivalence classes created\n"),
    numecs, csize );
   }

  if ( usemecs )
   {
   tblsiz = tblsiz + numecs;
   fprintf( err,
   ("  %d/%d meta-equivalence classes created\n"),
    nummecs, csize );
   }

  fprintf( err,
  ("  %d (%d saved) hash collisions, %d DFAs equal\n"),
   hshcol, hshsave, dfaeql );
  fprintf( err, ("  %d sets of reallocations needed\n"),
   num_reallocs );
  fprintf( err, ("  %d total table entries needed\n"),
   tblsiz );
  }

 exit( exit_status );
 }




void flexinit( argc, argv )
int argc;
char **argv;
 {
 int i, sawcmpflag;
 char *arg;

 printstats = syntaxerror = trace = spprdflt = caseins = 0;
 lex_compat = C_plus_plus = backing_up_report = ddebug = fulltbl = 0;
 fullspd = long_align = nowarn = yymore_used = continued_action = 0;
 do_yylineno = yytext_is_array = in_rule = reject = do_stdinit = 0;
 yymore_really_used = reject_really_used = -1;
 interactive = csize = -1;
 do_yywrap = gen_line_dirs = usemecs = useecs = 1;
 performance_report = 0;
 did_outfilename = 0;
 prefix = "yy";
 yyclass = 0;
 use_read = use_stdout = 0;

 sawcmpflag = 0;


 action_size = 2048;
 action_array = (char *) allocate_array( action_size, sizeof( char ) );
 defs1_offset = prolog_offset = action_offset = action_index = 0;
 action_array[0] = '\0';




        program_name = "Executable";

 if ( program_name[0] != '\0' &&
      program_name[strlen( program_name ) - 1] == '+' )
  C_plus_plus = 1;


        ++argv;--argc;



 for ( --argc, ++argv; argc ; --argc, ++argv )
  {
  arg = argv[0];

  if ( arg[0] != '-' || arg[1] == '\0' )
   break;

  if ( arg[1] == '-' )
   {
   if ( ! strcmp( arg, "--help" ) )
    arg = "-h";

   else if ( ! strcmp( arg, "--version" ) )
    arg = "-V";

   else if ( ! strcmp( arg, "--" ) )
    {
    --argc;
    ++argv;
    break;
    }
   }

  for ( i = 1; arg[i] != '\0'; ++i )
   switch ( arg[i] )
    {
    case '+':
     C_plus_plus = 1;
     break;

    case 'B':
     interactive = 0;
     break;

    case 'b':
     backing_up_report = 1;
     break;

    case 'c':
     break;

    case 'C':
     if ( i != 1 )
      flexerror(
    ("-C flag must be given separately") );

     if ( ! sawcmpflag )
      {
      useecs = 0;
      usemecs = 0;
      fulltbl = 0;
      sawcmpflag = 1;
      }

     for ( ++i; arg[i] != '\0'; ++i )
      switch ( arg[i] )
       {
       case 'a':
        long_align =
         1;
        break;

       case 'e':
        useecs = 1;
        break;

       case 'F':
        fullspd = 1;
        break;

       case 'f':
        fulltbl = 1;
        break;

       case 'm':
        usemecs = 1;
        break;

       case 'r':
        use_read = 1;
        break;

       default:
        lerrif(
      ("unknown -C option '%c'"),
        (int) arg[i] );
        break;
       }

     goto get_next_arg;

    case 'd':
     ddebug = 1;
     break;

    case 'f':
     useecs = usemecs = 0;
     use_read = fulltbl = 1;
     break;

    case 'F':
     useecs = usemecs = 0;
     use_read = fullspd = 1;
     break;

    case '?':
    case 'h':
     usage();
     exit( 0 );

    case 'I':
     interactive = 1;
     break;

    case 'i':
     caseins = 1;
     break;

    case 'l':
     lex_compat = 1;
     break;

    case 'L':
     gen_line_dirs = 0;
     break;

    case 'n':



     break;

    case 'o':
     if ( i != 1 )
      flexerror(
    ("-o flag must be given separately") );

     outfilename = arg + i + 1;
     did_outfilename = 1;
     goto get_next_arg;

    case 'P':
     if ( i != 1 )
      flexerror(
    ("-P flag must be given separately") );

     prefix = arg + i + 1;
     goto get_next_arg;

    case 'p':
     ++performance_report;
     break;

    case 'S':
     if ( i != 1 )
      flexerror(
    ("-S flag must be given separately") );

     skelname = arg + i + 1;
     goto get_next_arg;

    case 's':
     spprdflt = 1;
     break;

    case 't':
     use_stdout = 1;
     break;

    case 'T':
     trace = 1;
     break;

    case 'v':
     printstats = 1;
     break;

    case 'V':
     printf( ("%s version %s\n"),
      program_name, flex_version );
     exit( 0 );

    case 'w':
     nowarn = 1;
     break;

    case '7':
     csize = 128;
     break;

    case '8':
     csize = 256;
     break;

    default:
     fprintf( err,
  ("%s: unknown flag '%c'.  For usage, try\n\t%s --help\n"),
      program_name, (int) arg[i],
      program_name );
     exit( 1 );
    }




  get_next_arg: ;
  }

 num_input_files = argc;
 input_files = argv;
 set_input_file( num_input_files > 0 ? input_files[0] : 
# 850 "flex_single_original.c" 3 4
                                                       ((void *)0) 
# 850 "flex_single_original.c"
                                                            );

 lastccl = lastsc = lastdfa = lastnfa = 0;
 num_rules = num_eof_rules = default_rule = 0;
 numas = numsnpairs = tmpuses = 0;
 numecs = numeps = eps2 = num_reallocs = hshcol = dfaeql = totnst = 0;
 numuniq = numdup = hshsave = eofseen = datapos = dataline = 0;
 num_backing_up = onesp = numprots = 0;
 variable_trailing_context_rules = bol_needed = 0;

 out_linenum = linenum = sectnum = 1;
 firstprot = 0;




 lastprot = 1;

 set_up_initial_allocations();
 }




void readin()
 {
 static char yy_stdinit[] = "FILE *yyin = stdin, *yyout = stdout;";
 static char yy_nostdinit[] =
  "FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;";

 line_directive_out( (FILE *) 0, 1 );

 if ( yyparse() )
  {
  pinpoint_message( ("fatal parse error") );
  flexend( 1 );
  }

 if ( syntaxerror )
  flexend( 1 );

 if ( backing_up_report )
  {
  backing_up_file = fopen( backing_name, "w" );
  if ( backing_up_file == 
# 894 "flex_single_original.c" 3 4
                         ((void *)0) 
# 894 "flex_single_original.c"
                              )
   lerrsf(
   ("could not create backing-up info file %s"),
    backing_name );
  }

 else
  backing_up_file = 
# 901 "flex_single_original.c" 3 4
                   ((void *)0)
# 901 "flex_single_original.c"
                       ;

 if ( yymore_really_used == 1 )
  yymore_used = 1;
 else if ( yymore_really_used == 0 )
  yymore_used = 0;

 if ( reject_really_used == 1 )
  reject = 1;
 else if ( reject_really_used == 0 )
  reject = 0;

 if ( performance_report > 0 )
  {
  if ( lex_compat )
   {
   fprintf( err,
("-l AT&T lex compatibility option entails a large performance penalty\n") );
   fprintf( err,
(" and may be the actual source of other reported performance penalties\n") );
   }

  else if ( do_yylineno )
   {
   fprintf( err,
 ("%%option yylineno entails a large performance penalty\n") );
   }

  if ( performance_report > 1 )
   {
   if ( interactive )
    fprintf( err,
 ("-I (interactive) entails a minor performance penalty\n") );

   if ( yymore_used )
    fprintf( err,
  ("yymore() entails a minor performance penalty\n") );
   }

  if ( reject )
   fprintf( err,
   ("REJECT entails a large performance penalty\n") );

  if ( variable_trailing_context_rules )
   fprintf( err,
("Variable trailing context rules entail a large performance penalty\n") );
  }

 if ( reject )
  real_reject = 1;

 if ( variable_trailing_context_rules )
  reject = 1;

 if ( (fulltbl || fullspd) && reject )
  {
  if ( real_reject )
   flexerror(
    ("REJECT cannot be used with -f or -F") );
  else if ( do_yylineno )
   flexerror(
   ("%option yylineno cannot be used with -f or -F") );
  else
   flexerror(
 ("variable trailing context rules cannot be used with -f or -F") );
  }

 if ( reject )
  outn( "\n#define YY_USES_REJECT" );

 if ( ! do_yywrap )
  {
  outn( "\n#define yywrap() 1" );
  outn( "#define YY_SKIP_YYWRAP" );
  }

 if ( ddebug )
  outn( "\n#define FLEX_DEBUG" );

 if ( csize == 256 )
  outn( "typedef unsigned char YY_CHAR;" );
 else
  outn( "typedef char YY_CHAR;" );

 if ( C_plus_plus )
  {
  outn( "#define yytext_ptr yytext" );

  if ( interactive )
   outn( "#define YY_INTERACTIVE" );
  }

 else
  {
  if ( do_stdinit )
   {
   outn( "#ifdef VMS" );
   outn( "#ifndef __VMS_POSIX" );
   outn( yy_nostdinit );
   outn( "#else" );
   outn( yy_stdinit );
   outn( "#endif" );
   outn( "#else" );
   outn( yy_stdinit );
   outn( "#endif" );
   }

  else
   outn( yy_nostdinit );
  }

 if ( fullspd )
  outn( "typedef yyconst struct yy_trans_info *yy_state_type;" );
 else if ( ! C_plus_plus )
  outn( "typedef int yy_state_type;" );

 if ( ddebug )
  outn( "\n#define FLEX_DEBUG" );

 if ( lex_compat )
  outn( "#define YY_FLEX_LEX_COMPAT" );

 if ( do_yylineno && ! C_plus_plus )
  {
  outn( "extern int yylineno;" );
  outn( "int yylineno = 1;" );
  }

 if ( C_plus_plus )
  {
  outn( "\n#include <FlexLexer.h>" );

  if ( yyclass )
   {
   outn( "int yyFlexLexer::yylex()" );
   outn( "\t{" );
   outn(
"\tLexerError( \"yyFlexLexer::yylex invoked but %option yyclass used\" );" );
   outn( "\treturn 0;" );
   outn( "\t}" );

   out_str( "\n#define YY_DECL int %s::yylex()\n",
    yyclass );
   }
  }

 else
  {
  if ( yytext_is_array )
   outn( "extern char yytext[];\n" );

  else
   {
   outn( "extern char *yytext;" );
   outn( "#define yytext_ptr yytext" );
   }

  if ( yyclass )
   flexerror(
  ("%option yyclass only meaningful for C++ scanners") );
  }

 if ( useecs )
  numecs = cre8ecs( nextecm, ecgroup, csize );
 else
  numecs = csize;


 ecgroup[0] = ecgroup[csize];
 NUL_ec = ((ecgroup[0]) < 0 ? -(ecgroup[0]) : (ecgroup[0]));

 if ( useecs )
  ccl2ecl();
 }




void set_up_initial_allocations()
 {
 current_mns = 2000;
 firstst = (int *) allocate_array( current_mns, sizeof( int ) );
 lastst = (int *) allocate_array( current_mns, sizeof( int ) );
 finalst = (int *) allocate_array( current_mns, sizeof( int ) );
 transchar = (int *) allocate_array( current_mns, sizeof( int ) );
 trans1 = (int *) allocate_array( current_mns, sizeof( int ) );
 trans2 = (int *) allocate_array( current_mns, sizeof( int ) );
 accptnum = (int *) allocate_array( current_mns, sizeof( int ) );
 assoc_rule = (int *) allocate_array( current_mns, sizeof( int ) );
 state_type = (int *) allocate_array( current_mns, sizeof( int ) );

 current_max_rules = 100;
 rule_type = (int *) allocate_array( current_max_rules, sizeof( int ) );
 rule_linenum = (int *) allocate_array( current_max_rules, sizeof( int ) );
 rule_useful = (int *) allocate_array( current_max_rules, sizeof( int ) );

 current_max_scs = 40;
 scset = (int *) allocate_array( current_max_scs, sizeof( int ) );
 scbol = (int *) allocate_array( current_max_scs, sizeof( int ) );
 scxclu = (int *) allocate_array( current_max_scs, sizeof( int ) );
 sceof = (int *) allocate_array( current_max_scs, sizeof( int ) );
 scname = (char **) allocate_array( current_max_scs, sizeof( char * ) );

 current_maxccls = 100;
 cclmap = (int *) allocate_array( current_maxccls, sizeof( int ) );
 ccllen = (int *) allocate_array( current_maxccls, sizeof( int ) );
 cclng = (int *) allocate_array( current_maxccls, sizeof( int ) );

 current_max_ccl_tbl_size = 500;
 ccltbl = (unsigned char *) allocate_array( current_max_ccl_tbl_size, sizeof( unsigned char ) );

 current_max_dfa_size = 750;

 current_max_xpairs = 2000;
 nxt = (int *) allocate_array( current_max_xpairs, sizeof( int ) );
 chk = (int *) allocate_array( current_max_xpairs, sizeof( int ) );

 current_max_template_xpairs = 2500;
 tnxt = (int *) allocate_array( current_max_template_xpairs, sizeof( int ) );

 current_max_dfas = 1000;
 base = (int *) allocate_array( current_max_dfas, sizeof( int ) );
 def = (int *) allocate_array( current_max_dfas, sizeof( int ) );
 dfasiz = (int *) allocate_array( current_max_dfas, sizeof( int ) );
 accsiz = (int *) allocate_array( current_max_dfas, sizeof( int ) );
 dhash = (int *) allocate_array( current_max_dfas, sizeof( int ) );
 dss = (int **) allocate_array( current_max_dfas, sizeof( int * ) );
 dfaacc = (union dfaacc_union *) allocate_array( current_max_dfas, sizeof( union dfaacc_union ) );

 nultrans = (int *) 0;
 }


void usage()
 {


 fprintf( err,
("%s [-bcdfhilnpstvwBFILTV78+? -C[aefFmr] -ooutput -Pprefix -Sskeleton]\n"),
  program_name );
 fprintf( err, ("\t[--help --version] [file ...]\n") );

 fprintf( err, ("\t-b  generate backing-up information to %s\n"),
  backing_name );
 fprintf( err, ("\t-c  do-nothing POSIX option\n") );
 fprintf( err, ("\t-d  turn on debug mode in generated scanner\n") );
 fprintf( err, ("\t-f  generate fast, large scanner\n") );
 fprintf( err, ("\t-h  produce this help message\n") );
 fprintf( err, ("\t-i  generate case-insensitive scanner\n") );
 fprintf( err, ("\t-l  maximal compatibility with original lex\n") );
 fprintf( err, ("\t-n  do-nothing POSIX option\n") );
 fprintf( err, ("\t-p  generate performance report to err\n") );
 fprintf( err,
  ("\t-s  suppress default rule to ECHO unmatched text\n") );

 if ( ! did_outfilename )
  {
  sprintf( outfile_path, outfile_template,
   prefix, C_plus_plus ? "cc" : "c" );
  outfilename = outfile_path;
  }

 fprintf( err,
  ("\t-t  write generated scanner on stdout instead of %s\n"),
  outfilename );

 fprintf( err,
  ("\t-v  write summary of scanner statistics to f\n") );
 fprintf( err, ("\t-w  do not generate warnings\n") );
 fprintf( err, ("\t-B  generate batch scanner (opposite of -I)\n") );
 fprintf( err,
  ("\t-F  use alternative fast scanner representation\n") );
 fprintf( err,
  ("\t-I  generate interactive scanner (opposite of -B)\n") );
 fprintf( err, ("\t-L  suppress #line directives in scanner\n") );
 fprintf( err, ("\t-T  %s should run in trace mode\n"), program_name );
 fprintf( err, ("\t-V  report %s version\n"), program_name );
 fprintf( err, ("\t-7  generate 7-bit scanner\n") );
 fprintf( err, ("\t-8  generate 8-bit scanner\n") );
 fprintf( err, ("\t-+  generate C++ scanner class\n") );
 fprintf( err, ("\t-?  produce this help message\n") );
 fprintf( err,
("\t-C  specify degree of table compression (default is -Cem):\n") );
 fprintf( err,
("\t\t-Ca  trade off larger tables for better memory alignment\n") );
 fprintf( err, ("\t\t-Ce  construct equivalence classes\n") );
 fprintf( err,
("\t\t-Cf  do not compress scanner tables; use -f representation\n") );
 fprintf( err,
("\t\t-CF  do not compress scanner tables; use -F representation\n") );
 fprintf( err, ("\t\t-Cm  construct meta-equivalence classes\n") );
 fprintf( err,
 ("\t\t-Cr  use read() instead of stdio for scanner input\n") );
 fprintf( err, ("\t-o  specify output filename\n") );
 fprintf( err, ("\t-P  specify scanner prefix other than \"yy\"\n") );
 fprintf( err, ("\t-S  specify skeleton file\n") );
 fprintf( err, ("\t--help     produce this help message\n") );
 fprintf( err, ("\t--version  report %s version\n"), program_name );
 }
# 1233 "flex_single_original.c"
void ccladd( cclp, ch )
int cclp;
int ch;
 {
 int ind, len, newpos, i;

 check_char( ch );

 len = ccllen[cclp];
 ind = cclmap[cclp];



 for ( i = 0; i < len; ++i )
  if ( ccltbl[ind + i] == ch )
   return;

 newpos = ind + len;

 if ( newpos >= current_max_ccl_tbl_size )
  {
  current_max_ccl_tbl_size += 250;

  ++num_reallocs;

  ccltbl = (unsigned char *) reallocate_array( (void *) ccltbl, current_max_ccl_tbl_size, sizeof( unsigned char ) )
                                ;
  }

 ccllen[cclp] = len + 1;
 ccltbl[newpos] = ch;
 }




int cclinit()
 {
 if ( ++lastccl >= current_maxccls )
  {
  current_maxccls += 100;

  ++num_reallocs;

  cclmap = (int *) reallocate_array( (void *) cclmap, current_maxccls, sizeof( int ) );
  ccllen = (int *) reallocate_array( (void *) ccllen, current_maxccls, sizeof( int ) );
  cclng = (int *) reallocate_array( (void *) cclng, current_maxccls, sizeof( int ) );
  }

 if ( lastccl == 1 )

  cclmap[lastccl] = 0;

 else





  cclmap[lastccl] = cclmap[lastccl - 1] + ccllen[lastccl - 1];

 ccllen[lastccl] = 0;
 cclng[lastccl] = 0;

 return lastccl;
 }




void cclnegate( cclp )
int cclp;
 {
 cclng[cclp] = 1;
 }
# 1317 "flex_single_original.c"
void list_character_set( file, cset )
FILE *file;
int cset[];
 {
 register int i;

 
# 1323 "flex_single_original.c" 3 4
_IO_putc (
# 1323 "flex_single_original.c"
'['
# 1323 "flex_single_original.c" 3 4
, 
# 1323 "flex_single_original.c"
file
# 1323 "flex_single_original.c" 3 4
)
# 1323 "flex_single_original.c"
                 ;

 for ( i = 0; i < csize; ++i )
  {
  if ( cset[i] )
   {
   register int start_char = i;

   
# 1331 "flex_single_original.c" 3 4
  _IO_putc (
# 1331 "flex_single_original.c"
  ' '
# 1331 "flex_single_original.c" 3 4
  , 
# 1331 "flex_single_original.c"
  file
# 1331 "flex_single_original.c" 3 4
  )
# 1331 "flex_single_original.c"
                   ;

   fputs( readable_form( i ), file );

   while ( ++i < csize && cset[i] )
    ;

   if ( i - 1 > start_char )

    fprintf( file, "-%s", readable_form( i - 1 ) );

   
# 1342 "flex_single_original.c" 3 4
  _IO_putc (
# 1342 "flex_single_original.c"
  ' '
# 1342 "flex_single_original.c" 3 4
  , 
# 1342 "flex_single_original.c"
  file
# 1342 "flex_single_original.c" 3 4
  )
# 1342 "flex_single_original.c"
                   ;
   }
  }

 
# 1346 "flex_single_original.c" 3 4
_IO_putc (
# 1346 "flex_single_original.c"
']'
# 1346 "flex_single_original.c" 3 4
, 
# 1346 "flex_single_original.c"
file
# 1346 "flex_single_original.c" 3 4
)
# 1346 "flex_single_original.c"
                 ;
 }
# 1382 "flex_single_original.c"
void dump_associated_rules (FILE*, int);
void dump_transitions (FILE*, int[]);
void sympartition (int[], int, int[], int[]);
int symfollowset (int[], int, int, int[]);
# 1397 "flex_single_original.c"
void check_for_backing_up( ds, state )
int ds;
int state[];
 {
 if ( (reject && ! dfaacc[ds].dfaacc_set) ||
      (! reject && ! dfaacc[ds].dfaacc_state) )
  {
  ++num_backing_up;

  if ( backing_up_report )
   {
   fprintf( backing_up_file,
    ("State #%d is non-accepting -\n"), ds );


   dump_associated_rules( backing_up_file, ds );




   dump_transitions( backing_up_file, state );

   
# 1419 "flex_single_original.c" 3 4
  _IO_putc (
# 1419 "flex_single_original.c"
  '\n'
# 1419 "flex_single_original.c" 3 4
  , 
# 1419 "flex_single_original.c"
  backing_up_file
# 1419 "flex_single_original.c" 3 4
  )
# 1419 "flex_single_original.c"
                               ;
   }
  }
 }
# 1447 "flex_single_original.c"
void check_trailing_context( nfa_states, num_states, accset, nacc )
int *nfa_states, num_states;
int *accset;
int nacc;
 {
 register int i, j;

 for ( i = 1; i <= num_states; ++i )
  {
  int ns = nfa_states[i];
  register int type = state_type[ns];
  register int ar = assoc_rule[ns];

  if ( type == 0x1 || rule_type[ar] != 1 )
   {
   }

  else if ( type == 0x2 )
   {






   for ( j = 1; j <= nacc; ++j )
    if ( accset[j] & 0x4000 )
     {
     line_warning(
     ("dangerous trailing context"),
      rule_linenum[ar] );
     return;
     }
   }
  }
 }
# 1492 "flex_single_original.c"
void dump_associated_rules( file, ds )
FILE *file;
int ds;
 {
 register int i, j;
 register int num_associated_rules = 0;
 int rule_set[100 + 1];
 int *dset = dss[ds];
 int size = dfasiz[ds];

 for ( i = 1; i <= size; ++i )
  {
  register int rule_num = rule_linenum[assoc_rule[dset[i]]];

  for ( j = 1; j <= num_associated_rules; ++j )
   if ( rule_num == rule_set[j] )
    break;

  if ( j > num_associated_rules )
   {
   if ( num_associated_rules < 100 )
    rule_set[++num_associated_rules] = rule_num;
   }
  }

 bubble( rule_set, num_associated_rules );

 fprintf( file, (" associated rule line numbers:") );

 for ( i = 1; i <= num_associated_rules; ++i )
  {
  if ( i % 8 == 1 )
   
# 1524 "flex_single_original.c" 3 4
  _IO_putc (
# 1524 "flex_single_original.c"
  '\n'
# 1524 "flex_single_original.c" 3 4
  , 
# 1524 "flex_single_original.c"
  file
# 1524 "flex_single_original.c" 3 4
  )
# 1524 "flex_single_original.c"
                    ;

  fprintf( file, "\t%d", rule_set[i] );
  }

 
# 1529 "flex_single_original.c" 3 4
_IO_putc (
# 1529 "flex_single_original.c"
'\n'
# 1529 "flex_single_original.c" 3 4
, 
# 1529 "flex_single_original.c"
file
# 1529 "flex_single_original.c" 3 4
)
# 1529 "flex_single_original.c"
                  ;
 }
# 1544 "flex_single_original.c"
void dump_transitions( file, state )
FILE *file;
int state[];
 {
 register int i, ec;
 int out_char_set[256];

 for ( i = 0; i < csize; ++i )
  {
  ec = ((ecgroup[i]) < 0 ? -(ecgroup[i]) : (ecgroup[i]));
  out_char_set[i] = state[ec];
  }

 fprintf( file, (" out-transitions: ") );

 list_character_set( file, out_char_set );


 for ( i = 0; i < csize; ++i )
  out_char_set[i] = ! out_char_set[i];

 fprintf( file, ("\n jam-transitions: EOF ") );

 list_character_set( file, out_char_set );

 
# 1569 "flex_single_original.c" 3 4
_IO_putc (
# 1569 "flex_single_original.c"
'\n'
# 1569 "flex_single_original.c" 3 4
, 
# 1569 "flex_single_original.c"
file
# 1569 "flex_single_original.c" 3 4
)
# 1569 "flex_single_original.c"
                  ;
 }
# 1593 "flex_single_original.c"
int *epsclosure( t, ns_addr, accset, nacc_addr, hv_addr )
int *t, *ns_addr, accset[], *nacc_addr, *hv_addr;
 {
 register int stkpos, ns, tsp;
 int numstates = *ns_addr, nacc, hashval, transsym, nfaccnum;
 int stkend, nstate;
 static int did_stk_init = 0, *stk;
# 1649 "flex_single_original.c"
 if ( ! did_stk_init )
  {
  stk = (int *) allocate_array( current_max_dfa_size, sizeof( int ) );
  did_stk_init = 1;
  }

 nacc = stkend = hashval = 0;

 for ( nstate = 1; nstate <= numstates; ++nstate )
  {
  ns = t[nstate];




  if ( ! (trans1[ns] < 0) )
   {
   { if ( ++stkend >= current_max_dfa_size ) { current_max_dfa_size += 750; ++num_reallocs; t = (int *) reallocate_array( (void *) t, current_max_dfa_size, sizeof( int ) ); stk = (int *) reallocate_array( (void *) stk, current_max_dfa_size, sizeof( int ) ); } stk[stkend] = ns; trans1[ns] = trans1[ns] - (31999 +2); }
   { nfaccnum = accptnum[ns]; if ( nfaccnum != 0 ) accset[++nacc] = nfaccnum; }
   hashval += ns;
   }
  }

 for ( stkpos = 1; stkpos <= stkend; ++stkpos )
  {
  ns = stk[stkpos];
  transsym = transchar[ns];

  if ( transsym == (256 + 1) )
   {
   tsp = trans1[ns] + (31999 +2);

   if ( tsp != 0 )
    {
    if ( ! (trans1[tsp] < 0) )
     { { if ( ++stkend >= current_max_dfa_size ) { current_max_dfa_size += 750; ++num_reallocs; t = (int *) reallocate_array( (void *) t, current_max_dfa_size, sizeof( int ) ); stk = (int *) reallocate_array( (void *) stk, current_max_dfa_size, sizeof( int ) ); } stk[stkend] = tsp; trans1[tsp] = trans1[tsp] - (31999 +2); } { nfaccnum = accptnum[tsp]; if ( nfaccnum != 0 ) accset[++nacc] = nfaccnum; } if ( nfaccnum != 0 || transchar[tsp] != (256 + 1) ) { if ( ++numstates >= current_max_dfa_size ) { current_max_dfa_size += 750; ++num_reallocs; t = (int *) reallocate_array( (void *) t, current_max_dfa_size, sizeof( int ) ); stk = (int *) reallocate_array( (void *) stk, current_max_dfa_size, sizeof( int ) ); } t[numstates] = tsp; hashval += tsp; } }

    tsp = trans2[ns];

    if ( tsp != 0 && ! (trans1[tsp] < 0) )
     { { if ( ++stkend >= current_max_dfa_size ) { current_max_dfa_size += 750; ++num_reallocs; t = (int *) reallocate_array( (void *) t, current_max_dfa_size, sizeof( int ) ); stk = (int *) reallocate_array( (void *) stk, current_max_dfa_size, sizeof( int ) ); } stk[stkend] = tsp; trans1[tsp] = trans1[tsp] - (31999 +2); } { nfaccnum = accptnum[tsp]; if ( nfaccnum != 0 ) accset[++nacc] = nfaccnum; } if ( nfaccnum != 0 || transchar[tsp] != (256 + 1) ) { if ( ++numstates >= current_max_dfa_size ) { current_max_dfa_size += 750; ++num_reallocs; t = (int *) reallocate_array( (void *) t, current_max_dfa_size, sizeof( int ) ); stk = (int *) reallocate_array( (void *) stk, current_max_dfa_size, sizeof( int ) ); } t[numstates] = tsp; hashval += tsp; } }
    }
   }
  }



 for ( stkpos = 1; stkpos <= stkend; ++stkpos )
  {
  if ( (trans1[stk[stkpos]] < 0) )
   trans1[stk[stkpos]] = trans1[stk[stkpos]] + (31999 +2);
  else
   flexfatal(
   ("consistency check failed in epsclosure()") );
  }

 *ns_addr = numstates;
 *hv_addr = hashval;
 *nacc_addr = nacc;

 return t;
 }




void increase_max_dfas()
 {
 current_max_dfas += 1000;

 ++num_reallocs;

 base = (int *) reallocate_array( (void *) base, current_max_dfas, sizeof( int ) );
 def = (int *) reallocate_array( (void *) def, current_max_dfas, sizeof( int ) );
 dfasiz = (int *) reallocate_array( (void *) dfasiz, current_max_dfas, sizeof( int ) );
 accsiz = (int *) reallocate_array( (void *) accsiz, current_max_dfas, sizeof( int ) );
 dhash = (int *) reallocate_array( (void *) dhash, current_max_dfas, sizeof( int ) );
 dss = (int **) reallocate_array( (void *) dss, current_max_dfas, sizeof( int * ) );
 dfaacc = (union dfaacc_union *) reallocate_array( (void *) dfaacc, current_max_dfas, sizeof( union dfaacc_union ) );

 if ( nultrans )
  nultrans =
   (int *) reallocate_array( (void *) nultrans, current_max_dfas, sizeof( int ) );
 }
# 1741 "flex_single_original.c"
void ntod()
 {
 int *accset, ds, nacc, newds;
 int sym, hashval, numstates, dsize;
 int num_full_table_rows;
 int *nset, *dset;
 int targptr, totaltrans, i, comstate, comfreq, targ;
 int symlist[256 + 1];
 int num_start_states;
 int todo_head, todo_next;
# 1759 "flex_single_original.c"
 int duplist[256 + 1], state[256 + 1];
 int targfreq[256 + 1], targstate[256 + 1];

 accset = (int *) allocate_array( num_rules + 1, sizeof( int ) );
 nset = (int *) allocate_array( current_max_dfa_size, sizeof( int ) );







 todo_head = todo_next = 0;

 for ( i = 0; i <= csize; ++i )
  {
  duplist[i] = 0;
  symlist[i] = 0;
  }

 for ( i = 0; i <= num_rules; ++i )
  accset[i] = 0;

 if ( trace )
  {
  dumpnfa( scset[1] );
  fputs( ("\n\nDFA Dump:\n\n"), err );
  }

 inittbl();
# 1822 "flex_single_original.c"
 if ( ! fullspd && ecgroup[0] == numecs )
  {



  int use_NUL_table = (numecs == csize);

  if ( fulltbl && ! use_NUL_table )
   {



   int power_of_two;

   for ( power_of_two = 1; power_of_two <= csize;
         power_of_two *= 2 )
    if ( numecs == power_of_two )
     {
     use_NUL_table = 1;
     break;
     }
   }

  if ( use_NUL_table )
   nultrans = (int *) allocate_array( current_max_dfas, sizeof( int ) );




  }


 if ( fullspd )
  {
  for ( i = 0; i <= numecs; ++i )
   state[i] = 0;

  place_state( state, 0, 0 );
  dfaacc[0].dfaacc_state = 0;
  }

 else if ( fulltbl )
  {
  if ( nultrans )



   num_full_table_rows = numecs;

  else




   num_full_table_rows = numecs + 1;




  out_str_dec( "static yyconst %s yy_nxt[][%d] =\n    {\n",

   long_align ? "long" : "short", num_full_table_rows );

  outn( "    {" );


  for ( i = 0; i < num_full_table_rows; ++i )
   mk2data( 0 );

  dataflush();
  outn( "    },\n" );
  }



 num_start_states = lastsc * 2;

 for ( i = 1; i <= num_start_states; ++i )
  {
  numstates = 1;





  if ( i % 2 == 1 )
   nset[numstates] = scset[(i / 2) + 1];
  else
   nset[numstates] =
    mkbranch( scbol[i / 2], scset[i / 2] );

  nset = epsclosure( nset, &numstates, accset, &nacc, &hashval );

  if ( snstods( nset, numstates, accset, nacc, hashval, &ds ) )
   {
   numas += nacc;
   totnst += numstates;
   ++todo_next;

   if ( variable_trailing_context_rules && nacc > 0 )
    check_trailing_context( nset, numstates,
       accset, nacc );
   }
  }

 if ( ! fullspd )
  {
  if ( ! snstods( nset, 0, accset, 0, 0, &end_of_buffer_state ) )
   flexfatal(
   ("could not create unique end-of-buffer state") );

  ++numas;
  ++num_start_states;
  ++todo_next;
  }

 while ( todo_head < todo_next )
  {
  targptr = 0;
  totaltrans = 0;

  for ( i = 1; i <= numecs; ++i )
   state[i] = 0;

  ds = ++todo_head;

  dset = dss[ds];
  dsize = dfasiz[ds];

  if ( trace )
   fprintf( err, ("state # %d:\n"), ds );

  sympartition( dset, dsize, symlist, duplist );

  for ( sym = 1; sym <= numecs; ++sym )
   {
   if ( symlist[sym] )
    {
    symlist[sym] = 0;

    if ( duplist[sym] == 0 )
     {

     numstates = symfollowset( dset, dsize,
        sym, nset );
     nset = epsclosure( nset, &numstates,
      accset, &nacc, &hashval );

     if ( snstods( nset, numstates, accset,
      nacc, hashval, &newds ) )
      {
      totnst = totnst + numstates;
      ++todo_next;
      numas += nacc;

      if (
     variable_trailing_context_rules &&
       nacc > 0 )
       check_trailing_context(
        nset, numstates,
        accset, nacc );
      }

     state[sym] = newds;

     if ( trace )
      fprintf( err, "\t%d\t%d\n",
       sym, newds );

     targfreq[++targptr] = 1;
     targstate[targptr] = newds;
     ++numuniq;
     }

    else
     {




     targ = state[duplist[sym]];
     state[sym] = targ;

     if ( trace )
      fprintf( err, "\t%d\t%d\n",
       sym, targ );





     i = 0;
     while ( targstate[++i] != targ )
      ;

     ++targfreq[i];
     ++numdup;
     }

    ++totaltrans;
    duplist[sym] = 0;
    }
   }

  if ( caseins && ! useecs )
   {
   register int j;

   for ( i = 'A', j = 'a'; i <= 'Z'; ++i, ++j )
    {
    if ( state[i] == 0 && state[j] != 0 )

     ++totaltrans;

    else if ( state[i] != 0 && state[j] == 0 )

     --totaltrans;

    state[i] = state[j];
    }
   }

  numsnpairs += totaltrans;

  if ( ds > num_start_states )
   check_for_backing_up( ds, state );

  if ( nultrans )
   {
   nultrans[ds] = state[NUL_ec];
   state[NUL_ec] = 0;
   }

  if ( fulltbl )
   {
   outn( "    {" );


   if ( ds == end_of_buffer_state )
    mk2data( -end_of_buffer_state );
   else
    mk2data( end_of_buffer_state );

   for ( i = 1; i < num_full_table_rows; ++i )



    mk2data( state[i] ? state[i] : -ds );

   dataflush();
   outn( "    },\n" );
   }

  else if ( fullspd )
   place_state( state, ds, totaltrans );

  else if ( ds == end_of_buffer_state )



   stack1( ds, 0, 0, -32766 );

  else
   {




   comfreq = 0;
   comstate = 0;

   for ( i = 1; i <= targptr; ++i )
    if ( targfreq[i] > comfreq )
     {
     comfreq = targfreq[i];
     comstate = targstate[i];
     }

   bldtbl( state, ds, totaltrans, comstate, comfreq );
   }
  }

 if ( fulltbl )
  dataend();

 else if ( ! fullspd )
  {
  cmptmps();




  while ( onesp > 0 )
   {
   mk1tbl( onestate[onesp], onesym[onesp], onenext[onesp],
   onedef[onesp] );
   --onesp;
   }

  mkdeftbl();
  }

 flex_free( (void *) accset );
 flex_free( (void *) nset );
 }
# 2139 "flex_single_original.c"
int snstods( sns, numstates, accset, nacc, hashval, newds_addr )
int sns[], numstates, accset[], nacc, hashval, *newds_addr;
 {
 int didsort = 0;
 register int i, j;
 int newds, *oldsns;

 for ( i = 1; i <= lastdfa; ++i )
  if ( hashval == dhash[i] )
   {
   if ( numstates == dfasiz[i] )
    {
    oldsns = dss[i];

    if ( ! didsort )
     {





     bubble( sns, numstates );
     didsort = 1;
     }

    for ( j = 1; j <= numstates; ++j )
     if ( sns[j] != oldsns[j] )
      break;

    if ( j > numstates )
     {
     ++dfaeql;
     *newds_addr = i;
     return 0;
     }

    ++hshcol;
    }

   else
    ++hshsave;
   }



 if ( ++lastdfa >= current_max_dfas )
  increase_max_dfas();

 newds = lastdfa;

 dss[newds] = (int *) allocate_array( numstates + 1, sizeof( int ) );





 if ( ! didsort )
  bubble( sns, numstates );

 for ( i = 1; i <= numstates; ++i )
  dss[newds][i] = sns[i];

 dfasiz[newds] = numstates;
 dhash[newds] = hashval;

 if ( nacc == 0 )
  {
  if ( reject )
   dfaacc[newds].dfaacc_set = (int *) 0;
  else
   dfaacc[newds].dfaacc_state = 0;

  accsiz[newds] = 0;
  }

 else if ( reject )
  {






  bubble( accset, nacc );

  dfaacc[newds].dfaacc_set = (int *) allocate_array( nacc + 1, sizeof( int ) );


  for ( i = 1; i <= nacc; ++i )
   {
   dfaacc[newds].dfaacc_set[i] = accset[i];

   if ( accset[i] <= num_rules )



    rule_useful[accset[i]] = 1;
   }

  accsiz[newds] = nacc;
  }

 else
  {



  j = num_rules + 1;

  for ( i = 1; i <= nacc; ++i )
   if ( accset[i] < j )
    j = accset[i];

  dfaacc[newds].dfaacc_state = j;

  if ( j <= num_rules )
   rule_useful[j] = 1;
  }

 *newds_addr = newds;

 return 1;
 }
# 2271 "flex_single_original.c"
int symfollowset( ds, dsize, transsym, nset )
int ds[], dsize, transsym, nset[];
 {
 int ns, tsp, sym, i, j, lenccl, ch, numstates, ccllist;

 numstates = 0;

 for ( i = 1; i <= dsize; ++i )
  {
  ns = ds[i];
  sym = transchar[ns];
  tsp = trans1[ns];

  if ( sym < 0 )
   {
   sym = -sym;
   ccllist = cclmap[sym];
   lenccl = ccllen[sym];

   if ( cclng[sym] )
    {
    for ( j = 0; j < lenccl; ++j )
     {



     ch = ccltbl[ccllist + j];

     if ( ch == 0 )
      ch = NUL_ec;

     if ( ch > transsym )



      break;

     else if ( ch == transsym )
                   goto bottom;
     }


    nset[++numstates] = tsp;
    }

   else
    for ( j = 0; j < lenccl; ++j )
     {
     ch = ccltbl[ccllist + j];

     if ( ch == 0 )
      ch = NUL_ec;

     if ( ch > transsym )
      break;
     else if ( ch == transsym )
      {
      nset[++numstates] = tsp;
      break;
      }
     }
   }

  else if ( sym >= 'A' && sym <= 'Z' && caseins )
   flexfatal(
   ("consistency check failed in symfollowset") );

  else if ( sym == (256 + 1) )
   {
   }

  else if ( ((ecgroup[sym]) < 0 ? -(ecgroup[sym]) : (ecgroup[sym])) == transsym )
   nset[++numstates] = tsp;

  bottom: ;
  }

 return numstates;
 }
# 2359 "flex_single_original.c"
void sympartition( ds, numstates, symlist, duplist )
int ds[], numstates;
int symlist[], duplist[];
 {
 int tch, i, j, k, ns, dupfwd[256 + 1], lenccl, cclp, ich;






 for ( i = 1; i <= numecs; ++i )
  {
  duplist[i] = i - 1;
  dupfwd[i] = i + 1;
  }

 duplist[1] = 0;
 dupfwd[numecs] = 0;

 for ( i = 1; i <= numstates; ++i )
  {
  ns = ds[i];
  tch = transchar[ns];

  if ( tch != (256 + 1) )
   {
   if ( tch < -lastccl || tch >= csize )
    {
    flexfatal(
  ("bad transition character detected in sympartition()") );
    }

   if ( tch >= 0 )
    {
    int ec = ecgroup[tch];

    mkechar( ec, dupfwd, duplist );
    symlist[ec] = 1;
    }

   else
    {
    tch = -tch;

    lenccl = ccllen[tch];
    cclp = cclmap[tch];
    mkeccl( ccltbl + cclp, lenccl, dupfwd,
     duplist, numecs, NUL_ec );

    if ( cclng[tch] )
     {
     j = 0;

     for ( k = 0; k < lenccl; ++k )
      {
      ich = ccltbl[cclp + k];

      if ( ich == 0 )
       ich = NUL_ec;

      for ( ++j; j < ich; ++j )
       symlist[j] = 1;
      }

     for ( ++j; j <= numecs; ++j )
      symlist[j] = 1;
     }

    else
     for ( k = 0; k < lenccl; ++k )
      {
      ich = ccltbl[cclp + k];

      if ( ich == 0 )
       ich = NUL_ec;

      symlist[ich] = 1;
      }
    }
   }
  }
 }
# 2475 "flex_single_original.c"
void ccl2ecl()
 {
 int i, ich, newlen, cclp, ccls, cclmec;

 for ( i = 1; i <= lastccl; ++i )
  {







  newlen = 0;
  cclp = cclmap[i];

  for ( ccls = 0; ccls < ccllen[i]; ++ccls )
   {
   ich = ccltbl[cclp + ccls];
   cclmec = ecgroup[ich];

   if ( cclmec > 0 )
    {
    ccltbl[cclp + newlen] = cclmec;
    ++newlen;
    }
   }

  ccllen[i] = newlen;
  }
 }
# 2516 "flex_single_original.c"
int cre8ecs( fwd, bck, num )
int fwd[], bck[], num;
 {
 int i, j, numcl;

 numcl = 0;






 for ( i = 1; i <= num; ++i )
  if ( bck[i] == 0 )
   {
   bck[i] = ++numcl;
   for ( j = fwd[i]; j != 0; j = fwd[j] )
    bck[j] = -numcl;
   }

 return numcl;
 }
# 2555 "flex_single_original.c"
void mkeccl( ccls, lenccl, fwd, bck, llsiz, NUL_mapping )
unsigned char ccls[];
int lenccl, fwd[], bck[], llsiz, NUL_mapping;
 {
 int cclp, oldec, newec;
 int cclm, i, j;
 static unsigned char cclflags[256];





 cclp = 0;

 while ( cclp < lenccl )
  {
  cclm = ccls[cclp];

  if ( NUL_mapping && cclm == 0 )
   cclm = NUL_mapping;

  oldec = bck[cclm];
  newec = cclm;

  j = cclp + 1;

  for ( i = fwd[cclm]; i != 0 && i <= llsiz; i = fwd[i] )
   {
   for ( ; j < lenccl; ++j )
    {
    register int ccl_char;

    if ( NUL_mapping && ccls[j] == 0 )
     ccl_char = NUL_mapping;
    else
     ccl_char = ccls[j];

    if ( ccl_char > i )
     break;

    if ( ccl_char == i && ! cclflags[j] )
     {






     bck[i] = newec;
     fwd[newec] = i;
     newec = i;

     cclflags[j] = 1;



     goto next_pt;
     }
    }





   bck[i] = oldec;

   if ( oldec != 0 )
    fwd[oldec] = i;

   oldec = i;

   next_pt: ;
   }

  if ( bck[cclm] != 0 || oldec != bck[cclm] )
   {
   bck[cclm] = 0;
   fwd[oldec] = 0;
   }

  fwd[newec] = 0;



  for ( ++cclp; cclflags[cclp] && cclp < lenccl; ++cclp )
   {

   cclflags[cclp] = 0;
   }
  }
 }




void mkechar( tch, fwd, bck )
int tch, fwd[], bck[];
 {




 if ( fwd[tch] != 0 )
  bck[fwd[tch]] = bck[tch];

 if ( bck[tch] != 0 )
  fwd[bck[tch]] = fwd[tch];

 fwd[tch] = 0;
 bck[tch] = 0;
 }
# 2700 "flex_single_original.c"
void gen_next_state (int);
void genecs (void);
void indent_put2s (char [], char []);
void indent_puts (char []);


static int indent_level = 0;
# 2717 "flex_single_original.c"
static char C_int_decl[] = "static yyconst int %s[%d] =\n    {   0,\n";
static char C_short_decl[] = "static yyconst short int %s[%d] =\n    {   0,\n";
static char C_long_decl[] = "static yyconst long int %s[%d] =\n    {   0,\n";
static char C_state_decl[] =
 "static yyconst yy_state_type %s[%d] =\n    {   0,\n";




void do_indent()
 {
 register int i = indent_level * 8;

 while ( i >= 8 )
  {
  outc( '\t' );
  i -= 8;
  }

 while ( i > 0 )
  {
  outc( ' ' );
  --i;
  }
 }




void gen_backing_up()
 {
 if ( reject || num_backing_up == 0 )
  return;

 if ( fullspd )
  indent_puts( "if ( yy_current_state[-1].yy_nxt )" );
 else
  indent_puts( "if ( yy_accept[yy_current_state] )" );

 (++indent_level);
 indent_puts( "{" );
 indent_puts( "yy_last_accepting_state = yy_current_state;" );
 indent_puts( "yy_last_accepting_cpos = yy_cp;" );
 indent_puts( "}" );
 (--indent_level);
 }




void gen_bu_action()
 {
 if ( reject || num_backing_up == 0 )
  return;

 indent_level = 3;

 indent_puts( "case 0: /* must back up */" );
 indent_puts( "/* undo the effects of YY_DO_BEFORE_ACTION */" );
 indent_puts( "*yy_cp = yy_hold_char;" );

 if ( fullspd || fulltbl )
  indent_puts( "yy_cp = yy_last_accepting_cpos + 1;" );
 else



  indent_puts( "yy_cp = yy_last_accepting_cpos;" );

 indent_puts( "yy_current_state = yy_last_accepting_state;" );
 indent_puts( "goto yy_find_action;" );
 outc( '\n' );

 indent_level = 0;
 }




void genctbl()
 {
 register int i;
 int end_of_buffer_action = num_rules + 1;


 out_dec( "static yyconst struct yy_trans_info yy_transition[%d] =\n",
  tblend + numecs + 1 );
 outn( "    {" );
# 2824 "flex_single_original.c"
 while ( tblend + 2 >= current_max_xpairs )
  expand_nxt_chk();

 while ( lastdfa + 1 >= current_max_dfas )
  increase_max_dfas();

 base[lastdfa + 1] = tblend + 2;
 nxt[tblend + 1] = end_of_buffer_action;
 chk[tblend + 1] = numecs + 1;
 chk[tblend + 2] = 1;


 nxt[tblend + 2] = 0;




 for ( i = 0; i <= lastdfa; ++i )
  {
  int anum = dfaacc[i].dfaacc_state;
  int offset = base[i];

  chk[offset] = -1;
  chk[offset - 1] = -2;
  nxt[offset - 1] = anum;
  }

 for ( i = 0; i <= tblend; ++i )
  {
  if ( chk[i] == -1 )
   transition_struct_out( 0, base[lastdfa + 1] - i );

  else if ( chk[i] == -2 )
   transition_struct_out( 0, nxt[i] );

  else if ( chk[i] > numecs || chk[i] == 0 )
   transition_struct_out( 0, 0 );

  else
   transition_struct_out( chk[i],
      base[nxt[i]] - (i - chk[i]) );
  }



 transition_struct_out( chk[tblend + 1], nxt[tblend + 1] );
 transition_struct_out( chk[tblend + 2], nxt[tblend + 2] );

 outn( "    };\n" );


 out_dec(
 "static yyconst struct yy_trans_info *yy_start_state_list[%d] =\n",
  lastsc * 2 + 1 );
 outn( "    {" );

 for ( i = 0; i <= lastsc * 2; ++i )
  out_dec( "    &yy_transition[%d],\n", base[i] );

 dataend();

 if ( useecs )
  genecs();
 }




void genecs()
 {
 register int i, j;
 int numrows;

 out_str_dec( C_int_decl, "yy_ec", csize );

 for ( i = 1; i < csize; ++i )
  {
  if ( caseins && (i >= 'A') && (i <= 'Z') )
   ecgroup[i] = ecgroup[clower( i )];

  ecgroup[i] = ((ecgroup[i]) < 0 ? -(ecgroup[i]) : (ecgroup[i]));
  mkdata( ecgroup[i] );
  }

 dataend();

 if ( trace )
  {
  fputs( ("\n\nEquivalence Classes:\n\n"), err );

  numrows = csize / 8;

  for ( j = 0; j < numrows; ++j )
   {
   for ( i = j; i < csize; i = i + numrows )
    {
    fprintf( err, "%4s = %-2d",
     readable_form( i ), ecgroup[i] );

    
# 2923 "flex_single_original.c" 3 4
   _IO_putc (
# 2923 "flex_single_original.c"
   ' '
# 2923 "flex_single_original.c" 3 4
   , 
# 2923 "flex_single_original.c"
   err
# 2923 "flex_single_original.c" 3 4
   )
# 2923 "flex_single_original.c"
                   ;
    }

   
# 2926 "flex_single_original.c" 3 4
  _IO_putc (
# 2926 "flex_single_original.c"
  '\n'
# 2926 "flex_single_original.c" 3 4
  , 
# 2926 "flex_single_original.c"
  err
# 2926 "flex_single_original.c" 3 4
  )
# 2926 "flex_single_original.c"
                   ;
   }
  }
 }




void gen_find_action()
 {
 if ( fullspd )
  indent_puts( "yy_act = yy_current_state[-1].yy_nxt;" );

 else if ( fulltbl )
  indent_puts( "yy_act = yy_accept[yy_current_state];" );

 else if ( reject )
  {
  indent_puts( "yy_current_state = *--yy_state_ptr;" );
  indent_puts( "yy_lp = yy_accept[yy_current_state];" );

  outn(
  "find_rule: /* we branch to this label when backing up */" );

  indent_puts(
  "for ( ; ; ) /* until we find what rule we matched */" );

  (++indent_level);

  indent_puts( "{" );

  indent_puts(
  "if ( yy_lp && yy_lp < yy_accept[yy_current_state + 1] )" );
  (++indent_level);
  indent_puts( "{" );
  indent_puts( "yy_act = yy_acclist[yy_lp];" );

  if ( variable_trailing_context_rules )
   {
   indent_puts( "if ( yy_act & YY_TRAILING_HEAD_MASK ||" );
   indent_puts( "     yy_looking_for_trail_begin )" );
   (++indent_level);
   indent_puts( "{" );

   indent_puts(
    "if ( yy_act == yy_looking_for_trail_begin )" );
   (++indent_level);
   indent_puts( "{" );
   indent_puts( "yy_looking_for_trail_begin = 0;" );
   indent_puts( "yy_act &= ~YY_TRAILING_HEAD_MASK;" );
   indent_puts( "break;" );
   indent_puts( "}" );
   (--indent_level);

   indent_puts( "}" );
   (--indent_level);

   indent_puts( "else if ( yy_act & YY_TRAILING_MASK )" );
   (++indent_level);
   indent_puts( "{" );
   indent_puts(
  "yy_looking_for_trail_begin = yy_act & ~YY_TRAILING_MASK;" );
   indent_puts(
  "yy_looking_for_trail_begin |= YY_TRAILING_HEAD_MASK;" );

   if ( real_reject )
    {



    indent_puts( "yy_full_match = yy_cp;" );
    indent_puts( "yy_full_state = yy_state_ptr;" );
    indent_puts( "yy_full_lp = yy_lp;" );
    }

   indent_puts( "}" );
   (--indent_level);

   indent_puts( "else" );
   (++indent_level);
   indent_puts( "{" );
   indent_puts( "yy_full_match = yy_cp;" );
   indent_puts( "yy_full_state = yy_state_ptr;" );
   indent_puts( "yy_full_lp = yy_lp;" );
   indent_puts( "break;" );
   indent_puts( "}" );
   (--indent_level);

   indent_puts( "++yy_lp;" );
   indent_puts( "goto find_rule;" );
   }

  else
   {



   (++indent_level);
   indent_puts( "{" );
   indent_puts( "yy_full_match = yy_cp;" );
   indent_puts( "break;" );
   indent_puts( "}" );
   (--indent_level);
   }

  indent_puts( "}" );
  (--indent_level);

  indent_puts( "--yy_cp;" );





  indent_puts( "yy_current_state = *--yy_state_ptr;" );
  indent_puts( "yy_lp = yy_accept[yy_current_state];" );

  indent_puts( "}" );

  (--indent_level);
  }

 else
  {
  indent_puts( "yy_act = yy_accept[yy_current_state];" );

  if ( interactive && ! reject )
   {



   indent_puts( "if ( yy_act == 0 )" );
   (++indent_level);
   indent_puts( "{ /* have to back up */" );
   indent_puts( "yy_cp = yy_last_accepting_cpos;" );
   indent_puts(
    "yy_current_state = yy_last_accepting_state;" );
   indent_puts( "yy_act = yy_accept[yy_current_state];" );
   indent_puts( "}" );
   (--indent_level);
   }
  }
 }




void genftbl()
 {
 register int i;
 int end_of_buffer_action = num_rules + 1;

 out_str_dec( long_align ? C_long_decl : C_short_decl,
  "yy_accept", lastdfa + 1 );

 dfaacc[end_of_buffer_state].dfaacc_state = end_of_buffer_action;

 for ( i = 1; i <= lastdfa; ++i )
  {
  register int anum = dfaacc[i].dfaacc_state;

  mkdata( anum );

  if ( trace && anum )
   fprintf( err, ("state # %d accepts: [%d]\n"),
    i, anum );
  }

 dataend();

 if ( useecs )
  genecs();




 }




void gen_next_compressed_state( char_map )
char *char_map;
 {
 indent_put2s( "register YY_CHAR yy_c = %s;", char_map );





 gen_backing_up();

 indent_puts(
"while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )" );
 (++indent_level);
 indent_puts( "{" );
 indent_puts( "yy_current_state = (int) yy_def[yy_current_state];" );

 if ( usemecs )
  {







  do_indent();


  out_dec( "if ( yy_current_state >= %d )\n", lastdfa + 2 );

  (++indent_level);
  indent_puts( "yy_c = yy_meta[(unsigned int) yy_c];" );
  (--indent_level);
  }

 indent_puts( "}" );
 (--indent_level);

 indent_puts(
"yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];" );
 }




void gen_next_match()
 {



 char *char_map = useecs ?
    "yy_ec[YY_SC_TO_UI(*yy_cp)]" :
    "YY_SC_TO_UI(*yy_cp)";

 char *char_map_2 = useecs ?
    "yy_ec[YY_SC_TO_UI(*++yy_cp)]" :
    "YY_SC_TO_UI(*++yy_cp)";

 if ( fulltbl )
  {
  indent_put2s(
 "while ( (yy_current_state = yy_nxt[yy_current_state][%s]) > 0 )",
    char_map );

  (++indent_level);

  if ( num_backing_up > 0 )
   {
   indent_puts( "{" );
   gen_backing_up();
   outc( '\n' );
   }

  indent_puts( "++yy_cp;" );

  if ( num_backing_up > 0 )

   indent_puts( "}" );

  (--indent_level);

  outc( '\n' );
  indent_puts( "yy_current_state = -yy_current_state;" );
  }

 else if ( fullspd )
  {
  indent_puts( "{" );
  indent_puts(
  "register yyconst struct yy_trans_info *yy_trans_info;\n" );
  indent_puts( "register YY_CHAR yy_c;\n" );
  indent_put2s( "for ( yy_c = %s;", char_map );
  indent_puts(
 "      (yy_trans_info = &yy_current_state[(unsigned int) yy_c])->" );
  indent_puts( "yy_verify == yy_c;" );
  indent_put2s( "      yy_c = %s )", char_map_2 );

  (++indent_level);

  if ( num_backing_up > 0 )
   indent_puts( "{" );

  indent_puts( "yy_current_state += yy_trans_info->yy_nxt;" );

  if ( num_backing_up > 0 )
   {
   outc( '\n' );
   gen_backing_up();
   indent_puts( "}" );
   }

  (--indent_level);
  indent_puts( "}" );
  }

 else
  {
  indent_puts( "do" );

  (++indent_level);
  indent_puts( "{" );

  gen_next_state( 0 );

  indent_puts( "++yy_cp;" );


  indent_puts( "}" );
  (--indent_level);

  do_indent();

  if ( interactive )
   out_dec( "while ( yy_base[yy_current_state] != %d );\n",
    jambase );
  else
   out_dec( "while ( yy_current_state != %d );\n",
    jamstate );

  if ( ! reject && ! interactive )
   {



   indent_puts( "yy_cp = yy_last_accepting_cpos;" );
   indent_puts(
    "yy_current_state = yy_last_accepting_state;" );
   }
  }
 }




void gen_next_state( worry_about_NULs )
int worry_about_NULs;
 {
 char char_map[256];

 if ( worry_about_NULs && ! nultrans )
  {
  if ( useecs )
   (void) sprintf( char_map,
    "(*yy_cp ? yy_ec[YY_SC_TO_UI(*yy_cp)] : %d)",
     NUL_ec );
  else
   (void) sprintf( char_map,
    "(*yy_cp ? YY_SC_TO_UI(*yy_cp) : %d)", NUL_ec );
  }

 else
  strcpy( char_map, useecs ?
   "yy_ec[YY_SC_TO_UI(*yy_cp)]" : "YY_SC_TO_UI(*yy_cp)" );

 if ( worry_about_NULs && nultrans )
  {
  if ( ! fulltbl && ! fullspd )

   gen_backing_up();

  indent_puts( "if ( *yy_cp )" );
  (++indent_level);
  indent_puts( "{" );
  }

 if ( fulltbl )
  indent_put2s(
   "yy_current_state = yy_nxt[yy_current_state][%s];",
    char_map );

 else if ( fullspd )
  indent_put2s(
   "yy_current_state += yy_current_state[%s].yy_nxt;",
    char_map );

 else
  gen_next_compressed_state( char_map );

 if ( worry_about_NULs && nultrans )
  {

  indent_puts( "}" );
  (--indent_level);
  indent_puts( "else" );
  (++indent_level);
  indent_puts(
   "yy_current_state = yy_NUL_trans[yy_current_state];" );
  (--indent_level);
  }

 if ( fullspd || fulltbl )
  gen_backing_up();

 if ( reject )
  indent_puts( "*yy_state_ptr++ = yy_current_state;" );
 }




void gen_NUL_trans()
 {



 int need_backing_up = (num_backing_up > 0 && ! reject);

 if ( need_backing_up && (! nultrans || fullspd || fulltbl) )



  indent_puts( "register char *yy_cp = yy_c_buf_p;" );

 outc( '\n' );

 if ( nultrans )
  {
  indent_puts(
   "yy_current_state = yy_NUL_trans[yy_current_state];" );
  indent_puts( "yy_is_jam = (yy_current_state == 0);" );
  }

 else if ( fulltbl )
  {
  do_indent();
  out_dec( "yy_current_state = yy_nxt[yy_current_state][%d];\n",
   NUL_ec );
  indent_puts( "yy_is_jam = (yy_current_state <= 0);" );
  }

 else if ( fullspd )
  {
  do_indent();
  out_dec( "register int yy_c = %d;\n", NUL_ec );

  indent_puts(
  "register yyconst struct yy_trans_info *yy_trans_info;\n" );
  indent_puts(
  "yy_trans_info = &yy_current_state[(unsigned int) yy_c];" );
  indent_puts( "yy_current_state += yy_trans_info->yy_nxt;" );

  indent_puts(
   "yy_is_jam = (yy_trans_info->yy_verify != yy_c);" );
  }

 else
  {
  char NUL_ec_str[20];

  (void) sprintf( NUL_ec_str, "%d", NUL_ec );
  gen_next_compressed_state( NUL_ec_str );
# 3387 "flex_single_original.c"
  if ( reject )
   {
   do_indent();
   out_dec( "yy_is_jam = (yy_current_state == %d);\n", jamstate );





   indent_puts( "if ( ! yy_is_jam )" );





            (--indent_level);
            indent_puts( "*yy_state_ptr++ = yy_current_state;" );
            (++indent_level);

   }
  }





 if ( need_backing_up && (fullspd || fulltbl) )
  {
  outc( '\n' );
  indent_puts( "if ( ! yy_is_jam )" );
  (++indent_level);
  indent_puts( "{" );
  gen_backing_up();
  indent_puts( "}" );
  (--indent_level);
  }
 }




void gen_start_state()
 {
 if ( fullspd )
  {
  if ( bol_needed )
   {
   indent_puts(
 "yy_current_state = yy_start_state_list[yy_start + YY_AT_BOL()];" );
   }
  else
   indent_puts(
   "yy_current_state = yy_start_state_list[yy_start];" );
  }

 else
  {
  indent_puts( "yy_current_state = yy_start;" );

  if ( bol_needed )
   indent_puts( "yy_current_state += YY_AT_BOL();" );

  if ( reject )
   {

   indent_puts( "yy_state_ptr = yy_state_buf;" );
   indent_puts( "*yy_state_ptr++ = yy_current_state;" );
   }
  }
 }




void gentabs()
 {
 int i, j, k, *accset, nacc, *acc_array, total_states;
 int end_of_buffer_action = num_rules + 1;

 acc_array = (int *) allocate_array( current_max_dfas, sizeof( int ) );
 nummt = 0;






 ++num_backing_up;

 if ( reject )
  {






  int EOB_accepting_list[2];


  EOB_accepting_list[0] = 0;
  EOB_accepting_list[1] = end_of_buffer_action;
  accsiz[end_of_buffer_state] = 1;
  dfaacc[end_of_buffer_state].dfaacc_set = EOB_accepting_list;

  out_str_dec( long_align ? C_long_decl : C_short_decl,
   "yy_acclist", ((numas) > (1) ? (numas) : (1)) + 1 );

  j = 1;

  for ( i = 1; i <= lastdfa; ++i )
   {
   acc_array[i] = j;

   if ( accsiz[i] != 0 )
    {
    accset = dfaacc[i].dfaacc_set;
    nacc = accsiz[i];

    if ( trace )
     fprintf( err,
      ("state # %d accepts: "),
      i );

    for ( k = 1; k <= nacc; ++k )
     {
     int accnum = accset[k];

     ++j;

     if ( variable_trailing_context_rules &&
       ! (accnum & 0x4000) &&
        accnum > 0 && accnum <= num_rules &&
       rule_type[accnum] == 1 )
      {




      accnum |= 0x2000;
      }

     mkdata( accnum );

     if ( trace )
      {
      fprintf( err, "[%d]",
       accset[k] );

      if ( k < nacc )
       fputs( ", ", err );
      else
       
# 3539 "flex_single_original.c" 3 4
      _IO_putc (
# 3539 "flex_single_original.c"
      '\n'
# 3539 "flex_single_original.c" 3 4
      , 
# 3539 "flex_single_original.c"
      err
# 3539 "flex_single_original.c" 3 4
      )
# 3539 "flex_single_original.c"
                       ;
      }
     }
    }
   }


  acc_array[i] = j;

  dataend();
  }

 else
  {
  dfaacc[end_of_buffer_state].dfaacc_state = end_of_buffer_action;

  for ( i = 1; i <= lastdfa; ++i )
   acc_array[i] = dfaacc[i].dfaacc_state;


  acc_array[i] = 0;
  }
# 3570 "flex_single_original.c"
 k = lastdfa + 2;

 if ( reject )





  ++k;

 out_str_dec( long_align ? C_long_decl : C_short_decl, "yy_accept", k );

 for ( i = 1; i <= lastdfa; ++i )
  {
  mkdata( acc_array[i] );

  if ( ! reject && trace && acc_array[i] )
   fprintf( err, ("state # %d accepts: [%d]\n"),
    i, acc_array[i] );
  }


 mkdata( acc_array[i] );

 if ( reject )

  mkdata( acc_array[i] );

 dataend();

 if ( useecs )
  genecs();

 if ( usemecs )
  {




  if ( trace )
   fputs( ("\n\nMeta-Equivalence Classes:\n"),
         err );

  out_str_dec( C_int_decl, "yy_meta", numecs + 1 );

  for ( i = 1; i <= numecs; ++i )
   {
   if ( trace )
    fprintf( err, "%d = %d\n",
     i, ((tecbck[i]) < 0 ? -(tecbck[i]) : (tecbck[i])) );

   mkdata( ((tecbck[i]) < 0 ? -(tecbck[i]) : (tecbck[i])) );
   }

  dataend();
  }

 total_states = lastdfa + numtemps;

 out_str_dec( (tblend >= 32700 || long_align) ?
   C_long_decl : C_short_decl,
  "yy_base", total_states + 1 );

 for ( i = 1; i <= lastdfa; ++i )
  {
  register int d = def[i];

  if ( base[i] == -32766 )
   base[i] = jambase;

  if ( d == -32766 )
   def[i] = jamstate;

  else if ( d < 0 )
   {

   ++tmpuses;
   def[i] = lastdfa - d + 1;
   }

  mkdata( base[i] );
  }


 mkdata( base[i] );

 for ( ++i ; i <= total_states; ++i )
  {
  mkdata( base[i] );
  def[i] = jamstate;
  }

 dataend();

 out_str_dec( (total_states >= 32700 || long_align) ?
   C_long_decl : C_short_decl,
  "yy_def", total_states + 1 );

 for ( i = 1; i <= total_states; ++i )
  mkdata( def[i] );

 dataend();

 out_str_dec( (total_states >= 32700 || long_align) ?
   C_long_decl : C_short_decl,
  "yy_nxt", tblend + 1 );

 for ( i = 1; i <= tblend; ++i )
  {



  if ( chk[i] == 0 || nxt[i] == 0 )
   nxt[i] = jamstate;

  mkdata( nxt[i] );
  }

 dataend();

 out_str_dec( (total_states >= 32700 || long_align) ?
   C_long_decl : C_short_decl,
  "yy_chk", tblend + 1 );

 for ( i = 1; i <= tblend; ++i )
  {
  if ( chk[i] == 0 )
   ++nummt;

  mkdata( chk[i] );
  }

 dataend();
 }






void indent_put2s( fmt, arg )
char fmt[], arg[];
 {
 do_indent();
 out_str( fmt, arg );
 outn( "" );
 }






void indent_puts( str )
char str[];
 {
 do_indent();
 outn( str );
 }





void make_tables()
 {
 register int i;
 int did_eof_rule = 0;

 skelout();




 indent_level = 1;



    if ( yymore_used )

  {
  indent_puts( "yytext_ptr -= yy_more_len; \\" );
  indent_puts( "yyleng = (int) (yy_cp - yytext_ptr); \\" );
  }

 else
  indent_puts( "yyleng = (int) (yy_cp - yy_bp); \\" );


 skelout();
 if ( yytext_is_array )
  {
  if ( yymore_used )






   indent_puts( "if ( yyleng >= YYLMAX ) \\" );
  else
   indent_puts(
    "if ( yyleng + yy_more_offset >= YYLMAX ) \\" );


  (++indent_level);
  indent_puts(
  "YY_FATAL_ERROR( \"token too large, exceeds YYLMAX\" ); \\" );
  (--indent_level);

  if ( yymore_used )
   {
   indent_puts(
"yy_flex_strncpy( &yytext[yy_more_offset], yytext_ptr, yyleng + 1 ); \\" );
   indent_puts( "yyleng += yy_more_offset; \\" );
   indent_puts(
    "yy_prev_more_offset = yy_more_offset; \\" );
   indent_puts( "yy_more_offset = 0; \\" );
   }
  else
   {
   indent_puts(
  "yy_flex_strncpy( yytext, yytext_ptr, yyleng + 1 ); \\" );
   }
  }

 indent_level = 0;

 skelout();


 out_dec( "#define YY_NUM_RULES %d\n", num_rules );
 out_dec( "#define YY_END_OF_BUFFER %d\n", num_rules + 1 );

 if ( fullspd )
  {



  int total_table_size = tblend + numecs + 1;
  char *trans_offset_type =
   (total_table_size >= 32700 || long_align) ?
    "long" : "short";

  indent_level = 0;
  indent_puts( "struct yy_trans_info" );
  (++indent_level);
  indent_puts( "{" );

  if ( long_align )
   indent_puts( "long yy_verify;" );
  else
   indent_puts( "short yy_verify;" );
# 3832 "flex_single_original.c"
  indent_put2s( "%s yy_nxt;", trans_offset_type );
  indent_puts( "};" );
  (--indent_level);
  }

 if ( fullspd )
  genctbl();
 else if ( fulltbl )
  genftbl();
 else
  gentabs();





 if ( num_backing_up > 0 && ! reject )
  {
  if ( ! C_plus_plus )
   {
   indent_puts(
   "static yy_state_type yy_last_accepting_state;" );
   indent_puts(
    "static char *yy_last_accepting_cpos;\n" );
   }
  }

 if ( nultrans )
  {
  out_str_dec( C_state_decl, "yy_NUL_trans", lastdfa + 1 );

  for ( i = 1; i <= lastdfa; ++i )
   {
   if ( fullspd )
    out_dec( "    &yy_transition[%d],\n", base[i] );
   else
    mkdata( nultrans[i] );
   }

  dataend();
  }

 if ( ddebug )
  {
  if ( ! C_plus_plus )
   {
   indent_puts( "extern int yy_flex_debug;" );
   indent_puts( "int yy_flex_debug = 1;\n" );
   }

  out_str_dec( long_align ? C_long_decl : C_short_decl,
   "yy_rule_linenum", num_rules );
  for ( i = 1; i < num_rules; ++i )
   mkdata( rule_linenum[i] );
  dataend();
  }

 if ( reject )
  {

  if ( ! C_plus_plus )
   {
   outn(
 "static yy_state_type yy_state_buf[YY_BUF_SIZE + 2], *yy_state_ptr;" );
   outn( "static char *yy_full_match;" );
   outn( "static int yy_lp;" );
   }

  if ( variable_trailing_context_rules )
   {
   if ( ! C_plus_plus )
    {
    outn(
    "static int yy_looking_for_trail_begin = 0;" );
    outn( "static int yy_full_lp;" );
    outn( "static int *yy_full_state;" );
    }

   out_hex( "#define YY_TRAILING_MASK 0x%x\n",
    (unsigned int) 0x2000 );
   out_hex( "#define YY_TRAILING_HEAD_MASK 0x%x\n",
    (unsigned int) 0x4000 );
   }

  outn( "#define REJECT \\" );
  outn( "{ \\" );
  outn(
 "*yy_cp = yy_hold_char; /* undo effects of setting up yytext */ \\" );
  outn(
 "yy_cp = yy_full_match; /* restore poss. backed-over text */ \\" );

  if ( variable_trailing_context_rules )
   {
   outn(
  "yy_lp = yy_full_lp; /* restore orig. accepting pos. */ \\" );
   outn(
  "yy_state_ptr = yy_full_state; /* restore orig. state */ \\" );
   outn(
 "yy_current_state = *yy_state_ptr; /* restore curr. state */ \\" );
   }

  outn( "++yy_lp; \\" );
  outn( "goto find_rule; \\" );

  outn( "}" );
  }

 else
  {
  outn(
  "/* The intent behind this definition is that it'll catch" );
  outn( " * any uses of REJECT which flex missed." );
  outn( " */" );
  outn( "#define REJECT reject_used_but_not_detected" );
  }

 if ( yymore_used )
  {
  if ( ! C_plus_plus )
   {



    indent_puts( "static int yy_more_flag = 0;" );

   if ( yytext_is_array )
    {
    indent_puts( "static int yy_more_offset = 0;" );
    indent_puts(
     "static int yy_prev_more_offset = 0;" );
    }
   else
    {
    indent_puts( "static int yy_more_flag = 0;" );
    indent_puts( "static int yy_more_len = 0;" );
    }
   }



        if ( ! yytext_is_array )

   {
   indent_puts(
 "#define yymore() (yy_more_offset = yy_flex_strlen( yytext ))" );
   indent_puts( "#define YY_NEED_STRLEN" );
   indent_puts( "#define YY_MORE_ADJ 0" );
   indent_puts( "#define YY_RESTORE_YY_MORE_OFFSET \\" );
   (++indent_level);
   indent_puts( "{ \\" );
   indent_puts( "yy_more_offset = yy_prev_more_offset; \\" );
   indent_puts( "yyleng -= yy_more_offset; \\" );
   indent_puts( "}" );
   (--indent_level);
   }
  else
   {
   indent_puts( "#define yymore() (yy_more_flag = 1)" );
   indent_puts( "#define YY_MORE_ADJ yy_more_len" );
   indent_puts( "#define YY_RESTORE_YY_MORE_OFFSET" );
   }
  }

 else
  {
  indent_puts( "#define yymore() yymore_used_but_not_detected" );
  indent_puts( "#define YY_MORE_ADJ 0" );





  }

 if ( ! C_plus_plus )
  {
  if ( yytext_is_array )
   {
   outn( "#ifndef YYLMAX" );
   outn( "#define YYLMAX 8192" );
   outn( "#endif\n" );
   outn( "char yytext[YYLMAX];" );
   outn( "char *yytext_ptr;" );
   }

  else
   outn( "char *yytext;" );
  }

 out( &action_array[defs1_offset] );

 line_directive_out( 
# 4023 "flex_single_original.c" 3 4
                    stdout
# 4023 "flex_single_original.c"
                          , 0 );

 skelout();

 if ( ! C_plus_plus )
  {
  if ( use_read )
   {
   outn(
"\tif ( (result = read( fileno(yyin), (char *) buf, max_size )) < 0 ) \\" );
   outn(
  "\t\tYY_FATAL_ERROR( \"input in flex scanner failed\" );" );
   }

  else
   {
   outn(
   "\tif ( yy_current_buffer->yy_is_interactive ) \\" );
   outn( "\t\t{ \\" );
   outn( "\t\tint c = '*', n; \\" );
   outn( "\t\tfor ( n = 0; n < max_size && \\" );
 outn( "\t\t\t     (c = getc( yyin )) != EOF && c != '\\n'; ++n ) \\" );
   outn( "\t\t\tbuf[n] = (char) c; \\" );
   outn( "\t\tif ( c == '\\n' ) \\" );



   outn( "\t\t\buf[n++] = (char) c; \\" );

   outn( "\t\tif ( c == EOF && ferror( yyin ) ) \\" );
   outn(
 "\t\t\tYY_FATAL_ERROR( \"input in flex scanner failed\" ); \\" );
   outn( "\t\tresult = n; \\" );
   outn( "\t\t} \\" );
   outn(
 "\telse if ( ((result = fread( buf, 1, max_size, yyin )) == 0) \\" );
   outn( "\t\t  && ferror( yyin ) ) \\" );
   outn(
  "\t\tYY_FATAL_ERROR( \"input in flex scanner failed\" );" );
   }
  }

 skelout();

 indent_puts( "#define YY_RULE_SETUP \\" );
 (++indent_level);
 if ( bol_needed )
  {
  indent_puts( "if ( yyleng > 0 ) \\" );
  (++indent_level);
  indent_puts( "yy_current_buffer->yy_at_bol = \\" );
  indent_puts( "\t\t(yytext[yyleng - 1] == '\\n'); \\" );
  (--indent_level);
  }
 indent_puts( "YY_USER_ACTION" );
 (--indent_level);

 skelout();


 out( &action_array[prolog_offset] );

 line_directive_out( 
# 4085 "flex_single_original.c" 3 4
                    stdout
# 4085 "flex_single_original.c"
                          , 0 );

 skelout();

 indent_level = 2;




 if ( yymore_used || yytext_is_array )

  {
  indent_puts( "yy_more_len = 0;" );
  indent_puts( "if ( yy_more_flag )" );
  (++indent_level);
  indent_puts( "{" );
  indent_puts( "yy_more_len = yy_c_buf_p - yytext_ptr;" );
  indent_puts( "yy_more_flag = 0;" );
  indent_puts( "}" );
  (--indent_level);
  }

 skelout();

 gen_start_state();


 outn( "yy_match:" );
 gen_next_match();

 skelout();
 indent_level = 2;
 gen_find_action();

 skelout();
 if ( do_yylineno )
  {
  indent_puts( "if ( yy_act != YY_END_OF_BUFFER )" );
  (++indent_level);
  indent_puts( "{" );
  indent_puts( "int yyl;" );
  indent_puts( "for ( yyl = 0; yyl < yyleng; ++yyl )" );
  (++indent_level);
  indent_puts( "if ( yytext[yyl] == '\\n' )" );
  (++indent_level);
  indent_puts( "++yylineno;" );
  (--indent_level);
  (--indent_level);
  indent_puts( "}" );
  (--indent_level);
  }

 skelout();
 if ( ddebug )
  {
  indent_puts( "if ( yy_flex_debug )" );
  (++indent_level);

  indent_puts( "{" );
  indent_puts( "if ( yy_act == 0 )" );
  (++indent_level);
  indent_puts( C_plus_plus ?
   "cerr << \"--scanner backing up\\n\";" :
   "fprintf( err, \"--scanner backing up\\n\" );" );
  (--indent_level);

  do_indent();
  out_dec( "else if ( yy_act < %d )\n", num_rules );
  (++indent_level);

  if ( C_plus_plus )
   {
   indent_puts(
 "cerr << \"--accepting rule at line \" << yy_rule_linenum[yy_act] <<" );
   indent_puts(
   "         \"(\\\"\" << yytext << \"\\\")\\n\";" );
   }
  else
   {
   indent_puts(
 "fprintf( err, \"--accepting rule at line %d (\\\"%s\\\")\\n\"," );

   indent_puts(
    "         yy_rule_linenum[yy_act], yytext );" );
   }

  (--indent_level);

  do_indent();
  out_dec( "else if ( yy_act == %d )\n", num_rules );
  (++indent_level);

  if ( C_plus_plus )
   {
   indent_puts(
"cerr << \"--accepting default rule (\\\"\" << yytext << \"\\\")\\n\";" );
   }
  else
   {
   indent_puts(
 "fprintf( err, \"--accepting default rule (\\\"%s\\\")\\n\"," );
   indent_puts( "         yytext );" );
   }

  (--indent_level);

  do_indent();
  out_dec( "else if ( yy_act == %d )\n", num_rules + 1 );
  (++indent_level);

  indent_puts( C_plus_plus ?
   "cerr << \"--(end of buffer or a NUL)\\n\";" :
  "fprintf( err, \"--(end of buffer or a NUL)\\n\" );" );

  (--indent_level);

  do_indent();
  outn( "else" );
  (++indent_level);

  if ( C_plus_plus )
   {
   indent_puts(
 "cerr << \"--EOF (start condition \" << YY_START << \")\\n\";" );
   }
  else
   {
   indent_puts(
 "fprintf( err, \"--EOF (start condition %d)\\n\", YY_START );" );
   }

  (--indent_level);

  indent_puts( "}" );
  (--indent_level);
  }


 skelout();
 (++indent_level);
 gen_bu_action();
 out( &action_array[action_offset] );

 line_directive_out( 
# 4228 "flex_single_original.c" 3 4
                    stdout
# 4228 "flex_single_original.c"
                          , 0 );


 for ( i = 1; i <= lastsc; ++i )
  if ( ! sceof[i] )
   {
   do_indent();
   out_str( "case YY_STATE_EOF(%s):\n", scname[i] );
   did_eof_rule = 1;
   }

 if ( did_eof_rule )
  {
  (++indent_level);
  indent_puts( "yyterminate();" );
  (--indent_level);
  }







 skelout();
 indent_level = 4;

 if ( fullspd || fulltbl )
  indent_puts( "yy_cp = yy_c_buf_p;" );

 else
  {
  if ( ! reject && ! interactive )
   {



   indent_puts( "yy_cp = yy_last_accepting_cpos;" );
   indent_puts(
    "yy_current_state = yy_last_accepting_state;" );
   }

  else




   indent_puts( "yy_cp = yy_c_buf_p;" );
  }



 indent_level = 1;
 skelout();

 gen_start_state();

 indent_level = 2;
 skelout();
 gen_next_state( 1 );

 indent_level = 1;
 skelout();
 gen_NUL_trans();

 skelout();
 if ( do_yylineno )
  {
  indent_puts( "if ( c == '\\n' )" );
  (++indent_level);
  indent_puts( "--yylineno;" );
  (--indent_level);
  }

 skelout();

 if ( bol_needed )
  {
  indent_puts( "yy_current_buffer->yy_at_bol = (c == '\\n');" );
  if ( do_yylineno )
   {
   indent_puts( "if ( yy_current_buffer->yy_at_bol )" );
   (++indent_level);
   indent_puts( "++yylineno;" );
   (--indent_level);
   }
  }

 else if ( do_yylineno )
  {
  indent_puts( "if ( c == '\\n' )" );
  (++indent_level);
  indent_puts( "++yylineno;" );
  (--indent_level);
  }

 skelout();



 line_directive_out( 
# 4328 "flex_single_original.c" 3 4
                    stdout
# 4328 "flex_single_original.c"
                          , 1 );

 if ( sectnum == 3 )
  (void) flexscan();
 }
# 4365 "flex_single_original.c"
void action_define( defname, value )
char *defname;
int value;
 {
 char buf[2048];

 if ( (int) strlen( defname ) > 2048 / 2 )
  {
  format_pinpoint_message( ("name \"%s\" ridiculously long"),
   defname );
  return;
  }

 sprintf( buf, "#define %s %d\n", defname, value );
 add_action( buf );
 }


void add_action( new_text )
char *new_text;
 {
 int len = strlen( new_text );

 while ( len + action_index >= action_size - 10 )
  {
  int new_size = action_size * 2;

  if ( new_size <= 0 )



   action_size += action_size / 8;
  else
   action_size = new_size;

  action_array =
   (char *) reallocate_array( (void *) action_array, action_size, sizeof( char ) );
  }

 strcpy( &action_array[action_index], new_text );

 action_index += len;
 }




void *allocate_array( size, element_size )
int size;
size_t element_size;
 {
 register void *mem;
 size_t num_bytes = element_size * size;

 mem = flex_alloc( num_bytes );
 if ( ! mem )
  flexfatal(
   ("memory allocation failed in allocate_array()") );

 return mem;
 }




int all_lower( str )
register char *str;
 {
 while ( *str )
  {
  if ( ! 
# 4435 "flex_single_original.c" 3 4
        (((
# 4435 "flex_single_original.c"
        (unsigned char) *str
# 4435 "flex_single_original.c" 3 4
        ) & ~0x7f) == 0) 
# 4435 "flex_single_original.c"
                               || ! 
# 4435 "flex_single_original.c" 3 4
                                    ((*__ctype_b_loc ())[(int) ((
# 4435 "flex_single_original.c"
                                    *str
# 4435 "flex_single_original.c" 3 4
                                    ))] & (unsigned short int) _ISlower) 
# 4435 "flex_single_original.c"
                                                    )
   return 0;
  ++str;
  }

 return 1;
 }




int all_upper( str )
register char *str;
 {
 while ( *str )
  {
  if ( ! 
# 4451 "flex_single_original.c" 3 4
        (((
# 4451 "flex_single_original.c"
        (unsigned char) *str
# 4451 "flex_single_original.c" 3 4
        ) & ~0x7f) == 0) 
# 4451 "flex_single_original.c"
                               || ! 
# 4451 "flex_single_original.c" 3 4
                                    ((*__ctype_b_loc ())[(int) ((
# 4451 "flex_single_original.c"
                                    *str
# 4451 "flex_single_original.c" 3 4
                                    ))] & (unsigned short int) _ISupper) 
# 4451 "flex_single_original.c"
                                                    )
   return 0;
  ++str;
  }

 return 1;
 }
# 4475 "flex_single_original.c"
void bubble( v, n )
int v[], n;
 {
 register int i, j, k;

 for ( i = n; i > 1; --i )
  for ( j = 1; j < i; ++j )
   if ( v[j] > v[j + 1] )
    {
    k = v[j];
    v[j] = v[j + 1];
    v[j + 1] = k;
    }
 }







void check_char( c )
int c;
 {
 if ( c >= 256 )
  lerrsf( ("bad character '%s' detected in check_char()"),
   readable_form( c ) );

 if ( c >= csize )
  lerrsf(
  ("scanner requires -8 flag to use the character %s"),
   readable_form( c ) );
 }





unsigned char clower( c )
register int c;
 {
 return (unsigned char) ((
# 4516 "flex_single_original.c" 3 4
                (((
# 4516 "flex_single_original.c"
                c
# 4516 "flex_single_original.c" 3 4
                ) & ~0x7f) == 0) 
# 4516 "flex_single_original.c"
                             && 
# 4516 "flex_single_original.c" 3 4
                                ((*__ctype_b_loc ())[(int) ((
# 4516 "flex_single_original.c"
                                c
# 4516 "flex_single_original.c" 3 4
                                ))] & (unsigned short int) _ISupper)
# 4516 "flex_single_original.c"
                                            ) ? tolower( c ) : c);
 }




char *copy_string( str )
register const char *str;
 {
 register const char *c1;
 register char *c2;
 char *copy;
 unsigned int size;


 for ( c1 = str; *c1; ++c1 )
  ;

 size = (c1 - str + 1) * sizeof( char );
 copy = (char *) flex_alloc( size );

 if ( copy == 
# 4537 "flex_single_original.c" 3 4
             ((void *)0) 
# 4537 "flex_single_original.c"
                  )
  flexfatal( ("dynamic memory failure in copy_string()") );

 for ( c2 = copy; (*c2++ = *str++) != 0; )
  ;

 return copy;
 }






unsigned char *copy_unsigned_string( str )
register unsigned char *str;
 {
 register unsigned char *c;
 unsigned char *copy;


 for ( c = str; *c; ++c )
  ;

 copy = (unsigned char *) allocate_array( c - str + 1, sizeof( unsigned char ) );

 for ( c = copy; (*c++ = *str++) != 0; )
  ;

 return copy;
 }
# 4588 "flex_single_original.c"
void cshell( v, n, special_case_0 )
unsigned char v[];
int n, special_case_0;
 {
 int gap, i, j, jg;
 unsigned char k;

 for ( gap = n / 2; gap > 0; gap = gap / 2 )
  for ( i = gap; i < n; ++i )
   for ( j = i - gap; j >= 0; j = j - gap )
    {
    jg = j + gap;

    if ( special_case_0 )
     {
     if ( v[jg] == 0 )
      break;

     else if ( v[j] != 0 && v[j] <= v[jg] )
      break;
     }

    else if ( v[j] <= v[jg] )
     break;

    k = v[j];
    v[j] = v[jg];
    v[jg] = k;
    }
 }




void dataend()
 {
 if ( datapos > 0 )
  dataflush();


 outn( "    } ;\n" );

 dataline = 0;
 datapos = 0;
 }




void dataflush()
 {
 outc( '\n' );

 if ( ++dataline >= 10 )
  {



  outc( '\n' );
  dataline = 0;
  }


 datapos = 0;
 }




void flexerror( msg )
const char msg[];
 {
 fprintf( err, "%s: %s\n", program_name, msg );
 flexend( 1 );
 }




void flexfatal( msg )
const char msg[];
 {
 fprintf( err, ("%s: fatal internal error, %s\n"),
  program_name, msg );
 exit( 1 );
 }




int htoi( str )
unsigned char str[];
 {
 unsigned int result;

 (void) sscanf( (char *) str, "%x", &result );

 return result;
 }




void lerrif( msg, arg )
const char msg[];
int arg;
 {
 char errmsg[2048];
 (void) sprintf( errmsg, msg, arg );
 flexerror( errmsg );
 }




void lerrsf( msg, arg )
const char msg[], arg[];
 {
 char errmsg[2048];

 (void) sprintf( errmsg, msg, arg );
 flexerror( errmsg );
 }




void line_directive_out( output_file, do_infile )
FILE *output_file;
int do_infile;
 {
 char directive[2048], filename[2048];
 char *s1, *s2, *s3;
 static char line_fmt[] = "#line %d \"%s\"\n";

 if ( ! gen_line_dirs )
  return;

 if ( (do_infile && ! infilename) || (! do_infile && ! outfilename) )

  return;

 s1 = do_infile ? infilename : outfilename;
 s2 = filename;
 s3 = &filename[sizeof( filename ) - 2];

 while ( s2 < s3 && *s1 )
  {
  if ( *s1 == '\\' )

   *s2++ = '\\';

  *s2++ = *s1++;
  }

 *s2 = '\0';

 if ( do_infile )
  sprintf( directive, line_fmt, linenum, filename );
 else
  {
  if ( output_file == 
# 4749 "flex_single_original.c" 3 4
                     stdout 
# 4749 "flex_single_original.c"
                            )

   ++out_linenum;

  sprintf( directive, line_fmt, out_linenum, filename );
  }




 if ( output_file )
  {
  fputs( directive, output_file );
  }
 else
  add_action( directive );
 }






void mark_defs1()
 {
 defs1_offset = 0;
 action_array[action_index++] = '\0';
 action_offset = prolog_offset = action_index;
 action_array[action_index] = '\0';
 }





void mark_prolog()
 {
 action_array[action_index++] = '\0';
 action_offset = action_index;
 action_array[action_index] = '\0';
 }






void mk2data( value )
int value;
 {
 if ( datapos >= 10 )
  {
  outc( ',' );
  dataflush();
  }

 if ( datapos == 0 )

  out( "    " );

 else
  outc( ',' );

 ++datapos;

 out_dec( "%5d", value );
 }







void mkdata( value )
int value;
 {
 if ( datapos >= 10 )
  {
  outc( ',' );
  dataflush();
  }

 if ( datapos == 0 )

  out( "    " );
 else
  outc( ',' );

 ++datapos;

 out_dec( "%5d", value );
 }




int myctoi( array )
char array[];
 {
 int val = 0;

 (void) sscanf( array, "%d", &val );

 return val;
 }




unsigned char myesc( array )
unsigned char array[];
 {
 unsigned char c, esc_char;

 switch ( array[1] )
  {
  case 'b': return '\b';
  case 'f': return '\f';
  case 'n': return '\n';
  case 'r': return '\r';
  case 't': return '\t';


  case 'a': return '\a';
  case 'v': return '\v';





  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
   {
   int sptr = 1;

   while ( 
# 4891 "flex_single_original.c" 3 4
          (((
# 4891 "flex_single_original.c"
          array[sptr]
# 4891 "flex_single_original.c" 3 4
          ) & ~0x7f) == 0) 
# 4891 "flex_single_original.c"
                                 &&
    
# 4892 "flex_single_original.c" 3 4
   ((*__ctype_b_loc ())[(int) ((
# 4892 "flex_single_original.c"
   array[sptr]
# 4892 "flex_single_original.c" 3 4
   ))] & (unsigned short int) _ISdigit) 
# 4892 "flex_single_original.c"
                          )




    ++sptr;

   c = array[sptr];
   array[sptr] = '\0';

   esc_char = otoi( array + 1 );

   array[sptr] = c;

   return esc_char;
   }

  case 'x':
   {
   int sptr = 2;

   while ( 
# 4913 "flex_single_original.c" 3 4
          (((
# 4913 "flex_single_original.c"
          array[sptr]
# 4913 "flex_single_original.c" 3 4
          ) & ~0x7f) == 0) 
# 4913 "flex_single_original.c"
                                 &&
    
# 4914 "flex_single_original.c" 3 4
   ((*__ctype_b_loc ())[(int) ((
# 4914 "flex_single_original.c"
   (char) array[sptr]
# 4914 "flex_single_original.c" 3 4
   ))] & (unsigned short int) _ISxdigit) 
# 4914 "flex_single_original.c"
                                  )




    ++sptr;

   c = array[sptr];
   array[sptr] = '\0';

   esc_char = htoi( array + 2 );

   array[sptr] = c;

   return esc_char;
   }

  default:
   return array[1];
  }
 }




int otoi( str )
unsigned char str[];
 {
 unsigned int result;

 (void) sscanf( (char *) str, "%o", &result );
 return result;
 }






void out( str )
const char str[];
 {
 fputs( str, 
# 4956 "flex_single_original.c" 3 4
            stdout 
# 4956 "flex_single_original.c"
                   );
 out_line_count( str );
 }

void out_dec( fmt, n )
const char fmt[];
int n;
 {
 printf( fmt, n );
 out_line_count( fmt );
 }

void out_dec2( fmt, n1, n2 )
const char fmt[];
int n1, n2;
 {
 printf( fmt, n1, n2 );
 out_line_count( fmt );
 }

void out_hex( fmt, x )
const char fmt[];
unsigned int x;
 {
 printf( fmt, x );
 out_line_count( fmt );
 }

void out_line_count( str )
const char str[];
 {
 register int i;

 for ( i = 0; str[i]; ++i )
  if ( str[i] == '\n' )
   ++out_linenum;
 }

void out_str( fmt, str )
const char fmt[], str[];
 {
 printf( fmt, str );
 out_line_count( fmt );
 out_line_count( str );
 }

void out_str3( fmt, s1, s2, s3 )
const char fmt[], s1[], s2[], s3[];
 {
 printf( fmt, s1, s2, s3 );
 out_line_count( fmt );
 out_line_count( s1 );
 out_line_count( s2 );
 out_line_count( s3 );
 }

void out_str_dec( fmt, str, n )
const char fmt[], str[];
int n;
 {
 printf( fmt, str, n );
 out_line_count( fmt );
 out_line_count( str );
 }

void outc( c )
int c;
 {
 
# 5024 "flex_single_original.c" 3 4
_IO_putc (
# 5024 "flex_single_original.c"
c
# 5024 "flex_single_original.c" 3 4
, stdout)
# 5024 "flex_single_original.c"
                 ;

 if ( c == '\n' )
  ++out_linenum;
 }

void outn( str )
const char str[];
 {
 puts( str );
 out_line_count( str );
 ++out_linenum;
 }







char *readable_form( c )
register int c;
 {
 static char rform[10];

 if ( (c >= 0 && c < 32) || c >= 127 )
  {
  switch ( c )
   {
   case '\b': return "\\b";
   case '\f': return "\\f";
   case '\n': return "\\n";
   case '\r': return "\\r";
   case '\t': return "\\t";


   case '\a': return "\\a";
   case '\v': return "\\v";


   default:
    (void) sprintf( rform, "\\%.3o",
      (unsigned int) c );
    return rform;
   }
  }

 else if ( c == ' ' )
  return "' '";

 else
  {
  rform[0] = c;
  rform[1] = '\0';

  return rform;
  }
 }




void *reallocate_array( array, size, element_size )
void *array;
int size;
size_t element_size;
 {
 register void *new_array;
 size_t num_bytes = element_size * size;

 new_array = flex_realloc( array, num_bytes );
 if ( ! new_array )
  flexfatal( ("attempt to increase array size failed") );

 return new_array;
 }
# 5108 "flex_single_original.c"
void skelout()
 {
 char buf_storage[2048];
 char *buf = buf_storage;
 int do_copy = 1;




 while ( skelfile ?
  (fgets( buf, 2048, skelfile ) != 
# 5118 "flex_single_original.c" 3 4
                                     ((void *)0)
# 5118 "flex_single_original.c"
                                         ) :
  ((buf = (char *) skel[skel_ind++]) != 0) )
  {
  if ( buf[0] == '%' )
   {
   switch ( buf[1] )
    {
    case '%':
     return;

    case '+':
     do_copy = C_plus_plus;
     break;

    case '-':
     do_copy = ! C_plus_plus;
     break;

    case '*':
     do_copy = 1;
     break;

    default:
     flexfatal(
     ("bad line in skeleton file") );
    }
   }

  else if ( do_copy )
   {
   if ( skelfile )



    out( buf );
   else
    outn( buf );
   }
  }
 }
# 5166 "flex_single_original.c"
void transition_struct_out( element_v, element_n )
int element_v, element_n;
 {
 out_dec2( " {%4d,%4d },", element_v, element_n );

 datapos += 14;

 if ( datapos >= 79 - 14 )
  {
  outc( '\n' );

  if ( ++dataline % 10 == 0 )
   outc( '\n' );

  datapos = 0;
  }
 }





void *yy_flex_xmalloc( size )
int size;
 {
 void *result = flex_alloc( (size_t) size );

 if ( ! result )
  flexfatal(
   ("memory allocation failed in yy_flex_xmalloc()") );

 return result;
 }







void zero_out( region_ptr, size_in_bytes )
char *region_ptr;
size_t size_in_bytes;
 {
 register char *rp, *rp_end;

 rp = region_ptr;
 rp_end = region_ptr + size_in_bytes;

 while ( rp < rp_end )
  *rp++ = 0;
 }
# 5252 "flex_single_original.c"
int dupmachine (int);
void mkxtion (int, int);







void add_accept( mach, accepting_number )
int mach, accepting_number;
 {






 if ( transchar[finalst[mach]] == (256 + 1) )
  accptnum[finalst[mach]] = accepting_number;

 else
  {
  int astate = mkstate( (256 + 1) );
  accptnum[astate] = accepting_number;
  (void) link_machines( mach, astate );
  }
 }
# 5293 "flex_single_original.c"
int copysingl( singl, num )
int singl, num;
 {
 int copy, i;

 copy = mkstate( (256 + 1) );

 for ( i = 1; i <= num; ++i )
  copy = link_machines( copy, dupmachine( singl ) );

 return copy;
 }




void dumpnfa( state1 )
int state1;

 {
 int sym, tsp1, tsp2, anum, ns;

 fprintf( err,
 ("\n\n********** beginning dump of nfa with start state %d\n"),
  state1 );
# 5326 "flex_single_original.c"
 for ( ns = 1; ns <= lastnfa; ++ns )
  {
  fprintf( err, ("state # %4d\t"), ns );

  sym = transchar[ns];
  tsp1 = trans1[ns];
  tsp2 = trans2[ns];
  anum = accptnum[ns];

  fprintf( err, "%3d:  %4d, %4d", sym, tsp1, tsp2 );

  if ( anum != 0 )
   fprintf( err, "  [%d]", anum );

  fprintf( err, "\n" );
  }

 fprintf( err, ("********** end of dump\n") );
 }
# 5364 "flex_single_original.c"
int dupmachine( mach )
int mach;
 {
 int i, init, state_offset;
 int state = 0;
 int last = lastst[mach];

 for ( i = firstst[mach]; i <= last; ++i )
  {
  state = mkstate( transchar[i] );

  if ( trans1[i] != 0 )
   {
   mkxtion( finalst[state], trans1[i] + state - i );

   if ( transchar[i] == (256 + 1) &&
        trans2[i] != 0 )
    mkxtion( finalst[state],
     trans2[i] + state - i );
   }

  accptnum[state] = accptnum[i];
  }

 if ( state == 0 )
  flexfatal( ("empty machine in dupmachine()") );

 state_offset = state - i + 1;

 init = mach + state_offset;
 firstst[init] = firstst[mach] + state_offset;
 finalst[init] = finalst[mach] + state_offset;
 lastst[init] = lastst[mach] + state_offset;

 return init;
 }
# 5414 "flex_single_original.c"
void finish_rule( mach, variable_trail_rule, headcnt, trailcnt )
int mach, variable_trail_rule, headcnt, trailcnt;
 {
 char action_text[2048];

 add_accept( mach, num_rules );




 rule_linenum[num_rules] = linenum;




 if ( continued_action )
  --rule_linenum[num_rules];

 sprintf( action_text, "case %d:\n", num_rules );
 add_action( action_text );

 if ( variable_trail_rule )
  {
  rule_type[num_rules] = 1;

  if ( performance_report > 0 )
   fprintf( err,
   ("Variable trailing context rule at line %d\n"),
    rule_linenum[num_rules] );

  variable_trailing_context_rules = 1;
  }

 else
  {
  rule_type[num_rules] = 0;

  if ( headcnt > 0 || trailcnt > 0 )
   {



   char *scanner_cp = "yy_c_buf_p = yy_cp";
   char *scanner_bp = "yy_bp";

   add_action(
 "*yy_cp = yy_hold_char; /* undo effects of setting up yytext */\n" );

   if ( headcnt > 0 )
    {
    sprintf( action_text, "%s = %s + %d;\n",
    scanner_cp, scanner_bp, headcnt );
    add_action( action_text );
    }

   else
    {
    sprintf( action_text, "%s -= %d;\n",
     scanner_cp, trailcnt );
    add_action( action_text );
    }

   add_action(
   "YY_DO_BEFORE_ACTION; /* set up yytext again */\n" );
   }
  }






 if ( ! continued_action )
  add_action( "YY_RULE_SETUP\n" );

 line_directive_out( (FILE *) 0, 1 );
 }
# 5509 "flex_single_original.c"
int link_machines( first, last )
int first, last;
 {
 if ( first == 0 )
  return last;

 else if ( last == 0 )
  return first;

 else
  {
  mkxtion( finalst[first], last );
  finalst[first] = finalst[last];
  lastst[first] = ((lastst[first]) > (lastst[last]) ? (lastst[first]) : (lastst[last]));
  firstst[first] = ((firstst[first]) < (firstst[last]) ? (firstst[first]) : (firstst[last]));

  return first;
  }
 }
# 5537 "flex_single_original.c"
void mark_beginning_as_normal( mach )
register int mach;
 {
 switch ( state_type[mach] )
  {
  case 0x1:

   return;

  case 0x2:
   state_type[mach] = 0x1;

   if ( transchar[mach] == (256 + 1) )
    {
    if ( trans1[mach] != 0 )
     mark_beginning_as_normal(
      trans1[mach] );

    if ( trans2[mach] != 0 )
     mark_beginning_as_normal(
      trans2[mach] );
    }
   break;

  default:
   flexerror(
   ("bad state type in mark_beginning_as_normal()") );
   break;
  }
 }
# 5583 "flex_single_original.c"
int mkbranch( first, second )
int first, second;
 {
 int eps;

 if ( first == 0 )
  return second;

 else if ( second == 0 )
  return first;

 eps = mkstate( (256 + 1) );

 mkxtion( eps, first );
 mkxtion( eps, second );

 return eps;
 }
# 5611 "flex_single_original.c"
int mkclos( state )
int state;
 {
 return mkopt( mkposcl( state ) );
 }
# 5632 "flex_single_original.c"
int mkopt( mach )
int mach;
 {
 int eps;

 if ( ! (transchar[finalst[mach]] == (256 + 1) && trans1[finalst[mach]] == 0) )
  {
  eps = mkstate( (256 + 1) );
  mach = link_machines( mach, eps );
  }





 eps = mkstate( (256 + 1) );
 mach = link_machines( eps, mach );

 mkxtion( mach, finalst[mach] );

 return mach;
 }
# 5670 "flex_single_original.c"
int mkor( first, second )
int first, second;
 {
 int eps, orend;

 if ( first == 0 )
  return second;

 else if ( second == 0 )
  return first;

 else
  {



  eps = mkstate( (256 + 1) );

  first = link_machines( eps, first );

  mkxtion( first, second );

  if ( (transchar[finalst[first]] == (256 + 1) && trans1[finalst[first]] == 0) &&
       accptnum[finalst[first]] == 0 )
   {
   orend = finalst[first];
   mkxtion( finalst[second], orend );
   }

  else if ( (transchar[finalst[second]] == (256 + 1) && trans1[finalst[second]] == 0) &&
     accptnum[finalst[second]] == 0 )
   {
   orend = finalst[second];
   mkxtion( finalst[first], orend );
   }

  else
   {
   eps = mkstate( (256 + 1) );

   first = link_machines( first, eps );
   orend = finalst[first];

   mkxtion( finalst[second], orend );
   }
  }

 finalst[first] = orend;
 return first;
 }
# 5730 "flex_single_original.c"
int mkposcl( state )
int state;
 {
 int eps;

 if ( (transchar[finalst[state]] == (256 + 1) && trans1[finalst[state]] == 0) )
  {
  mkxtion( finalst[state], state );
  return state;
  }

 else
  {
  eps = mkstate( (256 + 1) );
  mkxtion( eps, state );
  return link_machines( state, eps );
  }
 }
# 5762 "flex_single_original.c"
int mkrep( mach, lb, ub )
int mach, lb, ub;
 {
 int base_mach, tail, copy, i;

 base_mach = copysingl( mach, lb - 1 );

 if ( ub == -1 )
  {
  copy = dupmachine( mach );
  mach = link_machines( mach,
  link_machines( base_mach, mkclos( copy ) ) );
  }

 else
  {
  tail = mkstate( (256 + 1) );

  for ( i = lb; i < ub; ++i )
   {
   copy = dupmachine( mach );
   tail = mkopt( link_machines( copy, tail ) );
   }

  mach = link_machines( mach, link_machines( base_mach, tail ) );
  }

 return mach;
 }
# 5809 "flex_single_original.c"
int mkstate( sym )
int sym;
 {
 if ( ++lastnfa >= current_mns )
  {
  if ( (current_mns += 1000) >= 31999 )
   lerrif(
  ("input rules are too complicated (>= %d NFA states)"),
    current_mns );

  ++num_reallocs;

  firstst = (int *) reallocate_array( (void *) firstst, current_mns, sizeof( int ) );
  lastst = (int *) reallocate_array( (void *) lastst, current_mns, sizeof( int ) );
  finalst = (int *) reallocate_array( (void *) finalst, current_mns, sizeof( int ) );
  transchar = (int *) reallocate_array( (void *) transchar, current_mns, sizeof( int ) );
  trans1 = (int *) reallocate_array( (void *) trans1, current_mns, sizeof( int ) );
  trans2 = (int *) reallocate_array( (void *) trans2, current_mns, sizeof( int ) );
  accptnum = (int *) reallocate_array( (void *) accptnum, current_mns, sizeof( int ) );
  assoc_rule =
   (int *) reallocate_array( (void *) assoc_rule, current_mns, sizeof( int ) );
  state_type =
   (int *) reallocate_array( (void *) state_type, current_mns, sizeof( int ) );
  }

 firstst[lastnfa] = lastnfa;
 finalst[lastnfa] = lastnfa;
 lastst[lastnfa] = lastnfa;
 transchar[lastnfa] = sym;
 trans1[lastnfa] = 0;
 trans2[lastnfa] = 0;
 accptnum[lastnfa] = 0;
 assoc_rule[lastnfa] = num_rules;
 state_type[lastnfa] = current_state_type;
# 5853 "flex_single_original.c"
 if ( sym < 0 )
  {




  }

 else if ( sym == (256 + 1) )
  ++numeps;

 else
  {
  check_char( sym );

  if ( useecs )

   mkechar( sym ? sym : csize, nextecm, ecgroup );
  }

 return lastnfa;
 }
# 5887 "flex_single_original.c"
void mkxtion( statefrom, stateto )
int statefrom, stateto;
 {
 if ( trans1[statefrom] == 0 )
  trans1[statefrom] = stateto;

 else if ( (transchar[statefrom] != (256 + 1)) ||
    (trans2[statefrom] != 0) )
  flexfatal( ("found too many transitions in mkxtion()") );

 else
  {
  ++eps2;
  trans2[statefrom] = stateto;
  }
 }



void new_rule()
 {
 if ( ++num_rules >= current_max_rules )
  {
  ++num_reallocs;
  current_max_rules += 100;
  rule_type = (int *) reallocate_array( (void *) rule_type, current_max_rules, sizeof( int ) )
                          ;
  rule_linenum = (int *) reallocate_array( (void *) rule_linenum, current_max_rules, sizeof( int ) )
                          ;
  rule_useful = (int *) reallocate_array( (void *) rule_useful, current_max_rules, sizeof( int ) )
                          ;
  }

 if ( num_rules > (0x2000 - 1) )
  lerrif( ("too many rules (> %d)!"), (0x2000 - 1) );

 rule_linenum[num_rules] = linenum;
 rule_useful[num_rules] = 0;
 }



const char *skel[] = {
  "/* A lexical scanner generated by flex */",
  "",
  "/* Scanner skeleton version:",
  " * $Header: /a1/cvsadm/cvsroot/expsir/csubjects/flex/versions.alt/versions.seeded/v4/flex.c,v 1.1.1.2 2003/09/02 20:21:59 expsir Exp $",
  " */",
  "",
  "#define FLEX_SCANNER",
  "#define YY_FLEX_MAJOR_VERSION 2",
  "#define YY_FLEX_MINOR_VERSION 5",
  "",
  "%-",
  "#include <stdio.h>",
  "%*",
  "",
  "",
  "/* cfront 1.2 defines \"c_plusplus\" instead of \"__cplusplus\" */",
  "#ifdef c_plusplus",
  "#ifndef __cplusplus",
  "#define __cplusplus",
  "#endif",
  "#endif",
  "",
  "",
  "#ifdef __cplusplus",
  "",
  "#include <stdlib.h>",
  "%+",
  "class istream;",
  "%*",
  "#include <unistd.h>",
  "",
  "/* Use prototypes in function declarations. */",
  "#define YY_USE_PROTOS",
  "",
  "/* The \"const\" storage-class-modifier is valid. */",
  "#define YY_USE_CONST",
  "",
  "#else	/* ! __cplusplus */",
  "",
  "#if __STDC__",
  "",
  "#define YY_USE_PROTOS",
  "#define YY_USE_CONST",
  "",
  "#endif	/* __STDC__ */",
  "#endif	/* ! __cplusplus */",
  "",
  "#ifdef __TURBOC__",
  " #pragma warn -rch",
  " #pragma warn -use",
  "#include <io.h>",
  "#include <stdlib.h>",
  "#define YY_USE_CONST",
  "#define YY_USE_PROTOS",
  "#endif",
  "",
  "#ifdef YY_USE_CONST",
  "#define yyconst const",
  "#else",
  "#define yyconst",
  "#endif",
  "",
  "",
  "#ifdef YY_USE_PROTOS",
  "#define YY_PROTO(proto) proto",
  "#else",
  "#define YY_PROTO(proto) ()",
  "#endif",
  "",
  "/* Returned upon end-of-file. */",
  "#define YY_NULL 0",
  "",
  "/* Promotes a possibly negative, possibly signed char to an unsigned",
  " * integer for use as an array index.  If the signed char is negative,",
  " * we want to instead treat it as an 8-bit unsigned char, hence the",
  " * double cast.",
  " */",
  "#define YY_SC_TO_UI(c) ((unsigned int) (unsigned char) c)",
  "",
  "/* Enter a start condition.  This macro really ought to take a parameter,",
  " * but we do it the disgusting crufty way forced on us by the ()-less",
  " * definition of BEGIN.",
  " */",
  "#define BEGIN yy_start = 1 + 2 *",
  "",
  "/* Translate the current start state into a value that can be later handed",
  " * to BEGIN to return to the state.  The YYSTATE alias is for lex",
  " * compatibility.",
  " */",
  "#define YY_START ((yy_start - 1) / 2)",
  "#define YYSTATE YY_START",
  "",
  "/* Action number for EOF rule of a given start state. */",
  "#define YY_STATE_EOF(state) (YY_END_OF_BUFFER + state + 1)",
  "",
  "/* Special action meaning \"start processing a new file\". */",
  "#define YY_NEW_FILE yyrestart( yyin )",
  "",
  "#define YY_END_OF_BUFFER_CHAR 0",
  "",
  "/* Size of default input buffer. */",
  "#define YY_BUF_SIZE 16384",
  "",
  "typedef struct yy_buffer_state *YY_BUFFER_STATE;",
  "",
  "extern int yyleng;",
  "%-",
  "extern FILE *yyin, *yyout;",
  "%*",
  "",
  "#define EOB_ACT_CONTINUE_SCAN 0",
  "#define EOB_ACT_END_OF_FILE 1",
  "#define EOB_ACT_LAST_MATCH 2",
  "",
  "/* The funky do-while in the following #define is used to turn the definition",
  " * int a single C statement (which needs a semi-colon terminator).  This",
  " * avoids problems with code like:",
  " *",
  " * 	if ( condition_holds )",
  " *		yyless( 5 );",
  " *	else",
  " *		do_something_else();",
  " *",
  " * Prior to using the do-while the compiler would get upset at the",
  " * \"else\" because it interpreted the \"if\" statement as being all",
  " * done when it reached the ';' after the yyless() call.",
  " */",
  "",
  "/* Return all but the first 'n' matched characters back to the input stream. */",
  "",
  "#define yyless(n) \\",
  "	do \\",
  "		{ \\",
  "		/* Undo effects of setting up yytext. */ \\",
  "		*yy_cp = yy_hold_char; \\",
  "		YY_RESTORE_YY_MORE_OFFSET \\",
  "		yy_c_buf_p = yy_cp = yy_bp + n - YY_MORE_ADJ; \\",
  "		YY_DO_BEFORE_ACTION; /* set up yytext again */ \\",
  "		} \\",
  "	while ( 0 )",
  "",
  "#define unput(c) yyunput( c, yytext_ptr )",
  "",
  "/* The following is because we cannot portably get our hands on size_t",
  " * (without autoconf's help, which isn't available because we want",
  " * flex-generated scanners to compile on their own).",
  " */",
  "typedef unsigned int yy_size_t;",
  "",
  "",
  "struct yy_buffer_state",
  "	{",
  "%-",
  "	FILE *yy_input_file;",
  "%+",
  "	istream* yy_input_file;",
  "%*",
  "",
  "	char *yy_ch_buf;		/* input buffer */",
  "	char *yy_buf_pos;		/* current position in input buffer */",
  "",
  "	/* Size of input buffer in bytes, not including room for EOB",
  "	 * characters.",
  "	 */",
  "	yy_size_t yy_buf_size;",
  "",
  "	/* Number of characters read into yy_ch_buf, not including EOB",
  "	 * characters.",
  "	 */",
  "	int yy_n_chars;",
  "",
  "	/* Whether we \"own\" the buffer - i.e., we know we created it,",
  "	 * and can realloc() it to grow it, and should free() it to",
  "	 * delete it.",
  "	 */",
  "	int yy_is_our_buffer;",
  "",
  "	/* Whether this is an \"interactive\" input source; if so, and",
  "	 * if we're using stdio for input, then we want to use getc()",
  "	 * instead of fread(), to make sure we stop fetching input after",
  "	 * each newline.",
  "	 */",
  "	int yy_is_interactive;",
  "",
  "	/* Whether we're considered to be at the beginning of a line.",
  "	 * If so, '^' rules will be active on the next match, otherwise",
  "	 * not.",
  "	 */",
  "	int yy_at_bol;",
  "",
  "	/* Whether to try to fill the input buffer when we reach the",
  "	 * end of it.",
  "	 */",
  "	int yy_fill_buffer;",
  "",
  "	int yy_buffer_status;",
  "#define YY_BUFFER_NEW 0",
  "#define YY_BUFFER_NORMAL 1",
  "	/* When an EOF's been seen but there's still some text to process",
  "	 * then we mark the buffer as YY_EOF_PENDING, to indicate that we",
  "	 * shouldn't try reading from the input source any more.  We might",
  "	 * still have a bunch of tokens to match, though, because of",
  "	 * possible backing-up.",
  "	 *",
  "	 * When we actually see the EOF, we change the status to \"new\"",
  "	 * (via yyrestart()), so that the user can continue scanning by",
  "	 * just pointing yyin at a new input file.",
  "	 */",
  "#define YY_BUFFER_EOF_PENDING 2",
  "	};",
  "",
  "%- Standard (non-C++) definition",
  "static YY_BUFFER_STATE yy_current_buffer = 0;",
  "%*",
  "",
  "/* We provide macros for accessing buffer states in case in the",
  " * future we want to put the buffer states in a more general",
  " * \"scanner state\".",
  " */",
  "#define YY_CURRENT_BUFFER yy_current_buffer",
  "",
  "",
  "%- Standard (non-C++) definition",
  "/* yy_hold_char holds the character lost when yytext is formed. */",
  "static char yy_hold_char;",
  "",
  "static int yy_n_chars;		/* number of characters read into yy_ch_buf */",
  "",
  "",
  "int yyleng;",
  "",
  "/* Points to current character in buffer. */",
  "static char *yy_c_buf_p = (char *) 0;",
  "static int yy_init = 1;		/* whether we need to initialize */",
  "static int yy_start = 0;	/* start state number */",
  "",
  "/* Flag which is used to allow yywrap()'s to do buffer switches",
  " * instead of setting up a fresh yyin.  A bit of a hack ...",
  " */",
  "static int yy_did_buffer_switch_on_eof;",
  "",
  "void yyrestart YY_PROTO(( FILE *input_file ));",
  "",
  "void yy_switch_to_buffer YY_PROTO(( YY_BUFFER_STATE new_buffer ));",
  "void yy_load_buffer_state YY_PROTO(( void ));",
  "YY_BUFFER_STATE yy_create_buffer YY_PROTO(( FILE *file, int size ));",
  "void yy_delete_buffer YY_PROTO(( YY_BUFFER_STATE b ));",
  "void yy_init_buffer YY_PROTO(( YY_BUFFER_STATE b, FILE *file ));",
  "void yy_flush_buffer YY_PROTO(( YY_BUFFER_STATE b ));",
  "#define YY_FLUSH_BUFFER yy_flush_buffer( yy_current_buffer )",
  "",
  "YY_BUFFER_STATE yy_scan_buffer YY_PROTO(( char *base, yy_size_t size ));",
  "YY_BUFFER_STATE yy_scan_string YY_PROTO(( yyconst char *str ));",
  "YY_BUFFER_STATE yy_scan_bytes YY_PROTO(( yyconst char *bytes, int len ));",
  "%*",
  "",
  "static void *yy_flex_alloc YY_PROTO(( yy_size_t ));",
  "static void *yy_flex_realloc YY_PROTO(( void *, yy_size_t ));",
  "static void yy_flex_free YY_PROTO(( void * ));",
  "",
  "#define yy_new_buffer yy_create_buffer",
  "",
  "#define yy_set_interactive(is_interactive) \\",
  "	{ \\",
  "	if ( ! yy_current_buffer ) \\",
  "		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \\",
  "	yy_current_buffer->yy_is_interactive = is_interactive; \\",
  "	}",
  "",
  "#define yy_set_bol(at_bol) \\",
  "	{ \\",
  "	if ( ! yy_current_buffer ) \\",
  "		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE ); \\",
  "	yy_current_buffer->yy_at_bol = at_bol; \\",
  "	}",
  "",
  "#define YY_AT_BOL() (yy_current_buffer->yy_at_bol)",
  "",
  "%% yytext/yyin/yyout/yy_state_type/yylineno etc. def's & init go here",
  "",
  "%- Standard (non-C++) definition",
  "static yy_state_type yy_get_previous_state YY_PROTO(( void ));",
  "static yy_state_type yy_try_NUL_trans YY_PROTO(( yy_state_type current_state ));",
  "static int yy_get_next_buffer YY_PROTO(( void ));",
  "static void yy_fatal_error YY_PROTO(( yyconst char msg[] ));",
  "%*",
  "",
  "/* Done after the current pattern has been matched and before the",
  " * corresponding action - sets up yytext.",
  " */",
  "#define YY_DO_BEFORE_ACTION \\",
  "	yytext_ptr = yy_bp; \\",
  "%% code to fiddle yytext and yyleng for yymore() goes here",
  "	yy_hold_char = *yy_cp; \\",
  "	*yy_cp = '\\0'; \\",
  "%% code to copy yytext_ptr to yytext[] goes here, if %array",
  "	yy_c_buf_p = yy_cp;",
  "",
  "%% data tables for the DFA and the user's section 1 definitions go here",
  "",
  "/* Macros after this point can all be overridden by user definitions in",
  " * section 1.",
  " */",
  "",
  "#ifndef YY_SKIP_YYWRAP",
  "#ifdef __cplusplus",
  "extern \"C\" int yywrap YY_PROTO(( void ));",
  "#else",
  "extern int yywrap YY_PROTO(( void ));",
  "#endif",
  "#endif",
  "",
  "%-",
  "#ifndef YY_NO_UNPUT",
  "static void yyunput YY_PROTO(( int c, char *buf_ptr ));",
  "#endif",
  "%*",
  "",
  "#ifndef yytext_ptr",
  "static void yy_flex_strncpy YY_PROTO(( char *, yyconst char *, int ));",
  "#endif",
  "",





  "static int yy_flex_strlen YY_PROTO(( yyconst char * ));",
  "#endif",
  "",
  "#ifndef YY_NO_INPUT",
  "%- Standard (non-C++) definition",
  "#ifdef __cplusplus",
  "static int yyinput YY_PROTO(( void ));",
  "#else",
  "static int input YY_PROTO(( void ));",
  "#endif",
  "%*",
  "#endif",
  "",
  "#if YY_STACK_USED",
  "static int yy_start_stack_ptr = 0;",
  "static int yy_start_stack_depth = 0;",
  "static int *yy_start_stack = 0;",
  "#ifndef YY_NO_PUSH_STATE",
  "static void yy_push_state YY_PROTO(( int new_state ));",
  "#endif",
  "#ifndef YY_NO_POP_STATE",
  "static void yy_pop_state YY_PROTO(( void ));",
  "#endif",
  "#ifndef YY_NO_TOP_STATE",
  "static int yy_top_state YY_PROTO(( void ));",
  "#endif",
  "",
  "#else",
  "#define YY_NO_PUSH_STATE 1",
  "#define YY_NO_POP_STATE 1",
  "#define YY_NO_TOP_STATE 1",
  "#endif",
  "",
  "#ifdef YY_MALLOC_DECL",
  "YY_MALLOC_DECL",
  "#else",
  "#if __STDC__",
  "#ifndef __cplusplus",
  "#include <stdlib.h>",
  "#endif",
  "#else",
  "/* Just try to get by without declaring the routines.  This will fail",
  " * miserably on non-ANSI systems for which sizeof(size_t) != sizeof(int)",
  " * or sizeof(void*) != sizeof(int).",
  " */",
  "#endif",
  "#endif",
  "",
  "/* Amount of stuff to slurp up with each read. */",
  "#ifndef YY_READ_BUF_SIZE",
  "#define YY_READ_BUF_SIZE 8192",
  "#endif",
  "",
  "/* Copy whatever the last rule matched to the standard output. */",
  "",
  "#ifndef ECHO",
  "%- Standard (non-C++) definition",
  "/* This used to be an fputs(), but since the string might contain NUL's,",
  " * we now use fwrite().",
  " */",
  "#define ECHO (void) fwrite( yytext, yyleng, 1, yyout )",
  "%+ C++ definition",
  "#define ECHO LexerOutput( yytext, yyleng )",
  "%*",
  "#endif",
  "",
  "/* Gets input and stuffs it into \"buf\".  number of characters read, or YY_NULL,",
  " * is returned in \"result\".",
  " */",
  "#ifndef YY_INPUT",
  "#define YY_INPUT(buf,result,max_size) \\",
  "%% fread()/read() definition of YY_INPUT goes here unless we're doing C++",
  "%+ C++ definition",
  "	if ( (result = LexerInput( (char *) buf, max_size )) < 0 ) \\",
  "		YY_FATAL_ERROR( \"input in flex scanner failed\" );",
  "%*",
  "#endif",
  "",
  "/* No semi-colon after return; correct usage is to write \"yyterminate();\" -",
  " * we don't want an extra ';' after the \"return\" because that will cause",
  " * some compilers to complain about unreachable statements.",
  " */",
  "#ifndef yyterminate",
  "#define yyterminate() return YY_NULL",
  "#endif",
  "",
  "/* Number of entries by which start-condition stack grows. */",
  "#ifndef YY_START_STACK_INCR",
  "#define YY_START_STACK_INCR 25",
  "#endif",
  "",
  "/* Report a fatal error. */",
  "#ifndef YY_FATAL_ERROR",
  "%-",
  "#define YY_FATAL_ERROR(msg) yy_fatal_error( msg )",
  "%+",
  "#define YY_FATAL_ERROR(msg) LexerError( msg )",
  "%*",
  "#endif",
  "",
  "/* Default declaration of generated scanner - a define so the user can",
  " * easily add parameters.",
  " */",
  "#ifndef YY_DECL",
  "%- Standard (non-C++) definition",
  "#define YY_DECL int yylex YY_PROTO(( void ))",
  "%+ C++ definition",
  "#define YY_DECL int yyFlexLexer::yylex()",
  "%*",
  "#endif",
  "",
  "/* Code executed at the beginning of each rule, after yytext and yyleng",
  " * have been set up.",
  " */",
  "#ifndef YY_USER_ACTION",
  "#define YY_USER_ACTION",
  "#endif",
  "",
  "/* Code executed at the end of each rule. */",
  "#ifndef YY_BREAK",
  "#define YY_BREAK break;",
  "#endif",
  "",
  "%% YY_RULE_SETUP definition goes here",
  "",
  "YY_DECL",
  "	{",
  "	register yy_state_type yy_current_state;",
  "	register char *yy_cp, *yy_bp;",
  "	register int yy_act;",
  "",
  "%% user's declarations go here",
  "",
  "	if ( yy_init )",
  "		{",
  "		yy_init = 0;",
  "",
  "#ifdef YY_USER_INIT",
  "		YY_USER_INIT;",
  "#endif",
  "",
  "		if ( ! yy_start )",
  "			yy_start = 1;	/* first start state */",
  "",
  "		if ( ! yyin )",
  "%-",
  "			yyin = stdin;",
  "%+",
  "			yyin = &cin;",
  "%*",
  "",
  "		if ( ! yyout )",
  "%-",
  "			yyout = stdout;",
  "%+",
  "			yyout = &cout;",
  "%*",
  "",
  "		if ( ! yy_current_buffer )",
  "			yy_current_buffer =",
  "				yy_create_buffer( yyin, YY_BUF_SIZE );",
  "",
  "		yy_load_buffer_state();",
  "		}",
  "",
  "	while ( 1 )		/* loops until end-of-file is reached */",
  "		{",
  "%% yymore()-related code goes here",
  "		yy_cp = yy_c_buf_p;",
  "",
  "		/* Support of yytext. */",
  "		*yy_cp = yy_hold_char;",
  "",
  "		/* yy_bp points to the position in yy_ch_buf of the start of",
  "		 * the current run.",
  "		 */",
  "		yy_bp = yy_cp;",
  "",
  "%% code to set up and find next match goes here",
  "",
  "yy_find_action:",
  "%% code to find the action number goes here",
  "",
  "		YY_DO_BEFORE_ACTION;",
  "",
  "%% code for yylineno update goes here",
  "",
  "do_action:	/* This label is used only to access EOF actions. */",
  "",
  "%% debug code goes here",
  "",
  "		switch ( yy_act )",
  "	{ /* beginning of action switch */",
  "%% actions go here",
  "",
  "	case YY_END_OF_BUFFER:",
  "		{",
  "		/* Amount of text matched not including the EOB char. */",
  "		int yy_amount_of_matched_text = (int) (yy_cp - yytext_ptr) - 1;",
  "",
  "		/* Undo the effects of YY_DO_BEFORE_ACTION. */",
  "		*yy_cp = yy_hold_char;",
  "		YY_RESTORE_YY_MORE_OFFSET",
  "",
  "		if ( yy_current_buffer->yy_buffer_status == YY_BUFFER_NEW )",
  "			{",
  "			/* We're scanning a new file or input source.  It's",
  "			 * possible that this happened because the user",
  "			 * just pointed yyin at a new source and called",
  "			 * yylex().  If so, then we have to assure",
  "			 * consistency between yy_current_buffer and our",
  "			 * globals.  Here is the right place to do so, because",
  "			 * this is the first action (other than possibly a",
  "			 * back-up) that will match for the new input source.",
  "			 */",
  "			yy_n_chars = yy_current_buffer->yy_n_chars;",
  "			yy_current_buffer->yy_input_file = yyin;",
  "			yy_current_buffer->yy_buffer_status = YY_BUFFER_NORMAL;",
  "			}",
  "",
  "		/* Note that here we test for yy_c_buf_p \"<=\" to the position",
  "		 * of the first EOB in the buffer, since yy_c_buf_p will",
  "		 * already have been incremented past the NUL character",
  "		 * (since all states make transitions on EOB to the",
  "		 * end-of-buffer state).  Contrast this with the test",
  "		 * in input().",
  "		 */",
  "		if ( yy_c_buf_p <= &yy_current_buffer->yy_ch_buf[yy_n_chars] )",
  "			{ /* This was really a NUL. */",
  "			yy_state_type yy_next_state;",
  "",
  "			yy_c_buf_p = yytext_ptr + yy_amount_of_matched_text;",
  "",
  "			yy_current_state = yy_get_previous_state();",
  "",
  "			/* Okay, we're now positioned to make the NUL",
  "			 * transition.  We couldn't have",
  "			 * yy_get_previous_state() go ahead and do it",
  "			 * for us because it doesn't know how to deal",
  "			 * with the possibility of jamming (and we don't",
  "			 * want to build jamming into it because then it",
  "			 * will run more slowly).",
  "			 */",
  "",
  "			yy_next_state = yy_try_NUL_trans( yy_current_state );",
  "",
  "			yy_bp = yytext_ptr + YY_MORE_ADJ;",
  "",
  "			if ( yy_next_state )",
  "				{",
  "				/* Consume the NUL. */",
  "				yy_cp = ++yy_c_buf_p;",
  "				yy_current_state = yy_next_state;",
  "				goto yy_match;",
  "				}",
  "",
  "			else",
  "				{",
  "%% code to do back-up for compressed tables and set up yy_cp goes here",
  "				goto yy_find_action;",
  "				}",
  "			}",
  "",
  "		else switch ( yy_get_next_buffer() )",
  "			{",
  "			case EOB_ACT_END_OF_FILE:",
  "				{",
  "				yy_did_buffer_switch_on_eof = 0;",
  "",
  "				if ( yywrap() )",
  "					{",
  "					/* Note: because we've taken care in",
  "					 * yy_get_next_buffer() to have set up",
  "					 * yytext, we can now set up",
  "					 * yy_c_buf_p so that if some total",
  "					 * hoser (like flex itself) wants to",
  "					 * call the scanner after we return the",
  "					 * YY_NULL, it'll still work - another",
  "					 * YY_NULL will get returned.",
  "					 */",
  "					yy_c_buf_p = yytext_ptr + YY_MORE_ADJ;",
  "",
  "					yy_act = YY_STATE_EOF(YY_START);",
  "					goto do_action;",
  "					}",
  "",
  "				else",
  "					{",
  "					if ( ! yy_did_buffer_switch_on_eof )",
  "						YY_NEW_FILE;",
  "					}",
  "				break;",
  "				}",
  "",
  "			case EOB_ACT_CONTINUE_SCAN:",
  "				yy_c_buf_p =",
  "					yytext_ptr + yy_amount_of_matched_text;",
  "",
  "				yy_current_state = yy_get_previous_state();",
  "",
  "				yy_cp = yy_c_buf_p;",
  "				yy_bp = yytext_ptr + YY_MORE_ADJ;",
  "				goto yy_match;",
  "",
  "			case EOB_ACT_LAST_MATCH:",
  "				yy_c_buf_p =",
  "				&yy_current_buffer->yy_ch_buf[yy_n_chars];",
  "",
  "				yy_current_state = yy_get_previous_state();",
  "",
  "				yy_cp = yy_c_buf_p;",
  "				yy_bp = yytext_ptr + YY_MORE_ADJ;",
  "				goto yy_find_action;",
  "			}",
  "		break;",
  "		}",
  "",
  "	default:",
  "		YY_FATAL_ERROR(",
  "			\"fatal flex scanner internal error--no action found\" );",
  "	} /* end of action switch */",
  "		} /* end of scanning one token */",
  "	} /* end of yylex */",
  "",
  "%+",
  "yyFlexLexer::yyFlexLexer( istream* arg_yyin, ostream* arg_yyout )",
  "	{",
  "	yyin = arg_yyin;",
  "	yyout = arg_yyout;",
  "	yy_c_buf_p = 0;",
  "	yy_init = 1;",
  "	yy_start = 0;",
  "	yy_flex_debug = 0;",
  "	yylineno = 1;	// this will only get updated if %option yylineno",
  "",
  "	yy_did_buffer_switch_on_eof = 0;",
  "",
  "	yy_looking_for_trail_begin = 0;",
  "	yy_more_flag = 0;",
  "	yy_more_len = 0;",
  "	yy_more_offset = yy_prev_more_offset = 0;",
  "",
  "	yy_start_stack_ptr = yy_start_stack_depth = 0;",
  "	yy_start_stack = 0;",
  "",
  "	yy_current_buffer = 0;",
  "",
  "#ifdef YY_USES_REJECT",
  "	yy_state_buf = new yy_state_type[YY_BUF_SIZE + 2];",
  "#else",
  "	yy_state_buf = 0;",
  "#endif",
  "	}",
  "",
  "yyFlexLexer::~yyFlexLexer()",
  "	{",
  "	delete yy_state_buf;",
  "	yy_delete_buffer( yy_current_buffer );",
  "	}",
  "",
  "void yyFlexLexer::switch_streams( istream* new_in, ostream* new_out )",
  "	{",
  "	if ( new_in )",
  "		{",
  "		yy_delete_buffer( yy_current_buffer );",
  "		yy_switch_to_buffer( yy_create_buffer( new_in, YY_BUF_SIZE ) );",
  "		}",
  "",
  "	if ( new_out )",
  "		yyout = new_out;",
  "	}",
  "",
  "#ifdef YY_INTERACTIVE",
  "int yyFlexLexer::LexerInput( char* buf, int /* max_size */ )",
  "#else",
  "int yyFlexLexer::LexerInput( char* buf, int max_size )",
  "#endif",
  "	{",
  "	if ( yyin->eof() || yyin->fail() )",
  "		return 0;",
  "",
  "#ifdef YY_INTERACTIVE",
  "	yyin->get( buf[0] );",
  "",
  "	if ( yyin->eof() )",
  "		return 0;",
  "",
  "	if ( yyin->bad() )",
  "		return -1;",
  "",
  "	return 1;",
  "",
  "#else",
  "	(void) yyin->read( buf, max_size );",
  "",
  "	if ( yyin->bad() )",
  "		return -1;",
  "	else",
  "		return yyin->gcount();",
  "#endif",
  "	}",
  "",
  "void yyFlexLexer::LexerOutput( const char* buf, int size )",
  "	{",
  "	(void) yyout->write( buf, size );",
  "	}",
  "%*",
  "",
  "/* yy_get_next_buffer - try to read in a new buffer",
  " *",
  " * Returns a code representing an action:",
  " *	EOB_ACT_LAST_MATCH -",
  " *	EOB_ACT_CONTINUE_SCAN - continue scanning from current position",
  " *	EOB_ACT_END_OF_FILE - end of file",
  " */",
  "",
  "%-",
  "static int yy_get_next_buffer()",
  "%+",
  "int yyFlexLexer::yy_get_next_buffer()",
  "%*",
  "	{",
  "	register char *dest = yy_current_buffer->yy_ch_buf;",
  "	register char *source = yytext_ptr;",
  "	register int number_to_move, i;",
  "	int ret_val;",
  "",
  "	if ( yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1] )",
  "		YY_FATAL_ERROR(",
  "		\"fatal flex scanner internal error--end of buffer missed\" );",
  "",
  "	if ( yy_current_buffer->yy_fill_buffer == 0 )",
  "		{ /* Don't try to fill the buffer, so this is an EOF. */",
  "		if ( yy_c_buf_p - yytext_ptr - YY_MORE_ADJ == 1 )",
  "			{",
  "			/* We matched a single character, the EOB, so",
  "			 * treat this as a final EOF.",
  "			 */",
  "			return EOB_ACT_END_OF_FILE;",
  "			}",
  "",
  "		else",
  "			{",
  "			/* We matched some text prior to the EOB, first",
  "			 * process it.",
  "			 */",
  "			return EOB_ACT_LAST_MATCH;",
  "			}",
  "		}",
  "",
  "	/* Try to read more data. */",
  "",
  "	/* First move last chars to start of buffer. */",
  "	number_to_move = (int) (yy_c_buf_p - yytext_ptr) - 1;",
  "",
  "	for ( i = 0; i < number_to_move; ++i )",
  "		*(dest++) = *(source++);",
  "",
  "	if ( yy_current_buffer->yy_buffer_status == YY_BUFFER_EOF_PENDING )",
  "		/* don't do the read, it's not guaranteed to return an EOF,",
  "		 * just force an EOF",
  "		 */",
  "		yy_n_chars = 0;",
  "",
  "	else",
  "		{",
  "		int num_to_read =",
  "			yy_current_buffer->yy_buf_size - number_to_move - 1;",
  "",
  "		while ( num_to_read <= 0 )",
  "			{ /* Not enough room in the buffer - grow it. */",
  "#ifdef YY_USES_REJECT",
  "			YY_FATAL_ERROR(",
  "\"input buffer overflow, can't enlarge buffer because scanner uses REJECT\" );",
  "#else",
  "",
  "			/* just a shorter name for the current buffer */",
  "			YY_BUFFER_STATE b = yy_current_buffer;",
  "",
  "			int yy_c_buf_p_offset =",
  "				(int) (yy_c_buf_p - b->yy_ch_buf);",
  "",
  "			if ( b->yy_is_our_buffer )",
  "				{",
  "				int new_size = b->yy_buf_size * 2;",
  "",
  "				if ( new_size <= 0 )",
  "					b->yy_buf_size += b->yy_buf_size / 8;",
  "				else",
  "					b->yy_buf_size *= 2;",
  "",
  "				b->yy_ch_buf = (char *)",
  "					/* Include room in for 2 EOB chars. */",
  "					yy_flex_realloc( (void *) b->yy_ch_buf,",
  "							 b->yy_buf_size + 2 );",
  "				}",
  "			else",
  "				/* Can't grow it, we don't own it. */",
  "				b->yy_ch_buf = 0;",
  "",
  "			if ( ! b->yy_ch_buf )",
  "				YY_FATAL_ERROR(",
  "				\"fatal error - scanner input buffer overflow\" );",
  "",
  "			yy_c_buf_p = &b->yy_ch_buf[yy_c_buf_p_offset];",
  "",
  "			num_to_read = yy_current_buffer->yy_buf_size -",
  "						number_to_move - 1;",
  "#endif",
  "			}",
  "",
  "		if ( num_to_read > YY_READ_BUF_SIZE )",
  "			num_to_read = YY_READ_BUF_SIZE;",
  "",
  "		/* Read in more data. */",
  "		YY_INPUT( (&yy_current_buffer->yy_ch_buf[number_to_move]),",
  "			yy_n_chars, num_to_read );",
  "		}",
  "",
  "	if ( yy_n_chars == 0 )",
  "		{",
  "		if ( number_to_move == YY_MORE_ADJ )",
  "			{",
  "			ret_val = EOB_ACT_END_OF_FILE;",
  "			yyrestart( yyin );",
  "			}",
  "",
  "		else",
  "			{",
  "			ret_val = EOB_ACT_LAST_MATCH;",
  "			yy_current_buffer->yy_buffer_status =",
  "				YY_BUFFER_EOF_PENDING;",
  "			}",
  "		}",
  "",
  "	else",
  "		ret_val = EOB_ACT_CONTINUE_SCAN;",
  "",
  "	yy_n_chars += number_to_move;",
  "	yy_current_buffer->yy_ch_buf[yy_n_chars] = YY_END_OF_BUFFER_CHAR;",
  "	yy_current_buffer->yy_ch_buf[yy_n_chars + 1] = YY_END_OF_BUFFER_CHAR;",
  "",
  "	yytext_ptr = &yy_current_buffer->yy_ch_buf[0];",
  "",
  "	return ret_val;",
  "	}",
  "",
  "",
  "/* yy_get_previous_state - get the state just before the EOB char was reached */",
  "",
  "%-",
  "static yy_state_type yy_get_previous_state()",
  "%+",
  "yy_state_type yyFlexLexer::yy_get_previous_state()",
  "%*",
  "	{",
  "	register yy_state_type yy_current_state;",
  "	register char *yy_cp;",
  "",
  "%% code to get the start state into yy_current_state goes here",
  "",
  "	for ( yy_cp = yytext_ptr + YY_MORE_ADJ; yy_cp < yy_c_buf_p; ++yy_cp )",
  "		{",
  "%% code to find the next state goes here",
  "		}",
  "",
  "	return yy_current_state;",
  "	}",
  "",
  "",
  "/* yy_try_NUL_trans - try to make a transition on the NUL character",
  " *",
  " * synopsis",
  " *	next_state = yy_try_NUL_trans( current_state );",
  " */",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "static yy_state_type yy_try_NUL_trans( yy_state_type yy_current_state )",
  "#else",
  "static yy_state_type yy_try_NUL_trans( yy_current_state )",
  "yy_state_type yy_current_state;",
  "#endif",
  "%+",
  "yy_state_type yyFlexLexer::yy_try_NUL_trans( yy_state_type yy_current_state )",
  "%*",
  "	{",
  "	register int yy_is_jam;",
  "%% code to find the next state, and perhaps do backing up, goes here",
  "",
  "	return yy_is_jam ? 0 : yy_current_state;",
  "	}",
  "",
  "",
  "%-",
  "#ifndef YY_NO_UNPUT",
  "#ifdef YY_USE_PROTOS",
  "static void yyunput( int c, register char *yy_bp )",
  "#else",
  "static void yyunput( c, yy_bp )",
  "int c;",
  "register char *yy_bp;",
  "#endif",
  "%+",
  "void yyFlexLexer::yyunput( int c, register char* yy_bp )",
  "%*",
  "	{",
  "	register char *yy_cp = yy_c_buf_p;",
  "",
  "	/* undo effects of setting up yytext */",
  "	*yy_cp = yy_hold_char;",
  "",
  "	if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )",
  "		{ /* need to shift things up to make room */",
  "		/* +2 for EOB chars. */",
  "		register int number_to_move = yy_n_chars + 2;",
  "		register char *dest = &yy_current_buffer->yy_ch_buf[",
  "					yy_current_buffer->yy_buf_size + 2];",
  "		register char *source =",
  "				&yy_current_buffer->yy_ch_buf[number_to_move];",
  "",
  "		while ( source > yy_current_buffer->yy_ch_buf )",
  "			*--dest = *--source;",
  "",
  "		yy_cp += (int) (dest - source);",
  "		yy_bp += (int) (dest - source);",
  "		yy_n_chars = yy_current_buffer->yy_buf_size;",
  "",
  "		if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )",
  "			YY_FATAL_ERROR( \"flex scanner push-back overflow\" );",
  "		}",
  "",
  "	*--yy_cp = (char) c;",
  "",
  "%% update yylineno here",
  "",
  "	yytext_ptr = yy_bp;",
  "	yy_hold_char = *yy_cp;",
  "	yy_c_buf_p = yy_cp;",
  "	}",
  "%-",
  "#endif	/* ifndef YY_NO_UNPUT */",
  "%*",
  "",
  "",
  "%-",
  "#ifdef __cplusplus",
  "static int yyinput()",
  "#else",
  "static int input()",
  "#endif",
  "%+",
  "int yyFlexLexer::yyinput()",
  "%*",
  "	{",
  "	int c;",
  "",
  "	*yy_c_buf_p = yy_hold_char;",
  "",
  "	if ( *yy_c_buf_p == YY_END_OF_BUFFER_CHAR )",
  "		{",
  "		/* yy_c_buf_p now points to the character we want to return.",
  "		 * If this occurs *before* the EOB characters, then it's a",
  "		 * valid NUL; if not, then we've hit the end of the buffer.",
  "		 */",
  "		if ( yy_c_buf_p < &yy_current_buffer->yy_ch_buf[yy_n_chars] )",
  "			/* This was really a NUL. */",
  "			*yy_c_buf_p = '\\0';",
  "",
  "		else",
  "			{ /* need more input */",
  "			int offset = yy_c_buf_p - yytext_ptr;",
  "			++yy_c_buf_p;",
  "",
  "			switch ( yy_get_next_buffer() )",
  "				{",
  "				case EOB_ACT_END_OF_FILE:",
  "					{",
  "					if ( yywrap() )",
  "						{",
  "						yy_c_buf_p = yytext_ptr + offset;",
  "						return EOF;",
  "						}",
  "",
  "					if ( ! yy_did_buffer_switch_on_eof )",
  "						YY_NEW_FILE;",
  "#ifdef __cplusplus",
  "					return yyinput();",
  "#else",
  "					return input();",
  "#endif",
  "					}",
  "",
  "				case EOB_ACT_CONTINUE_SCAN:",
  "					yy_c_buf_p = yytext_ptr + offset;",
  "					break;",
  "",
  "				case EOB_ACT_LAST_MATCH:",
  "#ifdef __cplusplus",
  "					YY_FATAL_ERROR(",
  "					\"unexpected last match in yyinput()\" );",
  "#else",
  "					YY_FATAL_ERROR(",
  "					\"unexpected last match in input()\" );",
  "#endif",
  "				}",
  "			}",
  "		}",
  "",
  "	c = *(unsigned char *) yy_c_buf_p;	/* cast for 8-bit char's */",
  "	*yy_c_buf_p = '\\0';	/* preserve yytext */",
  "	yy_hold_char = *++yy_c_buf_p;",
  "",
  "%% update BOL and yylineno",
  "",
  "	return c;",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "void yyrestart( FILE *input_file )",
  "#else",
  "void yyrestart( input_file )",
  "FILE *input_file;",
  "#endif",
  "%+",
  "void yyFlexLexer::yyrestart( istream* input_file )",
  "%*",
  "	{",
  "	if ( ! yy_current_buffer )",
  "		yy_current_buffer = yy_create_buffer( yyin, YY_BUF_SIZE );",
  "",
  "	yy_init_buffer( yy_current_buffer, input_file );",
  "	yy_load_buffer_state();",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer )",
  "#else",
  "void yy_switch_to_buffer( new_buffer )",
  "YY_BUFFER_STATE new_buffer;",
  "#endif",
  "%+",
  "void yyFlexLexer::yy_switch_to_buffer( YY_BUFFER_STATE new_buffer )",
  "%*",
  "	{",
  "	if ( yy_current_buffer == new_buffer )",
  "		return;",
  "",
  "	if ( yy_current_buffer )",
  "		{",
  "		/* Flush out information for old buffer. */",
  "		*yy_c_buf_p = yy_hold_char;",
  "		yy_current_buffer->yy_buf_pos = yy_c_buf_p;",
  "		yy_current_buffer->yy_n_chars = yy_n_chars;",
  "		}",
  "",
  "	yy_current_buffer = new_buffer;",
  "	yy_load_buffer_state();",
  "",
  "	/* We don't actually know whether we did this switch during",
  "	 * EOF (yywrap()) processing, but the only time this flag",
  "	 * is looked at is after yywrap() is called, so it's safe",
  "	 * to go ahead and always set it.",
  "	 */",
  "	yy_did_buffer_switch_on_eof = 1;",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "void yy_load_buffer_state( void )",
  "#else",
  "void yy_load_buffer_state()",
  "#endif",
  "%+",
  "void yyFlexLexer::yy_load_buffer_state()",
  "%*",
  "	{",
  "	yy_n_chars = yy_current_buffer->yy_n_chars;",
  "	yytext_ptr = yy_c_buf_p = yy_current_buffer->yy_buf_pos;",
  "	yyin = yy_current_buffer->yy_input_file;",
  "	yy_hold_char = *yy_c_buf_p;",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "YY_BUFFER_STATE yy_create_buffer( FILE *file, int size )",
  "#else",
  "YY_BUFFER_STATE yy_create_buffer( file, size )",
  "FILE *file;",
  "int size;",
  "#endif",
  "%+",
  "YY_BUFFER_STATE yyFlexLexer::yy_create_buffer( istream* file, int size )",
  "%*",
  "	{",
  "	YY_BUFFER_STATE b;",
  "",
  "	b = (YY_BUFFER_STATE) yy_flex_alloc( sizeof( struct yy_buffer_state ) );",
  "	if ( ! b )",
  "		YY_FATAL_ERROR( \"out of dynamic memory in yy_create_buffer()\" );",
  "",
  "	b->yy_buf_size = size;",
  "",
  "	/* yy_ch_buf has to be 2 characters longer than the size given because",
  "	 * we need to put in 2 end-of-buffer characters.",
  "	 */",
  "	b->yy_ch_buf = (char *) yy_flex_alloc( b->yy_buf_size + 2 );",
  "	if ( ! b->yy_ch_buf )",
  "		YY_FATAL_ERROR( \"out of dynamic memory in yy_create_buffer()\" );",
  "",
  "	b->yy_is_our_buffer = 1;",
  "",
  "	yy_init_buffer( b, file );",
  "",
  "	return b;",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "void yy_delete_buffer( YY_BUFFER_STATE b )",
  "#else",
  "void yy_delete_buffer( b )",
  "YY_BUFFER_STATE b;",
  "#endif",
  "%+",
  "void yyFlexLexer::yy_delete_buffer( YY_BUFFER_STATE b )",
  "%*",
  "	{",
  "	if ( ! b )",
  "		return;",
  "",
  "	if ( b == yy_current_buffer )",
  "		yy_current_buffer = (YY_BUFFER_STATE) 0;",
  "",
  "	if ( b->yy_is_our_buffer )",
  "		yy_flex_free( (void *) b->yy_ch_buf );",
  "",
  "	yy_flex_free( (void *) b );",
  "	}",
  "",
  "",
  "%-",
  "#ifndef YY_ALWAYS_INTERACTIVE",
  "#ifndef YY_NEVER_INTERACTIVE",
  "extern int isatty YY_PROTO(( int ));",
  "#endif",
  "#endif",
  "",
  "#ifdef YY_USE_PROTOS",
  "void yy_init_buffer( YY_BUFFER_STATE b, FILE *file )",
  "#else",
  "void yy_init_buffer( b, file )",
  "YY_BUFFER_STATE b;",
  "FILE *file;",
  "#endif",
  "",
  "%+",
  "extern \"C\" int isatty YY_PROTO(( int ));",
  "void yyFlexLexer::yy_init_buffer( YY_BUFFER_STATE b, istream* file )",
  "%*",
  "",
  "	{",
  "	yy_flush_buffer( b );",
  "",
  "	b->yy_input_file = file;",
  "	b->yy_fill_buffer = 1;",
  "",
  "%-",
  "#if YY_ALWAYS_INTERACTIVE",
  "	b->yy_is_interactive = 1;",
  "#else",
  "#if YY_NEVER_INTERACTIVE",
  "	b->yy_is_interactive = 0;",
  "#else",
  "	b->yy_is_interactive = file ? (isatty( fileno(file) ) > 0) : 0;",
  "#endif",
  "#endif",
  "%+",
  "	b->yy_is_interactive = 0;",
  "%*",
  "	}",
  "",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "void yy_flush_buffer( YY_BUFFER_STATE b )",
  "#else",
  "void yy_flush_buffer( b )",
  "YY_BUFFER_STATE b;",
  "#endif",
  "",
  "%+",
  "void yyFlexLexer::yy_flush_buffer( YY_BUFFER_STATE b )",
  "%*",
  "	{",
  "	b->yy_n_chars = 0;",
  "",
  "	/* We always need two end-of-buffer characters.  The first causes",
  "	 * a transition to the end-of-buffer state.  The second causes",
  "	 * a jam in that state.",
  "	 */",
  "	b->yy_ch_buf[0] = YY_END_OF_BUFFER_CHAR;",
  "	b->yy_ch_buf[1] = YY_END_OF_BUFFER_CHAR;",
  "",
  "	b->yy_buf_pos = &b->yy_ch_buf[0];",
  "",
  "	b->yy_at_bol = 1;",
  "	b->yy_buffer_status = YY_BUFFER_NEW;",
  "",
  "	if ( b == yy_current_buffer )",
  "		yy_load_buffer_state();",
  "	}",
  "%*",
  "",
  "",
  "#ifndef YY_NO_SCAN_BUFFER",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "YY_BUFFER_STATE yy_scan_buffer( char *base, yy_size_t size )",
  "#else",
  "YY_BUFFER_STATE yy_scan_buffer( base, size )",
  "char *base;",
  "yy_size_t size;",
  "#endif",
  "	{",
  "	YY_BUFFER_STATE b;",
  "",
  "	if ( size < 2 ||",
  "	     base[size-2] != YY_END_OF_BUFFER_CHAR ||",
  "	     base[size-1] != YY_END_OF_BUFFER_CHAR )",
  "		/* They forgot to leave room for the EOB's. */",
  "		return 0;",
  "",
  "	b = (YY_BUFFER_STATE) yy_flex_alloc( sizeof( struct yy_buffer_state ) );",
  "	if ( ! b )",
  "		YY_FATAL_ERROR( \"out of dynamic memory in yy_scan_buffer()\" );",
  "",
  "	b->yy_buf_size = size - 2;	/* \"- 2\" to take care of EOB's */",
  "	b->yy_buf_pos = b->yy_ch_buf = base;",
  "	b->yy_is_our_buffer = 0;",
  "	b->yy_input_file = 0;",
  "	b->yy_n_chars = b->yy_buf_size;",
  "	b->yy_is_interactive = 0;",
  "	b->yy_at_bol = 1;",
  "	b->yy_fill_buffer = 0;",
  "	b->yy_buffer_status = YY_BUFFER_NEW;",
  "",
  "	yy_switch_to_buffer( b );",
  "",
  "	return b;",
  "	}",
  "%*",
  "#endif",
  "",
  "",
  "#ifndef YY_NO_SCAN_STRING",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "YY_BUFFER_STATE yy_scan_string( yyconst char *str )",
  "#else",
  "YY_BUFFER_STATE yy_scan_string( str )",
  "yyconst char *str;",
  "#endif",
  "	{",
  "	int len;",
  "	for ( len = 0; str[len]; ++len )",
  "		;",
  "",
  "	return yy_scan_bytes( str, len );",
  "	}",
  "%*",
  "#endif",
  "",
  "",
  "#ifndef YY_NO_SCAN_BYTES",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "YY_BUFFER_STATE yy_scan_bytes( yyconst char *bytes, int len )",
  "#else",
  "YY_BUFFER_STATE yy_scan_bytes( bytes, len )",
  "yyconst char *bytes;",
  "int len;",
  "#endif",
  "	{",
  "	YY_BUFFER_STATE b;",
  "	char *buf;",
  "	yy_size_t n;",
  "	int i;",
  "",
  "	/* Get memory for full buffer, including space for trailing EOB's. */",
  "	n = len + 2;",
  "	buf = (char *) yy_flex_alloc( n );",
  "	if ( ! buf )",
  "		YY_FATAL_ERROR( \"out of dynamic memory in yy_scan_bytes()\" );",
  "",
  "	for ( i = 0; i < len; ++i )",
  "		buf[i] = bytes[i];",
  "",
  "	buf[len] = buf[len+1] = YY_END_OF_BUFFER_CHAR;",
  "",
  "	b = yy_scan_buffer( buf, n );",
  "	if ( ! b )",
  "		YY_FATAL_ERROR( \"bad buffer in yy_scan_bytes()\" );",
  "",
  "	/* It's okay to grow etc. this buffer, and we should throw it",
  "	 * away when we're done.",
  "	 */",
  "	b->yy_is_our_buffer = 1;",
  "",
  "	return b;",
  "	}",
  "%*",
  "#endif",
  "",
  "",
  "#ifndef YY_NO_PUSH_STATE",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "static void yy_push_state( int new_state )",
  "#else",
  "static void yy_push_state( new_state )",
  "int new_state;",
  "#endif",
  "%+",
  "void yyFlexLexer::yy_push_state( int new_state )",
  "%*",
  "	{",
  "	if ( yy_start_stack_ptr >= yy_start_stack_depth )",
  "		{",
  "		yy_size_t new_size;",
  "",
  "		yy_start_stack_depth += YY_START_STACK_INCR;",
  "		new_size = yy_start_stack_depth * sizeof( int );",
  "",
  "		if ( ! yy_start_stack )",
  "			yy_start_stack = (int *) yy_flex_alloc( new_size );",
  "",
  "		else",
  "			yy_start_stack = (int *) yy_flex_realloc(",
  "					(void *) yy_start_stack, new_size );",
  "",
  "		if ( ! yy_start_stack )",
  "			YY_FATAL_ERROR(",
  "			\"out of memory expanding start-condition stack\" );",
  "		}",
  "",
  "	yy_start_stack[yy_start_stack_ptr++] = YY_START;",
  "",
  "	BEGIN(new_state);",
  "	}",
  "#endif",
  "",
  "",
  "#ifndef YY_NO_POP_STATE",
  "%-",
  "static void yy_pop_state()",
  "%+",
  "void yyFlexLexer::yy_pop_state()",
  "%*",
  "	{",
  "	if ( --yy_start_stack_ptr < 0 )",
  "		YY_FATAL_ERROR( \"start-condition stack underflow\" );",
  "",
  "	BEGIN(yy_start_stack[yy_start_stack_ptr]);",
  "	}",
  "#endif",
  "",
  "",
  "#ifndef YY_NO_TOP_STATE",
  "%-",
  "static int yy_top_state()",
  "%+",
  "int yyFlexLexer::yy_top_state()",
  "%*",
  "	{",
  "	return yy_start_stack[yy_start_stack_ptr - 1];",
  "	}",
  "#endif",
  "",
  "#ifndef YY_EXIT_FAILURE",
  "#define YY_EXIT_FAILURE 2",
  "#endif",
  "",
  "%-",
  "#ifdef YY_USE_PROTOS",
  "static void yy_fatal_error( yyconst char msg[] )",
  "#else",
  "static void yy_fatal_error( msg )",
  "char msg[];",
  "#endif",
  "	{",
  "FILE *err;",
  "	(void) fprintf( err, \"%s\\n\", msg );",
  "	exit( YY_EXIT_FAILURE );",
  "	}",
  "",
  "%+",
  "",
  "void yyFlexLexer::LexerError( yyconst char msg[] )",
  "	{",
  "	cerr << msg << '\\n';",
  "	exit( YY_EXIT_FAILURE );",
  "	}",
  "%*",
  "",
  "",
  "/* Redefine yyless() so it works in section 3 code. */",
  "",
  "#undef yyless",
  "#define yyless(n) \\",
  "	do \\",
  "		{ \\",
  "		/* Undo effects of setting up yytext. */ \\",
  "		yytext[yyleng] = yy_hold_char; \\",



  "		yy_c_buf_p = yytext + n - YY_MORE_ADJ; \\",

  "		yy_hold_char = *yy_c_buf_p; \\",
  "		*yy_c_buf_p = '\\0'; \\",
  "		yyleng = n; \\",
  "		} \\",
  "	while ( 0 )",
  "",
  "",
  "/* Internal utility routines. */",
  "",
  "#ifndef yytext_ptr",
  "#ifdef YY_USE_PROTOS",
  "static void yy_flex_strncpy( char *s1, yyconst char *s2, int n )",
  "#else",
  "static void yy_flex_strncpy( s1, s2, n )",
  "char *s1;",
  "yyconst char *s2;",
  "int n;",
  "#endif",
  "	{",
  "	register int i;",
  "	for ( i = 0; i < n; ++i )",
  "		s1[i] = s2[i];",
  "	}",
  "#endif",
  "",
  "#ifdef YY_NEED_STRLEN",
  "#ifdef YY_USE_PROTOS",
  "static int yy_flex_strlen( yyconst char *s )",
  "#else",
  "static int yy_flex_strlen( s )",
  "yyconst char *s;",
  "#endif",
  "	{",
  "	register int n;",
  "	for ( n = 0; s[n]; ++n )",
  "		;",
  "",
  "	return n;",
  "	}",
  "#endif",
  "",
  "",
  "#ifdef YY_USE_PROTOS",
  "static void *yy_flex_alloc( yy_size_t size )",
  "#else",
  "static void *yy_flex_alloc( size )",
  "yy_size_t size;",
  "#endif",
  "	{",
  "	return (void *) malloc( size );",
  "	}",
  "",
  "#ifdef YY_USE_PROTOS",
  "static void *yy_flex_realloc( void *ptr, yy_size_t size )",
  "#else",
  "static void *yy_flex_realloc( ptr, size )",
  "void *ptr;",
  "yy_size_t size;",
  "#endif",
  "	{",
  "	/* The cast to (char *) in the following accommodates both",
  "	 * implementations that use char* generic pointers, and those",
  "	 * that use void* generic pointers.  It works with the latter",
  "	 * because both ANSI C and C++ allow castless assignment from",
  "	 * any pointer type to void*, and deal with argument conversions",
  "	 * as though doing an assignment.",
  "	 */",
  "	return (void *) realloc( (char *) ptr, size );",
  "	}",
  "",
  "#ifdef YY_USE_PROTOS",
  "static void yy_flex_free( void *ptr )",
  "#else",
  "static void yy_flex_free( ptr )",
  "void *ptr;",
  "#endif",
  "	{",
  "	free( ptr );",
  "	}",
  "",
  "#if YY_MAIN",
  "int main()",
  "	{",
  "	yylex();",
  "	return 0;",
  "	}",
  "#endif",
  0
};
# 7506 "flex_single_original.c"
int hashfunct (register char[], int);


struct hash_entry *ndtbl[101];
struct hash_entry *sctbl[101];
struct hash_entry *ccltab[101];

struct hash_entry *findsym();







int addsym( sym, str_def, int_def, table, table_size )
register char sym[];
char *str_def;
int int_def;
hash_table table;
int table_size;
 {
 int hash_val = hashfunct( sym, table_size );
 register struct hash_entry *sym_entry = table[hash_val];
 register struct hash_entry *new_entry;
 register struct hash_entry *successor;

 while ( sym_entry )
  {
  if ( ! strcmp( sym, sym_entry->name ) )
   {
   return -1;
   }

  sym_entry = sym_entry->next;
  }


 new_entry = (struct hash_entry *)
  flex_alloc( sizeof( struct hash_entry ) );

 if ( new_entry == 
# 7547 "flex_single_original.c" 3 4
                  ((void *)0) 
# 7547 "flex_single_original.c"
                       )
  flexfatal( ("symbol table memory allocation failed") );

 if ( (successor = table[hash_val]) != 0 )
  {
  new_entry->next = successor;
  successor->prev = new_entry;
  }
 else
  new_entry->next = 
# 7556 "flex_single_original.c" 3 4
                   ((void *)0)
# 7556 "flex_single_original.c"
                       ;

 new_entry->prev = 
# 7558 "flex_single_original.c" 3 4
                  ((void *)0)
# 7558 "flex_single_original.c"
                      ;
 new_entry->name = sym;
 new_entry->str_val = str_def;
 new_entry->int_val = int_def;

 table[hash_val] = new_entry;

 return 0;
 }




void cclinstal( ccltxt, cclnum )
unsigned char ccltxt[];
int cclnum;
 {



 unsigned char *copy_unsigned_string();

 (void) addsym( (char *) copy_unsigned_string( ccltxt ),
   (char *) 0, cclnum,
   ccltab, 101 );
 }







int ccllookup( ccltxt )
unsigned char ccltxt[];
 {
 return findsym( (char *) ccltxt, ccltab, 101 )->int_val;
 }




struct hash_entry *findsym( sym, table, table_size )
register char sym[];
hash_table table;
int table_size;
 {
 static struct hash_entry empty_entry =
  {
  (struct hash_entry *) 0, (struct hash_entry *) 0,
  (char *) 0, (char *) 0, 0,
  } ;
 register struct hash_entry *sym_entry =
  table[hashfunct( sym, table_size )];

 while ( sym_entry )
  {
  if ( ! strcmp( sym, sym_entry->name ) )
   return sym_entry;
  sym_entry = sym_entry->next;
  }

 return &empty_entry;
 }




int hashfunct( str, hash_size )
register char str[];
int hash_size;
 {
 register int hashval;
 register int locstr;

 hashval = 0;
 locstr = 0;

 while ( str[locstr] )
  {
  hashval = (hashval << 1) + (unsigned char) str[locstr++];
  hashval %= hash_size;
  }

 return hashval;
 }




void ndinstal( name, definition )
char name[];
unsigned char definition[];
 {
 char *copy_string();
 unsigned char *copy_unsigned_string();

 if ( addsym( copy_string( name ),
   (char *) copy_unsigned_string( definition ), 0,
   ndtbl, 101 ) )
  synerr( ("name defined twice") );
 }







unsigned char *ndlookup( nd )
char nd[];
 {
 return (unsigned char *) findsym( nd, ndtbl, 101 )->str_val;
 }




void scextend()
 {
 current_max_scs += 40;

 ++num_reallocs;

 scset = (int *) reallocate_array( (void *) scset, current_max_scs, sizeof( int ) );
 scbol = (int *) reallocate_array( (void *) scbol, current_max_scs, sizeof( int ) );
 scxclu = (int *) reallocate_array( (void *) scxclu, current_max_scs, sizeof( int ) );
 sceof = (int *) reallocate_array( (void *) sceof, current_max_scs, sizeof( int ) );
 scname = (char **) reallocate_array( (void *) scname, current_max_scs, sizeof( char * ) );
 }
# 7696 "flex_single_original.c"
void scinstal( str, xcluflg )
char str[];
int xcluflg;
 {
 char *copy_string();


 action_define( str, lastsc );

 if ( ++lastsc >= current_max_scs )
  scextend();

 scname[lastsc] = copy_string( str );

 if ( addsym( scname[lastsc], (char *) 0, lastsc,
   sctbl, 101 ) )
  format_pinpoint_message(
    ("start condition %s declared twice"),
     str );

 scset[lastsc] = mkstate( (256 + 1) );
 scbol[lastsc] = mkstate( (256 + 1) );
 scxclu[lastsc] = xcluflg;
 sceof[lastsc] = 0;
 }







int sclookup( str )
char str[];
 {
 return findsym( str, sctbl, 101 )->int_val;
 }
# 7767 "flex_single_original.c"
void mkentry (register int*, int, int, int, int);
void mkprot (int[], int, int);
void mktemplate (int[], int, int);
void mv2front (int);
int tbldiff (int[], int, int[]);
# 7809 "flex_single_original.c"
void bldtbl( state, statenum, totaltrans, comstate, comfreq )
int state[], statenum, totaltrans, comstate, comfreq;
 {
 int extptr, extrct[2][256 + 1];
 int mindiff, minprot, i, d;
# 7825 "flex_single_original.c"
 extptr = 0;





 if ( (totaltrans * 100) < (numecs * 15) )
  mkentry( state, numecs, statenum, -32766, totaltrans );

 else
  {



  int checkcom =
   comfreq * 100 > totaltrans * 50;

  minprot = firstprot;
  mindiff = totaltrans;

  if ( checkcom )
   {

   for ( i = firstprot; i != 0; i = protnext[i] )
    if ( protcomst[i] == comstate )
     {
     minprot = i;
     mindiff = tbldiff( state, minprot,
       extrct[extptr] );
     break;
     }
   }

  else
   {






   comstate = 0;

   if ( firstprot != 0 )
    {
    minprot = firstprot;
    mindiff = tbldiff( state, minprot,
      extrct[extptr] );
    }
   }







  if ( mindiff * 100 > totaltrans * 10 )
   {



   for ( i = minprot; i != 0; i = protnext[i] )
    {
    d = tbldiff( state, i, extrct[1 - extptr] );
    if ( d < mindiff )
     {
     extptr = 1 - extptr;
     mindiff = d;
     minprot = i;
     }
    }
   }





  if ( mindiff * 100 > totaltrans * 50 )
   {





   if ( comfreq * 100 >=
        totaltrans * 60 )
    mktemplate( state, statenum, comstate );

   else
    {
    mkprot( state, statenum, comstate );
    mkentry( state, numecs, statenum,
     -32766, totaltrans );
    }
   }

  else
   {
   mkentry( extrct[extptr], numecs, statenum,
    prottbl[minprot], mindiff );





   if ( mindiff * 100 >=
        totaltrans * 20 )
    mkprot( state, statenum, comstate );
# 7945 "flex_single_original.c"
   mv2front( minprot );
   }
  }
 }
# 7959 "flex_single_original.c"
void cmptmps()
 {
 int tmpstorage[256 + 1];
 register int *tmp = tmpstorage, i, j;
 int totaltrans, trans;

 peakpairs = numtemps * numecs + tblend;

 if ( usemecs )
  {



  nummecs = cre8ecs( tecfwd, tecbck, numecs );
  }

 else
  nummecs = numecs;

 while ( lastdfa + numtemps + 1 >= current_max_dfas )
  increase_max_dfas();



 for ( i = 1; i <= numtemps; ++i )
  {

  totaltrans = 0;

  for ( j = 1; j <= numecs; ++j )
   {
   trans = tnxt[numecs * i + j];

   if ( usemecs )
    {




    if ( tecbck[j] > 0 )
     {
     tmp[tecbck[j]] = trans;

     if ( trans > 0 )
      ++totaltrans;
     }
    }

   else
    {
    tmp[j] = trans;

    if ( trans > 0 )
     ++totaltrans;
    }
   }
# 8024 "flex_single_original.c"
  mkentry( tmp, nummecs, lastdfa + i + 1, -32766, totaltrans );
  }
 }





void expand_nxt_chk()
 {
 register int old_max = current_max_xpairs;

 current_max_xpairs += 2000;

 ++num_reallocs;

 nxt = (int *) reallocate_array( (void *) nxt, current_max_xpairs, sizeof( int ) );
 chk = (int *) reallocate_array( (void *) chk, current_max_xpairs, sizeof( int ) );

 zero_out( (char *) (chk + old_max),
  (size_t) (2000 * sizeof( int )) );
 }
# 8067 "flex_single_original.c"
int find_table_space( state, numtrans )
int *state, numtrans;
 {



 register int i;
 register int *state_ptr, *chk_ptr;
 register int *ptr_to_last_entry_in_state;




 if ( numtrans > 4 )
  {



  if ( tblend < 2 )
   return 1;




  i = tblend - numecs;
  }

 else




  i = firstfree;

 while ( 1 )
  {
  while ( i + numecs >= current_max_xpairs )
   expand_nxt_chk();




  while ( 1 )
   {

   if ( chk[i - 1] == 0 )
    {

    if ( chk[i] == 0 )
     break;

    else





     i += 2;
    }

   else
    ++i;

   while ( i + numecs >= current_max_xpairs )
    expand_nxt_chk();
   }




  if ( numtrans <= 4 )
   firstfree = i + 1;





  state_ptr = &state[1];
  ptr_to_last_entry_in_state = &chk[i + numecs + 1];

  for ( chk_ptr = &chk[i + 1];
        chk_ptr != ptr_to_last_entry_in_state; ++chk_ptr )
   if ( *(state_ptr++) != 0 && *chk_ptr != 0 )
    break;

  if ( chk_ptr == ptr_to_last_entry_in_state )
   return i;

  else
  ++i;
  }
 }







void inittbl()
 {
 register int i;

 zero_out( (char *) chk, (size_t) (current_max_xpairs * sizeof( int )) );

 tblend = 0;
 firstfree = tblend + 1;
 numtemps = 0;

 if ( usemecs )
  {





  tecbck[1] = 0;

  for ( i = 2; i <= numecs; ++i )
   {
   tecbck[i] = i - 1;
   tecfwd[i - 1] = i;
   }

  tecfwd[numecs] = 0;
  }
 }




void mkdeftbl()
 {
 int i;

 jamstate = lastdfa + 1;

 ++tblend;

 while ( tblend + numecs >= current_max_xpairs )
  expand_nxt_chk();


 nxt[tblend] = end_of_buffer_state;
 chk[tblend] = jamstate;

 for ( i = 1; i <= numecs; ++i )
  {
  nxt[tblend + i] = 0;
  chk[tblend + i] = jamstate;
  }

 jambase = tblend;

 base[jamstate] = jambase;
 def[jamstate] = 0;

 tblend += numecs;
 ++numtemps;
 }
# 8248 "flex_single_original.c"
void mkentry( state, numchars, statenum, deflink, totaltrans )
register int *state;
int numchars, statenum, deflink, totaltrans;
 {
 register int minec, maxec, i, baseaddr;
 int tblbase, tbllast;

 if ( totaltrans == 0 )
  {
  if ( deflink == -32766 )
   base[statenum] = -32766;
  else
   base[statenum] = 0;

  def[statenum] = deflink;
  return;
  }

 for ( minec = 1; minec <= numchars; ++minec )
  {
  if ( state[minec] != -1 )
   if ( state[minec] != 0 || deflink != -32766 )
    break;
  }

 if ( totaltrans == 1 )
  {



  stack1( statenum, minec, state[minec], deflink );
  return;
  }

 for ( maxec = numchars; maxec > 0; --maxec )
  {
  if ( state[maxec] != -1 )
   if ( state[maxec] != 0 || deflink != -32766 )
    break;
  }
# 8299 "flex_single_original.c"
 if ( totaltrans * 100 <= numchars * 15 )
  {

  baseaddr = firstfree;

  while ( baseaddr < minec )
   {



   for ( ++baseaddr; chk[baseaddr] != 0; ++baseaddr )
    ;
   }

  while ( baseaddr + maxec - minec + 1 >= current_max_xpairs )
   expand_nxt_chk();

  for ( i = minec; i <= maxec; ++i )
   if ( state[i] != -1 &&
        (state[i] != 0 || deflink != -32766) &&
        chk[baseaddr + i - minec] != 0 )
    {
    for ( ++baseaddr;
          baseaddr < current_max_xpairs &&
          chk[baseaddr] != 0; ++baseaddr )
     ;

    while ( baseaddr + maxec - minec + 1 >=
     current_max_xpairs )
     expand_nxt_chk();





    i = minec - 1;
    }
  }

 else
  {



  baseaddr = ((tblend + 1) > (minec) ? (tblend + 1) : (minec));
  }

 tblbase = baseaddr - minec;
 tbllast = tblbase + maxec;

 while ( tbllast + 1 >= current_max_xpairs )
  expand_nxt_chk();

 base[statenum] = tblbase;
 def[statenum] = deflink;

 for ( i = minec; i <= maxec; ++i )
  if ( state[i] != -1 )
   if ( state[i] != 0 || deflink != -32766 )
    {
    nxt[tblbase + i] = state[i];
    chk[tblbase + i] = statenum;
    }

 if ( baseaddr == firstfree )

  for ( ++firstfree; chk[firstfree] != 0; ++firstfree )
   ;

 tblend = ((tblend) > (tbllast) ? (tblend) : (tbllast));
 }






void mk1tbl( state, sym, onenxt, onedef )
int state, sym, onenxt, onedef;
 {
 if ( firstfree < sym )
  firstfree = sym;

 while ( chk[firstfree] != 0 )
  if ( ++firstfree >= current_max_xpairs )
   expand_nxt_chk();

 base[state] = firstfree - sym;
 def[state] = onedef;
 chk[firstfree] = state;
 nxt[firstfree] = onenxt;

 if ( firstfree > tblend )
  {
  tblend = firstfree++;

  if ( firstfree >= current_max_xpairs )
   expand_nxt_chk();
  }
 }




void mkprot( state, statenum, comstate )
int state[], statenum, comstate;
 {
 int i, slot, tblbase;

 if ( ++numprots >= 50 || numecs * numprots >= 2000 )
  {



  slot = lastprot;
  lastprot = protprev[lastprot];
  protnext[lastprot] = 0;
  }

 else
  slot = numprots;

 protnext[slot] = firstprot;

 if ( firstprot != 0 )
  protprev[firstprot] = slot;

 firstprot = slot;
 prottbl[slot] = statenum;
 protcomst[slot] = comstate;


 tblbase = numecs * (slot - 1);

 for ( i = 1; i <= numecs; ++i )
  protsave[tblbase + i] = state[i];
 }






void mktemplate( state, statenum, comstate )
int state[], statenum, comstate;
 {
 int i, numdiff, tmpbase, tmp[256 + 1];
 unsigned char transset[256 + 1];
 int tsptr;

 ++numtemps;

 tsptr = 0;






 tmpbase = numtemps * numecs;

 if ( tmpbase + numecs >= current_max_template_xpairs )
  {
  current_max_template_xpairs += 2500;

  ++num_reallocs;

  tnxt = (int *) reallocate_array( (void *) tnxt, current_max_template_xpairs, sizeof( int ) )
                                ;
  }

 for ( i = 1; i <= numecs; ++i )
  if ( state[i] == 0 )
   tnxt[tmpbase + i] = 0;
  else
   {
   transset[tsptr++] = i;
   tnxt[tmpbase + i] = comstate;
   }

 if ( usemecs )
  mkeccl( transset, tsptr, tecfwd, tecbck, numecs, 0 );

 mkprot( tnxt + tmpbase, -numtemps, comstate );





 numdiff = tbldiff( state, firstprot, tmp );
 mkentry( tmp, numecs, statenum, -numtemps, numdiff );
 }




void mv2front( qelm )
int qelm;
 {
 if ( firstprot != qelm )
  {
  if ( qelm == lastprot )
   lastprot = protprev[lastprot];

  protnext[protprev[qelm]] = protnext[qelm];

  if ( protnext[qelm] != 0 )
   protprev[protnext[qelm]] = protprev[qelm];

  protprev[qelm] = 0;
  protnext[qelm] = firstprot;
  protprev[firstprot] = qelm;
  firstprot = qelm;
  }
 }
# 8523 "flex_single_original.c"
void place_state( state, statenum, transnum )
int *state, statenum, transnum;
 {
 register int i;
 register int *state_ptr;
 int position = find_table_space( state, transnum );


 base[statenum] = position;






 chk[position - 1] = 1;




 chk[position] = 1;


 state_ptr = &state[1];

 for ( i = 1; i <= numecs; ++i, ++state_ptr )
  if ( *state_ptr != 0 )
   {
   chk[position + i] = i;
   nxt[position + i] = *state_ptr;
   }

 if ( position + numecs > tblend )
  tblend = position + numecs;
 }
# 8567 "flex_single_original.c"
void stack1( statenum, sym, nextstate, deflink )
int statenum, sym, nextstate, deflink;
 {
 if ( onesp >= 500 - 1 )
  mk1tbl( statenum, sym, nextstate, deflink );

 else
  {
  ++onesp;
  onestate[onesp] = statenum;
  onesym[onesp] = sym;
  onenext[onesp] = nextstate;
  onedef[onesp] = deflink;
  }
 }
# 8598 "flex_single_original.c"
int tbldiff( state, pr, ext )
int state[], pr, ext[];
 {
 register int i, *sp = state, *ep = ext, *protp;
 register int numdiff = 0;

 protp = &protsave[numecs * (pr - 1)];

 for ( i = numecs; i > 0; --i )
  {
  if ( *++protp == *++sp )
   *++ep = -1;
  else
   {
   *++ep = *sp;
   ++numdiff;
   }
  }

 return numdiff;
 }
# 8652 "flex_single_original.c"
int yylex()
 {
 int toktype;
 static int beglin = 0;
 extern char *yytext;

 if ( eofseen )
  toktype = 
# 8659 "flex_single_original.c" 3 4
           (-1)
# 8659 "flex_single_original.c"
              ;
 else
  toktype = flexscan();

 if ( toktype == 
# 8663 "flex_single_original.c" 3 4
                (-1) 
# 8663 "flex_single_original.c"
                    || toktype == 0 )
  {
  eofseen = 1;

  if ( sectnum == 1 )
   {
   synerr( ("premature EOF") );
   sectnum = 2;
   toktype = 259;
   }

  else
   toktype = 0;
  }

 if ( trace )
  {
  if ( beglin )
   {
   fprintf( err, "%d\t", num_rules + 1 );
   beglin = 0;
   }

  switch ( toktype )
   {
   case '<':
   case '>':
   case '^':
   case '$':
   case '"':
   case '[':
   case ']':
   case '{':
   case '}':
   case '|':
   case '(':
   case ')':
   case '-':
   case '/':
   case '\\':
   case '?':
   case '.':
   case '*':
   case '+':
   case ',':
    (void) 
# 8708 "flex_single_original.c" 3 4
          _IO_putc (
# 8708 "flex_single_original.c"
          toktype
# 8708 "flex_single_original.c" 3 4
          , 
# 8708 "flex_single_original.c"
          err
# 8708 "flex_single_original.c" 3 4
          )
# 8708 "flex_single_original.c"
                              ;
    break;

   case '\n':
    (void) 
# 8712 "flex_single_original.c" 3 4
          _IO_putc (
# 8712 "flex_single_original.c"
          '\n'
# 8712 "flex_single_original.c" 3 4
          , 
# 8712 "flex_single_original.c"
          err
# 8712 "flex_single_original.c" 3 4
          )
# 8712 "flex_single_original.c"
                           ;

    if ( sectnum == 2 )
    beglin = 1;

    break;

   case 260:
    fputs( "%s", err );
    break;

   case 261:
    fputs( "%x", err );
    break;

   case 259:
    fputs( "%%\n", err );





    if ( sectnum == 2 )
     beglin = 1;

    break;

   case 262:
    fprintf( err, "'%s'", nmstr );
    break;

   case 257:
    switch ( yylval )
     {
     case '<':
     case '>':
     case '^':
     case '$':
     case '"':
     case '[':
     case ']':
     case '{':
     case '}':
     case '|':
     case '(':
     case ')':
     case '-':
     case '/':
     case '\\':
     case '?':
     case '.':
     case '*':
     case '+':
     case ',':
      fprintf( err, "\\%c",
       yylval );
      break;

     default:
      if ( ! 
# 8771 "flex_single_original.c" 3 4
            (((
# 8771 "flex_single_original.c"
            yylval
# 8771 "flex_single_original.c" 3 4
            ) & ~0x7f) == 0) 
# 8771 "flex_single_original.c"
                              ||
           ! 
# 8772 "flex_single_original.c" 3 4
            ((*__ctype_b_loc ())[(int) ((
# 8772 "flex_single_original.c"
            yylval
# 8772 "flex_single_original.c" 3 4
            ))] & (unsigned short int) _ISprint) 
# 8772 "flex_single_original.c"
                              )
       fprintf( err,
        "\\%.3o",
       (unsigned int) yylval );
      else
       (void) 
# 8777 "flex_single_original.c" 3 4
             _IO_putc (
# 8777 "flex_single_original.c"
             yylval
# 8777 "flex_single_original.c" 3 4
             , 
# 8777 "flex_single_original.c"
             err
# 8777 "flex_single_original.c" 3 4
             )
             
# 8778 "flex_single_original.c"
            ;
     break;
     }

    break;

   case 258:
    fprintf( err, "%d", yylval );
    break;

   case 263:
    fprintf( err, "[%d]", yylval );
    break;

   case 264:
    fprintf( err, "<<EOF>>" );
    break;

   case 265:
    fprintf( err, "%s ", yytext );
    break;

   case 266:
   case 267:
   case 269:
   case 270:
   case 271:
   case 272:
   case 273:
   case 274:
   case 275:
   case 276:
   case 277:
   case 278:
   case 279:
   case 280:
    fprintf( err, "%s", yytext );
    break;

   case 0:
    fprintf( err, ("End Marker\n") );
    break;

   default:
    fprintf( err,
    ("*Something Weird* - tok: %d val: %d\n"),
     toktype, yylval );
    break;
   }
  }

 return toktype;
 }
# 8932 "flex_single_original.c"
int pat, scnum, eps, headcnt, trailcnt, anyccl, lastchar, i, rulelen;
int trlcontxt, xcluflg, currccl, cclsorted, varlength, variable_trail_rule;

int *scon_stk;
int scon_stk_ptr;

static int madeany = 0;
int previous_continued_action;
# 8980 "flex_single_original.c"
static const char yytranslate[] = { 0,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 28,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 42, 2, 36, 2, 2, 2, 43,
    44, 34, 39, 35, 47, 41, 38, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 32,
    27, 33, 40, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    45, 2, 46, 31, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 29, 37, 30, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
     2, 2, 2, 2, 2, 1, 3, 4, 5, 6,
     7, 8, 9, 10, 11, 12, 13, 14, 15, 16,
    17, 18, 19, 20, 21, 22, 23, 24, 25, 26
};
# 9077 "flex_single_original.c"
static const short yyr1[] = { 0,
    48, 49, 50, 50, 50, 50, 51, 52, 52, 53,
    53, 53, 54, 55, 55, 56, 56, 56, 57, 57,
    57, 58, 59, 59, 59, 59, 60, 61, 61, 61,
    62, 62, 62, 63, 64, 64, 64, 64, 65, 65,
    66, 67, 67, 68, 68, 68, 68, 68, 68, 68,
    68, 68, 68, 68, 68, 69, 69, 70, 70, 70,
    70, 71, 71, 71, 71, 71, 71, 71, 71, 71,
    71, 71, 71, 72, 72
};

static const short yyr2[] = { 0,
     5, 0, 3, 2, 0, 1, 1, 1, 1, 2,
     1, 1, 2, 2, 0, 3, 3, 3, 5, 5,
     0, 0, 2, 1, 1, 1, 0, 4, 3, 0,
     3, 1, 1, 1, 2, 3, 2, 1, 3, 1,
     2, 2, 1, 2, 2, 2, 6, 5, 4, 1,
     1, 1, 3, 3, 1, 3, 4, 4, 2, 2,
     0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 2, 0
};

static const short yydefact[] = { 2,
     0, 6, 0, 7, 8, 9, 15, 21, 0, 4,
    13, 30, 12, 11, 3, 0, 0, 0, 14, 27,
     1, 22, 10, 0, 0, 0, 0, 0, 21, 0,
    16, 17, 18, 29, 33, 34, 0, 32, 30, 26,
    55, 52, 25, 0, 50, 75, 0, 61, 0, 24,
    38, 0, 40, 43, 51, 28, 0, 20, 23, 0,
     0, 61, 0, 19, 37, 0, 41, 35, 42, 0,
    44, 45, 46, 31, 74, 53, 54, 0, 59, 62,
    63, 64, 65, 66, 67, 68, 69, 70, 71, 72,
    73, 56, 60, 39, 36, 0, 57, 0, 49, 0,
    58, 0, 48, 47, 0, 0, 0
};

static const short yydefgoto[] = { 105,
     1, 3, 8, 9, 15, 10, 11, 19, 12, 21,
    49, 28, 22, 37, 38, 50, 51, 52, 53, 54,
    55, 63, 93, 60
};

static const short yypact[] = {-32768,
    78,-32768, 81,-32768,-32768,-32768,-32768,-32768, 6,-32768,
    -2, 5,-32768,-32768, -7, -14, 1, 9,-32768, 28,
-32768, 14,-32768, 55, 65, 74, 57, 30,-32768, -1,
-32768,-32768,-32768,-32768,-32768,-32768, 58,-32768, 44,-32768,
-32768,-32768,-32768, 24,-32768,-32768, 24, 63, 69,-32768,
    23, 24, 24, 41,-32768,-32768, 90,-32768,-32768, 26,
    27,-32768, 0,-32768,-32768, 24,-32768, 59, 41, 95,
-32768,-32768,-32768,-32768,-32768,-32768,-32768, 32, 53,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768, 24,-32768, 4,-32768, 98,-32768, 2,
-32768, 72,-32768,-32768, 103, 104,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768, 76, 84,
-32768,-32768,-32768,-32768, 50, 64, 25,-32768, 43, -49,
-32768, 48,-32768,-32768
};





static const short yytable[] = { 40,
    23, 41, 79, 69, -22, 102, 13, 42, 43, 16,
    17, 18, 24, 14, 80, 81, 82, 83, 84, 85,
    86, 87, 88, 89, 90, 91, 41, 25, 75, 44,
    35, 103, 42, 99, 79, 26, 20, 36, 100, 45,
    46, 47, 29, 48, 69, 92, 80, 81, 82, 83,
    84, 85, 86, 87, 88, 89, 90, 91, 65, 66,
    67, 27, 31, 66, 45, 46, 47, 76, 48, 70,
    77, 61, 32, 58, 71, 20, 68, 97, 2, 72,
    73, 33, -5, -5, -5, 4, 5, 6, -5, 34,
    56, 7, 57, 62, 95, 66, 64, 36, 96, 98,
   101, 104, 106, 107, 39, 30, 74, 59, 94, 78
};

static const short yycheck[] = { 1,
     8, 3, 3, 53, 0, 4, 1, 9, 10, 12,
    13, 14, 27, 8, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 3, 27, 3, 31,
     1, 30, 9, 30, 3, 27, 32, 8, 35, 41,
    42, 43, 29, 45, 94, 46, 15, 16, 17, 18,
    19, 20, 21, 22, 23, 24, 25, 26, 36, 37,
    38, 34, 8, 37, 41, 42, 43, 42, 45, 29,
    44, 47, 8, 30, 34, 32, 52, 46, 1, 39,
    40, 8, 5, 6, 7, 5, 6, 7, 11, 33,
    33, 11, 35, 31, 36, 37, 28, 8, 4, 47,
     3, 30, 0, 0, 29, 22, 57, 44, 66, 62
};
# 9305 "flex_single_original.c"
int yychar;
int yylval;







int yynerrs;
# 9407 "flex_single_original.c"
int yyparse (void);



int
yyparse()
    
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register int *yyvsp;
  int yyerrstatus;
  int yychar1 = 0;

  short yyssa[200];
  int yyvsa[200];

  short *yyss = yyssa;
  int *yyvs = yyvsa;
# 9438 "flex_single_original.c"
  int yystacksize = 200;
  int yyfree_stacks = 0;
# 9450 "flex_single_original.c"
  int yyval;



  int yylen;






  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = -2;






  yyssp = yyss - 1;
  yyvsp = yyvs;







yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {


      int *yyvs1 = yyvs;
      short *yyss1 = yyss;





      int size = yyssp - yyss + 1;
# 9521 "flex_single_original.c"
      if (yystacksize >= 10000)
 {
   yyerror("parser stack overflow");
   if (yyfree_stacks)
     {
       free (yyss);
       free (yyvs);



     }
   return 2;
 }
      yystacksize *= 2;
      if (yystacksize > 10000)
 yystacksize = 10000;



      yyss = (short *) 
# 9540 "flex_single_original.c" 3 4
                      __builtin_alloca (
# 9540 "flex_single_original.c"
                      yystacksize * sizeof (*yyssp)
# 9540 "flex_single_original.c" 3 4
                      )
# 9540 "flex_single_original.c"
                                                                   ;
      __builtin_memcpy((char *)yyss,(char *)yyss1,size * (unsigned int) sizeof (*yyssp))
                                           ;
      yyvs = (int *) 
# 9543 "flex_single_original.c" 3 4
                        __builtin_alloca (
# 9543 "flex_single_original.c"
                        yystacksize * sizeof (*yyvsp)
# 9543 "flex_single_original.c" 3 4
                        )
# 9543 "flex_single_original.c"
                                                                     ;
      __builtin_memcpy((char *)yyvs,(char *)yyvs1,size * (unsigned int) sizeof (*yyvsp))
                                           ;







      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
# 9564 "flex_single_original.c"
      if (yyssp >= yyss + yystacksize - 1)
 goto yyabortlab;
    }






  goto yybackup;
 yybackup:







  yyn = yypact[yystate];
  if (yyn == -32768)
    goto yydefault;






  if (yychar == -2)
    {




      yychar = yylex();
    }



  if (yychar <= 0)
    {
      yychar1 = 0;
      yychar = 0;





    }
  else
    {
      yychar1 = ((unsigned)(yychar) <= 280 ? yytranslate[yychar] : 73);
# 9628 "flex_single_original.c"
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > 110 || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];
# 9643 "flex_single_original.c"
  if (yyn < 0)
    {
      if (yyn == -32768)
 goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == 107)
    goto yyacceptlab;
# 9664 "flex_single_original.c"
  if (yychar != 0)
    yychar = -2;

  *++yyvsp = yylval;





  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;


yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen];
# 9707 "flex_single_original.c"
  switch (yyn) {

case 1:
{
   int def_rule;

   pat = cclinit();
   cclnegate( pat );

   def_rule = mkstate( -pat );




   default_rule = num_rules;

   finish_rule( def_rule, 0, 0, 0 );

   for ( i = 1; i <= lastsc; ++i )
    scset[i] = mkbranch( scset[i], def_rule );

   if ( spprdflt )
    add_action(
    "YY_FATAL_ERROR( \"flex scanner jammed\" )" );
   else
    add_action( "ECHO" );

   add_action( ";\n\tYY_BREAK\n" );
   ;
    break;}
case 2:
{


   scinstal( "INITIAL", 0 );
   ;
    break;}
case 6:
{ synerr( "unknown error processing section 1" ); ;
    break;}
case 7:
{
   check_options();
   scon_stk = (int *) allocate_array( lastsc + 1, sizeof( int ) );
   scon_stk_ptr = 0;
   ;
    break;}
case 8:
{ xcluflg = 0; ;
    break;}
case 9:
{ xcluflg = 1; ;
    break;}
case 10:
{ scinstal( nmstr, xcluflg ); ;
    break;}
case 11:
{ scinstal( nmstr, xcluflg ); ;
    break;}
case 12:
{ synerr( "bad start condition list" ); ;
    break;}
case 16:
{
   outfilename = copy_string( nmstr );
   did_outfilename = 1;
   ;
    break;}
case 17:
{ prefix = copy_string( nmstr ); ;
    break;}
case 18:
{ yyclass = copy_string( nmstr ); ;
    break;}
case 19:
{ scon_stk_ptr = yyvsp[-3]; ;
    break;}
case 20:
{ scon_stk_ptr = yyvsp[-3]; ;
    break;}
case 22:
{

   trlcontxt = variable_trail_rule = varlength = 0;
   trailcnt = headcnt = rulelen = 0;
   current_state_type = 0x1;
   previous_continued_action = continued_action;
   in_rule = 1;

   new_rule();
   ;
    break;}
case 23:
{
   pat = yyvsp[0];
   finish_rule( pat, variable_trail_rule,
    headcnt, trailcnt );

   if ( scon_stk_ptr > 0 )
    {
    for ( i = 1; i <= scon_stk_ptr; ++i )
     scbol[scon_stk[i]] =
      mkbranch( scbol[scon_stk[i]],
        pat );
    }

   else
    {




    for ( i = 1; i <= lastsc; ++i )
     if ( ! scxclu[i] )
      scbol[i] = mkbranch( scbol[i],
         pat );
    }

   if ( ! bol_needed )
    {
    bol_needed = 1;

    if ( performance_report > 1 )
     pinpoint_message(
   "'^' operator results in sub-optimal performance" );
    }
   ;
    break;}
case 24:
{
   pat = yyvsp[0];
   finish_rule( pat, variable_trail_rule,
    headcnt, trailcnt );

   if ( scon_stk_ptr > 0 )
    {
    for ( i = 1; i <= scon_stk_ptr; ++i )
     scset[scon_stk[i]] =
      mkbranch( scset[scon_stk[i]],
        pat );
    }

   else
    {
    for ( i = 1; i <= lastsc; ++i )
     if ( ! scxclu[i] )
      scset[i] =
       mkbranch( scset[i],
        pat );
    }
   ;
    break;}
case 25:
{
   if ( scon_stk_ptr > 0 )
    build_eof_action();

   else
    {



    for ( i = 1; i <= lastsc; ++i )
     if ( ! sceof[i] )
      scon_stk[++scon_stk_ptr] = i;

    if ( scon_stk_ptr == 0 )
     warn(
   "all start conditions already have <<EOF>> rules" );

    else
     build_eof_action();
    }
   ;
    break;}
case 26:
{ synerr( "unrecognized rule" ); ;
    break;}
case 27:
{ yyval = scon_stk_ptr; ;
    break;}
case 28:
{ yyval = yyvsp[-2]; ;
    break;}
case 29:
{
   yyval = scon_stk_ptr;

   for ( i = 1; i <= lastsc; ++i )
    {
    int j;

    for ( j = 1; j <= scon_stk_ptr; ++j )
     if ( scon_stk[j] == i )
      break;

    if ( j > scon_stk_ptr )
     scon_stk[++scon_stk_ptr] = i;
    }
   ;
    break;}
case 30:
{ yyval = scon_stk_ptr; ;
    break;}
case 33:
{ synerr( "bad start condition list" ); ;
    break;}
case 34:
{
   if ( (scnum = sclookup( nmstr )) == 0 )
    format_pinpoint_message(
     "undeclared start condition %s",
     nmstr );
   else
    {
    for ( i = 1; i <= scon_stk_ptr; ++i )
     if ( scon_stk[i] == scnum )
      {
      format_warn(
       "<%s> specified twice",
       scname[scnum] );
      break;
      }

    if ( i > scon_stk_ptr )
     scon_stk[++scon_stk_ptr] = scnum;
    }
   ;
    break;}
case 35:
{
   if ( transchar[lastst[yyvsp[0]]] != (256 + 1) )




    yyvsp[0] = link_machines( yyvsp[0],
      mkstate( (256 + 1) ) );

   mark_beginning_as_normal( yyvsp[0] );
   current_state_type = 0x1;

   if ( previous_continued_action )
    {
# 9959 "flex_single_original.c"
    if ( ! varlength || headcnt != 0 )
     warn(
  "trailing context made variable due to preceding '|' action" );


    varlength = 1;
    headcnt = 0;
    }

   if ( lex_compat || (varlength && headcnt == 0) )
    {
# 9980 "flex_single_original.c"
    add_accept( yyvsp[-1],
     num_rules | 0x4000 );
    variable_trail_rule = 1;
    }

   else
    trailcnt = rulelen;

   yyval = link_machines( yyvsp[-1], yyvsp[0] );
   ;
    break;}
case 36:
{ synerr( "trailing context used twice" ); ;
    break;}
case 37:
{
   headcnt = 0;
   trailcnt = 1;
   rulelen = 1;
   varlength = 0;

   current_state_type = 0x2;

   if ( trlcontxt )
    {
    synerr( "trailing context used twice" );
    yyval = mkstate( (256 + 1) );
    }

   else if ( previous_continued_action )
    {



    warn(
  "trailing context made variable due to preceding '|' action" );

    varlength = 1;
    }

   if ( lex_compat || varlength )
    {



    add_accept( yyvsp[-1],
     num_rules | 0x4000 );
    variable_trail_rule = 1;
    }

   trlcontxt = 1;

   eps = mkstate( (256 + 1) );
   yyval = link_machines( yyvsp[-1],
    link_machines( eps, mkstate( '\n' ) ) );
   ;
    break;}
case 38:
{
   yyval = yyvsp[0];

   if ( trlcontxt )
    {
    if ( lex_compat || (varlength && headcnt == 0) )



     variable_trail_rule = 1;
    else
     trailcnt = rulelen;
    }
   ;
    break;}
case 39:
{
   varlength = 1;
   yyval = mkor( yyvsp[-2], yyvsp[0] );
   ;
    break;}
case 40:
{ yyval = yyvsp[0]; ;
    break;}
case 41:
{





   if ( trlcontxt )
    synerr( "trailing context used twice" );
   else
    trlcontxt = 1;

   if ( varlength )



    varlength = 0;
   else
    headcnt = rulelen;

   rulelen = 0;

   current_state_type = 0x2;
   yyval = yyvsp[-1];
   ;
    break;}
case 42:
{



   yyval = link_machines( yyvsp[-1], yyvsp[0] );
   ;
    break;}
case 43:
{ yyval = yyvsp[0]; ;
    break;}
case 44:
{
   varlength = 1;

   yyval = mkclos( yyvsp[-1] );
   ;
    break;}
case 45:
{
   varlength = 1;
   yyval = mkposcl( yyvsp[-1] );
   ;
    break;}
case 46:
{
   varlength = 1;
   yyval = mkopt( yyvsp[-1] );
   ;
    break;}
case 47:
{
   varlength = 1;

   if ( yyvsp[-3] > yyvsp[-1] || yyvsp[-3] < 0 )
    {
    synerr( "bad iteration values" );
    yyval = yyvsp[-5];
    }
   else
    {
    if ( yyvsp[-3] == 0 )
     {
     if ( yyvsp[-1] <= 0 )
      {
      synerr(
      "bad iteration values" );
      yyval = yyvsp[-5];
      }
     else
      yyval = mkopt(
       mkrep( yyvsp[-5], 1, yyvsp[-1] ) );
     }
    else
     yyval = mkrep( yyvsp[-5], yyvsp[-3], yyvsp[-1] );
    }
   ;
    break;}
case 48:
{
   varlength = 1;

   if ( yyvsp[-2] <= 0 )
    {
    synerr( "iteration value must be positive" );
    yyval = yyvsp[-4];
    }

   else
    yyval = mkrep( yyvsp[-4], yyvsp[-2], -1 );
   ;
    break;}
case 49:
{




   varlength = 1;

   if ( yyvsp[-1] <= 0 )
    {
    synerr( "iteration value must be positive" );
    yyval = yyvsp[-3];
    }

   else
    yyval = link_machines( yyvsp[-3],
      copysingl( yyvsp[-3], yyvsp[-1] - 1 ) );
   ;
    break;}
case 50:
{
   if ( ! madeany )
    {

    anyccl = cclinit();
    ccladd( anyccl, '\n' );
    cclnegate( anyccl );

    if ( useecs )
     mkeccl( ccltbl + cclmap[anyccl],
      ccllen[anyccl], nextecm,
      ecgroup, csize, csize );

    madeany = 1;
    }

   ++rulelen;

   yyval = mkstate( -anyccl );
   ;
    break;}
case 51:
{
   if ( ! cclsorted )




    cshell( ccltbl + cclmap[yyvsp[0]], ccllen[yyvsp[0]], 1 );

   if ( useecs )
    mkeccl( ccltbl + cclmap[yyvsp[0]], ccllen[yyvsp[0]],
     nextecm, ecgroup, csize, csize );

   ++rulelen;

   yyval = mkstate( -yyvsp[0] );
   ;
    break;}
case 52:
{
   ++rulelen;

   yyval = mkstate( -yyvsp[0] );
   ;
    break;}
case 53:
{ yyval = yyvsp[-1]; ;
    break;}
case 54:
{ yyval = yyvsp[-1]; ;
    break;}
case 55:
{
   ++rulelen;

   if ( caseins && yyvsp[0] >= 'A' && yyvsp[0] <= 'Z' )
    yyvsp[0] = clower( yyvsp[0] );

   yyval = mkstate( yyvsp[0] );
   ;
    break;}
case 56:
{ yyval = yyvsp[-1]; ;
    break;}
case 57:
{
   cclnegate( yyvsp[-1] );
   yyval = yyvsp[-1];
   ;
    break;}
case 58:
{
   if ( caseins )
    {
    if ( yyvsp[-2] >= 'A' && yyvsp[-2] <= 'Z' )
     yyvsp[-2] = clower( yyvsp[-2] );
    if ( yyvsp[0] >= 'A' && yyvsp[0] <= 'Z' )
     yyvsp[0] = clower( yyvsp[0] );
    }

   if ( yyvsp[-2] > yyvsp[0] )
    synerr( "negative range in character class" );

   else
    {
    for ( i = yyvsp[-2]; i <= yyvsp[0]; ++i )
     ccladd( yyvsp[-3], i );




    cclsorted = cclsorted && (yyvsp[-2] > lastchar);
    lastchar = yyvsp[0];
    }

   yyval = yyvsp[-3];
   ;
    break;}
case 59:
{
   if ( caseins && yyvsp[0] >= 'A' && yyvsp[0] <= 'Z' )
    yyvsp[0] = clower( yyvsp[0] );

   ccladd( yyvsp[-1], yyvsp[0] );
   cclsorted = cclsorted && (yyvsp[0] > lastchar);
   lastchar = yyvsp[0];
   yyval = yyvsp[-1];
   ;
    break;}
case 60:
{

   cclsorted = 0;
   yyval = yyvsp[-1];
   ;
    break;}
case 61:
{
   cclsorted = 1;
   lastchar = 0;
   currccl = yyval = cclinit();
   ;
    break;}
case 62:
{ { int c; for ( c = 0; c < csize; ++c ) if ( 
# 10305 "flex_single_original.c" 3 4
 (((
# 10305 "flex_single_original.c"
 c
# 10305 "flex_single_original.c" 3 4
 ) & ~0x7f) == 0) 
# 10305 "flex_single_original.c"
 && 
# 10305 "flex_single_original.c" 3 4
 ((*__ctype_b_loc ())[(int) ((
# 10305 "flex_single_original.c"
 c
# 10305 "flex_single_original.c" 3 4
 ))] & (unsigned short int) _ISalnum) 
# 10305 "flex_single_original.c"
 ) ccladd( currccl, c ); } ;
    break;}
case 63:
{ { int c; for ( c = 0; c < csize; ++c ) if ( 
# 10308 "flex_single_original.c" 3 4
 (((
# 10308 "flex_single_original.c"
 c
# 10308 "flex_single_original.c" 3 4
 ) & ~0x7f) == 0) 
# 10308 "flex_single_original.c"
 && 
# 10308 "flex_single_original.c" 3 4
 ((*__ctype_b_loc ())[(int) ((
# 10308 "flex_single_original.c"
 c
# 10308 "flex_single_original.c" 3 4
 ))] & (unsigned short int) _ISalpha) 
# 10308 "flex_single_original.c"
 ) ccladd( currccl, c ); } ;
    break;}
case 64:
{ { int c; for ( c = 0; c < csize; ++c ) if ( 
# 10311 "flex_single_original.c" 3 4
 (((
# 10311 "flex_single_original.c"
 c
# 10311 "flex_single_original.c" 3 4
 ) & ~0x7f) == 0) 
# 10311 "flex_single_original.c"
 && ((c) == ' ' || (c) == '\t') ) ccladd( currccl, c ); } ;
    break;}
case 65:
{ { int c; for ( c = 0; c < csize; ++c ) if ( 
# 10314 "flex_single_original.c" 3 4
 (((
# 10314 "flex_single_original.c"
 c
# 10314 "flex_single_original.c" 3 4
 ) & ~0x7f) == 0) 
# 10314 "flex_single_original.c"
 && 
# 10314 "flex_single_original.c" 3 4
 ((*__ctype_b_loc ())[(int) ((
# 10314 "flex_single_original.c"
 c
# 10314 "flex_single_original.c" 3 4
 ))] & (unsigned short int) _IScntrl) 
# 10314 "flex_single_original.c"
 ) ccladd( currccl, c ); } ;
    break;}
case 66:
{ { int c; for ( c = 0; c < csize; ++c ) if ( 
# 10317 "flex_single_original.c" 3 4
 (((
# 10317 "flex_single_original.c"
 c
# 10317 "flex_single_original.c" 3 4
 ) & ~0x7f) == 0) 
# 10317 "flex_single_original.c"
 && 
# 10317 "flex_single_original.c" 3 4
 ((*__ctype_b_loc ())[(int) ((
# 10317 "flex_single_original.c"
 c
# 10317 "flex_single_original.c" 3 4
 ))] & (unsigned short int) _ISdigit) 
# 10317 "flex_single_original.c"
 ) ccladd( currccl, c ); } ;
    break;}
case 67:
{ { int c; for ( c = 0; c < csize; ++c ) if ( 
# 10320 "flex_single_original.c" 3 4
 (((
# 10320 "flex_single_original.c"
 c
# 10320 "flex_single_original.c" 3 4
 ) & ~0x7f) == 0) 
# 10320 "flex_single_original.c"
 && 
# 10320 "flex_single_original.c" 3 4
 ((*__ctype_b_loc ())[(int) ((
# 10320 "flex_single_original.c"
 c
# 10320 "flex_single_original.c" 3 4
 ))] & (unsigned short int) _ISgraph) 
# 10320 "flex_single_original.c"
 ) ccladd( currccl, c ); } ;
    break;}
case 68:
{ { int c; for ( c = 0; c < csize; ++c ) if ( 
# 10323 "flex_single_original.c" 3 4
 (((
# 10323 "flex_single_original.c"
 c
# 10323 "flex_single_original.c" 3 4
 ) & ~0x7f) == 0) 
# 10323 "flex_single_original.c"
 && 
# 10323 "flex_single_original.c" 3 4
 ((*__ctype_b_loc ())[(int) ((
# 10323 "flex_single_original.c"
 c
# 10323 "flex_single_original.c" 3 4
 ))] & (unsigned short int) _ISlower) 
# 10323 "flex_single_original.c"
 ) ccladd( currccl, c ); } ;
    break;}
case 69:
{ { int c; for ( c = 0; c < csize; ++c ) if ( 
# 10326 "flex_single_original.c" 3 4
 (((
# 10326 "flex_single_original.c"
 c
# 10326 "flex_single_original.c" 3 4
 ) & ~0x7f) == 0) 
# 10326 "flex_single_original.c"
 && 
# 10326 "flex_single_original.c" 3 4
 ((*__ctype_b_loc ())[(int) ((
# 10326 "flex_single_original.c"
 c
# 10326 "flex_single_original.c" 3 4
 ))] & (unsigned short int) _ISprint) 
# 10326 "flex_single_original.c"
 ) ccladd( currccl, c ); } ;
    break;}
case 70:
{ { int c; for ( c = 0; c < csize; ++c ) if ( 
# 10329 "flex_single_original.c" 3 4
 (((
# 10329 "flex_single_original.c"
 c
# 10329 "flex_single_original.c" 3 4
 ) & ~0x7f) == 0) 
# 10329 "flex_single_original.c"
 && 
# 10329 "flex_single_original.c" 3 4
 ((*__ctype_b_loc ())[(int) ((
# 10329 "flex_single_original.c"
 c
# 10329 "flex_single_original.c" 3 4
 ))] & (unsigned short int) _ISpunct) 
# 10329 "flex_single_original.c"
 ) ccladd( currccl, c ); } ;
    break;}
case 71:
{ { int c; for ( c = 0; c < csize; ++c ) if ( 
# 10332 "flex_single_original.c" 3 4
 (((
# 10332 "flex_single_original.c"
 c
# 10332 "flex_single_original.c" 3 4
 ) & ~0x7f) == 0) 
# 10332 "flex_single_original.c"
 && 
# 10332 "flex_single_original.c" 3 4
 ((*__ctype_b_loc ())[(int) ((
# 10332 "flex_single_original.c"
 c
# 10332 "flex_single_original.c" 3 4
 ))] & (unsigned short int) _ISspace) 
# 10332 "flex_single_original.c"
 ) ccladd( currccl, c ); } ;
    break;}
case 72:
{
    if ( caseins )
     { int c; for ( c = 0; c < csize; ++c ) if ( 
# 10337 "flex_single_original.c" 3 4
    (((
# 10337 "flex_single_original.c"
    c
# 10337 "flex_single_original.c" 3 4
    ) & ~0x7f) == 0) 
# 10337 "flex_single_original.c"
    && 
# 10337 "flex_single_original.c" 3 4
    ((*__ctype_b_loc ())[(int) ((
# 10337 "flex_single_original.c"
    c
# 10337 "flex_single_original.c" 3 4
    ))] & (unsigned short int) _ISlower) 
# 10337 "flex_single_original.c"
    ) ccladd( currccl, c ); }
    else
     { int c; for ( c = 0; c < csize; ++c ) if ( 
# 10339 "flex_single_original.c" 3 4
    (((
# 10339 "flex_single_original.c"
    c
# 10339 "flex_single_original.c" 3 4
    ) & ~0x7f) == 0) 
# 10339 "flex_single_original.c"
    && 
# 10339 "flex_single_original.c" 3 4
    ((*__ctype_b_loc ())[(int) ((
# 10339 "flex_single_original.c"
    c
# 10339 "flex_single_original.c" 3 4
    ))] & (unsigned short int) _ISupper) 
# 10339 "flex_single_original.c"
    ) ccladd( currccl, c ); }
    ;
    break;}
case 73:
{ { int c; for ( c = 0; c < csize; ++c ) if ( 
# 10343 "flex_single_original.c" 3 4
 (((
# 10343 "flex_single_original.c"
 c
# 10343 "flex_single_original.c" 3 4
 ) & ~0x7f) == 0) 
# 10343 "flex_single_original.c"
 && 
# 10343 "flex_single_original.c" 3 4
 ((*__ctype_b_loc ())[(int) ((
# 10343 "flex_single_original.c"
 c
# 10343 "flex_single_original.c" 3 4
 ))] & (unsigned short int) _ISxdigit) 
# 10343 "flex_single_original.c"
 ) ccladd( currccl, c ); } ;
    break;}
case 74:
{
   if ( caseins && yyvsp[0] >= 'A' && yyvsp[0] <= 'Z' )
    yyvsp[0] = clower( yyvsp[0] );

   ++rulelen;

   yyval = link_machines( yyvsp[-1], mkstate( yyvsp[0] ) );
   ;
    break;}
case 75:
{ yyval = mkstate( (256 + 1) ); ;
    break;}
}

  yyvsp -= yylen;
  yyssp -= yylen;
# 10377 "flex_single_original.c"
  *++yyvsp = yyval;
# 10401 "flex_single_original.c"
  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - 48] + *yyssp;
  if (yystate >= 0 && yystate <= 110 && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - 48];

  goto yynewstate;

yyerrlab:

  if (! yyerrstatus)

    {
      ++yynerrs;
# 10459 "flex_single_original.c"
 yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:

  if (yyerrstatus == 3)
    {



      if (yychar == 0)
 goto yyabortlab;






      yychar = -2;
    }




  yyerrstatus = 3;

  goto yyerrhandle;

yyerrdefault:
# 10497 "flex_single_original.c"
yyerrpop:

  if (yyssp == yyss) goto yyabortlab;
  yyvsp--;
  yystate = *--yyssp;
# 10517 "flex_single_original.c"
yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == -32768)
    goto yyerrdefault;

  yyn += 1;
  if (yyn < 0 || yyn > 110 || yycheck[yyn] != 1)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == -32768)
 goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == 107)
    goto yyacceptlab;






  *++yyvsp = yylval;




  yystate = yyn;
  goto yynewstate;

 yyacceptlab:

  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);



    }
  return 0;

 yyabortlab:

  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);



    }
  return 1;
}







void build_eof_action()
 {
 register int i;
 char action_text[2048];

 for ( i = 1; i <= scon_stk_ptr; ++i )
  {
  if ( sceof[scon_stk[i]] )
   format_pinpoint_message(
    "multiple <<EOF>> rules for start condition %s",
    scname[scon_stk[i]] );

  else
   {
   sceof[scon_stk[i]] = 1;
   sprintf( action_text, "case YY_STATE_EOF(%s):\n",
    scname[scon_stk[i]] );
   add_action( action_text );
   }
  }

 line_directive_out( (FILE *) 0, 1 );






 --num_rules;
 ++num_eof_rules;
 }




void format_synerr( msg, arg )
char msg[], arg[];
 {
 char errmsg[2048];

 (void) sprintf( errmsg, msg, arg );
 synerr( errmsg );
 }




void synerr( str )
char str[];
 {
 syntaxerror = 1;
 pinpoint_message( str );
 }




void format_warn( msg, arg )
char msg[], arg[];
 {
 char warn_msg[2048];

 (void) sprintf( warn_msg, msg, arg );
 warn( warn_msg );
 }




void warn( str )
char str[];
 {
 line_warning( str, linenum );
 }





void format_pinpoint_message( msg, arg )
char msg[], arg[];
 {
 char errmsg[2048];

 (void) sprintf( errmsg, msg, arg );
 pinpoint_message( errmsg );
 }




void pinpoint_message( str )
char str[];
 {
 line_pinpoint( str, linenum );
 }




void line_warning( str, line )
char str[];
int line;
 {
 char warning[2048];

 if ( ! nowarn )
  {
  sprintf( warning, "warning, %s", str );
  line_pinpoint( warning, line );
  }
 }




void line_pinpoint( str, line )
char str[];
int line;
 {
 fprintf( err, "\"%s\", line %d: %s\n", infilename, line, str );
 }






void yyerror( msg )
char msg[];
 {
 }
# 10815 "flex_single_original.c"
typedef struct yy_buffer_state *YY_BUFFER_STATE;

extern int yyleng;
extern FILE *yyin, *yyout;
# 10857 "flex_single_original.c"
typedef unsigned int yy_size_t;


struct yy_buffer_state
 {
 FILE *yy_input_file;

 char *yy_ch_buf;
 char *yy_buf_pos;




 yy_size_t yy_buf_size;




 int yy_n_chars;





 int yy_is_our_buffer;






 int yy_is_interactive;





 int yy_at_bol;




 int yy_fill_buffer;

 int yy_buffer_status;
# 10915 "flex_single_original.c"
 };

static YY_BUFFER_STATE yy_current_buffer = 0;
# 10927 "flex_single_original.c"
static char yy_hold_char;

static int yy_n_chars;


int yyleng;


static char *yy_c_buf_p = (char *) 0;
static int yy_init = 1;
static int yy_start = 0;




static int yy_did_buffer_switch_on_eof;

void yyrestart ( FILE *input_file );

void yy_switch_to_buffer ( YY_BUFFER_STATE new_buffer );
void yy_load_buffer_state ( void );
YY_BUFFER_STATE yy_create_buffer ( FILE *file, int size );
void yy_delete_buffer ( YY_BUFFER_STATE b );
void yy_init_buffer ( YY_BUFFER_STATE b, FILE *file );
void yy_flush_buffer ( YY_BUFFER_STATE b );


YY_BUFFER_STATE yy_scan_buffer ( char *base, yy_size_t size );
YY_BUFFER_STATE yy_scan_string ( const char *str );
YY_BUFFER_STATE yy_scan_bytes ( const char *bytes, int len );

static void *yy_flex_alloc ( yy_size_t );
static void *yy_flex_realloc ( void *, yy_size_t );
static void yy_flex_free ( void * );
# 10980 "flex_single_original.c"
typedef unsigned char YY_CHAR;
FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;
typedef int yy_state_type;
extern char *yytext;


static yy_state_type yy_get_previous_state ( void );
static yy_state_type yy_try_NUL_trans ( yy_state_type current_state );
static int yy_get_next_buffer ( void );
static void yy_fatal_error ( const char msg[] );
# 11003 "flex_single_original.c"
static const short int yy_accept[769] =
    { 0,
        0, 0, 0, 0, 87, 87, 163, 163, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 166, 164,
        7, 18, 164, 16, 1, 17, 164, 164, 164, 164,
       15, 108, 100, 101, 108, 93, 108, 107, 108, 108,
      108, 107, 99, 89, 108, 108, 91, 92, 87, 88,
       87, 86, 85, 86, 86, 163, 163, 28, 29, 28,
       28, 28, 28, 28, 28, 31, 30, 32, 31, 113,
      109, 110, 112, 114, 141, 142, 141, 139, 138, 140,

      115, 117, 115, 116, 115, 120, 120, 120, 120, 122,
      124, 122, 122, 122, 122, 123, 151, 155, 151, 154,
      156, 156, 152, 152, 152, 149, 150, 164, 82, 164,
       21, 22, 21, 20, 157, 159, 157, 160, 161, 147,
      147, 148, 147, 147, 147, 147, 147, 147, 147, 81,
       34, 33, 81, 81, 81, 81, 35, 81, 81, 81,
       81, 81, 81, 81, 81, 81, 81, 81, 81, 81,
       81, 81, 81, 81, 81, 81, 26, 23, 26, 24,
        7, 18, 0, 16, 1, 17, 0, 0, 0, 14,
        8, 0, 0, 0, 0, 4, 5, 0, 2, 15,

      100, 101, 0, 0, 0, 95, 0, 0, 105, 105,
        0, 162, 162, 162, 94, 0, 99, 89, 0, 0,
        0, 91, 92, 104, 90, 0, 87, 88, 86, 85,
       85, 83, 84, 163, 163, 28, 29, 28, 28, 28,
       28, 31, 30, 32, 111, 112, 142, 138, 117, 0,
      118, 119, 124, 121, 151, 155, 0, 153, 0, 144,
      152, 152, 152, 0, 82, 0, 21, 22, 21, 19,
      157, 159, 158, 147, 147, 147, 148, 143, 147, 147,
      147, 34, 33, 0, 80, 0, 0, 81, 81, 81,
       81, 81, 81, 81, 81, 81, 81, 81, 81, 81,

       81, 81, 81, 36, 81, 81, 81, 81, 81, 81,
       81, 81, 81, 81, 0, 25, 24, 0, 14, 8,
        0, 12, 0, 0, 0, 0, 0, 4, 5, 0,
        6, 0, 96, 0, 97, 0, 0, 105, 105, 0,
      105, 105, 105, 162, 162, 0, 106, 90, 98, 0,
      104, 0, 83, 84, 28, 28, 28, 27, 28, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 152, 152, 143, 143, 147, 147, 0, 0, 81,
       81, 81, 81, 81, 44, 81, 81, 81, 49, 81,
       81, 81, 81, 81, 81, 81, 81, 81, 81, 81,

       81, 81, 81, 81, 81, 81, 81, 81, 0, 81,
       81, 81, 81, 0, 0, 0, 12, 0, 0, 0,
        0, 0, 0, 4, 5, 0, 105, 105, 105, 105,
      105, 105, 162, 0, 0, 28, 28, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      152, 152, 147, 147, 37, 38, 81, 81, 81, 81,
       81, 81, 81, 81, 50, 51, 81, 81, 81, 55,
       81, 81, 81, 81, 81, 81, 60, 81, 81, 81,
       81, 81, 81, 67, 0, 0, 0, 81, 81, 81,
       81, 0, 13, 0, 0, 0, 0, 0, 0, 105,

      105, 105, 105, 105, 105, 0, 0, 28, 28, 137,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 152, 152, 147, 147, 39, 81, 41, 81,
       43, 81, 81, 81, 47, 81, 52, 81, 81, 81,
       81, 81, 81, 81, 81, 81, 62, 81, 81, 65,
       81, 0, 0, 0, 0, 81, 81, 81, 81, 3,
        0, 0, 0, 0, 105, 105, 105, 0, 0, 28,
       28, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 145, 146, 145, 146, 81, 42, 81,
       81, 81, 81, 81, 81, 81, 81, 81, 81, 81,

       81, 78, 61, 81, 64, 81, 0, 0, 0, 0,
       81, 81, 69, 70, 0, 10, 0, 11, 0, 103,
        0, 102, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 81, 81, 81, 45, 81, 48,
       81, 81, 81, 81, 77, 81, 59, 63, 66, 0,
        0, 0, 0, 79, 81, 0, 102, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 81,
       81, 81, 46, 81, 81, 56, 81, 81, 0, 0,
        0, 0, 68, 0, 9, 0, 125, 126, 127, 128,
      129, 130, 131, 132, 133, 134, 135, 0, 81, 81,

       81, 81, 81, 81, 81, 0, 0, 0, 0, 0,
      136, 81, 81, 81, 81, 54, 81, 81, 0, 0,
        0, 0, 0, 0, 81, 81, 81, 53, 81, 58,
        0, 0, 0, 0, 0, 0, 81, 81, 81, 81,
       72, 0, 0, 0, 0, 73, 81, 81, 81, 81,
       71, 0, 75, 0, 81, 81, 81, 74, 76, 81,
       81, 81, 81, 81, 81, 57, 40, 0
    } ;

static const int yy_ec[256] =
    { 0,
        1, 1, 1, 1, 1, 1, 1, 1, 2, 3,
        1, 1, 4, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 2, 1, 5, 6, 7, 8, 1, 9, 10,
       10, 11, 12, 13, 14, 10, 15, 16, 16, 16,
       16, 16, 16, 16, 17, 18, 19, 20, 1, 21,
       22, 23, 10, 1, 31, 32, 33, 34, 35, 36,
       37, 38, 39, 40, 41, 42, 43, 44, 45, 46,
       47, 48, 49, 50, 51, 52, 53, 54, 55, 47,
       26, 27, 28, 29, 30, 1, 31, 32, 33, 34,

       35, 36, 37, 38, 39, 40, 41, 42, 43, 44,
       45, 46, 47, 48, 49, 50, 51, 52, 53, 54,
       55, 47, 56, 57, 58, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,

        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1
    } ;

static const int yy_meta[59] =
    { 0,
        1, 1, 2, 1, 3, 1, 1, 1, 4, 1,
        5, 6, 1, 7, 4, 8, 8, 8, 8, 1,
        1, 1, 1, 9, 10, 1, 11, 12, 1, 13,
       14, 14, 14, 14, 14, 14, 15, 15, 15, 15,
       15, 15, 15, 15, 15, 15, 15, 15, 15, 15,
       15, 15, 15, 15, 15, 4, 1, 16
    } ;

static const short int yy_base[858] =
    { 0,
        0, 58, 115, 172, 120, 129, 2712, 2711, 230, 2705,
      136, 141, 288, 0, 2683, 2682, 144, 151, 185, 191,
      178, 188, 344, 347, 375, 0, 125, 131, 147, 216,
      431, 434, 461, 0, 519, 0, 205, 349, 2710, 2716,
      353, 2716, 2706, 0, 360, 2716, 2705, 144, 570, 2696,
        0, 2716, 577, 2716, 2703, 2716, 438, 2716, 2684, 126,
      149, 427, 591, 2716, 2701, 141, 2682, 2716, 0, 2716,
     2699, 0, 2699, 2697, 155, 2696, 2716, 0, 2716, 2695,
     2716, 0, 2662, 2641, 2637, 0, 2692, 2716, 2690, 2716,
     2716, 2663, 0, 2716, 2716, 2716, 2688, 2716, 431, 2716,

     2716, 2716, 2687, 2716, 567, 2716, 2669, 571, 164, 2716,
     2716, 2685, 0, 2667, 573, 2716, 0, 2716, 2683, 2716,
      573, 2674, 0, 2649, 2628, 2716, 2716, 222, 2716, 356,
      448, 2716, 450, 2667, 0, 2716, 2678, 2716, 0, 0,
      198, 2716, 2677, 2621, 2716, 2667, 0, 2642, 2621, 2716,
     2673, 2716, 2671, 2668, 2640, 2639, 2716, 544, 2639, 579,
     2634, 2635, 318, 0, 2623, 2631, 424, 562, 2614, 587,
     2629, 2613, 2618, 2626, 2629, 2604, 2716, 2716, 2653, 612,
      634, 2716, 2654, 0, 637, 2716, 2653, 600, 2616, 0,
        0, 641, 647, 651, 669, 0, 0, 453, 2716, 0,

      672, 2716, 2651, 2597, 605, 2716, 2649, 2616, 620, 657,
      645, 2716, 662, 0, 2716, 2592, 688, 2716, 2646, 2592,
     2636, 2625, 2716, 0, 2716, 2610, 0, 2716, 0, 0,
     2642, 0, 0, 2640, 2716, 0, 2716, 0, 2602, 2598,
      745, 0, 2638, 2716, 2716, 0, 2716, 688, 2716, 773,
     2716, 2716, 2716, 2716, 0, 2716, 673, 2716, 0, 2716,
        0, 2599, 2595, 690, 2716, 698, 707, 2716, 709, 2716,
        0, 2716, 2716, 0, 596, 2579, 2716, 827, 0, 2596,
     2592, 2632, 2716, 2628, 2716, 2593, 2592, 0, 642, 2582,
      563, 2617, 2579, 620, 2578, 2577, 2583, 669, 2570, 2584,

     2572, 0, 2569, 2716, 2570, 2571, 2579, 2582, 685, 125,
     2570, 2567, 2566, 688, 2608, 2716, 716, 2568, 0, 0,
      720, 2716, 2608, 884, 2562, 2559, 2569, 0, 0, 723,
     2716, 739, 2716, 805, 2716, 808, 2562, 787, 869, 876,
      930, 881, 973, 800, 0, 2548, 2716, 2716, 2716, 2570,
        0, 2559, 0, 0, 2568, 2557, 0, 2716, 0, 1009,
     2581, 678, 870, 871, 874, 879, 913, 992, 974, 1013,
      885, 2565, 2554, 0, 1067, 2563, 2552, 2546, 2545, 2557,
     2562, 2561, 2550, 2557, 0, 2554, 2537, 2556, 0, 2536,
     2543, 2533, 2548, 2568, 2537, 2549, 2544, 2542, 2541, 2532,

     2539, 2540, 2538, 2539, 578, 2520, 2538, 2525, 860, 2526,
     2528, 2521, 2517, 2529, 817, 1044, 2716, 822, 1095, 914,
     2532, 2523, 2517, 0, 0, 2524, 1102, 1025, 1142, 2539,
     1028, 1163, 2716, 2513, 2521, 2523, 2507, 0, 2526, 1058,
      891, 1014, 1019, 894, 1038, 1080, 1072, 1086, 1083, 1081,
     2520, 2504, 2518, 2502, 2716, 2716, 2505, 2493, 2492, 2495,
     2507, 1148, 2507, 2492, 0, 0, 2492, 2493, 2507, 0,
     2525, 2490, 2498, 2522, 2485, 2495, 0, 2500, 2491, 2487,
     2479, 2479, 2483, 0, 875, 2494, 2481, 2494, 2480, 2475,
     2491, 2519, 2716, 920, 999, 2465, 2474, 2468, 2494, 2496,

     1105, 1184, 1081, 902, 969, 2479, 2491, 2463, 2477, 2716,
      165, 1090, 1144, 1143, 1147, 1163, 1095, 1145, 1037, 1085,
     1150, 1173, 2461, 2475, 2459, 2473, 0, 2458, 0, 2460,
        0, 1165, 2454, 2469, 0, 2461, 0, 2471, 2410, 2414,
     2434, 2400, 2393, 2405, 2385, 2382, 0, 2383, 2335, 0,
     2335, 2330, 2326, 2309, 2278, 2259, 2269, 2268, 2256, 2297,
     1046, 2238, 2242, 2253, 1179, 1142, 1145, 2247, 2246, 0,
        0, 1191, 1192, 1172, 1201, 1202, 1204, 1205, 1206, 1207,
     1209, 1210, 1208, 0, 0, 0, 0, 2254, 0, 2221,
     2229, 2218, 2208, 2200, 2209, 2198, 2195, 2165, 2168, 2149,

     2132, 0, 0, 2129, 0, 2139, 2143, 2134, 2124, 2137,
     2117, 2116, 0, 0, 1228, 2716, 1232, 2716, 2111, 2716,
     2117, 2716, 2115, 2114, 2108, 2107, 2106, 2103, 2102, 2098,
     2095, 2063, 2047, 1213, 2012, 1986, 1975, 0, 1954, 0,
     1947, 1950, 1941, 1945, 0, 1942, 0, 0, 0, 1938,
     1940, 1934, 1905, 0, 1872, 1234, 2716, 1888, 1882, 1881,
     1864, 1848, 1832, 1828, 1827, 1826, 1823, 1806, 1809, 1784,
     1787, 1772, 0, 1781, 1786, 0, 1766, 1767, 1759, 1744,
     1213, 1736, 0, 1236, 2716, 1245, 2716, 2716, 2716, 2716,
     2716, 2716, 2716, 2716, 2716, 2716, 2716, 1750, 1727, 1720,

     1701, 1687, 1670, 1681, 1667, 1679, 1659, 689, 1658, 1671,
     2716, 1657, 1627, 1621, 1635, 0, 1603, 1596, 1595, 1608,
     1602, 1587, 1586, 1583, 1581, 1587, 1555, 0, 1547, 0,
     1527, 1507, 1520, 1503, 1483, 1482, 1485, 1443, 1440, 1228,
     2716, 1225, 1224, 1206, 1210, 2716, 1213, 1202, 1018, 948,
     2716, 945, 2716, 884, 780, 771, 779, 2716, 2716, 689,
      673, 581, 408, 318, 86, 0, 0, 2716, 1263, 1279,
     1295, 1311, 1327, 1343, 1359, 1375, 1391, 1407, 1423, 1439,
     1455, 1471, 1481, 1496, 1505, 1520, 1536, 1545, 1560, 1576,
     1592, 1608, 1624, 1634, 1649, 1659, 1674, 1690, 1706, 1718,

     1728, 1743, 1759, 1775, 1791, 1807, 1817, 1832, 1843, 1236,
     1858, 1874, 1890, 1898, 1905, 1920, 1936, 1952, 1968, 1977,
     1985, 2001, 2017, 2033, 2049, 2065, 2081, 2097, 2113, 2123,
     2138, 2148, 2155, 2170, 2182, 2192, 2207, 2223, 2239, 2255,
     2265, 2280, 2291, 2306, 2322, 2338, 2354, 2364, 2373, 2388,
     2404, 2420, 2429, 2437, 2453, 2469, 2485
    } ;

static const short int yy_def[858] =
    { 0,
      768, 768, 769, 769, 770, 771, 772, 772, 768, 9,
      773, 773, 768, 13, 774, 774, 775, 775, 776, 776,
      777, 777, 778, 778, 768, 25, 779, 779, 780, 780,
      781, 781, 768, 33, 768, 35, 782, 782, 768, 768,
      768, 768, 768, 783, 768, 768, 768, 768, 784, 768,
      785, 768, 768, 768, 768, 768, 768, 768, 768, 786,
      787, 788, 768, 768, 768, 768, 768, 768, 789, 768,
      789, 790, 791, 790, 790, 792, 768, 793, 768, 793,
      768, 794, 794, 794, 793, 795, 768, 768, 795, 768,
      768, 768, 796, 768, 768, 768, 768, 768, 768, 768,

      768, 768, 768, 768, 787, 768, 768, 787, 797, 768,
      768, 768, 798, 768, 787, 768, 799, 768, 799, 768,
      800, 768, 801, 801, 801, 768, 768, 802, 768, 802,
      803, 768, 803, 768, 804, 768, 804, 768, 805, 806,
      806, 768, 806, 806, 768, 806, 807, 807, 807, 768,
      768, 768, 768, 808, 768, 768, 768, 809, 809, 809,
      809, 809, 809, 809, 809, 809, 809, 810, 809, 809,
      809, 809, 809, 809, 809, 809, 768, 768, 811, 768,
      768, 768, 768, 783, 768, 768, 768, 768, 768, 812,
      813, 768, 768, 768, 768, 814, 815, 816, 768, 785,

      768, 768, 768, 768, 817, 768, 768, 768, 818, 818,
      819, 768, 768, 820, 768, 821, 768, 768, 768, 768,
      768, 768, 768, 822, 768, 768, 823, 768, 824, 825,
      825, 826, 827, 828, 768, 829, 768, 830, 830, 830,
      768, 831, 768, 768, 768, 832, 768, 768, 768, 833,
      768, 768, 768, 768, 834, 768, 835, 768, 835, 768,
      836, 836, 836, 837, 768, 837, 838, 768, 838, 768,
      839, 768, 768, 840, 840, 840, 768, 768, 841, 841,
      841, 768, 768, 842, 768, 768, 768, 843, 843, 843,
      843, 843, 843, 843, 843, 843, 843, 843, 843, 843,

      843, 843, 843, 768, 843, 843, 843, 843, 843, 843,
      843, 843, 843, 843, 844, 768, 768, 768, 845, 846,
      847, 768, 768, 768, 768, 768, 768, 848, 849, 850,
      768, 850, 768, 851, 768, 851, 768, 852, 852, 852,
      768, 852, 852, 768, 853, 854, 768, 768, 768, 768,
      855, 768, 826, 827, 830, 830, 241, 768, 241, 241,
      833, 833, 833, 833, 833, 833, 833, 833, 833, 833,
      833, 836, 836, 278, 278, 841, 841, 768, 768, 843,
      843, 843, 843, 843, 843, 843, 843, 843, 843, 843,
      843, 843, 843, 843, 843, 843, 843, 843, 843, 843,

      843, 843, 843, 843, 843, 843, 843, 843, 768, 843,
      843, 843, 843, 768, 847, 847, 768, 847, 847, 768,
      768, 768, 768, 848, 849, 768, 341, 852, 343, 341,
      852, 343, 768, 768, 768, 830, 830, 360, 768, 833,
      833, 833, 833, 833, 833, 833, 833, 833, 833, 833,
      836, 836, 841, 841, 768, 768, 843, 843, 843, 843,
      843, 843, 843, 843, 843, 843, 843, 843, 843, 843,
      843, 843, 843, 843, 843, 843, 843, 843, 843, 843,
      843, 843, 843, 843, 768, 768, 768, 843, 843, 843,
      843, 768, 768, 847, 847, 768, 768, 768, 768, 427,

      852, 343, 852, 852, 852, 768, 768, 830, 830, 768,
      833, 833, 833, 833, 833, 833, 833, 833, 833, 833,
      833, 833, 836, 836, 841, 841, 843, 843, 843, 843,
      843, 843, 843, 843, 843, 843, 843, 843, 843, 843,
      843, 843, 843, 843, 843, 843, 843, 843, 843, 843,
      843, 768, 768, 768, 768, 843, 843, 843, 843, 768,
      856, 768, 768, 768, 852, 852, 852, 768, 768, 830,
      830, 833, 833, 833, 833, 833, 833, 833, 833, 833,
      833, 833, 833, 836, 836, 841, 841, 843, 843, 843,
      843, 843, 843, 843, 843, 843, 843, 843, 843, 843,

      843, 843, 843, 843, 843, 843, 768, 768, 768, 768,
      843, 843, 843, 843, 856, 768, 856, 768, 768, 768,
      768, 768, 833, 833, 833, 833, 833, 833, 833, 833,
      833, 833, 833, 833, 843, 843, 843, 843, 843, 843,
      843, 843, 843, 843, 843, 843, 843, 843, 843, 768,
      768, 768, 768, 843, 843, 857, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 833, 843,
      843, 843, 843, 843, 843, 843, 843, 843, 768, 768,
      768, 768, 843, 857, 768, 857, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 843, 843,

      843, 843, 843, 843, 843, 768, 768, 768, 768, 768,
      768, 843, 843, 843, 843, 843, 843, 843, 768, 768,
      768, 768, 768, 768, 843, 843, 843, 843, 843, 843,
      768, 768, 768, 768, 768, 768, 843, 843, 843, 843,
      768, 768, 768, 768, 768, 768, 843, 843, 843, 843,
      768, 768, 768, 768, 843, 843, 843, 768, 768, 843,
      843, 843, 843, 843, 843, 843, 843, 0, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,

      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768
    } ;

static const short int yy_nxt[2775] =
    { 0,
       40, 41, 42, 43, 40, 40, 40, 40, 40, 40,
       40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
       40, 40, 40, 44, 44, 40, 40, 40, 40, 44,
       44, 44, 44, 44, 44, 44, 44, 44, 44, 44,
       44, 44, 44, 44, 44, 44, 44, 44, 44, 44,
       44, 44, 44, 44, 44, 40, 40, 40, 40, 45,
       46, 47, 40, 48, 40, 49, 40, 40, 40, 40,
       40, 40, 50, 40, 40, 40, 40, 40, 40, 40,
       40, 51, 51, 40, 40, 40, 40, 51, 51, 51,
       51, 51, 51, 51, 51, 51, 51, 51, 51, 51,

       51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
       51, 51, 51, 40, 40, 40, 53, 54, 55, 56,
      767, 57, 70, 71, 58, 58, 58, 129, 130, 58,
       73, 70, 74, 129, 130, 59, 75, 87, 88, 89,
       60, 61, 87, 88, 89, 188, 96, 97, 224, 132,
      133, 210, 211, 96, 97, 404, 98, 134, 405, 99,
       99, 99, 99, 98, 213, 213, 99, 99, 99, 99,
       62, 58, 58, 63, 64, 65, 56, 252, 57, 66,
       40, 58, 58, 58, 439, 189, 58, 102, 103, 104,
       40, 252, 67, 102, 103, 104, 225, 60, 61, 275,

       68, 100, 214, 107, 108, 276, 109, 178, 100, 179,
      232, 105, 233, 107, 108, 572, 109, 105, 132, 133,
      180, 180, 180, 180, 265, 266, 134, 62, 58, 58,
       78, 78, 79, 80, 78, 78, 78, 78, 78, 78,
       81, 78, 78, 78, 78, 78, 78, 78, 78, 78,
       78, 78, 78, 82, 82, 78, 78, 78, 78, 82,
       82, 82, 82, 82, 82, 82, 82, 82, 82, 82,
       82, 82, 82, 82, 82, 82, 82, 83, 82, 82,
       82, 82, 82, 82, 84, 78, 78, 78, 90, 90,
       40, 90, 90, 90, 90, 90, 90, 90, 91, 90,

       91, 90, 90, 90, 90, 90, 90, 90, 90, 90,
       92, 93, 93, 90, 90, 90, 90, 93, 93, 93,
       93, 93, 93, 93, 93, 93, 93, 93, 93, 93,
       93, 93, 93, 93, 93, 93, 93, 93, 93, 93,
       93, 93, 93, 90, 90, 90, 111, 112, 296, 111,
      112, 178, 766, 179, 181, 182, 183, 113, 265, 266,
      113, 185, 186, 187, 180, 180, 180, 180, 297, 114,
      115, 116, 114, 115, 116, 117, 117, 118, 119, 120,
      117, 117, 117, 121, 117, 117, 117, 117, 117, 122,
      117, 117, 117, 117, 117, 117, 117, 117, 123, 123,

      117, 117, 117, 117, 123, 123, 123, 123, 123, 123,
      123, 123, 123, 123, 123, 123, 123, 123, 123, 123,
      123, 123, 124, 123, 123, 123, 123, 123, 123, 125,
      126, 117, 127, 136, 137, 138, 136, 137, 138, 206,
      206, 207, 215, 215, 215, 215, 248, 248, 248, 248,
      268, 269, 268, 269, 300, 331, 332, 139, 301, 765,
      139, 140, 141, 142, 143, 140, 140, 140, 144, 140,
      140, 145, 140, 140, 140, 146, 140, 140, 140, 140,
      140, 140, 140, 140, 147, 147, 140, 140, 140, 140,
      147, 147, 147, 147, 147, 147, 147, 147, 147, 147,

      147, 147, 147, 147, 147, 147, 147, 147, 148, 147,
      147, 147, 147, 147, 147, 149, 140, 140, 140, 150,
      151, 152, 153, 154, 150, 150, 150, 150, 150, 150,
      150, 150, 150, 150, 150, 155, 156, 150, 150, 150,
      157, 150, 150, 150, 150, 150, 150, 150, 150, 158,
      159, 160, 161, 162, 163, 164, 164, 165, 164, 164,
      166, 167, 168, 169, 170, 164, 171, 172, 164, 173,
      174, 175, 164, 176, 150, 150, 150, 191, 201, 202,
      203, 258, 213, 213, 204, 289, 213, 213, 213, 213,
      292, 290, 217, 218, 219, 383, 303, 275, 220, 259,

      192, 188, 193, 276, 193, 221, 304, 335, 336, 293,
      193, 222, 384, 193, 194, 195, 480, 193, 196, 223,
      214, 306, 481, 197, 214, 198, 214, 317, 317, 317,
      317, 307, 764, 205, 308, 181, 182, 183, 185, 186,
      187, 189, 321, 322, 323, 339, 340, 205, 321, 322,
      323, 387, 321, 322, 323, 388, 324, 324, 324, 324,
      342, 342, 324, 324, 324, 324, 324, 324, 324, 324,
      321, 322, 323, 201, 202, 203, 341, 344, 344, 204,
      380, 258, 339, 340, 324, 324, 324, 324, 325, 217,
      218, 219, 265, 266, 381, 220, 326, 439, 343, 259,

      265, 266, 221, 248, 248, 248, 248, 673, 222, 268,
      269, 268, 269, 327, 392, 402, 223, 409, 393, 440,
      410, 416, 417, 418, 403, 331, 332, 763, 205, 411,
      412, 317, 317, 317, 317, 419, 419, 419, 419, 721,
      413, 331, 332, 722, 205, 357, 357, 358, 359, 357,
      357, 357, 357, 357, 357, 360, 357, 357, 357, 357,
      357, 357, 357, 357, 357, 357, 357, 357, 360, 360,
      357, 357, 357, 357, 360, 360, 360, 360, 360, 360,
      360, 360, 360, 360, 360, 360, 360, 360, 360, 360,
      360, 360, 360, 360, 360, 360, 360, 360, 360, 360,

      357, 357, 357, 362, 363, 364, 365, 335, 336, 366,
      335, 336, 339, 340, 367, 212, 212, 762, 368, 493,
      494, 369, 761, 370, 417, 494, 371, 374, 374, 760,
      374, 374, 374, 374, 374, 374, 374, 375, 374, 374,
      374, 374, 374, 374, 374, 374, 374, 374, 374, 374,
      375, 375, 374, 374, 374, 374, 375, 375, 375, 375,
      375, 375, 375, 375, 375, 375, 375, 375, 375, 375,
      375, 375, 375, 375, 375, 375, 375, 375, 375, 375,
      375, 375, 374, 374, 374, 420, 322, 323, 427, 439,
      439, 428, 428, 439, 339, 340, 431, 431, 439, 324,

      324, 324, 324, 338, 439, 485, 339, 340, 486, 487,
      439, 441, 443, 439, 442, 420, 322, 323, 450, 552,
      759, 513, 493, 494, 516, 553, 444, 339, 340, 429,
      338, 338, 439, 338, 338, 338, 338, 338, 338, 338,
      338, 338, 338, 338, 338, 338, 338, 338, 338, 338,
      338, 338, 338, 430, 430, 339, 340, 445, 338, 338,
      430, 430, 430, 430, 430, 430, 430, 430, 430, 430,
      430, 430, 430, 430, 430, 430, 430, 430, 430, 430,
      430, 430, 430, 430, 430, 338, 338, 338, 432, 432,
      432, 432, 758, 439, 339, 340, 432, 757, 339, 340,

      495, 417, 418, 432, 432, 432, 432, 432, 432, 360,
      360, 439, 438, 360, 360, 360, 360, 360, 360, 448,
      360, 360, 360, 360, 360, 360, 360, 360, 360, 360,
      360, 360, 439, 439, 360, 360, 360, 360, 439, 446,
      501, 501, 447, 504, 504, 416, 417, 418, 616, 617,
      339, 340, 638, 339, 340, 515, 439, 439, 449, 419,
      419, 419, 419, 514, 360, 360, 360, 375, 375, 580,
      375, 375, 375, 375, 375, 375, 375, 439, 375, 375,
      375, 375, 375, 375, 375, 375, 375, 375, 375, 375,
      517, 439, 375, 375, 375, 375, 495, 417, 418, 439,

      439, 511, 439, 512, 439, 439, 339, 340, 209, 439,
      419, 419, 419, 419, 439, 519, 520, 581, 518, 522,
      566, 566, 375, 375, 375, 500, 500, 573, 521, 578,
      339, 340, 500, 500, 500, 500, 500, 500, 500, 500,
      500, 500, 500, 500, 500, 500, 500, 500, 500, 500,
      500, 500, 500, 500, 500, 500, 500, 502, 502, 502,
      502, 532, 439, 439, 439, 502, 439, 339, 340, 439,
      339, 340, 502, 502, 502, 502, 502, 502, 505, 505,
      505, 505, 439, 533, 582, 576, 505, 574, 579, 534,
      575, 439, 439, 505, 505, 505, 505, 505, 505, 567,

      567, 567, 567, 590, 339, 340, 338, 567, 577, 583,
      439, 439, 625, 591, 567, 567, 567, 567, 567, 567,
      439, 439, 624, 439, 439, 439, 439, 439, 439, 439,
      616, 617, 439, 623, 616, 617, 685, 686, 685, 686,
      756, 628, 626, 632, 708, 755, 634, 685, 686, 302,
      302, 627, 629, 754, 753, 630, 631, 633, 752, 751,
      750, 709, 669, 52, 52, 52, 52, 52, 52, 52,
       52, 52, 52, 52, 52, 52, 52, 52, 52, 69,
       69, 69, 69, 69, 69, 69, 69, 69, 69, 69,
       69, 69, 69, 69, 69, 72, 72, 72, 72, 72,

       72, 72, 72, 72, 72, 72, 72, 72, 72, 72,
       72, 76, 76, 76, 76, 76, 76, 76, 76, 76,
       76, 76, 76, 76, 76, 76, 76, 86, 86, 86,
       86, 86, 86, 86, 86, 86, 86, 86, 86, 86,
       86, 86, 86, 40, 40, 40, 40, 40, 40, 40,
       40, 40, 40, 40, 40, 40, 40, 40, 40, 95,
       95, 95, 95, 95, 95, 95, 95, 95, 95, 95,
       95, 95, 95, 95, 95, 101, 101, 101, 101, 101,
      101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
      101, 106, 106, 106, 106, 106, 106, 106, 106, 106,

      106, 106, 106, 106, 106, 106, 106, 110, 110, 110,
      110, 110, 110, 110, 110, 110, 110, 110, 110, 110,
      110, 110, 110, 128, 128, 128, 128, 128, 128, 128,
      128, 128, 128, 128, 128, 128, 128, 128, 128, 131,
      131, 131, 131, 131, 131, 131, 131, 131, 131, 131,
      131, 131, 131, 131, 131, 135, 135, 135, 135, 135,
      135, 135, 135, 135, 135, 135, 135, 135, 135, 135,
      135, 177, 177, 177, 177, 177, 177, 177, 177, 177,
      177, 177, 177, 177, 177, 177, 177, 184, 184, 184,
      184, 749, 748, 184, 184, 184, 190, 190, 190, 190,

      190, 190, 190, 190, 190, 190, 190, 190, 190, 190,
      190, 200, 200, 200, 200, 747, 746, 200, 200, 200,
      209, 745, 209, 209, 209, 209, 209, 209, 209, 209,
      209, 209, 209, 209, 209, 209, 212, 744, 212, 212,
      212, 212, 212, 212, 212, 212, 212, 212, 212, 212,
      212, 212, 216, 216, 216, 743, 742, 216, 216, 216,
      227, 741, 227, 227, 227, 227, 227, 227, 227, 227,
      227, 227, 227, 227, 227, 227, 229, 740, 229, 229,
      229, 229, 229, 229, 229, 229, 229, 229, 229, 229,
      229, 229, 230, 739, 230, 230, 230, 230, 230, 230,

      230, 230, 230, 230, 230, 230, 230, 230, 234, 234,
      234, 234, 234, 234, 234, 234, 234, 234, 234, 234,
      234, 234, 234, 234, 236, 738, 236, 236, 737, 236,
      236, 236, 736, 735, 236, 236, 734, 733, 732, 236,
      238, 238, 238, 238, 731, 730, 238, 238, 238, 242,
      729, 242, 242, 242, 242, 242, 242, 242, 242, 242,
      242, 242, 242, 242, 242, 246, 246, 246, 246, 728,
      727, 246, 246, 246, 251, 726, 251, 251, 251, 251,
      251, 251, 251, 251, 251, 251, 251, 251, 251, 251,
      254, 725, 254, 254, 254, 254, 254, 254, 254, 254,

      254, 724, 254, 254, 254, 254, 255, 723, 720, 719,
      255, 255, 255, 255, 718, 717, 255, 255, 257, 716,
      257, 257, 257, 257, 257, 257, 257, 257, 257, 257,
      257, 257, 257, 257, 261, 261, 261, 261, 715, 714,
      261, 261, 261, 264, 264, 264, 264, 264, 264, 264,
      264, 264, 264, 264, 264, 264, 264, 264, 264, 267,
      267, 267, 267, 713, 267, 267, 267, 267, 267, 267,
      267, 267, 267, 267, 267, 271, 712, 711, 271, 271,
      271, 271, 271, 271, 271, 710, 271, 271, 271, 271,
      271, 273, 707, 273, 273, 273, 273, 273, 273, 273,

      273, 273, 273, 273, 273, 273, 273, 274, 706, 274,
      274, 705, 274, 274, 274, 704, 703, 274, 274, 702,
      701, 700, 274, 279, 279, 279, 279, 699, 698, 279,
      279, 279, 284, 697, 284, 284, 284, 284, 284, 284,
      284, 284, 284, 284, 284, 284, 284, 284, 288, 288,
      696, 288, 288, 695, 694, 693, 288, 288, 315, 692,
      315, 315, 315, 315, 315, 315, 315, 315, 315, 315,
      315, 315, 315, 315, 319, 691, 319, 319, 319, 319,
      319, 319, 319, 319, 319, 319, 319, 319, 319, 319,
      320, 690, 320, 320, 320, 320, 320, 320, 320, 320,

      320, 320, 320, 320, 320, 320, 328, 328, 689, 688,
      328, 328, 328, 329, 329, 687, 683, 329, 329, 329,
      330, 330, 330, 330, 330, 330, 330, 330, 330, 330,
      330, 330, 330, 330, 330, 330, 334, 334, 334, 334,
      334, 334, 334, 334, 334, 334, 334, 334, 334, 334,
      334, 334, 338, 682, 338, 338, 338, 338, 338, 338,
      338, 338, 338, 681, 338, 338, 338, 338, 209, 680,
      209, 209, 209, 209, 209, 209, 209, 209, 209, 209,
      209, 209, 209, 209, 345, 345, 679, 678, 677, 676,
      345, 346, 346, 346, 346, 675, 674, 346, 346, 346,

      346, 351, 673, 351, 351, 351, 351, 351, 351, 351,
      351, 351, 351, 351, 351, 351, 351, 227, 672, 227,
      227, 227, 227, 227, 227, 227, 227, 227, 227, 227,
      227, 227, 227, 229, 671, 229, 229, 229, 229, 229,
      229, 229, 229, 229, 229, 229, 229, 229, 229, 230,
      670, 230, 230, 230, 230, 230, 230, 230, 230, 230,
      230, 230, 230, 230, 230, 353, 668, 353, 353, 353,
      353, 353, 353, 353, 353, 353, 353, 353, 353, 353,
      353, 354, 667, 354, 354, 354, 354, 354, 354, 354,
      354, 354, 354, 354, 354, 354, 354, 234, 234, 234,

      234, 234, 234, 234, 234, 234, 234, 234, 234, 234,
      234, 234, 234, 236, 666, 236, 236, 665, 236, 236,
      236, 664, 663, 236, 236, 662, 661, 660, 236, 238,
      238, 238, 238, 659, 658, 238, 238, 238, 242, 657,
      242, 242, 242, 242, 242, 242, 242, 242, 242, 242,
      242, 242, 242, 242, 246, 246, 246, 246, 656, 655,
      246, 246, 246, 361, 361, 654, 653, 652, 361, 361,
      255, 651, 650, 649, 255, 255, 255, 255, 648, 647,
      255, 255, 257, 646, 257, 257, 257, 257, 257, 257,
      257, 257, 257, 257, 257, 257, 257, 257, 261, 261,

      261, 261, 645, 644, 261, 261, 261, 264, 264, 264,
      264, 264, 264, 264, 264, 264, 264, 264, 264, 264,
      264, 264, 264, 267, 267, 267, 267, 643, 267, 267,
      267, 267, 267, 267, 267, 267, 267, 267, 267, 271,
      642, 641, 271, 271, 271, 271, 271, 271, 271, 640,
      271, 271, 271, 271, 271, 274, 639, 274, 274, 638,
      274, 274, 274, 637, 636, 274, 274, 635, 622, 621,
      274, 279, 279, 279, 279, 620, 619, 279, 279, 279,
      284, 618, 284, 284, 284, 284, 284, 284, 284, 284,
      284, 284, 284, 284, 284, 284, 288, 288, 560, 288,

      288, 614, 613, 612, 288, 288, 315, 611, 315, 315,
      315, 315, 315, 315, 315, 315, 315, 315, 315, 315,
      315, 315, 319, 610, 319, 319, 319, 319, 319, 319,
      319, 319, 319, 319, 319, 319, 319, 319, 320, 609,
      320, 320, 320, 320, 320, 320, 320, 320, 320, 320,
      320, 320, 320, 320, 415, 415, 415, 415, 415, 415,
      415, 415, 415, 415, 415, 415, 415, 415, 415, 415,
      424, 424, 424, 424, 608, 607, 424, 424, 424, 425,
      425, 425, 425, 606, 605, 425, 425, 425, 330, 330,
      330, 330, 330, 330, 330, 330, 330, 330, 330, 330,

      330, 330, 330, 330, 334, 334, 334, 334, 334, 334,
      334, 334, 334, 334, 334, 334, 334, 334, 334, 334,
      338, 604, 338, 338, 338, 338, 338, 338, 338, 338,
      338, 603, 338, 338, 338, 338, 433, 433, 602, 601,
      600, 599, 433, 346, 346, 346, 346, 598, 597, 346,
      346, 346, 346, 351, 596, 351, 351, 351, 351, 351,
      351, 351, 351, 351, 351, 351, 351, 351, 351, 615,
      615, 615, 615, 615, 615, 615, 615, 615, 615, 615,
      615, 615, 615, 615, 615, 684, 684, 684, 684, 684,
      684, 684, 684, 684, 684, 684, 684, 684, 684, 684,

      684, 595, 594, 593, 592, 589, 588, 587, 586, 585,
      584, 571, 570, 569, 568, 565, 564, 563, 562, 561,
      560, 559, 558, 557, 556, 555, 554, 551, 550, 549,
      548, 547, 546, 545, 544, 543, 542, 541, 540, 539,
      538, 537, 536, 535, 531, 530, 529, 528, 527, 526,
      525, 524, 523, 510, 509, 508, 507, 506, 503, 499,
      498, 497, 496, 492, 491, 490, 489, 488, 484, 483,
      482, 479, 478, 477, 476, 475, 474, 473, 472, 471,
      470, 469, 468, 467, 466, 465, 464, 463, 462, 461,
      460, 459, 458, 457, 456, 455, 454, 453, 452, 451,

      439, 437, 436, 435, 434, 347, 426, 423, 422, 421,
      322, 414, 316, 408, 407, 406, 401, 400, 399, 398,
      397, 396, 395, 394, 391, 390, 389, 386, 385, 382,
      379, 378, 285, 282, 377, 376, 278, 373, 372, 243,
      356, 355, 235, 231, 352, 350, 349, 348, 218, 347,
      337, 206, 333, 202, 318, 186, 182, 316, 314, 313,
      312, 311, 310, 309, 305, 299, 298, 295, 294, 291,
      287, 286, 285, 283, 282, 281, 280, 260, 278, 277,
      272, 270, 263, 262, 260, 256, 250, 253, 250, 249,
      247, 245, 244, 243, 241, 240, 239, 237, 235, 228,

      231, 228, 226, 218, 208, 202, 199, 186, 182, 768,
       94, 94, 85, 77, 77, 39, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768
    } ;

static const short int yy_chk[2775] =
    { 0,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,

        2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 2, 2, 2, 2, 2, 3, 3, 3, 3,
      765, 3, 5, 5, 3, 3, 3, 27, 27, 3,
        6, 6, 6, 28, 28, 3, 6, 11, 11, 11,
        3, 3, 12, 12, 12, 48, 17, 17, 66, 29,
       29, 60, 60, 18, 18, 310, 17, 29, 310, 17,
       17, 17, 17, 18, 61, 61, 18, 18, 18, 18,
        3, 3, 3, 4, 4, 4, 4, 109, 4, 4,
       21, 4, 4, 4, 511, 48, 4, 19, 19, 19,
       22, 109, 4, 20, 20, 20, 66, 4, 4, 141,

        4, 17, 61, 21, 21, 141, 21, 37, 18, 37,
       75, 19, 75, 22, 22, 511, 22, 20, 30, 30,
       37, 37, 37, 37, 128, 128, 30, 4, 4, 4,
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 9, 9,
        9, 9, 9, 9, 9, 9, 9, 9, 13, 13,
       13, 13, 13, 13, 13, 13, 13, 13, 13, 13,

       13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
       13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
       13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
       13, 13, 13, 13, 13, 13, 13, 13, 13, 13,
       13, 13, 13, 13, 13, 13, 23, 23, 163, 24,
       24, 38, 764, 38, 41, 41, 41, 23, 130, 130,
       24, 45, 45, 45, 38, 38, 38, 38, 163, 23,
       23, 23, 24, 24, 24, 25, 25, 25, 25, 25,
       25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
       25, 25, 25, 25, 25, 25, 25, 25, 25, 25,

       25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
       25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
       25, 25, 25, 25, 25, 25, 25, 25, 25, 25,
       25, 25, 25, 31, 31, 31, 32, 32, 32, 57,
       57, 57, 62, 62, 62, 62, 99, 99, 99, 99,
      131, 131, 133, 133, 167, 198, 198, 31, 167, 763,
       32, 33, 33, 33, 33, 33, 33, 33, 33, 33,
       33, 33, 33, 33, 33, 33, 33, 33, 33, 33,
       33, 33, 33, 33, 33, 33, 33, 33, 33, 33,
       33, 33, 33, 33, 33, 33, 33, 33, 33, 33,

       33, 33, 33, 33, 33, 33, 33, 33, 33, 33,
       33, 33, 33, 33, 33, 33, 33, 33, 33, 35,
       35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
       35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
       35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
       35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
       35, 35, 35, 35, 35, 35, 35, 35, 35, 35,
       35, 35, 35, 35, 35, 35, 35, 49, 53, 53,
       53, 121, 105, 105, 53, 158, 108, 108, 115, 115,
      160, 158, 63, 63, 63, 291, 168, 275, 63, 121,

       49, 188, 49, 275, 49, 63, 168, 205, 205, 160,
       49, 63, 291, 49, 49, 49, 405, 49, 49, 63,
      105, 170, 405, 49, 108, 49, 115, 180, 180, 180,
      180, 170, 762, 53, 170, 181, 181, 181, 185, 185,
      185, 188, 192, 192, 192, 209, 209, 63, 193, 193,
      193, 294, 194, 194, 194, 294, 192, 192, 192, 192,
      211, 211, 193, 193, 193, 193, 194, 194, 194, 194,
      195, 195, 195, 201, 201, 201, 210, 213, 213, 201,
      289, 257, 210, 210, 195, 195, 195, 195, 192, 217,
      217, 217, 264, 264, 289, 217, 194, 362, 211, 257,

      266, 266, 217, 248, 248, 248, 248, 761, 217, 267,
      267, 269, 269, 195, 298, 309, 217, 314, 298, 362,
      314, 321, 321, 321, 309, 330, 330, 760, 201, 314,
      314, 317, 317, 317, 317, 321, 321, 321, 321, 708,
      314, 332, 332, 708, 217, 241, 241, 241, 241, 241,
      241, 241, 241, 241, 241, 241, 241, 241, 241, 241,
      241, 241, 241, 241, 241, 241, 241, 241, 241, 241,
      241, 241, 241, 241, 241, 241, 241, 241, 241, 241,
      241, 241, 241, 241, 241, 241, 241, 241, 241, 241,
      241, 241, 241, 241, 241, 241, 241, 241, 241, 241,

      241, 241, 241, 250, 250, 250, 250, 334, 334, 250,
      336, 336, 338, 338, 250, 344, 344, 757, 250, 415,
      415, 250, 756, 250, 418, 418, 250, 278, 278, 755,
      278, 278, 278, 278, 278, 278, 278, 278, 278, 278,
      278, 278, 278, 278, 278, 278, 278, 278, 278, 278,
      278, 278, 278, 278, 278, 278, 278, 278, 278, 278,
      278, 278, 278, 278, 278, 278, 278, 278, 278, 278,
      278, 278, 278, 278, 278, 278, 278, 278, 278, 278,
      278, 278, 278, 278, 278, 324, 324, 324, 339, 363,
      364, 340, 340, 365, 339, 339, 342, 342, 366, 324,

      324, 324, 324, 340, 371, 409, 342, 342, 409, 409,
      441, 363, 365, 444, 364, 420, 420, 420, 371, 485,
      754, 441, 494, 494, 444, 485, 366, 504, 504, 340,
      341, 341, 367, 341, 341, 341, 341, 341, 341, 341,
      341, 341, 341, 341, 341, 341, 341, 341, 341, 341,
      341, 341, 341, 341, 341, 341, 341, 367, 341, 341,
      341, 341, 341, 341, 341, 341, 341, 341, 341, 341,
      341, 341, 341, 341, 341, 341, 341, 341, 341, 341,
      341, 341, 341, 341, 341, 341, 341, 341, 343, 343,
      343, 343, 752, 369, 505, 505, 343, 750, 343, 343,

      495, 495, 495, 343, 343, 343, 343, 343, 343, 360,
      360, 368, 360, 360, 360, 360, 360, 360, 360, 369,
      360, 360, 360, 360, 360, 360, 360, 360, 360, 360,
      360, 360, 370, 442, 360, 360, 360, 360, 443, 368,
      428, 428, 368, 431, 431, 416, 416, 416, 561, 561,
      428, 428, 749, 431, 431, 443, 519, 445, 370, 416,
      416, 416, 416, 442, 360, 360, 360, 375, 375, 519,
      375, 375, 375, 375, 375, 375, 375, 440, 375, 375,
      375, 375, 375, 375, 375, 375, 375, 375, 375, 375,
      445, 447, 375, 375, 375, 375, 419, 419, 419, 446,

      450, 440, 449, 440, 520, 448, 503, 503, 503, 512,
      419, 419, 419, 419, 517, 447, 448, 520, 446, 450,
      501, 501, 375, 375, 375, 427, 427, 512, 449, 517,
      501, 501, 427, 427, 427, 427, 427, 427, 427, 427,
      427, 427, 427, 427, 427, 427, 427, 427, 427, 427,
      427, 427, 427, 427, 427, 427, 427, 429, 429, 429,
      429, 462, 514, 513, 518, 429, 515, 566, 566, 521,
      567, 567, 429, 429, 429, 429, 429, 429, 432, 432,
      432, 432, 516, 462, 521, 515, 432, 513, 518, 462,
      514, 574, 522, 432, 432, 432, 432, 432, 432, 502,

      502, 502, 502, 532, 565, 565, 565, 502, 516, 522,
      572, 573, 574, 532, 502, 502, 502, 502, 502, 502,
      575, 576, 573, 577, 578, 579, 580, 583, 581, 582,
      615, 615, 634, 572, 617, 617, 656, 656, 684, 684,
      748, 577, 575, 581, 681, 747, 583, 686, 686, 810,
      810, 576, 578, 745, 744, 579, 580, 582, 743, 742,
      740, 681, 634, 769, 769, 769, 769, 769, 769, 769,
      769, 769, 769, 769, 769, 769, 769, 769, 769, 770,
      770, 770, 770, 770, 770, 770, 770, 770, 770, 770,
      770, 770, 770, 770, 770, 771, 771, 771, 771, 771,

      771, 771, 771, 771, 771, 771, 771, 771, 771, 771,
      771, 772, 772, 772, 772, 772, 772, 772, 772, 772,
      772, 772, 772, 772, 772, 772, 772, 773, 773, 773,
      773, 773, 773, 773, 773, 773, 773, 773, 773, 773,
      773, 773, 773, 774, 774, 774, 774, 774, 774, 774,
      774, 774, 774, 774, 774, 774, 774, 774, 774, 775,
      775, 775, 775, 775, 775, 775, 775, 775, 775, 775,
      775, 775, 775, 775, 775, 776, 776, 776, 776, 776,
      776, 776, 776, 776, 776, 776, 776, 776, 776, 776,
      776, 777, 777, 777, 777, 777, 777, 777, 777, 777,

      777, 777, 777, 777, 777, 777, 777, 778, 778, 778,
      778, 778, 778, 778, 778, 778, 778, 778, 778, 778,
      778, 778, 778, 779, 779, 779, 779, 779, 779, 779,
      779, 779, 779, 779, 779, 779, 779, 779, 779, 780,
      780, 780, 780, 780, 780, 780, 780, 780, 780, 780,
      780, 780, 780, 780, 780, 781, 781, 781, 781, 781,
      781, 781, 781, 781, 781, 781, 781, 781, 781, 781,
      781, 782, 782, 782, 782, 782, 782, 782, 782, 782,
      782, 782, 782, 782, 782, 782, 782, 783, 783, 783,
      783, 739, 738, 783, 783, 783, 784, 784, 784, 784,

      784, 784, 784, 784, 784, 784, 784, 784, 784, 784,
      784, 785, 785, 785, 785, 737, 736, 785, 785, 785,
      786, 735, 786, 786, 786, 786, 786, 786, 786, 786,
      786, 786, 786, 786, 786, 786, 787, 734, 787, 787,
      787, 787, 787, 787, 787, 787, 787, 787, 787, 787,
      787, 787, 788, 788, 788, 733, 732, 788, 788, 788,
      789, 731, 789, 789, 789, 789, 789, 789, 789, 789,
      789, 789, 789, 789, 789, 789, 790, 729, 790, 790,
      790, 790, 790, 790, 790, 790, 790, 790, 790, 790,
      790, 790, 791, 727, 791, 791, 791, 791, 791, 791,

      791, 791, 791, 791, 791, 791, 791, 791, 792, 792,
      792, 792, 792, 792, 792, 792, 792, 792, 792, 792,
      792, 792, 792, 792, 793, 726, 793, 793, 725, 793,
      793, 793, 724, 723, 793, 793, 722, 721, 720, 793,
      794, 794, 794, 794, 719, 718, 794, 794, 794, 795,
      717, 795, 795, 795, 795, 795, 795, 795, 795, 795,
      795, 795, 795, 795, 795, 796, 796, 796, 796, 715,
      714, 796, 796, 796, 797, 713, 797, 797, 797, 797,
      797, 797, 797, 797, 797, 797, 797, 797, 797, 797,
      798, 712, 798, 798, 798, 798, 798, 798, 798, 798,

      798, 710, 798, 798, 798, 798, 799, 709, 707, 706,
      799, 799, 799, 799, 705, 704, 799, 799, 800, 703,
      800, 800, 800, 800, 800, 800, 800, 800, 800, 800,
      800, 800, 800, 800, 801, 801, 801, 801, 702, 701,
      801, 801, 801, 802, 802, 802, 802, 802, 802, 802,
      802, 802, 802, 802, 802, 802, 802, 802, 802, 803,
      803, 803, 803, 700, 803, 803, 803, 803, 803, 803,
      803, 803, 803, 803, 803, 804, 699, 698, 804, 804,
      804, 804, 804, 804, 804, 682, 804, 804, 804, 804,
      804, 805, 680, 805, 805, 805, 805, 805, 805, 805,

      805, 805, 805, 805, 805, 805, 805, 806, 679, 806,
      806, 678, 806, 806, 806, 677, 675, 806, 806, 674,
      672, 671, 806, 807, 807, 807, 807, 670, 669, 807,
      807, 807, 808, 668, 808, 808, 808, 808, 808, 808,
      808, 808, 808, 808, 808, 808, 808, 808, 809, 809,
      667, 809, 809, 666, 665, 664, 809, 809, 811, 663,
      811, 811, 811, 811, 811, 811, 811, 811, 811, 811,
      811, 811, 811, 811, 812, 662, 812, 812, 812, 812,
      812, 812, 812, 812, 812, 812, 812, 812, 812, 812,
      813, 661, 813, 813, 813, 813, 813, 813, 813, 813,

      813, 813, 813, 813, 813, 813, 814, 814, 660, 659,
      814, 814, 814, 815, 815, 658, 655, 815, 815, 815,
      816, 816, 816, 816, 816, 816, 816, 816, 816, 816,
      816, 816, 816, 816, 816, 816, 817, 817, 817, 817,
      817, 817, 817, 817, 817, 817, 817, 817, 817, 817,
      817, 817, 818, 653, 818, 818, 818, 818, 818, 818,
      818, 818, 818, 652, 818, 818, 818, 818, 819, 651,
      819, 819, 819, 819, 819, 819, 819, 819, 819, 819,
      819, 819, 819, 819, 820, 820, 650, 646, 644, 643,
      820, 821, 821, 821, 821, 642, 641, 821, 821, 821,

      821, 822, 639, 822, 822, 822, 822, 822, 822, 822,
      822, 822, 822, 822, 822, 822, 822, 823, 637, 823,
      823, 823, 823, 823, 823, 823, 823, 823, 823, 823,
      823, 823, 823, 824, 636, 824, 824, 824, 824, 824,
      824, 824, 824, 824, 824, 824, 824, 824, 824, 825,
      635, 825, 825, 825, 825, 825, 825, 825, 825, 825,
      825, 825, 825, 825, 825, 826, 633, 826, 826, 826,
      826, 826, 826, 826, 826, 826, 826, 826, 826, 826,
      826, 827, 632, 827, 827, 827, 827, 827, 827, 827,
      827, 827, 827, 827, 827, 827, 827, 828, 828, 828,

      828, 828, 828, 828, 828, 828, 828, 828, 828, 828,
      828, 828, 828, 829, 631, 829, 829, 630, 829, 829,
      829, 629, 628, 829, 829, 627, 626, 625, 829, 830,
      830, 830, 830, 624, 623, 830, 830, 830, 831, 621,
      831, 831, 831, 831, 831, 831, 831, 831, 831, 831,
      831, 831, 831, 831, 832, 832, 832, 832, 619, 612,
      832, 832, 832, 833, 833, 611, 610, 609, 833, 833,
      834, 608, 607, 606, 834, 834, 834, 834, 604, 601,
      834, 834, 835, 600, 835, 835, 835, 835, 835, 835,
      835, 835, 835, 835, 835, 835, 835, 835, 836, 836,

      836, 836, 599, 598, 836, 836, 836, 837, 837, 837,
      837, 837, 837, 837, 837, 837, 837, 837, 837, 837,
      837, 837, 837, 838, 838, 838, 838, 597, 838, 838,
      838, 838, 838, 838, 838, 838, 838, 838, 838, 839,
      596, 595, 839, 839, 839, 839, 839, 839, 839, 594,
      839, 839, 839, 839, 839, 840, 593, 840, 840, 592,
      840, 840, 840, 591, 590, 840, 840, 588, 569, 568,
      840, 841, 841, 841, 841, 564, 563, 841, 841, 841,
      842, 562, 842, 842, 842, 842, 842, 842, 842, 842,
      842, 842, 842, 842, 842, 842, 843, 843, 560, 843,

      843, 559, 558, 557, 843, 843, 844, 556, 844, 844,
      844, 844, 844, 844, 844, 844, 844, 844, 844, 844,
      844, 844, 845, 555, 845, 845, 845, 845, 845, 845,
      845, 845, 845, 845, 845, 845, 845, 845, 846, 554,
      846, 846, 846, 846, 846, 846, 846, 846, 846, 846,
      846, 846, 846, 846, 847, 847, 847, 847, 847, 847,
      847, 847, 847, 847, 847, 847, 847, 847, 847, 847,
      848, 848, 848, 848, 553, 552, 848, 848, 848, 849,
      849, 849, 849, 551, 549, 849, 849, 849, 850, 850,
      850, 850, 850, 850, 850, 850, 850, 850, 850, 850,

      850, 850, 850, 850, 851, 851, 851, 851, 851, 851,
      851, 851, 851, 851, 851, 851, 851, 851, 851, 851,
      852, 548, 852, 852, 852, 852, 852, 852, 852, 852,
      852, 546, 852, 852, 852, 852, 853, 853, 545, 544,
      543, 542, 853, 854, 854, 854, 854, 541, 540, 854,
      854, 854, 854, 855, 539, 855, 855, 855, 855, 855,
      855, 855, 855, 855, 855, 855, 855, 855, 855, 856,
      856, 856, 856, 856, 856, 856, 856, 856, 856, 856,
      856, 856, 856, 856, 856, 857, 857, 857, 857, 857,
      857, 857, 857, 857, 857, 857, 857, 857, 857, 857,

      857, 538, 536, 534, 533, 530, 528, 526, 525, 524,
      523, 509, 508, 507, 506, 500, 499, 498, 497, 496,
      492, 491, 490, 489, 488, 487, 486, 483, 482, 481,
      480, 479, 478, 476, 475, 474, 473, 472, 471, 469,
      468, 467, 464, 463, 461, 460, 459, 458, 457, 454,
      453, 452, 451, 439, 437, 436, 435, 434, 430, 426,
      423, 422, 421, 414, 413, 412, 411, 410, 408, 407,
      406, 404, 403, 402, 401, 400, 399, 398, 397, 396,
      395, 394, 393, 392, 391, 390, 388, 387, 386, 384,
      383, 382, 381, 380, 379, 378, 377, 376, 373, 372,

      361, 356, 355, 352, 350, 346, 337, 327, 326, 325,
      323, 318, 315, 313, 312, 311, 308, 307, 306, 305,
      303, 301, 300, 299, 297, 296, 295, 293, 292, 290,
      287, 286, 284, 282, 281, 280, 276, 263, 262, 243,
      240, 239, 234, 231, 226, 222, 221, 220, 219, 216,
      208, 207, 204, 203, 189, 187, 183, 179, 176, 175,
      174, 173, 172, 171, 169, 166, 165, 162, 161, 159,
      156, 155, 154, 153, 151, 149, 148, 146, 144, 143,
      137, 134, 125, 124, 122, 119, 114, 112, 107, 103,
       97, 92, 89, 87, 85, 84, 83, 80, 76, 74,

       73, 71, 67, 65, 59, 55, 50, 47, 43, 39,
       16, 15, 10, 8, 7, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768, 768, 768, 768, 768, 768, 768,
      768, 768, 768, 768
    } ;

static yy_state_type yy_last_accepting_state;
static char *yy_last_accepting_cpos;
# 11957 "flex_single_original.c"
char *yytext;
# 12051 "flex_single_original.c"
extern int yywrap ( void );




static void yyunput ( int c, char *buf_ptr );
# 12071 "flex_single_original.c"
static int input ( void );




static int yy_start_stack_ptr = 0;
static int yy_start_stack_depth = 0;
static int *yy_start_stack = 0;

static void yy_push_state ( int new_state );


static void yy_pop_state ( void );
# 12189 "flex_single_original.c"
int flexscan()
 {
 register yy_state_type yy_current_state;
 register char *yy_cp, *yy_bp;
 register int yy_act;


 static int bracelevel, didadef, indented_code;
 static int doing_rule_action = 0;
 static int option_sense;

 int doing_codeblock = 0;
 int i;
 unsigned char nmdef[2048], myesc();



 if ( yy_init )
  {
  yy_init = 0;





  if ( ! yy_start )
   yy_start = 1;

  if ( ! yyin )
   yyin = 
# 12218 "flex_single_original.c" 3 4
         stdin
# 12218 "flex_single_original.c"
              ;

  if ( ! yyout )
   yyout = 
# 12221 "flex_single_original.c" 3 4
          stdout
# 12221 "flex_single_original.c"
                ;

  if ( ! yy_current_buffer )
   yy_current_buffer =
    yy_create_buffer( yyin, 16384 );

  yy_load_buffer_state();
  }

 while ( 1 )
  {
  yy_cp = yy_c_buf_p;


  *yy_cp = yy_hold_char;




  yy_bp = yy_cp;

  yy_current_state = yy_start;
  yy_current_state += (yy_current_buffer->yy_at_bol);
yy_match:
  do
   {
   register YY_CHAR yy_c = yy_ec[((unsigned int) (unsigned char) *yy_cp)];
   if ( yy_accept[yy_current_state] )
    {
    yy_last_accepting_state = yy_current_state;
    yy_last_accepting_cpos = yy_cp;
    }
   while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
    {
    yy_current_state = (int) yy_def[yy_current_state];
    if ( yy_current_state >= 769 )
     yy_c = yy_meta[(unsigned int) yy_c];
    }
   yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
   ++yy_cp;
   }
  while ( yy_base[yy_current_state] != 2716 );

yy_find_action:
  yy_act = yy_accept[yy_current_state];
  if ( yy_act == 0 )
   {
   yy_cp = yy_last_accepting_cpos;
   yy_current_state = yy_last_accepting_state;
   yy_act = yy_accept[yy_current_state];
   }

  yytext = yy_bp; yyleng = (int) (yy_cp - yy_bp); yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;


do_action:


  switch ( yy_act )
 {
   case 0:

   *yy_cp = yy_hold_char;
   yy_cp = yy_last_accepting_cpos;
   yy_current_state = yy_last_accepting_state;
   goto yy_find_action;


case 1:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
indented_code = 1; yy_start = 1 + 2 *(4);
 break;
case 2:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext ); yy_push_state( 14 );
 break;
case 3:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_push_state( 18 );
 break;
case 4:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return 260;
 break;
case 5:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return 261;
 break;
case 6:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   ++linenum;
   line_directive_out( (FILE *) 0, 1 );
   indented_code = 0;
   yy_start = 1 + 2 *(4);
   }
 break;
case 7:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');

 break;
case 8:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   sectnum = 2;
   bracelevel = 0;
   mark_defs1();
   line_directive_out( (FILE *) 0, 1 );
   yy_start = 1 + 2 *(2);
   return 259;
   }
 break;
case 9:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yytext_is_array = 0; ++linenum;
 break;
case 10:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yytext_is_array = 1; ++linenum;
 break;
case 11:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(17); return 265;
 break;
case 12:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
++linenum;
 break;
case 13:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
++linenum;
 break;
case 14:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
synerr( ("unrecognized '%' directive") );
 break;
case 15:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   strcpy( nmstr, yytext );
   didadef = 0;
   yy_start = 1 + 2 *(5);
   }
 break;
case 16:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
strcpy( nmstr, yytext ); return 262;;
 break;
case 17:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
++linenum;
 break;
case 18:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext ); ++linenum;
 break;


case 19:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext ); yy_pop_state();
 break;
case 20:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext );
 break;
case 21:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext );
 break;
case 22:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
++linenum; add_action( yytext );
 break;


case 23:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_pop_state();
 break;
case 24:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
linenum = myctoi( yytext );
 break;
case 25:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   flex_free( (void *) infilename );
   infilename = copy_string( yytext + 1 );
   infilename[strlen( infilename ) - 1] = '\0';
   }
 break;
case 26:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');

 break;


case 27:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
++linenum; yy_start = 1 + 2 *(0);
 break;
case 28:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext );
 break;
case 29:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   ++linenum;
   add_action( yytext );
   if ( indented_code )
    yy_start = 1 + 2 *(0);
   }
 break;


case 30:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');

 break;
case 31:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   strcpy( (char *) nmdef, yytext );


   for ( i = strlen( (char *) nmdef ) - 1;
         i >= 0 && (nmdef[i] == ' ' || nmdef[i] == '\t');
         --i )
    ;

   nmdef[i + 1] = '\0';

   ndinstal( nmstr, nmdef );
   didadef = 1;
   }
 break;
case 32:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   if ( ! didadef )
    synerr( ("incomplete name definition") );
   yy_start = 1 + 2 *(0);
   ++linenum;
   }
 break;


case 33:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
++linenum; yy_start = 1 + 2 *(0);
 break;
case 34:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
option_sense = 1;
 break;
case 35:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return '=';
 break;
case 36:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
option_sense = ! option_sense;
 break;
case 37:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
csize = option_sense ? 128 : 256;
 break;
case 38:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
csize = option_sense ? 256 : 128;
 break;
case 39:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
long_align = option_sense;
 break;
case 40:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   action_define( "YY_ALWAYS_INTERACTIVE", option_sense );
   }
 break;
case 41:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yytext_is_array = option_sense;
 break;
case 42:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
backing_up_report = option_sense;
 break;
case 43:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
interactive = ! option_sense;
 break;
case 44:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
C_plus_plus = option_sense;
 break;
case 45:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
caseins = ! option_sense;
 break;
case 46:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
caseins = option_sense;
 break;
case 47:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
ddebug = option_sense;
 break;
case 48:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
spprdflt = ! option_sense;
 break;
case 49:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
useecs = option_sense;
 break;
case 50:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   useecs = usemecs = 0;
   use_read = fullspd = 1;
   }
 break;
case 51:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   useecs = usemecs = 0;
   use_read = fulltbl = 1;
   }
 break;
case 52:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{ if ( ! option_sense ) action_define( "YY_NO_INPUT", 1 ); };
 break;
case 53:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
interactive = option_sense;
 break;
case 54:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
lex_compat = option_sense;
 break;
case 55:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   action_define( "YY_MAIN", option_sense );
   do_yywrap = ! option_sense;
   }
 break;
case 56:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
usemecs = option_sense;
 break;
case 57:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   action_define( "YY_NEVER_INTERACTIVE", option_sense );
   }
 break;
case 58:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
performance_report += option_sense ? 1 : -1;
 break;
case 59:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yytext_is_array = ! option_sense;
 break;
case 60:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
use_read = option_sense;
 break;
case 61:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
reject_really_used = option_sense;
 break;
case 62:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
action_define( "YY_STACK_USED", option_sense );
 break;
case 63:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
do_stdinit = option_sense;
 break;
case 64:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
use_stdout = option_sense;
 break;
case 65:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{ if ( ! option_sense ) action_define( "YY_NO_UNPUT", 1 ); };
 break;
case 66:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
printstats = option_sense;
 break;
case 67:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
nowarn = ! option_sense;
 break;
case 68:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
do_yylineno = option_sense;
 break;
case 69:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yymore_really_used = option_sense;
 break;
case 70:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
do_yywrap = option_sense;
 break;
case 71:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{ if ( ! option_sense ) action_define( "YY_NO_PUSH_STATE", 1 ); };
 break;
case 72:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{ if ( ! option_sense ) action_define( "YY_NO_POP_STATE", 1 ); };
 break;
case 73:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{ if ( ! option_sense ) action_define( "YY_NO_TOP_STATE", 1 ); };
 break;
case 74:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{ if ( ! option_sense ) action_define( "YY_NO_SCAN_BUFFER", 1 ); };
 break;
case 75:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{ if ( ! option_sense ) action_define( "YY_NO_SCAN_BYTES", 1 ); };
 break;
case 76:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{ if ( ! option_sense ) action_define( "YY_NO_SCAN_STRING", 1 ); };
 break;
case 77:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return 266;
 break;
case 78:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return 267;
 break;
case 79:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return 268;
 break;
case 80:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   strcpy( nmstr, yytext + 1 );
   nmstr[strlen( nmstr ) - 1] = '\0';
   return 262;
   }
 break;
case 81:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   format_synerr( ("unrecognized %%option: %s"),
    yytext );
   yy_start = 1 + 2 *(13);
   }
 break;

case 82:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
++linenum; yy_start = 1 + 2 *(0);
 break;

case 83:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
++bracelevel; do { *yy_cp = yy_hold_char; yy_c_buf_p = yy_cp = yy_bp + 2 - 0; yytext = yy_bp; yyleng = (int) (yy_cp - yy_bp); yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;; } while ( 0 );
 break;
case 84:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
--bracelevel; do { *yy_cp = yy_hold_char; yy_c_buf_p = yy_cp = yy_bp + 2 - 0; yytext = yy_bp; yyleng = (int) (yy_cp - yy_bp); yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;; } while ( 0 );
 break;
case 85:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext );
 break;
case 86:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   if ( bracelevel <= 0 )
    {
    do { *yy_cp = yy_hold_char; yy_c_buf_p = yy_cp = yy_bp + 0 - 0; yytext = yy_bp; yyleng = (int) (yy_cp - yy_bp); yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;; } while ( 0 );
    { if ( ! yy_current_buffer ) yy_current_buffer = yy_create_buffer( yyin, 16384 ); yy_current_buffer->yy_at_bol = 1; };
    mark_prolog();
    yy_start = 1 + 2 *(1);
    }
   else
    add_action( yytext );
   }
 break;
case 87:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext );
 break;
case 88:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
++linenum; add_action( yytext );
 break;
case (166 + 2 + 1):
{
   mark_prolog();
   sectnum = 0;
   return 0;
   }
 break;


case 89:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
++linenum;
 break;
case 90:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   indented_code = 0;
   doing_codeblock = 1;
   bracelevel = 1;
   yy_start = 1 + 2 *(16);
   }
 break;
case 91:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(6); return '<';
 break;
case 92:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return '^';
 break;
case 93:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(9); return '"';
 break;
case 94:
*yy_cp = yy_hold_char;
yy_c_buf_p = yy_cp = yy_bp + 1;
yytext = yy_bp; yyleng = (int) (yy_cp - yy_bp); yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(8); return '{';
 break;
case 95:
*yy_cp = yy_hold_char;
yy_c_buf_p = yy_cp = yy_bp + 1;
yytext = yy_bp; yyleng = (int) (yy_cp - yy_bp); yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return '$';
 break;
case 96:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   bracelevel = 1;
   yy_start = 1 + 2 *(16);

   if ( in_rule )
    {
    doing_rule_action = 1;
    in_rule = 0;
    return '\n';
    }
   }
 break;
case 97:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
continued_action = 1; ++linenum; return '\n';
 break;
case 98:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   do { *yy_cp = yy_hold_char; yy_c_buf_p = yy_cp = yy_bp + yyleng - 2 - 0; yytext = yy_bp; yyleng = (int) (yy_cp - yy_bp); yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;; } while ( 0 );
   bracelevel = 0;
   continued_action = 0;
   yy_start = 1 + 2 *(12);
   }
 break;
case 99:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');

 break;
case 100:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{




   bracelevel = 0;
   continued_action = 0;
   yy_start = 1 + 2 *(12);

   if ( in_rule )
    {
    doing_rule_action = 1;
    in_rule = 0;
    return '\n';
    }
   }
 break;
case 101:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   bracelevel = 0;
   continued_action = 0;
   yy_start = 1 + 2 *(12);
   yyunput( '\n', yytext );

   if ( in_rule )
    {
    doing_rule_action = 1;
    in_rule = 0;
    return '\n';
    }
   }
 break;
case 102:
case 103:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return 264;
 break;
case 104:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   sectnum = 3;
   yy_start = 1 + 2 *(3);
   return 0;
   }
 break;
case 105:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   int cclval;

   strcpy( nmstr, yytext );




   if ( (cclval = ccllookup( (unsigned char *) nmstr )) != 0 )
    {
    if ( input() != ']' )
     synerr( ("bad character class") );

    yylval = cclval;
    ++cclreuse;
    return 263;
    }
   else
    {



    cclinstal( (unsigned char *) nmstr, lastccl + 1 );




    do { *yy_cp = yy_hold_char; yy_c_buf_p = yy_cp = yy_bp + 1 - 0; yytext = yy_bp; yyleng = (int) (yy_cp - yy_bp); yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;; } while ( 0 );

    yy_start = 1 + 2 *(10);
    return '[';
    }
   }
 break;
case 106:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   register unsigned char *nmdefptr;
   unsigned char *ndlookup();

   strcpy( nmstr, yytext + 1 );
   nmstr[yyleng - 2] = '\0';

   if ( (nmdefptr = ndlookup( nmstr )) == 0 )
    format_synerr(
     ("undefined definition {%s}"),
      nmstr );

   else
    {
    int len = strlen( (char *) nmdefptr );

    if ( lex_compat || nmdefptr[0] == '^' ||
         (len > 0 && nmdefptr[len - 1] == '$') )
     {
     for ( i = strlen( (char *) nmdefptr ) - 1; i >= 0; --i ) yyunput( ((char *) nmdefptr)[i], yytext );

     if ( nmdefptr[0] == '^' )
      yy_start = 1 + 2 *(7);
     }

    else
     {
     yyunput( ')', yytext );
     for ( i = strlen( (char *) nmdefptr ) - 1; i >= 0; --i ) yyunput( ((char *) nmdefptr)[i], yytext );
     yyunput( '(', yytext );
     }
    }
   }
 break;
case 107:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return (unsigned char) yytext[0];
 break;
case 108:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yylval = (unsigned char) yytext[0]; return 257;;
 break;


case 109:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return (unsigned char) yytext[0];
 break;
case 110:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(1); return '>';
 break;
case 111:
*yy_cp = yy_hold_char;
yy_c_buf_p = yy_cp = yy_bp + 1;
yytext = yy_bp; yyleng = (int) (yy_cp - yy_bp); yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(7); return '>';
 break;
case 112:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
strcpy( nmstr, yytext ); return 262;;
 break;
case 113:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   format_synerr( ("bad <start condition>: %s"),
    yytext );
   }
 break;

case 114:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(1); return '^';
 break;

case 115:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yylval = (unsigned char) yytext[0]; return 257;;
 break;
case 116:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(1); return '"';
 break;
case 117:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   synerr( ("missing quote") );
   yy_start = 1 + 2 *(1);
   ++linenum;
   return '"';
   }
 break;


case 118:
*yy_cp = yy_hold_char;
yy_c_buf_p = yy_cp = yy_bp + 1;
yytext = yy_bp; yyleng = (int) (yy_cp - yy_bp); yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); return '^';
 break;
case 119:
*yy_cp = yy_hold_char;
yy_c_buf_p = yy_cp = yy_bp + 1;
yytext = yy_bp; yyleng = (int) (yy_cp - yy_bp); yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return '^';
 break;
case 120:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); yylval = (unsigned char) yytext[0]; return 257;;
 break;


case 121:
*yy_cp = yy_hold_char;
yy_c_buf_p = yy_cp = yy_bp + 1;
yytext = yy_bp; yyleng = (int) (yy_cp - yy_bp); yy_hold_char = *yy_cp; *yy_cp = '\0'; yy_c_buf_p = yy_cp;;
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return '-';
 break;
case 122:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yylval = (unsigned char) yytext[0]; return 257;;
 break;
case 123:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(1); return ']';
 break;
case 124:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   synerr( ("bad character class") );
   yy_start = 1 + 2 *(1);
   return ']';
   }
 break;


case 125:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); return 269;
 break;
case 126:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); return 270;
 break;
case 127:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); return 271;
 break;
case 128:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); return 272;
 break;
case 129:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); return 273;
 break;
case 130:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); return 274;
 break;
case 131:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); return 275;
 break;
case 132:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); return 276;
 break;
case 133:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); return 277;
 break;
case 134:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); return 278;
 break;
case 135:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); return 279;
 break;
case 136:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(11); return 280;
 break;
case 137:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   format_synerr(
    ("bad character class expression: %s"),
     yytext );
   yy_start = 1 + 2 *(11); return 269;
   }
 break;


case 138:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   yylval = myctoi( yytext );
   return 258;
   }
 break;
case 139:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
return ',';
 break;
case 140:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_start = 1 + 2 *(1); return '}';
 break;
case 141:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   synerr( ("bad character inside {}'s") );
   yy_start = 1 + 2 *(1);
   return '}';
   }
 break;
case 142:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   synerr( ("missing }") );
   yy_start = 1 + 2 *(1);
   ++linenum;
   return '}';
   }
 break;


case 143:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
bracelevel = 0;
 break;
case 144:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext ); yy_push_state( 14 );
 break;

case 145:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   add_action( yytext );
   if ( all_upper( yytext ) ) reject = 1;;
   }
 break;
case 146:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   add_action( yytext );
   if ( all_lower( yytext ) ) yymore_used = 1;;
   }
 break;

case 147:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext );
 break;
case 148:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   ++linenum;
   add_action( yytext );
   if ( bracelevel == 0 ||
        (doing_codeblock && indented_code) )
    {
    if ( doing_rule_action )
     add_action( "\tYY_BREAK\n" );

    doing_rule_action = doing_codeblock = 0;
    yy_start = 1 + 2 *(1);
    }
   }
 break;



case 149:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext ); ++bracelevel;
 break;
case 150:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext ); --bracelevel;
 break;
case 151:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext );
 break;
case 152:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext );
 break;
case 153:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext );
 break;
case 154:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext ); yy_start = 1 + 2 *(15);
 break;
case 155:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   ++linenum;
   add_action( yytext );
   if ( bracelevel == 0 )
    {
    if ( doing_rule_action )
     add_action( "\tYY_BREAK\n" );

    doing_rule_action = 0;
    yy_start = 1 + 2 *(1);
    }
   }
 break;
case 156:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext );
 break;


case 157:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext );
 break;
case 158:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext );
 break;
case 159:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
++linenum; add_action( yytext );
 break;
case 160:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext ); yy_start = 1 + 2 *(12);
 break;
case 161:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
add_action( yytext );
 break;

case (166 + 14 + 1):
case (166 + 12 + 1):
case (166 + 15 + 1):
{
   synerr( ("EOF encountered inside an action") );
   return 0;
   }
 break;
case 162:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
{
   yylval = myesc( (unsigned char *) yytext );

   if ( ((yy_start - 1) / 2) == 10 )
    yy_start = 1 + 2 *(11);

   return 257;
   }
 break;

case 163:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
(void) fwrite( yytext, yyleng, 1, yyout );
 break;
case (166 + 3 + 1):
sectnum = 0; return 0;
 break;

case 164:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
format_synerr( ("bad character: %s"), yytext );
 break;
case 165:
if ( yyleng > 0 ) yy_current_buffer->yy_at_bol = (yytext[yyleng - 1] == '\n');
yy_fatal_error( "flex scanner jammed" );
 break;
case (166 + 0 + 1):
case (166 + 1 + 1):
case (166 + 4 + 1):
case (166 + 5 + 1):
case (166 + 6 + 1):
case (166 + 7 + 1):
case (166 + 8 + 1):
case (166 + 9 + 1):
case (166 + 10 + 1):
case (166 + 11 + 1):
case (166 + 13 + 1):
case (166 + 16 + 1):
case (166 + 17 + 1):
case (166 + 18 + 1):
 return 0;

 case 166:
  {

  int yy_amount_of_matched_text = (int) (yy_cp - yytext) - 1;


  *yy_cp = yy_hold_char;
 

  if ( yy_current_buffer->yy_buffer_status == 0 )
   {
# 13310 "flex_single_original.c"
   yy_n_chars = yy_current_buffer->yy_n_chars;
   yy_current_buffer->yy_input_file = yyin;
   yy_current_buffer->yy_buffer_status = 1;
   }
# 13322 "flex_single_original.c"
  if ( yy_c_buf_p <= &yy_current_buffer->yy_ch_buf[yy_n_chars] )
   {
   yy_state_type yy_next_state;

   yy_c_buf_p = yytext + yy_amount_of_matched_text;

   yy_current_state = yy_get_previous_state();
# 13339 "flex_single_original.c"
   yy_next_state = yy_try_NUL_trans( yy_current_state );

   yy_bp = yytext + 0;

   if ( yy_next_state )
    {

    yy_cp = ++yy_c_buf_p;
    yy_current_state = yy_next_state;
    goto yy_match;
    }

   else
    {
    yy_cp = yy_c_buf_p;
    goto yy_find_action;
    }
   }

  else switch ( yy_get_next_buffer() )
   {
   case 1:
    {
    yy_did_buffer_switch_on_eof = 0;

    if ( yywrap() )
     {
# 13375 "flex_single_original.c"
     yy_c_buf_p = yytext + 0;

     yy_act = (166 + ((yy_start - 1) / 2) + 1);
     goto do_action;
     }

    else
     {
     if ( ! yy_did_buffer_switch_on_eof )
      yyrestart( yyin );
     }
    break;
    }

   case 0:
    yy_c_buf_p =
     yytext + yy_amount_of_matched_text;

    yy_current_state = yy_get_previous_state();

    yy_cp = yy_c_buf_p;
    yy_bp = yytext + 0;
    goto yy_match;

   case 2:
    yy_c_buf_p =
    &yy_current_buffer->yy_ch_buf[yy_n_chars];

    yy_current_state = yy_get_previous_state();

    yy_cp = yy_c_buf_p;
    yy_bp = yytext + 0;
    goto yy_find_action;
   }
  break;
  }

 default:
  yy_fatal_error( "fatal flex scanner internal error--no action found" )
                                                         ;
 }
  }
 }
# 13428 "flex_single_original.c"
static int yy_get_next_buffer()
 {
 register char *dest = yy_current_buffer->yy_ch_buf;
 register char *source = yytext;
 register int number_to_move, i;
 int ret_val;

 if ( yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1] )
  yy_fatal_error( "fatal flex scanner internal error--end of buffer missed" )
                                                             ;

 if ( yy_current_buffer->yy_fill_buffer == 0 )
  {
  if ( yy_c_buf_p - yytext - 0 == 1 )
   {



   return 1;
   }

  else
   {



   return 2;
   }
  }




 number_to_move = (int) (yy_c_buf_p - yytext) - 1;

 for ( i = 0; i < number_to_move; ++i )
  *(dest++) = *(source++);

 if ( yy_current_buffer->yy_buffer_status == 2 )



  yy_n_chars = 0;

 else
  {
  int num_to_read =
   yy_current_buffer->yy_buf_size - number_to_move - 1;

  while ( num_to_read <= 0 )
   {






   YY_BUFFER_STATE b = yy_current_buffer;

   int yy_c_buf_p_offset =
    (int) (yy_c_buf_p - b->yy_ch_buf);

   if ( b->yy_is_our_buffer )
    {
    int new_size = b->yy_buf_size * 2;

    if ( new_size <= 0 )
     b->yy_buf_size += b->yy_buf_size / 8;
    else
     b->yy_buf_size *= 2;

    b->yy_ch_buf = (char *)

     yy_flex_realloc( (void *) b->yy_ch_buf,
        b->yy_buf_size + 2 );
    }
   else

    b->yy_ch_buf = 0;

   if ( ! b->yy_ch_buf )
    yy_fatal_error( "fatal error - scanner input buffer overflow" )
                                                   ;

   yy_c_buf_p = &b->yy_ch_buf[yy_c_buf_p_offset];

   num_to_read = yy_current_buffer->yy_buf_size -
      number_to_move - 1;

   }

  if ( num_to_read > 8192 )
   num_to_read = 8192;


  if ( yy_current_buffer->yy_is_interactive ) { int c = '*', n; for ( n = 0; n < num_to_read && (c = 
# 13523 "flex_single_original.c" 3 4
 _IO_getc (
# 13523 "flex_single_original.c"
 yyin
# 13523 "flex_single_original.c" 3 4
 )
# 13523 "flex_single_original.c"
 ) != 
# 13523 "flex_single_original.c" 3 4
 (-1) 
# 13523 "flex_single_original.c"
 && c != '\n'; ++n ) (&yy_current_buffer->yy_ch_buf[number_to_move])[n] = (char) c; if ( c == '\n' ) (&yy_current_buffer->yy_ch_buf[number_to_move])[n++] = (char) c; if ( c == 
# 13523 "flex_single_original.c" 3 4
 (-1) 
# 13523 "flex_single_original.c"
 && ferror( yyin ) ) yy_fatal_error( "input in flex scanner failed" ); yy_n_chars = n; } else if ( ((yy_n_chars = fread( (&yy_current_buffer->yy_ch_buf[number_to_move]), 1, num_to_read, yyin )) == 0) && ferror( yyin ) ) yy_fatal_error( "input in flex scanner failed" );
                            ;
  }

 if ( yy_n_chars == 0 )
  {
  if ( number_to_move == 0 )
   {
   ret_val = 1;
   yyrestart( yyin );
   }

  else
   {
   ret_val = 2;
   yy_current_buffer->yy_buffer_status =
    2;
   }
  }

 else
  ret_val = 0;

 yy_n_chars += number_to_move;
 yy_current_buffer->yy_ch_buf[yy_n_chars] = 0;
 yy_current_buffer->yy_ch_buf[yy_n_chars + 1] = 0;

 yytext = &yy_current_buffer->yy_ch_buf[0];

 return ret_val;
 }




static yy_state_type yy_get_previous_state()
 {
 register yy_state_type yy_current_state;
 register char *yy_cp;

 yy_current_state = yy_start;
 yy_current_state += (yy_current_buffer->yy_at_bol);

 for ( yy_cp = yytext + 0; yy_cp < yy_c_buf_p; ++yy_cp )
  {
  register YY_CHAR yy_c = (*yy_cp ? yy_ec[((unsigned int) (unsigned char) *yy_cp)] : 1);
  if ( yy_accept[yy_current_state] )
   {
   yy_last_accepting_state = yy_current_state;
   yy_last_accepting_cpos = yy_cp;
   }
  while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
   {
   yy_current_state = (int) yy_def[yy_current_state];
   if ( yy_current_state >= 769 )
    yy_c = yy_meta[(unsigned int) yy_c];
   }
  yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
  }

 return yy_current_state;
 }
# 13594 "flex_single_original.c"
static yy_state_type yy_try_NUL_trans( yy_state_type yy_current_state )




 {
 register int yy_is_jam;
 register char *yy_cp = yy_c_buf_p;

 register YY_CHAR yy_c = 1;
 if ( yy_accept[yy_current_state] )
  {
  yy_last_accepting_state = yy_current_state;
  yy_last_accepting_cpos = yy_cp;
  }
 while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
  {
  yy_current_state = (int) yy_def[yy_current_state];
  if ( yy_current_state >= 769 )
   yy_c = yy_meta[(unsigned int) yy_c];
  }
 yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
 yy_is_jam = (yy_current_state == 768);

 return yy_is_jam ? 0 : yy_current_state;
 }




static void yyunput( int c, register char *yy_bp )





 {
 register char *yy_cp = yy_c_buf_p;


 *yy_cp = yy_hold_char;

 if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
  {

  register int number_to_move = yy_n_chars + 2;
  register char *dest = &yy_current_buffer->yy_ch_buf[
     yy_current_buffer->yy_buf_size + 2];
  register char *source =
    &yy_current_buffer->yy_ch_buf[number_to_move];

  while ( source > yy_current_buffer->yy_ch_buf )
   *--dest = *--source;

  yy_cp += (int) (dest - source);
  yy_bp += (int) (dest - source);
  yy_n_chars = yy_current_buffer->yy_buf_size;

  if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
   yy_fatal_error( "flex scanner push-back overflow" );
  }

 *--yy_cp = (char) c;


 yytext = yy_bp;
 yy_hold_char = *yy_cp;
 yy_c_buf_p = yy_cp;
 }






static int input()

 {
 int c;

 *yy_c_buf_p = yy_hold_char;

 if ( *yy_c_buf_p == 0 )
  {




  if ( yy_c_buf_p < &yy_current_buffer->yy_ch_buf[yy_n_chars] )

   *yy_c_buf_p = '\0';

  else
   {



   int offset = yy_c_buf_p;

   ++yy_c_buf_p;

   switch ( yy_get_next_buffer() )
    {
    case 1:
     {
     if ( yywrap() )
      {
      yy_c_buf_p = yytext + offset;





      }

     if ( ! yy_did_buffer_switch_on_eof )
      yyrestart( yyin );



     return input();

     }

    case 0:



     yy_c_buf_p = yytext;

     break;

    case 2:




     yy_fatal_error( "unexpected last match in input()" )
                                         ;

    }
   }
  }

 c = *(unsigned char *) yy_c_buf_p;
 *yy_c_buf_p = '\0';
 yy_hold_char = *++yy_c_buf_p;

 yy_current_buffer->yy_at_bol = (c == '\n');

 return c;
 }



void yyrestart( FILE *input_file )




 {
 if ( ! yy_current_buffer )
  yy_current_buffer = yy_create_buffer( yyin, 16384 );

 yy_init_buffer( yy_current_buffer, input_file );
 yy_load_buffer_state();
 }



void yy_switch_to_buffer( YY_BUFFER_STATE new_buffer )




 {
 if ( yy_current_buffer == new_buffer )
  return;

 if ( yy_current_buffer )
  {

  *yy_c_buf_p = yy_hold_char;
  yy_current_buffer->yy_buf_pos = yy_c_buf_p;
  yy_current_buffer->yy_n_chars = yy_n_chars;
  }

 yy_current_buffer = new_buffer;
 yy_load_buffer_state();






 yy_did_buffer_switch_on_eof = 1;
 }



void yy_load_buffer_state( void )



 {
 yy_n_chars = yy_current_buffer->yy_n_chars;
 yytext = yy_c_buf_p = yy_current_buffer->yy_buf_pos;
 yyin = yy_current_buffer->yy_input_file;
 yy_hold_char = *yy_c_buf_p;
 }



YY_BUFFER_STATE yy_create_buffer( FILE *file, int size )





 {
 YY_BUFFER_STATE b;

 b = (YY_BUFFER_STATE) yy_flex_alloc( sizeof( struct yy_buffer_state ) );
 if ( ! b )
  yy_fatal_error( "out of dynamic memory in yy_create_buffer()" );

 b->yy_buf_size = size;




 b->yy_ch_buf = (char *) yy_flex_alloc( b->yy_buf_size + 2 );
 if ( ! b->yy_ch_buf )
  yy_fatal_error( "out of dynamic memory in yy_create_buffer()" );

 b->yy_is_our_buffer = 1;

 yy_init_buffer( b, file );

 return b;
 }



void yy_delete_buffer( YY_BUFFER_STATE b )




 {
 if ( ! b )
  return;

 if ( b == yy_current_buffer )
  yy_current_buffer = (YY_BUFFER_STATE) 0;

 if ( b->yy_is_our_buffer )
  yy_flex_free( (void *) b->yy_ch_buf );

 yy_flex_free( (void *) b );
 }




extern int isatty ( int );




void yy_init_buffer( YY_BUFFER_STATE b, FILE *file )







 {
 yy_flush_buffer( b );

 b->yy_input_file = file;
 b->yy_fill_buffer = 1;







 b->yy_is_interactive = file ? (isatty( fileno(file) ) > 0) : 0;


 }



void yy_flush_buffer( YY_BUFFER_STATE b )





 {
 b->yy_n_chars = 0;





 b->yy_ch_buf[0] = 0;
 b->yy_ch_buf[1] = 0;

 b->yy_buf_pos = &b->yy_ch_buf[0];

 b->yy_at_bol = 1;
 b->yy_buffer_status = 0;

 if ( b == yy_current_buffer )
  yy_load_buffer_state();
 }




YY_BUFFER_STATE yy_scan_buffer( char *base, yy_size_t size )





 {
 YY_BUFFER_STATE b;

 if ( size < 2 ||
      base[size-2] != 0 ||
      base[size-1] != 0 )

  return 0;

 b = (YY_BUFFER_STATE) yy_flex_alloc( sizeof( struct yy_buffer_state ) );
 if ( ! b )
  yy_fatal_error( "out of dynamic memory in yy_scan_buffer()" );

 b->yy_buf_size = size - 2;
 b->yy_buf_pos = b->yy_ch_buf = base;
 b->yy_is_our_buffer = 0;
 b->yy_input_file = 0;
 b->yy_n_chars = b->yy_buf_size;
 b->yy_is_interactive = 0;
 b->yy_at_bol = 1;
 b->yy_fill_buffer = 0;
 b->yy_buffer_status = 0;

 yy_switch_to_buffer( b );

 return b;
 }





YY_BUFFER_STATE yy_scan_string( const char *str )




 {
 int len;
 for ( len = 0; str[len]; ++len )
  ;

 return yy_scan_bytes( str, len );
 }





YY_BUFFER_STATE yy_scan_bytes( const char *bytes, int len )





 {
 YY_BUFFER_STATE b;
 char *buf;
 yy_size_t n;
 int i;


 n = len + 2;
 buf = (char *) yy_flex_alloc( n );
 if ( ! buf )
  yy_fatal_error( "out of dynamic memory in yy_scan_bytes()" );

 for ( i = 0; i < len; ++i )
  buf[i] = bytes[i];

 buf[len] = buf[len+1] = 0;

 b = yy_scan_buffer( buf, n );
 if ( ! b )
  yy_fatal_error( "bad buffer in yy_scan_bytes()" );




 b->yy_is_our_buffer = 1;

 return b;
 }





static void yy_push_state( int new_state )




 {
 if ( yy_start_stack_ptr >= yy_start_stack_depth )
  {
  yy_size_t new_size;

  yy_start_stack_depth += 25;
  new_size = yy_start_stack_depth * sizeof( int );

  if ( ! yy_start_stack )
   yy_start_stack = (int *) yy_flex_alloc( new_size );

  else
   yy_start_stack = (int *) yy_flex_realloc(
     (void *) yy_start_stack, new_size );

  if ( ! yy_start_stack )
   yy_fatal_error( "out of memory expanding start-condition stack" )
                                                    ;
  }

 yy_start_stack[yy_start_stack_ptr++] = ((yy_start - 1) / 2);

 yy_start = 1 + 2 *(new_state);
 }




static void yy_pop_state()
 {
 if ( --yy_start_stack_ptr < 0 )
  yy_fatal_error( "start-condition stack underflow" );

 yy_start = 1 + 2 *(yy_start_stack[yy_start_stack_ptr]);
 }
# 14068 "flex_single_original.c"
static void yy_fatal_error( const char msg[] )




 {
 (void) fprintf( err, "%s\n", msg );
 exit( 2 );
 }
# 14140 "flex_single_original.c"
static void *yy_flex_alloc( yy_size_t size )




 {
 return (void *) malloc( size );
 }


static void *yy_flex_realloc( void *ptr, yy_size_t size )





 {







 return (void *) realloc( (char *) ptr, size );
 }


static void yy_flex_free( void *ptr )




 {
 free( ptr );
 }
# 14187 "flex_single_original.c"
int yywrap()
 {
 if ( --num_input_files > 0 )
  {
  set_input_file( *++input_files );
  return 0;
  }

 else
  return 1;
 }




void set_input_file( file )
char *file;
 {
 if ( file && strcmp( file, "-" ) )
  {
  infilename = copy_string( file );
  yyin = fopen( infilename, "r" );

  if ( yyin == 
# 14210 "flex_single_original.c" 3 4
              ((void *)0) 
# 14210 "flex_single_original.c"
                   )
   lerrsf( ("can't open %s"), file );
  }

 else
  {
  yyin = 
# 14216 "flex_single_original.c" 3 4
        stdin
# 14216 "flex_single_original.c"
             ;
  infilename = copy_string( "<stdin>" );
  }

 linenum = 1;
 }




void *flex_alloc( size )
size_t size;
 {
 return (void *) malloc( size );
 }

void *flex_realloc( ptr, size )
void *ptr;
size_t size;
 {
 return (void *) realloc( ptr, size );
 }

void flex_free( ptr )
void *ptr;
 {
 if ( ptr )
  free( ptr );
 }
