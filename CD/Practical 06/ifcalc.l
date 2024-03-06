%option noyywrap
%{
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <math.h>

    #define YYSTYPE double

    #include "ifcalc.tab.h"

    void yyerror(char *);

%}

%%

[0-9]+\.?[0-9]* {
    yylval = atof(yytext);
    return NUM;
}

"(" {return LPAREN;}
")" {return RPAREN;}

[+*^/\-] | /* Send operator as is */

"\n" {
    return *yytext;
}

[ \t]+ {
    /* ignore whitespace */
}

%%
