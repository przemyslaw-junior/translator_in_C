// aby kompilator nie dodawa³ do pilku g³ównego juz  istniej¹cych zmiennych/funkcji
// nie powiela³ kompilacji kodu.
#pragma once
extern int count_repeats_letter;
extern int count_correct_letter;
extern int count_errors_letter;

void alphabet_department();