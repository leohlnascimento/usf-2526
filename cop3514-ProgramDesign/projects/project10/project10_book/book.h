#ifndef BOOK_H
#define BOOK_H

#define TITLE_LEN 100
#define NAME_LEN 30

typedef struct book{
    struct book *next;
    double price;
    int num_requests;
	char title[TITLE_LEN + 1];
	char first[NAME_LEN + 1];
	char last[NAME_LEN + 1];
} Book;

Book *add_to_list(Book *list);
Book *delete_from_list(Book *list);
void print_list(Book *list);
void clear_list(Book *list);

#endif
