#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DBPATH "./sigedb"
//#define SITEDIR "./site"

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


struct runOptions {
	char outputFormat;
	/* OPTIONS
	 * q quiet
	 * s standalone
	 * a archive
	 * f feed
	 * r rss
	 */
};

void addPost(struct post *newPost) {
	FILE *dbPtr;
	dbPtr = fopen(DBPATH, "a");
	char dbBuffer[650];
	//tab separated values, each post on its own line:
	//url	title	year-month-day	author	filePath
	sprintf(dbBuffer, "%s\t%s\t%d-%d-%d\t%s\t%s\n",
		newPost->url,
		newPost->title,
		newPost->date.year,
		newPost->date.month,
		newPost->date.day,
		newPost->author,
		newPost->filePath
	);
	printf("%s", dbBuffer);
	fclose(dbPtr);
}


void listPosts() {
	FILE *dbptr;
	dbptr = fopen(DBPATH, "r");
	fclose(dbptr);
}

void removePost(char url[]) {

}


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

	//command parsing requires string comparison, annoying, handle later
	addPost(&userProvided);
	return 0;
}
