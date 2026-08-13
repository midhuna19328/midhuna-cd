#include <stdio.h>

int main()
{
    char firstS[10], firstA[10], firstB[10];
    int nS = 0, nA = 0, nB = 0;

    /* FIRST(A) */
    firstA[nA++] = 'e';   // e represents epsilon

    /* FIRST(B) */
    firstB[nB++] = 'e';

    /* S -> AaAb
       A can produce epsilon, so FIRST(AaAb) = {a}
       
       S -> BbBa
       B can produce epsilon, so FIRST(BbBa) = {b}
    */

    firstS[nS++] = 'a';
    firstS[nS++] = 'b';

    printf("Given Grammar:\n");
    printf("S -> AaAb | BbBa\n");
    printf("A -> e\n");
    printf("B -> e\n\n");

    printf("FIRST(A) = { ");
    for (int i = 0; i < nA; i++)
        printf("%c ", firstA[i]);
    printf("}\n");

    printf("FIRST(B) = { ");
    for (int i = 0; i < nB; i++)
        printf("%c ", firstB[i]);
    printf("}\n");

    printf("FIRST(S) = { ");
    for (int i = 0; i < nS; i++)
        printf("%c ", firstS[i]);
    printf("}\n");

    return 0;
}