#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <string.h>

typedef struct student {
	char name[21];
	char gender;
	int height; //positive intege[cm]
	int score;
	char email[31]; //identifier
} STUDENT;



#endif // !STUDENT_H