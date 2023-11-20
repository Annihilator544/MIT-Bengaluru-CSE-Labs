%{
#include <stdio.h>
#include <stdlib.h>
%}

%%
[0-9]+ {printf("The hexadecimal notation of %s is %X\n", yytext, atoi(yytext));}
. {ECHO;}
%%
int yywrap(){} 
int main()
{
    printf("Enter a decimal number: ");
    yylex();
    return 0;
}
