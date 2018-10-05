#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 4

char* strnsub (char *p, int n);

int main()
{
	/* This is the line to parse. */
	char line[] = "His textbook was bought from that bookstore";  
	/* Pointers that are size LEN, hold LEN sequential chars from line. */
	char *p1, *p2;

	/* Counter for keeping track of where p1 is. */
	int p1Count = 0;

	/* Counter for keeping track of where p2 is. */
	int p2Count = 0;

	int size = sizeof(line)/sizeof(line[0]);
	
	//Initializes p1 to the first LEN chars of line.
	//This is so we have something to compare p2 to.
	p1 = line;

	//While p1 < the length of line.
	while (*p1 != line[size]) 
	{
		//Set p2 equal to where p1 was in line + 1, so we don't get a false positive.
		p2 = p1 + sizeof(char);

		//Offset p2count to p1count + 1, or we will get a false positive.
		p2Count = p1Count + 1;

		while (*p2 != line[size])	
		{
			//Simple print statement for manual debugging.
			printf("p1: %s ...  p2: %s\n", p1, p2);
			//If p1 and p2 are equal, then strncmp returns 0.
			if (strncmp(p1, p2, LEN) == 0)
			{
				printf("\nThe original string is:\n%s\n", line);
				printf("The first substring:  %s\n", strnsub(p1, LEN));
				printf("The second substring: %s\n", strnsub(p2, LEN));
				return 0;
			}
			//Increment p2Count, so it will get the next char in line.
			p2 = p2 + sizeof(char);
        }
	//Set p1 equal to next char offset.
	p1 = p1 + sizeof(char);
    }

	//No matches found.
	printf("\nNo repeated patterns of length %d in the following string:\n%s\n",
            LEN, line);
	return 0;
}


char* strnsub (char* p, int n)
{
	char test[n+1];
	
	for (int i = 0; i < n; i++)
		test[i] = p[i];
	
	test[n] = '\0';
	p = test;
	return p;
/*
	//Temp char array for holding the new chars.	
	char* temp = malloc(n+1 * sizeof(char));
	
	//Copy over the next n elements from p, which is line.
	strncpy(temp, p, n);

	//Add the null char at end. This is necessary for char arrays.
	temp[n] = '\0';

	//Return emp.
	return temp;
*/
}
