%{
#include <stdio.h>

int characters = 0;
int lines = 0;
int words = 0;
%}

%%

[ \t]+          { characters += yyleng; }

\n              { lines++; characters++; }

"//".*          { }

[A-Za-z0-9_]+   { words++; characters += yyleng; }

.               { characters++; }

%%

int main()
{
    FILE *fp;

    fp = fopen("sample.c", "r");

    if (fp == NULL)
    {
        printf("Cannot open sample.c\n");
        return 1;
    }

    yyin = fp;

    yylex();

    fclose(fp);

    printf("\nNumber of Characters = %d", characters);
    printf("\nNumber of Lines      = %d", lines);
    printf("\nNumber of Words      = %d\n", words);

    return 0;
}

int yywrap()
{
    return 1;
}