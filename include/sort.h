#ifndef SORT_H
#define SORT_H

void bubble_sort(int* arr, int (*pair_is_in_order)(int a, int b), int length);
int numbers_in_ascending_order(int a, int b);
int letters_in_order(int a, int b);
void swap(int* a, int* b);

#endif
