%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the tokens for the lexer
#define INT 1
#define FLOAT 2
#define CHAR 3
#define ID 4
#define IF 5
#define ELSE 6
#define NUM 7
#define PLUS 8
#define MINUS 9
#define MUL 10
#define DIV 11
#define POW 12
#define NL 13

// Declare a union to store the token values
%union {
  int ival;
  float fval;
  char cval;
  char *sval;
}

// Declare the token types and their values
%token <ival> INT
%token <fval> FLOAT
%token <cval> CHAR
%token <sval> ID
%token <sval> IF
%token <sval> ELSE
%token <fval> NUM
%token <sval> PLUS
%token <sval> MINUS
%token <sval> MUL
%token <sval> DIV
%token <sval> POW
%token <sval> NL

// Declare the type of the non-terminal symbols
%type <fval> exp
%type <sval> type
%type <sval> var
%type <sval> op

// Declare the precedence and associativity of the operators
%left PLUS MINUS
%left MUL DIV
%right POW

// Declare the start symbol of the grammar
%start input
%%

// Define the grammar rules and the actions

// The input consists of zero or more lines
input: /* empty */
     | input line
     ;

// A line consists of either a newline or an expression followed by a newline
line: NL { printf("Empty line\n"); }
    | exp NL { printf("The value of the expression is: %f\n", $1); }
    | decl NL { printf("The declaration is valid\n"); }
    | cond NL { printf("The condition is valid\n"); }
    ;

// An expression consists of either a number or an operation on two expressions
exp: NUM { $$ = $1; }
   | exp op exp { 
       if ($2[0] == '+') $$ = $1 + $3;
       else if ($2[0] == '-') $$ = $1 - $3;
       else if ($2[0] == '*') $$ = $1 * $3;
       else if ($2[0] == '/') {
         if ($3 == 0) {
           printf("Division by zero error\n");
           exit(1);
         }
         else $$ = $1 / $3;
       }
       else if ($2[0] == '^') $$ = pow($1, $3);
       else {
         printf("Invalid operator: %s\n", $2);
         exit(1);
       }
     }
   ;

// An operator is one of the symbols +, -, *, /, or ^
op: PLUS { $$ = $1; }
  | MINUS { $$ = $1; }
  | MUL { $$ = $1; }
  | DIV { $$ = $1; }
  | POW { $$ = $1; }
  ;

// A declaration consists of a type and a variable
decl: type var { 
       if ($1[0] == 'i') printf("The variable %s is declared as an integer\n", $2);
       else if ($1[0] == 'f') printf("The variable %s is declared as a float\n", $2);
       else if ($1[0] == 'c') printf("The variable %s is declared as a char\n", $2);
       else {
         printf("Invalid type: %s\n", $1);
         exit(1);
       }
     }
    ;

// A type is one of the keywords int, float, or char
type: INT { $$ = $1; }
    | FLOAT { $$ = $1; }
    | CHAR { $$ = $1; }
    ;

// A variable is an identifier
var: ID { $$ = $1; }
   ;

// A condition consists of an if statement with an optional else clause
cond: IF '(' exp ')' '{' exp '}' { 
        printf("The if condition is: %f\n", $3);
        printf("The if body is: %f\n", $6);
      }
    | IF '(' exp ')' '{' exp '}' ELSE '{' exp '}' { 
        printf("The if condition is: %f\n", $3);
        printf("The if body is: %f\n", $6);
        printf("The else body is: %f\n", $10);
      }
    ;
%%

// Define the error handler function
void yyerror(char *msg) {
  printf("Error: %s\n", msg);
  exit(1);
}

// Define the main function
int main() {
  printf("Enter the input\n");
  yyparse();
  return 0;
}
