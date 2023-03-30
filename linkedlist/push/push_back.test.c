#include <criterion/criterion.h>

#include "push.h"
#include "../new/new.h"
#include "../delete/delete.h"
#include "../struct/struct.h"

Test(push_back, push_back_null_list) {
    linkedlist * list = NULL;
    push_back(list, 'A');

    cr_assert_null(list);
}

Test(get_tail, push_back_empty_list) {
    linkedlist * list = new_empty_list();

    push_back(list, 'A');
    cr_assert_not_null(list->head);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(length(list), 1);

    delete(list);
}

Test(get_tail, push_back_one_element_list) {
    linkedlist * list = new_list('A');

    push_back(list, 'B');
    cr_assert_not_null(list->head);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(get_tail(list)->data, 'B');
    cr_assert_eq(length(list), 2);

    delete(list);
}

Test(get_tail, push_back_big_list) {
    linkedlist * list = new_list_from_array("ABCDE");

    push_back(list, 'F');
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(get_tail(list)->data, 'F');
    cr_assert_eq(length(list), 6);

    delete(list);
}