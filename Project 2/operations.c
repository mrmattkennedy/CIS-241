#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include "operations.h"
typedef struct product product;
static float profit = 0.0;
void type_text(char *s, unsigned ms_delay)
{
	unsigned usecs = ms_delay * 1000; /* 1000 microseconds per ms */

	for (; *s; s++) {
		putchar(*s);
		fflush(stdout); /* alternatively, do once: setbuf(stdout, NULL); */
		usleep(usecs);
	}	
}


int insert(product **l, product node)
{
	product *temp = (product *)malloc(sizeof(product));
	
	strcpy(temp->name, node.name);
	temp->quantity_value = node.quantity_value;
	strcpy(temp->quantity_unit, node.quantity_unit);
	temp->price_value = node.price_value;
	strcpy(temp->price_unit, node.price_unit);

	temp->next = NULL;

	product *head = *l;

	if (*l == NULL)
	{
		*l = temp;
		return;
	}

	while (head != NULL)
	{
		if (strcmp(head->name, temp->name) == 0)
		{
			head->quantity_value+=temp->quantity_value;
			return 1;
		}
		head = head->next;
	}

	head = *l;
	while (head->next != NULL)
		head = head->next;

	head->next = temp;
	return 1;
}

void rmItem(product *l, product *node)
{
	product *head = l;
	while (head != NULL)
	{
		if (strcmp(head->next->name, node->name) == 0)
		{
			head->next = head->next->next;
			return;
		}
		head = head->next;
	}
	printf("Product does not exist.\n");
	return;
}

float purchase(product *l, char productName[], float q)
{
	product *head = l;
	
	while (head != NULL)
	{
		if (strcmp(head->name, productName) == 0)
		{
			if (head->quantity_value < q)
			{
				printf("We don't have %f of %s in stock.\n\n", q, head->name);
				return 0.0;
			} else {
				printf("You purchased %f of %s.\n\n", q, head->name);
				profit += (head->price_value * q);
				head->quantity_value-=q;
				return 0.0;
			}
		}
		head = head->next;
	}
	printf("Product does not exist.");
	return 0.0;
}

void check_price(product *l, char p[])
{
	product *head = l;

	while (head != NULL)
	{
		if (strcmp(head->name, p) == 0)
		{
			printf("Price of item %s is %f\n\n", head->name, head->price_value);
			return;
		}
		head = head->next;
	}
	printf("Product does not exist.\n");
	return;
}

void findItem(product *l, char p[])
{
	product *head = l;

	while (head != NULL)
	{
		if (strcmp(head->name, p) == 0)
		{
			printf("%s   %0.2f %s    %s%0.2f\n", head->name, head->quantity_value, head->quantity_unit, head->price_unit, head->price_value);
			return;
		}
		head = head->next;
	}
	printf("Product does not exist.\n");
	return;
}

void inventory()
{
	printf("Store has made $%0.2f so far.\n", profit);
}

void printList(product *node)
{
	while (node != NULL)
	{
		printf("%s   %0.2f %s    %s%0.2f\n", node->name, node->quantity_value, node->quantity_unit, node->price_unit, node->price_value);
		node = node->next;
	}
}

void loadAll(product **l)
{
	FILE* fin = fopen("data.txt", "r");
	if (fin == NULL)
		return;
	char line[256];
	char *token,*line_ptr;
	product *temp = (product *)malloc(sizeof(product));
	int currArg = 0;

	while (fgets(line, sizeof(line), fin) != NULL) {
		line[strlen(line) - 1] = '\0';
		line_ptr = line;
		free(temp);
		temp = (product *)malloc(sizeof(product));
		currArg = 0;
		while ((token = strsep(&line_ptr, ",")) != NULL)
		{
			if (currArg == 0)
				strcpy(temp->name, token);
			else if (currArg == 1)
				temp->quantity_value = atof(token);
			else if (currArg == 2)
				strcpy(temp->quantity_unit, token);
			else if (currArg == 3)
				temp->price_value = atof(token);
			else if (currArg == 4)
				strcpy(temp->price_unit, token);
			currArg++;
		}
		insert(l, *temp);
	}

	fclose(fin);
}

void saveAll(product *l)
{
	fclose(fopen("data.txt", "w"));
	FILE *fout = fopen("data.txt", "w");
	if (fout == NULL)
	{
		printf("File could not be opened.\n");
		return;
	}


	while (l != NULL)
	{
		fprintf(fout, "%s,", l->name);
		fprintf(fout, "%f,", l->quantity_value);
		fprintf(fout, "%s,", l->quantity_unit);
		fprintf(fout, "%f,", l->price_value);
		fprintf(fout, "%s", l->price_unit);
		fprintf(fout, "\n");
		l = l->next;
	}	
	fclose(fout);
}
int get_item_info(product *l, int service_choice)
{
	char *pos;
	char name[20];
	float quantity_val;
	char quantity_unit[20];
	float price_value;
	char price_unit[20];

	if (service_choice == 1 || service_choice == 2 || service_choice == 3 || service_choice == 5 || service_choice == 6)
	{
		type_text("Please enter a product name:", 5);
		getchar(); 
		fgets(name, sizeof(name), stdin);
		if ((pos=strchr(name, '\n')) != NULL)
		    *pos = '\0';
	}
	
	if (service_choice == 1)
	{	
		product *head = l;
		while (head != NULL)
		{
			if (strcmp(head->name, name) == 0)
			{
				type_text("Product already exists, please enter quantity value: ", 5);
				scanf("%f",&quantity_val);
				product temp = {.quantity_value = quantity_val};
				strcpy(temp.name, name);
				insert(&l, temp);
				return;
			}
			head = head->next;
		}
	}
	if (service_choice == 1 || service_choice == 2)
	{
		type_text("\nPlease enter a quantity value:", 5);
		scanf("%f",&quantity_val);
	}

	if (service_choice == 1)
	{

		type_text("\nPlease enter a quantity unit:", 5);
		getchar();
		fgets(quantity_unit, sizeof(quantity_unit), stdin);
		if ((pos=strchr(quantity_unit, '\n')) != NULL)
			    *pos = '\0';
	}

	if (service_choice == 1)
	{
		type_text("\nPlease enter a price value:", 5);
		scanf("%f",&price_value);
	}

	if (service_choice == 1)
	{
		type_text("\nPlease enter a price unit:", 5);
		getchar();
		fgets(price_unit, sizeof(price_unit), stdin);
		if ((pos=strchr(price_unit, '\n')) != NULL)
			    *pos = '\0';
	}

	if (service_choice == 1)
	{
		product temp = {.quantity_value = quantity_val,
			.price_value = price_value,
		};

		strcpy(temp.name, name);
		strcpy(temp.quantity_unit, quantity_unit);
		strcpy(temp.price_unit, price_unit);
		insert(&l, temp);
	}

	if (service_choice == 2)
		purchase(l, name, quantity_val);

	if (service_choice == 3)
		check_price(l, name);

	if (service_choice == 4)
		printList(l);

	if (service_choice == 5)
	{
		product temp;
		strcpy(temp.name, name);
		rmItem(l, &temp);
	}
	
	if (service_choice == 6)
		findItem(l, name);

	if (service_choice == 7)
	{
		inventory();
		printList(l);
	}
	
	if (service_choice == 8)
		saveAll(l);
}


