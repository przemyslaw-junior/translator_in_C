#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "colors.h"
#include "section_end.h"

#define MAX_WORD_SIZE 20

int count_repeats_colors = 0;
int count_correct_colors = 0;
int count_errors_colors = 0;

struct Translation
{
    char kolor[MAX_WORD_SIZE];
    char colors[MAX_WORD_SIZE];
};

void section_colors()
{
    FILE* file;
    file = fopen("colors_data.txt", "r");
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
        fscanf(file, "%s %s", translations[i].kolor, translations[i].colors);
    }
    
    do {
        puts("Wybierz kolor z listy :\n1- bialy  2- czarny  3- szary  4- zolty  5- pomaranczowy");
        puts("6- brazowy  7- czerwony 8- rozowy  9- fioletowy");
        puts("10- niebieski  11- zielony  12- srebrny ");
        puts("Mozesz sprobowac i wpisac slowo po angielsku");
        puts("Tylko pamietaj nie uzywaj polskich znakow");

        char wordToTranslate[MAX_WORD_SIZE];

        printf("Podaj nazwe koloru: ");
        scanf("%s", wordToTranslate);
        getchar();

        count_repeats_colors++;

        bool exists = false;
        for (int i = 0; i < wordsCount; i++)
        {
            if (strcmp(wordToTranslate, translations[i].kolor) == 0)
            {
                printf("%s = %s\n", wordToTranslate, translations[i].colors);
                count_correct_colors++;
                exists = true;
            }
            else if (strcmp(wordToTranslate, translations[i].colors) == 0)
            {
                printf("%s = %s\n", wordToTranslate, translations[i].kolor);
                count_correct_colors++;
                exists = true;
            }
        }
        if (exists == false)
        {
            printf("Blad w slowie \"%s\" masz literowke albo slowo jest nie przetlumaczone \n", wordToTranslate);
            count_errors_colors++;
        }

        section_end(count_repeats_colors, count_correct_colors, count_errors_colors);

    } while (is_over != 'Y' && is_over != 'y');

    fclose(file);
    free(translations);
}