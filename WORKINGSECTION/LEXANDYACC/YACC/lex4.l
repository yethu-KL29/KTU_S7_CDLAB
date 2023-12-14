%{ 
/* Definition section */
#include "y.tab.h" 
%} 

/* Rule Section */
%% 
[aA] {return A;} 
[bB] {return B;} 
\n   {return yytext[0];}

. {return yytext[0];} 
%% 

int yywrap() 
{ 
return 1; 
} 
