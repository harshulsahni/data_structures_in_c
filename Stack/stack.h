#ifndef STACK_H_SEEN
#define STACK_H_SEEN
#include "../LinkedList/linked_list.h"

struct Stack {
    struct LinkedList *list; 
};

void print_stack(struct Stack *stack);

void push_to_stack(struct Stack *stack, int element_to_push);

struct Stack *make_stack(struct LinkedList *list);

void destroy_stack(struct Stack *stack);

int pop_stack(struct Stack *stack);

#endif
