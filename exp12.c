#include <stdio.h>
#include <string.h>

char input[100];
int pos = 0;

int E();
int Eprime();
int T();
int Tprime();
int F();

int E()
{
    if (T())
        return Eprime();

    return 0;
}

int Eprime()
{
    if (input[pos] == '+')
    {
        pos++;

        if (T())
            return Eprime();

        return 0;
    }

    return 1;   // epsilon
}

int T()
{
    if (F())
        return Tprime();

    return 0;
}

int Tprime()
{
    if (input[pos] == '*')
    {
        pos++;

        if (F())
            return Tprime();

        return 0;
    }

    return 1;   // epsilon
}

int F()
{
    if (strncmp(&input[pos], "id", 2) == 0)
    {
        pos += 2;
        return 1;
    }

    if (input[pos] == '(')
    {
        pos++;

        if (E() && input[pos] == ')')
        {
            pos++;
            return 1;
        }

        return 0;
    }

    return 0;
}

int main()
{
    printf("Grammar:\n");
    printf("E  -> TE'\n");
    printf("E' -> +TE' | e\n");
    printf("T  -> FT'\n");
    printf("T' -> *FT' | e\n");
    printf("F  -> (E) | id\n\n");

    printf("Enter input string: ");
    scanf("%s", input);

    pos = 0;

    if (E() && input[pos] == '\0')
        printf("\nString is ACCEPTED.\n");
    else
        printf("\nString is REJECTED.\n");

    return 0;
}