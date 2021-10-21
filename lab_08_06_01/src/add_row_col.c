#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../inc/defines.h"
#include "../inc/io.h"

void fill_row(int **data, size_t r, size_t c)
{
    int mult = 1;

    for (size_t i = 0; i < c; i++)
    {
        for (size_t j = 0; j < r; j++)
        {
            mult *= data[j][i];
        }
        data[r][i] = (int) pow(mult, 1 / ((double) r));
        mult = 1;
    }
}


int add_row(int **data, size_t *r, size_t *c, size_t z)
{
    while (*r != z)
    {
        data[*r] = malloc((*c) * sizeof(int));

        if (data[*r] == NULL)
        {
            return ERR;
        }

        fill_row(data, *r, *c);
        (*r)++;
    }
    return OK;
}

void fill_col(int **data, size_t r, size_t *c, size_t z)
{
    int min = data[0][0];
    while (*c != z)
    {
        for (size_t i = 0; i < r; i++)
        {
            min = data[i][0];
            for (size_t j = 0; j < *c; j++)
            {
                if (data[i][j] < min)
                {
                    min = data[i][j];
                }
            }
            data[i][*c] = min;
        }
        (*c)++;
    }
}

int add_col(int **data, size_t *r, size_t *c, size_t z)
{
    for (size_t i = 0; i < *r; i++)
    {
        data[i] = realloc(data[i], z * sizeof(int));
        if (data[i] == NULL)
        {
            return ERR;
        }
    }

    fill_col(data, *r, c, z);
    return OK;
}
