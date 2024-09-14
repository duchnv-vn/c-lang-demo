#include "stdio.h"
#include "math.h"

// Tính tổng chữ số của một số
int exercise1(int input)
{
    int absInput = abs(input);
    int baseNumber = 10;
    int length = 1;
    int compareNumber = pow(baseNumber, length);

    while (compareNumber < absInput)
    {
        compareNumber = pow(baseNumber, ++length);
    }

    return length;
}

// Phân tích thừa số nguyên tố
void exercise2(int input)
{
    if (input <= 1)
    {
        printf("input must be greater than 1");
        return;
    }

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

// Tính ước chung lớn nhất
int exercise3(int a, int b)
{
    if (a == b)
    {
        return a;
    }

    int greaterNumber;
    int smallerNumber;
    if (a > b)
    {
        greaterNumber = a;
        smallerNumber = b;
    }
    else
    {
        greaterNumber = b;
        smallerNumber = a;
    }

    while (smallerNumber > 0)
    {
        int i = greaterNumber % smallerNumber;
        greaterNumber = smallerNumber;
        smallerNumber = i;
    }

    return greaterNumber;
}

void main()
{
    // int lengthOfNumber = exercise1(-999);
    // printf("Exercise 1 result: %d\n", lengthOfNumber);

    // exercise2(120);

    // int result3 = exercise3(30, 48);
    // printf("Exercise 3 result: %d\n", result3);
}
