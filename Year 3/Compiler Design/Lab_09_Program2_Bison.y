%{
#include <stdio.h>
#include <stdlib.h>
%}

%token ID INT FLOAT CHAR DOUBLE IF ELSE THEN

%%

stmt: decl ';'
    | assign ';'
    | if_stmt ';'
    | error ';' {printf("Invalid statement\n"); yyerrok;}
    ;


decl: type ID ';' {printf("Valid declaration\n");}
    | type ID '=' expr ';' {printf("Valid declaration\n");}
    ;

assign: ID '=' expr ';' {printf("Valid assignment\n");}
    ;

if_stmt: IF expr THEN stmt {printf("Valid if statement\n");}
       | IF expr THEN stmt ELSE stmt {printf("Valid if-else statement\n");}
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
