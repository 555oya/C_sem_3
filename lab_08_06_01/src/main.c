#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/defines.h"
#include "../inc/io.h"
#include "../inc/add_row_col.h"
#include "../inc/alloc_free_matrix.h"
#include "../inc/delete_rows_cols.h"
#include "../inc/mult_matrix.h"

int main()
{
    size_t m = 0;
    size_t n = 0;
    size_t p = 0;
    size_t q = 0;
    size_t k = 0;
    size_t s = 0;
    size_t z = 0;
    int **a = NULL;
    int **b = NULL;
    int **ab = NULL;

    if (get_arr_size(&m, &n, &p, &q) == ERR)
    {
        return ERR_BAD_ARR_SIZE;
    }

    a = allocate_matrix(m, n);
    if (a == NULL)
    {
        return ERR_NO_MEM_FOR_ARR;
    }

    b = allocate_matrix(p, q);
    if (b == NULL)
    {
        free_matrix(a, m);
        return ERR_NO_MEM_FOR_ARR;
    }

    //printf("\nEnter A's elements: \n");
    if (get_arr(a, m, n) == ERR)
    {
        free_matrix(a, m);
        free_matrix(b, p);
        return ERR_BAD_ARR_ELEMENTS;
    }
    //printf("\nEnter B's elements: \n");
    if (get_arr(b, p, q) == ERR)
    {
        free_matrix(a, m);
        free_matrix(b, p);
        return ERR_BAD_ARR_ELEMENTS;
    }

    if (delete_row_col(a, &m, &n) == ERR)
    {
        free_matrix(a, m);
        free_matrix(b, p);
        return ERR_BAD_REALLOC;
    }

    if (delete_row_col(b, &p, &q) == ERR)
    {
        free_matrix(a, m);
        free_matrix(b, p);
        return ERR_BAD_REALLOC;
    }

    if (m < p)
    {
        z = p;
        a = realloc(a, (z * sizeof(int*)));
        if (add_row(a, &m, &n, z) == ERR)
        {
            free_matrix(a, m);
            free_matrix(b, p);
            return ERR_NO_MEM_FOR_ARR;
        }
        if (add_col(a, &m, &n, z) == ERR)
        {
            free_matrix(a, m);
            free_matrix(b, p);
            return ERR_NO_MEM_FOR_ARR;
        }
    }
    else if (p < m)
    {
        z = m;
        b = realloc(b, (z * sizeof(int*)));
        if (add_row(b, &p, &q, z) == ERR)
        {
            free_matrix(a, m);
            free_matrix(b, p);
            return ERR_NO_MEM_FOR_ARR;
        }
        if (add_col(b, &p, &q, z) == ERR)
        {
            free_matrix(a, m);
            free_matrix(b, p);
            return ERR_NO_MEM_FOR_ARR;
        }
    }
    else
    {
        z = m;
    }

    if (get_mult_times(&k, &s) == ERR)
    {
        free_matrix(a, m);
        free_matrix(b, p);
        return ERR_BAD_POWER;
    }

    ab = allocate_matrix(z, z);
    if (ab == NULL)
    {
        free_matrix(a, m);
        free_matrix(b, p);
        return ERR_NO_MEM_FOR_ARR;
    }
    if (mult_matrix(a, b, ab, z, k, s) == ERR)
    {
        free_matrix(a, m);
        free_matrix(b, p);
        free_matrix(ab, z);
        return ERR_MULT_ALLOC;
    }

    print_matrix(ab, z, z);

    free_matrix(a, m);
    free_matrix(b, p);
    free_matrix(ab, z);

    return EXIT_SUCCESS;
}
