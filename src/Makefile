EXEC=hyper-cube

CC=g++
CFLAGS=-c -O3 -Wall -g -pg
LDFLAGS=-lcurses -g -pg
SOURCES=$(wildcard *.cpp)
OBJS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJS)
		$(CC) -o ../bin/$@ $(OBJS) $(LDFLAGS)

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@

clean:
		rm -rf *.o ../bin/$(EXEC)
