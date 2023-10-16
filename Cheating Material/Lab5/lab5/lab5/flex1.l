%{
#include <stdio.h>
int vowelCount = 0;
int consonantCount = 0;
%}

%%

[AEIOUaeiou] {
    /* Increment vowel count for any vowel (case-insensitive) */
    vowelCount++;
}

[A-Za-z] {
    /* Increment consonant count for any letter (case-insensitive) */
    consonantCount++;
}

\n {
    /* Newline character encountered, end of input */
    printf("Vowels: %d\nConsonants: %d\n", vowelCount, consonantCount);
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
