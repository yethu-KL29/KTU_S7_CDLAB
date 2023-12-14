%{
  #include<stdio.h> 
   #include<stdlib.h> 
  int valid = 1;
%}

%token A B

%%

start: S { if (valid) printf("Valid\n"); else printf("Invalid\n"); }
S: A S B { /* do nothing */ }
 | ;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    valid = 0;  // Set the flag to indicate an error
}
