%{
#include<stdio.h>
#include<stdlib.h>

int valid = 1; // Assume initially valid

void yyerror(const char *msg)
{
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}
%}

%token LET NUM

%%
stmt : S { if (valid) printf("valid\n"); }
    ;
S : LET 
  | S LET
  | S NUM
  ;

%%

int main()
{
    printf("Enter a statement: ");
    yyparse();
    return 0;
}
