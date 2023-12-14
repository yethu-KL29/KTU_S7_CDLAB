#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

struct exp
{
    int pos;
    char op;
};

int i = 1, j = 0, no = 0, tmpch = 90;
char str[100], left[15], right[15];
struct exp k[15];

void findopr();
void explore();
void fleft(int);
void fright(int);

int main()
{
    printf("\t\tINTERMEDIATE CODE GENERATION\n\n");
    printf("Enter the Expression : ");
    scanf("%s", str);
    printf("The intermediate code:\n");
    findopr();
    explore();

    return 0;
}

void findopr()
{
    char operators[] = {':', '/', '*', '+', '-'};

    for (int op = 0; op < sizeof(operators) / sizeof(operators[0]); op++)
    {
        for (i = 0; str[i] != '\0'; i++)
        {
            if (str[i] == operators[op])
            {
                k[j].pos = i;
                k[j++].op = operators[op];
            }
        }
    }
}

void explore()
{
    i = 1;
    fleft(0);  // Handle the leftmost variable
    while (k[i].op != '\0')
    {
        fright(k[i - 1].pos);  // Use the position of the previous operator
        str[k[i - 1].pos] = tmpch--;

        printf("\t%c := %s%c%s\t\t", str[k[i - 1].pos], left, k[i - 1].op, right);
        printf("\n");

        i++;
        fleft(k[i - 1].pos);  // Use the position of the current operator
    }

    // Handle the last part of the expression
    fright(k[i - 1].pos);  // Use the position of the last operator
    printf("\t%s := %s%c%s", left, left, k[i - 1].op, right);
    getchar();
}


void fleft(int x)
{
    int w = 0, flag = 0;
    x--;

    while (x != -1 && strchr("+-*/:=(", str[x]) == NULL && str[x] != '\0')
    {
        if (str[x] != '$' && flag == 0)
        {
            left[w++] = str[x];
            left[w] = '\0';
            str[x] = '$';
            flag = 1;
        }

        x--;
    }
}

void fright(int x)
{
    int w = 0, flag = 0;
    x++;

    while (x != -1 && strchr("+-*/:=)", str[x]) == NULL && str[x] != '\0')
    {
        if (str[x] != '$' && flag == 0)
        {
            right[w++] = str[x];
            right[w] = '\0';
            str[x] = '$';
            flag = 1;
        }

        x++;
    }

    if (str[x] == '=' && str[x - 1] != ':')
    {
        right[w++] = str[x];
        right[w] = '\0';
    }
}
