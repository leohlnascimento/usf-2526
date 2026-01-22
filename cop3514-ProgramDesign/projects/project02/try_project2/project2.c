/*
    Project 02
    Leonardo Henriques Lemos Nascimento
    U91479116

    This is a program that ...
*/

#include <stdio.h>

int main(void) {
    int c;
    
    do{
        printf("Enter 1 or more characters then ENTER:\n");
        printf("(NOTE: a character # will exit the program):");
        while ((c = getchar()) != '#' && c != '\n'){
            printf("\nYou typed: '%c' (ASCII %d)\n", c, c);
            printf("Class: ");
            if (c < 32 || 127 <= c) {
                printf("Non-printable\n");
                printf("No conversion done");
            } else if (48 <= c && c <= 57) {
                printf("Digit\n");
                printf("No conversion done");
            } else if (65 <= c && c <= 90) {
                printf("Uppercase Letter\n");
                printf("Converted to: '%c'", (c + 32));
            } else if (97 <= c && c <= 122) {
                printf("Lowercase Letter\n"); 
                printf("Converted to: '%c'", (c - 32));
            } else {
                printf("Printable Symbol\n");
                printf("No conversion done");
            }
            printf("\n");
        }
        printf("\n");
    } while (c != '#');

    return 0;
}
