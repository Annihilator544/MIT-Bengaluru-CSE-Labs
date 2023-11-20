%{
#include "y.tab.h"
%}

%%

[0-9]+ {return INT;}
[0-9]+\.[0-9]+ {return FLOAT;}
\'[^\']*\' {return CHAR;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}
"int" {return INT;}
"float" {return FLOAT;}
"char" {return CHAR;}
"double" {return DOUBLE;}
"+"|"-"|"*"|"/"|"="|"("|")" {return yytext[0];}
";" {return ';';}
[ \t\n] {}
. {printf("Invalid character: %c\n", yytext[0]);}
%%

int yywrap()
{
    return 1;
}
