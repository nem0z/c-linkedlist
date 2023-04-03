#include <criterion/criterion.h>

#include "reverse.h"
#include "../new/new.h"
#include "../delete/delete.h"
#include "../struct/struct.h"

Test(reverse, reverse_null_list) {
    linkedlist * list = NULL;
    reverse(list);

    cr_assert_null(list);
}

Test(get_tail, reverse_empty_list) {
    linkedlist * list = new_empty_list();

    reverse(list);
    cr_assert_not_null(list);
    cr_assert_null(list->head);

    delete(list);
}

Test(get_tail, reverse_one_element_list) {
    linkedlist * list = new_list('A');

    reverse(list);
    cr_assert_not_null(list->head);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(get_tail(list)->data, 'A');
    cr_assert_eq(length(list), 1);

    delete(list);
}

Test(get_tail, reverse_big_list) {
    linkedlist * list = new_list_from_array("ABCDE");

    reverse(list);
    cr_assert_eq(list->head->data, 'E');
    cr_assert_eq(at(list, 1)->data, 'D');
    cr_assert_eq(at(list, 2)->data, 'C');
    cr_assert_eq(at(list, 3)->data, 'B');
    cr_assert_eq(get_tail(list)->data, 'A');
    cr_assert_eq(length(list), 5);

    delete(list);
}