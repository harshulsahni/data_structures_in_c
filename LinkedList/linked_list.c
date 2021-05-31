#include <assert.h>
#include <stdio.h> 
#include <stdlib.h>

struct LinkedList {
        int val; 
        struct LinkedList *next; 
};

struct LinkedList* make_linked_list(int v, struct LinkedList *n){
        struct LinkedList *output_ll = malloc(sizeof(struct LinkedList));
        assert(output_ll != NULL); 

        output_ll->val = v; 
        output_ll->next = n; 

        return output_ll; 
}

void destroy_linked_list(struct LinkedList *ll){ 
        assert(ll != NULL); 
        free(ll->next);
        free(ll); 
}

void print_linked_list(struct LinkedList *ll) {
        struct LinkedList *current_ll = ll;
        do {
                printf("%d -> ", current_ll->val); 
                current_ll = current_ll->next; 
        } while (current_ll != NULL);
        printf("END\n");
}


int main(int argc, char* argv[]){
        if (argc > 0){ 

        struct LinkedList *ll = make_linked_list(0, make_linked_list(1, make_linked_list(2, NULL))); 
        print_linked_list(ll); 
        destroy_linked_list(ll); 

        return 0; 
}


