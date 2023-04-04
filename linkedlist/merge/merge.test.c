#include <criterion/criterion.h>g

#include "merge.h"
#include "../new/new.h"
#include "../delete/delete.h"
#include "../struct/struct.h"

Test(merge, merge_null_list) {
    linkedlist * list = NULL;
    linkedlist * to_merge = NULL;
    
    merge(list, to_merge);

    cr_assert_null(list);
    cr_assert_null(to_merge);

    list = new_list('A');
    
    merge(list, to_merge);

    cr_assert_not_null(list);
    cr_assert_eq(length(list), 1);
    cr_assert_null(to_merge);

    delete(list);
    list = NULL;
    to_merge = new_list('A');
    
    merge(list, to_merge);

    cr_assert_null(list);
    cr_assert_not_null(to_merge);

    delete(to_merge);
}

Test(merge, merge_empty_list) {
    linkedlist * list = new_empty_list();
    linkedlist * to_merge = new_empty_list();
    
    merge(list, to_merge);

    cr_assert_eq(length(list), 0);
    cr_assert_eq(length(to_merge), 0);

    list = new_list('A');
    
    merge(list, to_merge);

    cr_assert_eq(length(list), 1);
    cr_assert_eq(length(to_merge), 0);

    delete(list);
    list = NULL;
    to_merge = new_list('A');
    
    merge(list, to_merge);

    cr_assert_eq(length(list), 0);
    cr_assert_eq(length(to_merge), 1);

    delete(to_merge);
}

Test(merge, merge_one_element_list) {
    linkedlist * list = new_list('A');
    linkedlist * to_merge = new_list('B');
    
    merge(list, to_merge);

    cr_assert_eq(length(list), 2);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(get_tail(list)->data, 'B');

    delete(list);
}

Test(merge, merge_big_list) {
    linkedlist * list = new_list_from_array("ABC");
    linkedlist * to_merge = new_list_from_array("DE");
    printf("%p\n", to_merge);
    merge(list, to_merge);

    cr_assert_eq(length(list), 5);
    cr_assert_eq(list->head->data, 'A');
    cr_assert_eq(list->head->next->data, 'B');
    cr_assert_eq(get_tail(list)->data, 'E');

    delete(list);
}