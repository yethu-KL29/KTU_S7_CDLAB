%{
#include <stdio.h>
int cnt1 = 0, cnt2 = 0, cnt3 = 0;
%}

%%
[(] { cnt1++; }
[)] { cnt1--; }
[{] { cnt2++; }
[}] { cnt2--; }
[[] { cnt3++; }
[]] { cnt3--; }
[a-zA-Z] {}
.   {}

\n {
    if ((cnt1 == 0) && (cnt2 == 0) && (cnt3 == 0)) {
        printf("Matching\n");
    } else {
        printf("Not Matching\n");
    }
    cnt1 = 0;
    cnt2 = 0;
    cnt3 = 0;
}
%%

int main() {
    printf("Enter the characters: \n");
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
