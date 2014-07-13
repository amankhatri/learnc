/*we are declaring variables of different types and then printing them with
different "printf" format strings. */
#include<stdio.h>
int main(int argc, char *argv[])
{
	int distance = 100;
/* you declare integers with the "int" keyword, and print them with %d. */

	float power = 2.345f;
	double super_power = 56789.4532;
/*Declared with "float" or "double" depending on how big they need to be
(double is bigger) and printed with "%f" */

	char initial = 'A';
/* Declared with "char" written with a "'" (single-quote) character around 
the char, and then printed with "%c".*/

	char first_name[] = "Zed";
	char last_name[] = "Shaw";
	char empty_string[] = " ";
/* Declared with "char name[]", written with """ characters (double quotes),
printed with %s. */

/* You will notice that C makes a distinction between single-quote for "char"
and double-quote for "char[] or strings.*/

/* When talking about C types, I will typically write in English "char[]" 
instead of the whole "char SOMENAME[]". THis is not valid C code, just a simpler
way to talk about tupes when writing English. */ 	
	printf("You are %d miles away.\n", distance);
	printf("You have %f levels of power.\n", power);
	printf("You have %f awesome super powers.\n",super_power);
	printf("I have an initial %c.\n", initial);
	printf("I have an first name %s.\n", first_name);
	printf("I have a last name %s.\n", last_name);
	printf("My whole name is %s %c. %s.\n", first_name, initial, last_name);
	printf("The empty string is %s.\n",empty_string);
	return 0;
}
