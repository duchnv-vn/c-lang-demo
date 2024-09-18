#include "stdio.h"

#define n1 5

void readArray(int arr[2])
{
    for (int i = 0; i < 2; i++)
    {
        printf("%d: %d\n", i, arr[i]);
    }
}

void main()
{
    // ARRAY
    int a1[n1];

    int a2[] = {1, 2, 3, 4, 5};
    readArray(a2);

    // STRING
    char firstName[5] = {'h',
                         'e',
                         'l',
                         'l',
                         'o'};

    char lastName[5] = "World";

    char name[] = "Tony Stack";
}