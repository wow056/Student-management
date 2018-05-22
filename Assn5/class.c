#include <stdlib.h>
#include <stdio.h>
#include "class.h"

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

void remove_node(NODE *ptr, LIST *plist) {
	if (ptr == plist->head) {
		del(plist);
	}
	else {
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		free(ptr);
		plist->count--;
	}
}

void del(LIST *plist){
	NODE *temp;
	temp = plist->head;
	plist->head = temp->next;
	plist->head->prev = NULL;
	plist->count--;
	free(temp);
}

void swap(NODE *a, NODE *b) {
	STUDENT temp;
	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void insert(LIST *plist, NODE *destination, NODE *pick) {
	if (pick == destination) {//1. when pick is destination
		return;
	}
	else if (pick->next == destination) {//2. When destination is next to pick
		return;
	}
	else if (pick == plist->head) {//3. When pick is head of list
		plist->head = pick->next;
		plist->head->prev = NULL;//picking

		pick->next = destination;
		pick->prev = destination->prev;//changing pointer in pick

		destination->prev->next = pick;
		destination->prev = pick;//inserting
	}
	else if (pick->next == NULL) {//4. When pick is tail of list
		pick->prev->next = pick->next;//picking

		pick->next = destination;
		pick->prev = destination->prev;//changing pointer in pick
		if (destination == plist->head) {
			plist->head = pick;
			destination->prev = pick;//inserting
		}
		else {
			destination->prev->next = pick;
			destination->prev = pick;//inserting
		}
	}
	else {//5. else
		pick->prev->next = pick->next;
		pick->next->prev = pick->prev;//picking

		pick->next = destination;
		pick->prev = destination->prev;//changing pointer in pick
		if (destination == plist->head) {
			plist->head = pick;
			destination->prev = pick;//inserting
		}
		else {
			destination->prev->next = pick;
			destination->prev = pick;//inserting
		}
	}
}

void insertion_sort(LIST *plist){
	NODE *ptr, *pick;
	for (pick = plist->head; pick != NULL; pick = ptr->next) {
		for (ptr = plist->head; ptr != pick; ptr = ptr->next) {
			if (pick->data.height > ptr->data.height) {
				insert(plist, ptr, pick);
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