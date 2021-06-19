#include <stdio.h> 
#include "bst.h" 


int main() {
        struct BST *bst = make_bst(); 
        insert_into_bst(bst, 3);
        insert_into_bst(bst, 7); 
        insert_into_bst(bst, 5); 
        insert_into_bst(bst, 1);
        insert_into_bst(bst, -1);   
        print_bst(bst); 
        printf("The depth of this tree is %d\n", get_tree_depth(bst));
        delete_bst(bst); 
        return 0; 
}
