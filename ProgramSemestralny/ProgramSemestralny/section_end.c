#include <stdlib.h>
#include <string.h>

char is_over;

void section_end(count_repetitions, count_correct, count_errors)
{
    puts("Czy chcesz zakonczyc ? Y/N");
    scanf_s("%c", &is_over, 1);
    getchar();

    if (is_over != 'Y' && is_over != 'y')
    {
        puts("Widze ze chcesz wiecej. Brawo");
    }
    else
    {
        puts("Milo mi sie z toba uczylo\nZobacz swoje statystyki");
        printf("Powtorzyles %d razy,\nw tym odpowiedzi poprwane: %d,\nodpowiedzi nie poprawne: %d\n\n", count_repetitions, count_correct, count_errors);
        puts("Wcisnij jakikolwiek klawisz aby przejsc do menu wyboru zagadnienia");
    }
}