/*
    Bài 16: Viết chương trình nhập vào vào mảng A có n phần tử, các phần tử là những số nguyên lớn hơn 0 và nhỏ hơn 100 được nhập vào từ bàn phím. Thực hiện các chức năng sau:
        1.Tìm phần tử lớn nhất và lớn thứ 2 trong mảng cùng chỉ số của các số đó.
        2. Sắp xếp mảng theo thứ tự giảm dần.
        3. Nhập một số nguyên x và chèn x vào mảng A sao cho vẫn đảm bảo tính sắp xếp giảm dần.
 */

#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"

typedef int ArrEleType;
int eleNum;

// ************************************************
// 1.Tìm phần tử lớn nhất và lớn thứ 2 trong mảng cùng chỉ số của các số đó.
void problem1(ArrEleType arr[eleNum])
{
    int maxValueIndex = 0;
    int secMaxValueIndex = 0;
    ArrEleType maxValue = arr[maxValueIndex];
    ArrEleType secMaxValue = 0;

    printf("test %d\n", maxValue);

    for (int i = 0; i < eleNum; i++)
    {
        int currNum = arr[i];
        int nextNumIndex = i + 1;
        int nextNum = arr[nextNumIndex];

        if (nextNumIndex < eleNum && nextNum > currNum && nextNum > maxValue)
        {
            maxValue = nextNum;
            maxValueIndex = nextNumIndex;
        }

        if (currNum < maxValue && currNum > secMaxValue)
        {
            secMaxValue = currNum;
            secMaxValueIndex = i;
        }
    }

    printf("\nProblem 1 result:\n");
    printf("Max value: %d | Index: %d\n", maxValue, maxValueIndex);
    printf("Second max value: %d | Index: %d\n", secMaxValue, secMaxValueIndex);
}

// ************************************************
// 2. Sắp xếp mảng theo thứ tự giảm dần.
int compare(const void *a, const void *b)
{
    const ArrEleType *pNumA = a;
    const ArrEleType *pNumB = b;
    ArrEleType numA = *pNumA;
    ArrEleType numB = *pNumB;

    return numA > numB
               ? -1
           : numA < numB
               ? 1
               : 0;
};
void problem2(ArrEleType arr[eleNum])
{
    ArrEleType arrClone[eleNum];
    memcpy(arrClone, arr, eleNum * sizeof(ArrEleType));
    qsort(arrClone, eleNum, sizeof(ArrEleType), compare);

    printf("\nProblem 2 result:\n");
    for (int i = 0; i < eleNum; i++)
    {
        printf("%d ", arrClone[i]);
    }
    printf("\n");
}

// ************************************************
// 3. Nhập một số nguyên x và chèn x vào mảng A sao cho vẫn đảm bảo tính sắp xếp giảm dần.
void problem3(ArrEleType arr[eleNum])
{
    int x;
    printf("\nEnter number x:\n");
    scanf("%d", &x);

    ArrEleType arrClone[eleNum + 1];
    memcpy(arrClone, arr, eleNum * sizeof(ArrEleType));
    qsort(arrClone, eleNum, sizeof(ArrEleType), compare);
    arrClone[eleNum] = 0;

    int targetNumIndex = eleNum;
    while (targetNumIndex--)
    {
        if (arrClone[targetNumIndex] > x)
        {
            arrClone[targetNumIndex + 1] = x;
            break;
        }
        else
        {
            arrClone[targetNumIndex + 1] = arrClone[targetNumIndex];
        }
    }

    printf("\nProblem 3 result:\n");
    for (int i = 0; i < eleNum + 1; i++)
    {
        printf("%d ", arrClone[i]);
    }
    printf("\n");
}

void main(void)
{
    printf("\nEnter total number:\n");
    scanf("%d", &eleNum);

    ArrEleType arr[eleNum];

    for (int i = 0; i < eleNum; i++)
    {
        printf("\nEnter number %d:\n", i);
        bool isValid = true;
        do
        {
            if (!isValid)
            {
                printf("\nInvalid number, re-enter: ");
            }

            scanf("%d", &arr[i]);
            isValid = arr[i] > 0 || arr[i] < 100;
        } while (!isValid);
    }

    problem1(arr);
    problem2(arr);
    problem3(arr);
}