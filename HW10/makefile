OBJS = main.o
CC = g++
CFLAGS = -g -Wall

all : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

main.o : hash.h hash.hpp main.cpp
	$(CC) $(CFLAGS) -c main.cpp


.PHONY: clean

clean:
	-@rm *.o ant 2>/dev/null || true