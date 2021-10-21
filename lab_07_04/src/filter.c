#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int find_arithmetic_mean(const int *pb_src, const int *pe_src)
{
    const int *p_curr = pb_src;
    int sum = 0;
    int rez = 0;
    int count = 0;

    while (p_curr != pe_src)
    {
        sum = sum + (*p_curr);
        p_curr++;
        count++;
    }

    rez = sum / count;

    return rez;
}

int count_nums(const int *pb_src, const int *pe_src)
{
    int arith_mean = find_arithmetic_mean(pb_src, pe_src);
    const int *p_curr = pb_src;
    int count = 0;

    while (p_curr != pe_src)
    {
        if (*p_curr > arith_mean)
        {
            count++;
        }
        p_curr++;
    }

    return count;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    if (pb_src == NULL || pe_src == NULL)
    {
        return -1;
    }
    
    if (*pb_dst == NULL || *pe_dst == NULL)
    {
        return -1;
    }
    
    if (pb_src >= pe_src)
    {
        return -1;
    }

    int arith_mean = find_arithmetic_mean(pb_src, pe_src);
    int *p_curr = (int *) pb_src;
    int *pe_curr = (int *) pe_src;
    int count_n = count_nums(pb_src, pe_src);

    if (count_n == 0)
    {
        return -1;
    }

    int *p_curr_dst = NULL;
    int buff = 0;

    while (p_curr != pe_src)
    {
        if (*p_curr <= arith_mean)
        {
            p_curr_dst = (int *) p_curr;
            pe_curr--;
            while (p_curr_dst != pe_curr)
            {
                p_curr_dst++;
                buff = *p_curr_dst;
                p_curr_dst--;
                *p_curr_dst = buff;
                p_curr_dst++;
            }
        }
        else
        {
            p_curr++;
        }
    }

    memcpy(*pb_dst, pb_src, sizeof(int) * count_n);

    *pe_dst = (int *) *pb_dst + count_n;

    return 1;
}

