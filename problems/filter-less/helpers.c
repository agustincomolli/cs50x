#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Prototipo de funciones
int limit_to_255(int sepia_result);
void swap_pixels(RGBTRIPLE *left, RGBTRIPLE *right);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Take average of red, green, and blue
            int average = image[row][col].rgbtBlue;
            average += image[row][col].rgbtGreen;
            average += image[row][col].rgbtRed;
            average = (int) round(average / 3.0);

            // Update pixel values
            image[row][col].rgbtBlue = average;
            image[row][col].rgbtGreen = average;
            image[row][col].rgbtRed = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Compute sepia values
            int original_red = image[row][col].rgbtRed;
            int original_green = image[row][col].rgbtGreen;
            int original_blue = image[row][col].rgbtBlue;

            // Calcular y redondear el resultado.
            int sepia_red =
                round(.393 * original_red + .769 * original_green + .189 * original_blue);
            int sepia_green =
                round(.349 * original_red + .686 * original_green + .168 * original_blue);
            int sepia_blue =
                round(.272 * original_red + .534 * original_green + .131 * original_blue);

            // Chequear que los valores no superen 255
            sepia_red = limit_to_255(sepia_red);
            sepia_green = limit_to_255(sepia_green);
            sepia_blue = limit_to_255(sepia_blue);

            // Update pixel with sepia values
            image[row][col].rgbtRed = sepia_red;
            image[row][col].rgbtGreen = sepia_green;
            image[row][col].rgbtBlue = sepia_blue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < (width / 2); col++)
        {
            // Definir unos punteros que tendrán las direcciones de memoria
            // de los pixeles a intercambiar.
            RGBTRIPLE *left = &image[row][col];
            RGBTRIPLE *right = &image[row][width - col - 1];
            // Swap pixels
            swap_pixels(left, right);
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy_image[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            copy_image[row][col] = image[row][col];
        }
    }

    // Recorrer pixel por pixel
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Por cada promedio a obtener inicializar las variables.
            int average_red = 0;
            int average_green = 0;
            int average_blue = 0;
            int count = 0;

            // Recorrer las 3 filas de pixeles (superior, medio e inferior).
            for (int y = -1; y <= 1; y++)
            {
                // Recorrer las 3 columnas de pixeles (izquierda, centro y derecha).
                for (int x = -1; x <= 1; x++)
                {
                    // Comprobar que los rangos sean válidos en el array.
                    if ((row + y >= 0) && (row + y < height) && (col + x >= 0) && (col + x < width))
                    {
                        average_red += copy_image[row + y][col + x].rgbtRed;
                        average_green += copy_image[row + y][col + x].rgbtGreen;
                        average_blue += copy_image[row + y][col + x].rgbtBlue;
                        count++;
                    }
                }
            }

            // Para promediar hay que transformar primero la división en número flotante.
            image[row][col].rgbtRed = (int) round((float) average_red / count);
            image[row][col].rgbtGreen = (int) round((float) average_green / count);
            image[row][col].rgbtBlue = (int) round((float) average_blue / count);
        }
    }

    return;
}

/**
 * Comprueba si el valor devuelto de la transformación de un pixel a
 * sepia es superior a 255 y si es así devuelve 255.
 *
 * @param sepia_result: Es el valor resultante de la transformación a
 *                      sepia.
 * @returns: Devuelve 255 si sepia_result es mayor a 255, sino devuelve
 *           sepia_result.
 */
int limit_to_255(int sepia_result)
{
    int const TOP_VALUE = 255;

    if (sepia_result > TOP_VALUE)
    {
        return TOP_VALUE;
    }

    return sepia_result;
}

/**
 * Intercambia de lugar un pixel de la imagen.
 *
 * @param left: es el puntero al pixel del lado izquierdo de la imagen.
 * @param right: es el puntero al pixel del lado derecho de la imagen.
 */
void swap_pixels(RGBTRIPLE *left, RGBTRIPLE *right)
{
    RGBTRIPLE temp;
    temp = *left;
    *left = *right;
    *right = temp;
}
