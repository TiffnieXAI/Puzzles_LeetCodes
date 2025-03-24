#include <stdio.h>
#include <math.h>

/* 
 * Program Title: Reverse an Integer
 * Description: This program takes an integer as input and reverses its digits.
 * The reversal is achieved by extracting the last digit using modulo operation,
 * then multiplying the current reversed number by 10 to shift its digits left, 
 * and adding the extracted digit to the ones place of the reversed number.
 * This continues until the original number becomes 0, and the reversed number is printed.
 */

int main(){

	int n, last, reversed = 0;
	printf("Input:\t");
	scanf("%d", &n);

	// Reversing the number
	while (n != 0) {
		last = n % 10; // Extract the last element

        // Increase the place value here by multiplying by 10 to shift current digits, 
        // then add the last digit to the ones place
        reversed = reversed * 10 + last; 

		// Update the element to remove the last digit so we can simply extract the remaining digits
		n = n / 10;
	}

    // Output the reversed number
    printf("Reversed: %d\n", reversed); 

}
