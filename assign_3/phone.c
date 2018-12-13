/* Name: Joshua Noble
   Student #: 250700795
   
   This program accepts a 10 digit phone
   number via standard input and formats
   it according to the user's selection. */

#include <stdio.h>

int main(void) {
	int r, x, y, z;	
	char option;

	printf("Input Phone Number: ");

	// scanf returns # of matches, save to r for future validation
	r = scanf("%3d%3d%4d", &x, &y, &z);

	// Error code of 1 is returned if the format of the number is not valid
	if (r != 3) { // Make sure exactly 3 matches were found
		printf("\nError: Invalid Phone Number!\n");
		return 1;	
	} else if (x < 100 || x > 999) { // Check area code has 3 digits, doesn't start with 0
		printf("\nError: Invalid Phone Number!\n");
		return 1;
	} else if (y < 100 || y > 999) { // Check central office code has 3 digits, doesn't start with 0
		printf("\nError: Invalid Phone Number!\n");
		return 1;
	} else if (z < 1000 || z > 9999) { // Check line number has 3 digitss, doesn't start with 0
		printf("\nError: Invalid Phone Number!\n");
		return 1;
	}

	printf("\nFormat Options:\nA) Local\nB) Domestic\nC) International\nD) Odd\n");
	printf("\nInput Option: ");

	/* This preliminary scanf will clear all characters from the input
	   buffer, up to the newline ('\n') character. This is because there
	   can still be characters left on the input buffer from the 
	   previous scanf call */
	scanf("%*[^\n]");

	/* Use a leading space in front of %c so scanf will accept and 
	   discard the whitespace (including '\n') left on the input buffer */
	scanf(" %c", &option);

	// Use a switch to handle each of the menu options
	switch (option) {
		case 'a': // Lower case letters mimic behaviour of uppercase by removing 'break'
		case 'A':
			printf("\nPhone Number: %d-%d\n", y, z);
			break;
		case 'b':
		case 'B':
			printf("\nPhone Number: (%d) %d-%d\n", x, y, z);
			break;
		case 'c':
		case 'C':
			printf("\nPhone Number: +1-%d-%d-%d\n", x, y, z);
			break;
		case 'd':
		case 'D':
			printf("\nPhone Number: %6.4d%6.4d%6.4d\n", x, y, z);
			break;
		default: // Handle all other cases with default
			printf("\nError: Invalid Option!\n");
			return 1;
	}

	return 0;
}
