#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/cipher.h"

#define WINNINGSCORE 5
#define SHAPECOUNT 5

int main(int argc, char *argv[])
{
    int shapes[] = {'r', 'p', 's', 'o', 'l'};
    char computer;
    int score1, score2;
    score1 = score2 = 0;
    char choice;
    int winner;

    while (1) {
	printf("welcome to Rock paper spock lizard (RPSSL)\n (s) Single player\n (e) exit\nInput> ");
	choice = getchar();
	getchar();

	if (choice == 'e')
	    break;
	else if (choice != 's') {
	    printf("ERROR! Undefined option: %c\n", choice);
	    return EXIT_FAILURE;
	}

	while (score1 != WINNINGSCORE && score2 != WINNINGSCORE) {
	    printf("Choose a shape:\n [r]: rock, [p]: paper, [s]: scissors, [o]: spock, [l]: lizard\nInput> ");
	    choice = getchar();
	    getchar();

	    srand(time(NULL));
	    computer = shapes[(rand() % SHAPECOUNT)];
	    printf("%c vs %c!\n", choice, computer);
	    winner = shapeCmp(choice, computer);
	    if (winner == -1)
		printf("TIE!!!\n");
	    else if (winner)
		score1++;
	    else
		score2++;
	    printf("Current score: You: %d, Bot: %d\n", score1, score2);
	}
	if (score1 > score2)
	    printf("You win!\n");
	else
	    printf("Computer won :(\n");

    }

    return 0;
}
