#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// List of C keywords
const char *c_keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register",
    "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
    "union", "unsigned", "void", "volatile", "while"
};

#define NUM_KEYWORDS (sizeof(c_keywords) / sizeof(c_keywords[0]))

void print_upper(char *str) {
    printf("here");
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
    printf("%s ", str);
}


int main( )
{
    FILE *fp;
    int i;
    char filename[100];
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    char word[50];
    while (fscanf(fp, "%49s", word) == 1) {
        int is_keyword = 0;
        for(i=0; i<NUM_KEYWORDS; i++){
            if(!strcmp(word, c_keywords[i])){
                print_upper(word);
                is_keyword = 1;
            }
        }
        if(!is_keyword)
            printf("%s\n", word);
    }

    fclose(fp);
    return 0;
}
