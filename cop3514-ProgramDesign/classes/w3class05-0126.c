/*
    Notes - Class 05 - Jan 26, 2026

    - Unix Commands
        mv
            move a file or rename
        cp
            copy file(s)
        rm
            remove
    - Assignment
        in many programming languages, assignment is a statement
        in C, however, it is an right associative operator
    - Lvalues (left operand of assignment)
    - switch statement
        switch ( controlling expression ) {
            case constant-expression : statements
            ...
            case constant-expression : statements
            default : statements
        }
        switch fall through
    - jump statements: break, continue, return
    - comparisons (i<j) yields 0 or 1
    - bool type is available in stdbool.h
*/

#include <stdio.h>

int main(void) {
    /*
    int i = 0;
    // int j = 0;
    // -j = i;
    i = 3;
    switch (i)
    {
    // default:
    //    printf("Ha ha ha\n");
    //    break;
    case 0:
        printf("Oi 0\n");
        break;
    } */

    /*
    int m1, d1, y1;
    int m2, d2, y2;
    int earlier;
    m1 = d1 = y1 = m2 = d2 = y2 = earlier = 0;
    printf("Enter first date: (mm/dd/yyyy): ");
    scanf(" %d / %d / %d", &m1, &d1, &y1);
    printf("Enter second date: (mm/dd/yyyy): ");
    scanf(" %d / %d / %d", &m2, &d2, &y2);
    if (y1 == y2 && m1 == m2) 
        earlier = (d1 < d2) ? 1 : 2;
    else if (y1 == y2)
        earlier = (m1 < m2) ? 1 : 2;
    else
        earlier = (y1 < y2) ? 1 : 2;

    switch (earlier) {
        case 1: printf("%d/%d/%d is earlier\n", m1, d1, y1); 
                break;
        case 2: printf("%d/%d/%d is earlier\n", m2, d2, y2); 
                break;
    }
    */

    int i;
    scanf("%d", &i);
    printf("%d\n", i);
    
    return 0;
}
