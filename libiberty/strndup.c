/* Implement the strndup function.
   Copyright (C) 2005 Free Software Foundation, Inc.
   Written by Kaveh R. Ghazi <ghazi@caip.rutgers.edu>.

This file is part of the libiberty library.
Libiberty is free software; you can redistribute it and/or
modify it under the terms of the GNU Library General Public
License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

Libiberty is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Library General Public License for more details.

You should have received a copy of the GNU Library General Public
License along with libiberty; see the file COPYING.LIB.  If
not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/*

@deftypefn Extension char* strndup (const char *@var{s}, size_t @var{n})

Returns a pointer to a copy of @var{s} with at most @var{n} characters
in memory obtained from @code{malloc}, or @code{NULL} if insufficient
memory was available.  The result is always NUL terminated.

@end deftypefn

*/

#include "ansidecl.h"
#ifdef ANSI_PROTOTYPES
#include <stddef.h>
#else
#define size_t unsigned long
#endif

extern size_t	strlen PARAMS ((const char*));
extern PTR	malloc PARAMS ((size_t));
extern PTR	memcpy PARAMS ((PTR, const PTR, size_t));

char *
strndup(s, n)
     const char *s;
     size_t n;
{
  char *result;
  size_t len = strlen (s);

  if (n < len)
    len = n;

  result = malloc (len + 1);
  if (!result)
    return 0;

  result[len] = '\0';
  return memcpy (result, s, len);
}
