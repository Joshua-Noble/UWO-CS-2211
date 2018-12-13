/* Name: Joshua Noble
   Student #: 250700795
   This header file contains the prototypes
   for all of the functions implemented in
   the ciphers.c file. The description of 
   each function is located above the
   implementation in the ciphers.c file. */

char * caesar_encrypt(char *plaintext, int key);

char * caesar_decrypt(char *ciphertext, int key);

char * vigen_encrypt(char *plaintext, char *key);

char * vigen_decrypt(char *ciphertext, char *key);

void freq_analysis(char *ciphertext, double letters[26]);


