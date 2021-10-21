#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/defines.h"

int get_arr_size(size_t *m, size_t *n, size_t *p, size_t *q)
{
    //printf("\nEnter number of rows in matrix A: ");
    if (scanf("%zu", m) != 1 || *m < 1)
    {
        return ERR;
    }

    //printf("\nEnter number of columns in matrix A: ");
    if (scanf("%zu", n) != 1 || *n < 1)
    {
        return ERR;
    }

    //printf("\nEnter number of rows in matrix B: ");
    if (scanf("%zu", p) != 1 || *p < 1)
    {
        return ERR;
    }

    //printf("\nEnter number of columns in matrix B: ");
    if (scanf("%zu", q) != 1 || *q < 1)
    {
        return ERR;
    }
    return OK;
}

int get_arr(int **data, size_t m, size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (scanf("%d", &data[i][j]) != 1)
            {
                return ERR;
            }
        }
    }
    return OK;
}

int get_mult_times(size_t *k, size_t *s)
{
    //printf("\n\nEnter ρ: ");
    if (scanf("%zu", k) != 1)
    {
        return ERR;
    }
    //printf("\nEnter γ: ");
    if (scanf("%zu", s) != 1)
    {
        return ERR;
    }
    return OK;
}

void print_matrix(int **data, size_t r, size_t c)
{
    //printf("\nResult: \n");
    //printf("\n");
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}
