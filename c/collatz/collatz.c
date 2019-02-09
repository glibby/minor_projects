/**
 * FILE: collatz.c
 * AUTHOR: Max Cooper
 * PURPOSE: Performs operations on a given number following the Collatz
 * conjecture. The Collatz conjecture states that if you take any number n
 * that is greater than 1 and follow the sequence:
 * 	- If n is even, the next value is n/2
 * 	- If n is odd, the next value is (n*3) + 1
 * 
 * you shall eventually reach 1. This algorithm was proven to be true for numbers
 * <= about 5.48 * pow(10, 18), so any value that you can fit in a u64 ought to
 * work.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s <number>", argv[0]);
		exit(-1);
	}

	uint64_t col_int = strtoull(argv[1], NULL, 10);
	uint32_t step_count = 0;
	uint8_t rem = 0;

	while (col_int > 1) {
		step_count++;
		rem = col_int & 0x1;
		col_int = rem > 0 ? (col_int * 3) + 1 : col_int / 2;
	}

	printf("It took %u steps to reduce the number to 1.\n", step_count);
	exit(0);
}
