#include "stdio.h"

void main()
{
    int number, result;

    printf("Enter number:\n");
    scanf("%d", &number);

    int base = 10;
    while (number > 0)
    {
        int remainder = number % base;
        number = number / base;
        result += remainder;
    }

    printf("Result: %d\n", result);
}