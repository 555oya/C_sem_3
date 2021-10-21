#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_matrix(double **data, size_t m)
{
    for (size_t i = 0; i < m; i++)
    {
        free(data[i]);
    }

    free(data);
}

double **allocate_matrix(size_t m, size_t n)
{
    double **data;

    data = calloc(m, sizeof(double*));
    
    if (!data)
    {
        return NULL;
    }

    for (size_t i = 0; i < m; i++)
    {
        data[i] = malloc(n * sizeof(double));
        if (!data[i])
        {
            free_matrix(data, m);

            return NULL;
        }
    }

    return data;
}
