/*In the exercise you will learn how to make a "struct" , point a pointer at them to make sense to internal memory structure. I will also apply the knowledge of pointers from the last exercise and get you constructing these structures from raw memory using "malloc"*/
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<string.h>
/*This is where I am creating a sturcture that has 4 elements to describe a person. The final result is a new compund type that lets me reference these elements all as one, or each piece by name. It is similar to a row of a database table or a class in an oop language*/
struct Person
{
	char *name;
	int age;
	int height;
	int weight;
};

/*I need a way to create these structures so I have made a function to do that. Here is the important things this function is doing:
	a) I use "malloc" for "memory allocate" to ask OS to give me a piece of raw memory
	b) I pass to "malloc" the "sizeof(struct Person) which calculates the size of "struct", given all the fields inside it.
	c) I use assert to make sure that I have a valid piece of memory back from "malloc". There is a special constant called "Null" that you use to mean "unset or invalid pointer". This assert is basically checking that "malloc" didn't return a "NULL" invalid pointer.
	d) I initialize each field of "struct Person" using "x->y" syntax to say what part of struct I want to set.
	e) I use the "strdup" function to duplicate the string name, just to make sure that this structure actually owns it. The "strdup" actually is like  "malloc" and it also copies the original string into the memory it creates.*/
struct Person *Person_create(char *name, int age, int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who!=NULL);
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	return who;
}

/*If I have a "create", then I always need a "destroy" function, and this is what destroy "Person" structs. I again use "assert" to make sure I am not getting bad input. Then I use the function "free" to return the memory I got with "malloc" and "Strdup". If you don't do this you get a "memory leak".*/
void Person_destroy(struct Person *who)
{
	assert(who!= NULL);
	free(who->name);
	free(who);
}

/*I need a way to print out people, which is all this function does. It uses the same "x->y" syntax to get the field from the struc to print it.*/
void Person_print(struct Person *who)
{	
	printf("Name: %s\n", who->name);
	printf("Age: %d\n", who->age);
	printf("Height: %d\n", who->height);
	printf("Weight: %d\n", who->weight);
}
/*In the main function I use all the previous functions and the "Struct Person" to do the following:*/
int main(int argc, char *argv[])
{
	/*Make two people structures*/
	struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
	struct Person *frank = Person_create("Frank Blank", 20, 72,180);
	
	/*Print them out and where they are in memory*/
	printf("Joe is at memory location %p: \n", joe);
	Person_print(joe);
	printf("Frank is at memory location %p: \n", frank);
	Person_print(frank);

	/*Make everyone age 20 years and print them again*/
	printf("Make everyone age 20 years and print them again.\n");
	joe->age +=20;
	joe->height-=2;
	joe->weight+=40;
	Person_print(joe);
	frank->age+=20;
	frank->weight+=20;
	Person_print(frank);

	/*Destroy them both so we clean up*/
	Person_destroy(joe);
	Person_destroy(frank);

	return 0;
}
/*Structure in C is a collection of other data tyoes(variables) that are stored in one block of memory but let you access each variable independently by name. They are similar to a record in a datbase table, or a very simplistic class in an object oriented language. We can break one down this way:
	a) In the above code , you make a "Struct" that has the fields you would expect for a person: name, age, weight, height.
	b) Each of those fields has a type like "int".
	c) C then packs those together so they can all be contained in one single "Struct"
	d) The "Struct Person" is now a compund data type, which means you now refer to "Struct Person" in the same kinds of expression you would other data types.
	e) This lets you pass the whole cohesive grouping to other functions, as you did with  "Person_print"
	f) You can then access the individual parts of a "Struct" by their names using  "x->y" if you are dealing with a pointer
	g) There are also a way to make a struct that does not need a pointer, and you use the "x.y" syntax to work with it. You will do this in extra credit*/

/*If you didn't have "Struct" you would need to figure out the size , packing, and location of pieces of memory with contents like this. In fact, in most early assembler code(and even some now) this is what you do. with C you can let C handle the memory structuring of these compund data types and then focus on what you do with them.*/
