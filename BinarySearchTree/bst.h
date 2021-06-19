#ifndef BST_H_SEEN
#define BST_H_SEEN


struct BSTNode {
        int val; 
        struct BSTNode *left; 
        struct BSTNode *right; 
        int count; 
};


struct BST {
        struct BSTNode *head; 
        int size; 
};


void multiply_string(char *str, int i, char *result); 
struct BST *make_bst(); 
void insert_into_bst(struct BST *bst, int val_to_insert); 
void print_bst_node(struct BSTNode *bst_node, int indentation); 
void print_bst(struct BST *bst);
int get_tree_depth(struct BST *bst);
void delete_bst(struct BST *bst);

#endif
