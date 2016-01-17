#include <stdio.h>
#include <stdlib.h>
#include "get_code.h"
#include "make_code.h"
int main(int argc, const char * argv[]) {

    char code_arr[LETAMT][LETAMT];
    for (int i = 0; i < LETAMT; i++)
        code_arr[i][0] = '\0';
    char code[LETAMT];
    huff_list *list = read_f("test.txt");
    huff_tree *tree = make_tree(list);
    code_tree(tree, 0, code_arr, code);
    printf("%s %s %s ", code_arr[(int) 'a'], code_arr[(int) 'b'], code_arr[(int) ' ']);
    
    char tab[8];
    for (int i = 0; i < 8; i++)
        tab[i] = '1';
    int a = bin2dec(tab);
    printf("%d ", a);
    return 0;
}
