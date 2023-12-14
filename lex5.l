%{
    #include <stdio.h>

%}

%%

[a-zA-z]+ {
    for(int i = 0 ; i < yyleng ; i++){
       if (yytext[i] >= 'A' && yytext[i] <= 'Z'){
           yytext[i] = yytext[i] + 32;
       }
    } 
    printf("%s\n", yytext);
}

%%

int main(){
    printf("Enter a string: ");
    yylex();
}


int yywrap(){
    return 1;
}
