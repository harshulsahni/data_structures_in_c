#include <stdio.h> 
#include <stdlib.h>
#include <string.h> 
#include "bst.h"


struct BSTNode *make_bst_node(int val, struct BSTNode *left, struct BSTNode *right) {
        struct BSTNode *bst_node = malloc(sizeof(struct BSTNode)); 
        bst_node->left = left; 
        bst_node->right = right; 
        bst_node->val = val; 
        bst_node->count = 1; 

        return bst_node; 
}


struct BST *make_bst() {
        struct BST *bst = malloc(sizeof(struct BST)); 
        bst->head = NULL; 
        bst->size = 0; 

        return bst; 
}


int is_val_in_bst_node(struct BSTNode *bst_node, int val_to_check) {
        if (!bst_node) return 0; 
        
        int head_val = bst_node->val; 

        if (head_val == val_to_check) {
                return 1; 
        } else if (head_val > val_to_check) {
                return is_val_in_bst_node(bst_node->left, val_to_check); 
        } else {
                return is_val_in_bst_node(bst_node->right, val_to_check); 
        }
}


int is_val_in_bst(struct BST *bst, int val_to_check) {
        return is_val_in_bst_node(bst->head, val_to_check); 
}


struct BSTNode *insert_into_bst_node(struct BSTNode *bst_node, int val_to_insert) {
        if (!bst_node) {
                return make_bst_node(val_to_insert, NULL, NULL); 
        }

        if (bst_node->val == val_to_insert) {
                bst_node->count++; 
                return bst_node; 
        } else if (bst_node->val > val_to_insert) {
                bst_node->left = insert_into_bst_node(bst_node->left, val_to_insert); 
                return bst_node; 
        } else {
                bst_node->right = insert_into_bst_node(bst_node->right, val_to_insert); 
                return bst_node; 
        }
}


void insert_into_bst(struct BST *bst, int val_to_insert) {
        bst->head = insert_into_bst_node(bst->head, val_to_insert); 
        bst->size++; 
}


int find_num_digits(int i) {
        int num_digits = 1; 
        while (i >= 10) {
                num_digits += 1; 
                i = (int) (i / 10); 
        }
        return num_digits; 
}


int represent_bst_node_len(struct BSTNode *bst_node) {
        if (!bst_node) return 5;
        return find_num_digits(bst_node->count) + find_num_digits(bst_node->val) + 4;
}
        

void represent_bst_node(struct BSTNode *bst_node, char *output) {
        if (!bst_node) {
                sprintf(output, "%s", "NULL"); 
                return;
        }

        sprintf(output, "%d (%d)", bst_node->val, bst_node->count);  
}


void multiply_string(char *str, int i, char *result) {
        int str_len = strlen(str);
        for (int j = 0; j < str_len * i; j++) {
                result[j] = str[j % str_len]; 
        }
        result[str_len * i] = '\0'; 
}


int max(int i1, int i2) {
        if (i1 > i2) {
                return i1; 
        } else {
                return i2; 
        }
}


int get_tree_depth_helper(struct BSTNode *bst_node, int depth) {
        if (!bst_node) {
                return depth; 
        }
        return max(get_tree_depth_helper(bst_node->right, depth+1), get_tree_depth_helper(bst_node->left, depth+1)); 
}


int get_tree_depth(struct BST *bst) {
        return get_tree_depth_helper(bst->head, 0);
}


void print_bst_node(struct BSTNode *bst_node, int indentation) {
        if (!bst_node) return; 
        char indent_str[indentation+1];
        char bst_node_str[represent_bst_node_len(bst_node)]; 
        multiply_string(" ", indentation, indent_str);
        represent_bst_node(bst_node, bst_node_str); 


        printf("%s%s\n", indent_str, bst_node_str);
        if (bst_node->left) {
                if (bst_node->right) {
                        printf("├──"); 
                        print_bst_node(bst_node->left, indentation+4);
                        printf("└──"); 
                        print_bst_node(bst_node->right, indentation+4);
                } else {
                        printf("└──"); 
                        print_bst_node(bst_node->left, indentation+4);
                }
        } else if (bst_node->right) {
                printf("└──"); 
                print_bst_node(bst_node->right, indentation+4);
        } else {
                return;
        }

}


void print_bst(struct BST *bst) {
        print_bst_node(bst->head, 0); 
}


void delete_bst_node(struct BSTNode *bst_node) {
        if (!bst_node) return;
        delete_bst_node(bst_node->right); 
        delete_bst_node(bst_node->left); 
        bst_node->right = NULL; 
        bst_node->left = NULL; 
        free(bst_node); 
}


void delete_bst(struct BST *bst) {
        delete_bst_node(bst->head); 
        bst->head = NULL; 
        free(bst);
}

