all: operations.h operations.o main.o
	gcc -o main operations.o main.o

main.o: operations.h main.c
	gcc -c main.c

operations.o: operations.h operations.c
	gcc -c operations.c

run: main
	./main

clean:
	rm -f *.o main data.txt
