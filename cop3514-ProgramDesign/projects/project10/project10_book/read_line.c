#include <stdio.h>
#include <ctype.h>
#include "read_line.h"

int read_line(char str[], int n) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n' && isspace(ch))
        ;

    if (ch == '\n') {
        str[0] = '\0';
        return 0;
    }

    str[i++] = ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < n)
        str[i++] = ch;
    }
  
    str[i] = '\0';
    return i;
}