#include <criterion/criterion.h>

#include "display.h"
#include "../new/new.h"
#include "../delete/delete.h"
#include "../struct/struct.h"

unsigned mystrlen(char * str) {
    unsigned i = 0;
    for(; *str != '\0'; str++, ++i);
    return i;
}

Test(to_string, to_string_null_list) {
    linkedlist * list = NULL;
    char * str = to_string(list);

    cr_assert_null(list);
    cr_assert_null(str);
}

Test(to_string, to_string_empty_list) {
    linkedlist * list = new_empty_list();
    char * str = to_string(list);

    cr_assert_null(list->head);
    cr_assert_eq(*str, '\0');
    cr_assert_eq(mystrlen(str), length(list));

    delete(list);
}

Test(to_string, to_string_one_element_list) {
    linkedlist * list = new_list('A');
    char * str = to_string(list);

    cr_assert_not_null(list->head);
    cr_assert_eq(mystrlen(str), length(list));

    cr_assert_eq(*str, 'A');
    cr_assert_eq(*(++str), '\0');

    delete(list);
}

Test(to_string, to_string_big_list) {
    linkedlist * list = new_list_from_array("ABCDE");
    char * str = to_string(list);

    cr_assert_not_null(list->head);
    cr_assert_eq(mystrlen(str), length(list));

    cr_assert_eq(*str, 'A');
    cr_assert_eq(*(++str), 'B');
    cr_assert_eq(*(++str), 'C');
    cr_assert_eq(*(++str), 'D');
    cr_assert_eq(*(++str), 'E');
    cr_assert_eq(*(++str), '\0');

    delete(list);
}