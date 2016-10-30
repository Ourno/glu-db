
CC=g++

CFLAGS=-c -Wall -std=c++11

all: db
	 ./db.out
	 clear

db: common.o student.o main.o
	$(CC) common.o student.o main.o -o db.out

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

student.o: student.cpp
	$(CC) $(CFLAGS) student.cpp

common.o: common.cpp
	$(CC) $(CFLAGS) common.cpp

clean:
	rm -rf *.o db.out