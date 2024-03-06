%option noyywrap
%{
    #include <stdio.h>

    #include "pfcalc.tab.h"
%}

%%

[ \t]+ { /* Ignore Whitespaces */}

[0-9]+ { yylval = atoi(yytext); return NUMBER; }

[+\-*/] { return *yytext; }

\n { return EOL; }

%%
