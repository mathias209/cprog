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

    int sums[12];

    for (int i = 0; i < ITERATIONS; i++)
	sums[rannum(0,6) + rannum(0,6)]++;

    for (int i = 0; i < 11; i++)
	printf("%d: %d\n", i+2, sums[i+1]);

    return 0;
}
