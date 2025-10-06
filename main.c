#include <stdio.h>

#include "include/cipher.h"

int main(int argc, char *argv[])
{
    if (argc == 1) {
	printf("Synopsis:\n\tcipher MODE ALGORITHM [KEY]\n\nModes:\n\te, encrypt\tEncrypt the input text\n\td, decrypt\tDecrypt the input text\n\nAlgorithms:\n\tc, caesar\tCaesar cipher\n\tv, vigenere\tVigenère cipher\n");
	return 0;
    }

    if (*argv[1] == 'e') {
	if (*argv[2] == 'c' && argc == 4)
	    printf("%s\n", ceasar_encrypt(lower(argv[3])));
	else if (*argv[2] == 'v' && argc == 5)
	    printf("%s\n", viginere_encrypt(lower(argv[3]), lower(argv[4])));
	else
	    printf("ERROR! Malformed command. Potentially missing a key?\n");
    } else if (*argv[1] == 'd') {
	if (*argv[2] == 'c' && argc == 4)
	    printf("%s\n", ceasar_decrypt(lower(argv[3])));
	else if (*argv[2] == 'v' && argc == 5)
	    printf("%s\n", viginere_decrypt(lower(argv[3]), lower(argv[4])));
	else
	    printf("ERROR! Malformed command. Potentially missing a key?\n");
    }

    return 0;
}
