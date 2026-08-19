%{
#include <stdio.h>

int macros = 0;
int headers = 0;
%}

%%

^[ \t]*#[ \t]*define[^\n]*       { macros++; }

^[ \t]*#[ \t]*include[ \t]*<[^>]+>   { headers++; }

[0-9]+(\.[0-9]+)?                { printf("Constant: %s\n", yytext); }

.|\n                              ;

%%

int main()
{
    FILE *fp;

    fp = fopen("input.c", "r");

    if(fp == NULL)
    {
        printf("Cannot open input.c\n");
        return 1;
    }

    yyin = fp;

    printf("Constants in the C program:\n");

    yylex();

    fclose(fp);

    printf("\nNumber of Macros = %d\n", macros);
    printf("Number of Header Files = %d\n", headers);

    return 0;
}

int yywrap()
{
    return 1;
}