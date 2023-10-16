%{
#include <stdio.h>
int positiveIntCount = 0;
int negativeIntCount = 0;
int positiveFloatCount = 0;
int negativeFloatCount = 0;
%}

%%

[+-]?[0-9]+ {
    /* Match integers (positive or negative) */
    if (atoi(yytext) > 0) {
        positiveIntCount++;
    } else if (atoi(yytext) < 0) {
        negativeIntCount++;
    }
}

[+-]?[0-9]*\.[0-9]+ {
    /* Match floating-point numbers (positive or negative) */
    if (atof(yytext) > 0) {
        positiveFloatCount++;
    } else if (atof(yytext) < 0) {
        negativeFloatCount++;
    }
}

\n {
    /* Newline character encountered, end of input */
    printf("Positive Integers: %d\nNegative Integers: %d\nPositive Floating-Point Numbers: %d\nNegative Floating-Point Numbers: %d\n", positiveIntCount, negativeIntCount, positiveFloatCount, negativeFloatCount);
    return 0;
}

[ \t] {
    /* Ignore spaces and tabs */
}

. {
    /* Ignore other characters */
}

%%
int yywrap() {return 1;}
int main() {
    yylex();
    return 0;
}
