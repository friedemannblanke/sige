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

void generateURL(struct post *workingPost);
char *searchAndReplace(char target[], char *baseText);
