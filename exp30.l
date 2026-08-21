%{
#include <stdio.h>
int count = 0;
%}

%%
[a-zA-Z] {
    if (yytext[0]!='a' && yytext[0]!='e' && yytext[0]!='i' &&
        yytext[0]!='o' && yytext[0]!='u' &&
        yytext[0]!='A' && yytext[0]!='E' && yytext[0]!='I' &&
        yytext[0]!='O' && yytext[0]!='U')
        count++;
}

\n {
    printf("Number of consonants = %d\n", count);
    return 0;
}

. ;
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter a sentence: ");
    yylex();
    return 0;
}