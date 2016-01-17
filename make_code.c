#include "make_code.h"
#include <stdio.h>
#include <stdlib.h>

int bin2dec (char code[])
{
    int sum = 0;
    int pow = 1;
    for (int i = 7; i >= 0; i--)
    {
        sum = sum + pow * ((int)(code[i] - '0'));
        pow *= 2;
    }
    return sum;
}

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
//--------------------------------------------------------test------------------------------------------------------------
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

void codecpy (char code_arr [LETAMT][LETAMT], char code[], int num, char sign)
{
    for (int i = 0; i < num; i++)
        code_arr[(int) sign][i] = code[i];
    code_arr[(int) sign][num] = '\0';
}

void code_tree (huff_tree *tree, int num, char code_arr [LETAMT][LETAMT], char code[])
{
    if (tree->left == NULL && tree->right == NULL)
        codecpy(code_arr, code, num, tree->elem->list_letter->sign);

    else
    {
        if (tree->left != NULL)
        {
            code[num] = '0';
            code_tree(tree->left, num + 1, code_arr, code);
        }
        if (tree->right != NULL)
        {
            code[num] = '1';
            code_tree(tree->right, num + 1, code_arr, code);
        }
    }

}
