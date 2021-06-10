#ifndef STACK_H_SEEN
#define STACK_H_SEEN
#include "../LinkedList/linked_list.h"

struct Stack {
    int size; 
    struct LinkedList *list; 
};

#endif
