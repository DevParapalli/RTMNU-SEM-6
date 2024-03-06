%{
    #define YYSTYPE double

    #include <stdio.h>
    #include <string.h>
    #include <math.h>

    int yylex(void);
    int yyerror(char *);
%}

%token NUM LPAREN RPAREN

%left '+' '-'
%left '*' '/'
%right '^'

%%

input:   /* empty */
    | input line
    ;

line: '\n' 
    | exp '\n' { printf("= %f\n", $1); }
;

exp: NUM { $$ = $1; }
    | LPAREN exp RPAREN { $$ = $2; }
    | exp '+' exp { $$ = $1 + $3; }
    | exp '-' exp { $$ = $1 - $3; }
    | exp '*' exp { $$ = $1 * $3; }
    | exp '/' exp { $$ = $1 / $3; }
    | exp '^' exp { $$ = pow($1, $3); }
;

%%

int yyerror(char *s) {
    fprintf(stderr, "![E] %s\n", s);
    return 0;
}

int main(void) {
    return yyparse();
}

