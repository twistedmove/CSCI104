OBJS = comparison.o 
CC = g++
CFLAGS = -g -Wall

all : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o comp

comparison.o : comparison.cpp arraydouble.h arrayten.h arrayone.h arraylist.h linkedlist.h
	$(CC) $(CFLAGS) -c comparison.cpp


.PHONY: clean

clean:
	-@rm *.o ant 2>/dev/null || true