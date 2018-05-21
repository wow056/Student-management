#include "class.h"
#include <stdlib.h>
#include <stdio.h>

void init(LIST *plist){
	plist->head = NULL;
	plist->count = 0;
}

void show(const LIST *plist){
	NODE *ptr;
	printf("NAME\t\tGender\tHeight\tEmail\n");
	for (ptr = plist->head; ptr != NULL; ptr = ptr->next)
		printf("%s\t\t%c\t%d\t%s\n", ptr->data.name, ptr->data.gender, ptr->data.height, ptr->data.email);
	
}

void add(LIST *plist, STUDENT data){
	NODE *temp;
	temp = (NODE*)malloc(sizeof(NODE));
	temp->prev = NULL;
	temp->data = data;
	temp->next = plist->head;
	plist->head->prev = temp;
	plist->head = temp;
	plist->count++;
}

void remove(NODE

void del(LIST *plist){
	NODE *temp;
	temp = plist->head;
	plist->head = temp->next;
	plist->head->prev = NULL;
	plist->count--;
	free(temp);
}

void swap(NODE *a, NODE *b) {
	NODE temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void insert(LIST *plist, NODE *destination, NODE *pick) {
	if (pick == plist->head) {

	}
	
	pick->prev->next = pick->next;
	pick->next->prev = pick->prev;
	destination->prev = pick;
	pick->next = destination;
}

void insertion_sort(LIST *plist){
	NODE *ptr, *pick, *mark;
	for (pick = plist->head; pick != NULL; pick = ptr->next) {
		for (ptr = plist->head; ptr != pick; ptr = ptr->next) {
			if (pick->data.height > ptr->data.height) {
				insert(ptr, pick);
			}
		}
	}
}

STUDENT pop(LIST *plist) {
	STUDENT temp;
	temp = plist->head->data;
	del(plist);
	return temp;
}

void sort(LIST *plist) {
	LIST m_list, f_list;
	STUDENT temp;
	int i, n;

	init(&m_list);
	init(&f_list);

	while (plist->head != NULL) {
		temp = pop(plist);
		if (temp.gender == 'm') {
			add(&m_list, temp);
		}
		else if (temp.gender == 'f') {
			add(&f_list, temp);
		}
	}

	insertion_sort(&m_list);
	insertion_sort(&f_list);

	if (m_list.count > f_list.count) {
		while (m_list.count == f_list.count) {
			add(plist, pop(&m_list));
		}
	}
	else if (m_list.count < f_list.count) {
		while (m_list.count == f_list.count) {
			add(plist, pop(&f_list));
		}
	}

	if (m_list.head->data.height >= f_list.head->data.height) {
		n = m_list.count;
		for (i = 0; i < n; i++) {
			add(plist, pop(&m_list));
			add(plist, pop(&f_list));
		}
	}
	else {
		n = m_list.count;
		for (i = 0; i < n; i++) {
			add(plist, pop(&f_list));
			add(plist, pop(&m_list));
		}
	}
}