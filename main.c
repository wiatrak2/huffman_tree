#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#include "get_code.h"
#include "make_code.h"
#include "get_uncode.h"
#include "make_uncode.h"
int main(int argc, const char * argv[]) {

    if (strcmp (argv[1], "k") == 0)
    {
        char code_arr[LETAMT][LETAMT];
        for (int i = 0; i < LETAMT; i++)
            code_arr[i][0] = '\0';
        char code[LETAMT];
        huff_list *h_list = read_f(argv[2]);
        huff_tree *tree = make_tree(h_list);
        code_tree(tree, 0, code_arr, code);
        text2code(argv[2], argv[3], code_arr);
    }
    else
    {
        uncode_tree *un_tree = get_tree(argv[2]);
        list *num_list = numbers(argv[2]);
        int while_eof = get_while_eof(argv[2]);
        get_sign(num_list, un_tree, while_eof, argv[3]);
    }

    return 0;
}
