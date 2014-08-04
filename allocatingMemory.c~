/*http://www.indiabix.com/technical/c/the-c-language-basics page 2 , I will modify certain bits of program because they don't show that it is nessacary to free the memory after you are done with processing.*/
/*can you tell whether a loop ended prematurely?*/
/*Attempt (in vain, I must add...) to
   allocate 512 10KB blocks in memory. */

#include<stdio.h>
#include<string.h>
#define REQUESTED_BLOCKS 512
int main(int argc, char *argv[])
{
	int i =0;
	char *cp[REQUESTED_BLOCKS];
	for(i=0; i<REQUESTED_BLOCKS;i++)
	{
		cp[i] = (char*)malloc(10000);
		/*casting null to char*/
		if (cp[i] == (char*) NULL)
		{
			break;
		}
	}	
	if(i<REQUESTED_BLOCKS)
	{
		printf("the loop ends prematurely");
	}
	free(cp);
	return 0;
}

