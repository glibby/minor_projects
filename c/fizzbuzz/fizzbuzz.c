/**
 * FILE: fizzbuzz.c
 * AUTHOR: Max Cooper
 * PURPOSE: Solve the classic fizzbuzz problem.
 * 	- Count from 1 to a certain number.
 * 	- On multiples of 3, print fizz
 * 	- Multiples of 5, print buzz
 * 	- Multiple of 3 and 5, print fizzbuzz
 */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s <number>\n", argv[0]);
		exit(-1);
	}

	int max_num = 0;
	int rem3 = 0;
	int rem5 = 0;

	max_num = atoi(argv[1]);

	printf("Printing numbers from 0 to %d\n", max_num);
	for (int i = 1; i < max_num; i++){
		rem3 = i % 3;
		rem5 = i % 5;
		if (rem3 == 0 && rem5 == 0) {
			printf("fizzbuzz\n");
			continue;
		} else if (rem3 == 0) {
			printf("fizz\n");
			continue;
		} else if (rem5 == 0) {
			printf("buzz\n");
			continue;
		}
		printf("%d\n", i);
	}
	printf("Done printing numbers\n");

	exit(0);
}
