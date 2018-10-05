#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char encrypt(char ch, int k);

int main(int argc, char* argv[])
{
	/* Choice is the choice for encryption or decription, keyLength is the size of the key. */
	int choice, keyLength;

	/* These are the in files and out files. */
	FILE *fin, *fout;

	/* ch is used to get the in file string character by character. */
	char ch;

	/* This is a char array which will hold the actual key values. */
	char* cipher;

	/* This counter is used for the key, to cycle through the different keys. */
	int counter;
	
	/* There needs to be 5 arguments that the user inputs:
	 * 	1. This is the compiled file, we don't use this.
	 * 	2. This is the option for encryption or decryption (1 or 2).
	 * 	3. This is the actual key input by the user. (Ex: fab).
	 * 	4. This is the input file.
	 * 	5. This is the output file.
	 */
	if (argc != 5)
	{
		printf ("Usage: cipher option key infile, outfile\n");
		printf ("Option 1 for encryption and 2 for decryption");
		exit(1);
	}
	
	//Sets the choice equal to whatever the user input for the first argument.
	choice = atoi(argv[1]);

	//Creates a cipher equal to the length of argv[2], which holds the input key string.
	cipher = (char *)malloc(strlen(argv[2]) * sizeof(char));

	//Sets cipher equal to argv, so we dereference argv[2].
	cipher = argv[2];

	//Gets the length that cipher should be.
	keyLength = strlen(cipher);
	
	/*	
	//This for loop will set the key values to 0-25. This is so the encryption function works correctly.
	//This code only works if the input is letters for actual chars, not numbers. Due to being numbers, offset is always 48.
	for (int i = 0; i < keyLength; i++) 		
		if (isupper(cipher[i]))
			cipher[i] -= 65;
		else
			cipher[i] -= 97;
	*/

	for (int i = 0; i < keyLength; i++)
		cipher[i] -= 48;
	//If the choice is 2, reverse all keys to negative. This will de-encrypt the input string.
	if (choice == 2)
		for (int i = 0; i < keyLength; i++)
			cipher[i] = -cipher[i];

	//Open the files for reading and writing.
    	fin = fopen(argv[3], "r");
	fout = fopen(argv[4], "w");
    
	//If there was an error opening the file, then exit.
    	if (fin ==  NULL || fout == NULL) 
	{
		printf("File could not be opened\n");
		exit(1);
	}
	
	//Initial the counter, and get the values from encrypt function.
	counter = 0;
	while ( fscanf(fin, "%c", &ch) != EOF )
	{
		fprintf(fout, "%c", encrypt(ch, cipher[counter % keyLength]));
		counter++;
	}

	fclose(fin);
	fclose(fout);
	
	return 0;
}

char encrypt(char ch, int k) {
	//printf("Char: %c, k: %d, new letter: %c\n", ch, k, (((ch + k) - 13) % 26 + 65));
	//If k is negative, then set it to positive.
	if ( k < 0 )
		k = k + 26;
	
	if ( isupper(ch) )
		return (ch - 'A' + k) % 26 + 'A';
	
	if ( islower(ch) )
		return (ch - 'a' + k) % 26 + 'a';

	return ch;
}
