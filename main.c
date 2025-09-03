#include <stdio.h>
#include <stdlib.h>

int main()
{
    int motors = 0;
    float weight = 0.0;

    printf("How many motors are carrying the packages?: ");
    scanf("%d", &motors);

    printf("How many kg of packages do we expect?: ");
    scanf("%g", &weight);

    if (weight / motors <= 5.6)
	printf("Yes! The conveyor belt can carry the packages.\n");
    else
	printf("No. The conveyor belt cannot carry the packages.\n");

    return 0;
}
