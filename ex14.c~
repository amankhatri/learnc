/*Writing and using functions*/
#include<stdio.h>
#include<ctype.h>

//forward declarations
int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[])
{
	int i = 0;
	printf("pass the arguments in argv to the function print_letters one by one.\n");
	for(i=0;i<argc;i++)
	{
		print_letters(argv[i]);
	}
}
void print_letters(char arg[])
{
	int i = 0;
	printf("Print each character of the arguments passed on to this function by print_arguments function.\n");
	for(i=0;arg[i]!='\0';i++)
	{
		char ch = arg[i];
		if(can_print_it(ch))
		{
			printf("'%c' == %d ",ch, ch);
		}
	}
}
int can_print_it(char ch)
{
	return isaplha(ch)||isblank(ch);
}
int main(int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}



