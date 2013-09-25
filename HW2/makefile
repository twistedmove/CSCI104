# valgrind --tool=memcheck ./memory
CC = g++
CFLAGS  = -c -Wall
FLAGS = 

all: energy

ant: energy.cpp
		${CC} energy.cpp -o $@ ${CPPFLAGS}

.PHONY: clean

clean:
		-@rm *.o ant 2>/dev/null || true