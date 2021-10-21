#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

int main(int argc, char const *argv[])
{
    struct substance item[MAX_SUBSTANCE_NUM] = { { "\0", 0, 0 } }; //15 записей максимально
    size_t count = 0;
    char name_str[MAX_STR_SIZE] = "";
    double mass;
    double volume;
    long abuba = 0;

    FILE *f;
    //проверка количества параметров
    if ((argc > 3) || (argc < 2))  
    {
        printf("ERR invalid number of args\n");
        return -1;
    }
    //открывает файл для чтения
    f = fopen(argv[1], "r"); 

    if (f == NULL)
    {
        printf("ERR file\n");
        return -1;
    }
    //проверяет длину аргумента имени
    if ((argc == 3) && (strlen(argv[2]) > MAX_STR_SIZE - 1))
    {
        printf("ERR arg len\n");
        fclose(f);
        return -1;
    }
    // проверяет наличие поля сортировки  ПЕРЕНЕСТИ ПОСЛЕ СЧИТЫВАНИЯ ФАЙЛА
    /*
    if (strcmp(argv[2], "ALL") != 0)
    {
        printf("show all structures");
        fclose(f);
        return -1;
    }
    */
    abuba = fscanf(f, "%25s", name_str);

    if (abuba == EOF)
    {
        printf("ERR empty file\n");
        return -1;
    }

    //начинает считывать файл по строкам
    while (abuba != EOF)
    {
        //abuba = fscanf(f, "%s", name_str);
        //printf("%s\n", name_str);

        if (!abuba)
        {
            printf("ERR abuba\n");
            return -1;
        }

        if (count == 15) //15 записей возможно
        {
            printf("ERR 15 str\n");
            fclose(f);
            return -1;
        }

        if (strlen(name_str) > MAX_STR_SIZE) //если название длиннее 25 символов -> ошибка
        {
            printf("ERR invalid input\n");
            printf("%zu", count);
            fclose(f);
            return -1;
        }

        abuba = fscanf(f, "%lf", &mass);

        if ((!abuba) || (abuba == EOF)) //если считывание массы зафакапилось -> ошибка
        {
            printf("ERR invalid input\n");
            fclose(f);
            return -1;
        }

        abuba = fscanf(f, "%lf", &volume);

        if ((!abuba) || (abuba == EOF)) //если считывание объема зафакапилось -> ошибка
        {
            printf("ERR invalid input\n");
            fclose(f);
            return -1;
        }

        //printf("??????");
        //printf("%s", name_str);
        /*
        strcpy(item[count].name, name_str);
        item[count].mass = mass;
        item[count].volume = volume;*/
        // если prefix all, то просто копируем по порядку ДОБАВИТЬ РАЗДЕЛЕНИЕ ЕСЛИ ПРЕФИКС НЕ ОЛЛ
        
        switch (argc)
        {
            case 3:
                strcpy(item[count].name, name_str);
                item[count].mass = mass;
                item[count].volume = volume;
                break;

            case 2:
                insert_element(item, name_str, mass, volume, count);
                break;
        }

        /*
        if ((argc == 3) && (strcmp(argv[2], "ALL") == 0))
        {
            strcpy(item[count].name, name_str);
            item[count].mass = mass;
            item[count].volume = volume;
        }
        else //иначе сортируем
        {
            insert_element(item, name_str, mass, volume, count);
        }
        */
        //printf("структура %zu\n", count);

        count++;

        //printf("структура %zu\n", count);

        abuba = fscanf(f, "%25s", name_str);
    }
    /*
    if ((argc == 3) && (strcmp(argv[2], "ALL") != 0) && (matching_num == 0))
    {
        printf("No names starting with \"%s\" were found", argv[2]);
        fclose(f);
        return -1;
    }
*/
    //name(item, count); //убирает символ табуляции

    if((argc == 3) && (strcmp(argv[2], "ALL") != 0))
    {
        if(!print_search_list(item, count, argv[2]))
        {
            printf("ERR no name found\n");
            return -1;
        }
    }
    else
    {
        print_whole_list(item, count);
    }

    fclose(f);

    return 0;
}
