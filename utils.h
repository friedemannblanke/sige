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
	char *body;
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

//Utils
void generateURL(struct post *workingPost);
char *searchAndReplace(char *target, char *baseText, char *toInsert, int resultLength);
int readIn(struct post *newPost);

//Commands
void addPost(struct post *newPost);
void listPosts(void);
void removePost(char url[]);
