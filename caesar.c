/****************************************************************
 * pset2
 * caesar.c
 * 
 * Charul
 * Computer Science 50
 *
 * program to encrypt a message
 ***************************************************************/

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* prototypes */
void usage(char *me);

int main(int argc, char *argv[]) {
	// no arguments - print usage and exit
	if (argc != 2)
		usage(argv[0]);

	char *key = argv[1];
	int len = strlen(key);

	//checks if argument is a positive integer
	for (int i = 0; i < len; i++)
	{
		if (!(isdigit(key[i])))
			usage(argv[0]);
	}

	int k = atoi(argv[1]);

	//this probably means the user gave me a number > 2 billion... atoi does not have error handling, strtol does. Abort in this case.
	if (k < 0)
		usage(argv[0]);

	//key > 26 can be simplified. ie k26 == k0, k27 == k1.
	//k %= 26; // but unnecessary.

	//get input
	char *ptext = GetString();

	//reuse len
	len = strlen(ptext);

	//loop through ptext, apply cipher in-place.
	for (int i = 0; i < len; i++)
	{
		char alpha;
		if (isupper(ptext[i]))
			alpha = 'A';
		else if (islower(ptext[i]))
			alpha = 'a';
		else
			continue; // not alphanumeric.
		ptext[i] -= alpha;
		ptext[i] += k;
		ptext[i] %= 26;
		ptext[i] += alpha;
	}
	printf("%s\n", ptext);

	return (EXIT_SUCCESS);
}

void usage(char *me) {
	printf("Usage: %s N. Where N is the rotation key, ie. a positive integer.\n", me);
	exit(EXIT_FAILURE);
}

