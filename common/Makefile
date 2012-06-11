include ../Makefile.inc

# TODO: we have to manually remove the .o file
OBJS=Random.o

all: lib

lib: ../lib/libgraph.a

../lib/libgraph.a: $(OBJS)
	ar rcv ../lib/libgraph.a $(OBJS)
	- ranlib ../lib/libgraph.a
