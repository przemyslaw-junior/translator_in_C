
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "alphabet.h"
#include "section_end.h"

#define MAX_LETTER_SIZE 5

int count_repeats_letter = 0;
int count_correct_letter = 0;
int count_errors_letter = 0;

struct Translation
{
    char litera[MAX_LETTER_SIZE];
    char letter[MAX_LETTER_SIZE];
};

void alphabet_department()
{
    FILE* file;
    file = fopen("alphabet_data.txt", "r");
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
        fscanf(file, "%s %s", translations[i].litera, translations[i].letter);
    }

    do {
        puts("Wybierz litere z alfabetu");
        puts("Mozesz takze sprawdzic czy znasz wymowe i ja wpisac");
        puts("Tylko pamietaj nie uzywaj polskich znakow");

        char wordToTranslate[MAX_LETTER_SIZE];

        printf("Podaj litere: ");
        scanf("%s", wordToTranslate);
        getchar();

        count_repeats_letter++;

        bool exists = false;
        for (int i = 0; i < wordsCount; i++)
        {
            if (strcmp(wordToTranslate, translations[i].litera) == 0)
            {
                printf("%s = %s\n", wordToTranslate, translations[i].letter);
                count_correct_letter++;
                exists = true;
            }
            else  if (strcmp(wordToTranslate, translations[i].letter) == 0)
            {
                printf("%s = %s\n", wordToTranslate, translations[i].litera);
                count_correct_letter++;
                exists = true;
            }
        }
        if (exists == false)
        {
            printf("Blad to \"%s\" nie jest litera alfabetu \n", wordToTranslate);
            count_errors_letter++;
        }
        section_end(count_repeats_letter, count_correct_letter, count_errors_letter);

    } while (is_over != 'Y' && is_over != 'y');

    fclose(file);
    free(translations);
}