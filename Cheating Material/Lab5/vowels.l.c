%{
#include <stdio.h>
int vowelCount = 0;
int consonantCount = 0;
%}

%%

[AEIOUaeiou] {
    vowelCount++;
}

[A-Za-z] {
    consonantCount++;
}

\n {
    printf("Vowels: %d\nConsonants: %d\n", vowelCount, consonantCount);
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
