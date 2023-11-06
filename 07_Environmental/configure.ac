#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([RHASHER], [0.00], [BUG-REPORT-ADDRESS])
AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([rhash],[rhash_library_init],[],[AC_MSG_ERROR([There is no rhash library])])
AC_CHECK_LIB([rhash],[rhash_msg],[],[AC_MSG_ERROR([There is no rhash library])])
AC_CHECK_LIB([rhash],[rhash_print_bytes],[],[AC_MSG_ERROR([There is no rhash library])])
AC_CHECK_LIB([rhash],[rhash_get_digest_size],[],[AC_MSG_ERROR([There is no rhash library])])
AC_CHECK_LIB([rhash],[rhash_file],[],[AC_MSG_ERROR([There is no rhash library])])
AC_CHECK_LIB([readline],[readline])

# Checks for header files.
AC_CHECK_HEADERS([rhash.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([strcasecmp strerror])

AC_ARG_ENABLE([readline],
    AS_HELP_STRING([--enable-readline], [Use readline lib]),
    AC_DEFINE(USE_READLINE,[],[Use readline lib])
  )

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
