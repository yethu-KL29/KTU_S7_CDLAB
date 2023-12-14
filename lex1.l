%{
    #include <stdio.h>

%}

%%
[0-9]+ { printf("Integer: %s\n", yytext); }
[a-zA-Z]+ { printf("String: %s\n", yytext); }
. { printf("Special Character: %s\n", yytext); }
%%

int main()
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}


