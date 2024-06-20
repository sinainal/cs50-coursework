#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("error");
        return 1;
    }
    int len = strlen(argv[1]);
    if (argc == 2 && len == 26)
    {
        int a = 0;
        for (int i = 0; i < len; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                a++;
            }
            for (int i1 = i + 1; i1 < len; i1++)
            {
                if (toupper(argv[1][i]) == toupper(argv[1][i1]))
                {
                    a++;
                }
            }
        }
        if (a > 0)
        {
            printf("error");
            return 1;
        }
        else
        {
            string text = get_string("plaintext: ");
            printf("ciphertext: ");
            int tlen = strlen(text);
            for (int i = 0; i < tlen; i++)
            {
                if (isupper(text[i]))
                {
                    int ni = text[i] - 'A';
                    char c = toupper(argv[1][ni]);
                    printf("%c", c);
                }
                else if (islower(text[i]))
                {
                    int ni = text[i] - 'a';
                    char c = tolower(argv[1][ni]);
                    printf("%c", c);
                }
                else
                {
                    char c = text[i];
                    printf("%c", c);
                }
            }
            printf("\n");
        }
    }
    else
    {
        printf("error");
        return 1;
    }
}
