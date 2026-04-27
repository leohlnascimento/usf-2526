/* 
Project 10
Leonardo Henriques Lemos Nascimento
U91479116

This project implements a dynamically allocated 
linked list in C to manage a classroom library's
book requests. It features alphabetical sorting by
author name and includes robust functions for adding,
searching, and deleting entries while ensuring
efficient memory management.
*/

#include <stdio.h>
#include <stdlib.h>
#include "book.h"
#include "read_line.h"

/**********************************************************
 * main: Prompts the user to enter an operation code,     *
 *       then calls a function to perform the requested   *
 *       action. Repeats until the user enters the        *
 *       command 'q'. Prints an error message if the user *
 *       enters an illegal code.                          *
 **********************************************************/
int main(void)
{
    char code;

    Book *book_list = NULL;  
    printf("Operation Code: a for adding to the list, d for deleting a book"
           ", p for printing the list; q for quit.\n");
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')   /* skips to end of line */
            ;
        switch (code) {
            case 'a': book_list = add_to_list(book_list);
                      break;
            case 'd': book_list = delete_from_list(book_list);
                      break;
            case 'p': print_list(book_list);
                      break;
            case 'q': clear_list(book_list);
                      return 0;
            default:  printf("Illegal code\n");
        }
        printf("\n");
    }
}
