#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([toyhack], [0.1.0], [yasuenag@gmail.com])
AC_CONFIG_SRCDIR([src])
AC_CONFIG_AUX_DIR([./m4])
AC_CONFIG_MACRO_DIR([./m4])
AM_INIT_AUTOMAKE([subdir-objects])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([wiringPi], [wiringPiSetup])

# Checks for header files.
AC_CHECK_HEADERS([wiringPi.h mcp23017.h],
                 [], [AC_MSG_ERROR([WiringPi header files not found.])])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL

# Checks for WiringPi
AC_ARG_WITH([wiring-pi], AC_HELP_STRING([--with-wiring-pi@<:@=PATH@:>@],
                                                         [Path to WiringPi.]))


AC_CONFIG_FILES([
  Makefile
  src/common/Makefile
  src/kyoryuger/Makefile
  src/kyoryuger/gaburevolver/Makefile
  src/kyoryuger/gaburevolver/lib/Makefile
  src/kyoryuger/minityra/Makefile
  src/kyoryuger/minityra/lib/Makefile
  src/yokai-watch/Makefile
  src/yokai-watch/dx/Makefile
  src/yokai-watch/dx/lib/Makefile
])

AC_PROG_RANLIB
AC_OUTPUT
