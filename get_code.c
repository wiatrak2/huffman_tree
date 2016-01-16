#include "get_code.h"
#include "make_code.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare (const void *a, const void *b) //funkcja porównująca
{
    letter *a1 = *(struct letter**)a;
    letter *a2 = *(struct letter**)b;
    if (a1->amount == a2->amount)
        return 0;
    if (a1->amount < a2->amount)
        return -1;
    return 1;
}

huff_list *read_f (const char *input_name) //wczytywanie tekstu z pliku
{
    
    letter **array = malloc(LETAMT * sizeof(letter *));
    for (int i = 0; i < LETAMT; i++)
        array[i] = create_letter();
    
    FILE *input;
    input = fopen(input_name, "r");
    char let = '\0';
    int sum = 0;
    while (!feof(input))
    {
        let = fgetc(input);
        if ((int) let >= 0)
        {
            if (array[let]->amount == 0)
                sum++;
            array[let]->amount++;
            array[let]->sign = let;
        }
    }
    qsort(array, LETAMT, sizeof(letter *), compare); //sortowanie tablicy liter i ich wystąpień
    
    huff_list *list = create_huff_list();
    huff_list *start = list;
    
    for (int i = LETAMT - sum; i < LETAMT; i++) //tworzenie listy tylko z literami o niezerowych wystąpieniach
    {

        list->list_letter = array[i];
        list->val = list->list_letter->amount;
        if (i < LETAMT - 1)
            list->next = create_huff_list();
        list = list->next;
        
    }
    list = start;
   /*  -----------------------------------------------test---------------------------------------------------
    for (int i = 0; i < LETAMT - sum; i++)
        free(array[i]);
    
    huff_tree *dod = create_huff_tree();
    dod->val = 10;
    start = add_elem(list, dod);
  

    while (start->next != NULL)
    {
        printf("%d ", start->val);
        start = start->next;
    }
    printf("%d ", start->val);
    */
    fclose(input);
    return list;
}