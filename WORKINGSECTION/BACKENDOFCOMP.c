#include <stdio.h>
#include <string.h>

char inp[10][10], stk[10], opr[10];

int main() {
    printf("Enter the intermediate code (terminate with 'e'):\n");
    
    int i = 0;
    do {
        scanf("%s", inp[i]);
    } while (inp[i++][0] != 'e');

    i = 0;
    while (inp[i][0] != 'e') {
        strcpy(stk, inp[i]);

        switch (stk[3]) {
            case '+':
                strcpy(opr, "ADD");
                break;
            case '-':
                strcpy(opr, "SUB");
             
   break;
            case '*':
                strcpy(opr, "MUL");
                break;
            case '/':
                strcpy(opr, "DIV");
                break;
        }

        printf("move %c, R%d\n", stk[2], i);
        printf("%s %c, R%d\n", opr, stk[4], i);
        printf("move R%d, %c\n", i, stk[0]);

        i++;
    }

    return 0;
}
