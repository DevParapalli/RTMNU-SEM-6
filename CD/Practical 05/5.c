#include <stdio.h>
#include <stdlib.h>

char* InputString;

unsigned short int E() {
    if (*InputString == '+') {
        printf("%-16s E->+EE\n", InputString);
        InputString++;
        E();
        E();
    } else if (*InputString == '-') {
        printf("%-16s E->-EE\n", InputString);
        InputString++;
        E();
        E();
    } else if (*InputString == 'a') {
        printf("%-16s E->a\n", InputString);
        InputString++;
    } else if (*InputString == 'b') {
        printf("%-16s E->b\n", InputString);
        InputString++;
    }
    if (*InputString == '\0') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    InputString = "+-a-aa+ab";
    E() ? printf("String is accepted\n") : printf("String is not accepted\n");

    return 0;
}