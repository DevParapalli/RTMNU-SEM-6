%{
    #include <stdio.h>
    #include <stdlib.h>
    
    int yylex(void);
    int yyerror(char *);
%}

%token NUMBER EOL

%%
input: /* empty */
    | input expr EOL { printf("= %d\n", $2); }
    ;

expr: NUMBER {$$ = $1}
    | expr expr '+' {$$ = $1 + $2}
    | expr expr '-' {$$ = $1 - $2}
    | expr expr '*' {$$ = $1 * $2}
    | expr expr '/' {$$ = $1 / $2}
;
%%

int main() {
    yyparse();
    return 0;
}

int yyerror(char *s) {
    fprintf(stderr, "![E] %s\n", s);
    return 0;
}