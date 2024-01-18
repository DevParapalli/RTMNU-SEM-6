%option noyywrap
%{
#include <stdio.h>
%}
%%
(a|b)*abb {printf("Valid String: %s\n", yytext);}
%%
int main()
{
    yylex();
    return 0;
}
