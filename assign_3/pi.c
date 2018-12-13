/* Name: Joshua Noble
   Student #: 250700795
   
   This program approximates the mathematical
   constant pi using the area of a circle 
   and random number generation. 
   
   Note: Must be compiled with -lm option
   for use of math.h functions. */

// Use stdlib.h for rand/srand, math.h for sqrt, time.h for time
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Prototype function to calculate an estimate of pi
double estimate_pi(long long n);

int main(void) {
	int i, r;
	long long n;
	double pi, mean = 0, sd = 0;
	
	printf("Enter the value of N: ");
	r = scanf("%lld", &n);

	if (r != 1 || n <= 0) { // If a positive integer was not input
		printf("Error: Invalid input detected!\n");
		return 1; // Exit with error status 1
	}

	/* Set the seed for rand() calls, use current
	   time as seed, so multiple executions of
	   program yield different results (unless
	   they are executed in the same second) */
	srand(time(NULL));

	for (i = 0; i < 10; i++) { // Make 10 estimates of pi, using N = n
		pi = estimate_pi(n);
		printf("Estimate of pi: %.10f\n", pi);

		mean += pi; // Intermediate calc for mean
		sd += pi*pi; // Intermediate calc for sd
	}

	mean /= 10; // Final calc for mean
	sd = sqrt(sd / 10 - mean*mean); // Final calc for sd

	// Print formatted results for mean and sd
	printf("\nMean: %.10f\n", mean);
	printf("Standard Deviation: %.10f\n", sd);

	return 0;
}

// Function which estimates the value of pi using quadrant of a circle & N = n
double estimate_pi(long long n) {
	int i, count = 0;
	double x, y, temp, pi;
	
	for (i = 0; i < n; i++) { // Steps must be performed N = n times
		// Generate real numbers between [0,1] for x and y, cast to double to avoid integer division
		x = (double) rand() / RAND_MAX;
		y = (double) rand() / RAND_MAX;
		
		temp = x*x + y*y;
		
		if (temp <= 1) { // if x^2 + y^2 <= 1, (x,y) is in the shaded quadrant
			count++;
		}
	}

	// Estimate for pi is the ratio of points inside shaded quadrant to N, multiplied by 4
	pi = (double) count / n * 4; // Cast to double to avoid integer division
	
	return pi;
}
