#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <check.h>

#include "../inc/add_row_col.h"
#include "../inc/delete_rows_cols.h"
#include "../inc/mult_matrix.h"
#include "../inc/defines.h"

int compare(int **a, int **b, size_t z)
{
    for (size_t i = 0; i < z; i++)
    {
        for (size_t j = 0; j < z; j++)
        {
            if (a[i][j] != b[i][j])
            {
                return ERR;
            }
        }
    }
    return OK;
}


START_TEST(test_add_row_usual_matrix)
{
    int a[] = { {1, 1} };
    int b[] = { {1, 1}, {1, 1} };
    size_t m = 1;
    size_t n = 2;
    size_t z = 2;

    int rc;

    rc = add_row(a, &m, &n, z);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_add_row_usual_matrix_compare)
{
    int a[] = { {1, 1} };
    int b[] = { {1, 1}, {1, 1} };
    size_t m = 1;
    size_t n = 2;
    size_t z = 2;

    int rc;

    add_row(a, &m, &n, z);

    rc = compare(a, b, z)

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_add_col_usual_matrix)
{
    int a[] = { {1, 2}, {2, 7}, {2, 1} };
    int b[] = { {1, 2, 1}, {2, 7, 2}, {2, 1, 1} };
    size_t m = 3;
    size_t n = 2;
    size_t z = 3;

    int rc;

    rc = add_col(a, &m, &n, z);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_add_col_usual_matrix_compare)
{
    int a[] = { {1, 2}, {2, 7}, {2, 1} };
    int b[] = { {1, 2, 1}, {2, 7, 2}, {2, 1, 1} };
    size_t m = 3;
    size_t n = 2;
    size_t z = 3;

    int rc;

    add_col(a, &m, &n, z);

    rc = compare(a, b, z);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_delete_row_col_usual_matrix_del_row)
{
    int a[] = { {1, 2}, {2, 7}, {2, 1} };
    size_t m = 3;
    size_t n = 2;

    int rc;

    rc = delete_row_col(a, &m, &n);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_delete_row_col_usual_matrix_del_col)
{
    int a[] = { {1, 2, 3, 5}, {2, 7, 4, 5}, {2, 1, 2, 2} };
    size_t m = 3;
    size_t n = 4;

    int rc;

    rc = delete_row_col(a, &m, &n);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_delete_row_col_usual_matrix_del_none)
{
    int a[] = { {1, 2, 3}, {2, 7, 4}, {2, 1, 2} };
    size_t m = 3;
    size_t n = 3;

    int rc;

    rc = delete_row_col(a, &m, &n);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_null_matrix_usual_matrix)
{
    int a[] = { {1, 2, 3}, {2, 7, 4}, {2, 1, 2} };
    int b[] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
    size_t z = 3;

    int rc;

    null_matrix(a, z);

    rc = compare(a, b, z);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_pow_matrix_usual_matrix)
{
    int a[] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
    int b[] = { {2, 2, 2}, {2, 2, 2}, {2, 2, 2} };
    size_t z = 3;
    size_t k = 2;

    int rc;

    pow_matrix(a, z, k)

    rc = compare(a, b, z);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_pow_matrix_usual_matrix)
{
    int a[] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
    int b[] = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
    int ab[] = { {2, 2, 2}, {2, 2, 2}, {2, 2, 2} };
    int ab_2[] = { {2, 2, 2}, {2, 2, 2}, {2, 2, 2} };
    size_t z = 3;

    int rc;

    get_ab_matrix(a, b, ab, z);

    rc = compare(ab, ab_2, z);

    ck_assert_int_eq(rc, OK);
}
END_TEST


Suite* calc_avg_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("units");

    tc_neg = tcase_create("negatives");

    //tcase_add_test(tc_neg, );

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, test_add_row_usual_matrix);
    tcase_add_test(tc_pos, test_add_row_usual_matrix_compare);
    tcase_add_test(tc_pos, test_add_col_usual_matrix);
    tcase_add_test(tc_pos, test_add_col_usual_matrix_compare);
    tcase_add_test(tc_pos, test_delete_row_col_usual_matrix_del_row);
    tcase_add_test(tc_pos, test_delete_row_col_usual_matrix_del_col);
    tcase_add_test(tc_pos, test_delete_row_col_usual_matrix_del_none);
    tcase_add_test(tc_pos, test_null_matrix_usual_matrix);
    tcase_add_test(tc_pos, test_pow_matrix_usual_matrix);
    tcase_add_test(tc_pos, test_pow_matrix_usual_matrix);

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
