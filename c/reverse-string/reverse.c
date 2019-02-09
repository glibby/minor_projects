/**
 * FILE: reverse.c
 * AUTHOR: Max Cooper
 * PURPOSE: Reverses a string in place, then prints it.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
		fprintf(stderr, "usage: %s <string>\n", argv[0]);
		exit(-1);
	}

	// Copy string to be reversed in case argv[1] is needed later.
	char *rev_str = malloc(sizeof(char) * strlen(argv[1]));
	strcpy(rev_str, argv[1]);

	// Subtract 1 so the \0 isn't accidentally reversed.
	int end_ind = strlen(rev_str) - 1;
	int start_ind = 0;
	char temp = '\0';

	while (start_ind < end_ind) {
		temp = rev_str[start_ind];
		rev_str[start_ind] = rev_str[end_ind];
		rev_str[end_ind] = temp;

		start_ind += 1;
		end_ind -= 1;
	}

	printf("Reversed string: %s\n", rev_str);
	exit(0);
}
