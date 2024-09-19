//
// Created by Timo Niemann on 11.06.24.
//
#include <stdio.h>      
#include "malloc.h"

// if string.h is included the define would shadow the strcpy define in string.h
#ifndef strcpy
// create a MAKRO that will create two char pointers which copy the addresses of the destination and source
// these are iterated over and the destination is aligned the current value the pointer s_c is pointing to
#define strcpy(d, s) 	char *d_c = d, *s_c = s; while((*d_c++ = *s_c++))       // se how the pointer does not apply to the type
#endif                                                                          // int *x, y; would create x as a pointer but y is a normal int 

// this def pstr just prints each character of the string with pointer arithmetic
#define pstr(s)         char *str = s; while(*str) printf("%c", *str++) // no brackets on *str++ because we want to increment the pointer
#define strnull(s)      if(!s) return           // because this is a macro and macros are replaced in code this return will actually exit
                                                // the function it is used in

/**
 * Get the length of a string given as parameter
 * @param s string to get length from
 * @return length of the string
 */
size_t strlen(const char *s){
    // counter variable to count elements in the string
    size_t len = 0;
    // copy to not alter the strings pointer
    char *s_c = (char*)s;
    // loop to determine the length
    while(*s_c++) len++;

    // return the counted length
    return len;
}

// function for string arithmetics
void mystic_string_function(void){
    // create a c_str with content: "Hello, World!"
	char *s = "Hello, World!";

    // get a pointer to a legitimate memory location
	char *s_copy = (char*)malloc(strlen(s) + 1);
    // strnull checks if the string is null or not, returns when necessary
    strnull(s_copy);

    // copies the string s as source to the destination s_copy
	strcpy(s_copy, s);

    // standard print of char*
	printf("s_copy: %s\n", s_copy);
    // weird referencing of s_copy[i]
    for(int i = 0; i < strlen(s); i++)
        printf("%9d[s_copy]: %c\n", i, i[s_copy]);
    printf("\n\n");
    // 0[s_copy] is really *(0 + s_copy) and s_copy[0] is *(s_copy + 0)
    for(int i = 0; i < strlen(s); i++)
        printf("%7d + *s_copy: %c\n", i, *(i + s_copy));
    printf("\n\n");

    // print with pointer arithmetic
    pstr(s);

    // increment heap pointer
	free(s_copy);
}

// entry point
int main(){
    // makes the main simpler and more readable because this program is really readable
	mystic_string_function();
}
