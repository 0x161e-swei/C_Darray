# -*- makefile -*-

bin_PROGRAMS = test

SRCDIR = src
INCDIR = include

O ?= 0
AM_CFLAGS = -std=c99 -g -ggdb3 -Wall -Wextra -pedantic -pthread -O$(O)
AM_CPPFLAGS = -I$(INCDIR) -DDEBUG

noinst_LIBRARIES = libdarray.a

libdarray_a_SOURCES = src/darray.c
libdarray_a_CFLAGS = $(AM_CFLAGS)
libdarray_a_CPPFLAGS = $(AM_CPPFLAGS)


test_SOURCES = src/test/test.c
test_CFLAGS = $(AM_CFLAGS)
test_LDADD = libdarray.a
test_CPPFLAGS = $(AM_CPPFLAGS)

