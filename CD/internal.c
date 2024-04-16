#include <stdio.h>
#include <stdlib.h>

char* str;

unsigned short int E() {
    if (*str == '+') {
        printf("%-16s E->+EE\n", str);
        str++;
        E();
        E();
    } else if (*str == '-') {
        printf("%-16s E->-EE\n", str);
        str++;
        E();
        E();
    } else if (*str == 'a') {
        printf("%-16s E->a\n", str);
        str++;
    } else if (*str == 'b') {
        printf("%-16s E->b\n", str);
        str++;
    }
    if (*str == '\0') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    str = "+-b-ab+aa";
    E() ? printf("String is accepted\n") : printf("String is not accepted\n");

    return 0;
}