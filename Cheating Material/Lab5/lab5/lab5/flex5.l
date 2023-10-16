%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

[0-9]+ {
    /* Match decimal numbers */
    int decimal = atoi(yytext);  /* Convert decimal to integer */
    printf("Decimal: %d --> Hexadecimal: 0x%X\n", decimal, decimal); /* Convert and print as hexadecimal */
}

[ \t\n] {
    return 0;
}

. {
    /* Ignore other characters */
}

%%
int yywrap() {return 1;}
int main() {
    printf("Enter decimal numbers (press Ctrl+D to exit):\n");
    yylex();
    return 0;
}
