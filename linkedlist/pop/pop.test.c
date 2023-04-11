#include <criterion/criterion.h>

#include "pop.h"
#include "../new/new.h"
#include "../delete/delete.h"
#include "../struct/struct.h"

Test(pop, pop_big_list) {
    linkedlist * list = new_list_from_array("ABCDE");

    node * n = pop(list);
    cr_assert_not_null(list);
    cr_assert_eq(n->data, 'A');
    cr_assert_not_null(list->head);
    cr_assert_eq(length(list), 4);

    n = pop_front(list);
    cr_assert_not_null(list);
    cr_assert_eq(n->data, 'B');
    cr_assert_not_null(list->head);
    cr_assert_eq(length(list), 3);

    delete(list);
}