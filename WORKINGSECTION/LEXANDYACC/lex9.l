%{
#include <stdio.h>
int line = 0, w = 0, c = 0;
%}

%%
[a-zA-Z0-9]+ { w++; c+=yyleng;}
[ \t]        { }
\n           { line++; }
.            { c++; }

%%

int yywrap() {
   
    return 1; // Returning 1 to indicate there is no more input
}

int main() {
    printf("Enter the sentence:\n");
    yylex();
    printf("Words: %d, Lines: %d, Characters: %d\n", w, line, c);
    return 0;
}
