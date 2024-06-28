#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int r = image[h][w].rgbtRed;
            int g = image[h][w].rgbtGreen;
            int b = image[h][w].rgbtBlue;
            float sum = (r + g + b) / 3.0;
            int s = round(sum);
            image[h][w].rgbtRed = s;
            image[h][w].rgbtGreen = s;
            image[h][w].rgbtBlue = s;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int r = image[h][w].rgbtRed;
            int g = image[h][w].rgbtGreen;
            int b = image[h][w].rgbtBlue;
            if (round(0.393 * r + 0.769 * g + 0.189 * b) > 255)
            {
                image[h][w].rgbtRed = 255;
            }
            else
            {
                image[h][w].rgbtRed = round(0.393 * r + 0.769 * g + 0.189 * b);
            }
            if (round(0.349 * r + 0.686 * g + 0.168 * b) > 255)
            {
                image[h][w].rgbtGreen = 255;
            }
            else
            {
                image[h][w].rgbtGreen = round(0.349 * r + 0.686 * g + 0.168 * b);
            }
            if (round(0.272 * r + 0.534 * g + 0.131 * b) > 255)
            {
                image[h][w].rgbtBlue = 255;
            }
            else
            {
                image[h][w].rgbtBlue = round(0.272 * r + 0.534 * g + 0.131 * b);
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            RGBTRIPLE clone = image[h][w];
            image[h][w] = image[h][width - w - 1];
            image[h][width - w - 1] = clone;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE cimage[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int sumr = 0;
            int sumg = 0;
            int sumb = 0;
            float n = 0;
            for (int h1 = h - 1; h1 < h + 2; h1++)
            {
                for (int w1 = w - 1; w1 < w + 2; w1++)
                {
                    if (w1 >= 0 && h1 >= 0 && h1 < height && w1 < width)
                    {
                        sumr = sumr + image[h1][w1].rgbtRed;
                        sumg = sumg + image[h1][w1].rgbtGreen;
                        sumb = sumb + image[h1][w1].rgbtBlue;
                        n++;
                    }
                }
            }
            cimage[h][w].rgbtRed = round(sumr / n);
            cimage[h][w].rgbtGreen = round(sumg / n);
            cimage[h][w].rgbtBlue = round(sumb / n);
        }
    }
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtRed = cimage[h][w].rgbtRed;
            image[h][w].rgbtGreen = cimage[h][w].rgbtGreen;
            image[h][w].rgbtBlue = cimage[h][w].rgbtBlue;
        }
    }
    return;
}
