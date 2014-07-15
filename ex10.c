/*You can make array of various types and have the idea down that a "string" and "array of bytes" are the same thing. The next thing tis to take this one step further and do an array that has strings in it. We will also introduce your first looping construct, the "for" loop to help print out this new data structure*/
/*The fun part of this is that there has been an array of strings hiding in your programs for a while now, the "char *argv[]" in the main function arguments. Here is code that will print out any comand line arguments you pass it */

#include<stdio.h>
int main(int argc, char *argv[])
{
	int i=0;

/*Go through the each string in argv*/
/*Note we are skipping argv[0] why?-because argv[0] is the name of the program which is ./ex10*/
	for(i=1;i<argc;i++)
	{
		printf("The string in argc is %d long and contains %s.\n",argc, argv[i]);
	}
	// let's make our own array of strings
	char *states[] = { "California", "Oregon", "Washington", "Texas"};
	int num_states = 4;
	for(i=0;i<num_states;i++)
	{
		printf("The number of elements in states array is %lu letters and it contains %s.\n", sizeof(states),states[i]);
	}

//extra credit last part (a)
	argv[argc] = states[3];
	for(i=1;i<argc+1;i++)
	{
		printf("Extra Credit assigning values to argv.\n");
		printf("The string in argc is %d long and contains %s.\n",argc, argv[i]);
	}
// in conclusion, we can assign anything to argv once we are in the program. 

//extra credit last part (b)
	states[num_states] = argv[1];
	for(i=0;i<num_states+1;i++)
	{
		printf("Extra Credit assigning values of argv to an array.\n");
		printf("The number of elements in states array is %lu letters and it contains %s.\n", sizeof(states),states[i]);
	}
	return 0;
/*From thid you should be able to figure out that in C you make an "array of strings" by combining the "char *str = blah" syntax with "char str[]={'b','l','a','h'}" sytax to construct a 2-d array. The sytanx "char states[]={...}" on line 16 is this 2-D combination with each string being one element, and each character in the string being another. The concept of multiple dimensions is something most people never think about so what you should do is build this array of string on paper:
	a) Make a grid with the index of each "string" on the left.
	b) Then put the index of each character on the top
	c) Then, fill in the squares in the middle with what single character goes in that cell
	d) Once you have the grid trace through the code manually using this grid of paper.*/
}
