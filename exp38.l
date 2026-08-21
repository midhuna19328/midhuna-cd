%{
#include <stdio.h>

int max = 0;
char longest[100];
%}

%%
[a-zA-Z]+ {
    if (yyleng > max) {
        max = yyleng;
        sprintf(longest, "%s", yytext);
    }
}

\n {
    printf("Longest word = %s\n", longest);
    printf("Length = %d\n", max);
    return 0;
}

[ \t]+ ;
. ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a sentence: ");
    yylex();
    return 0;
}