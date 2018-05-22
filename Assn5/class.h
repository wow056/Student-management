#ifndef CLASS_H
#define CLASS_H

#include "student.h"

typedef struct node {
	struct node *prev;
	struct student data;
	struct node *next;
} NODE;

typedef struct list {
	NODE *head;
	int count;
} LIST;


void init(LIST *plist);
void show(const LIST *plist);
void add(LIST *plist, STUDENT data);
void del(LIST *plist);
void swap(NODE *a, NODE *b);
STUDENT pop(LIST *plist);
void remove_node(NODE *ptr, LIST *plist);
void insert(LIST *plist, NODE *destination, NODE *pick);
void insertion_sort(LIST *plist);
#endif // !CLASS_H