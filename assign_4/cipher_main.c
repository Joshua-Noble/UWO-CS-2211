/* Name: Joshua Noble
   Student #: 250700795
   This program accepts a string of plain text
   as input from the user and encrypts it using
   the cipher selected by the user, displaying
   the results on the screen. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ciphers.h"

// Define the max length accepted as string input
#define MAX_LENGTH 100

int main(void) {
	// Variables are declared, memory is allocated for strings
	char *p, *q, *d, *plaintext = (char *) malloc(MAX_LENGTH * sizeof(char));
	char *keyString = (char *) malloc(MAX_LENGTH * sizeof(char));
	int i, r, choice, keyNum;
	char c;
	double letters[26];

	// fgets allows us to limit the number of chars from the user
	printf("Input plaintext (100 char max):\n");
	fgets(plaintext, MAX_LENGTH, stdin);

	// Need to remove the newline ('\n') character and add a null terminator after using fgets
	if ((strlen(plaintext) > 0) && (plaintext[strlen(plaintext) - 1] == '\n')) {
		plaintext[strlen(plaintext) - 1] = '\0';
	}

	printf("\nAvailable Ciphers:\n1) Caesar\n2) Vigenere\n");
	printf("\nSelect Cipher: ");

	// r will hold number of matched values, used for input validation
	r = scanf("%d", &choice);

	// Clear input buffer
	while (getchar() != '\n');
	
	// Check to make sure choice is a valid option
	if (r == 1 && choice == 1) { // If Caesar option is chosen
		// Reset value of r for re-use in input validation
		r = 0;

		printf("\nInput key as number: ");
		r = scanf("%d", &keyNum);
		
		// If we don't receive a valid number key, exit with error
		if (r != 1) {
			printf("Error: bad key!\n");
			return 1;
		}

		// Perform encryption/decryption, save results in pointers q/d, respectively
		q = caesar_encrypt(plaintext, keyNum);
		d = caesar_decrypt(q, keyNum);
	} else if (r == 1 && choice == 2) {
		printf("\nInput key as string:\n");
		scanf("%[^\n]", keyString);

		// Use p to iterate through keyString without losing starting location
		p = keyString;
		
		// Check to make sure only letters were input, otherwise exit with error
		while(*p != '\0') {
			if (!isalpha(*p)) {
				printf("Error: bad key, invalid char!\n");
				return 1;
			}
			p++;
		}
		
		// Perform encryption/decryption, save results in pointers q/d, respectively
		q = vigen_encrypt(plaintext, keyString);
		d = vigen_decrypt(q, keyString);
	} else {
		// Exit with error if choice is not a valid option
		printf("Error: bad selection!\n");
		return 1;
	}

	// Print all results to the screen
	printf("\nPlaintext:\n");
	printf("%s\n", plaintext);

	printf("\nCiphertext:\n");
	printf("%s\n", q);

	printf("\nDecrypted plaintext:\n");
	printf("%s\n", d);

	printf("\nFrequency analysis:\n");
	
	// Print letters for frequency table (you may have to increase terminal size for best results)
	for (c = 'A'; c <= 'Z'; ++c) {
		printf("%6c", c);
	} 

	printf("\n");

	// Perform frequency analysis
	freq_analysis(q, letters);

	// Print frequency of letters, after array has been modified
	for (i = 0; i < 26; i++) {
		printf("%6.1f", letters[i]);
	}

	printf("\n");

	// Free all dynamically allocated memory before exiting program
	free(q);
	free(d);
	free(plaintext);
	free(keyString);

	return 0;
}
