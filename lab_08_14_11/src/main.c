#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/defines.h"
#include "../inc/io.h"
#include "../inc/add_row_col.h"
#include "../inc/alloc_free_matrix.h"
#include "../inc/mult_matrix.h"

int main(int argc, char const *argv[])
{
    size_t m = 0;
    size_t n = 0;
    size_t p = 0;
    size_t q = 0;
    double **mtr_1 = NULL;
    double **mtr_2 = NULL;
    double **rez = NULL;
    
    FILE *mtr_1_file = NULL, *mtr_2_file = NULL, *rez_file = NULL;
    
    if ((argc > 5) || (argc < 4))
    {
        printf("1");
        return EXIT_FAILURE;
    }
    printf("%s", argv[1]);
    if ((strcmp(argv[1], "a") != 0) && (strcmp(argv[1], "m") != 0) && (strcmp(argv[1], "o") != 0))
    {
        printf("2");
        return EXIT_FAILURE;
    }
    
    if ((argc == 4) && (strcmp(argv[1], "o") != 0)) 
    {
        printf("");
        return EXIT_FAILURE;
    }
    
    if ((argc == 5) && (strcmp(argv[1], "o") == 0)) 
    {
        printf("4");
        return EXIT_FAILURE;
    }

    mtr_1_file = fopen(argv[2], "r");

    if (mtr_1_file == NULL)
    {
        printf("5");
        return EXIT_FAILURE;
    }

    if (get_matrix(mtr_1_file, &m, &n, mtr_1) == ERR)
    {
        printf("6");
        fclose(mtr_1_file);
        return ERR_BAD_ARR;
    }
    
    fclose(mtr_1_file);
    
    if (argc == 5) 
    {
        mtr_2_file = fopen(argv[3], "r");
        if (get_matrix(mtr_2_file, &p, &q, mtr_2) == ERR)
        {
            fclose(mtr_2_file);
            fclose(mtr_1_file);
            printf("7");
            return ERR_BAD_ARR;
        }
    }
    
    fclose(mtr_2_file);
    
    if (strcmp(argv[1], "a") == 0) 
    {
        if ((m != p) || (n != q)) 
        {
            free_matrix(mtr_1, m);
            free_matrix(mtr_2, p);
            printf("8");
            return EXIT_FAILURE;
        }
        
        rez = allocate_matrix(m, n);
        if (rez == NULL) 
        {
            free_matrix(mtr_1, m);
            free_matrix(mtr_2, p);
            printf("9");
            return EXIT_FAILURE;
        }
        
        add_matrix(mtr_1, mtr_2, rez, m, n);
        
        rez_file = fopen(argv[4], "w");
        if (rez_file == NULL)
        {
            free_matrix(mtr_1, m);
            free_matrix(mtr_2, p);
            printf("10");
            return EXIT_FAILURE;
        }
        
        print_matrix(rez_file, rez, m, n);
        
        fclose(rez_file);
        
        free_matrix(mtr_1, m);
        free_matrix(mtr_2, p);
        free_matrix(rez, m);
    }
    else if (strcmp(argv[1], "m") == 0) 
    {
        if ((m != q) || (n != p)) 
        {
            free_matrix(mtr_1, m);
            free_matrix(mtr_2, p);
            printf("11");
            return EXIT_FAILURE;
        }
        
        rez = allocate_matrix(m, m);
        if (rez == NULL) 
        {
            free_matrix(mtr_1, m);
            free_matrix(mtr_2, p);
            printf("12");
            return EXIT_FAILURE;
        }
        
        mult_matrix(mtr_1, mtr_2, rez, m, n);
        
        rez_file = fopen(argv[4], "w");
        if (rez_file == NULL)
        {
            free_matrix(mtr_1, m);
            free_matrix(mtr_2, p);
            printf("13");
            return EXIT_FAILURE;
        }
        
        print_matrix(rez_file, rez, m, m);
        
        fclose(rez_file);
        
        free_matrix(mtr_1, m);
        free_matrix(mtr_2, p);
        free_matrix(rez, m);
    }
    else
    {
        if (m != n) 
        {
            free_matrix(mtr_1, m);
            printf("14");
            return EXIT_FAILURE;
        }
        
        rez = allocate_matrix(m, m);
        if (rez == NULL) 
        {
            free_matrix(mtr_1, m);
            printf("15");
            return EXIT_FAILURE;
        }
        
        if(inverse_matrix(mtr_1, m) == ERR)
        {
            free_matrix(mtr_1, m);
            printf("16");
            return EXIT_FAILURE;
        }
        
        rez_file = fopen(argv[3], "w");
        if (rez_file == NULL)
        {
            free_matrix(mtr_1, m);
            printf("17");
            return EXIT_FAILURE;
        }
        
        print_matrix(rez_file, rez, m, m);
        
        fclose(rez_file);
        
        free_matrix(mtr_1, m);
        free_matrix(rez, m);
    }

    return EXIT_SUCCESS;
}
