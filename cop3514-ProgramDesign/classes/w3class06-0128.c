/*
    Notes - Class 06 - Jan 28, 2026

    - Vim
    - Prefix and Postfix
    - Loops
        Types of C statements: selection, iteration, jump, and Null
        while ( expression ) { statements }
        do { statements } while ( expression );
        for ( expr1 ; expr2 ; expr3 ) { statements }
        expr1 initializes variable(s)
        expr2 controls loop termination
        expr3 operation to be performed at the end of each loop iteration
        The Comma Operator: expr1a, expr1b
        break vs continue
    - The Null Statement:
        i = 0; ; j = 1;
*/

#include <stdio.h>

int main(void){
    int n;
    printf("Enter a non-negative number: ");
    scanf("%d", &n);
    int reverse = 0;
    do {
        reverse = reverse * 10 + (n % 10);
        n /= 10;
    } while (n > 0);
    printf("The reverse is %d\n", reverse);
	return 0;
}
