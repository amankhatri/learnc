/*"switch" statement is actually entirely different and is really a "jump table" . Insdead of random boolean expressions, you can only put expressions that  result in integers, and these integers are used to calculate jumps from the top of the "switch" to the part that matches that value. Here is some code that we will break down to understand the concept of "jump tables"*/
#include<stdio.h>
/*if you have to enter multple argument as one element in array then you do ./ex13 "zed shawn". here my question is how do we make it "argv" a multidimentional array*/
int main (int argc , char *argv[])
{
	if(argc!=2)
	{
		printf("Error: YOu need one argument.\n");
		/*This is how you abort a program*/		
		return 1;
	}
	int i = 0;
	for(i=0;argv[1][i]!='\0';i++)
	{
		char letter = argv[1][i];
		switch(letter)
		{
			case 'a':
			case 'A':
			printf("%d: 'A'\n", i);
			break;

			case 'e':
			case 'E':
			printf("%d: 'E'\n", i);
			break;

			case 'i':
			case 'I':
			printf("%d: 'I'\n", i);
			break;
			case 'o':
			case 'O':
			printf("%d: 'O'\n", i);
			break;

			case 'u':
			case 'U':
			printf("%d: 'U'\n", i);
			break;

			case 'y':
			case 'Y':
				if(i>2)
				{
					/*IT IS ONLY SOMETIMES Y*/
					printf("%d: 'Y'\n", i);
				}
			break;
			default:
			printf("%d: %c is not a vowel.\n",i, letter);
		}
	}

	return 0;
}
/*In this program we take a single command line argument and print out all of the vowels in an incredibly tedious way to demostrate a "switch" statement. Here is how the "switch" statement works:
	a) The compiler marks the places in the program where the "Swtich" statement starts, lets call this location Y.
	b)It then evaluates the expression in switch(letter) to come up with a number. In this case the number will be the raw ASCII code of the letter in argv[1].
	c)The compler has also translated each of the "case" blocks like "case 'A':" into a location in the program that is far away. So the code under "case 'A':" is Y+'A' in the program.
	d)It then does the math to figure out where Y+ letter is located in the "switch" statement and if it is too far then it adusts it to Y+default.
	e)Once it knows the location, the program "jumps" to that spot in code and then continues running. This is why you have break on some of the "case" blocks , but not others.
	f) If 'a' is enterd, then it jumps to "case 'a'", there is not break so it "falls through" to the one right under it "case 'A'" which has code and a break.
	g) Finally it runs this code, hits the break then exits out of the "Switch" statement entirely.*/
/*This is a deep dive into how the "swith: works,but in practice you just have to remember a frew simple rules:
	a) Always include a "default:" branch so that you catch any missing inputs.
	b) Don't allow "fall through" unless you really want, and it is a good idea to add a comment "//fallthrough" so people know it is on purpose.
	c)Always write the "case" and the "break" before you write the code that goes in it.
	d)Try to use "if: statements instead if you can.*/ 
