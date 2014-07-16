/*You have had your first taste of how c does loop, but the boolean expression "i<argc" might have not been clear to you. Let me explain something about it before we see how a "while" loop works.*/
/*In C, there is not really a "boolean" type, and instead any integer thats "0" is "false" and otherwise it is "true". In the last exression "i<argc" actually resulted in "1" or "0" , not an explicit "true" or "false" like in python. This is another example of C being closer to how computer works, because to a computer truth values are just integers.*/
#include<stdio.h>
int main(int argc, char *argv[])
{
	int i = 0;
	while(i<argc)
	{
		printf("argc: %d, argv: %s.\n",i, argv[i]);
		i++;
	}
	char *states[] = {"california","Oregan","Washington","Texas"};
	int num_states = 4;
	i = 0;
	while(i<num_states)
	{
		printf("state %d: %s.\n",i,states[i]);
		i++;
	}
	printf("---------Extra Credit-----------\n");
	printf("Loop is working backwards ---Part1\n");
	 i = argc;
	while(i>0)
	{
		printf("argc: %d, argv: %s.\n",argc-i, argv[argc-i]);
		i--;
	}
	printf("---------Extra Credit-----------\n");
	printf("assigning values to state array ---Part2\n");
	i = 0;
	while(i<argc)
	{
		states[i] = argv[i];
		i++;
	}
	 i = 0;
	while(i<argc)
	{
		printf("States value is %s and corresponding argv value is %s.\n",states[i], argv[i]);
		i++;
	}
	
	printf("---------Extra Credit-----------\n");
	printf("limiting the value of argvs which can be assigned to state array ---Part3\n");
	printf("You can only pass three values of to states.\n");
	i = 0;
	while(i<3)
	{
		states[i] = argv[i];
		i++;
	}
	i=0;	
	while(i<argc)
	{
		printf("States value is %s and corresponding argv value is %s.\n",states[i], argv[i]);
		i++;
	}
	return 0;
	
}
