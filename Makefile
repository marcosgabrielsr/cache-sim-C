all: cache.o address_op.o
	clang cache.o address_op.o main.c -o main -lm
	rm -rf *.o

cache.o: cache.h
	clang -c cache.c

address_op.o: cache.c
	clang -c address_op.c

clean:
	rm -rf *.o

run:
	./main
