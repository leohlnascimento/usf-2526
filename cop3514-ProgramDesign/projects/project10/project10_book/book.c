#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"
#include "read_line.h"

Book *add_to_list(Book *list){

    Book *prev, *cur, *new_node;

    new_node = (Book *)malloc(sizeof(Book));
    if (new_node == NULL) {
        printf("Database is full; can't add more.\n");
        return list;
    }

    printf("Enter book title: ");
    read_line(new_node->title, TITLE_LEN);

    printf("Enter author's first name: ");
    read_line(new_node->first, NAME_LEN);

    printf("Enter author's last name: ");
    read_line(new_node->last, NAME_LEN);


    for (cur = list; cur != NULL; cur = cur->next)
    if (cur != NULL && strcmp(new_node->title, cur->title) == 0
                    && strcmp(new_node->first, cur->first)== 0
                    && strcmp(new_node->last, cur->last)==0) {
        printf("book already exists\n");
        free(new_node);
        return list;
    }

    printf("Enter book's price: ");
    scanf("%lf", &new_node->price);

    printf("Enter the number of requests: ");
    scanf("%d", &new_node->num_requests);

    for (cur = list, prev = NULL;
        cur != NULL && (strcmp(new_node->last, cur->last) > 0 || 
        (strcmp(new_node->last, cur->last) == 0 && strcmp(new_node->first, cur->first) > 0));
        prev = cur, cur = cur->next)
        ;
    
    new_node->next = cur;

    if (prev == NULL) {
        return new_node; // new node becomes the head of the list
    } else {
        prev->next = new_node;
        return list;
    }
}

Book *delete_from_list(Book *list)
{
    char first_name[NAME_LEN + 1];
    char last_name[NAME_LEN + 1];
    char book_title[TITLE_LEN + 1];
    
    Book *cur = list, *prev = NULL;

    printf("Enter title: ");
    read_line(book_title, NAME_LEN);
    printf("Enter author first name: ");
    read_line(first_name, NAME_LEN);
    printf("Enter author last name: ");
    read_line(last_name, NAME_LEN);

    while (cur != NULL) {
        if (strcmp(cur->title, book_title) == 0 && 
            strcmp(cur->first, first_name) == 0 && 
            strcmp(cur->last, last_name) == 0) {
        
            // if found, remove from list
            if (prev == NULL) {
                list = cur->next; // deleting the first node
            } else {
                prev->next = cur->next; // bypassing the current node
            }
        
            free(cur);
            printf("book deleted\n");
            return list;
        }
        prev = cur;
        cur = cur->next;
    }

    printf("book does not exist\n");
    return list;
}

//print all books in the list
void print_list(Book *list){

    Book *p;

    printf("\nTitle\t\t\t\t\tFirst Name\tLast Name\t"
            "Requests  Price\n");
    for (p =list; p != NULL; p = p->next)
        printf("%-40s%-16s%-16s%6d%10.2f\n", p->title, p->first,p->last,
            p->num_requests, p->price);
}

// release memory of the nodes in the linked list
void clear_list(Book *list){
    Book *p;

    while(list!=NULL){
        p = list;
        list = list->next;
        if(p!=NULL)
            free(p);
    }
}