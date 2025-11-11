#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void simpleGetline(char s[], int maxlen);

int main()
{
    int nParts = 3;
    char *parts[] = { "hydraulic pump", "PLC module", "servo motor" };
    int stock[] = { 5, 5, 5 };

    char prompt[MAXLINE];


    printf("Hej. Welcome to the spare parts inventory! (type \"help\" for help)\n");
    while (1) {
	printf("prompt> ");
	simpleGetline(prompt, MAXLINE);
	int part = -1;
	for (int i = 0; i<nParts; i++)
	    if (strcmp(prompt, parts[i]) == 0) {
		part = i;
		break;
	    }
	if (part != -1 && stock[part] > 0) {
	    printf("I have got %s here for you :). Bye!\n", parts[part]);
	    stock[part]--;
	} else if (part != -1) {
	    printf("Sorry, %s is out of stock :(\n", parts[part]);
	} else if (strcmp(prompt, "list") == 0) {
	    for (int i = 0; i<nParts; i++)
		printf("%s: %d\n", parts[i], stock[i]);
	} else if (strcmp(prompt, "help") == 0) {
	    printf("Type name of part to buy\nType \"list\" for a list of parts and their stock\nType \"help\" for this help message\nType \"quit\" to exit program\n");
	} else if (strcmp(prompt, "quit") == 0) {
	    break;
	} else {
	    printf("ERROR: Invalid prompt: %s. Type \"help\" for help\n", prompt);
	}
    }

    return 0;
}

void simpleGetline(char s[], int maxlen)
{
    int i = 0;
    char c;

    while ((c = getchar()) != '\n')
	s[i++] = c;
    s[i] = '\0';
}
