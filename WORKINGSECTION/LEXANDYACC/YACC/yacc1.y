%{
    #include <stdio.h>
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
start : T  {printf("%d\n", $1);}
      
T     : T '+'T {$$ = $1 + $3;}
      | T '-'T {$$ = $1 - $3;}
      | T '*'T {$$ = $1 * $3;}
      | T '/'T {$$ = $1 / $3;}
      | '('T ')' {$$ = $2;}
      | NUM {$$ = $1;}
      ;
%%

int main()
{
    yyparse();

    return 0;
}

int yyerror()
{
    
    return 0;
}