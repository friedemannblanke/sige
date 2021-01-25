#include <ctype.h>

#include "structs.h"
#include "utils.h"

void generateURL(struct post *workingPost) {
	int parseIndex = 0;
	do {
		if (workingPost->title[i] == ' ') {
			workingPost->url[i] = '-';
		} else {
			workingPost->url[i] = tolower(workingPost->title[i]);
		}
		i++;
	} while (workingPost->title[i] != '\0')
}
