#include "stdio.h"
#include "stdbool.h"

#define arrLen 10

void main()
{
    int arr[arrLen] = {5, 6, 8, 3, 1, 2, 4, 9, 7, 0};

    int sortedArr[arrLen];
    sortedArr[0] = arr[0];

    for (int i = 1; i < arrLen; i++)
    {
        for (int j = (i - 1); j >= 0; j--)
        {
            bool isGreater = arr[i] >= sortedArr[j];

            if (isGreater)
            {
                sortedArr[j + 1] = arr[i];
                break;
            }
            else
            {
                sortedArr[j + 1] = sortedArr[j];

                if (j == 0)
                {
                    sortedArr[0] = arr[i];
                }
            }
        }
    }

    // Print results
    for (int i = 0; i < arrLen; i++)
    {
        printf("%d ", sortedArr[i]);
    }
}