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
    node = start;
    return node;
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
    char get_sign [5];
    
    while (!feof(input))
    {
        fscanf(input, "%s", get_sign);
        if (strcmp(get_sign, "'") == 0 && strcmp(get_sign, "'\n'") != 0)
            sign = ' ';
        else if (strcmp(get_sign, "'\\n'") == 0)
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
    
    fclose(input);
    return tree;
}

list *numbers (const char *input_name)
{
    list *num_list = create_list();
    list *start = num_list;
    FILE *input;
    input = fopen(input_name, "r");
    char code_text [10];
    fscanf(input, "%s\n", code_text);
    char sign = '\0';
    while (sign != '\n' && sign != 'w')
    {
        fscanf(input, "%d", &num_list->val);
        num_list->next = create_list();
        num_list = num_list->next;
        sign = getc(input);
    }
    num_list = start;
    while (num_list->next->val != 0)
        num_list = num_list->next;
    num_list->next = NULL;
    num_list = start;
    
    fclose(input);
    return num_list;
}

int get_while_eof (const char *input_name)
{
    int while_eof;
    FILE *input;
    input = fopen(input_name, "r");
    char sign = '\0';
    while (sign != '=')
        sign = fgetc(input);
    fscanf(input, "%d", &while_eof);
    
    fclose(input);
    return while_eof;
}