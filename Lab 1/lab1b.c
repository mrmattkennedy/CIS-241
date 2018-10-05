#include <stdio.h>
#include <ctype.h>
int main ()
{
	char ch;
	int wordSeq = 0;
	int symbolSeq = 0;

	int alnum = 0;
	int symbol = 0;
	FILE *writefile = fopen("output.txt", "w");
	int current = 1;
	/*
	puts("Enter 1 to use keyboard, or 2 to read from a file:\n");
	ch = getchar();
	if (ch == '2') {
	*/
		FILE *file = fopen("testInput.dat", "rb");
		if (file) {
			while ((ch = getc(file)) != EOF) 
			{	
				putchar(ch);
				if ((isalnum(ch) || ch == '_') && alnum == 0) {
					wordSeq +=1;
					symbol = 0;
					alnum = 1;
				} else if (ispunct(ch) && symbol == 0) {
					symbolSeq +=1;
					symbol = 1;
					alnum = 0;
				} else if (isspace(ch)) {
					symbol = 0;
					alnum = 0;
				}
				fputc(ch, writefile);
				current+=1;
			}
			fclose(file);
		}
	/*
	} else {
	
		puts("Enter characters");
		fseek(stdin,0,SEEK_END);
		while (ch = getchar(), ch != EOF, ch != '\n') 
		{
			if ((isalnum(ch) || ch == '_') && alnum == 0) {
				wordSeq +=1;
				symbol = 0;
				alnum = 1;
			} else if (ispunct(ch) && symbol == 0) {
				symbolSeq +=1;
				symbol = 1;
				alnum = 0;
			} else if (isspace(ch)) {
				symbol = 0;
				alnum = 0;
			}
			fputc(ch, writefile);
			current+=1;
		}
	}
	*/
	fclose(writefile);
	printf("%d, %d\n", wordSeq, symbolSeq);
	
}
