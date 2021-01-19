#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DBPATH "./sigedb"

struct date {
	int year;
	int month;
	int day;
};

struct post {
	struct date date;
	char author[50];
	char title[250];
	char url[150];
	char filePath[200];
};

void addPost(struct post *newPost) {
	FILE *dbptr;
	dbptr = fopen(DBPATH, "a");
	//writing to db requires turning date into readable format
	fputs(newPost->author, dbptr);
	fclose(dbptr);
}


void listPosts() {

}

void removePost(char url[]) {

}

int main(int argc, char *argv[]) {
	//parse CLI args
	//first argument is command, following are options

	struct post userProvided;
	//options
	for (int i = 1; i < argc; i++) {
		//detect flags
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
				case 'd':
					//date handling
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
				//uncaught cases are unrecognized flags
				default:
					printf("\x1b[33mWarning:\x1b[0m -%c is not a recognized option\n", argv[i][1]);
			}
			i++;
		}
	}

	//command parsing requires string comparison, annoying, handle later
	addPost(&userProvided);
	return 0;
}
