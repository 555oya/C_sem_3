#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../inc/defines.h"
#include "../inc/io.h"

void fill_identity_matrix(double **data, size_t m)
{
        for (size_t i = 0; i < m; i++) 
        {
            for (size_t j = 3; j < m * 2; j++) 
            {
                if (i + 3 == j) 
                {
                    data[i][j] = 1;
                }
                else
                {
                    data[i][j] = 0;
                }
            }
        }
}

int add_identity_matrix(double **data, size_t m)
{
    for (size_t i = 0; i < m; i++)
    {
        data[i] = realloc(data[i], (m * 2) * sizeof(double));
        if (data[i] == NULL)
        {
            return ERR;
        }
    }

    fill_identity_matrix(data, m);
    
    return OK;
}
