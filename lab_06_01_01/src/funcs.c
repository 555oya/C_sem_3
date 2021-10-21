#include <stdio.h>
#include <string.h>
#include "funcs.h"

size_t is_matching(char *name_str, const char *prefix)
{
    char new_name_str[MAX_STR_SIZE] = "\0";
    size_t char_num = strlen(prefix);

    strncpy(new_name_str, name_str, char_num);

    if (strcmp(prefix, new_name_str) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

double get_density(double mass, double volume)
{
    return mass / volume;
}

void insert_element(struct substance item[], char *name_str, double mass, double volume, size_t count)
{
    size_t c = 0;

    while ((get_density(mass, volume) > get_density(item[c].mass, item[c].volume) ) && (c < count))// ПЕРЕПИСАТЬ ЧТОБЫ СИЧТАЛАСЬ ПЛОТНОСТЬ
    {
        c++;
    }

    if (c == count)
    {
        strcpy(item[c].name, name_str);
        item[c].mass = mass;
        item[c].volume = volume;
    }
    else
    {
        for (size_t i = count; i > c; i--)
        {
            strcpy(item[i].name, item[i - 1].name);
            item[i].mass = item[i - 1].mass;
            item[i].volume = item[i - 1].volume;
        }
        strcpy(item[c].name, name_str);
        item[c].mass = mass;
        item[c].volume = volume;
    }
}

void name(struct substance *item, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        for (size_t j = 0; j < strlen(item[i].name); j++)
        {
            if (item[i].name[j] == '\n')
            {
                item[i].name[j] = '\0';
            }
        }
    }
}

void print_whole_list(struct substance *item, size_t count)
{
    for (size_t i = 0; i < count; i++) 
    {
        printf("%s\n", item[i].name);
        printf("%lf\n", item[i].mass);
        printf("%lf\n", item[i].volume);
    }
}

size_t print_search_list(struct substance *item, size_t count, const char *prefix)
{
    size_t num = 0;

    for (size_t i = 0; i < count; i++)
    {
        if (is_matching(item[i].name, prefix))
        {
            printf("%s\n", item[i].name);
            printf("%lf\n", item[i].mass);
            printf("%lf\n", item[i].volume);

            num++;
        }
    }

    return num;
}
