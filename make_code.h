#ifndef make_code_h
#define make_code_h

#include "get_code.h"
#include "lib.h"

int bin2dec (char code[]); //konwertowanie tablicy z zapisem binarnym liczby na liczbę typu int
huff_list *add_elem (huff_list *list, huff_tree *elem); //dodawanie elementu w odpowiednie miejsce w liście
int add_val (huff_tree *tree); //aktualizacja wartości w drzewie
huff_tree *make_tree (huff_list *list); //tworzenie drzewa binarnego potrzebnego do wygenerowania kodów binarnych
void code_tree (huff_tree *tree, int num, char code_arr[LETAMT][LETAMT], char code[]); //generowanie kodów binarnych poszczególnych znaków
void text2code (const char *input_name, const char *output_name , char code_arr[LETAMT][LETAMT]); //kodowanie pliku

#endif
