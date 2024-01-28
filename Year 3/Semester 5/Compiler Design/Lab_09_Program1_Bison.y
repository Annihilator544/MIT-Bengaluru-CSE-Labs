%{
#include <stdio.h>
#include <stdlib.h>
%}

%token ID INT FLOAT CHAR DOUBLE

%%

decl: type ID ';' {printf("Valid declaration\n");}
    | type ID '=' expr ';' {printf("Valid declaration\n");}
    | error ';' {printf("Invalid declaration\n"); yyerrok;}
    ;

type: INT | FLOAT | CHAR | DOUBLE
    ;

expr: expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | ID
    | INT
    | FLOAT
    | '\'' CHAR '\''
    | DOUBLE
    ;

%%

int main()
{
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    printf("%s\n", s);
    return 0;
}
