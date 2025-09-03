#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

void getlinesimple(char s[]);

int main()
{
    int motors = 0;
    float weight = 0.0;

    printf("How many motors are carrying the packages?: ");
    char buffer[MAXLINE];
    getlinesimple(buffer);
    motors = atoi(buffer);

    printf("How many kg of packages do we expect?: ");
    getlinesimple(buffer);
    weight = atof(buffer);

    if (weight / motors <= 5.6)
	printf("Yes! The conveyor belt can carry the packages.\n");
    else
	printf("No. The conveyor belt cannot carry the packages.\n");

    return 0;
}

void getlinesimple(char s[])
{
    int i = 0;
    char c;

    while ((c = getchar()) != '\n')
	s[i++] = c;

    s[i] = '\0';
}
