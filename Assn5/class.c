#include "class.h"
#include <stdlib.h>
#include <stdio.h>

void init(LIST *plist)
{
	plist->head = NULL;
	plist->count = 0;
}

void show(const LIST *plist)
{
	NODE *ptr;
	printf("NAME\t\tGender\tHeight\tEmail\n");
	for (ptr = plist->head; ptr != NULL; ptr = ptr->next)
		printf("%s\t%c\t%d\t%s\n", ptr->data.email, ptr->data.gender, ptr->data.height, ptr->data.name);
	
}

void add(LIST *plist, STUDENT data)
{
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->data = data;
	temp->next = plist->head;
	plist->head = temp;
	plist->count++;
}

void remove(LIST *plist)
{
	NODE *temp;
	temp = plist->head;
	plist->head = plist->head->next;
	plist->count--;
	free(temp);
}

