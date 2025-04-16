all: cache.o
	clang cache.o main.c -o main -lm
	rm -rf *.o

cache.o: cache.h
	clang -c cache.c

clean:
	rm -rf *.o

run:
	./main
