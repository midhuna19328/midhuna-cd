%{
#include<stdio.h>
%}

%%
hello { printf("Hello Found\n"); }
. ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter Text: ");
    yylex();
    return 0;
}