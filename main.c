#include <stdio.h>
#include "linkedlist/includes.h"

char next_char(char c) {
    return c+1;
}

int main() {

    char * array_data = "ABCDE";
    linkedlist * list = new_list_from_array(array_data);

    printf("Original list : \n");
    display(list);

    linkedlist * new_list = map(list, &next_char);
    printf("\n");    
    display(new_list);
    
    
    delete(list);
    delete(new_list);

    return 0;
}