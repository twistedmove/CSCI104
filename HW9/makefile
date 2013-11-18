OBJS = main.o
CC = g++
CFLAGS = -g -Wall

all : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o main

quicksort.o : quicksort.h quicksort.hpp
	$(CC) $(CFLAGS) -c quicksort.hpp

main.o : quicksort.h quicksort.hpp main.cpp
	$(CC) $(CFLAGS) -c main.cpp


.PHONY: clean

clean:
	-@rm *.o ant 2>/dev/null || true