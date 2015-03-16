CC=gcc
CXX=g++
INCLUDES= -I./
CXXFLAGS = -g $(INCLUDES)

RM=rm -f
CFLAGS=-g -O2
LDFLAGS=-g -O2
LINKFLAGS= -lcppunit


EXAMPLE_SRS=../SubSecuencia.cpp
FRAMEWORK=../Simulador.cpp

SRCS=UnitTestCase.cpp $(EXAMPLE_SRS) $(FRAMEWORK)
OBJS=$(subst .cpp,.o,$(SRCS))

all: main

main: $(OBJS)
	$(CXX) $(LDFLAGS) -o main $(OBJS) $(LINKFLAGS) $(LINKFLAGSLOG4) $(LIBLOG)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

dist-clean: clean
	$(RM) *~ .dependtool

include .depend
