#include <stdio.h>
#include "../linkedlist/includes.h"

char next_char(char c) {
    return c+1;
}

char is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int main() {

    char * array_data = "A2AE1ZR1";
    linkedlist * list = new_list_from_array(array_data);

    printf("Original list : \n");
    display(list);

    filter(list, &is_digit);
    printf("\n");
    display(list);    
    
    delete(list);

    return 0;
}