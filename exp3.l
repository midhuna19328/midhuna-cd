%{
#include <stdio.h>
%}

%%
[ \t\n]+        ;                  /* Ignore spaces, tabs, new lines */
"//".*          ;                  /* Ignore single-line comments */
"/*"([^*]|\*+[^*/])*\*+"/"   ;    /* Ignore multi-line comments */

[0-9]+          { printf("NUMBER: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*  { printf("IDENTIFIER: %s\n", yytext); }
[+\-*/=]        { printf("OPERATOR: %s\n", yytext); }
[(){};,]        { printf("SYMBOL: %s\n", yytext); }

.               { printf("UNKNOWN: %s\n", yytext); }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter the input:\n");
    yylex();
    return 0;
}