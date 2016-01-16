#include "lib.h"
#include <stdlib.h>
#include <stdio.h>

letter *create_letter (void)
{
    letter *new_letter = malloc(sizeof(letter));
    new_letter->amount = 0;
    new_letter->sign = '\0';
    return new_letter;
}

huff_tree *create_huff_tree (void)
{
    huff_tree *new_tree = malloc(sizeof(huff_tree));
    new_tree->left = NULL;
    new_tree->right = NULL;
    new_tree->val = 0;
    new_tree->elem = NULL;
    return new_tree;
}

huff_list *create_huff_list (void)
{
    huff_list *new_list = malloc(sizeof(huff_list));
    new_list->val = 0;
    new_list->list_letter = NULL;
    new_list->next = NULL;
    new_list->node = NULL;
    return new_list;
}