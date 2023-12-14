#include <stdio.h>
#include <string.h>

int main() {
    char icode[10][30], str[20], opr[10];
    int i = 0;

    printf("\nEnter the set of intermediate code (terminated by exit):\n");

    do {
        scanf("%s", icode[i]);
    } while (strcmp(icode[i++], "exit") != 0);

    printf("\nTarget code generation\n");
    printf("************************\n");

    i = 0;

    do {
        strcpy(str, icode[i]);

        switch (str[3]) {
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

        printf("Mov %c,R%d\n", str[2], i); //mov a,R0
        printf("%s %c,R%d\n", opr, str[4], i);//ADD b,R0
        printf("Mov R%d,%c\n", i, str[0]);//mov R0,a

    } while (strcmp(icode[++i], "exit") != 0);

    return 0;
}
