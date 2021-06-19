CC=gcc
GFLAGS=-Wall -g

bst: bst.h bst.c main.c
	$(CC) $(GFLAGS) bst.c main.c -o bst

tests: bst.h bst.c tests.c
	$(CC) $(GFLAGS) bst.c tests.c -o tests


clean: 
	rm -f $(OBJFILES) bst
