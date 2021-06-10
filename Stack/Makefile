CC = gcc
GFLAGS=-Wall -g

stack: stack.c stack.h ../LinkedList/linked_list.c ../LinkedList/linked_list.h
	$(CC) $(GFLAGS) stack.c main.c ../LinkedList/linked_list.c -o stack

clean: 
	rm -f $(OBJFILES) stack
