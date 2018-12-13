/* Name: Joshua Noble
   Student #: 250700795
   
   This program uses a function pay_amount to
   determine the smallest number of $20, $10,
   $5, $2, and $1 bills/coins necessary to
   pay a dollar amount. */

#include <stdio.h>

// Function prototype for calculating change amount, parameters are passed by reference (except dollars)
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *lonnies);

int main(void) {
	int dollars, twenties, tens, fives, toonies, lonnies, r;

	printf("Enter a positive integer amount: $");
	r = scanf("%d", &dollars);
	
	if (r != 1 || dollars < 0) { // If a positive integer was not input
		printf("Error: Invalid input detected!\n");
		return 1; // Exit with error status 1
	}

	pay_amount(dollars, &twenties, &tens, &fives, &toonies, &lonnies); // Call function to calculate change, pass arguments by reference
	
	// Print formatted list of change due
	printf("\nChange Due\n----------\n");
	printf("Twenties: %d\nTens: %d\nFives: %d\nToonies: %d\nLonnies: %d\n", twenties, tens, fives, toonies, lonnies);
	
	return 0;
}

// Function which takes pointers as input parameters and stores the number of each bill/coin needed for change
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *lonnies) {
	*twenties = dollars / 20; // Number of a bill required is: dollars / bill value
	dollars = dollars % 20; // We use modulo operator to subtract the value of change that was previously calculated

	// Repeat above process for each bill/coin (in decreasing order of value)
	*tens = dollars / 10;
	dollars = dollars % 10;

	*fives = dollars / 5;
	dollars = dollars % 5;

	*toonies = dollars / 2;
	dollars = dollars % 2;

	// Since 1 lonnie = $1, the remaining value of dollars is the number of lonnies needed
	*lonnies = dollars;

	return;
}
