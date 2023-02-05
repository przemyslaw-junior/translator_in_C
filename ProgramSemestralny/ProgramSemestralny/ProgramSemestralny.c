#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alphabet.h"
#include "colors.h"
#include "animals.h"
#include "numbers.h"
#include "months.h"
#include "days.h"
#include "section_end.h"
#include "statistic.h"

int main()
{
    int task;
    int end = 0;
    
    enum menu { alphabet = 1, colors, animals, numbers, months, days, the_end };

    do {
        printf("Wybierz zagadnienie\n %d- alfabet : alphabet\n %d- kolory : colors\n %d- zwierzeta : animals\n", alphabet, colors, animals);
        printf(" %d- liczby : numbers\n %d- miesiace : months\n %d- dni : days\n %d- koniec zajec\n", numbers, months, days, the_end);
        puts("Wybierz numer dzialu");

        scanf_s("%d", &task);
        getchar();

        switch (task)
        {
        case alphabet:
            alphabet_department();
            break;
        case colors:
            section_colors();
            break;
        case animals:
            animals_department();
            break;
        case numbers:
            numbers_division();
            break;
        case months:
            months_department();
            break;
        case days:
            days_department();
            break;
        case the_end:
            puts("Czy chcesz zakonczyc na dzis:  Y/N ");
            scanf_s("%c", &is_over, 1);
            getchar();
            if (is_over == 'Y' || is_over == 'y')
            {
                end = 1;
            }
            break;

        default: if (task > end);
            printf("poza zaksesem dzialu\n");
            break;
        }
    } while (end != 1);

    statistic();
    
    return 0;
}