#include "student.h"


STUDENT input_student(char name[], char gender, int height, char email){
	STUDENT temp;
	strcpy(temp.name, name);
	temp.gender = gender;
	temp.height = height;
	strcpy(temp.email, email);
	return temp;
}

void read_file(LIST *plist, FILE *f) {
	STUDENT temp;
	while (fscanf(f, "%s\t%c\t%d\t%s\n", temp.name, &temp.gender, &temp.height, temp.email)!=EOF) {
		add(plist, temp);
	}
}