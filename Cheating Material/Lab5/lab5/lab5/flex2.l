%{
#include <stdio.h>
int wordCount = 0;
int charCount = 0;
int blankCount = 0;
int lineCount = 0;
%}

%%
[a-zA-Z]+ {
    /* Increment word count for each word */
    wordCount++;
    charCount += yyleng; /* Update character count */
}

\n {
    /* Newline character encountered, end of line */
    charCount++; /* Include the newline character */
    lineCount++;
}

0 {
	return 0;
}

[ \t] {
    /* Space or tab encountered, increment blank count */
    blankCount++;
    charCount++;
}

. {
    /* Any other character */
    charCount++;
}

%%
int yywrap() {return 1;}
int main() {
    yylex();
    printf("Words: %d\nCharacters: %d\nBlanks: %d\nLines: %d\n", wordCount, charCount, blankCount, lineCount);
    return 0;
}
