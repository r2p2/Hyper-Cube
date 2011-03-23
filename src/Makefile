EXEC=hyper-cube

CC=g++
CFLAGS=-c -O3 -Wall
LDFLAGS=-lcurses
SOURCES=$(wildcard *.cpp)
OBJS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJS)
		$(CC) $(LDFLAGS) $(OBJS) -o ../bin/$@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@

clean:
		rm -rf *.o ../bin/$(EXEC)
