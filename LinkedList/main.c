#include <stdio.h>
#include "linked_list.h"

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