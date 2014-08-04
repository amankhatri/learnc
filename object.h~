/*The object header file- I want to put the data types and functions into a seperate hearder files names "object.h". This is standard C practice and it lets you ship binary libraries, but still let the programmer complie against it. In this file I have several advances CPP techiniques I am going to quickly describe and then have you see in action later:*/
#ifndef_object_h
#define_object_h
typedef enum
{
	NORTH, SOUTH, EAST, WEST
}Direction;
typedef struct
{
 	char *description;
	int (*init)(void *self);
	void (*describe) (void *self);
	void (*destroy) (void *self);
	void *(*move)(void *self, Direction direction);
	int (*attact)(void *self, int damage);
} Object;
int Object_init(void *self);
void Object_destroy(void *self);
void Object_describe(void *self);
void *Object_move(void *self, Direction direction);
int Object_attack(void *self, int damage);
void *Object_new(size_t size, Object proto, char *description);
#define NEW(T,N) Object_new(sizeof(T), T##Proto, N)
#define _(N) proto.N
#endif
