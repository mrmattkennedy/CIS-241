#ifndef _FUNCTIONS_HEADER_
#define _FUNCTIONS_HEADER_

char* removeDuplicates(char word[]);
int targetFound(char charArray[], int num, char target);
void initializeEncryptArray(char key[], char encrypt[]);
void initializeDecryptArray(char encrypt[], char decrypt[]);
void processInput(FILE * inf, FILE * outf, char substitute[]);
#endif
