CC=gcc
CFLAGS=-W -Wall -g
OBJECTS = project3C.o project3C_hashtable.o

all: project3C
project3C: project3C.o $(OBJECTS)
	$(CC) $(CFLAGS) -o project3C $(OBJECTS)

project3C.o: project3C.c project3C_hashtable.h
project3C_hashtable.o: project3C_hashtable.c project3C_hashtable.h

clean:
	rm -f proj $(OBJECTS)



