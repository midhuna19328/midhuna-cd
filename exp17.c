#include <stdio.h>

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
        TRAILING(F):
        F -> ( E )
        F -> id

        Therefore:
        TRAILING(F) = { ), i }
    */
    F[0] = ')';
    F[1] = 'i';
    F[2] = '\0';

    /*
        TRAILING(T):
        T -> T * F
        T -> F

        From T -> T * F, '*' is trailing
        From T -> F, TRAILING(F) is added

        Therefore:
        TRAILING(T) = { *, ), i }
    */
    T[0] = '*';
    T[1] = ')';
    T[2] = 'i';
    T[3] = '\0';

    /*
        TRAILING(E):
        E -> E + T
        E -> T

        From E -> E + T, '+' is trailing
        From E -> T, TRAILING(T) is added

        Therefore:
        TRAILING(E) = { +, *, ), i }
    */
    E[0] = '+';
    E[1] = '*';
    E[2] = ')';
    E[3] = 'i';
    E[4] = '\0';

    printf("Given Grammar:\n");
    printf("E -> E + T | T\n");
    printf("T -> T * F | F\n");
    printf("F -> ( E ) | id\n");

    printf("\nTRAILING Sets:\n");

    printf("TRAILING(E) = { ");
    for (int i = 0; E[i] != '\0'; i++)
        printf("%c ", E[i]);
    printf("}\n");

    printf("TRAILING(T) = { ");
    for (int i = 0; T[i] != '\0'; i++)
        printf("%c ", T[i]);
    printf("}\n");

    printf("TRAILING(F) = { ");
    for (int i = 0; F[i] != '\0'; i++)
        printf("%c ", F[i]);
    printf("}\n");

    return 0;
}