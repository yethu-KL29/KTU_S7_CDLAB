#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char state[10], result[10][10], states[10][10], copy[10], state1[10], input[10], state2[10];

void add_state(char c[10], int i)
{
    strcpy(result[i], c);
}
void display(int i)
{
    int k = 0;
    printf("\n\n\n Epsilon closure of %s = { ", copy);
    while (k < i)
    {
        printf("%s", result[k]);
        k++;
    }
    printf(" } \n\n\n");
}

int main()
{

    FILE *file;
    file = fopen("input.dat", "r");

    int n;
    printf("Enter the number of states: ");
    scanf("%d", &n);

    printf("\nEnter the states\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", states[i]);
    }

    for (int i = 0; i < n; i++)
    {

        int k = 0;
        strcpy(state, states[i]);
        strcpy(copy, state);
        add_state(state, k++);

        while (1)
        {
            int end = fscanf(file, "%s%s%s", state1, input, state2);
            if (end == EOF)
            {
                break;
            }
            if (strcmp(state, state1) == 0)
            {
                if (strcmp(input, "e") == 0)
                {
                    add_state(state2, k++);
                    strcpy(state, state2);
                }
            }
        }
        display(k);
        rewind(file);
    }
    fclose(file);
    return 0;
}
