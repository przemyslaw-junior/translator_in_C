// aby kompilator nie dodawa� do pilku g��wnego juz  istniej�cych zmiennych/funkcji
// nie powiela� kompilacji kodu.
#pragma once
extern int count_repeats_letter;
extern int count_correct_letter;
extern int count_errors_letter;

void alphabet_department();