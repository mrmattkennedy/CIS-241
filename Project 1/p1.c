#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"

#define MAXNUM 26

int main(int argc, char* argv[])
{
	int keyLength;
	char* cipher;
	char* encrypt = (char *)malloc(MAXNUM * sizeof(char));
	char* decrypt = (char *)malloc(MAXNUM * sizeof(char));
	char choice;
	/* These are the in files and out files. */
        FILE *fin, *fout;

	
	if (argc != 5)
        {
                printf ("Usage: cipher option key infile, outfile\n");
                printf ("Option 1 for encryption and 2 for decryption\n");
                exit(1);
        }
	choice = *argv[1];
	keyLength = strlen(argv[2]);
	cipher = argv[2];
	int currIndex = 0;
	while (cipher[currIndex] != '\0')
	{
		if (!isalpha(cipher[currIndex]))
		{
			printf("Key must be all letters.\n");
			exit(1);
		}
		currIndex++;
	}	
	cipher = removeDuplicates(cipher);
	
	initializeEncryptArray(cipher, encrypt);

	//Open the files for reading and writing.
        fin = fopen(argv[3], "r");
        fout = fopen(argv[4], "w");
	
	//If there was an error opening the file, then exit.
        if (fin ==  NULL || fout == NULL)
        {
        	printf("File could not be opened\n");
                exit(1);
	}                                                                        
	if (choice == 'e')
		processInput(fin, fout, encrypt);
	else if (choice == 'd')	
	{
		initializeDecryptArray(encrypt, decrypt);
		processInput(fin, fout, decrypt);
	free(decrypt);
	}
	else {
		printf("Enter e for encryption or d for decryption.\n");
		exit(1);
	}
free(encrypt);
}	

