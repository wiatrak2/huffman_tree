#ifndef get_code_h
#define get_code_h

#include "lib.h"
#define LETAMT 128

letter *read_f (const char *input_name);
int compare (const void *a, const void *b);
huff_list* add_elem (huff_list *list, letter *elem);

#endif
