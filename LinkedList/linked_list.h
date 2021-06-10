#ifndef LINKED_LIST_H_SEEN
#define LINKED_LIST_H_SEEN
struct LinkedList {
    int val; 
    struct LinkedList *next; 
    int size;
};

struct LinkedList *make_linked_list(int v, struct LinkedList *n);

struct LinkedList *push_to_linked_list(struct LinkedList *ll, int num_to_push);

int get_linked_list(struct LinkedList *ll, int idx);

int pop_linked_list(struct LinkedList **ll_address);

void destroy_linked_list(struct LinkedList *ll); 

void print_linked_list(struct LinkedList *ll); 

#endif

