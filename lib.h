#ifndef lib_h
#define lib_h
typedef struct letter{
    char sign;
    int amount;
}letter;

typedef struct huff_tree{
    letter *val;
    struct huff_tree *left;
    struct huff_tree *right;
}tree;

typedef struct huff_list{
    letter *list_letter;
    struct huff_list *next;
}huff_list;


#endif
