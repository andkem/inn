/*  $Id$
**
**  Replacement for a missing strerror.
**
**  Written by Russ Allbery <rra@stanford.edu>
**  This work is hereby placed in the public domain by its author.
**
**  Provides the same functionality as the standard library routine strerror
**  for those platforms that don't have it (e.g. Ultrix).  Assume that we
**  have sys_nerr and sys_errlist available to use instead.  Calling
**  strerror should be thread-safe unless it is called for an unknown errno.
*/

#include "config.h"

/* Our declarations of sys_nerr and sys_errlist may conflict with the ones
   provided by stdio.h from glibc.  This trick hides the declarations in the
   system header from the compiler while we test.  (The conflicts are just
   whether or not to const, so there are no negative effects from using our
   declarations.) */
#if TESTING
# define sys_nerr       hidden_sys_nerr
# define sys_errlist    hidden_sys_errlist
#endif

#include <errno.h>
#include <stdio.h>

#if TESTING
# undef sys_nerr
# undef sys_errlist
#endif

extern const int sys_nerr;
extern const char *sys_errlist[];

/* If we're running the test suite, rename strerror to avoid conflicts with
   the system version. */
#if TESTING
# define strerror test_strerror
const char *test_strerror(int);
int snprintf(char *, size_t, const char *, ...);
#endif

const char *
strerror(int error)
{
    static char buff[32];
    int oerrno;

    if (error >= 0 && error < sys_nerr)
        return sys_errlist[error];
    oerrno = errno;
    snprintf(buff, sizeof(buff), "Error code %d", error);
    errno = oerrno;
    return buff;
}