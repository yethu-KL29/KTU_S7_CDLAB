%{
#include <stdio.h>
int i = 0;
%}

%token A B
%left A B

%%
S: pal '\n' { i = 1; }
pal:
   | A pal A { printf("my3\n"); i = 1; }
   | B pal B { printf("my4\n"); i = 1; }       
   | A { printf("my1\n"); i = 1; }
   | B { printf("my2\n"); i = 1; }         
   ;
%%

int main()
{
   yyparse();
   if (i == 0)
       printf("my5\n");
   return 0;
}

int yyerror()
{
   printf("error\n");
   return 0;    }
