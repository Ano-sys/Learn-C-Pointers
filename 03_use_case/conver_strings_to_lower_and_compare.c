#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Converts given string to lowercase letters, only convertes A-Z to a-z
 * Operates inplace, means give string is converted no extra memory is allocated
 */
void convert_lower(char *s){
    char *it = s;
    while(*it){
        if(*it >= 65 && *it <= 90){
            *it = (char)(*it + 32);
        }
        it++;
    }
}

/**
 * Creates a copy of the given string
 *
 * @attention allocates memory which needs to be freed
 * @param s string to be copied
 * @return copy of s
 */
char *cpy(char *s){
    char *ret = (char*)malloc(sizeof(char) * strlen(s) + 1);
    char *t = s;
    char *t1 = ret;

    while((*t1++ = *t++));

    size_t r_size = strlen(ret);
    ret[r_size] = '\0';

    return ret;
}

/**
 * Compares the two strings given as parameter
 *
 * @return 0 if equal, -1 if not equal
 */
int strcmp_case(char *str1, char *str2){
    if(strlen(str1) != strlen(str2)) return -1;

    char *s = cpy(str1);
    char *s1 = cpy(str2);

    convert_lower(s);
    convert_lower(s1);

    char *s_save = s, *s1_save = s1;

    while(*s){
        if(*s++ != *s1++) {
            free(s_save);
            free(s1_save);
            return -1;
        }
    }

    free(s_save);
    free(s1_save);

    return 0;
}

/**
 * gets two strings as arguments
 * calls strcmp_case to make an insensitive compare of both strings
 */
int main(int argc, char **argv){
    // if less than three args are given exit, program needs two strings to compare
    // if more the first two strings are compared
    if(argc < 3){
        perror("False Argument count!");
        return -1;
    }
    // Print the user if the strings are equal or not
    printf(strcmp_case(argv[1], argv[2]) == 0 ? "YES, the strings are equal!\n" : "NO, the strings are not equal!\n");
}
