%{
#include <stdio.h>
#include <stdlib.h>
%}

%%

[0-9]+ {
    int decimal = atoi(yytext);
    printf("Decimal: %d --> Hexadecimal: 0x%X\n", decimal, decimal);
}

[ \t\n] {
}

. {
}

%%

int main() {
    printf("Enter decimal numbers (press Ctrl+D to exit):\n");
    yylex();
    return 0;
}
