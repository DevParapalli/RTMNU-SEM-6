%option noyywrap
%{
#include <stdio.h>
%}
%%
(a|b)*abb\n {printf("Valid String: %s", yytext);}
%%
int main()
{
    yylex();
    return 0;
}
