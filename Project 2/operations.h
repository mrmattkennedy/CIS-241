#ifndef INCLUDE_GUARD
#define INCLUDE_GUARD

#include <stdio.h>
#include <unistd.h>

#define maxStrLen  20
#define initialSize 10

typedef struct product product;
struct product
{
	char name[maxStrLen];
	float quantity_value;
	char quantity_unit[maxStrLen];
	float price_value;
	char price_unit[maxStrLen];
	struct product *next;
};

int insert(product **l, product node);
void type_text(char *s, unsigned ms_delay);
void printlist(product *node);
void rmItem(product *l, product *node);
float purchase(product *l, char productName[], float q);
void check_price(product *l, char p[]);
void findItem(product *l, char p[]);
void loadAll(product **l);
void saveAll(product *l);
#endif
