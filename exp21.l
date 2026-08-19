%{
#include <stdio.h>
%}

%%

"<"[^>]+">"    { printf("%s\n", yytext); }

.|\n           ;

%%

int main()
{
    FILE *fp;

    fp = fopen("input.html", "r");

    if(fp == NULL)
    {
        printf("Cannot open input.html\n");
        return 1;
    }

    yyin = fp;

    printf("HTML Tags:\n");

    yylex();

    fclose(fp);

    return 0;
}

int yywrap()
{
    return 1;
}