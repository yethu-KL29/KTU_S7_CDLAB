%{
#include <stdio.h>
%}

%token NUM
%left '+' '-'
%left '*' '/''%'

%%
S : E {printf("%d\n",$1);}
E : E '+' E {$$=$1+$3;}
  | E '-' E {$$=$1-$3;}
  | E '*' E {$$=$1*$3;}
  | E '/' E {$$=$1/$3;}
  | E '%' E {$$=$1%$3;}
  | '(' E ')' {$$=$2;}
  | NUM {$$=$1;}
  ;
%%

int main()
{
  yyparse();
  return 0;
}

int yyerror(char *s)
{
  printf("%s\n",s);
  return 0;
}
