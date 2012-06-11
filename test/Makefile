include ../Makefile.inc

CPPFLAGS+=-I../common
# TODO: fix this
LIBPATH=../lib
LDFLAGS=-L$(LIBPATH)
LDLIBS=-lgraph

SOURCES=RandomTest.cpp
# TODO: this shows up in the build cmd line
LIBDEP=$(LIBPATH)/libgraph.a

# TODO: fix this (we want to use all)
RandomTest: $(SOURCES) $(LIBDEP)
