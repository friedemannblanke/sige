#include "commands.h"
#include "structs.h"

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

