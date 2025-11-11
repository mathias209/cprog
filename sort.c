#include <stdio.h>

#include "include/sort.h"

void bubble_sort(int* arr, int (*pair_is_in_order)(int a, int b), int length)
{
    int didswap = 1;
    while (didswap) {
	didswap = 0;
	for (int i = 0; i < length - 1; i++) {
	    if (!(*pair_is_in_order)(arr[i], arr[i + 1])) {
		swap(&arr[i], &arr[i + 1]);
		didswap = 1;
	    }
	}
    }
}

int numbers_in_ascending_order(int a, int b)
{
    return a < b ? 1 : 0;
}

int letters_in_order(int a, int b)
{
    if (a < 'a')
	a += 'a' - 'A';
    if (b < 'a')
	b += 'a' - 'A';

    // printf("%c < %c = %s\n", a, b, a < b ? "true" : "false");
    return a <= b ? 1 : 0;
}

void swap(int* a, int* b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
