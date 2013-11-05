OBJS = tree.o
CC = g++
CFLAGS = -g -Wall

all : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o tree

tree.o : priorityQ.h priorityQ.hpp tree.cpp
	$(CC) $(CFLAGS) -c tree.cpp

.PHONY: clean

clean:
	-@rm *.o ant 2>/dev/null || true