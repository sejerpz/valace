#ifndef __FAKE_WIN32_H__
#define __FAKE_WIN32_H__

/* DEBUG Macros */
#define ___MB_SETFOREGROUND 0x10000

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define AT __FILE__ ":" TOSTRING(__LINE__)

#define DBG(V)	MessageBoxW (NULL, TEXT (AT), TEXT(V),___MB_SETFOREGROUND);
#define DBGP(V)	g_print ("%s: %s\n", AT)


#define G_OS_WIN32


/* FAKE errno Support */

#define _errno	errno
static int errno = 0;


#define error(A,B,C,D)	(fprintf (stderr, "error %s", D); exit(-1);)

#define EPERM           1       /* Operation not permitted */
#define ENOFILE         2       /* No such file or directory */
#define ENOENT          2
#define ESRCH           3       /* No such process */
#define EINTR           4       /* Interrupted function call */
#define EIO             5       /* Input/output error */
#define ENXIO           6       /* No such device or address */
#define E2BIG           7       /* Arg list too long */
#define ENOEXEC         8       /* Exec format error */
#define EBADF           9       /* Bad file descriptor */
#define ECHILD          10      /* No child processes */
#define EAGAIN          11      /* Resource temporarily unavailable */
#define ENOMEM          12      /* Not enough space */
#define EACCES          13      /* Permission denied */
#define EFAULT          14      /* Bad address */
/* 15 - Unknown Error */
#define EBUSY           16      /* strerror reports "Resource device" */
#define EEXIST          17      /* File exists */
#define EXDEV           18      /* Improper link (cross-device link?) */
#define ENODEV          19      /* No such device */
#define ENOTDIR         20      /* Not a directory */
#define EISDIR          21      /* Is a directory */
#define EINVAL          22      /* Invalid argument */
#define ENFILE          23      /* Too many open files in system */
#define EMFILE          24      /* Too many open files */
#define ENOTTY          25      /* Inappropriate I/O control operation */
/* 26 - Unknown Error */
#define EFBIG           27      /* File too large */
#define ENOSPC          28      /* No space left on device */
#define ESPIPE          29      /* Invalid seek (seek on a pipe?) */
#define EROFS           30      /* Read-only file system */
#define EMLINK          31      /* Too many links */
#define EPIPE           32      /* Broken pipe */
#define EDOM            33      /* Domain error (math functions) */
#define ERANGE          34      /* Result too large (possibly too small) */
/* 35 - Unknown Error */
#define EDEADLOCK       36      /* Resource deadlock avoided (non-Cyg) */
#define EDEADLK         36
/* 37 - Unknown Error */
#define ENAMETOOLONG    38      /* Filename too long (91 in Cyg?) */
#define ENOLCK          39      /* No locks available (46 in Cyg?) */
#define ENOSYS          40      /* Function not implemented (88 in Cyg?) */
#define ENOTEMPTY       41      /* Directory not empty (90 in Cyg?) */
#define EILSEQ          42      /* Illegal byte sequence */




/* These function are missing from coredll */

/*
 * Macro uses args so we can cast start_proc to LPTHREAD_START_ROUTINE
 * in order to avoid warnings because of return type
 */

#define _beginthreadex(security, \
                       stack_size, \
                       start_proc, \
                       arg, \
                       flags, \
                       pid) \
        CreateThread(security, \
                     stack_size, \
                     (LPTHREAD_START_ROUTINE) start_proc, \
                     arg, \
                     flags, \
                     pid)

#define _endthreadex ExitThread



/* Misc hidden function */

#define getenv(VAR)	(NULL)
#define getpid()	(0)
#define PATH_MAX	259

#endif
