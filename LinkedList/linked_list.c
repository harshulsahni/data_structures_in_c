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
        printf("LinkedList has size %lu.\n", ll->size); 

        struct LinkedList *current_ll = ll;
        do {
                printf("%d -> ", current_ll->val); 
                current_ll = current_ll->next; 
        } while (current_ll);

        printf("END\n");
}


int pop_linked_list(struct LinkedList **ll_address) {
        struct LinkedList *ll = *ll_address;
        if(!ll || !ll->next) {
                printf("Lists of sizes 1 or 0 cannot be popped.\n"); 
                exit(1); 
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


void destroy_linked_list(struct LinkedList *ll){ 
        if(!ll) return;
        assert(ll); 

        int dummy_val = 0; 
        while(ll->size > 1) {
            pop_linked_list(&ll); 
        }
        free(ll); 
}


int main(int argc, char* argv[]){
        if (argc > 1){ 
                int i = argc; 
                int val = 0;
                sscanf(argv[i - 1], "%d", &val); 

                struct LinkedList *current_ll = make_linked_list(val, NULL);
                i--; 
                while (i > 1){
                        sscanf(argv[i - 1], "%d", &val); 
                        current_ll = make_linked_list(val, current_ll); 
                        i--; 
                }
                print_linked_list(current_ll);

                struct LinkedList *temp_ll = current_ll;
                
                int first_element = pop_linked_list(&current_ll);
                printf("List after popping element %d:\n", first_element);
                print_linked_list(current_ll);

                printf("Get the index 2 of the list: %d\n", get_linked_list(current_ll, 2)); 


                destroy_linked_list(current_ll);
        } else { 
            printf("No list was entered. The program will default to printing [0, 1, 2]:\n"); 

            struct LinkedList *ll = make_linked_list(0, make_linked_list(1, make_linked_list(2, NULL))); 
            print_linked_list(ll); 
            destroy_linked_list(ll); 
        }

        return 0; 
}


