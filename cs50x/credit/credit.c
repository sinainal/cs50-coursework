#include <cs50.h>
#include <stdio.h>

int get_digit(int digit, long number);

int main(void)
{
    long number;
    int n;
    int length = 0;
    number = get_long("Number: ");
    long b = number;
    do
    {
        b = b / 10;
        length++;
    }
    while (b != 0);
    int sum = 0;
    int z = 1;
    for (int i = 1; i <= length; i += 1)
    {
        if (z % 2 == 0)
        {
            if (get_digit(i, number) * 2 >= 10)
            {
                sum = sum + (get_digit(i, number) * 2) / 10 + (get_digit(i, number) * 2) % 10;
            }
            else
            {
                sum = sum + get_digit(i, number) * 2;
            }
        }
        else
        {
            sum = sum + get_digit(i, number);
        }
        z++;
    }

    if ((get_digit(1, sum) != 0) || length < 13 || length > 16)
    {
        printf("INVALID\n");
    }
    else if (length == 15 && get_digit(length, number) == 3 &&
             ((get_digit(length - 1, number) == 4) || (get_digit(length - 1, number) == 7)))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && get_digit(length, number) == 5 &&
             ((get_digit(length - 1, number) == 1) || (get_digit(length - 1, number) == 2) ||
              (get_digit(length - 1, number) == 3) || (get_digit(length - 1, number) == 4) ||
              (get_digit(length - 1, number) == 5)))
    {
        printf("MASTERCARD\n");
    }
    else if (((length == 13) || (length == 16)) && get_digit(length, number) == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_digit(int digit, long number)
{
    long a;
    number = number * 10;
    do
    {
        number = number / 10;
        a = number % 10;
        digit--;
    }
    while (digit != 0);
    return a;
}
