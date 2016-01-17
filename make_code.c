#include "make_code.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void codetext (char code_arr [LETAMT][LETAMT], char code[], char sign)
{
    int index = 0;
    while (code[index] != '\0')
        index++;
    unsigned long int len = strlen(code_arr[(int) sign]);
    for (int i = index; i < index + len; i++)
        code[i] = code_arr[(int) sign][i - index];
    code[index + len] = '\0';
}

void move_code (char code[])
{
    unsigned long int len = strlen(code);
    if (len == 8)
        for (int i = 0; i < len; i++)
            code[i] = '\0';
    else
    {
        for (int i = 8; i <= len; i++)
           code[i - 8] = code[i];
    }
}

int final_num (char code[])
{
    int sum = 0;
    int pow = 1;
    unsigned long int len = strlen(code);
    for (unsigned long int i = 1; i <= len; i++)
    {
        sum = sum + pow * ((int)(code[len - i] - '0'));
        pow *= 2;
    }
    return sum;
}

void text2code (const char *input_name,const char *output_name, char code_arr[LETAMT][LETAMT])
{
    char code [LETAMT];
    for (int i  = 0; i < LETAMT; i++)
        code[i] = '\0';
    
    FILE *input;
    input = fopen(input_name, "r");
    FILE *output;
    output = fopen(output_name, "w");
    
    fprintf(output, "CODE:\n");
    char sign;
    while (!feof(input))
    {
        sign = fgetc(input);
        if ((int) sign >= 0)
            codetext(code_arr, code, sign);
        if (strlen(code) >= 8)
        {
            int coded = bin2dec(code);
            fprintf(output , "%d ", coded);
            move_code(code);
        }
    }
    
    unsigned long int while_eof = strlen(code);
    if (while_eof > 0)
    {
        int coded = final_num(code);
        fprintf(output, "%d ", coded);
    }
    
    fprintf(output, "\nwhile_eof = %lu\n", while_eof);
    fprintf(output, "TREE:\n");
    
    for (int i = 0; i < LETAMT; i++)
        if (code_arr[i][0] != '\0')
        {
            if ((char) i == ' ')
            {
                fprintf(output, "' ' - %s\n", code_arr[i]);
                continue;
            }
            if ((char) i == '\n')
            {
                fprintf(output, "'\n' - %s\n", code_arr[i]);
                continue;
            }
            fprintf(output, "%c - %s\n", (char) i, code_arr[i]);
        }
    
    fclose(input);
    fclose(output);
  
}
