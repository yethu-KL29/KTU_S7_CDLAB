%{
#include <stdio.h>
int ch=0, w=0, s=0, l =0;

%}

%%
[a-zA-z]+ {w++;ch=ch+yyleng;}
. {}
%%

int main() {
    printf("Enter the sentence:\n");
    yylex();
    printf("words: %d", ch);
    return 0;
}

int yywrap() {
    return 1;
}
