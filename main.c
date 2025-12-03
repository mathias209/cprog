#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ITERATIONS 50000

int rannum(int min, int max)
{
    return rand() % (max + 1 - min) + min;
}

int main()
{
    srand(time(NULL));

    int sums[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

    for (int i = 0; i < ITERATIONS; i++)
	sums[rannum(1,6) + rannum(1,6) - 1]++;

    int total = 0;
    for (int i = 0; i < 11; i++) {
	total += sums[i+1];
	printf("%d: %d\n", i+2, sums[i+1]);
    }
    printf("Total (should be 50000): %d\n", total);

    return 0;
}
