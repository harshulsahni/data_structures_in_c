#include <stdio.h>
#include <assert.h> 
#include <string.h>
#include "bst.h"


int are_strings_equal(char *str1, char *str2, int max_tries) {
        int i = 0; 
        while (1) {
                if (i > max_tries) {
                        return 0; 
                }

                char c1 = str1[i]; 
                char c2 = str2[i]; 
                if (c1 == '\0' && c2 == '\0') {
                        return 1; 
                }
                if (c1 == '\0' || c2 == '\0') {
                        return 0; 
                }
                if (str1[i] != str2[i]) {
                        return 0; 
                }
                i++;
        }
}


void test_multiply_string() {
        char *str_to_mul = "hello"; 
        int len = strlen(str_to_mul); 

        // string times 1 is just the string again
        char actual_str[len + 1];
        multiply_string(str_to_mul, 1, actual_str); 
        assert(are_strings_equal(actual_str, str_to_mul, len+2)); 

        //string times 3 will be tripled
        char actual_str_2[len*3 + 1]; 
        multiply_string(str_to_mul, 3, actual_str_2); 
        assert(are_strings_equal(actual_str_2, "hellohellohello", len*3+2)); 


}


void run_tests() {
        test_multiply_string();
}


int main() {
        run_tests();
}
