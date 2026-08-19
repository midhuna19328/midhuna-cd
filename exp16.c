#include <stdio.h>
#include <string.h>

void add(char set[], char ch)
{
    int i;

    for (i = 0; set[i] != '\0'; i++)
    {
        if (set[i] == ch)
            return;
    }

    set[i] = ch;
    set[i + 1] = '\0';
}

int main()
{
    char E[10] = "", T[10] = "", F[10] = "";

    /*
        Grammar:
        E -> E + T | T
        T -> T * F | F
        F -> ( E ) | id
    */

    /*
        LEADING(F):
        F -> (E) | id
        Therefore: ( , i
    */
    add(F, '(');
    add(F, 'i');

    /*
        LEADING(T):
        T -> T * F | F
        From T -> T * F, '*' is not leading
        From T -> F, leading(F) is added
        Therefore: ( , i
    */
    add(T, '(');
    add(T, 'i');

    /*
        LEADING(E):
        E -> E + T
        '+' is not leading because it comes after E
        E -> T
        Therefore leading(T) is added
        Hence: ( , i
    */
    add(E, '(');
    add(E, 'i');

    printf("Given Grammar:\n");
    printf("E -> E + T | T\n");
    printf("T -> T * F | F\n");
    printf("F -> ( E ) | id\n");

    printf("\nLEADING Sets:\n");

    printf("LEADING(E) = { ");
    for (int i = 0; E[i] != '\0'; i++)
        printf("%c ", E[i]);
    printf("}\n");

    printf("LEADING(T) = { ");
    for (int i = 0; T[i] != '\0'; i++)
        printf("%c ", T[i]);
    printf("}\n");

    printf("LEADING(F) = { ");
    for (int i = 0; F[i] != '\0'; i++)
        printf("%c ", F[i]);
    printf("}\n");

    return 0;
}