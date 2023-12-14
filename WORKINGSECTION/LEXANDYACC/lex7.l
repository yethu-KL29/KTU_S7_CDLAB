%{
#include <stdio.h>
int flag=0;
%}

%%
[a-zA-Z0-9]+[ ]+[a][n][d][ ]+[a-zA-Z0-9]+  {flag=1; }

%%

int yywrap(){
    return 1;
}

int main(){
    yylex();
    if(flag==0){
        printf("simple");
    }
    else{
        printf("comp");
    }

}