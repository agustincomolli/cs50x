#include <stdio.h>

#define MAX_SCORES 1024

int main(void)
{
    int scores[MAX_SCORES];

    for (int i = 0; i < MAX_SCORES; i++)
    {
        printf("%i\n", scores[i]);
    }
}
