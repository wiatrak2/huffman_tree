#ifndef make_uncode_h
#define make_uncode_h
#include "get_uncode.h"
#include "lib.h"

void dec2bin (int val, char bin[]); //konwertowanie liczby typu int na ciąg binarny
void get_sign (list *num_list, uncode_tree *tree, int while_eof, const char *output_name); //odczytywanie kolejnych znaków z tekstu na podstawie kodów binarnych

#endif
