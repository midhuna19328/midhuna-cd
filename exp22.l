%{
#include <stdio.h>

int line_number = 1;
%}

%%

\n      {
            printf("\n%d\t", ++line_number);
        }

.       {
            printf("%s", yytext);
        }

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

    printf("%d\t", line_number);

    yylex();

    fclose(fp);

    return 0;
}

int yywrap()
{
    return 1;
}