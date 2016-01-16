#ifndef make_code_h
#define make_code_h

#include "get_code.h"

huff_list *add_elem (huff_list *list, huff_tree *elem);
int add_val (huff_tree *tree);
huff_tree *make_node (huff_list *list);
huff_tree *make_tree (huff_list *list);

#endif
