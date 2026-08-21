%{
#include <stdio.h>
%}

%%
"http://www."[a-zA-Z0-9]+".com"    { printf("Valid URL\n"); }
"https://www."[a-zA-Z0-9]+".com"   { printf("Valid URL\n"); }
.*                                  { printf("Invalid URL\n"); }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter URL: ");
    yylex();
    return 0;
}