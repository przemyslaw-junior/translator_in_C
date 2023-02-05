#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "months.h"
#include "section_end.h"

#define MAX_WORD_SIZE 20

int count_repeats_months = 0;
int count_correct_months = 0;
int count_errors_months = 0;

struct Translation
{
    char miesiac[MAX_WORD_SIZE];
    char month[MAX_WORD_SIZE];
};

void months_department()
{
    FILE* file;
    file = fopen("months_data.txt", "r");
    if (file == NULL)
    {
        printf("Nie mozna otworzyc pliku\n");
        return 1;
    }

    int wordsCount;
    fscanf(file, "%d", &wordsCount);

    struct Translation* translations = (struct Translation*)malloc(sizeof(struct Translation) * wordsCount);

    for (int i = 0; i < wordsCount; i++)
    {
        fscanf(file, "%s %s", translations[i].miesiac, translations[i].month);
    }

    do {
        puts("Wybierz miesiac z listy :\n1- styczen  2- luty  3- marzec  4- kwiecien 5- maj  6- czerwiec");
        puts("7- lipiec  8- sierpien 9- wrzesien  10- pazdziernik  11- listopad  12- grudzien");
        puts("Mozesz sprobowac i wpisac slowo po angielsku");
        puts("Tylko pamietaj nie uzywaj polskich znakow");

        char wordToTranslate[MAX_WORD_SIZE];
        
        printf("Podaj nazwe miesiaca: ");
        scanf("%s", wordToTranslate);
        getchar();

        count_repeats_months++;

        bool exists = false;
        for (int i = 0; i < wordsCount; i++)
        {
            if (strcmp(wordToTranslate, translations[i].miesiac) == 0)
            {
                printf("%s = %s\n", wordToTranslate, translations[i].month);
                count_correct_months++;
                exists = true;
            }
            else if (strcmp(wordToTranslate, translations[i].month) == 0)
            {
                printf("%s = %s\n", wordToTranslate, translations[i].miesiac);
                count_correct_months++;
                exists = true;
            }
        }
        if (exists == false)
        {
            printf("blad w slowie \"%s\" masz literowke albo slowo jest nie przetlumaczone \n", wordToTranslate);
            count_errors_months++;
        }

        section_end(count_repeats_months, count_correct_months, count_errors_months);

    } while (is_over != 'Y' && is_over != 'y');

    fclose(file);
    free(translations);
}