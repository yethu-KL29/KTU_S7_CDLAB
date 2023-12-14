%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include <string.h>
#include <ctype.h>
%}

%%
[a-zA-Z]+   { yylval.str = strdup(yytext); return A; }
\n { return '\n'; }
. { return yytext[0]; }
%%

int yywrap() {
   return 1;
}
