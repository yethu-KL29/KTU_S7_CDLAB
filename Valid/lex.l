%{
#include <stdio.h>
#include "y.tab.h"
%}

%%

[aA]+  { return A; }
[bB]+  {return B; }
[ \t\n]   { /* skip whitespace */ }
.         { return yytext[0]; }

%%
int yywrap(void) { return 1; }
