#include <string.h>
#include <stdio.h>

int main(int* argc, char* argv[])
{
/*
	char *buff = "this is a test string";
	char* subbuff;
	char* subbuff2;
	memcpy( subbuff, &buff[10], 4 );
	memcpy(subbuff2, *buff + *subbuff + 4, 4);
	printf("%s\n", subbuff2);

	char* str = "this is a test";
	char* result = strstr(str, "is");
	printf("%d\n", result - str);

	char* newIndex = str + 3;
	printf("%s\n", newIndex);
	if (newIndex = "s is a test")
		printf("true\n");
*/
	char* src = "abcefgh";
	char* ptr1;
	strncpy(ptr1, src+2, 4);
	printf("%s\n", ptr1);

	char* ptr2;
	//printf("Second: %s\n", ptr2);
}

