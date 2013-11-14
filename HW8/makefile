OBJS = wallpostcomments.o wallpost.o wall.o mergesort.o user.o userlist.o social.o
CC = g++
CFLAGS = -g -Wall

all : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o social

wallpostcomments.o : wallpostcomments.h wallpostcomments.cpp
	$(CC) $(CFLAGS) -c wallpostcomments.cpp

wallpost.o : wallpost.h wallpost.cpp
	$(CC) $(CFLAGS) -c wallpost.cpp

wall.o : wall.h wallpost.h wall.cpp linklist.h
	$(CC) $(CFLAGS) -c wall.cpp

mergesort.o : sorting.h mergesort.h mergesort.cpp
	$(CC) $(CFLAGS) -c mergesort.cpp

user.o : user.h wall.h wallpost.h user.cpp
	$(CC) $(CFLAGS) -c user.cpp

userlist.o : userlist.h user.h linklist.h userlist.cpp
	$(CC) $(CFLAGS) -c userlist.cpp

social.o : social.cpp linklist.h user.h userlist.h wall.h wallpost.h
	$(CC) $(CFLAGS) -c social.cpp


.PHONY: clean

clean:
	-@rm *.o ant 2>/dev/null || true