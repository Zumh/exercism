#include "square_root.h"
int square_root(int number){
	/*In this implementation, we initialize the initial guess to (current + 1) / 2. 
	 * Then, we repeatedly update 'guess' using the formula guess = (guess + current / guess) / 2 until guess no longer changes, 
	 * which indicates that we have found a close approximation of the square root.
	 * */
	int current = number;

	int guess = (current + 1) /2; // Initial guess
	
	while (guess < current){
		current = guess;
		// re-calculate next guess
		guess = (current + (number / current)) / 2;
	}

	return current;
}
