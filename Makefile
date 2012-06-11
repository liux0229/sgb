include Makefile.inc

tests: force_look
	cd common; make $(MFLAGS)
	cd test; make $(MFLAGS)

force_look:
	true
