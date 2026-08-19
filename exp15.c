#include <stdio.h>
#include <string.h>

int main()
{
    int n, i;
    char op[10], arg1[20], arg2[20], result[20];

    printf("Enter number of Three Address Code instructions: ");
    scanf("%d", &n);

    printf("\nEnter Three Address Code:\n");
    printf("Example: t1 = a + b\n\n");

    for (i = 0; i < n; i++)
    {
        scanf("%s = %s %s %s", result, arg1, op, arg2);

        printf("\nInstruction %d:\n", i + 1);

        printf("MOV R0, %s\n", arg1);

        if (strcmp(op, "+") == 0)
            printf("ADD R0, %s\n", arg2);

        else if (strcmp(op, "-") == 0)
            printf("SUB R0, %s\n", arg2);

        else if (strcmp(op, "*") == 0)
            printf("MUL R0, %s\n", arg2);

        else if (strcmp(op, "/") == 0)
            printf("DIV R0, %s\n", arg2);

        printf("MOV %s, R0\n", result);
    }

    return 0;
}