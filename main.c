#include <stdio.h>
#include <stdlib.h>
#include "get_code.h"
#include "make_code.h"
#include "get_uncode.h"
int main(int argc, const char * argv[]) {

    char code_arr[LETAMT][LETAMT];
    for (int i = 0; i < LETAMT; i++)
        code_arr[i][0] = '\0';
    char code[LETAMT];
    huff_list *list = read_f("test.txt");
    huff_tree *tree = make_tree(list);
    code_tree(tree, 0, code_arr, code);
    text2code("test.txt", "wy.txt", code_arr);
    get_tree("wy.txt");
    return 0;
}
