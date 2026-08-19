#include <stdio.h>
#include <string.h>

char firstS[10], firstA[10], firstB[10];

void findFirst()
{
    // A -> epsilon
    strcpy(firstA, "e");

    // B -> epsilon
    strcpy(firstB, "e");

    // S -> AaAb / BbBa
    // A and B can produce epsilon,
    // so FIRST(S) contains a and b
    strcpy(firstS, "ab");
}

int main()
{
    findFirst();

    printf("Given Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> e\n");
    printf("B -> e\n\n");

    printf("FIRST(A) = { e }\n");
    printf("FIRST(B) = { e }\n");
    printf("FIRST(S) = { a, b }\n");

    return 0;
}