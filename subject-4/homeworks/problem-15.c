/*
    Viết chương trình nhập vào vào ma trận A có n dòng, m cột, các phần tử là những số nguyên lớn hơn 0 và nhỏ hơn 100 được nhập vào từ bàn phím. Thực hiện các chức năng sau:
    1. Tìm phần tử lớn nhất của ma trận cùng chỉ số của số đó.
    2. Tìm và in ra các phần tử là số nguyên tố của ma trận (các phần tử không nguyên tố thì thay bằng số 0).
    3. Sắp xếp tất cả các cột của ma trận theo thứ tự tăng dần và in kết quả ra màn hình.
 */
#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"

int rowNum;
int colNum;

// ************************************************
// 1. Tìm phần tử lớn nhất của ma trận cùng chỉ số của số đó.
void problem1(int matrix[rowNum][colNum])
{
    int rowIndex = 0;
    int colIndex = 0;
    int maxValue = matrix[rowIndex][colIndex];

    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 1; j < colNum; j++)
        {
            if (matrix[i][j] > maxValue)
            {
                maxValue = matrix[i][j];
                rowIndex = i;
                colIndex = j;
            }
        }
    }
    printf("\nProblem 2 result:\n");
    printf("Max value: %d | Row: %d | Column: %d\n", maxValue, rowIndex, colIndex);
}

// ************************************************
//  2. Tìm và in ra các phần tử là số nguyên tố của ma trận (các phần tử không nguyên tố thì thay bằng số 0).
void problem2(int matrix[rowNum][colNum])
{
    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 0; j < colNum; j++)
        {
            bool isPrime = true;
            for (int k = 2; k < matrix[i][j]; k++)
            {
                if (matrix[i][j] % k == 0)
                {
                    matrix[i][j] = 0;
                    isPrime = false;
                }
            }

            printf("\nProblem 2 result:\n");
            if (isPrime)
            {
                printf("%d ", matrix[i][j]);
            }
        }
    }
}

// ************************************************
// 3. Sắp xếp tất cả các cột của ma trận theo thứ tự tăng dần và in kết quả ra màn hình.
void problem3_solution1(int matrix[rowNum][colNum])
{
    int compare(const void *a, const void *b)
    {
        const int *pNumA = a;
        const int *pNumB = b;
        int numA = *pNumA;
        int numB = *pNumB;

        return numA > numB
                   ? 1
               : numA < numB
                   ? -1
                   : 0;
    };

    int matrixClone[rowNum][colNum];
    for (int i = 0; i < rowNum; i++)
    {
        memcpy(matrixClone[i], matrix[i], colNum * sizeof(int));
    }

    printf("\nProblem 3 - solution 1 result:\n");

    for (int i = 0; i < rowNum; i++)
    {
        qsort(matrixClone[i], colNum, sizeof(int), compare);

        for (int j = 0; j < colNum; j++)
        {
            printf("%d ", matrixClone[i][j]);
        }
        printf("\n");
    }
}

void problem3_solution2(int matrix[rowNum][colNum])
{
    printf("\nProblem 3 - solution 1 result:\n");

    int matrixClone[rowNum][colNum];
    for (int i = 0; i < rowNum; i++)
    {
        memcpy(matrixClone[i], matrix[i], colNum * sizeof(int));
    }

    for (int i = 0; i < rowNum; i++)
    {
        int checkNumIndex = colNum;

        while (checkNumIndex--)
        {
            for (int j = checkNumIndex - 1; j >= 0; j--)
            {
                if (matrixClone[i][checkNumIndex] < matrixClone[i][j])
                {
                    int temp = matrixClone[i][checkNumIndex];
                    matrixClone[i][checkNumIndex] = matrixClone[i][j];
                    matrixClone[i][j] = temp;
                }
            }
        }

        for (int j = 0; j < colNum; j++)
        {
            printf("%d ", matrixClone[i][j]);
        }
        printf("\n");
    }
}

void main(void)
{
    printf("\nEnter row number:\n");
    scanf("%d", &rowNum);

    printf("\nEnter column number:\n");
    scanf("%d", &colNum);

    int matrix[rowNum][colNum];
    for (int i = 0; i < rowNum; i++)
    {
        printf("\nEnter elements of row %d:\n", i);
        for (int j = 0; j < colNum; j++)
        {
            printf("\nElement %d: ", j);
            scanf("%d", &matrix[i][j]);
        }
    }

    problem1(matrix);
    problem2(matrix);
    problem3_solution1(matrix);
    problem3_solution2(matrix);
}