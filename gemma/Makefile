#
# Makefile for gemma, a GEM library
#

SHELL = /bin/sh
SUBDIRS = libgemma documentation libslb src configtool test

srcdir = .
top_srcdir = ..
subdir = gemma

default: all

include $(top_srcdir)/CONFIGVARS
include $(top_srcdir)/RULES
include $(top_srcdir)/PHONY
include $(srcdir)/VERSION

all-here: 

# default overwrites

# default definitions


install:
	mkdir -p ${PREFIX}/include/slb
	mkdir -p ${PREFIX}/local/lib/slb
	install -m 644 include/slb/gemma.h ${PREFIX}/include/slb
	install -m 644 include/slb/gemma-struct.h ${PREFIX}/include/slb
	install -m 644 include/slb/kernel.h ${PREFIX}/include/slb
	install -m 644 libgemma/libgemma.a ${PREFIX}/lib
ifeq ($(WITH_020_LIB),yes)
	install -m 644 libgemma/libgemma020.a ${PREFIX}/lib/m68020-60/libgemma.a
endif
	install -m 755 src/gemma32.slb ${PREFIX}/local/lib/slb
	install -m 755 kernel32.slb ${PREFIX}/local/lib/slb

uninstall:
	rm -f ${PREFIX}/include/slb/gemma-struct.h
	rm -f ${PREFIX}/include/slb/gemma.h
	rm -f ${PREFIX}/include/slb/kernel.h
	rm -f ${PREFIX}/lib/libgemma.a
ifeq ($(WITH_020_LIB),yes)
	rm -f ${PREFIX}/lib/m68020-60/libgemma.a
endif
	rm -f ${PREFIX}/local/lib/slb/gemma32.slb
	rm -f ${PREFIX}/local/lib/slb/kernel32.slb
