CC = gcc
GFLAGS=-Wall -g

linked_list: linked_list.c linked_list.h main.c
	$(CC) $(GFLAGS) linked_list.c main.c -o linked_list

clean: 
	rm $(objects) linked_list
