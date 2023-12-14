%{
   #include <stdio.h>

%}

%%
[a-zA-Z]+ { for(int i = 0 ; i < yyleng ; i++){
       if (yytext[i] >= 'A' && yytext[i] <= 'Z'){
           yytext[i] = yytext[i] + 32;
       }
    } 
           }
\n    { printf("%s",yytext); }


%%

int main(int argc, char **argv)
{
    yylex();
}
int yywrap()
{
    return 1;
}
