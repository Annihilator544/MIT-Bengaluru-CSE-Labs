%{
#include <stdio.h>
int scanf_count = 0;
int printf_count = 0;
%}

%%
"scanf" {scanf_count++; printf("READ");}
"printf" {printf_count++; printf("WRITE");}
. {ECHO;}
%%
int yywrap(){} 
int main()
{
    yyin = fopen("input.txt", "r");
    yylex();
    fclose(yyin);
    printf("\nNumber of scanf: %d\n", scanf_count);
    printf("Number of printf: %d\n", printf_count);
    return 0;
}
