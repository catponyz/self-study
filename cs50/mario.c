#include <cs50.h>
#include <stdio.h>

void rows(int n, int all);

int main(void)
{
    int numberOfRows;

    do
    {
        numberOfRows = get_int("How many rows in Pyramid? ");
    }
    while (numberOfRows < 1);

    for (int i = 1; i <= numberOfRows; i++)
    {
        rows(i, numberOfRows);
    }
}

void rows(int n, int all)
{
    int space = all - n;
    for (int j = 1; j <= space; j++)
    {
        printf(" ");
    }

    for (int j = 1; j <= n; j++)
    {
        printf("#");
    }

    printf("  ");

    for (int j = 1; j <= n; j++)
    {
        printf("#");
    }

    printf("\n");
}
