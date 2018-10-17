#!/usr/bin/make
CXX := g++
CXXFLAGS += -Wall -std=c++17 -g
LDFLAGS := libproject.a

LIBSRCS = $(filter-out main.cc, $(shell find -name \*.cc))
LIBOBJS = $(patsubst %.cc, %.o, $(LIBSRCS))

main: main.o libproject.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ $< $(LDFLAGS) 

$(LIBOBJS): %.o: %.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c -o $@ $<

libproject.a: $(LIBOBJS)
	ar rcs $@ $^

clean:
	rm -f libproject.a $(LIBOBJS) main

.PHONY: clean