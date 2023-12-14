#include <stdio.h>
#include <ctype.h>
#include <string.h>

char arr[10][20], stk[10], opr[10];

int main()
{
    printf("enter the expression\n");
    int i = 0;
    do
    {
        scanf("%s", arr[i]);
    } while (strcmp(arr[i++], "exit") != 0);

    int k = 0;
    while (strcmp(arr[k], "exit") != 0)
    {
        strcpy(stk, arr[k]);
        switch (stk[3])
        {
        case '+':
            strcpy(opr, "ADD");
            break;
        case '-':
            strcpy(opr, "SUB");
            break;
        case '*':
            strcpy(opr, "MUL");
            break;
        }
        printf("MOV %c , R%d\n", stk[2],k);
        printf("%s  %c , R%d\n", opr, stk[4],k);
        printf("MOV , R%d,%c ",k,stk[0]);
        k++;
    }
    
}