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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE cimage[height][width];
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int sumrx = 0;
            int sumgx = 0;
            int sumbx = 0;
            int sumry = 0;
            int sumgy = 0;
            int sumby = 0;
            for (int h1 = h - 1; h1 < h + 2; h1++)
            {
                for (int w1 = w - 1; w1 < w + 2; w1++)
                {
                    if (w1 >= 0 && h1 >= 0 && h1 < height && w1 < width)
                    {
                        sumrx = sumrx + image[h1][w1].rgbtRed * Gx[h1 - h + 1][w1 - w + 1];
                        sumgx = sumgx + image[h1][w1].rgbtGreen * Gx[h1 - h + 1][w1 - w + 1];
                        sumbx = sumbx + image[h1][w1].rgbtBlue * Gx[h1 - h + 1][w1 - w + 1];
                        sumry = sumry + image[h1][w1].rgbtRed * Gy[h1 - h + 1][w1 - w + 1];
                        sumgy = sumgy + image[h1][w1].rgbtGreen * Gy[h1 - h + 1][w1 - w + 1];
                        sumby = sumby + image[h1][w1].rgbtBlue * Gy[h1 - h + 1][w1 - w + 1];
                    }
                }
            }
            if (sqrt(sumrx * sumrx + sumry * sumry) < 255)
            {
                cimage[h][w].rgbtRed = round(sqrt(sumrx * sumrx + sumry * sumry));
            }
            else
            {
                cimage[h][w].rgbtRed = 255;
            }
            if (sqrt(sumgx * sumgx + sumgy * sumgy) < 255)
            {
                cimage[h][w].rgbtGreen = round(sqrt(sumgx * sumgx + sumgy * sumgy));
            }
            else
            {
                cimage[h][w].rgbtGreen = 255;
            }
            if (sqrt(sumbx * sumbx + sumby * sumby) < 255)
            {
                cimage[h][w].rgbtBlue = round(sqrt(sumbx * sumbx + sumby * sumby));
            }
            else
            {
                cimage[h][w].rgbtBlue = 255;
            }
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
