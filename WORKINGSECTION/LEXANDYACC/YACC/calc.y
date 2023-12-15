%{
    #include <stdio.h>
%}

%token NUM
%left '+' '-'
%%

S : T  {printf("%d\n",$1);}

T : T '+' T {$$ = $1+$3;}
  | T '-' T {$$ = $1-$3;}
  |NUM     {$$ = $1;}
   ;

%%


int yyerror(){
    printf("error");
}

int main(){
    printf("enter the numbers\n");
    yyparse();
}