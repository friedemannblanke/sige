struct Date {
	int year;
	int month;
	int day;
}

struct Post {
	date date;
	char author[50];
	char title[250];
	char link[150];
	FILE *postBody;
}
