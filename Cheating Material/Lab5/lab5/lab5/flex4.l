%{
#include <stdio.h>
int scanfCount = 0;
int printfCount = 0;
FILE* output;

void replaceAndCount(const char* text) {
    const char* ptr = text;
    while (*ptr != '\0') {
        if (strncmp(ptr, "scanf", 5) == 0) {
            fputs("READ", output);
            scanfCount++;
            ptr += 5;
        } else if (strncmp(ptr, "printf", 6) == 0) {
            fputs("WRITE", output);
            printfCount++;
            ptr += 6;
        } else {
            fputc(*ptr, output);
            ptr++;
        }
    }
}
%}

%%

[ \t] {
    /* Copy spaces and tabs as is */
    fputs(yytext, output);
}

\n {
    /* Copy newlines as is */
    fputs(yytext, output);
}

\"[^\"]*\" {
    /* String literals, copy as is */
    fputs(yytext, output);
}

scanf {
    /* Match scanf and replace it */
    replaceAndCount(yytext);
}

printf {
    /* Match printf and replace it */
    replaceAndCount(yytext);
}

. {
    /* Default rule, continue copying characters */
    fputc(yytext[0], output);
}

%%
int yywrap() {return 1;}
int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    output = fopen(argv[2], "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    yyin = input;

    while (yylex() != 0);

    fprintf(output, "\n\n");
    fprintf(output, "/* Total scanf occurrences replaced: %d */\n", scanfCount);
    fprintf(output, "/* Total printf occurrences replaced: %d */\n", printfCount);

    fclose(input);
    fclose(output);

    return 0;
}
