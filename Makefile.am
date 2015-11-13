# -*- makefile -*-

bin_PROGRAMS = test_float test_int

SRCDIR = src
INCDIR = include

O ?= 0
AM_CFLAGS = -std=c99 -g -fno-omit-frame-pointer -ggdb3 -Wall -Wextra -pedantic -pthread -O$(O)
AM_CPPFLAGS = -I$(INCDIR) -DDEBUG

noinst_LIBRARIES = libdarray.a

libdarray_a_SOURCES = src/darray.c
libdarray_a_CFLAGS = $(AM_CFLAGS)
libdarray_a_CPPFLAGS = $(AM_CPPFLAGS)


test_float_SOURCES = src/test/test_float.c
test_float_CFLAGS = $(AM_CFLAGS)
test_float_LDADD = libdarray.a
test_float_CPPFLAGS = $(AM_CPPFLAGS)

test_int_SOURCES = src/test/test_int.c
test_int_CFLAGS = $(AM_CFLAGS)
test_int_LDADD = libdarray.a
test_int_CPPFLAGS = $(AM_CPPFLAGS)

