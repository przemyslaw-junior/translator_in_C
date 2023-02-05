#include <stdlib.h>
#include <string.h>

#include "alphabet.h"
#include "colors.h"
#include "animals.h"
#include "numbers.h"
#include "months.h"
#include "days.h"

void statistic()
{
    int count_repeats = 0;
    int count_errors = 0;
    int count_correct = 0;

    count_repeats = count_repeats_letter + count_repeats_colors + count_repeats_animals + count_repeats_numbers + count_repeats_months + count_repeats_day;
    count_correct = count_correct_letter + count_correct_colors + count_correct_animals + count_correct_numbers + count_correct_months + count_correct_days;
    count_errors = count_errors_letter + count_errors_colors + count_errors_animals + count_errors_numbers + count_errors_months + count_errors_day;

    printf("Powtorzyles %d razy\n", count_repeats);
    printf("Odpowiedzi poprawnych bylo: %d \n", count_correct);
    printf("Odpowiedzi nie poprawnych bylo: %d \n", count_errors);
}