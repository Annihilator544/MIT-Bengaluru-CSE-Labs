%{#include <stdio.h>
#include <ctype.h>
int inComment = 0;
%}
%%
"/*" {
    /* Start of a comment */
    inComment = 1;
}

"*/" {
    /* End of a comment */
    inComment = 0;
}

[ \t]+ {
    /* Copy whitespace as is */
    if (!inComment) {
        printf("%s", yytext);
    }
}

\n {
    /* Copy newlines as is */
    if (!inComment) {
        printf("\n");
    }
}

[A-Z] {
    /* Convert uppercase to lowercase */
    if (!inComment) {
        printf("%c", tolower(yytext[0]));
    }
}

. {
    /* Copy other characters as is */
    if (!inComment) {
        printf("%s", yytext);
    }
}

%%
int yywrap() {return 1;}
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    yyin = inputFile;
    yylex();

    fclose(inputFile);

    return 0;
}
