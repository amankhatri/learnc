#include <stdio.h>
/*this is a comment*/
/*An include and it is the way to import the contents of one file into this
source file (ex5.c). C has a convention of using ".h" extensions for "header"
files, which then contain lists of functions you want to use in your program*/

int main(int argc, char *argv[])
/* A more complex version of the main function you have been using blindly
so far. How C programs work is the opertaing system loads your program,
and then runs the function named "main". For the function to be toatally
complete it needs to return an "int" and take two parameters , an "int" for 
the argument count, and an array of "char *" strings for the arguments. This
will be covered in future. */

{
/*To start the body of any funtion you write "{" character that indicates the
begning of a block. */

	int distance  =100;
/*A variable declaration and assignment at same time. This is how you create
a variable, with the syntax type "name = value;" In C statements (Except logic)
end in a ";" character */

	printf ("You are %d miles away.\n",distance);
/* A call to  "printf" function. Like in many languages function calls work
with the syntax "name(arg1, arg2);" and can have no arguments, or any number.
The "printf" function is actually kind of weird and can take multiple arguments
We will see that later.*/

	return 0;
/* A return from the main function , which gives the OS your exit value. You
may not be familiar with how Unix software uses return codes, so we will cover
that as well.*/

}
/* Finally, we end the main function with a closing brace "}" character and 
thats the end of the program.*/

