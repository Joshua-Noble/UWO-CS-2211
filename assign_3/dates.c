/* Name: Joshua Noble
   Student #: 250700795
   
   This program accepts any number of dates
   and determines which of the entered
   dates comes later on the calendar. */

#include <stdio.h>

// Function prototype to save latest date
void setLatest(int mm, int dd, int yy, int *mmLate, int *ddLate, int *yyLate);

int main(void) {
	int mm, dd, yy, r, mmLate = 0, ddLate = 0, yyLate = 0;

	// Infinite loop which will continue to request user input until exited via break or return (conditions below)
	while (1) {
		printf("Enter a date (mm/dd/yy): ");
		r = scanf("%d/%d/%d", &mm, &dd, &yy);
		
		if (r != 3) { // If 3 matching inputs were not found
			printf("Error: Invalid date format!\n");
			while (getchar() != '\n'); // Clear buffer of non-matching chars
		} else if (mm == 0 && dd == 0 && yy == 0) { // Exit condition, user enters 0/0/0
			if (mmLate == 0) {
				printf("Error: At least one date must be input!\n");
				return 1; // If mmLate is still 0, then no date has been input yet, exit with error status 1
			} else {
				break; // Otherwise, exit the loop
			}
		} else if (!(mm >= 1 && mm <= 12)) { // Check for valid month
			printf("Error: Invalid month number!\n");
		} else if (!(dd >= 1 && dd <= 31)) { // Check for valid day
			printf("Error: Invalid day number!\n");
		} else if (!(yy >= 0 && yy <= 99)) { // Check for valid year
			printf("Error: Invalid year number!\n");
		} else {
			if (yy > yyLate) { // These comparisons first check the year, then month, then date, to find latest
				setLatest(mm, dd, yy, &mmLate, &ddLate, &yyLate);
			} else if ( yy == yyLate && mm > mmLate) {
				setLatest(mm, dd, yy, &mmLate, &ddLate, &yyLate);
			} else if (yy == yyLate && mm == mmLate && dd > ddLate) {
				setLatest(mm, dd, yy, &mmLate, &ddLate, &yyLate);
			}
		}
	}

	// Formatted date is printed with padded zeroes
	printf("%02d/%02d/%02d is the latest date\n", mmLate, ddLate, yyLate);
	return 0;
}

// Function that sets the values of the latest date by taking mmLate, ddLate, yyLate by reference (using pointers)
void setLatest(int mm, int dd, int yy, int *mmLate, int *ddLate, int *yyLate) {
	*mmLate = mm;
	*ddLate = dd;
	*yyLate = yy;
	
	return;
}
