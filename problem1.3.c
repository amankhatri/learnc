/* Problem 1.3 in the book "Data Structures, Algorithm and software principals in C", This program is based on pointer implimentation exclusively, it also shows the use difference between array and how pointers can be implemented. 
Problem statement: Search an array of integers to find the first first negative integer, if one exists , return its poistion in the array.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void print_arguments(int argc, char *argv[])
{
	int i =0;
	for(i =0; i<argc;i++)
	{
		printf("Character is %s.\n",argv[i]);
	}
	for(i =0; i<argc;i++)
	{
		printf("Character is %s.\n",*(argv+i));
	}
}
void find_negative(int argc, char *argv[])
{
	int i = 0; 
	//ignore the first string of arguments because it will be "./problem1.3.c"
	for(i =1; i<argc;i++)
	{
		if(*(argv+i)==2)
		{
			printf("found it at %d location.\n", i);
		}
		else
		{
			printf("All positive.\n");
		}
	}
}

int main(int argc , char *argv[])
{
	print_arguments(argc, argv);
	find_negative(argc, argv);
	//printf("Argc is %d.\n",argc);
	return 0;
}
