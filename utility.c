#include <ctype.h>
#include <time.h>

char *lower(char *plaintext)
{
    char *cur = plaintext;

    for(; *cur != '\0'; cur++) {
	*cur = tolower(*cur);
    }

    return plaintext;
}
