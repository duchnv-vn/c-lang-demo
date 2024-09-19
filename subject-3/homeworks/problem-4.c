// Bài 4: Viết chương trình liệt kê tất cả các số nguyên tố nhỏ hơn n cho trước.
#include "stdio.h"
#include "stdbool.h"

void main()
{
    int limit;

    printf("Enter number: \n");
    scanf("%d", &limit);

    for (int i = 1; i < limit; i++)
    {
        bool isPrime = true;

        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }

        isPrime &&printf("%d ", i);
    }
}