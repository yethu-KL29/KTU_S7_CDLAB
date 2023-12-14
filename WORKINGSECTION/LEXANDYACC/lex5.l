%{
#include <stdio.h>
int pc = 0, sc = 0;
%}

%%
"printf"    { fprintf(yyout, "writef"); pc++; }
"scanf"     { fprintf(yyout, "readf"); sc++; }
.           { fprintf(yyout, "%s", yytext); }
%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <sourcefile> <destn file>\n", argv[0]);
        exit(0);
    }

    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");

   

    yylex();

    fclose(yyin);
    fclose(yyout);

    printf("No of printf statements = %d\nNo of scanf statements = %d\n", pc, sc);

    return 0;
}
