#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    float s = 0;
    float w = 0;
    float l = 0;

    string text = get_string("Text: ");
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            w += 1;
        }
        else if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            s += 1;
        }
        else
        {
            l += 1;
            if (!(isupper(text[i]) || islower(text[i])))
            {
                l--;
            }
        }
    }
    float L = (l) / (w + 1) * 100;
    float S = s / (w + 1) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int rindex = round(index);

    if (rindex <= 0)
    {
        printf("Before Grade 1\n");
    }
    else if (rindex > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", rindex);
    }
}
