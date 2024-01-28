%{
#include <stdio.h>
#include <ctype.h>
%}

%option yylineno

%s COMMENT

%%
"/*" {BEGIN COMMENT;}
<COMMENT>"*/" {BEGIN INITIAL;}
<COMMENT>.|\n {}
[A-Z] {printf("%c", tolower(yytext[0]));}
. {ECHO;}
%%
int yywrap(){} 
int main()
{
    yyin = fopen("input.txt", "r");
    yylex();
    fclose(yyin);
    return 0;
}
