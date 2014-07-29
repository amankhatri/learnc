/*In this exercise you are going to make a big leap in difficulty and create an entire small program to manage database. This database is not very efficient and does not store very much, but it does demonstrate most of what you have learned so far. It also introduces memory alllocation more formally and gets you started working with files. We use some file I/O functions, but I won't be explaining them too well so you caan try to figure them out first*/
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#define MAX_DATA 512
#define MAX_ROWS 100
/*The "Address" structure then uses these constants to create a piece of data that is fixed in size making it less efficient, but easier to store and read.*/
struct Address
{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_ROWS];
};
/*The "Database" struct is then also fixed size because it is a fixed lenght array of "Address" structs. This lets you write the whol thing to disk in one move later on.*/
struct Database
{
	struct Address rows[MAX_ROWS];
	
};
struct Connection
{
	FILE *file;
	struct Database *db;
};
/*In a small program like this you can make a single function that kills the program with an error if there is anything wrong. I call this "die", and it is used after any failed function calls or bad inputs to exit with an error using "exit".*/
void die(const char *message)
{
/*When you have an error return from a function, it will usually sent an external variable called "errno" to say exactly what error happened. These are just numbes, so you can use "perror" to print the error message*/
	if(errno)
	{
			perror(message);
	}
	else
	{
			printf("ERROR: %s\n", message);
	}
	exit(1);
}
void Address_print(struct Address *addr)
{
	printf("%d %s %s\n", addr->id,addr->name,addr->email);
}
void Database_load(struct Connection *conn)
{
/*I am using all new functions like "fopen", "fclose", and "rewind" to work with files. Each of these functions work on a "File" struct that is just like your structs , but is is defined by the C standard library*/
	int rc = fread(conn->db, sizeof(struct Database),1,conn->file);
	if(rc!=1)
	{
		die("Failed to load database.");
	}
}
struct Connection *Database_open(const char *filename, char mode)
{
/*allocating large data on the "heap" - the whole point of this progeam is that I am using "malloc" to ask the OS for a large amount of memory to work with when I create the "Database".  I cover this in more detail below.*/
	struct Connection *conn = malloc(sizeof(struct Connection));
	if(!conn) 
	{
		die("Memory Error");
	}
	conn-> db = malloc(sizeof(struct Database));
	if(!conn->db) 
	{
		die("Memory  Error");
	}
	if(mode == 'c')
	{
		conn->file = fopen(filename, "w");
	}
	else
	{
		conn->file = fopen(filename, "r+");
		if(conn->file)
		{
			Database_load(conn);
		}
	}
/*checking if pointer is not "NULL". On rare systems NULL will be stored in computer (represented) as something not 0, but the C standard says you should still be able to write code as if it has a  0 Value. From now on when I say "NULL is 0" I mean its value for anyone who is overly pendantic.*/
	if(!conn->file)
	{
		die("Failed to open the file");
	}
	return conn;
}
void Database_close(struct Connection *conn)
{
	if(conn)
	{
		if(conn->file)
		{
			fclose(conn->file);
		}
		if(conn->db)
		{
			free(conn->db);
		}
		free(conn);
	}
}
void Database_write(struct Connection *conn)
{
	rewind(conn->file);
	int rc = fwrite(conn->db,sizeof(struct Database),1,conn->file);
	if(rc!=1)
	{
		die("Failed to write database.");
	}
	rc=fflush(conn->file);
	if(rc == -1)
	{
		die("cannot flush database.");
	}
}
void Database_create(struct Connection *conn)
{/*Nested struct pointers - There is use of nested structes and getting the address of array elements that you should study. Specifically code like "&conn->db->rows[i]" which reads "get the i element of "rows" which is in "db" when is in "conn" then get the address of(&) it.*/
	int i =0;
	for(i=0;i<MAX_ROWS;i++)
	{
		// make prototype to initialize it
		struct Address addr = {.id = i, .set =0};
		// Then just assign it
		conn->db->rows[i] = addr;
	}
}
void Database_set(struct Connection *conn, int id, const char *name, const char *email)
{
	struct Address *addr = &conn->db->rows[id];
	if(addr->set)
	{
		die("Already set, delete it first");
	}
	addr->set = 1;
	//Warning: Bug , read the "How to Break It" and fix this
	char *res = strncpy(addr->name, name, MAX_DATA);
	//demonstrate the strncpy bug
	if(!res)
	{
		die("Name copy failed");
	}
	res = strncpy(addr->email, email, MAX_DATA);
	if(!res)
	{
		die("Email Copy failed");
	}
}
void Database_get(struct Connection *conn, int id)
{
	struct Address *addr = &conn->db->rows[id];
	if(addr->set)
	{
		Address_print(addr);;
	}
	else
	{
		die("ID is not set");	
	}
}
void Database_delete(struct Connection *conn, int id)
{/*copying struct prototypes -best shown here, you can see I am using temporary local "Address", initializing its "id" and "set" feilds, and then simply compying it into the "rows" array by assigning it to the element I want. This trick makes sure that all the fields but "set" and "id" are initialized to -s and is actually easier to write. Incidently, youi should not be using "memcpy" to do these kinds of struct copying operation. Modern c allows you to simply assign one struct to another and It will handle the copying for you */
	struct Address addr = {.id =id, .set = 0};
	conn->db->rows[id]= addr;
}
void Database_list(struct Connection *conn)
{
	int i =0;
	struct Database *db = conn->db;
	for(i=0;i<MAX_ROWS;i++)
	{
		struct Address *cur = &db->rows[i];
		
		if(cur->set)
		{
			Address_print(cur);
		}
	}
}
int main(int argc, char *argv[])
{
	if(argc<3)
	{
		die("USAGE: ex19 <dbfile> <action> [action params]");
	}
	char *filename = argv[1];
	char action = argv[2][0];
/*I am doing some more complex argument parsing, but this is not really the best way to do it. We will get into better option parsing later in the book*/
	struct Connection *conn = Database_open(filename, action);
	int id =0;
	if(argc > 3)
	{
/*I use "atoi" function to take the string for the id on the command line and convert it to the "int id" variable. Read up on this function and similar ones.*/
		 id = atoi(argv[3]);
	}
	if(id >= MAX_ROWS) 
	{
		die("There is not that many records.");
	}
	switch(action)
	{
		case 'c':
			Database_create(conn);
			Database_write(conn);
			break;
		case 'g':
			if(argc!=4)
			{
				die("Need an id to get.");
			}
			Database_get(conn,id);
			break;
		case 's':
			if(argc!=6)
			{
				die("Need id, name, email to set");
			}
			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;
		case 'd':
			if(argc!=4) 
			{
				die("need id to delete");
			}
			Database_delete(conn, id);
			Database_write(conn);
			break;
		case 'l':
			Database_list(conn);
			break;
		default:
			die("Invalid action, only: c= create, g= get, d=del, l = lists");
	}
	return 0;
}
/*C is different because it is using the real CPUs actual machinery to do its work and that involves a chunk of ram called the stack and another is called heap. Whats the difference? It all depends on where you get the storage. 
The heap is easier to explain as it is just all the remaining memory in your computer, and you access it with the function "malloc", the OS uses internal functions to register that piece of memory to you and then returns a poitner to it. When you are done with it, you use "free" to returmm it to the OS so that it can be used by other programs. Failing to do this will cause your proggram to "leak" memory, but "valgrind" will gep you tack these leaks down*/
/*The stack is a special region of memory that stores temporary variables each function creates aas locals to that function. How it works is each argument to a function is "pushed" onto the stack, and then used inside the function. It is really a stack data structure, so the last thing in is the first thing out. This  also happenswith all local variables like "char action" and "int id" in main. The advantage of using a stack for this is simply that , when the function exits, the C complier "pops" these variables off the stack to clean up. Ths simple and prevents memory leaks if the variable off the tack to clean up. This is simple and prevents memory leaks if the variable is on stack.
There is three primary problems with stacks and heaps to watch for:
	a) If you get a block of memory from "malloc", and have that pointer on the stach, then when the function exists , the pointer will get popped off and lost
	b) If you put too much data on the stack (like large struct and arrays) then you can cause a stack overflow and the program will abort. In this case, use the heap with malloc.
	c) If you take a pointer to something on the stach, and then pass that or return it from your function, then the function receiving it will "segmentation fault" because the actual data will get popped off and disappear. you will be pointing at dead space.
This is why in the program I have created a "Database_open" that allocates memory or dies, and then a "Database_close" that frees everything. If you create a "create" function , that makes the whole thing or nothen, and then a "destroy" function that cleans up everything safely, then it is easier to keep it all straight.
Finally, when a program exits the OS will clean up all the resouces for you, but sometimes not imidiately. A common idio is to just abort and let OS clean up on error*/
