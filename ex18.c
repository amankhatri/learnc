/*Functions in C are actually just pointers to a spot in the program where some code exists. Just like we have been creating pointers to "structs", "strings" and "arrays", you can point a pointer at a function too. The main use for this is to pass "callbacks to other functions, or to simulate classes and objects.*/
/*The format of a function pointer goes like this:
"int (*pointer_name) (int a, int b)"*/
/* A way to remember how to write one is to do this:
	a) Write a normal function declaration: "int callme(int a, int b)"
	b) Wrap the function name with pointer syntax: "int (*callme) (int a, int b)"
	c) change the name to the pointer name : "int (*compare_cb) (int a, int b)" */
/*The key thing to remember is , when you are done with this, the variable name for the pointer is called "compare_cb" and then you use it just like it is a function. This is similar to how pointers to array can be used just like the arrays they point to. Pointers to functions can be used like the functions they point to but with  a different name* 
"int (*tester)(int a, int b) = sorted_order;"
"printf("Test: %d is same as %d \n", tester(2,3), sorted_order(2,3)); */
/*This will work even if the function pointer returns a pointer to something
	a) Write it: "char *make_coolness(int awesome_levels)"
	b) wrap it: "*(*make_coolness) (int awesome_levels)"
	c) Rename it: char *(*coolness_cb)(int awesome_levels)"*/
/*The next problem to solve with using function pointers is that it is hard to give them as parameters to a function, like when you want to pass the function callback to another function. The solution to this is to use typedef which is a C keyword for making new names for other more complex types. Thee only thing you need to do is put "typedef" before the same function pointer syntax, and then after that you can use the name like it is a type. code follows for explaination:*/
