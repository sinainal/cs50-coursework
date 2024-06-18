#include <cs50.h>
#include <stdio.h>

void print_row(int bricks);
void print_space(int length);

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (1 > n || n > 8);
    for (int i = 0; i < n; i++)
    {
        print_space(n - i - 1);
        print_row(i + 1);
        printf("\n");
    }
}

void print_row(int bricks)
{
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
}

void print_space(int length)
{
    for (int i = 0; i < length; i++)
    {
        printf(" ");
    }
}
