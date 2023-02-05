#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "days.h"
#include "section_end.h"

#define MAX_WORD_SIZE 20

int count_repeats_day = 0;
int count_correct_days = 0;
int count_errors_day = 0;

struct Translation
{
    char dzien[MAX_WORD_SIZE];
    char day[MAX_WORD_SIZE];
};

void days_department()
{
    FILE* file;
    file = fopen("days_data.txt", "r");
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
        fscanf(file, "%s %s", translations[i].dzien, translations[i].day);
    }

    do {
        puts("Wybierz dzien z listy : \n1- poniedzialek   2- wtorek   3- sroda   4- czwartek   5- piatek   6- sobota   7- niedziela");
        puts("Mozesz sprobowac i wpisac slowo po angielsku");
        puts("Tylko pamietaj nie uzywaj polskich znakow");

        char wordToTranslate[MAX_WORD_SIZE];

        printf("Podaj nazwe dnia: ");
        scanf("%s", wordToTranslate);
        getchar();

        count_repeats_day++;

        bool exists = false;
        for (int i = 0; i < wordsCount; i++)
        {
            if (strcmp(wordToTranslate, translations[i].dzien) == 0)
            {
                printf("%s = %s\n", wordToTranslate, translations[i].day);
                count_correct_days++;
                exists = true;
            }
            else if (strcmp(wordToTranslate, translations[i].day) == 0)
            {
                printf("%s = %s\n", wordToTranslate, translations[i].dzien);
                count_correct_days++;
                exists = true;
            }
        }
        if (exists == false)
        {
            printf("Blad w slowie \"%s\" masz literowke albo slowo jest nie przetlumaczone \n", wordToTranslate);
            count_errors_day++;
        }
        section_end(count_repeats_day, count_correct_days, count_errors_day);

    } while (is_over != 'Y' && is_over != 'y');

    fclose(file);
    free(translations);
}