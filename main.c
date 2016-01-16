#include <stdio.h>
#include <stdlib.h>
#include "get_code.h"
#include "make_code.h"
int main(int argc, const char * argv[]) {

    huff_list *list = read_f("test.txt");
    make_tree(list);
    return 0;
}
