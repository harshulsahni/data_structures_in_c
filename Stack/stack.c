#ifndef STACK_SEEN 
#define STACK_SEEN

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


struct Stack *make_stack(struct LinkedList *list) {
    struct Stack *stack = malloc(sizeof(struct Stack)); 
    stack->list = list; 
    return stack; 
}


int get_stack_size(struct Stack *stack) {
    if (stack->list) {
        return stack->list->size; 
    } else {
        return 0;
    }
}


int is_stack_empty(struct Stack *stack) {
    return get_stack_size(stack) == 0; 
}


void push_to_stack(struct Stack *stack, int element_to_push){ 
    stack->list = push_to_linked_list(stack->list, element_to_push); 
}


int pop_stack(struct Stack *stack){ 
    if (get_stack_size(stack) < 1) {
        printf("Stacks of size 0 cannot be popped.\n"); 
        exit(1); 
    }

    return pop_linked_list(&(stack->list)); 
}


void destroy_stack(struct Stack *stack) {
    struct LinkedList *temp_ll = stack->list; 
    stack->list = NULL; 
    destroy_linked_list(temp_ll); 
    free(stack); 
}


void print_stack(struct Stack *stack) {
    print_linked_list(stack->list); 
}


#endif
