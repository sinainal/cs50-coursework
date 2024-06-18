#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a;
    do
    {
        a = get_int("Change owed: /n");
    }
    while (a <= 0);
    int q = a / 25;
    int qr = a % 25;
    int d = qr / 10;
    int dr = qr % 10;
    int n = dr / 5;
    int p = dr % 5;
    printf("%i", q + d + n + p);
}
