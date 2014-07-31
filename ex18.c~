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
typedef int (*compare_cb)(int a, int b);

/* A classic bubble sort function that uses the compare_cb to do the sorting */
int *bubble_sort(int *number, int count, compare_cb cmp)
{
	int temp = 0;
	int i = 0;
	int j = 0;	
	int *target = malloc(count *sizeof(int));
	if(!target)
	{
		die("Memory Error");
	}
	memcpy(target, number, count * sizeof(int));
	for(i=0;i<count;i++)
	{
		for(j=0;j<count-1;j++)
		{
			if(cmp(target[j], target[j+1]) >0)
			{
				temp = target[j+1];
				target[j+1] = target[j];
				target[j] = temp;
			}
		}
	}
	return target;
}
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
	free(sorted);
}

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
	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, sorted_order);
	test_sorting(numbers, count, sorted_order);
	return 0;
}
