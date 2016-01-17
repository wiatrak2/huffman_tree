#ifndef lib_h
#define lib_h
#define LETAMT 128

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

typedef struct uncode_tree{
    char sign;
    struct uncode_tree *left;
    struct uncode_tree *right;
}uncode_tree;

letter *create_letter (void);
huff_tree *create_huff_tree (void);
huff_list *create_huff_list (void);
uncode_tree *create_uncode_tree (void);

#endif
