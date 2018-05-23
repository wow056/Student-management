#include "class.h"
#include "student.h"

int main(int argc,char *argv[]) {
	FILE *f;
	LIST list;

	if (argc == 1) {
		f = fopen("student.txt", "r");
	}
	else {
		f = fopen(argv[1], "r");
	}
	if (f == NULL) {
		printf("Could not open input file!");
		return -1;
	}

	read_file(&list, f);
	show(&list);
}