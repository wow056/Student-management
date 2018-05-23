#ifndef STUDENT_H
#define STUDENT_H

#include "class.h"
#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[20];
	char gender;
	int height; //positive intege[cm]
	int score;
	char email[30]; //identifier
} STUDENT;

void read_file(LIST *plist, FILE *f);

#endif // !STUDENT_H