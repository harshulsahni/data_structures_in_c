#ifndef LINKED_LIST_SEEN
#define LINKED_LIST_SEEN

#include <assert.h>
#include <stdio.h> 
#include <stdlib.h>
#include "linked_list.h"

struct LinkedList *make_linked_list(int v, struct LinkedList *n){
        struct LinkedList *output_ll = malloc(sizeof(struct LinkedList));
        assert(output_ll); 

        output_ll->val = v; 
        output_ll->next = n; 
        if (!n){ 
                output_ll->size = 1; 
        } else {
                output_ll->size = n->size + 1; 
        }

        return output_ll; 
}


void print_linked_list(struct LinkedList *ll) {
        struct LinkedList *current_ll = ll;
        while (current_ll) {
            printf("%d -> ", current_ll->val); 
            current_ll = current_ll->next; 

        }
        printf("NULL\n");
}


int pop_linked_list(struct LinkedList **ll_address) {
        struct LinkedList *ll = *ll_address;
        if(!ll) {
            printf("Lists of size 0 cannot be popped.\n"); 
            exit(1); 
        }
        if (ll->size == 1) {
            int val = ll->val;
            *ll_address = NULL;  
            free(ll); 
            return val; 
        }

        int val = ll->val;
        struct LinkedList *next_ll = ll->next; 
        ll->next = next_ll->next; 
        ll->val = next_ll->val; 
        ll->size = next_ll->size;  

        next_ll->next = NULL; 
        free(next_ll); 

        return val; 
}


int peek_linked_list(struct LinkedList *ll) {
    return ll->val; 
}


int get_linked_list(struct LinkedList *ll, int idx) {
    if (!ll) {
            printf("The LinkedList is empty. The get_linked_list() function cannot return anything.\n"); 
            exit(1); 
    }

    if (idx < 0) {
        idx = ll->size + idx;
    }

    idx %= ll->size; 

    struct LinkedList *temp_ll = ll; 

    while (idx != 0) {
        temp_ll = temp_ll->next; 
        idx--;
    }

    return temp_ll->val;
}


struct LinkedList *push_to_linked_list(struct LinkedList *ll, int num_to_push) {
    return make_linked_list(num_to_push, ll); 
}


void destroy_linked_list(struct LinkedList *ll) {
    if (!ll) return;

    while (ll) {
        pop_linked_list(&ll);
    }
}


#endif
