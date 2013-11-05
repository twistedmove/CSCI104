OBJS = priorityQ.o tree.o
CC = g++
CFLAGS = -g -Wall

all : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o tree

priorityQ.o : priorityQ.h priorityQ.cpp arraydouble.h
	$(CC) $(CFLAGS) -c priorityQ.cpp

tree.o : priorityQ.h priorityQ.cpp tree.cpp
	$(CC) $(CFLAGS) -c tree.cpp

.PHONY: clean

clean:
	-@rm *.o ant 2>/dev/null || true