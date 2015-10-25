#include <stdio.h>
#include <string.h>

struct Book {
	char *title;
	char *author;
	int book_id;
};

int main(){
	struct Book Book1;

	Book1.title = "Hello";
	Book1.author = "Hello";
	Book1.book_id = 217821;

	printf("%s\n", Book1.title);
}