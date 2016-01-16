#include "make_code.h"
#include <stdio.h>
#include <stdlib.h>

huff_list *add_elem (huff_list *list, huff_tree *elem) //dodawanie nowo powstałej struktury huff_tree w odpowiednie miejsce
{
    huff_list *new_elem = create_huff_list();
    if (list->val >= elem->val)
    {
        new_elem->node = elem;
        new_elem->next = list;
        new_elem->val = elem->val;
        return new_elem;
    }
    huff_list *start = list;
    while (list->val < elem->val)
    {
        if (list->next->next == NULL)
        {
            list->next->next = create_huff_list();
            list->next->next->node = elem;
            list->next->next->val = elem->val;
            return start;
        }
        list = list->next;
    }
    new_elem->node = elem;
    new_elem->next = list->next;
    new_elem->val = elem->val;
    list->next = new_elem;
    return start;
    
}

huff_tree *make_node (huff_list *list)
{
    huff_tree *node = create_huff_tree();
    node->left = create_huff_tree();
    node->right = create_huff_tree();
    node->left->elem = list;
    list = list->next;
    node->right->elem = list;
    list = list->next;
    node->val = node->left->elem->val + node->right->elem->val;
    
    return node;
}

int add_val (huff_tree *tree)
{
    if (tree->left->val != 0 && tree->right->val != 0)
        return tree->left->val + tree->right->val;
    if (tree->left->val != 0 && tree->right->val == 0)
        return tree->left->val + tree->right->elem->val;
    if (tree->left->val == 0 && tree->right->val != 0)
        return tree->left->elem->val + tree->right->val;
    return tree->left->elem->val + tree->right->elem->val;

}

huff_tree *make_tree (huff_list *list)
{
    huff_list *start = list;
    
    while (list != NULL)
    {
        huff_tree *node = create_huff_tree();
        node->left = create_huff_tree();
        node->right = create_huff_tree();
        node->left->elem = list;
        
        if (node->left->elem->node != NULL)
            node->left = node->left->elem->node;
        
        list = list->next;
        node->right->elem = list;
        
        if (node->right->elem->node != NULL)
            node->right = node->right->elem->node;
  
        list = list->next;
        node->val = add_val(node);
        huff_list *add = start;
        add_elem(add, node);
    }
    
    list = start;
    while (list->next != NULL)
        list = list->next;
    
    huff_tree *root = list->node;
  //  printf("%d ", list->node->val);
    /*
    while (start->next != NULL)
    {
        printf("%d ", start->val);
        start = start->next;
    }
    printf("%d ", start->val);
    */
    
    return root;
}