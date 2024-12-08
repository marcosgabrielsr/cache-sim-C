all: cache.o
	gcc cache.o main.c -o main -lm
	rm -rf *.o

cache.o: cache.h
	gcc -c cache.c

run:
	./main