/*Copying string 1 to string 2 without using  strcpy*/
#include<stdio.h>
#include<string.h>
#define MAXSIZE 4
void copyStr(int argc, char *argv[])
{	
	
	/*initializing string str with some random values so we don't get segmentation fault*/
	/*if you do "char *str[] = {};" you will get segmentation fault and core dump"*/
	printf("First way to copy strings without using the function strcpy");
	char *str[MAXSIZE]={"Alan","frank","jake", "aman"}; 
	int i = 0;
	while(argv[i]!='\0')
	{
		str[i] = argv[i];
		printf("The %d element of argv is %s and str is %s.\n", i, argv[i],str[i]);
		i++;
	}
	
	printf("Second way to copy strings without using the function strcpy");
	i=0;
	while(*(argv+i)!='\0')
	{
		*(str+i) = *(argv+i);
		printf("The %d element of argv is %s and str is %s.\n", i, argv[i],str[i]);
		i++;	
	}
		
	
}


int main(int argc, char *argv[])
{
	copyStr(argc, argv);
	return 0;
}
