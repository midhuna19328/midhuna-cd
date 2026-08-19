%{
#include <stdio.h>
int valid = 0;
%}

%%

^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}\n {
    valid = 1;
    return 0;
}

^[^\n]+\n {
    valid = 0;
    return 0;
}

%%

int main()
{
    printf("Enter email address: ");
    yylex();

    if (valid)
        printf("Valid Email Address\n");
    else
        printf("Invalid Email Address\n");

    return 0;
}

int yywrap()
{
    return 1;
}