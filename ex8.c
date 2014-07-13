/*In the last exercise you did math, but with a '0'(num) character. This may be off coming from other languages, since they try to treat "strings" and "byte arrays" as different beasts. C however treats strings as just arrays of bytes, and it's only the different printing functions that know there is a difference.*/
#include<stdio.h>
int main(int argc, char *argv[])
{
/*In this code we create a few arrays with different data types in them. Because arrays of data are so central to how C works, there is a huge number of ways to create the,. For now, just use the syntax "type name[] = {initializer};" and we will explore more. What this syntaxx means is, "I waant an array of type that is initilized to {...}." When C sees this it does the following:
	a) Look at the type, in this first case it is "int"
	b) Look at the "[]" and see that there is no length given
	c) Look at the initializer, "{10, 12, 13, 14, 20}" and figure out that you want those 5 ints in your array.
	d) Create a piece of memory in the computer that can hold 5 integers one after another.
	e)Take the name you want, "areas" and assign it this location*/
/*In this case of "areas" it is creating an array of 5 ints that contain those numbers. when it gets to "char name[] = "Zed"; it is doing the same thing, except it's creating an array of 3 chars and assigning that to "name" . The final array we make is "full_name", but we use the annoying sytax of speling it out , one character at a time. To C "name" and "full_name" are identical methods of creating char array*/
	int areas[] = {10, 12, 13, 14, 20};
	char name[] = "Zed";
	char full_name[] = 
	{'Z','e','d',' ','A','.',' ','S','h','a','w','\0'};

	/*warning: On some systems you may have to change "ld" in this code to "%u" since it will use unsigned ints*/

/*The rest of file, we are using a keyword called "sizeof" to ask C how big things are in bytes. C is all about the size and location of pieces of memory and what you do with them. To help you keep that straight, it gives you "sizeof" so you can ask how big something is before you work with it.*/

/*Note that my computer thinks an "int" is 4 bytes in size. Your computer might use a different size if it is a 32 bit VS. 64 bit*/
	printf("The size of an int: %ld\n",sizeof(int));

/*The "areas" array has 4 integers in it, so it makes sense that my comptuer requires 20 bytes to store it.*/
	printf("The size of areas(int[]): %ld\n", 
	sizeof(areas));	
	
/*If we dive the size of "areas" by the size of an "int" then we get 5 elements as expected*/
	printf("The number of ints in areas: %ld.\n", 
	sizeof(areas)/sizeof(int));

/*We then did an array access to get "areas[0]" and "areas[1]" which means C is "zero indexed"*/
	printf("The 1st area is %d, the 2nd area is %d.\n", 
	areas[0], areas[1]);

/*We repeat this for the "name" array, but notice something odd about the size of array? It says it is 4 bytes, but we only typed "zed" for 3 characters. Where is the 4th one coming from?*/
/* Answer: That is because the default size of character is 4bytes.*/
	printf("The size of char: %ld\n", sizeof(char));
	printf("The size of name(char []) %ld.\n",sizeof(name));
	printf("The number of chars in name: %ld.\n", sizeof(name)/sizeof(char));

/*we do the same thing with with "full_name" and notice it gets this correct.*/
	printf("The size of full_name (char[]): %ld.\n", sizeof(full_name));
	printf("The number of chars in full_name is: %ld.\n",sizeof(full_name)/sizeof(char));
	printf("Name =\"%s\" and Full Name = \"%s\". \n", name, full_name);
	return 0;
}
