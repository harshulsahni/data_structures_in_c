#include <stdio.h>
#include "stack.h"

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
    printf("Popping off elements %d and %d.\n", pop_stack(s), pop_stack(s));

    printf("Stack looks like this: ");
    print_stack(s);

    printf("Pushing 3 and then 5 to stack.\n");
    push_to_stack(s, 3);
    push_to_stack(s, 5);

    printf("Stack looks like this: ");
    print_stack(s);

    destroy_stack(s);

    return 0;
}