// Bài 3: Viết chương trình phân tích một số nguyên thành các thừa số nguyên tố.
#include "stdio.h"

void main()
{
    int input;

    printf("Enter number:\n");
    scanf("%d", &input);

    int i = 2;
    while (input > 1)
    {
        if (input % i == 0)
        {
            input /= i;
            printf("%d ", i);
        }
        else
            i++;
    }
}