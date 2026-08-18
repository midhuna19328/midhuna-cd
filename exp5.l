%{
#include <stdio.h>

int spaces = 0;
int newlines = 0;
%}

%%
[ \t]+      { spaces += yyleng; }
\n          { newlines++; }
.           ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the input:\n");
    yylex();

    printf("\nNumber of Whitespaces: %d\n", spaces);
    printf("Number of Newline Characters: %d\n", newlines);

    return 0;
}