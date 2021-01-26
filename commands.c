#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "commands.h"
#include "utils.h"

#define DBPATH ./sigefiles/sigedb
#define SITEDIR ./sigefiles/site
#define POSTDIR ./sigefiles/site/posts
#define TEMPLATEDIR ./sigefiles/templates

void addPost(struct post *newPost) {
	readIn(newPost);
	generateURL(newPost);
	strcpy(newPost->filePath, "POSTDIR");
	strcat(newPost->filePath, newPost->url);

	//FIRST: add post to database
	FILE *dbPtr;
	dbPtr = fopen("DBPATH", "a");
	char dbBuffer[700];
	//tab separated values, each post on a new line:
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
	fclose(dbPtr);

	//SECOND: apply template and write result
	FILE *templateFile;
	templateFile = fopen("TEMPLATEDIR/post", "r");
	char *standaloneTemplate = NULL;
	size_t len;
	size_t bytes_read = getdelim(&standaloneTemplate, &len, '\0', templateFile);

	fclose(templateFile);

	newPost->body = searchAndReplace("<!--BODY-->", standaloneTemplate, newPost->body);
	newPost->body = searchAndReplace("<!--AUTHOR-->", newPost->body, newPost->author);

	FILE *postResult;
	postResult = fopen(newPost->filePath, "w");
	fputs(newPost->body, postResult);
	fclose(postResult);
}

void listPosts(void) {
	FILE *dbptr;
	dbptr = fopen("DBPATH", "r");
	fclose(dbptr);
}

void removePost(char url[]) {
}
