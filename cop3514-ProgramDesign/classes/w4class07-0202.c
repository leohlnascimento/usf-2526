/*
    Notes - Class 07 - Feb 02, 2026

    - Integer types
        signed and unsigned
        %hd - short int
        integer overflow: arithmetic operations performed on int
        with result too large to represent
    - Casting (explicit conversion)
        ( type-name ) expression
    - Floating types
        float: single-precision (32 bits) -> 6 digits of precision
        double: double-precision (64 bits) -> 15 digits of precision
        long double: extended-precision
        float f = 3.14; -> stored as a double
        float f = 3.14f; -> stored as a float
    - Format specifiers
        scanf: %f float %lf double
        printf: %f is always double
    - Type Definitions
        #define BOOL int ("Boolean type" macro)
        typedef int Bool;
        typedef long int ptrdiff_t;
        typedef unsigned long int size_t;
        strlen() function:
            size_t strlen(const char *s);
    - Characters
        ASCII code (American Standard Code for Information Interchange)
        C treats characters as small integers
    - getchar() and putchar()
        faster than scanf and printf for single-character input and output
    - Character-Handling Functions
        toupper library: #include <ctype.h>
        toupper() returns the upper-case version
        isdigit, isalpha
*/

#include <stdio.h>
#include <ctype.h>

int main(void) {
    /* char ch;
    int n = 0;
    while ((ch = getchar()) != '\n') {
        if (!(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9'))){
            printf("Invalid");
            return 0;
        }
        n++;
        printf("%c", ch);
    }
    if (n < 8) {
        printf("Invalid");
        return 0;
    }
    printf("Valid password with %d characters\n", n);
    */
   
    // exercise 01
    /*int c;
    for(c = 32; c <= 126; c++){
        printf("%c %d\n", c, c);
    }*/

    // exercise 02
    /*int ch;
    printf("Enter a message: ");
    while((ch = getchar()) != '\n'){
        if ('a' <= ch && ch <= 'z') ch -= ('a' - 'A');
        printf("%c", ch);
    }
    printf("\n");*/

    // exercise 03
    int ch;
    printf("Enter a message: ");
    while((ch = getchar()) != '\n'){
        if (isalpha(ch) && islower(ch)) ch = toupper(ch);
        printf("%c", ch);
    }
    printf("\n");
    
    return 0;
}
