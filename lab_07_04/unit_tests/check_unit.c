#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "../inc/filter.h"
#include "../inc/sorting.h"

int compare(int *a, int *b, size_t z)
{
    for (int i = 0; i < z; i++)
    {
        if (a[i] != b[i])
        {
            return -1;
        }
    }
    return 1;
}

START_TEST(test_key_bad_src_pointers)
{
    int *pb = NULL;
    int *pe = NULL;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *pb_filtered = a;
    int *pe_filtered = a;
    int rc;

    rc = key(pb, pe, &pb_filtered, &pe_filtered);
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_key_bad_dst_pointers)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *pb = a;
    int *pe = a + sizeof(a);
    int *pb_filtered = NULL;
    int *pe_filtered = NULL;
    int rc;

    rc = key(pb, pe, &pb_filtered, &pe_filtered);
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_key_bad_array_eq_elem)
{
    int a[] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    int *pb = a;
    int *pe = pb + 9;
    int b[] = {0, 0, 0, 0};
    int *pb_filtered = b;
    int *pe_filtered = pb;
    int rc;

    rc = key(pb, pe, &pb_filtered, &pe_filtered);
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_key_empty_array)
{
    int a[3];
    int *pb = a;
    int *pe = pb;
    int b[3];
    int *pb_filtered = b;
    int *pe_filtered = b + 3;
    int rc;

    rc = key(pb, pe, &pb_filtered, &pe_filtered);
    ck_assert_int_eq(rc, -1);
}
END_TEST

START_TEST(test_key_usual_array)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *pb = a;
    int *pe = pb + 9;
    int b[] = {6, 7, 8, 9};
    int *pb_filtered = b;
    int *pe_filtered = pb;
    int rc;

    rc = key(pb, pe, &pb_filtered, &pe_filtered);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(test_sort_usual_array)
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *pa = a;
    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *pb = b;
    size_t z = 9;
    int rc;
    mysort(pa, z, sizeof(int), &compar_func);

    rc = compare(pa, pb, z);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(test_sort_unsorted_array)
{
    int a[] = {1, 5, 3, 3, 1, 6, 22, 8, 9};
    int *pa = a;
    int b[] = {1, 1, 3, 3, 5, 6, 8, 9, 22};
    int *pb = b;
    size_t z = 9;
    int rc;
    mysort(pa, z, sizeof(int), &compar_func);

    rc = compare(pa, pb, z);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(test_sort_all_equal_array)
{
    int a[] = {5, 5, 5, 5, 5, 5, 5, 5};
    int *pa = a;
    int b[] = {5, 5, 5, 5, 5, 5, 5, 5};
    int *pb = b;
    size_t z = 8;
    int rc;
    mysort(pa, z, sizeof(int), &compar_func);

    rc = compare(pa, pb, z);
    ck_assert_int_eq(rc, 1);
}
END_TEST

START_TEST(test_sort_with_neg_el_array)
{
    int a[] = {5, -5, 0, -5, 6, 7, 11, 0};
    int *pa = a;
    int b[] = {-5, -5, 0, 0, 5, 6, 7, 11};
    int *pb = b;
    size_t z = 8;
    int rc;
    mysort(pa, z, sizeof(int), &compar_func);

    rc = compare(pa, pb, z);
    ck_assert_int_eq(rc, 1);
}
END_TEST

Suite* calc_avg_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("key");

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, test_key_bad_src_pointers);
    tcase_add_test(tc_neg, test_key_bad_dst_pointers);
    tcase_add_test(tc_neg, test_key_bad_array_eq_elem);
    tcase_add_test(tc_neg, test_key_empty_array);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_key_usual_array);
    tcase_add_test(tc_pos, test_sort_usual_array);
    tcase_add_test(tc_pos, test_sort_unsorted_array);
    tcase_add_test(tc_pos, test_sort_all_equal_array);
    tcase_add_test(tc_pos, test_sort_with_neg_el_array);

    suite_add_tcase(s, tc_pos);

    return s;
}


int main(void)
{
    int no_failed = 0;
    Suite *s;
    SRunner *runner;

    s = calc_avg_suite();
    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
