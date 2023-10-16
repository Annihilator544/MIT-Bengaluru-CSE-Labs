%{
#include <stdio.h>
int wordCount = 0;
int charCount = 0;
int blankCount = 0;
int lineCount = 0;
%}

%%
[a-zA-Z]+ {
    wordCount++;
    charCount += yyleng;
}

\n {
    charCount++;
    lineCount++;
}

[ \t] {
    blankCount++;
    charCount++;
}

. {
    charCount++;
}

%%

int main() {
    yylex();
    printf("Words: %d\nCharacters: %d\nBlanks: %d\nLines: %d\n", wordCount, charCount, blankCount, lineCount);
    return 0;
}
