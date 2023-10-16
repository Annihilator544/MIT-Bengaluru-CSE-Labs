%{
#include <stdio.h>
int positiveIntCount = 0;
int negativeIntCount = 0;
int positiveFloatCount = 0;
int negativeFloatCount = 0;
%}

%%

[+-]?[0-9]+ {
    if (atoi(yytext) > 0) {
        positiveIntCount++;
    } else if (atoi(yytext) < 0) {
        negativeIntCount++;
    }
}

[+-]?[0-9]*\.[0-9]+ {
    if (atof(yytext) > 0) {
        positiveFloatCount++;
    } else if (atof(yytext) < 0) {
        negativeFloatCount++;
    }
}

\n {
    printf("Positive Integers: %d\nNegative Integers: %d\nPositive Floating-Point Numbers: %d\nNegative Floating-Point Numbers: %d\n", positiveIntCount, negativeIntCount, positiveFloatCount, negativeFloatCount);
    return 0;
}

[ \t] {
}

. {
}

%%

int main() {
    yylex();
    return 0;
}
