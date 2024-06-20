#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int a = 0;
        int len = strlen(argv[1]);
        for (int i = 0; i < len; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                a++;
            }
        }
        if (a > 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            string text = get_string("plaintext: ");
            int k = atoi(argv[1]);
            int tlen = strlen(text);
            printf("ciphertext: ");
            for (int i = 0; i < tlen; i++)
            {
                if (isupper(text[i]))
                {
                    int ci = (text[i] + k - 'A') % 26;
                    printf("%c", 'A' + ci);
                }
                else if (islower(text[i]))
                {
                    int ci = (text[i] + k - 'a') % 26;
                    printf("%c", 'a' + ci);
                }
                else
                {
                    printf("%c", text[i]);
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
