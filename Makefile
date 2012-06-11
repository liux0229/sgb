include Makefile.inc

tests: force_look
	cd common; make $(MFLAGS)
	cd test; make $(MFLAGS)

#TODO: refine this
clean:
	rm -f *.o
	rm -fr lib
	rm -f common/*.o
	rm -f test/*.o test/RandomTest

force_look:
	true
