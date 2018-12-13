/* Name: Joshua Noble
   Student #: 250700795
   This file contains the implementations
   of the functions prototyped in the
   ciphers.h header file. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ciphers.h"

// This function encrypts the given text using the Caesar Cipher with
// the given key and returns a pointer to the newly encrypted text
char * caesar_encrypt(char *plaintext, int key) {
	char *ciphertext, *p = (char *) malloc((strlen(plaintext) + 1) * sizeof(char));
	int count = 0;

	// Check memory allocation
	if (p == NULL) {
		printf("Error allocating memory!\n");
		exit(EXIT_FAILURE);
	}

	// Hold starting location of pointer
	ciphertext = p;	

	// Copy string so we don't alter original
	strcpy(p, plaintext);

	// Loop through each character, encrypt using key
	while (*p != '\0') {
		if (isalpha(*p)) {
			*p = toupper(*p);
			
			// If negative key, need to modify encryption formula
			if (key >= 0) {
				*p = (*p - 'A' + key) % 26 + 'A';
			} else {
				count = abs(key) / 26;
				
				// To handle cases of negative numbers > 26
				if (count > 0) {
					*p = (*p - 'A' + key + ((count + 1) * 26)) % 26 + 'A';
				} else {
					*p = (*p - 'A' + key + 26) % 26 + 'A';
				}
				
			}
		}
		p++;
	}

	// Add null terminator
	*(ciphertext + strlen(plaintext)) = '\0';

	return ciphertext;
}

// This function decrypts the given text using the Caesar Cipher with
// the given key and returns a pointer to the newly decrypted text
char * caesar_decrypt(char *ciphertext, int key) {
	char *p = (char *) malloc((strlen(ciphertext) + 1) * sizeof(char));	

	// Check memory allocation
	if (p == NULL) {
		printf("Error allocating memory!\n");
		exit(EXIT_FAILURE);
	}

	// Use encryption function with negative key
	p = caesar_encrypt(ciphertext, -key);

	return p;
}

// This function encrypts the given text using the Vigenere Cipher with
// the given key and returns a pointer to the newly encrypted text
char * vigen_encrypt(char *plaintext, char *key) {
	char *ciphertext, *p = (char *) malloc((strlen(plaintext) + 1) * sizeof(char));
	char *keyPlace, *q = (char *) malloc((strlen(key) + 1) * sizeof(char));

	// Check memory allocation
	if (p == NULL || q == NULL) {
		printf("Error allocating memory!\n");
		exit(EXIT_FAILURE);
	}

	// Hold starting location of string and key
	ciphertext = p;	
	keyPlace = q;

	// Copy string and key so we don't alter original
	strcpy(p, plaintext);
	strcpy(q, key);

	// Loop through each character, apply encryption using string key
	while (*p != '\0') {
		// This statement allows us to repeat the string key with padding, if it is too short
		if (*q == '\0') {
			q = keyPlace;
		}

		// Only apply encryption to letters
		if (isalpha(*p)) {
			*p = toupper(*p);
			*q = toupper(*q);
			*p = (*p - 'A' + *q - 'A') % 26 + 'A';
		}

		p++;
		q++;
	}

	// Add null terminator
	*(ciphertext + strlen(plaintext)) = '\0';

	return ciphertext;
}

// This function decrypts the given text using the Vigenere Cipher with
// the given key and returns a pointer to the newly decrypted text
char * vigen_decrypt(char *ciphertext, char *key) {
	char *plaintext, *p = (char *) malloc((strlen(ciphertext) + 1) * sizeof(char));
	char *keyPlace, *q = (char *) malloc((strlen(key) + 1) * sizeof(char));

	// Check memory allocation
	if (p == NULL || q == NULL) {
		printf("Error allocating memory!\n");
		exit(EXIT_FAILURE);
	}

	// Hold starting location of pointer and key
	plaintext = p;	
	keyPlace = q;

	// Copy string and key so we don't alter originals
	strcpy(p, ciphertext);
	strcpy(q, key);

	// Loop through each character, apply encryption using string key
	while (*p != '\0') {
		// This statement allows us to repeat the string key with padding, if it is too short
		if (*q == '\0') {
			q = keyPlace;
		}

		// Only apply encryption to letters
		if (isalpha(*p)) {
			*p = toupper(*p);
			*q = toupper(*q);
			*p = (*p - 'A' - (*q - 'A') + 26) % 26 + 'A';
		}
		p++;
		q++;
	}

	// Add null terminator
	*(plaintext + strlen(ciphertext)) = '\0';

	return plaintext;
}

// This function counts the frequency of each letter in a given string
// and stores the percentage occurrence in the given array
void freq_analysis(char *ciphertext, double letters[26]) {
	char *p = (char *) malloc((strlen(ciphertext) + 1) * sizeof(char));
	int i, count = 0, len = strlen(ciphertext);

	// Check memory allocation
	if (p == NULL) {
		printf("Error allocating memory!\n");
		exit(EXIT_FAILURE);
	}

	// Copy string so we don't alter original
	strcpy(p, ciphertext);

	// Initialize/reset all values to 0	
	for (i = 0; i < 26; i++) {
		*(letters + i) = 0;
	}

	// Count occurences of each letter
	for (i = 0; i < len; i++) {
		if (isalpha(*(p + i))) {
			*(letters + (toupper(*(p + i)) - 'A')) += 1;
			count++;
		}
	}

	// Convert count of each letter to percentage
	for (i = 0; i < 26; i++) {
		*(letters + i) /= count;
		*(letters + i) *= 100;
	}

	// Since we aren't returning the pointer, free memory here to avoid memory leak
	free(p);
}
