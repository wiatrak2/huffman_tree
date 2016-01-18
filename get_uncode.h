#ifndef get_uncode_h
#define get_uncode_h

#include "lib.h"

uncode_tree *create_path (char code[], uncode_tree *node, char sign); //tworzenie ścieżek drzewa binarnego na podstawie kodów liter
uncode_tree *get_tree (const char *input_name); //tworzenie drzewa do odkodowania pliku
list *numbers (const char *input_name); //uzyskiwanie liczb - kodu pliku tekstowego
int get_while_eof (const char *input_name); //uzyskiwanie liczby while_eof odpowiadającej za ilość znaczących bitów w ostatniej liczbie

#endif
