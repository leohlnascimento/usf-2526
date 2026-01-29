/*
    Project 02
    Leonardo Henriques Lemos Nascimento
    U91479116

    This is a program that reads characters one at a time using
    getchar() and analyzes them based on ASCII values.
*/

#include <stdio.h>

int main(void) {
    int c;
    
    // do-while loop will run until a '#' character is typed
    do{
        printf("Enter 1 or more characters then ENTER:\n");
        printf("(NOTE: a character # will exit the program):\n");

        // getchat() is executed in the while condition and its value is assigned to the variable c
        // while loop will run until character '#' is typed, or the user types ENTER ('\n')
        while ((c = getchar()) != '#' && c != '\n'){
            
            // char is, in fact, also an integer that goes from 0 to 255
            // to represent ASCII or a character, we just need to change the format specifier (%c or %d)
            printf("\nYou typed: '%c' (ASCII %d)\n", c, c);
            printf("Class: ");

            if (c < 32 || 127 <= c) {
                printf("Non-printable\n");
                printf("No conversion done\n");
            } 
            else if (48 <= c && c <= 57) {
                printf("Digit\n");
                printf("No conversion done\n");
            } 
            else if (65 <= c && c <= 90) {
                printf("Uppercase Letter\n");
                printf("Converted to: '%c'\n", (c + 32));
            } 
            else if (97 <= c && c <= 122) {
                printf("Lowercase Letter\n"); 
                printf("Converted to: '%c'\n", (c - 32));
            }
            else {
                printf("Printable Symbol\n");
                printf("No conversion done\n");
            }
        }
        
        // if it is not the last iteration ('#' character), we'll skip a line
        if (c != '#') printf("\n");

    } while (c != '#');

    return 0;
}
