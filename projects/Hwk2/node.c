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

void delete_node(struct NODE *llist, int num) {
	struct NODE *temp;
	temp = (struct NODE *)malloc(sizeof(struct NODE));

	if (llist->number == num) {
		temp = llist->next;
		free(llist);
		llist = temp;
	} else {
		while (llist->next->number != num)
			llist = llist->next;

		temp = llist->next->next;
		free(llist->next);
		llist->next = temp;
	}
}

int search_value(struct NODE *llist, int num) {
	int retval = -1;
	int i = 1;

	while (llist->next != NULL) {
		if (llist->next->number == num)
			return i;
		else
			i++;

		llist = llist->next;
	}

	return retval;
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