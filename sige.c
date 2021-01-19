#include <stdio.h>

/*
struct DATE {
	int year;
	int month;
	int day;
};

struct Post {
	DATE date;
	char author[50];
	char title[250];
	char link[150];
	FILE *postBody;
};
*/

int main(int argc, char *argv[]) {
	//parse CLI args
	for (int i = 0; i < argc; i++) {
		//detect flags
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
				case 'a':
					printf("author: %s\n", argv[i + 1]);
					break;
				case 't':
					printf("title: %s\n", argv[i + 1]);
					break;
				case 'd':
					break;
				default:
					printf("\x1b[33mWarning:\x1b[0m -%c is not a recognized option\n", argv[i][1]);
			}
			i++;
		}
	}
	return 0;
}
