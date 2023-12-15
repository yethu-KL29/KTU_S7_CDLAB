#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int c, i, j;
char a[20], stk[20];

void check();
int main()
{
    printf("enter the expression\n");
    scanf("%s", a);

    c = strlen(a);

    for (i = 0, j = 0; j < c; i++, j++)
    {
        if (a[j] == 'i' && a[j + 1] == 'd')
        {
            stk[i] = a[j];
            stk[i + 1] = a[j + 1];
            stk[i + 2] = '\0';
            a[j] = ' ';
            a[j + 1] = ' ';
            printf("%s\t\t%s\t\t%s\n", stk, a, "shift");
            check();
        }
        else
        {
            stk[i] = a[j];
            stk[i + 1] = '\0';
            a[j] = ' ';
            printf("%s\t\t%s\t\t%s\n", stk, a, "shift");
            check();
        }
    }
}

void check()
{
    for (int z = 0; z < c; z++)
    {
        if (stk[z] == 'i' && stk[z + 1] == 'd')
        {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            j++;
            printf("%s\t\t%s\t\t%s\n", stk, a, "reduce");
        }
    }
    for (int z = 0; z < c; z++)
    {
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E')
        {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            i = i - 2;
            printf("%s\t\t%s\t\t%s\n", stk, a, "reduce");
        }
    }
    for (int z = 0; z < c; z++)
    {
        if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E')
        {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            i = i - 2;
            printf("%s\t\t%s\t\t%s\n", stk, a, "reduce");
        }
    }
    for (int z = 0; z < c; z++)
    {
        if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')')
        {
            stk[z] = 'E';
            stk[z + 1] = '\0';
            i = i - 2;
            printf("%s\t\t%s\t\t%s\n", stk, a, "reduce");
        }
    }
}


