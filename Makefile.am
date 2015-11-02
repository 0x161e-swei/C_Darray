# -*- makefile -*-

bin_PROGRAMS = test

SRCDIR = src

O ?= 3
AM_CFLAGS = -std=c99 -g -ggdb3 -Wall -Wextra -pedantic -pthread -O$(O)

noinst_LIBRARIES = libdarray.a

include_HEADERS = src/darray.h
libdarray_a_SOURCES = src/darray.c
libdarray_a_CFLAGS = $(AM_CFLAGS)

test_SOURCES = src/test/test.c
test_CFLAGS = $(AM_CFLAGS)
test_LDADD = libdarray.a
test_CPPFLAGS = -Isrc
