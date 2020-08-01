# 1 "print_tokens_single_original.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "print_tokens_single_original.c"


# 1 "/usr/include/ctype.h" 1 3 4
# 25 "/usr/include/ctype.h" 3 4
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
# 26 "/usr/include/ctype.h" 2 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/types.h" 1 3 4
# 27 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/wordsize.h" 1 3 4
# 28 "/usr/include/x86_64-linux-gnu/bits/types.h" 2 3 4



# 30 "/usr/include/x86_64-linux-gnu/bits/types.h" 3 4
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
# 27 "/usr/include/ctype.h" 2 3 4


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

# 4 "print_tokens_single_original.c" 2






# 9 "print_tokens_single_original.c"
typedef int BOOLEAN;
typedef char *string;

# 1 "/usr/include/stdio.h" 1 3 4
# 29 "/usr/include/stdio.h" 3 4




# 1 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 1 3 4
# 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4

# 216 "/usr/lib/gcc/x86_64-linux-gnu/5/include/stddef.h" 3 4
typedef long unsigned int size_t;
# 34 "/usr/include/stdio.h" 2 3 4
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

# 13 "print_tokens_single_original.c" 2
# 1 "tokens.h" 1







# 1 "stream.h" 1








# 8 "stream.h"
typedef struct stream_type {
                               FILE *fp;
                               int stream_ind;
                               char stream[80];
                            } *character_stream;

typedef char CHARACTER;

character_stream open_character_stream();

CHARACTER get_char();

BOOLEAN is_end_of_character_stream();
# 9 "tokens.h" 2
# 32 "tokens.h"
typedef struct token_stream_type {
                             character_stream ch_stream;
                          } *token_stream;

typedef struct token_type {
                                int token_id;
                                char token_string[80];
                          } *token;

token_stream open_token_stream();

token get_token();

BOOLEAN compare_token();

BOOLEAN is_eof_token();

int default1[]={
                 54, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 51, -2, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1 ,-1, -1, -1, -1, -1,
                 -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                 -1, 52, -3, -1 ,-1, -1, -1, -1, -1, -1
               };
int base[] ={
                  -32, -96,-105, -93, -94, -87, -1, -97, -86, -1,
                  -99, -1, -72, -1, -80, -82, -1, 53, 43, -1,
                  -1, -1, -1, -1, -1, -1, 133, -1, 233, -1,
                  -1, 0, -1, -1, -1, -1, -1, -1, -1, -1,
                  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
                  -1, 46, 40, -1, 251, -1, -1, -1, -1, -1
              };
int next[] = {
                  0, 2, 26, 28, 3, 4, 5, 23, 19, 20,
                  6, -1, 25, 8, 9, 11, 18, 18, 18, 18,
                 18, 18, 18, 18, 18, 18, -1, 30, -1, 31,
                 13, 15, 16, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 21,
                 -1, 22, 32, -1, 24, 7, 17, 17, 17, 17,
                 17, 17, 17, 12, 17, 17, 1, 17, 17, 10,
                 17, 17, 17, 17, 17, 17, 17, 17, 14, 17,
                 17, 18, 18, 18, 18, 18, 18, 18, 18, 18,
                 18, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 17, 17, -1, -1, 26, 26, 27, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                  0, 0, -1, -1, -1, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29,
                 29, 29, 29, 29, 29, 29, 29, 29, 29, 29
            };
int check[] = { 0, 1, 0, 0, 2, 3, 4, 0, 0, 0,
                  5, -1, 0, 7, 8, 10, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, -1, 0, -1, 0,
                 12, 14, 15, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                 -1, 0, 31, -1, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                  0, 18, 18, 18, 18, 18, 18, 18, 18, 18,
                 18, 17, 17, 17, 17, 17, 17, 17, 17, 17,
                 17, 51, 51, 51, 51, 51, 51, 51, 51, 51,
                 51, 51, 51, 51, 51, 51, 51, 51, 51, 51,
                 51, 51, 51, 51, 51, 51, 51, 52, 52, 52,
                 52, 52, 52, 52, 52, 52, 52, 52, 52, 52,
                 52, 52, 52, 52, 52, 52, 52, 52, 52, 52,
                 52, 52, 52, -1, -1, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 26, 26, 26, 26, 26, 26, 26, 26, 26, 26,
                 54, 54, -1, -1, -1, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28,
                 28, 28, 28, 28, 28, 28, 28, 28, 28, 28
              };
# 14 "print_tokens_single_original.c" 2

static token numeric_case();
static token error_or_eof_case();
static int check_delimiter();
static int keyword(int state);
static int special(int state);
static skip(character_stream stream_ptr);
static int constant(int state,char token_str[],int token_ind);
static int next_state();
static get_actual_token(char token_str[],int token_ind);

main(argc,argv)
int argc;
char *argv[];
{
      token token_ptr;
      token_stream stream_ptr;

      if(argc>2)
      {
          fprintf(
# 34 "print_tokens_single_original.c" 3 4
                 stdout
# 34 "print_tokens_single_original.c"
                       , "The format is print_tokens filename(optional)\n");
          exit(1);
      }
      stream_ptr=open_token_stream(argv[1]);

      while(!is_eof_token((token_ptr=get_token(stream_ptr))))
                print_token(token_ptr);
      print_token(token_ptr);
  exit(0);
}
# 60 "print_tokens_single_original.c"
character_stream open_character_stream(FILENAME)
string FILENAME;
{
      character_stream stream_ptr;

      stream_ptr=(character_stream)malloc(sizeof(struct stream_type));
      stream_ptr->stream_ind=5;
      stream_ptr->stream[5]='\0';
      if(FILENAME == 
# 68 "print_tokens_single_original.c" 3 4
                    ((void *)0)
# 68 "print_tokens_single_original.c"
                        )
          stream_ptr->fp=
# 69 "print_tokens_single_original.c" 3 4
                        stdin
# 69 "print_tokens_single_original.c"
                             ;
      else if((stream_ptr->fp=fopen(FILENAME,"r"))==
# 70 "print_tokens_single_original.c" 3 4
                                                   ((void *)0)
# 70 "print_tokens_single_original.c"
                                                       )
           {
               fprintf(
# 72 "print_tokens_single_original.c" 3 4
                      stdout
# 72 "print_tokens_single_original.c"
                            , "The file %s doesn't exists\n",FILENAME);
               exit(0);
           }
      return(stream_ptr);
}
# 89 "print_tokens_single_original.c"
CHARACTER get_char(stream_ptr)
character_stream stream_ptr;
{
      if(stream_ptr->stream[stream_ptr->stream_ind] == '\0')
      {
              if(fgets(stream_ptr->stream+5,80-5,stream_ptr->fp) == 
# 94 "print_tokens_single_original.c" 3 4
                                                                           ((void *)0)
# 94 "print_tokens_single_original.c"
                                                                               )
                    stream_ptr->stream[5]=
# 95 "print_tokens_single_original.c" 3 4
                                             (-1)
# 95 "print_tokens_single_original.c"
                                                ;
              stream_ptr->stream_ind=5;
      }
      return(stream_ptr->stream[(stream_ptr->stream_ind)++]);
}
# 112 "print_tokens_single_original.c"
BOOLEAN is_end_of_character_stream(stream_ptr)
character_stream stream_ptr;
{
      if(stream_ptr->stream[stream_ptr->stream_ind-1] == 
# 115 "print_tokens_single_original.c" 3 4
                                                        (-1)
# 115 "print_tokens_single_original.c"
                                                           )
            return(1);
      else
            return(0);
}
# 131 "print_tokens_single_original.c"
unget_char(ch,stream_ptr)
CHARACTER ch;
character_stream stream_ptr;
{
      if(stream_ptr->stream_ind == 0)
          return;
      else
          stream_ptr->stream[--(stream_ptr->stream_ind)]=ch;
      return;
}
# 155 "print_tokens_single_original.c"
token_stream open_token_stream(FILENAME)
string FILENAME;
{
    token_stream token_ptr;

    token_ptr=(token_stream)malloc(sizeof(struct token_stream_type));
    token_ptr->ch_stream=open_character_stream(FILENAME);

    return(token_ptr);
}
# 179 "print_tokens_single_original.c"
token get_token(tstream_ptr)
token_stream tstream_ptr;
{
      char token_str[80];
      int token_ind;
      token token_ptr;
      CHARACTER ch;
      int cu_state,next_st,token_found;

      token_ptr=(token)(malloc(sizeof(struct token_type)));
      ch=get_char(tstream_ptr->ch_stream);
      cu_state=token_ind=token_found=0;
      while(!token_found)
      {
   if(token_ind < 80)
   {
       token_str[token_ind++]=ch;
       next_st=next_state(cu_state,ch);
   }
   else
   {
       next_st = -1;
   }
   if (next_st == -1) {
       return(error_or_eof_case(tstream_ptr,
           token_ptr,cu_state,token_str,token_ind,ch));
   } else if (next_st == -2) {
       return(numeric_case(tstream_ptr,token_ptr,ch,
      token_str,token_ind));
   } else if (next_st == -3) {
       token_ptr->token_id=17;
       unget_char(ch,tstream_ptr->ch_stream);
       token_ind--;
       get_actual_token(token_str,token_ind);
       strcpy(token_ptr->token_string,token_str);
       return(token_ptr);
   }

   switch(next_st)
            {
                 default : break;
                 case 6 :
                 case 9 :
                 case 11 :
                 case 13 :
                 case 16 : ch=get_char(tstream_ptr->ch_stream);
                           if(check_delimiter(ch)==1)
                           {
                                 token_ptr->token_id=keyword(next_st);
                                 unget_char(ch,tstream_ptr->ch_stream);
                                 token_ptr->token_string[0]='\0';
                                 return(token_ptr);
                           }

                           break;
                 case 19 :
                 case 20 :
                 case 21 :
                 case 22 :
                 case 23 :
                 case 24 :
                 case 25 :
                 case 32 : token_ptr->token_id=special(next_st);
                           token_ptr->token_string[0]='\0';
                           return(token_ptr);
                 case 27 :
                 case 29 : token_ptr->token_id=constant(next_st,token_str,token_ind);
                           get_actual_token(token_str,token_ind);
                           strcpy(token_ptr->token_string,token_str);
                           return(token_ptr);
                 case 30 :
                           skip(tstream_ptr->ch_stream);
                           token_ind=next_st=0;
                           break;
            }
            cu_state=next_st;
            ch=get_char(tstream_ptr->ch_stream);
      }
}
# 268 "print_tokens_single_original.c"
static token numeric_case(tstream_ptr,token_ptr,ch,token_str,token_ind)
token_stream tstream_ptr;
token token_ptr;
char ch,token_str[];
int token_ind;
{
        if(check_delimiter(ch)!=1)
        {
            token_ptr->token_id=-1;
            while(check_delimiter(ch)==0)
     {
  if(token_ind >= 80) break;
  token_str[token_ind++]=ch=get_char(tstream_ptr->ch_stream);
     }
            unget_char(ch,tstream_ptr->ch_stream);
            token_ind--;
            get_actual_token(token_str,token_ind);
            strcpy(token_ptr->token_string,token_str);
            return(token_ptr);
        }
        token_ptr->token_id=18;
        unget_char(ch,tstream_ptr->ch_stream);
        token_ind--;
        get_actual_token(token_str,token_ind);
        strcpy(token_ptr->token_string,token_str);
        return(token_ptr);
}
# 306 "print_tokens_single_original.c"
static token error_or_eof_case(tstream_ptr,token_ptr,cu_state,token_str,token_ind,ch)
token_stream tstream_ptr;
token token_ptr;
int cu_state,token_ind;
char token_str[],ch;
{
      if(is_end_of_character_stream(tstream_ptr->ch_stream))
      {
            token_ptr->token_id = 0;
            token_ptr->token_string[0]='\0';
            return(token_ptr);
      }
      if(cu_state !=0)
      {
            unget_char(ch,tstream_ptr->ch_stream);
            token_ind--;
      }
      token_ptr->token_id=-1;
      get_actual_token(token_str,token_ind);
      strcpy(token_ptr->token_string,token_str);
      return(token_ptr);
}
# 339 "print_tokens_single_original.c"
static int check_delimiter(ch)
char ch;
{
      if(!
# 342 "print_tokens_single_original.c" 3 4
         ((*__ctype_b_loc ())[(int) ((
# 342 "print_tokens_single_original.c"
         ch
# 342 "print_tokens_single_original.c" 3 4
         ))] & (unsigned short int) _ISalpha) 
# 342 "print_tokens_single_original.c"
                     && !
# 342 "print_tokens_single_original.c" 3 4
                         ((*__ctype_b_loc ())[(int) ((
# 342 "print_tokens_single_original.c"
                         ch
# 342 "print_tokens_single_original.c" 3 4
                         ))] & (unsigned short int) _ISdigit)
# 342 "print_tokens_single_original.c"
                                    )
          return(1);
      return(0);
}
# 356 "print_tokens_single_original.c"
static int keyword(state)
int state;
{
      switch(state)
      {
          case 6 : return(6);
          case 9 : return(9);
          case 11: return(11);
          case 13: return(13);
          case 16: return(16);
          default: fprintf(
# 366 "print_tokens_single_original.c" 3 4
                          stdout
# 366 "print_tokens_single_original.c"
                                , "error\n");break;
      }
      exit(0);
}
# 381 "print_tokens_single_original.c"
static int special(state)
int state;
{
     switch(state)
     {
         case 19: return(19);
         case 20: return(20);
         case 21: return(21);
         case 22: return(22);
         case 23: return(23);
         case 24: return(24);
         case 25: return(25);
         case 32: return(32);
         default: fprintf(
# 394 "print_tokens_single_original.c" 3 4
                         stdout
# 394 "print_tokens_single_original.c"
                               , "error\n");break;
     }
     exit(0);
}
# 410 "print_tokens_single_original.c"
static skip(stream_ptr)
character_stream stream_ptr;
{
        char c;

        while((c=get_char(stream_ptr))!='\n' &&
               !is_end_of_character_stream(stream_ptr))
             ;
 if(c==
# 418 "print_tokens_single_original.c" 3 4
      (-1)
# 418 "print_tokens_single_original.c"
         ) unget_char(c, stream_ptr);
        return;
}
# 431 "print_tokens_single_original.c"
static int constant(state,token_str,token_ind)
int state,token_ind;
char token_str[];
{
     switch(state)
     {
         case 27 : return(27);
         case 29 : token_str[token_ind-2]=' '; return(29);
         default : break;
     }
}
# 454 "print_tokens_single_original.c"
static int next_state(state,ch)
int state;
char ch;
{
    if(state < 0)
      return(state);
    if(base[state]+ch >= 0)
    {
        if(check[base[state]+ch] == state)
             return(next[base[state]+ch]);
        else
              return(next_state(default1[state],ch));
    }
    else
        return(next_state(default1[state],ch));
}
# 481 "print_tokens_single_original.c"
BOOLEAN is_eof_token(t)
token t;
{
    if(t->token_id==0)
        return(1);
    return(0);
}
# 503 "print_tokens_single_original.c"
BOOLEAN print_token(token_ptr)
token token_ptr;
{
     switch(token_ptr->token_id)
     {
          case -1 : fprintf(
# 508 "print_tokens_single_original.c" 3 4
                              stdout
# 508 "print_tokens_single_original.c"
                                    , "error,\t\"");fprintf(
# 508 "print_tokens_single_original.c" 3 4
                                                            stdout
# 508 "print_tokens_single_original.c"
                                                                  , "%s",token_ptr->token_string);
                       fprintf(
# 509 "print_tokens_single_original.c" 3 4
                              stdout
# 509 "print_tokens_single_original.c"
                                    , "\".\n");return(1);
          case 0 : fprintf(
# 510 "print_tokens_single_original.c" 3 4
                                  stdout
# 510 "print_tokens_single_original.c"
                                        , "eof.\n");return(1);
          case 6 : fprintf(
# 511 "print_tokens_single_original.c" 3 4
                          stdout
# 511 "print_tokens_single_original.c"
                                , "keyword,\t\"lambda\".\n");return(1);
          case 9 : fprintf(
# 512 "print_tokens_single_original.c" 3 4
                          stdout
# 512 "print_tokens_single_original.c"
                                , "keyword,\t\"and\".\n");return(1);
          case 11: fprintf(
# 513 "print_tokens_single_original.c" 3 4
                          stdout
# 513 "print_tokens_single_original.c"
                                , "keyword,\t\"or\".\n");return(1);
          case 13: fprintf(
# 514 "print_tokens_single_original.c" 3 4
                          stdout
# 514 "print_tokens_single_original.c"
                                , "keyword,\t\"if\".\n");return(1);
          case 16: fprintf(
# 515 "print_tokens_single_original.c" 3 4
                          stdout
# 515 "print_tokens_single_original.c"
                                , "keyword,\t\"xor\".\n");return(1);
          case 17: fprintf(
# 516 "print_tokens_single_original.c" 3 4
                          stdout
# 516 "print_tokens_single_original.c"
                                , "identifier,\t\"");fprintf(
# 516 "print_tokens_single_original.c" 3 4
                                                             stdout
# 516 "print_tokens_single_original.c"
                                                                   , "%s",token_ptr->token_string);
                   fprintf(
# 517 "print_tokens_single_original.c" 3 4
                          stdout
# 517 "print_tokens_single_original.c"
                                , "\".\n");return(1);
          case 18: fprintf(
# 518 "print_tokens_single_original.c" 3 4
                          stdout
# 518 "print_tokens_single_original.c"
                                , "numeric,\t");fprintf(
# 518 "print_tokens_single_original.c" 3 4
                                                        stdout
# 518 "print_tokens_single_original.c"
                                                              , "%s",token_ptr->token_string);
                   fprintf(
# 519 "print_tokens_single_original.c" 3 4
                          stdout
# 519 "print_tokens_single_original.c"
                                , ".\n");return(1);
          case 19: fprintf(
# 520 "print_tokens_single_original.c" 3 4
                          stdout
# 520 "print_tokens_single_original.c"
                                , "lparen.\n");return(1);
          case 20: fprintf(
# 521 "print_tokens_single_original.c" 3 4
                          stdout
# 521 "print_tokens_single_original.c"
                                , "rparen.\n");return(1);
          case 21: fprintf(
# 522 "print_tokens_single_original.c" 3 4
                          stdout
# 522 "print_tokens_single_original.c"
                                , "lsquare.\n");return(1);
          case 22: fprintf(
# 523 "print_tokens_single_original.c" 3 4
                          stdout
# 523 "print_tokens_single_original.c"
                                , "rsquare.\n");return(1);
          case 23: fprintf(
# 524 "print_tokens_single_original.c" 3 4
                          stdout
# 524 "print_tokens_single_original.c"
                                , "quote.\n");return(1);
          case 24: fprintf(
# 525 "print_tokens_single_original.c" 3 4
                          stdout
# 525 "print_tokens_single_original.c"
                                , "bquote.\n");return(1);
          case 25: fprintf(
# 526 "print_tokens_single_original.c" 3 4
                          stdout
# 526 "print_tokens_single_original.c"
                                , "comma.\n");return(1);
          case 27: fprintf(
# 527 "print_tokens_single_original.c" 3 4
                          stdout
# 527 "print_tokens_single_original.c"
                                , "string,\t");fprintf(
# 527 "print_tokens_single_original.c" 3 4
                                                       stdout
# 527 "print_tokens_single_original.c"
                                                             , "%s",token_ptr->token_string);
                   fprintf(
# 528 "print_tokens_single_original.c" 3 4
                          stdout
# 528 "print_tokens_single_original.c"
                                , ".\n");return(1);
          case 29: fprintf(
# 529 "print_tokens_single_original.c" 3 4
                          stdout
# 529 "print_tokens_single_original.c"
                                , "character,\t\"");fprintf(
# 529 "print_tokens_single_original.c" 3 4
                                                            stdout
# 529 "print_tokens_single_original.c"
                                                                  , "%s",token_ptr->token_string);
                   fprintf(
# 530 "print_tokens_single_original.c" 3 4
                          stdout
# 530 "print_tokens_single_original.c"
                                , "\".\n");return(1);
          case 32: fprintf(
# 531 "print_tokens_single_original.c" 3 4
                          stdout
# 531 "print_tokens_single_original.c"
                                , "keyword,\t\"=>\".\n");return(1);
          default: break;
      }
      return(0);
}
# 547 "print_tokens_single_original.c"
static get_actual_token(token_str,token_ind)
int token_ind;
char token_str[];
{
          int ind,start;

          for(ind=token_ind;ind>0 && 
# 553 "print_tokens_single_original.c" 3 4
                                    ((*__ctype_b_loc ())[(int) ((
# 553 "print_tokens_single_original.c"
                                    token_str[ind-1]
# 553 "print_tokens_single_original.c" 3 4
                                    ))] & (unsigned short int) _ISspace)
# 553 "print_tokens_single_original.c"
                                                             ;--ind);

           token_str[ind]='\0';token_ind=ind;
          for(ind=0;ind<token_ind;++ind)
                if(!
# 557 "print_tokens_single_original.c" 3 4
                   ((*__ctype_b_loc ())[(int) ((
# 557 "print_tokens_single_original.c"
                   token_str[ind]
# 557 "print_tokens_single_original.c" 3 4
                   ))] & (unsigned short int) _ISspace)
# 557 "print_tokens_single_original.c"
                                          )
                      break;
          for(start=0;ind<=token_ind;++start,++ind)

                token_str[start]=token_str[ind];
          return;
}
