#include <ctype.h>

#include "structs.h"
#include "utils.h"

void generateURL(char *titleInput, char *urlOutput) {
	int parseIndex = 0;
	do {
		if (titleInput[i] == ' ') {
			urlOutput[i] = '-';
		} else {
			urlOutput[i] = tolower(titleInput[i]);
		}
		i++;
	} while (titleInput[i] != '\0')
}
