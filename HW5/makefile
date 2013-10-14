OBJS = vector.o calculator.o
CC = g++
CFLAGS = -g -Wall

all : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o calc

vector.o : vector.h vector.cpp
	$(CC) $(CFLAGS) -c vector.cpp

calculator.o : linkedlist.h stack.h calculator.cpp vector.h
	$(CC) $(CFLAGS) -c calculator.cpp


.PHONY: clean

clean:
	-@rm *.o ant 2>/dev/null || true