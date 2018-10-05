#include <stdio.h>
#include <string.h>
#include "operations.h"

#define MAX_LEN 20
typedef struct product product;
/*
void addStruct(struct product* products)
{
	struct product next;
	strcpy(next.name, "Not cereal");
	products->next = &next;
}
*/
int main()
{

	static product* products = NULL;
	loadAll(&products);
/*
	product curr = {.name = "Cereal2", .next = NULL, .quantity_value = 2.0, .quantity_unit = "Boxes", .price_value = 3.0, .price_unit = "$"};
	insert(&products, curr);

	product curr2 = {.name = "Cereal4", .next = NULL, .quantity_value = 2.0, .quantity_unit = "Boxes", .price_value = 5.0, .price_unit = "$"};
	insert(&products, curr2);

	product curr3 = {.name = "Cereal4", .next = NULL, .quantity_value = 2.0, .quantity_unit = "Boxes", .price_value = 5.0, .price_unit = "$"};
	insert(&products, curr3);

	product curr4 = {.name = "Cereal4", .next = NULL, .quantity_value = 2.0, .quantity_unit = "Boxes", .price_value = 5.0, .price_unit = "$"};
	insert(&products, curr4);
*/
	type_text("\n\nWelcome to Matt's store! Please select an option:\n", 40);
	type_text("============================================================================\n", 10);
	type_text("1. Add product to store\t\t\t", 10);
	type_text("2. Purchase product from store\n", 10);
	type_text("3. Check price of product\t\t", 10);
	type_text("4. Show products in store\n", 10);
	type_text("5. Clean up a product from store\t", 10);
	type_text("6. Find product\n", 10);
	type_text("7. Inventory\t\t\t\t", 10);
	type_text("8. Done for today\n", 10);
	char input;
	int temp;
	while (temp != 8)
	{
		printf("\nEnter an option: ");
		int ch;
		input = getchar();
		temp = input - 48;
		get_item_info(products, temp);
		while ((ch=getchar()) != EOF && ch != '\n')
			;
	}

	//purchase(products, "Cereal4", 5.0);
	//check_price(products, "Cereal4");
//	rmItem(products, &curr4);
	//printList(products);	
	return 1;
}
