/*In this exercise you are going to make a big leap in difficulty and create an entire small program to manage database. This database is not very efficient and does not store very much, but it does demonstrate most of what you have learned so far. It also introduces memory alllocation more formally and gets you started working with files. We use some file I/O functions, but I won't be explaining them too well so you caan try to figure them out first*/
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

struct Address
{
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_ROWS];
};
struct Database
{
	struct Address rows[MAX_ROWS];
	
};
struct Connection
{
	FILE *file;
	struct Database *db;
};
void die(const char *message)
{
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
	int rc = fread(conn->db, sizeof(struct Database),1,conn->file);
	if(rc!=1)
	{
		die("Failed to load database.");
	}
}
struct Connection *Database_open(const char *filename, char mode)
{
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
int main(int argc, char *argv[])
{
	return 0;
}
