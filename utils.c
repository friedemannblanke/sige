#include <stdlib.h>
#include <ctype.h>

#include "structs.h"
#include "utils.h"

/*generate the rightmost component of a posts URL by converting the title to lower case and replacing spaces with dashes
**WARNING:** does not handle URL-unsafe characters
Example
	samplePost.title = "Hello World";
	generateURL(samplePost);
	samplePost.url == "hello-world"
 */
void generateURL(struct post *workingPost) {
	int parseIndex = 0;
	do {
		if (workingPost->title[parseIndex] == ' ') {
			workingPost->url[parseIndex] = '-';
		} else {
			workingPost->url[parseIndex] = tolower(workingPost->title[parseIndex]);
		}
		parseIndex++;
	} while (workingPost->title[parseIndex] != '\0')
}

/* return false if any two characters at the same index in two strings do not match
Example
	char test1a[] = "Hello";
	char test1b[] = "Hello";
	stringMatch(test1a, test1b) == 1
	char test2a[] = "Hello";
	char test2b[] = "World";
	stringMatch(test2a, test2b) == 0
 */
int stringMatch(char *compA, char *compB) {
	int parseIndex = 0;
	 do {
		if (compA[parseIndex] != compB[parseIndex]) {
			return 0;
		}
		parseIndex++;
	} while (compA[parseIndex] != '\0')
	return 1;
}

//**WARNING:**does not handle less or more than one occurence of target within baseText
//should multiple occurences need to be handled, it is recommended to rewrite this function, instead of using a loop with a stringMatch condition, for efficiency reasons
char *searchAndReplace(char target[], char *baseText, char *toInsert) {

	//FIRST: find start of target in baseText
	char *searchBuffer;
	searchBuffer = (char *) malloc(sizeof(target));
	//prepare searchBuffer: initial population
	for (int i = 0; i < sizeof(target); i++) {
		searchBuffer[i] = baseText[i];
	}

	int parseIndex = 0; //will be location at which target begins in baseText after loop
	//exit loop if match, or if searchBuffer will reach end of baseText
	for (int i = 0; ( !stringMatch(searchBuffer, target) || baseText[parseIndex + sizeof(target)] == '\0'); i++) {
		for (int j = 0; j < sizeof(target); j++) {
			searchBuffer[j] = baseText[parseIndex + j];
		}
		parseIndex++;
	}

	//SECOND: copy baseText until begin of target, toInsert and the remainder of baseText into the result
	char *result;
	result = (char *) malloc(resultLength);
	for (int i = 0; i < parseIndex; i++) { //before target
		result[i] = baseText[i];
	}
	int copyIndex = 0;
	while (toInsert != '\0') { //target
		result[parseIndex + copyIndex] = toInsert[copyIndex++];
	}
	for (int i = parseIndex; baseText[i] != '\0'; i++) { //after target
		result[i + copyIndex] = baseText[i + sizeof(target)];
	}
	return result;
}
