#include "make_uncode.h"
#include <stdio.h>
#include <stdlib.h>

void dec2bin (int val, char bin[])
{
    for (int i = 7; i >= 0; i--)
    {
        int num = val % 2;
        bin[i] = num + '0';
        val /= 2;
    }
}

void get_sign (list *num_list, uncode_tree *tree, int while_eof, const char *output_name)
{
    FILE *output;
    output = fopen(output_name, "w");
    
    char bin [8];
    bin [0] = '\0';
    uncode_tree *start = tree;
    while (num_list->next != NULL)
    {
        int val = num_list->val;
        dec2bin(val, bin);
        for (int i = 0; i < 8; i++)
        {
            if (bin[i] == '0')
                tree = tree->left;
            else
                tree = tree->right;
            if (tree->sign != '\0')
            {
                fprintf(output, "%c", tree->sign);
                tree = start;
            }
        }
        num_list = num_list->next;
    }
    
    int val = num_list->val;
    dec2bin(val, bin);
    int amt;
    if (while_eof == 0)
        amt = 0;
    else
        amt = 8 - while_eof;
    for (int i = amt; i < 8; i++)
    {
        if (bin[i] == '0')
            tree = tree->left;
        else
            tree = tree->right;
        if (tree->sign != '\0')
        {
            fprintf(output, "%c", tree->sign);
            tree = start;
        }
    }
    

    fclose (output);
}