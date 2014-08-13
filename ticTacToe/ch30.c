/* simple tic tac toe Bluefever Software*/
/*representing board by a 3x3 2d array or 1d 9 element array by "-" but lets create a better edges around these 9 elements*/
#include<stdio.h>
/*int board[25] = {
	:,:,:,:,:,
	:,-,-,-,:,
	:,-,-,-,:,
	:,-,-,-,:,
	:,:,:,:,:};*/
const NOUGHTS = 1;
const CROSSES = 2;
const BORDER = 3;
const EMPTY = 0;
//initialize board

/*now we know that there are 9 inputs that user have to enter and we have made an array of 25 elements, so now we initialize an constant int to convert 1-9 or 0-8 array to 25 for example user could place the first NOUGHT or CROSS at index 6 on int board array. so all possible poistions are 6,7,8,11,12,13,16,17,18 */
const int ConvertTo25[9] ={6,7,8,11,12,13,16,17,18};
void InitialiseBoard (int *board)
{
	int index = 0;
	for(index = 0;index<25;++index)
	{
		board[index] = BORDER;
	}
	for(index = 0;index<9;++index)
	{
		board[ConvertTo25[9]] = EMPTY;
	}
	
}
//print board
void PrintBoard(const int *board)
{
	int index = 0;
	printf("BOARD\n");
	for(index = 0;index<25;++index)
	{
		if(index!=0&&index%5==0)
		{
			printf("\n");
		}
		else
		{
			printf("%4d",board[index]);
		}
		printf("\n");
	}
}



int main(int argc, char *argv[])
{
	int board[25];
/*Fix this: Process terminating with default action of signal 11 (SIGSEGV)
==3345==  Access not within mapped region at address 0x948053D58
==3345==    at 0x4005DA: InitialiseBoard (in /home/khatri/learnc/ticTacToe/ch30)
==3345==    by 0x400697: main (in /home/khatri/learnc/ticTacToe/ch30)
==3345==  If you believe this happened as a result of a stack
==3345==  overflow in your program's main thread (unlikely but
==3345==  possible), you can try to increase the size of the
==3345==  main thread stack using the --main-stacksize= flag.
==3345==  The main thread stack size used in this run was 8388608.*/
	//stack memory allocation error
	//InitialiseBoard(&board[0]);
/*or we can give InitialiseBoard the address of first element of board like this
	InitialiseBoard(&board[0]);*/
	//PrintBoard(&board[0]);
	
	return 0;

}
