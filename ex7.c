#include <stdio.h>
int main (int argc, char *argv[])
{
/* Declare "int" and "double" variable types for some fake bug data. */	
	int bugs = 100;
	double bug_rate = 1.2;
/*Print out the "int" and "double" variables*/
	printf("You have %d bugs at the imaginary rate of %f.\n",
	bugs, bug_rate);

/*Declare huge number using a new variable type "long" for storing big numbers*/
	long universe_of_defects = 1L * 1024L * 1024L *1024L;
/*Print out "long" variable using "%ld" which adds a modifier to usual "%d". Adding "l"( the letter ell) means "print this as a long decimal"*/
	printf("The entire universe has %ld bugs.\n", universe_of_defects);

/*Another declaration of type "double"*/	
	double expected_bugs = bugs*bug_rate;
/*Printing another variable for about declaration*/
	printf("You are expected to have %f bugs.\n", expected_bugs);

/*crafting up depiction of your bug rate compared to the bugs in the universe, which is completely inaccurate calculation.*/	
	double part_of_universe = expected_bugs/universe_of_defects;
/*Printing the about variable type "double". It is so small that we have to use "%e" to print it in scientific notation/*/
	printf("That is only a %e portion of the universe.\n",
	part_of_universe);
	
	//this makes no sense, just a demo of something weird
/*Make a charater, with a special syntax "'\0'" which creates a 'nul byte' character. This is effectively the number 0.*/
// note - if you put "" (double quotes) around \0 it becomes a char
 	char nul_byte = '\0';
/*Declaration of a new "integer" variable and multiply 'nul byte' with it to get zero*/
	int care_percentage = bugs * nul_byte;
/*Print that out and notice I have got a '%%' (two percent chars) so I can print a '%'(percent) character.*/
	printf ("which means you should care %d%%.\n", care_percentage);
	return 0;

/*------------------------Extra Credit--------------------------*/
/*n-bit integer(general case): unsigned : 0 to (2^n - 1)
/*A short integer can represent a whole number which may take less storage, while having a smaller range, compared with a standard integer on the same machine. In C, it is denoted by short. It is required to be at least 16bits, and is often smaller than a standard integer, but this is not required. A conforming program can assume that it can safely store values between "-(2^n) and (2^n -1) , but it may not assume that the range isn't larger. In c the long integer if 16 bits or 4 bytes. signed long int has range from -(2^n) and (2^n - 1) that is -(2^31) and (2^31 -1) and unsigned long int is  2^31 + (2^31 -1) */
/* when we multiply char and an int and we assign the value to a type int variable then we get an int value . so when the code
char nul_byte = "\n";
int care_percentage = bugs*nul_byte
we get an int value.
}

