#include <assert.h>
#include <stdio.h> 
#include <stdlib.h>

struct LinkedList {
        int val; 
        struct LinkedList *next;
        long size;  
};

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

void destroy_linked_list(struct LinkedList *ll){ 
        if(!ll) return;
        assert(ll); 
        struct LinkedList *temp_ll = ll;
        ll = ll->next; 
        free(temp_ll); 
        destroy_linked_list(ll);  
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
                destroy_linked_list(current_ll); 
        } else { 
            printf("No list was entered. The program will default to printing [0, 1, 2]:\n"); 

            struct LinkedList *ll = make_linked_list(0, make_linked_list(1, make_linked_list(2, NULL))); 
            print_linked_list(ll); 
            destroy_linked_list(ll); 
        }

        return 0; 
}


