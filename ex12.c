/*something common in every language is that "if-statement", and C has one. Here is code that uses an "if" statement to make sure you enter only 1 or 2 arguments:*/
#include<stdio.h>
int main(int argc, char *argv[])
{
	int i = 0;
	/* argc is any value between 0 and infinity, and the indexing of array starts from 0*/
	printf("The value of argc is %d.\n",argc);
	printf("The zeroth argument is %s:\n",argv[0]);
	if(argc==1)
	{
		printf("You only have one argument. You suck.\n");
	}
	else if(argc>1 && argc<4)
	{
		printf("Here are your arguments:\n");
		for(i=0;i<argc;i++)
		{
			printf("%s\n",argv[i]);
		}
	}
	else 
	{
		printf("You have too many arguments");
	}
	return 0;
}
