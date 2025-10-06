#include "include/cipher.h"

char ceasar(char c, int offset) {
    c += offset;
    if (c > 'z')
	c = 'a' + (c - 'z') - 1;
    else if (c < 'a')
	c = 'z' - ('a' - c - 1);
    return c;
}

char *ceasar_encrypt(char *plaintext)
{
    char *out = plaintext;

    for(;*out != '\0'; out++) {
	*out = ceasar(*out, 3);
    }

    return plaintext;
}

char *ceasar_decrypt(char *plaintext)
{
    char *out = plaintext;

    for(;*out != '\0'; out++) {
	*out = ceasar(*out, -3);
    }

    return plaintext;
}

char *viginere_encrypt(char *plaintext, char *key)
{
    char *out = plaintext;

    for(;*out != '\0'; out++, key++)
	*out = ceasar(*out, *key - 'a');

    return plaintext;
}

char *viginere_decrypt(char *plaintext, char *key)
{
    char *out = plaintext;

    for(;*out != '\0'; out++, key++)
	*out = ceasar(*out, -(*key - 'a'));

    return plaintext;
}
