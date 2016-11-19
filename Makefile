
CC=g++

CFLAGS=-c -Wall -std=c++11 -g

all: db

test: cleantest ./obj/validation.o ./test/test.cpp
	$(CC) ./test/test.cpp ./obj/validation.o -o ./test/test.out -lcheck -pthread -lrt
	./test/test.out

db: ./obj/common.o ./obj/student.o ./obj/main.o ./obj/validation.o
	$(CC) obj/common.o obj/student.o obj/main.o obj/validation.o -o bin/db.out

./obj/main.o: ./src/main.cpp
	$(CC) $(CFLAGS) ./src/main.cpp -o ./obj/main.o

./obj/validation.o: ./src/validation.cpp
	$(CC) $(CFLAGS) ./src/validation.cpp -o ./obj/validation.o

./obj/student.o: ./src/student.cpp
	$(CC) $(CFLAGS) ./src/student.cpp -o ./obj/student.o

./obj/common.o: ./src/common.cpp
	$(CC) $(CFLAGS) ./src/common.cpp -o ./obj/common.o

cleantest:
	rm -rf ./test/*.out

clean:
	rm -rf ./obj/*.o ./bin/db.out