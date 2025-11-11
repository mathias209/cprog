#include <stdio.h>
#include "include/sort.h"

#define _countof(array) (sizeof(array) / sizeof(array[0]))

int main()
{
    int letter_arr1[] = {'z', 'S', 's', 'a'};
    // aSsz
    int number_arr1[] = {4, -1, 2, 9};
    // -1, 2, 4, 9

    bubble_sort(number_arr1, numbers_in_ascending_order, _countof(number_arr1));

    for (int i = 0; i < _countof(number_arr1); i++)
	printf("%d, ", number_arr1[i]);
    putchar('\n');

    bubble_sort(letter_arr1, letters_in_order, _countof(letter_arr1));

    for (int i = 0; i < _countof(letter_arr1); i++)
	printf("%c, ", letter_arr1[i]);
    putchar('\n');

    return 0;
}
