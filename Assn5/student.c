#include "student.h"


STUDENT input_student(char name[], char gender, int height, char email){
	STUDENT temp;
	strcpy(temp.name, name);
	temp.gender = gender;
	temp.height = height;
	strcpy(temp.email, email);
	return temp;
}
