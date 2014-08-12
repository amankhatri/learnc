/*sandoundry.com/c-puzzles-address-arithmetic No understando :(*/
#include<stdio.h>
int main(int argc, char *argv[])
{
	double *ptr = (double *)100;
	ptr = ptr +2;
	printf(" unsigned ptr = %p.\n",ptr);
	return 0;
}
