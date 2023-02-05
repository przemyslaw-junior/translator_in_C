#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "numbers.h"
#include "section_end.h"

#define MAX_WORD_SIZE 20

int count_repeats_numbers = 0;
int count_correct_numbers = 0;
int count_errors_numbers = 0;

struct Translation
{
    char liczba[MAX_WORD_SIZE];
    char numbers[MAX_WORD_SIZE];
};

void numbers_division()
{
    FILE* file;
    file = fopen("numbers_data.txt", "r");
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
        fscanf(file, "%s %s", translations[i].liczba, translations[i].numbers);
    }

    do {
        puts("Wybierz liczbe od 0 do 10 tylko napisz slownie");
        puts("Mozesz sprobowac i wpisac slowo po angielsku");
        puts("Tylko pamietaj nie uzywaj polskich znakow");

        char wordToTranslate[MAX_WORD_SIZE];

        printf("Podaj nazwe liczby: ");
        scanf("%s", wordToTranslate);
        getchar();

        count_repeats_numbers++;

        bool exists = false;
        for (int i = 0; i < wordsCount; i++)
        {
            if (strcmp(wordToTranslate, translations[i].liczba) == 0)
            {
                printf("%s = %s\n", wordToTranslate, translations[i].numbers);
                count_correct_numbers++;
                exists = true;
            }
            else if (strcmp(wordToTranslate, translations[i].numbers) == 0)
            {
                printf("%s = %s\n", wordToTranslate, translations[i].liczba);
                count_correct_numbers++;
                exists = true;
            }
        }
        if (exists == false)
        {
            printf("Blad w slowie \"%s\" masz literowke albo slowo jest nie przetlumaczone \n", wordToTranslate);
            count_errors_numbers++;
        }
        section_end(count_repeats_numbers, count_correct_numbers, count_errors_numbers);

    } while (is_over != 'Y' && is_over != 'y');

    fclose(file);
    free(translations);
}