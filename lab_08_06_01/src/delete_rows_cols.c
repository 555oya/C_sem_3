#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/defines.h"

void free_row(int **data, size_t r)
{
    free(data[r]);
}

void delete_rows(int **data, size_t *r, size_t *c)
{
    int min = data[0][0];
    size_t min_i = 0;
    while (*r != *c)
    {
        min = data[0][0];
        for (size_t i = 0; i < *r; i++)
        {
            for (size_t j = 0; j < *c; j++)
            {
                if (data[i][j] <= min)
                {
                    min = data[i][j];
                    min_i = i;
                }
            }
        }
        for (size_t i = min_i; i < (*r - 1); i++)
        {
            data[i] = data[i + 1];
        }
        free_row(data, *r);
        (*r)--;
    }
}

int free_cols(int **data, size_t r, size_t c)
{
    for (size_t i = 0; i < r; i++)
    {
        data[i] = realloc(data[i], c * sizeof(int));
        if (data[i] == NULL)
        {
            return ERR;
        }
    }
    return OK;
}

int delete_cols(int **data, size_t *r, size_t *c)
{
    int min = data[0][0];
    size_t min_j = 0;
    while (*r != *c)
    {
        min = data[0][0];
        for (size_t i = 0; i < *r; i++)
        {
            for (size_t j = 0; j < *c; j++)
            {
                if (data[i][j] <= min)
                {
                    min = data[i][j];
                    min_j = j;
                }
            }
        }
        for (size_t i = 0; i < *r; i++)
        {
            for (size_t j = min_j; j < (*c - 1); j++)
            {
                data[i][j] = data[i][j + 1];
            }
        }
        (*c)--;
    }
    if (free_cols(data, *r, *c) == ERR)
    {
        return ERR;
    }
    return OK;
}

int delete_row_col(int **data, size_t *m, size_t *n)
{
    if (*m > *n)
    {
        delete_rows(data, m, n);
    }
    else if (*m < *n)
    {
        if (delete_cols(data, m, n) == ERR)
        {
            return ERR;
        }
    }
    return OK;
}
