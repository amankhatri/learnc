/*In this exercise we will explore similarity between arrays and strings and get into more about memory layouts.*/
#include<stdio.h>
int main(int argc, char *argv[])
{
/*Declare two arrays "Numbers and name". This is a short-cut that C has where , if you set just one element, it will fill the rest in with 0*/	
	int numbers[4] = {0};
	char name[4] = {'a'};
	
/*First print out the elemets of numbers and name (as char)*/
	printf("Numbers[0]: %d \nNumbers[1]: %d \nNumbers[2]: %d\n Numbers[3]: %d \n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf(" Name array as character value - \nName[0]: %c \nName[1]: %c \nName[2]: %c\nName[3]: %c \n", name[0], name [1], name [2], name [3]);

/*When you print the char "name" as integer valuethen we get DECimal value of character 'a'*/		
	printf(" Name array as Integer value - \nName[0]: %d \nName[1]: %d \nName[2]: %d\nName[3]: %d \n", name[0], name [1], name [2], name [3]);

/*Setup the elements of number array*/
	numbers[0] = 1;
	numbers[1] = 2;
	numbers[2] = 3;
	numbers[3] = 4;

/*Setup the elements of name array*/
	name[0] = 'Z';
	name[1] = 'e';
	name[2] = 'd';
	name[3] = '\0';

/*Printing the elements of the newly setup number array*/
	printf("The new assigned values to numbers array are:\nNumbers[0]: %d \nNumbers[1]: %d \nNumbers[2]: %d\nNumbers[3]: %d \n", numbers[0], numbers[1], numbers[2], numbers[3]);
	
/*Printing the elements of the newly setup name array as characters*/	
	printf("The new assigned characters to name array are:\n Name[0]: %c \nName[1]: %c \nName[2]: %c\nName[3]: %c \n", name[0], name [1], name [2], name [3]);

/*Printing name array as string*/
	printf("Printing name array as string: %s.\n", name);

/*There are two syntaxes for doing a string: "char name[4] = {'a'}" on line 7 and char *another = "name" below. The first one is less common and the second is what you should use for string literals like this*/ 
/*Pointers are array of memory locations, another way of assigning the values to an array via pointers*/
	char *another = "Zed";

/*printing the contents on memory location pointed by "*another" as strings */
	printf("Printing memory location pointer by a pointer in string format: %s.\n", another);

/*printing the contents on memory location pointer by "*another" as elements of array*/
	printf("Printing memory location pointer by another as elements of array \n: another[0]: %c\nanother[1]: %c\nanother[2]: %c\nanother[3]: %c \n", another[0],another[1],another[2],another[3]);
	return 0;
}
