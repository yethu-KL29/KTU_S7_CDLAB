%{
   #include <stdio.h>
   int num_lines = 0;
    int num_chars = 0;
    int num_words = 0;
%}

%%
[a-zA-z]*[0-9]* { num_chars += strlen(yytext); num_words++; }
\n { num_lines++; }
%%

int main(int argc, char **argv)
{
    yylex();
    printf("%d %d %d\n", num_lines, num_words, num_chars);
}

int yywrap()
{
    return 1;
}
