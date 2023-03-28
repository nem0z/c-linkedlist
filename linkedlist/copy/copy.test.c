#include <criterion/criterion.h>

#include "copy.h"

Test(copy, copy_empty_list) {
    linkedlist * empty_list = malloc(sizeof(linkedlist));
    linkedlist * copy_list = copy(empty_list);

    cr_assert_not_null(copy_list);
    cr_assert_not_null(copy_list->head);
    cr_assert_null(copy_list->head->next);
}