#ifndef CLASS_H
#define CLASS_H

typedef struct student {
	char name[20];
	char gender;
	int height; //positive intege[cm]
	int score;
	char email[30]; //identifier
} STUDENT;

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
void insert(NODE *destination, NODE *pick);
void insertion_sort(LIST *plist);
#endif