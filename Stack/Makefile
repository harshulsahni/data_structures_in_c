CC = gcc
GFLAGS=-Wall -g -I../LinkedList/
TARGET = stack

../LinkedList/linked_list: ../LinkedList/linked_list.c ../LinkedList/linked_list.h
	$(CC) $(CFLAGS) ../LinkedList/linked_list.c -o linked_list 

stack: stack.c stack.h ../LinkedList/linked_list.c ../LinkedList/linked_list.h
	$(CC) $(CFLAGS) $(TARGET).c ../LinkedList/linked_list.c -o $(TARGET)

clean: 
	rm -f $(OBJFILES) $(TARGET)
