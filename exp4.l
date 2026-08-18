%{
#include <stdio.h>
%}

%%
[+\-*/]    { printf("Valid Arithmetic Operator: %s\n", yytext); }
[ \t\n]+   ;
.          { printf("Invalid Operator: %s\n", yytext); }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter an operator: ");
    yylex();
    return 0;
}