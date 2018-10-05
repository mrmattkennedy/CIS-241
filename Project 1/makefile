CFLAGS:= -std=c99
all: functions.h functions.o p1.o
	gcc -o p functions.o p1.o -std=c99

p1.o: functions.h p1.c
	gcc -c p1.c -std=c99

functions.o: functions.h functions.c
	gcc -c functions.c -std=c99

test: enc, dec, tests, clean
enc: 
	./p e GOODMORNING data cipher

dec: 
	./p d GOODMORNING cipher ddata

tests:
	./p e GOODMORNING data cipher
	./p d GOODMORNING cipher ddata
	diff -s data ddata

clean:
	rm -f *.o p cipher ddata
