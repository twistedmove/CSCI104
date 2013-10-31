OBJS = friends.o
CC = g++
CFLAGS = -g -Wall

all : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o friend

friends.o : friends.cpp
	$(CC) $(CFLAGS) -c friends.cpp


.PHONY: clean

clean:
	-@rm *.o ant 2>/dev/null || true