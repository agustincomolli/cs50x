#include "helpers.h"
#include <math.h>

// Prototipo de funciones
int limit_to_255(int sepia_result);
void swap_pixels(RGBTRIPLE *left, RGBTRIPLE *right);
int get_gx(char channel, int row, int col, int width, int height, RGBTRIPLE image[height][width]);
int get_gy(char channel, int row, int col, int width, int height, RGBTRIPLE image[height][width]);
int get_sobel(int gx, int gy);

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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
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

    // Recorrer todos los pixeles
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // Calcular los valores GX y GY para cada canal de color.
            int gx_red = get_gx('r', row, col, width, height, copy_image);
            int gy_red = get_gy('r', row, col, width, height, copy_image);

            int gx_green = get_gx('g', row, col, width, height, copy_image);
            int gy_green = get_gy('g', row, col, width, height, copy_image);

            int gx_blue = get_gx('b', row, col, width, height, copy_image);
            int gy_blue = get_gy('b', row, col, width, height, copy_image);

            // Obtener el valor final.
            int final_red = get_sobel(gx_red, gy_red);
            int final_green = get_sobel(gx_green, gy_green);
            int final_blue = get_sobel(gx_blue, gy_blue);

            // Actualizar el pixel por el nuevo valor.
            image[row][col].rgbtRed = final_red;
            image[row][col].rgbtGreen = final_green;
            image[row][col].rgbtBlue = final_blue;
        }
    }

    return;
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

/**
 * Obtiene el valor GX recorriendo una matriz de 3x3 de los pixeles adyacentes.
 *
 * @param channel: Es una caracter que indica el color 'r', 'g' o 'b'.
 * @param row: Es la fila del pixel actual.
 * @param col: Es la columna del pixel actual.
 * @param width: Ancho de la imagen.
 * @param height: Alto de la imagen.
 * @param image: La copia de la imagen.
 *
 * @returns: Un entero con el valor de GX
 */
int get_gx(char channel, int row, int col, int width, int height, RGBTRIPLE image[height][width])
{
    int sum = 0;
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

    // Recorrer las 3 filas de pixeles (superior, medio e inferior).
    for (int y = -1; y <= 1; y++)
    {
        // Recorrer las 3 columnas de pixeles (izquierda, centro y derecha).
        for (int x = -1; x <= 1; x++)
        {
            // Comprobar que los rangos sean válidos en el array.
            if ((row + y >= 0) && (row + y < height) && (col + x >= 0) && (col + x < width))
            {
                if (channel == 'r')
                {
                    sum += image[row + y][col + x].rgbtRed * gx[y + 1][x + 1];
                }
                else if (channel == 'g')
                {
                    sum += image[row + y][col + x].rgbtGreen * gx[y + 1][x + 1];
                }
                else
                {
                    sum += image[row + y][col + x].rgbtBlue * gx[y + 1][x + 1];
                }
            }
        }
    }

    return sum;
}

/**
 * Obtiene el valor GY recorriendo una matriz de 3x3 de los pixeles adyacentes.
 *
 * @param channel: Es una caracter que indica el color 'r', 'g' o 'b'.
 * @param row: Es la fila del pixel actual.
 * @param col: Es la columna del pixel actual.
 * @param width: Ancho de la imagen.
 * @param height: Alto de la imagen.
 * @param image: La copia de la imagen.
 *
 * @returns: Un entero con el valor de GY
 */
int get_gy(char channel, int row, int col, int width, int height, RGBTRIPLE image[height][width])
{
    int sum = 0;
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Recorrer las 3 filas de pixeles (superior, medio e inferior).
    for (int y = -1; y <= 1; y++)
    {
        // Recorrer las 3 columnas de pixeles (izquierda, centro y derecha).
        for (int x = -1; x <= 1; x++)
        {
            // Comprobar que los rangos sean válidos en el array.
            if ((row + y >= 0) && (row + y < height) && (col + x >= 0) && (col + x < width))
            {
                if (channel == 'r')
                {
                    sum += image[row + y][col + x].rgbtRed * gy[y + 1][x + 1];
                }
                else if (channel == 'g')
                {
                    sum += image[row + y][col + x].rgbtGreen * gy[y + 1][x + 1];
                }
                else
                {
                    sum += image[row + y][col + x].rgbtBlue * gy[y + 1][x + 1];
                }
            }
        }
    }

    return sum;
}

/**
 * Obtiene el resultado del algoritmo Soble.
 *
 * @param gx: El valor GX para un canal de color.
 * @param gy: El valor GY para un canal de color.
 *
 * @returns: El valor que debe reemplazar al canal de color del pixel actual.
 */
int get_sobel(int gx, int gy)
{
    float final = round(sqrt(gx * gx + gy * gy));

    if ((int) final > 255)
    {
        return 255;
    }
    else if ((int) final < 0)
    {
        return 0;
    }

    return (int) final;
}
