#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_matrix(int **data, size_t m)
{
    for (size_t i = 0; i < m; i++)
    {
        free(data[i]);
    }

    free(data);
}

int **allocate_matrix(size_t m, size_t n)
{
    int **data;

    data = calloc(m, sizeof(int*));
    
    if (!data)
    {
        return NULL;
    }

    for (size_t i = 0; i < m; i++)
    {
        data[i] = malloc(n * sizeof(int));
        if (!data[i])
        {
            free_matrix(data, m);

            return NULL;
        }
    }

    return data;
}
