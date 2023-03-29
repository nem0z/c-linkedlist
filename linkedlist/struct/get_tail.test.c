#include <criterion/criterion.h>

#include "struct.h"
#include "../new/new.h"
#include "../delete/delete.h"

Test(get_tail, get_tail_null_list) {
    linkedlist * list = NULL;
    cr_assert_eq(get_tail(list), NULL);
}

Test(get_tail, get_tail_empty_list) {
    linkedlist * list = new_empty_list();
    cr_assert_eq(get_tail(list), NULL);

    delete(list);
}

Test(get_tail, get_tail_one_element_list) {
    linkedlist * list = new_list('A');

    cr_assert_not_null(get_tail(list));
    cr_assert_eq(get_tail(list), list->head);

    delete(list);
}

Test(get_tail, get_tail_big_list) {
    linkedlist * list = new_list_from_array("ABCDE");

    cr_assert_not_null(get_tail(list));
    cr_assert_eq(get_tail(list)->data, 'E');

    delete(list);
}