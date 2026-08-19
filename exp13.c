#include <stdio.h>
#include <string.h>
#include <ctype.h>

char expr[100];
int tempCount = 1;

void generateTAC(char *exp)
{
    int i, j;
    char op, arg1, arg2;
    char temp[10];

    // Process multiplication and division first
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '*' || exp[i] == '/')
        {
            op = exp[i];
            arg1 = exp[i - 1];
            arg2 = exp[i + 1];

            printf("t%d = %c %c %c\n",
                   tempCount, arg1, op, arg2);

            sprintf(temp, "t%d", tempCount);
            tempCount++;

            // Replace expression part with temporary variable
            exp[i - 1] = temp[0];
            for (j = i; exp[j] != '\0'; j++)
                exp[j] = exp[j + 2];

            i = -1;
        }
    }

    // Process addition and subtraction
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '+' || exp[i] == '-')
        {
            op = exp[i];
            arg1 = exp[i - 1];
            arg2 = exp[i + 1];

            printf("t%d = %c %c %c\n",
                   tempCount, arg1, op, arg2);

            sprintf(temp, "t%d", tempCount);
            tempCount++;

            exp[i - 1] = temp[0];
            for (j = i; exp[j] != '\0'; j++)
                exp[j] = exp[j + 2];

            i = -1;
        }
    }
}

int main()
{
    printf("Enter an expression: ");
    scanf("%s", expr);

    printf("\nThree Address Code:\n");

    generateTAC(expr);

    return 0;
}