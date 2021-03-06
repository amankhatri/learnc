/*Functions in C are actually just pointers to a spot in the program where some code exists. Just like we have been creating pointers to "structs", "strings" and "arrays", you can point a pointer at a function too. The main use for this is to pass "callbacks to other functions, or to simulate classes and objects.*/
/*The format of a function pointer goes like this:
"int (*pointer_name) (int a, int b)"*/
/* A way to remember how to write one is to do this:
	a) Write a normal function declaration: "int callme(int a, int b)"
	b) Wrap the function name with pointer syntax: "int (*callme) (int a, int b)"
	c) change the name to the pointer name : "int (*compare_cb) (int a, int b)" */
/*The key thing to remember is , when you are done with this, the variable name for the pointer is called "compare_cb" and then you use it just like it is a function. This is similar to how pointers to array can be used just like the arrays they point to. Pointers to functions can be used like the functions they point to but with  a different name* 
"int (*tester)(int a, int b) = sorted_order;"
"printf("Test: %d is same as %d \n", tester(2,3), sorted_order(2,3)); */
/*This will work even if the function pointer returns a pointer to something
	a) Write it: "char *make_coolness(int awesome_levels)"
	b) wrap it: "*(*make_coolness) (int awesome_levels)"
	c) Rename it: char *(*coolness_cb)(int awesome_levels)"*/
/*The next problem to solve with using function pointers is that it is hard to give them as parameters to a function, like when you want to pass the function callback to another function. The solution to this is to use typedef which is a C keyword for making new names for other more complex types. Thee only thing you need to do is put "typedef" before the same function pointer syntax, and then after that you can use the name like it is a type. code follows for explaination:*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

void die(const char *message)
{
	if(errno)
	{
		perror(message);
	}
	else
	{
		printf("Error: %s\n", message);
	}
	exit(1);
}
// a typedef creates a fake type, in this case for a function pointer
/*This is where the "typedef" is used, and later I use "compare_cb" like it is a type similar to "int" or "char" in the function "bubble_sort"*/
typedef int (*compare_cb)(int a, int b);

/* A classic bubble sort function that uses the compare_cb to do the sorting */
/*Here is where I use the typedef for "compare_cb" as the last parameter "cmp". This is now a function that will return a comparision between two integers for sorting.*/
int *bubble_sort(int *number, int count, compare_cb cmp)
{
/*The usual creation of variables on the stack, followed by a new array of integers on the heap  using malloc. Make sure you understand whaat "count *sizeof(int)" is doing.*/
	int temp = 0;
	int i = 0;
	int j = 0;	
	int *target = malloc(count *sizeof(int));
	if(!target)
	{
		die("Memory Error");
	}
	memcpy(target, number, count * sizeof(int));
/*The outer loop of the bubble sort*/
	for(i=0;i<count;i++)
	{
/*The inner loop of the bubble sort*/
		for(j=0;j<count-1;j++)
		{
/*Now I call the "cmp" callback just like it is a normal function, but instead of being the name of something we defined, it is just a pointer to it. This lets the caller pass in anything they want as long as it matches the "signature" of the "compare_cb typedef".*/
			if(cmp(target[j], target[j+1]) >0)
			{
/*Actual swapping operation a bubble sort needs to do what it does*/
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}
/*Finally return the newly created and sorted array target*/
	return target;
}
/*Three different versions of the "compare_cb" function type which needs to have the same defination as the "typedef" we created.  C compiler will complain to you if you get this wrong and say the types don't match*/
int sorted_order(int a , int b)
{
	return a-b;
}
int reverse_order(int a, int b)
{
	return b-a;
}
int strange_order(int a, int b)
{
	if(a==0 || b==0)
	{
		return 0;
	}
	else
	{
		return a%b;
	}
}
/*Used to test that we are sorting things correctly by doing the sort and printing it out*/
/*THis is a tester for the bubble_sort function. You  can see now how I am also using "compare_cb" to then pass to "bubble_sort" demosntrating how these can be passed around like any other pointers */
void test_sorting(int *numbers, int count, compare_cb cmp)
{
	int i = 0;
	int *sorted = bubble_sort(numbers,count,cmp);
	if(!sorted)
	{
		die("Failed to sort as requested.");
	}
	for(i=0;i<count;i++)
	{
		printf("%d ", sorted[i]);
	}
	printf("\n");
/*free the memory*/
	free(sorted);
}
/*A simple main function that sets up an array based on integers you pass on the command line, then calls the "test_sorting" function"*/
int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		die("USAGE: ex18 4 3 1 5 6");
	}
	int count = argc-1;
	int i = 0;
	char **inputs = argv+1;
	int *numbers = malloc(count * sizeof(int));
	if(!numbers)
	{
		die("memory error.");
	}
	for(i=0;i<count;i++)
	{
		numbers[i] = atoi(inputs[i]);
	}
/*Finally you get to see how the "compare_cb" function pointer "typedef" is used. I simply call "test_sorting" but give it the name of "sorted_order", "reverse_order and "strange_order" as the function to use. The C compiler then find the address of those functions, and makes it a pointer for "test_sorting" to use. If you look at "test_sorting"s you will see it then passes each of these to "bubble_sort" but it actually has no idea what they do, only tht they match the compare_cb" prototype and should work.*/
	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, reverse_order);
	test_sorting(numbers, count, strange_order);
/*last thing we do is free up the array  of numbers we made.*/	
	free(numbers);
	return 0;
}
/*I am going to have you do something kind of weird to break this.  These function pointers are pointers like every other pointer, so they point at blocks of memory. C has this ability to take one pointer and convert it to another so you can process the data in different way. It is usually not necessary, but to show you how to have compyter I want you to add this at the end of "test_sorting"*/
/* 
	unsigned char *data = (unsigned char *)cmp;
	for(i=0;i<25;i++)
	{
		printf("%02x:", data[i]);
	}
	printf("\n");
*/
/*This loop is sort of like converting your function to a string and then print out its contents. This wont break this program unless the CPU and OS you are on has a problem with you doing this. What you will see is a string of hexadecimal numbers after it prints the sorted array.*/
/*That should be the raw assembler byte code of the function itself, and you should see they start the same, but then have different endings. It is also possible that this loop is not getting all of the function or is getting too much and stomping on another piece of program. Without more analysis you wouldnt know.*/
