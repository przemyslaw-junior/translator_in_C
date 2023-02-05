#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "animals.h"
#include "section_end.h"

#define MAX_WORD_SIZE 20

int count_repeats_animals = 0;
int count_correct_animals = 0;
int count_errors_animals = 0;

struct Translation
{
    char zwierze[MAX_WORD_SIZE];
    char animal[MAX_WORD_SIZE];
};

void animals_department()
{
    FILE* file;
    file = fopen("animals_data.txt", "r");
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
        fscanf(file, "%s %s", translations[i].zwierze, translations[i].animal);
    }
       
    do {
        puts("Wybierz zwierze z listy : \n1- lew    2- niedzwiedz   3- owca    4- tygrys    5- zebra    6-lis");
        puts("Mozesz sprobowac i wpisac slowo po angielsku");
        puts("Tylko pamietaj nie uzywaj polskich znakow");

        char wordToTranslate[MAX_WORD_SIZE];

        printf("Podaj nazwe zwierzecia: ");
        scanf("%s", wordToTranslate);
        getchar();

        count_repeats_animals++;

        bool exists = false;
        for (int i = 0; i < wordsCount; i++)
        {
            if (strcmp(wordToTranslate, translations[i].zwierze) == 0)
            {
                printf("%s = %s\n", wordToTranslate, translations[i].animal);
                count_correct_animals++;
                exists = true;
            }
            else if (strcmp(wordToTranslate, translations[i].animal) == 0)
            {
                printf("%s = %s\n", wordToTranslate, translations[i].zwierze);
                count_correct_animals++;
                exists = true;
            }
        }
        if (exists == false)
        {
            printf("Blad w slowie \"%s\" masz literowke albo slowo jest nie przetlumaczone \n", wordToTranslate);
            count_errors_animals++;
        }
        section_end(count_repeats_animals, count_correct_animals, count_errors_animals);
            
    } while (is_over != 'Y' && is_over != 'y');
    
    fclose(file);
    free(translations);
}