//
// Created by Timo Niemann on 11.06.24.
//
/*
How to C Pointer:
Pointers are one major part of the C programming language, they are used to address memory addresses.


What is a heap or a stack?
Think abstract, heap... HEAP! The heap is a heap everything trash is pushed to the bottom of the heap.
Like moving literal trash together.
The Heap contains all memory which is not explizitly asked for (malloc), for example int x, x is placed on the heap
The Stack is like a pile of books. A new book is placed on top
Contains all memory which was asked for by malloc, calloc, ...

---------
|       |
| Heap  |   | grows downwards
|       |   v
|       |
---------
|       |
| Free  |   // they can meet but in 64 bit you have a so gigantic space of max address and min address (2^64 bytes (2 exabytes)
|       |   // so gigantic that the bare task to allocate this much memory would probably take years
|       |
---------   <- Here is the stackpointer which indicates the current position of the last allocated memory
| Stack |   ^
|       |   | grows upwards
---------
*/

// lets include stdio and especially stdlib, stdlib contains standard memory 'altering' functions
#include <stdio.h>
#include <stdlib.h>

// just to print inputs to stdout
void print_vars(int x, int *px){
    // referencing x
    printf("address (&x) = %p\n", &x);  // print the address, where x is stored
    printf("value x = %d\n\n", x);      // print x itself

    // referencing pointer to x
    printf("address (&px) = %p\n", &px);    // print the address of the pointer
    printf("address px is pointing to = %p\n", px); // lets have a look where the pointer is pointing to (get the pointed to address)
    printf("value (*px) = %d\n", *px);  // see this address? go look whats written there (follow the pointer and get the value of the address)
                                        // this is called dereferencing a pointer
}

// increment a by 1
int simple_increment(int a){
    return ++a; // remember ++a is increment then use not use then increment
}

// what if we want to increment but have a function that returns nothing
void simple_increment_no_ret(int a){
    a++;
}

// increments value in given address
void advanced_increment(int *pa){
    // notice the right brackets
    // this is dereference the pointer and increment the value
    // if no brackets were written the pointer is incremented, meaning the address does not point to the right value anymore
    // instead it points to the eraser beside my pencil
    (*pa)++;
}

int even_more_advanced_increment(int a, int *error){
    a++;
    // for example use pointers to set error states 
    *error = 1;
    return a;
}

/*
Starting here
this example shows how a pointer is created from a variable, especialy how the address is accessed
*/
void page1(){
    // static variable x which is stored on the heap
    int x = 4;
    // pointer to the address of x
    int *px = &x;       // se the operators * and & the & gets the address of x like 0x123456 the * is the pointer operator
                        // the pointer operator says that its not just an int instead its a pointer to an int
                        // like me pointing on a pencil I am the pinter to my pencil, i know where the pencil is
                        // but if i want to know what pencil i need to look where the pencil is and ask whats written on the pencil, ah yes H2

    // lets see what these variables have to offer
    print_vars(x, px);

    printf("\n\n");

    // see no witchcraft
}

void page2(){
    // lets leverage our knowledge
    int x = 4;

    printf("Let us increment x = %d by one\n", x);
    // Simply increment x by one and return this
    int result = simple_increment(x); // has return type int and takes int as argument
    printf("result = %d\n", result);

    // what is if the function has no return, its type void but you want to get a result
    printf("-> simple_increment_no_ret(x)\n\n");
    simple_increment_no_ret(x);
    printf("result = %d\n", x);

    printf("\nHow could we get the result in another way? -> See Page 3\n");
    printf("\n\n");
}

void page3(){
    int x = 4;
    int *px = &x;

    printf("Let us increment x = %d by one\nvia pointer and function which isn't returning anything\n\n", x);
    print_vars(x, px);
    // see we pass the pointer to x we also could have written &x to tell the function here is where you need to look
    advanced_increment(px);
    printf("\n-> advanced_increment(px)\n\n");
    print_vars(x, px);  // x is now 5 without return wooow
    printf("\n\n");
}

void page4(){
    printf("What if we want to get two returns, like a error?\n\n");
    int x = 4;
    // we want to have a fresh pointer that is not dependent on x
    // we utilize the malloc functions derived by the library stdlib
    // the pointer is now an int* cast to the void* malloc returns
    // malloc gives a pointer to the first address of a 4 byte defined large space on the stack
    int *error = (int*)malloc(sizeof(int));
    *error = 0;
    print_vars(x, error);
    printf("\n-> even_more_advanced_increment(x, error)\n\n");
    x = even_more_advanced_increment(x, error);
    print_vars(x, error);

    // because we allocated memory on the stack we need to also free this
    free(error);
}

int main(void){
    // comment or uncomment wanted outputs
    page1();
    page2();
    page3();
    page4();
}

/*
someone once made a good example for pointers
You do not carry your house around, you tell the address, where for example the party is. 
*/
