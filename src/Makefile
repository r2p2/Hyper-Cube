EXEC=hyper-cube

CXX?=g++
CFLAGS=-c -O3 -Wall -g -pg
LDFLAGS=-lcurses -g -pg
SOURCES=$(wildcard *.cpp)
OBJS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJS)
		$(CXX) -o ../bin/$@ $(OBJS) $(LDFLAGS)

.cpp.o:
		$(CXX) $(CFLAGS) $< -o $@

clean:
		rm -rf *.o ../bin/$(EXEC)
