%{
#include <stdio.h>

int comments = 0;
FILE *out;
%}

%%

"//".* {
    comments++;
}

"/*"([^*]|\*+[^*/])*\*+"/" {
    comments++;
}

\n {
    fputc('\n', out);
}

. {
    fputc(yytext[0], out);
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

    out = fopen("output.c", "w");

    if(out == NULL)
    {
        printf("Cannot create output.c\n");
        fclose(fp);
        return 1;
    }

    yyin = fp;

    yylex();

    fclose(fp);
    fclose(out);

    printf("Number of comment lines = %d\n", comments);
    printf("Comments removed successfully.\n");
    printf("Output written to output.c\n");

    return 0;
}

int yywrap()
{
    return 1;
}