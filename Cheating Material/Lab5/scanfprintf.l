%{
#include <stdio.h>
int scanfCount = 0;
int printfCount = 0;
%}

%%

"scanf" {
    printf("READ");
    scanfCount++;
}

"printf" {
    printf("WRITE");
    printfCount++;
}

. {
    putchar(yytext[0]);
}

%%

int main() {
    yylex();
    fprintf(stderr, "Number of scanf: %d\nNumber of printf: %d\n", scanfCount, printfCount);
    return 0;
}
