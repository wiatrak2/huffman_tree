#ifndef make_code_h
#define make_code_h

#include "get_code.h"
#include "lib.h"

int bin2dec (char code[]);
huff_list *add_elem (huff_list *list, huff_tree *elem);
int add_val (huff_tree *tree);
huff_tree *make_tree (huff_list *list);
void code_tree (huff_tree *tree, int num, char code_arr[LETAMT][LETAMT], char code[]);

#endif
