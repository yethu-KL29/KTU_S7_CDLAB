%{
#include "y.tab.h"
%}

%%
[a-zA-Z][a-zA-Z0-9]*     { return letter; }
[0-9]                    { return digit; }
\n                       { return 0; }
%%

int yywrap() {
    return 1;
}
