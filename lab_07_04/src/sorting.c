#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compar_func(const void *a, const void *b)
{
    if ((*(int *)a) < (*(int *)b))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void mysort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))
{
    void *p_curr = base;
    void *p_curr_2 = base;
    void *buff = malloc(size);
    size_t r_end = nitems - 1;
    size_t l_end = nitems - 1;
    size_t last_right_swap = r_end;
    size_t last_left_swap = l_end;

    for (size_t i = 0; i < (nitems / 2); i++)
    {
        if (i % 2 == 0)
        {
            p_curr_2 = base;
            p_curr = ((char *) p_curr) + size;

            for (size_t j = 0; j < r_end; j++)
            {
                if (compar(p_curr, p_curr_2))
                {
                    memmove(buff, p_curr, size);
                    memmove(p_curr, p_curr_2, size);
                    memmove(p_curr_2, buff, size);
                    last_right_swap = j;
                }

                p_curr_2 = ((char *) p_curr_2) + size;
                p_curr = ((char *) p_curr) + size;
            }
            r_end = last_right_swap;
        }
        else
        {
            p_curr = ((char *) base) + (nitems - 1) * size;
            p_curr_2 = ((char *) base) + (nitems - 2) * size;

            for (size_t j = 0; j < l_end; j++)
            {
                if (compar(p_curr, p_curr_2))
                {
                    memmove(buff, p_curr, size);
                    memmove(p_curr, p_curr_2, size);
                    memmove(p_curr_2, buff, size);
                    last_left_swap = j;
                }

                p_curr_2 = ((char *) p_curr_2) - size;
                p_curr = ((char *) p_curr) - size;
            }
            l_end = last_left_swap;
        }
    }

    free(buff);
}
