%{
#include <stdio.h>
#include <string.h>

char oldword[50], newword[50];
%}

%%
[a-zA-Z]+ {
    if (strcmp(yytext, oldword) == 0)
        printf("%s", newword);
    else
        printf("%s", yytext);
}

.|\n {
    printf("%s", yytext);
}
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter word to replace: ");
    scanf("%s", oldword);

    printf("Enter new word: ");
    scanf("%s", newword);

    printf("\nEnter file content:\n");
    yylex();

    return 0;
}