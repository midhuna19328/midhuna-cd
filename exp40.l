%{
#include <stdio.h>
%}

%%
"#include"                  { printf("PREPROCESSOR : %s\n", yytext); }
"int"|"float"|"char"|"double"|"void"|"if"|"else"|"for"|"while"|"return" {
    printf("KEYWORD      : %s\n", yytext);
}
[0-9]+ {
    printf("NUMBER       : %s\n", yytext);
}
[a-zA-Z_][a-zA-Z0-9_]* {
    printf("IDENTIFIER   : %s\n", yytext);
}
"=="|"!="|"<="|">="|"="|"+"|"-"|"*"|"/" {
    printf("OPERATOR     : %s\n", yytext);
}
"("|")"|"{"|"}"|";"|"," {
    printf("SYMBOL       : %s\n", yytext);
}
[ \t\n]+ ;
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("===== TOKEN SEPARATOR =====\n");
    printf("Enter C program:\n");
    yylex();
    return 0;
}