#ifndef lib_h
#define lib_h
typedef struct letter{
    char sign;
    int amount;
}letter;

typedef struct huff_tree{
    int val;
    struct huff_list *elem;
    struct huff_tree *left;
    struct huff_tree *right;
}huff_tree;

typedef struct huff_list{
    int val;
    letter *list_letter;
    struct huff_tree *node;
    struct huff_list *next;
}huff_list;

letter *create_letter (void);
huff_tree *create_huff_tree (void);
huff_list *create_huff_list (void);

#endif
