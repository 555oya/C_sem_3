#include <stdio.h>

int input_mass(int *pb, int *pe, FILE *in_file)
{
    int *p_curr = pb;
    int count = 0;

    while (p_curr != pe)
    {
        if (fscanf(in_file, "%d", p_curr) != 1)
        {
            return 0;
        }
        p_curr++;
        count++;
    }

    return count;
}

void print_out(const int *pb, const int *pe, FILE *out_file)
{
    while (pb != pe)
    {
        fprintf(out_file, "%d ", *pb);
        pb++;
    }
}
