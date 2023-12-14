%{
#include <stdio.h>
int id = 0;
%}

%%
[a-zA-Z][a-zA-Z0-9_]* { id++; }
\n  { }
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    printf("Number of Identifiers: %d\n", id); 
    return 0;
}
