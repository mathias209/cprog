#ifndef CIPHERH
#define CIPHERH

char ceasar(char c, int offset);
char *ceasar_encrypt(char *plaintext);
char *ceasar_decrypt(char *plaintext);
char *viginere_encrypt(char *plaintext, char *key);
char *viginere_decrypt(char *plaintext, char *key);
char *lower(char *plaintext);

#endif
