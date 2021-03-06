#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

int main(int argc, char *argv[]) {
	//parse CLI args
	//first argument is command, following are options

	struct post userProvided;
	//options & metadata
	for (int i = 1; i < argc; i++) {
		//detect flags
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
				case 'd':
					//date handling, ISO 8601 formatted
					sscanf(argv[i + 1], "%d-%d-%d", &userProvided.date.year, &userProvided.date.month, &userProvided.date.day);
					break;
				case 'a':
					//author handling
					strcpy(userProvided.author, argv[i + 1]);
					break;
				case 't':
					//title handling
					strcpy(userProvided.title, argv[i + 1]);
					break;
				case 'u':
					//url handling
					strcpy(userProvided.url, argv[i + 1]);
					break;
				case 'f':
					//file path handling
					strcpy(userProvided.filePath, argv[i + 1]);
					break;
				case 'o':
					//output format
					break;
				//uncaught cases are unrecognized flags
				default:
					printf("\x1b[33mWarning:\x1b[0m -%c is not a recognized option\n", argv[i][1]);
					return 1;
					break;
			}
			i++;
		}
	}

	printf("%s", userProvided.author);
	switch(argv[0][0]) {
		case 'a':
			addPost(&userProvided);
			break;
		default:
			printf("\x1b[31mError:\x1b[0m %c is not a recognized command\n", argv[0][0]);
	}
	//free(userProvided.body);
	return 0;
}
