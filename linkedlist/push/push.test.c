#include <criterion/criterion.h>

#include "push.h"
#include "../new/new.h"
#include "../delete/delete.h"
#include "../struct/struct.h"

Test(push, push_big_list) {
    linkedlist * list = new_list_from_array("BCDEF");

    push(list, 'A');
    cr_assert_not_null(list->head);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(list->head->next->data, 'B');
    cr_assert_eq(length(list), 6);

    delete(list);
}