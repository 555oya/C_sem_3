#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/defines.h"
#include "../inc/alloc_free_matrix.h"

int get_matrix(FILE *in_file, size_t *m, size_t *n, double **mtr)
{
    //printf("\nEnter number of rows in matrix: ");
    if (fscanf(in_file, "%zu", m) != 1 || *m < 1)
    {
        return ERR;
    }

    //printf("\nEnter number of columns in matrix: ");
    if (fscanf(in_file, "%zu", n) != 1 || *n < 1)
    {
        return ERR;
    }
    
    mtr = allocate_matrix(*m, *n);
    
    for (size_t i = 0; i < *m; i++)
    {
        for (size_t j = 0; j < *n; j++)
        {
            if (fscanf(in_file, "%lf", &mtr[i][j]) != 1)
            {
                return ERR;
            }
        }
    }
    return OK;
}

void print_matrix(FILE *file, double **data, size_t m, size_t n)
{
    //printf("\nResult: \n");
    //printf("\n");
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            fprintf(file, "%lf ", data[i][j]);
        }
        printf("\n");
    }
}
