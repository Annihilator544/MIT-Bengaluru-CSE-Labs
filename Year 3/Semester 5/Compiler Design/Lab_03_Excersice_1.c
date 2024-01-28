/*Write functions to identify the following tokens.
 a. Arithmetic, relational and logical operators.
 b. Special symbols, keywords, numerical constants, string literals and identifiers*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
FILE *in, *out;
char fchar, tword[16];
char keywords[32][16] = {"auto", "break", "case", "char", "const",
 "continue", "default", "do", "double", "else", "enum", "extern", 
 "float", "for", "goto", "if", "int", "long", "register", "return", 
 "short", "signed", "sizeof", "static", "struct", "switch", "typedef", 
 "union", "unsigned", "void" , "volatile" , "while"
};
int i = 0;
void main() {
    in=fopen("Lab_02_Exercise_3.c", "r");
    if(in==NULL){
        printf("Cannot open file \n");
        exit(0);
    }
    while((fchar=getc(in))!=EOF){
        if(isalpha(fchar)){
            tword[i++]=fchar;
            while((fchar=getc(in))!=EOF){
                if(isalnum(fchar)){
                    tword[i++]=fchar;
                }
                else{
                    tword[i]='\0';
                    i=0;
                    for(int j=0;j<32;j++){
                        if(strcmp(tword,keywords[j])==0){
                            printf("%s is a keyword\n",tword);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        else if(isdigit(fchar)){
            tword[i++]=fchar;
            while((fchar=getc(in))!=EOF){
                if(isdigit(fchar)){
                    tword[i++]=fchar;
                }
                else{
                    tword[i]='\0';
                    i=0;
                    printf("%s is a number\n",tword);
                    break;
                }
            }
        }
        else if(fchar=='"'){
            tword[i++]=fchar;
            while((fchar=getc(in))!=EOF){
                if(fchar!='"'){
                    tword[i++]=fchar;
                }
                else{
                    tword[i++]=fchar;
                    tword[i]='\0';
                    i=0;
                    printf("%s is a string literal\n",tword);
                    break;
                }
            }
        }
        else if(fchar=='+'||fchar=='-'||fchar=='*'||fchar=='/'||fchar=='%'){
            tword[i++]=fchar;
            while((fchar=getc(in))!=EOF){
                if(fchar=='+'||fchar=='-'||fchar=='*'||fchar=='/'||fchar=='%'){
                    tword[i++]=fchar;
                }
                else{
                    tword[i]='\0';
                    i=0;
                    printf("%s is an arithmetic operator\n",tword);
                    break;
                }
            }
        }
        else if(fchar=='<'||fchar=='>'||fchar=='!'||fchar=='='||fchar=='&'||fchar=='|'){
            tword[i++]=fchar;
            while((fchar=getc(in))!=EOF){
                if(fchar=='<'||fchar=='>'||fchar=='!'||fchar=='='||fchar=='&'||fchar=='|'){
                    tword[i++]=fchar;
                }
                else{
                    tword[i]='\0';
                    i=0;
                    printf("%s is a relational operator\n",tword);
                    break;
                }
            }
        }
        else if(fchar=='&'||fchar=='|'||fchar=='!'){
            tword[i++]=fchar;
            while((fchar=getc(in))!=EOF){
                if(fchar=='&'||fchar=='|'||fchar=='!'){
                    tword[i++]=fchar;
                }
                else{
                    tword[i]='\0';
                    i=0;
                    printf("%s is a logical operator\n",tword);
                    break;
                }
            }
        }
        else if(fchar=='('||fchar==')'||fchar=='{'||fchar=='}'||fchar=='['||fchar==']'||fchar==';'||fchar==','||fchar=='.'){
            tword[i++]=fchar;
            tword[i]='\0';
            i=0;
            printf("%s is a special symbol\n",tword);
        }
    }
    fclose(in);
}
