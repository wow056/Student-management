#ifndef CLASS_H
#define CLASS_H

typedef struct student {
	char name[20];
	char gender;
	int height; //positive intege[cm]
	char email[30]; //identifier
} STUDENT;

typedef struct node {
	struct student data;
	struct node *next;
} NODE;

typedef struct list {
	NODE *head;
	int count;
} LIST;

#endif