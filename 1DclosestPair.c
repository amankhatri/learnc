/*Programing Interview Question: Finding Closes pair of points in one dimention - Saurabh School youtube solution*/
#include <stdio.h>
#include<string.h>
#include <stdlib.h>

/*void print_series(char *argument[])
{
	int i = 1;
	while(argument[i]!= '\0')
	{
		printf("Arguements are %s.\n",argument[i]);
	}
	
}*/
void sortSeries(char *arg[])
{
	
	printf("I am in sortSeries function.\n");	
	int i = 1;
	int temp = 0;
	printf("Value of argv is %d.\n",atoi (arg[1]));
	while(arg[i]!= '\0')
	{
		printf("Print I %d:\n",i);
		if(atoi(arg[i+1])<(atoi(arg[i])))
		{
			temp = atoi (arg[i]);
			arg[i] = arg[i+1];
			*arg[i+1] = temp;
			i++;
			printf("stuck\n");
		}
		else
		{
			printf("I am breaking.\n");
			
		}
	
	}
	//print_series(arg);
	
}


int main(int argc, char *argv[])
{
	printf("I am in main.\n");
	sortSeries(argv);
	return 0;
}
