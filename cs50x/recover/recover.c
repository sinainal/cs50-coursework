#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n = 0;
    char filename[8];
    FILE *file;
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    unsigned char BUFFER[512];
    FILE *f = fopen(argv[1], "r");
    while (fread(BUFFER, 1, sizeof(BUFFER), f) == 512)
    {
        if ((BUFFER[0] == 0xff) && (BUFFER[1] == 0xd8) && (BUFFER[2] == 0xff) &&
            ((BUFFER[3] & 0xf0) == 0xe0))
        {
            if (n == 0)
            {
                sprintf(filename, "%03i.jpg", n);
                n++;
                file = fopen(filename, "w");
                fwrite(BUFFER, 1, sizeof(BUFFER), file);
            }
            else
            {
                fclose(file);
                sprintf(filename, "%03i.jpg", n);
                n++;
                file = fopen(filename, "w");
                fwrite(BUFFER, 1, sizeof(BUFFER), file);
            }
        }
        else
        {
            if (n > 0)
            {
                fwrite(BUFFER, 1, sizeof(BUFFER), file);
            }
        }
    }
    fclose(file);
    fclose(f);
}
