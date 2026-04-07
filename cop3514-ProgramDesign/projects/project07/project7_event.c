/* 
Project 7
Leonardo Henriques Lemos Nascimento
U91479116
*/

#include <stdio.h>

// using typedef to simplify writing
typedef struct {
    int purchases;
    // considering the max sizes for email and name
    char email[100];
    char name[100];
} Customer;

int search(Customer list[], int n, int num, Customer result[]);

int main(void) {
    int num;
    printf("Enter number of purchases: ");
    scanf("%d", &num);

    FILE *fp = fopen("customers.csv", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // using max size for customers list
    Customer customers[1000];
    Customer c;
    int i = 0;

    // fscanf returns the number of successfully matched and assigned input items
    while (fscanf(fp, "%[^,],%d,%[^\n]\n", c.email, &c.purchases, c.name) == 3) {
        customers[i++] = c;
        // when we finish the loop, i is going to be one more than the last index
        // as we start with index 0, that means i is equal to the list size
    }
    fclose(fp);

    Customer result[1000];
    int total = search(customers, i, num, result);

    fp = fopen("result.csv", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (Customer *p = result; p < result + total; p++) {
        // when using pointers, we use -> instead of .
        fprintf(fp, "%s, %d, %s\n", p->email, p->purchases, p->name);
    }

    printf("Output file name: result.csv\n");
    fclose(fp);
    return 0;
}

int search(Customer list[], int n, int num, Customer result[]) {
    int i;
    int j;
    for(i = 0, j = 0; i < n; i++) {
        if (list[i].purchases > num) {
            result[j++] = list[i];
        }
    }
    return j;
}

