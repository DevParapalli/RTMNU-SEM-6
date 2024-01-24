/*** Definition section ***/
%option noyywrap
%{
    #include <stdio.h>
%}

MACRO [a-zA-Z][a-zA-Z0-9]*

%%

/*** Rules section ***/

%%

/*** C Code section ***/
int main(void)
{
    yylex();
    return 0;
}%%