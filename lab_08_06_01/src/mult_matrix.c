#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/alloc_free_matrix.h"
#include "../inc/defines.h"
#include "../inc/io.h"

void get_ab_matrix(int **a, int **b, int **ab, size_t z)
{
    for (size_t i = 0; i < z; i++)
    {
        for (size_t j = 0; j < z; j++)
        {
            ab[i][j] = 0;
            for (size_t k = 0; k < z; k++)
            {
                ab[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void copy_matrix(int **data, int **new_data, size_t z)
{
    for (size_t i = 0; i < z; i++)
    {
        for (size_t j = 0; j < z; j++)
        {
            new_data[i][j] = data[i][j];
        }
    }
}

void null_matrix(int **data, size_t z)
{
    for (size_t i = 0; i < z; i++)
    {
        for (size_t j = 0; j < z; j++)
        {
            data[i][j] = 1;
        }
    }
}

int pow_matrix(int **data, size_t z, size_t n)
{
    int **new_data = allocate_matrix(z, z);
    int **rez = allocate_matrix(z, z);

    if ((new_data == NULL) || (rez == NULL))
    {
        return ERR;
    }
    copy_matrix(data, new_data, z);
    for (size_t i = 0; i < n - 1; i++)
    {
        for (size_t i = 0; i < z; i++)
        {
            for (size_t j = 0; j < z; j++)
            {
                rez[i][j] = 0;
                for (size_t k = 0; k < z; k++)
                {
                    rez[i][j] = rez[i][j] + (data[i][k] * new_data[k][j]);
                }
            }
        }
        copy_matrix(rez, data, z);
    }
    free_matrix(rez, z);
    free_matrix(new_data, z);
    return OK;
}

int mult_matrix(int **a, int **b, int **ab, size_t z, size_t k, size_t s)
{
    if (k == 0)
    {
        null_matrix(a, z);
    }
    else if (k > 1)
    {
        if (pow_matrix(a, z, k) == ERR)
        {
            return ERR;
        }
    }
    if (s == 0)
    {
        null_matrix(b, z);
    }
    else if (k > 1)
    {
        if (pow_matrix(b, z, s) == ERR)
        {
            return ERR;
        }
    }
    get_ab_matrix(a, b, ab, z);
    return OK;
}
