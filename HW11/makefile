OBJS = wallpostcomments.o wallpost.o wall.o user.o userlist.o social.o
CC = g++
CFLAGS = -g -Wall

all : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o social

wallpostcomments.o : wallpostcomments.h wallpostcomments.cpp
	$(CC) $(CFLAGS) -c wallpostcomments.cpp

wallpost.o : wallpost.h wallpost.cpp
	$(CC) $(CFLAGS) -c wallpost.cpp

wall.o : wall.h wallpost.h wall.cpp linklist.h priorityQ.h priorityQ.hpp arraydouble.h mergesort.h mergesort.hpp
	$(CC) $(CFLAGS) -c wall.cpp

user.o : user.h wall.h wallpost.h user.cpp
	$(CC) $(CFLAGS) -c user.cpp

mergesort.o : mergesort.h mergesort.hpp social.cpp
	$(CC) $(CFLAGS) -c social.cpp

userlist.o : userlist.h user.h linklist.h userlist.cpp
	$(CC) $(CFLAGS) -c userlist.cpp

social.o : social.cpp linklist.h user.h userlist.h wall.h wallpost.h
	$(CC) $(CFLAGS) -c social.cpp


.PHONY: clean

clean:
	-@rm *.o ant 2>/dev/null || true