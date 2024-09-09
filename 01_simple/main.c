//
// Created by Timo Niemann on 11.06.24.
//
#include <stdio.h>
#include <stdlib.h>

void print_vars(int x, int *px){
    // referencing x
    printf("address (&x) = %p\n", &x);
    printf("value x = %d\n\n", x);

    // referencing pointer to x
    printf("address (&px) = %p\n", &px);
    printf("address px is pointing to = %p\n", px);
    printf("value (*px) = %d\n", *px);
}

// increment a by 1
int simple_increment(int a){
    return ++a;
}

// what if we want to increment but have a function that returns nothing
void simple_increment_no_ret(int a){
    a++;
}

// increments value in given address
void advanced_increment(int *pa){
    // notice the right brackets
    (*pa)++;
}

int even_more_advanced_increment(int a, int *error){
    a++;
    *error = 1;
    return a;
}

void page1(){
    // static variable x which is stored on the heap
    int x = 4;
    // pointer to the address of x
    int *px = &x;

    print_vars(x, px);

    printf("\n\n");

    // see no witchcraft
}

void page2(){
    // lets leverage our knowledge
    int x = 4;

    printf("Let us increment x = %d by one\n", x);
    int result = simple_increment(x); // has return type int and takes int as argument
    printf("result = %d\n", result);

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
    advanced_increment(px);
    printf("\n-> advanced_increment(px)\n\n");
    print_vars(x, px);
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
    //page1();
    //page2();
    //page3();
    page4();
}
