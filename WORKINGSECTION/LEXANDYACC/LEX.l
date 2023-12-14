%{
#include <stdio.h>

%}
identifier [a-zA-Z][a-zA-Z0-9]* 
%%
#.* { printf("\n%s is a preprocessor directive\n", yytext); }
int |
float  {printf("% s is a keyword\n",yytext);}
{identifier} {printf("%s is identifier",yytext);}
[+-] {printf("%s is operator",yytext);}
\".*\" { printf("%s is a string\n", yytext); }

[0-9]+ { printf("%s is a number\n", yytext); }
. {printf("%s is special charecter\n",yytext);}

%%

int main() {
    FILE *fp;
    yyin = fopen("input.c","r");
    yylex();  // Call the Lexical Analyzer
    return 0;
}

int yywrap() {
    return 1;
}
