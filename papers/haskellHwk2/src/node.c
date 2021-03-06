#include <stdio.h>
#include <stdlib.h>
#include "headers/node.h"

void display_list(struct NODE *llist) {
	if (llist->next != NULL)
		llist = llist->next;
	while (llist->next != NULL) {
		printf("%d ", llist->number);
		llist = llist->next;
	}
	printf("%d \r\n", llist->number);
}
void display_list_array(struct NODE *llist, int length) {
	if (llist->next != NULL)	
		llist = llist->next;
	int i;
	while (llist->next != NULL) {

		for (i = 0; i < length; i++) {
			printf("%i ", llist->array[i]);
		}
		printf("\r\n");
		llist = llist->next;
	}
	if (llist->array != NULL) {
		for (i = 0; i < length; i++) {
			printf("%i ", llist->array[i]);
		}
		printf("\r\n");
	}
}
void append_node(struct NODE *llist, int num) {
	while (llist->next != NULL)
		llist = llist->next;

	llist->next = (struct NODE *)malloc(sizeof(struct NODE));
	llist->next->number = num;
	llist->next->next = NULL;
}
void append_node_array(struct NODE *llist, int* array) {
	while (llist->next != NULL)
		llist = llist->next;

	llist->next = (struct NODE *)malloc(sizeof(struct NODE));
	llist->next->array = array;
	llist->next->next = NULL;
}
int sum(struct NODE *llist) {
	int sum;
	if (llist->next != NULL)
		llist = llist->next;
	while (llist->next != NULL) {
		sum += llist->number;
		llist = llist->next;
	}
	sum += llist->number;
	return sum;
}
