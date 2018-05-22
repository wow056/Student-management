#include "student.h"
#include <stdio.h>

STUDENT input_student(FILE* f) {
	STUDENT temp;
	fscanf(f, "%s\t%c\t%d\t%s\n", &temp.name, &temp.gender, &temp.height, &temp.name);
}