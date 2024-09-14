#include "stdio.h"
#include "stdbool.h"

// Tính tổng S = 1 + 1/2 + ... +1/N
float exercise1(int input)
{
    if (input < 2)
    {
        printf("input must be greater than or equal 2");
        return 0;
    }

    float output = 1.0f;
    for (int i = 2; i <= input; i++)
    {
        output += 1.0f / i;
    }

    return output;
}

// Kiểm tra số nguyên tố
bool exercise2(int input)
{
    if (input <= 1)
        return false;

    for (int i = 2; i < input; i++)
    {
        if (input % i == 0)
            return false;
    }
    return true;
}

void main()
{
    // float result = exercise1(2);
    // printf("Exercise 1 result: %f\n", result);

    // for (int i = 2; i <= 100; i++)
    // {
    //     bool isPrime = exercise2(i);
    //     printf("Exercise 2 result of number %d: %d\n", i, isPrime);
    // }
}
