#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_LENGTH 10

int main() {
	char *body;
	body = (char *) malloc(BUFFER_LENGTH);
	int bodyLength = BUFFER_LENGTH;

	char readBuffer[BUFFER_LENGTH];
	int bufferPos = 0;
	//read stdin into readBuffer until EOF is read
	while (( readBuffer[bufferPos] = getchar() ) != EOF) {
		bufferPos++;
		//if the last element of readBuffer was just written into: extend body, append readBuffer to body, reset bufferPos to beginning of readBuffer
		if (bufferPos == BUFFER_LENGTH) {
			body = (char *) realloc(body, bodyLength += BUFFER_LENGTH);
			strcat(body, readBuffer);
			bufferPos = 0;
		}
	}

	//readBuffer has to be added to body one last time, since copying over step doesn't get executed after EOF has been read
	readBuffer[bufferPos] = '\0'; //append NULL to readBuffer to ensure proper handling of string end
	body = (char *) realloc(body, bodyLength += BUFFER_LENGTH);
	strcat(body, readBuffer);

	printf("body:\n\"%s\"\n", body);
	free(body);
	return 0;
}
