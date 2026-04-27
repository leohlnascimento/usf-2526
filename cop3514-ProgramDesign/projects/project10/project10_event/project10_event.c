/* 
Project 10
Leonardo Henriques Lemos Nascimento
U91479116

This program reads a filename from the user, reads customer data,
sorts them by the number of purchases in the last three years in 
ascending order using qsort, and writes the result to result.csv.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_NAME 50
#define MAX_NAME 100
#define MAX_CUSTOMERS 1000

// using typedef to simplify writing
typedef struct {
    int purchases;
    // considering the max sizes for email and name
    char email[MAX_NAME];
    char name[MAX_NAME];
} Customer;

int purchase_comparison(const void *a, const void *b);

int main(void) {
    char filename[MAX_FILE_NAME];
    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // using max size for customers list
    Customer customers[MAX_CUSTOMERS];
    int count = 0;

    // fscanf returns the number of successfully matched and assigned input items
    while (count < MAX_CUSTOMERS && fscanf(fp, "%[^,],%d,%[^\n]\n",
           customers[count].email,
           &customers[count].purchases,
           customers[count].name) == 3) {
        count++;
        // when we finish the loop, count is going to be one more than the last index
        // as we start with index 0, that means i is equal to the list size
    }
    fclose(fp);

    qsort(customers, count, sizeof(Customer), purchase_comparison);

    fp = fopen("result.csv", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s, %d, %s\n", customers[i].email,
                customers[i].purchases, customers[i].name);
    }

    fclose(fp);
    printf("Output file name: result.csv\n");
    return 0;
}

int purchase_comparison(const void *a, const void *b) {
    Customer *p = (Customer *)a;
    Customer *q = (Customer *)b;
    
    return p->purchases - q->purchases;
}
