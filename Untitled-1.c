#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char exp[100];
int pos = 0;

// E -> E + T | E - T | T
double E();

// T -> T * F | T / F | F
double T();

// F -> (E) | digit
double F();

double E()
{
    double val = T();

    while (exp[pos] == '+' || exp[pos] == '-')
    {
        char op = exp[pos++];

        if (op == '+')
            val = val + T();
        else
            val = val - T();
    }

    return val;
}

double T()
{
    double val = F();

    while (exp[pos] == '*' || exp[pos] == '/')
    {
        char op = exp[pos++];

        if (op == '*')
            val = val * F();
        else
            val = val / F();
    }

    return val;
}

double F()
{
    double val;

    if (exp[pos] == '(')
    {
        pos++;
        val = E();
        pos++;
    }
    else
    {
        val = exp[pos] - '0';
        pos++;
    }

    return val;
}

int main()
{
    printf("Enter arithmetic expression: ");
    scanf("%s", exp);

    double result = E();

    printf("Final Result = %.2lf\n", result);

    return 0;
}