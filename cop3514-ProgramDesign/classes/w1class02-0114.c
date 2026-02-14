/* 
    Notes - Class 02 - Jan 14, 2026

    - Why C?
        Access to machine-level concepts (e.g. bytes and pointers)
        C versions: C89, C99, C11
        C-based languages: C++, Objective-C, Java, C#

    - General Form of a Simple Program
        directives -> int main(){ statements }
        Preprocessing (directives) ->
        Compiling (translates into object code == machine instructions)
        Linking (combines the code produced by the compiler with any additional code)

    - GCC compiler (GNU Compiler Collection)
    - main function is mandatory and special
        it gets called automatically when the program is executed

    - Variables == way to store data
        Every variable has a type

    
*/
// Example of Program: 

// Standard Input Output
// .h == Header File
#include <stdio.h>

#define QUARTER 25 // macro definition

int main(void) {
    // printf("Hello, world\n");
    /* This is a block comment */
    int hours;
    double hourly_rate = 13.50; // reading a double: "lf"
    printf("Enter the number of hours: ");
    // & is the address operator
    scanf("%d", &hours);
    printf("The pay is %.2f\n", hours * hourly_rate);
    printf("%f\n", 5/9.0);
    return (0);
}

// gcc -Wall -Wextra -Wpedantic -std=c99 -g main.c -o main
// -Wall : shows all warnings
// -Wextra : more warnings
// -Wpedantic : pedantic warnings (follow strict standard)
// -g : debugging info