#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main()
{
    FILE *f1;
    char c, str[10];
    int lineno = 0, num = 0, i = 0;

    f1 = fopen("input.txt", "r");

    while ((c = getc(f1)) != EOF)
    {
        if (isdigit(c))
        {
            num = c - '0';
            c = getc(f1);
            while (isdigit(c))
            {
                num = num * 10 + (c - '0');
                c = getc(f1);
            }
            printf("%d is a number\n", num);
            ungetc(c, f1);
        }
        else if (isalpha(c))
        {
            str[i++] = c;
            c = getc(f1);
            while (isdigit(c) || isalpha(c) || c == '_')
            {
                str[i++] = c;
                c = getc(f1);
            }
            str[i] = '\0';
            i = 0;
            ungetc(c, f1);
            if (strcmp(str, "int") == 0 || strcmp(str, "char") == 0 || strcmp(str, "float") == 0 || strcmp(str, "double") == 0 || strcmp(str, "long") == 0 || strcmp(str, "short") == 0 || strcmp(str, "signed") == 0 || strcmp(str, "unsigned") == 0 || strcmp(str, "void") == 0 || strcmp(str, "if") == 0 || strcmp(str, "else") == 0 || strcmp(str, "for") == 0 || strcmp(str, "while") == 0 || strcmp(str, "do") == 0 || strcmp(str, "break") == 0 || strcmp(str, "continue") == 0 || strcmp(str, "goto") == 0 || strcmp(str, "switch") == 0 || strcmp(str, "case") == 0 || strcmp(str, "default") == 0 || strcmp(str, "return") == 0)
            {
                printf("%s is a keyword\n", str);
            }
            else
            {
                printf("%s is an identifier\n", str);
            }
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
            printf("%c is a special symbol\n", c);
        }
    }
    printf("Total number of lines are %d\n", lineno + 1);
    fclose(f1);
}