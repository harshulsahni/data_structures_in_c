#ifndef STACK_SEEN 
#define STACK_SEEN

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "../LinkedList/linked_list.h"

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


int main(int argc, char *argv[]) {
    struct Stack *s = make_stack(NULL); 
    printf("Initial stack: "); 
    print_stack(s); 
    printf("Going to add 1, 2, 3 to stack.\n"); 

    push_to_stack(s, 1); 
    push_to_stack(s, 2); 
    push_to_stack(s, 3); 

    printf("Stack looks like this: "); 
    print_stack(s); 
    printf("Popping off elements %d and %d\n", pop_stack(s), pop_stack(s)); 
    
    printf("Stack looks like this: "); 
    print_stack(s); 
    
    destroy_stack(s);

    return 0; 
}


#endif
