EXEC=hyper-cube

CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lcurses
SOURCES=$(wildcard *.cpp)
OBJS=$(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJS)
		$(CC) $(LDFLAGS) $(OBJS) -o $@

.cpp.o:
		$(CC) $(CFLAGS) $< -o $@

clean:
		rm -rf *.o $(EXEC)
