#include "get_code.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare (const void *a, const void *b) //funkcja porównująca
{
    letter a1 = *(struct letter*)a;
    letter a2 = *(struct letter*)b;
    if (a1.amount == a2.amount)
        return 0;
    if (a1.amount < a2.amount)
        return -1;
    return 1;
}

huff_list* add_elem (huff_list *list, letter *elem) //dodawanie nowo powstałej struktury letter w odpowiednie miejsce w liście
{
    huff_list *new_elem = malloc(sizeof(huff_list));
    if (list->list_letter->amount > elem->amount)
    {
        new_elem->list_letter = elem;
        new_elem->next = list;
        return new_elem;
    }
    huff_list *start = list;
    while (list->next->list_letter->amount < elem->amount)
    {
        if (list->next->next == NULL)
        {
            list->next->next = malloc(sizeof(huff_list));
            list->next->next->list_letter = elem;
            return start;
        }
        list = list->next;
    }
    new_elem->list_letter = elem;
    new_elem->next = list->next;
    list->next = new_elem;
    return start;
    
}

letter *read_f (const char *input_name) //wczytywanie tekstu z pliku
{
    letter *array = malloc(LETAMT * sizeof(letter));
   
   /*
    letter *array [LETAMT];
    for (int i = 0; i < LETAMT; i++)
        array[i] = malloc(sizeof(letter)); */
    FILE *input;
    input = fopen(input_name, "r");
    char let = '\0';
    
    
    int sum = 0;
    while (!feof(input))
    {
        let = fgetc(input);
        if (array[let].amount == 0)
            sum++;
        array[let].amount++;
        array[let].sign = let;
        
    }
    sum--;
    qsort(array, LETAMT, sizeof(letter), compare); //sortowanie tablicy liter i ich wystąpień
    
    huff_list *list = malloc(sizeof(huff_list));
    huff_list *start = list;
    
    letter **final_arr = malloc(sum * sizeof(letter*));
    for (int i = 0; i < sum; i++)
        final_arr[i] = malloc(sizeof(letter));
    
    for (int i = LETAMT - sum; i < LETAMT; i++) //tworzenie tablicy tylko z literami o niezerowych wystąpieniach
    {
        final_arr[i - LETAMT + sum]->amount = array[i].amount;
        final_arr[i - LETAMT + sum]->sign = array[i].sign;
        list->list_letter = final_arr[i - LETAMT + sum];
        list->next = malloc(sizeof(huff_list));
        list = list->next;
        
    }
    list = start;
    free(array);
    
    letter *dod = malloc(sizeof(letter));
    dod->amount = 1;
    start = add_elem(list, dod);

    while (start->next != NULL)
    {
        printf("%d ", start->list_letter->amount);
        start = start->next;
    }
   
    
    fclose(input);
    return *final_arr;
}