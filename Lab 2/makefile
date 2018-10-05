CFLAGS:= -std=c99
cipher: cipher.o
	gcc cipher.o -o cipher -std=c99
cipher.o: cipher.c

test: test1 test2 test3 test4 test5 test6
test1:
	./cipher 1 5 data.txt data.out
test2:
	./cipher 2 5 data.out data.bak
test3:
	./cipher 1 437 data.txt multiEncrypt.out
test4:
	./cipher 2 437 multiEncrypt.out multiEncrypt.bak
test5:
	diff -s data.txt data.bak
test6:
	diff -s data.txt multiEncrypt.bak
