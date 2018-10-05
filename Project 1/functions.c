#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
/**********************************************************************
 * Removes duplicate characters.
 * Uses 2 for loops. First loop picks characters from a string sequentially
 * Second character starts at character after first character, and compares the rest of the characters sequentially.
 **********************************************************************/
char* removeDuplicates(char word[])
{
	char charToCheck;
	char wordSize = strlen(word);
	char temp;
	int charToDeleteCount = 0;

	for (int i = 0; i < wordSize - 1 - charToDeleteCount; i++)
	{
		charToCheck = word[i];
		for (int j = i+1; j < wordSize - charToDeleteCount; j++)
		{
			if (charToCheck == word[j])
			{
				charToDeleteCount+=1;
				for (int k = j; k < wordSize-1; k++)
					word[k] = word[k+1];
				j--;
			}
		}
	}
	
	int newSize = (wordSize - charToDeleteCount);
	char* retArr = (char *)malloc(newSize * sizeof(char));
	for (int i = 0; i < newSize; i++)
		retArr[i] = word[i];

	return retArr;
}

int targetFound(char charArray[], int num, char target)
{
	for (int i = 0; i < num; i++)
	{
		if (charArray[i] == target)
			return i;
	}
	return -1;
}

void initializeEncryptArray(char key[], char encrypt[])
{
	for (int i = 0; i < strlen(key); i++)
	{
		if (islower(key[i]))
			encrypt[i] = key[i] - 32;
		else
			encrypt[i] = key[i];
	}

	int currIndex = strlen(key);
	for (int i = 'Z'; i >= 'A'; i--)
		if (targetFound(encrypt, strlen(encrypt), i) == -1)
		{
			encrypt[currIndex] = i;
			currIndex++;
		}

}

void initializeDecryptArray(char encrypt[], char decrypt[])
{
	int chLoc;
	for (int i = 0; i < strlen(encrypt); i++)
	{
		chLoc = encrypt[i] - 'A';
		decrypt[chLoc] = i + 'A';
	}
}

void processInput(FILE * inf, FILE * outf, char substitute[])
{
	char inCh;
	char outCh;
	int chLoc;
	while ( fscanf(inf, "%c", &inCh) != EOF )
        {
		if (isupper(inCh))
		{
			chLoc = inCh - 'A';
			outCh = substitute[chLoc] + 32;
		} else if (islower(inCh)) {
			chLoc = inCh - 'a';
			outCh = substitute[chLoc];
		} else 
			outCh = inCh;
		
		fprintf(outf, "%c", outCh);
        }
}
