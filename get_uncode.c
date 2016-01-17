#include "get_uncode.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

uncode_tree *create_path (char code[], uncode_tree *node, char sign)
{
    uncode_tree *start = node;
    unsigned long int len = strlen(code);
    
    for (int i = 0; i < len; i++)
    {
        if (code[i] == '0')
        {
            if (node->left == NULL)
                node->left = create_uncode_tree();
            node = node->left;
        }
        else
        {
            if (node->right == NULL)
                node->right = create_uncode_tree();
            node = node->right;
        }
    }
    node->sign = sign;
 //   printf("%c ", node->sign);
    return start;
}

uncode_tree *get_tree (const char *input_name)
{
    FILE *input;
    input = fopen(input_name, "r");
    
    uncode_tree *tree = create_uncode_tree();
    char word [LETAMT];
    while (strcmp(word, "TREE:") != 0)
        fscanf(input, "%s", word);
    
    char sign = fgetc(input);
    uncode_tree *node = tree;
    
    char code_sign[LETAMT];
    char get_sign [3];
    
    while (!feof(input))
    {
        fscanf(input, "%s", get_sign);
        if (strcmp(get_sign, "'") == 0)
            sign = ' ';
        else if (strcmp(get_sign, "'\n'") == 0)
            sign = '\n';
        else
            sign = get_sign[0];
       
        char anc = '\0';
        while (anc != '-' && !feof(input))
            anc = fgetc(input);
    
        fscanf(input, "%s\n", code_sign);
        
        node = create_path(code_sign, node, sign);
        if (feof(input))
            break;
    }
    return tree;
}