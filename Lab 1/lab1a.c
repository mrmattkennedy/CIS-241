#include <stdio.h>
#include <ctype.h>
int main ()
{
	char ch;
	puts("Enter text (Ctrl-D to quit).");
	while (ch = getchar(), ch != EOF){
		printf(ch[0]);
	}
	return 0;
}
