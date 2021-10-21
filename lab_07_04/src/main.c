#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/io.h"
#include "../inc/filter.h"
#include "../inc/sorting.h"

int main(int argc, char const *argv[])
{
    size_t mass_size = 0;
    int *pb = NULL;
    int *pe = NULL;
    int *pb_filtered = NULL;
    int *pe_filtered = NULL;
    int number = 0;
    int count = 0;

    FILE *in_file, *out_file;
        
    if ((argc > 4) || (argc < 3))
    {
        return EXIT_FAILURE;
    }

    in_file = fopen(argv[1], "r");

    if (in_file == NULL)
    {
        return EXIT_FAILURE;
    }

    if ((argc == 4) && (strcmp(argv[3], "f") != 0))
    {
        fclose(in_file);
        return EXIT_FAILURE;
    }

    while (fscanf(in_file, "%d", &number) == 1)
    {
        mass_size++;
    }

    if (!feof(in_file))
    {
        fclose(in_file);
        return EXIT_FAILURE;
    }
    rewind(in_file);

    if (mass_size == 0)
    {
        fclose(in_file);
        return EXIT_FAILURE;
    }

    pb = (int *) malloc(mass_size * sizeof(int));
    pe = pb + mass_size;
    if (pb == NULL)
    {
        fclose(in_file);
        free(pb);
        return EXIT_FAILURE;
    }

    if (input_mass(pb, pe, in_file) == 0)
    {
        fclose(in_file);
        free(pb);
        return EXIT_FAILURE;
    }

    fclose(in_file);

    count = count_nums(pb, pe);

    if (argc == 4)
    {
        pb_filtered = (int *) malloc(count * sizeof(int));
        pe_filtered = pb_filtered + count;

        if (pb_filtered == NULL)
        {
            return EXIT_FAILURE;
        }

        if (key(pb, pe, &pb_filtered, &pe_filtered) != 1)
        {
            free(pb);
            free(pb_filtered);
            return EXIT_FAILURE;
        }
        free(pb);
    }

    out_file = fopen(argv[2], "w");

    if (out_file == NULL)
    {
        return EXIT_FAILURE;
    }
    if (argc == 4)
    {
        mysort(pb_filtered, count, sizeof(int), compar_func);
        print_out(pb_filtered, pe_filtered, out_file);
        free(pb_filtered);
    }
    else
    {
        mysort(pb, mass_size, sizeof(int), compar_func);
        print_out(pb, pe, out_file);
        free(pb);
    }
    fclose(out_file);

    return EXIT_SUCCESS;
}
