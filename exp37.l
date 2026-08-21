%{
#include <stdio.h>
#include <string.h>

char word[50];
int count = 0;
%}

%%
[a-zA-Z]+ {
    if (strcmp(yytext, word) == 0)
        count++;
}

\n {
    printf("Frequency of '%s' = %d\n", word, count);
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
    printf("Enter the word to search: ");
    scanf("%s", word);
    getchar();

    printf("Enter the sentence: ");
    yylex();

    return 0;
}