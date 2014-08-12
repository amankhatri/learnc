/*saurab school, c programing youtube lecture 15 storage class (Autmoatic, static, register, and extern*/
#include<stdio.h>
int automaticCounter()
{
/*this type of declartion is automatic declarion and the value of variables dies outside of this fucntion*/
	int counter = 0;  
	counter ++;
	printf("The counter value is %d.\n",counter);
	return 0;
	
}
int staticCounter()
{
/*this type of declaration is automatic and the value of variables dont die*/
	int static count =0;
	count ++;
	printf("The static count is %d.\n",count);
	return 0;
}
int main(int argc, char *argv[])
{
	printf("Calling automaticCounter(); for first time.");
	automaticCounter();
	printf("Calling automaticCounter(); for second time.");
	automaticCounter();
	printf("Calling staticCounter(); for first time.");
	staticCounter();
	printf("Calling staticCounter(); for second time.");
	staticCounter();
	return 0;
}
