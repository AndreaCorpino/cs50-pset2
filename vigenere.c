/********************************************************************************
 * pset2
 * vigenere.c
 *
 * Charul
 * Computer Science 50
 *
 * program to encrypt message where encription key is given by user
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>


/* prototypes */
void usage();


int main(int argc, char *argv[]) {
	// no arguments - print usage and exit
	if (argc != 2)
		usage();

	char *key = argv[1];

	//convert contents of the key array, from chars to numbers (0 to 25)
	int keylen = strlen(key); //strlen(key) works here

	for (int i = 0; i < keylen; i++)
	{
		if (isupper(key[i]))
			key[i] = key[i] - 'A';
		else if (islower(key[i]))
			key[i] = key[i] - 'a';
		else
			usage();
    }
	
    //the 'current position' of the key cursor.
	int pos = 0;

	//get input
	char *ptext = GetString();

	//the length of the plain text.
	int len = strlen(ptext);

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
		ptext[i] += key[pos];
		ptext[i] %= 26;
		ptext[i] += alpha;

		pos++;
		pos %= keylen;
	}
	printf("%s\n", ptext);
	free(ptext);
	
	return (EXIT_SUCCESS);
}

void usage(void) {
	printf("Usage: vigenere <keyword>. Where keyword is a-zA-Z.\n");
	exit(EXIT_FAILURE);
}

