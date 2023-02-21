#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    for (int i = 1; i <= 20; i++)
    {
        bool printed = false;
        if (i % 3 == 0)
        {
            printf("Fizz");
            printed = true;
        }
        if (i % 5 == 0)
        {
            printf("Buzz");
            printed = true;
        }
        if (!printed)
        {
            printf("%d", i);
        }
        printf("\n");
    }
}