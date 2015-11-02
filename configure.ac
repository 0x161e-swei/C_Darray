#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([C_Darray], [0.1.0], [shijiawei@g.harvard.edu])


AC_CONFIG_AUX_DIR([build_aux])
AM_INIT_AUTOMAKE([subdir-objects foreign])
AM_SILENT_RULES([yes])
AC_CONFIG_SRCDIR([src/darray.c])
AC_CONFIG_HEADERS([config.h])

: ${CFLAGS=""}
# Checks for programs.
AC_PROG_CC
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
