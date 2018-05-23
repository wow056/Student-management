#include "class.h"
#include "student.h"



int main(int argc,char *argv[]) {
	FILE *f;
	LIST list;

	init(&list);

	if (argc == 1) {
		f = fopen("students.txt", "r");
	}
	else {
		f = fopen(argv[1], "r");
	}
	if (f == NULL) {
		printf("Could not open input file!\n");
		system("pause");
		return -1;
	}

	file_to_list(f, &list);
	show(&list);
	system("pause");
	insertion_sort(&list);
	show(&list);

	system("pause");
	return 0;
}