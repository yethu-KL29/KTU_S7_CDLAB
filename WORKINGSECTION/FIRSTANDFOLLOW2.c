#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int n, i, m, z = 0;
char arr[10][10], ch, c, f[10];

void first(char c);
void follow(char c);

int main()
{
    printf("Enter the number of expressions\n");
    scanf("%d", &n);


    printf("Enter the expressions\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s%c", arr[i], &ch);
    }

    do
    {
        printf("Enter the character for first and follow\n");
        scanf("%c", &c); // added a space to consume any leading whitespace

        m = 0;
        first(c);

        printf("First(%c)={", c);
        for (int i = 0; i < m; i++)
            printf("%c", f[i]);
        printf("}\n");

        strcpy(f, " ");

        m = 0;
        follow(c);

        printf("Follow(%c)={", c);
        for (int i = 0; i < m; i++)
            printf("%c", f[i]);
        printf("}\n");

        printf("Continue? (0/1)\n");
        scanf("%d%c", &z, &ch);

    } while (z == 1);

    return 0;
}
void first(char c)
{

      if (islower(c))
        {
            f[m++] = c;
        }

    for (i = 0; i < n; i++)
    {
       
        if (arr[i][0] == c)
        {

            if (islower(arr[i][2]))
            {
                f[m++] = arr[i][2];
            }
            else
            {
                first(arr[i][2]);
            }
        }
    }
}

void follow(char c)
{
    if (arr[0][0] == c)
    {
        f[m++] = '$';
    }

    for (i = 0; i < n; i++)
    {
        for (int j = 2; j < strlen(arr[i]); j++)
        {
            if (arr[i][j] == c)
            {
                if (arr[i][j + 1] != '\0')
                {
                    first(arr[i][j + 1]);
                }
                if (arr[i][j + 1] == '\0' && c != arr[i][0])
                    follow(arr[i][0]);
            }
        }
    }
}