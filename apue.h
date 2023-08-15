/*
* Our own header, to be included before all standard system headers.
*/
#ifndef _APUE_H
#define _APUE_H

#define _POSIX_C_SOURCE 200809L

/* we don't care about Solaris 10 */

#include <sys/types.h> /* some systems still require this ... why? */
#include <sys/stat.h>
#include <sys/termios.h> /* for winsize */

#if defined(MACOS) || !defined(TIOCGWINSZ)
#include <sys/ioctl.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define MAXLINE 4096 /* max line length */

#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

#define DIR_MODE (FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

typedef void Sigfunc(int);

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

void err_msg(const char *, ...);

#endif /* _APUE_H */
