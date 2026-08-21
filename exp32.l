%{
#include <stdio.h>

int positive = 0;
int negative = 0;
%}

%%
[+][0-9]+|[0-9]+ {
    positive++;
    printf("Positive Number : %s\n", yytext);
}

-[0-9]+ {
    negative++;
    printf("Negative Number : %s\n", yytext);
}

[ \t\n]+ ;

. ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter numbers:\n");
    yylex();

    printf("\nPositive Numbers = %d\n", positive);
    printf("Negative Numbers = %d\n", negative);

    return 0;
}