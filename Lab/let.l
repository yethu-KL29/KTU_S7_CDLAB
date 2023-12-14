%{
#include <stdio.h>
#include "y.tab.h"
%}

%%
[a-zA-Z]+ { yylval = atoi(yytext); 
         return NUM;
      }
[ \t] ;
. return yytext[0];
%%

int yywrap(void) {
   return 1;
}