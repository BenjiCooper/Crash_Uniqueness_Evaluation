CC = gcc

all: test_cmin_1 test_cmin_2

test_cmin_1: test_cmin_1.o
	$(CC) test_cmin_1.o -o test_cmin_1

test_cmin_2: test_cmin_2.o
	$(CC) test_cmin_2.o -o test_cmin_2

test_cmin_1.o: test_cmin_1.c
	$(CC) -c test_cmin_1.c

test_cmin_2.o: test_cmin_2.c
	$(CC) -c test_cmin_2.c

clean:
	rm -rf test_cmin_1
	rm -rf test_cmin_1.o
	rm -rf test_cmin_2
	rm -rf test_cmin_2.o
