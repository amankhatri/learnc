/*this program is extra credit for EX16 learn c the hardway*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

struct Person
{
	char *name;
	int age;
	int height;
	int weight;
}person; //<-- person is the type of object for struct person.

/*Now create person*/
void Person_create(char *name, int age, int height, int weight)
{
	//using person object store the information
	person.name = name;
	person.age = age;
	person.height = height;
	person.weight = weight;
	//return person;
}
void Person_print()
{
	printf("Name: %s\n",person.name);
	printf("Age: %d\n", person.age);
	printf("Height: %d\n", person.height);
	printf("Weight: %d\n",person.weight);
}
	

int main(int argc, char *argv[])
{
	Person_create("Joe Alex",32,64,140);
	Person_print();
	Person_create("Frank Blank",20,72,180);
	Person_print();
	return 0;
}
