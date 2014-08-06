/*ref:www.tutorialspoint.com/cprogramming/c_typedef.html*/
/*In this code we will explore how to use "typedef" and what it is*/
/*The C programming language provides a keyword called "typedef, which you can use to give a type a new name. following is an example  to define a term "BYTE" for one-byte numbers:
typedef unsigned char BYTE;
After this definition,the identifier BYTE can be used as an abbreviation for the type unsigned char for example
BYTE b1,b2;
By convention, uppercase letters are used for these definitions to remind the user that the type name is really a symbolic abbreviation, but you can use lowercase as follows:
typedef unsigned char byte;
and the declaration becomes:
byte b1,b2;
*/
typedef struct Books
{
	char *title;
	char *author;
	char *subject;
	int book_id;
}Books;
int main(int argc, char *argv[])
{
	//variable of type Books 
	Books book;
	book.title = "C programing";
	book.author = "Zed Shaw";
	book.subject = "Computer Science";
	book.book_id = 1;
	printf("Book Title: %s.\n",book.title);
	printf("Author Name: %s.\n",book.author);
	printf("Subject : %s.\n", book.subject);
	printf("Book Id: %d.\n", book.book_id);
	return 0;
}
	
