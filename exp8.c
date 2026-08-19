#include <stdio.h>
#include <string.h>

int main()
{
    char nonTerminal = 'L';
    char alpha[20] = ",S";
    char beta[20] = "S";

    printf("Given Grammar:\n");
    printf("S -> (L) | a\n");
    printf("L -> L,S | S\n\n");

    printf("Left Recursive Production:\n");
    printf("L -> L,S | S\n\n");

    printf("After Eliminating Left Recursion:\n");
    printf("S  -> (L) | a\n");
    printf("L  -> S L'\n");
    printf("L' -> , S L' | e\n");

    return 0;
}