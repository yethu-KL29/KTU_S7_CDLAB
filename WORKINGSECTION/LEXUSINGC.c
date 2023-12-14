#include <stdio.h>
#include <string.h>
#include <ctype.h>

char c, str[20];
int num=0, i = 0, lineno = 0;
int main()
{
    FILE *f;

    f = fopen("input.txt", "r");

    while ((c = getc(f)) != EOF)
    {

        if (isdigit(c))
        {
            num = num - '0';
            c = getc(f);
            while (isdigit(c))
            {
                num = num * 10 + (c - '0');
                c = getc(f);
            }
            printf("\n%d is a number\t\n", num);
            num=0;
            ungetc(c, f);
        }
        else if (isalpha(c))
        {
            str[i++] = c;
            c = getc(f);
            while (isdigit(c) || isalpha(c) || c == '_')
            {
                str[i++] = c;
                c = getc(f);
            }
            str[i++] = '\0';
            i=0;
            if (strcmp(str, "int") == 0 || strcmp(str, "float") == 0, strcmp(str, "char") == 0)
            {
                printf("%s is a Keyword\t\n", str);
            }
            else
            {
                printf("%s is a identifier\t\n", str);
            }
            ungetc(c, f);
        }
        else if (c == ' ' || c == '\t')
        {
            continue;
        }
        else if (c == '\n')
        {
            lineno++;
        }

        else
        {
            printf("%c is a special charecter\n", c);
            c = getc(f);
        }
    }
}