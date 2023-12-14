%{
#include <stdio.h>
int con = 0, vow = 0;
%}

%%
[aeiouAEIOU] { vow++; }
[^aeiouAEIOU\n] { con++; }
. {}
%%

int main() {
    printf("Enter the sentence:\n");
    yylex();
    printf("Vowels: %d, Consonants: %d\n", vow, con);
    return 0;
}

int yywrap() {
    return 1;
}
