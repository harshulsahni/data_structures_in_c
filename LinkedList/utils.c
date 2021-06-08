#include "linked_list.h"

void change_pointer(struct LinkedList **ptr_address, struct LinkedList *ptr_to_point_to){ 
    *ptr_address = ptr_to_point_to; 
}
