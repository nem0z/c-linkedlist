#include <criterion/criterion.h>

#include "push.h"
#include "../new/new.h"
#include "../delete/delete.h"

Test(push_front, push_front_null_list) {
    linkedlist * list = NULL;
    push_front(list, 'A');

    cr_assert_null(list);
}

Test(get_tail, push_front_empty_list) {
    linkedlist * list = new_empty_list();

    push_front(list, 'A');
    cr_assert_not_null(list->head);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(length(list), 1);

    delete(list);
}

Test(get_tail, push_front_one_element_list) {
    linkedlist * list = new_list('B');

    push_front(list, 'A');
    cr_assert_not_null(list->head);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(list->head->next->data, 'B');
    cr_assert_eq(length(list), 2);

    delete(list);
}

Test(get_tail, push_front_big_list) {
    linkedlist * list = new_list_from_array("BCDEF");

    push_front(list, 'A');
    cr_assert_not_null(list->head);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(list->head->next->data, 'B');
    cr_assert_eq(length(list), 6);

    delete(list);
}