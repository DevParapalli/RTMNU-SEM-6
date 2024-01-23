%option noyywrap
%{
#include <stdio.h>
%}

SIGN [+-]?
DIGIT [0-9]
ALPHA_ [a-zA-Z_]
ALNUM_ [a-zA-Z_0-9]
HEXDIGIT [0-9a-fA-F]

%%
{SIGN}[1-9]{DIGIT}*\n|{SIGN}0\n {printf("INTEGER\n");}
{SIGN}0[0-7]+\n {printf("OCTAL\n");}
{SIGN}0[xX]{HEXDIGIT}+\n {printf("HEXADECIMAL\n");}
{SIGN}{DIGIT}*\.?{DIGIT}+\n {printf("FLOAT\n");}
{SIGN}{DIGIT}*\.?{DIGIT}+([eE]{SIGN}{DIGIT}+)+\n {printf("EXPONENT\n");}
{ALPHA_}{ALNUM_}*\n {printf("IDENTIFIER\n");}
%%

int main() {
    yylex();
    return 0;
}
