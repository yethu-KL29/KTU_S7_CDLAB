%{
#include <stdio.h>
int pc = 0, sc = 0;
%}

%%
"printf"    { printf( "writef"); pc++; }
"scanf"     { printf( "readf"); sc++; }
.           { printf( "%s", yytext); } 
%%

int yywrap() {
    return 1;
}

int main() {
    

   

    yylex();

    

    printf("No of printf statements = %d\nNo of scanf statements = %d\n", pc, sc);

    return 0;
}
