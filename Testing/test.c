#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(int argc, char* argv[])
{
	int a = 6, b = 8;
	printf("Before: a = %d, b = %d\n", a, b);
	swap(&a, &b);
	printf("After: a = %d, b = %d\n", a, b);

	/*
	char str[] = "system", *p;
	p = str;
	printf("\n%c%s%s%d%d\n", p, str, p+1, strlen(str), sizeof(str));
	char *format = "\n%d\n%d\n%d\n%d\n";
	int a[] = {3, 6, 8};
	int *p = a;
	printf(format, *(p+1), *p + 7, 3 * **&p + 1, 2 * *(p + 1) - 2);
//6, 10, 10, 10
//	int *p = a;
//	printf(format, 	*(p+1), *p + 7, 3 * **&p + 1, 2 * *(p + 1) – 2);
//	*/
}
