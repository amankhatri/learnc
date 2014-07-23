/*Ex15, Pointers are famous mystical creatures in C that I will attempt to demystify by teaching you the vocablary used to deal with them. They actually aren't that complex, it is just they are frequently abused in weird ways that make them hard to use. If you avoid the stupid ways to use pointers fairly easy*/
/*To demonstrate pointers in a way we can talk about them, I have written a frivolous program that prints a group of peoples ages in three different ways*/
#include<stdio.h>
int main(int argc, char *argv[])
{
	/*create two arrays of "ages" and "names"*/
/*Create a pointer that points at ages, Notice the use of "int *" to create a "pointer to integer" type of pointer. That is similar to "char *", which is a "pointer to char" and a string is an array of chars.:(*/
	int ages[] = {23,43,12,89,2};
	char *names[] = {"Alan","Frank","Mary","John","Lisa"};
	
	/*get the size of ages to get the number of elements in the array ages for making "for" loop*/
	int count = sizeof(ages)/sizeof(int);
	int i = 0;

	/*first way using indexing, looping through the two arrays and printing how old each person is. This is using "i" to index into array.*/
	printf("First way of using pointers, indexing.\n");
	for(i=0;i<count;i++)
	{
		printf("%s has %d years alive.\n", names[i], ages[i]);
	}
	printf("--------------------------------\n");

	//setup the pointers to the start of arrays	
/*Create a pointer that points at "names". A "char *" is already a "pointer to char", so that is just a string. However you need 2 levels, since "names" is 2-dimentional, that means you need "char **" for "pointer to a pointer" type. Study that too, explain it to yourself*/
	int *cur_age = ages;
	char **cur_name = names;

	printf("Second way of using pointers.\n");
	//second way using pointers
/*Loop through the "ages" and "names" but instead use the pointers plus an offset of i. Writing "*(cur_name+i)" is same as "name[i]", and you should read it as "the value of (pointer cur_name +i)"*/
	for(i = 0;i<count;i++)
	{
		printf("%s is %d years old.\n", *(cur_name+i), *(cur_age+i));
	}
	printf("--------------------------------\n");

	printf("Third way of using pointers.\n");
	//third way , pointers are just arrays
/*This shows how the syntax to access an element of an array is the same for pointer*/
	for(i=0;i<count;i++)
	{
		printf("%s has %d years alive.\n", cur_name[i], cur_age[i]);
	}
	printf("--------------------------------\n");

/*Another admittedly insane loop that does the same thing as the other two, but instead it uses various pointer arithmatic methods:*/
	printf("Fourth way of using pointers.\n");
/*Initialize our "for-loop" then compares the distance of pointer "cur_age" from the ages. why does tht work?*/
/*The increment part of the "for-loop" then increments both "cur_name" and "cur_age" so that they point at the next element of the "name" and "age" arrays*/
	for(cur_name = names, cur_age = ages; (cur_age-ages)<count;cur_name++,cur_age++)
	{
/*The pointers "cur_name" and "cur_age" are now pointing at one element of the arrays they work on, and we can print them out using just "*cur_name" and "*cur_age", which means "the value of wherver "cur_name" is pointing.*/
		printf("%s has %d years alive.\n", *cur_name,*cur_age);
	}
	
	return 0;
}
/*more explanation about pointers*/

/*When you type something like "ages[i]" you are indexing into the array "ages", and you are using the number that is held in i to do it. If i is set to 0 then it is the same thing as typing "ages[0]". We have been calling this number "i" an index since it is a location inside "ages" that we want. It could also be called an "address" that is a way of saying "I want the integer in "ages" that is at address i".*/

/*If "i" is an index , than what is "ages"?. To C, the "ages" is a location in the computers memory where all of these integers start It is also an address, and the C compiler will replace anwhere you tupe ages with the address of the very first integer in "ages". Another way to think of "ages" is it is the "address of the first integer in ages". But the trick  is "ages" is an address inside the entire computer. it is not like "i" which was just an address inside "Ages". The "ages" array name is actuallly an address in the computer.*/

/*That leads to a certain realization: C thinks you whole computer is one massive array of bytes. Obviously this is not very useful, but then C layers on top of this massive array of bytes the concept of types and sizes of those types. You already saw how this worked in previous exercises, but now you can start to get an idea that C is somehow doing the following with your array:
	Creating a block of memory inside your computer.
	"Pointing" the name "ages" at the beginning of that block.
	"Indexing" into the block by talking the base address of "ages" and getting the element that is "i" away from there.
	converting that address at "ages+i" into a valid "int" of the right size, such that the index works to return what you want: the int at index i.*/

/*If you can take a base address, like "ages" and then add to it with another address like "i" to produce a new address, then you just make something that points right at this location all the time? Yes, and that thing is called a "pointer". This is what the pointers "cur_age" and "cur_name" are doing. They are variables pointing the the locations where "ages" and "names" live in your computer's memory. This example program is then movin them around or doing math on them to get values out of the memory. In one instance, they just add "i" to cur_age, which is same as what it does with "ages[i]" or "array[i]". In the last "for" loop though these two pointers are being moved own their own, without i to help out. In that loop, the pointers are treated like a combination of array and integer offset rolled into one.*/

/*A pointer is simply an address pointing somewhere inside the computer's memory, whi a type specifier so you get the right size of data with it. It is kind of like a combined "Ages" and "i" rolled into one data type. C knows where the pointers are pointing, knows the data type they point at, the size of those types, and how to get the data for you. Just like "i" you can increment them, devrement them, substact or add to them. But, just like "ages" you can also get values out of them, put new values in, and all the array operations.*/

/*The purpose of a pointer is to let you manually index into blocks or memory when an array won't do it right. In almost all toher cases you actually want to use an array. But there are times when you have to wrk with a raw block of memory and that is where a pointer comes in. A pointer gives you raw , direct access to a block of memory so you can work with it.*/

/*The final thing to grasp at this stage is that you can use either syntax for most array or pointer operations. You can make a pointer to something, but use the array sytanx for accessing it. you can take an array and do pointer arithimaetic with it*/

/*Read about sizes of different data types and 2 dimentional arrays*/
