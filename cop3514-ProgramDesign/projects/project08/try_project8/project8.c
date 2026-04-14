/* 
Project 8
Leonardo Henriques Lemos Nascimento
U91479116

This program is a Command Line Interface (CLI)
that evaluates simple arithmetic expressions
+ - / and *
in a special ordering of operands and operators
referred to as the Reversed Polish Notation (RPN)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 128

// -------------------------------------------------
// Defining the Linked List Structure and data type:
// -------------------------------------------------

typedef struct Node {
    int value;
    struct Node *next;
} Node;



// ---------------------------------------------
// The following functions are for you to write:
// ---------------------------------------------


// TODO: write the following function:    
Node* add_end(Node *head, int value) {
    // we need to allocate the new node on the heap
    // otherwise, it would be destroyed in the return
    Node* new = (Node*)malloc(sizeof(Node));
    if (!new) exit(EXIT_FAILURE);

    new->value = value;
    new->next = NULL;

    // empty list
    if (head == NULL) return new;

    Node* cur = head;

    // go to last node
    while (cur->next) cur = cur->next;

    cur->next = new;
    
    return head;
}

// TODO: write the following function:
Node* remove_last(Node *head, int *out) {
    if (out == NULL) {
        printf("Function remove_last called without proper arguments\n");
        exit(EXIT_FAILURE);
    }

    // empty list
    if (head == NULL) return head;

    // single element
    if (head->next == NULL) {
        *out = head->value;
        free(head);
        return NULL;
    }

    Node* cur = head;
    Node* prev = NULL;

    // go to last node
    while (cur->next) {
        prev = cur;
        cur = cur->next;
    }

    *out = cur->value;

    prev->next = NULL;
    free(cur);

    return head;
}

// TODO: write the following function:
void print_list(Node *head) {
    printf("The linked list contains: ");

    Node* cur = head;
    while (cur) {
        printf("[%d]", cur->value);
        cur = cur->next;
    }

    printf("\n");
}

// TODO: write the following function:
void clear_list(Node **head) {
    if (head == NULL) return;
    
    Node* cur = *head;
    while (cur) {
        Node* temp = cur;
        cur = cur->next;
        free(temp);
    }
    
    *head = NULL;
}


// ----------------------------------------------------
// The following functions are already provided to you:
// ----------------------------------------------------

/* Returns 1 if s is a valid integer (no extra characters), puts value in *out */
int parse_int_strict(const char *s, int *out) {
    char *endptr = NULL;
    long val = strtol(s, &endptr, 10);
    if (s[0] == '\0' || *endptr != '\0') return 0;  // must consume entire string
    *out = (int)val;
    return 1;
}

/* Returns 1 if s is exactly one of + - * / */
int is_operator(const char *s) {
    return (strlen(s) == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/'));
}



// -------------------------------------
// Main function (also provided to you):
// -------------------------------------


int main(void) {
    Node *list = NULL;
    char token[MAX_INPUT_LENGTH];

    printf("Welcome to our RPN calculator!\n");

    for (;;) {
        printf("\nEnter an operand or operator: ");

        /* Read a single word (no spaces) */
        if (scanf("%127s", token) != 1) break;

        /* Empty the rest of the line as required */
        int c;
        while ((c = getchar()) != '\n' && c != EOF) { /* discard */ }

        /* Exit command */
        if (strcmp(token, "exit") == 0) {
            printf("\nThank you for using the RPN calculator!\n");
            break;
        }

        /* If token is an integer, append and print list */
        int value;
        if (parse_int_strict(token, &value)) {
            list = add_end(list, value);
            print_list(list);
            continue;
        }

        /* If token is an operator, attempt to apply to last two values */
        if (is_operator(token)) {
            int b, a;
            if (list == NULL){ // empty list, no operands
                printf("--> ERROR: Not Enough Operands entered so far\n");
                continue;
            } else if (list->next == NULL){ // only one operand
                printf("--> ERROR: Not Enough Operands entered so far\n");
                continue;
            }
            // we know there are at least two operands, so we can safely remove them
            list = remove_last(list, &b);
            list = remove_last(list, &a);

            int result = 0;
            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        /* Not specified as a special error in the prompt; treat as invalid input. */
                        printf("--> ERROR: Invalid Input: \"%s\"\n", token);
                        /* Restore original operands to preserve state */
                        list = add_end(list, a);
                        list = add_end(list, b);
                        continue;
                    }
                    result = a / b;  /* integer division */
                    break;
            }

            /* Print operation in the order shown (last, then second-last) */
            printf("Applying operator %c to operands %d and %d for a result of %d\n",
                   token[0], b, a, result);

            list = add_end(list, result);
            print_list(list);
            continue;
        }

        /* Otherwise: invalid input */
        printf("--> ERROR: Invalid Input: \"%s\"\n", token);
    }

    clear_list(&list);
    return EXIT_SUCCESS;
}
