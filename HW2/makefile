# valgrind --tool=memcheck ./memory
CC = g++
CFLAGS  = -c -Wall
FLAGS = 

all: energy linked linkedlist

energy: energy.cpp
	${CC} energy.cpp -o $@ ${CPPFLAGS}

linked: linked.cpp
	${CC} linked.cpp -o $@ ${CPPFLAGS}

linkedlist: linkedlist.cpp
	${CC} linkedlist.cpp -o $@ ${CPPFLAGS}

.PHONY: clean

clean:
	-@rm *.o ant 2>/dev/null || true