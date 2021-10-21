#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../inc/alloc_free_matrix.h"
#include "../inc/defines.h"
#include "../inc/io.h"
#include "../inc/add_row_col.h"

void mult_matrix(double **a, double **b, double **ab, size_t m, size_t n)
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            ab[i][j] = 0;
            for (size_t k = 0; k < m; k++)
            {
                ab[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void add_matrix(double **a, double **b, double **ab, size_t m, size_t n) 
{
    for (size_t i = 0; i < m; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            ab[i][j] = a[i][j] + b[i][j];
        }
    }
}

void move_row(double **a, size_t m, size_t elem_i)
{
    float buff = 0;
    
    if (elem_i != 0) 
    {
        for (size_t j = 0; j < m * 2; j++) 
        {
            buff = a[0][j];
            a[0][j] = a[elem_i][j];
            a[elem_i][j] = buff;
        }
    }
}

int find_main_element(double **a, size_t m)
{
    double elem = 0;
    size_t elem_i = 0;
    
    for (size_t i = 0; i < m; i++) 
    {
        if ((fabs(elem - 0) < EPS) && (fabs(a[i][0] - 0) > EPS)) 
        {
            elem = a[i][0];
            elem_i = i;
        }
    }
    
    if (fabs(elem - 0) < EPS) 
    {
        return ERR;
    }
    
    // if ((elem_i != 0) || (elem_j != 0)) 
    // {
    //     move_row(a, m, elem_i);
    // }
    
    return OK;
}

int check_echelon_form(double **a, size_t m)
{
    for (size_t i = 0; i < m; i++) 
    {
        if (fabs(a[i][i] - 1) > 1) 
        {
            return ERR;
        }
    }
    
    return OK;
}

int row_echelon_form(double **a, size_t m)
{
    size_t start = 1;
    double buff = 0;
    
    if(find_main_element(a, m) == ERR)
    {
        return ERR;
    }
    
    for (size_t k = 0; k < m; k++) 
    {
        buff = a[k][k];
        
        if (fabs(buff - 0) > EPS) 
        {
            for (size_t i = 0; i < m * 2; i++) 
            {
                a[k][i] = a[k][i] / buff;
            }
        }
        
        for (size_t i = start; i < m; i++) 
        {
            buff = a[i][start - 1];
            for (size_t j = start - 1; j < m * 2; j++) 
            {
                a[i][j] = a[i][j] + a[i - 1][j] * (-buff);
            }
        }
        start++;
    }
    
    if (check_echelon_form(a, m) == ERR) 
    {
        return ERR;
    }
    
    return OK;
}

int inverse_matrix(double **a, size_t m) 
{
    size_t start = m - 1;
    size_t end = m - 2;
    double buff = 0;
    
    if(add_identity_matrix(a, m) == ERR)
    {
        return ERR;
    }
    if(row_echelon_form(a, m) == ERR)
    {
        return ERR;
    }
    
    for (size_t k = 0; k < m - 1; k++) 
    {
        for (size_t i = m - 2; i >= 0; i++) 
        {
            buff = a[i][start];
            for (size_t j = end; j < m * 2; j++) 
            {
                a[i][j] = a[i][j] + a[i + 1][j] * (-buff);
            }
        }
        start--;
        end--;
    }
    
    return OK;
}
