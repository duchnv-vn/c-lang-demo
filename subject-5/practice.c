#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "math.h"

// *****************************************************************************
/*
    Bài 1. Viết chương trình tính chu vi và diện tích của một số hình học cơ bản:
        · Yêu cầu người dùng nhập vào tên của hình muốn tính diện tích. Tên là một trong ba loại sau: tam giac, hinh chu nhat, hinh vuong.
        · Sau khi người dùng nhập vào tên hình cần tính, yêu cầu người dùng nhập các thông tin cần thiết để tính chu vi và diện tích.
            o   Với tam giác, yêu cầu nhập độ dài ba cạnh.
            o   Với hình chữ nhật, yêu cầu nhập chiều dài và chiều rộng.
            o   Với hình vuông, yêu cầu nhập độ dài cạnh.
        · Sau khi người dùng nhập đủ thông tin theo yêu cầu, kiểm tra dữ liệu nhập vào có phù hợp hay không. Nếu có, tính chu vi, diện tích và in kết quả ra màn hình.
 */
void exercise1(void)
{
    printf("Enter shape id (1 - tam giac | 2 - vuong | 3 - chu nhat):\n");

    char *shape;
    int shapeId;
    bool isValidShapeId = true;

    do
    {
        scanf("%d", &shapeId);
        isValidShapeId = shapeId == 1 || shapeId == 2 || shapeId == 3;
    } while (!isValidShapeId);

    switch (shapeId)
    {
    case 1:
        shape = "tam giac";
        break;
    case 2:
        shape = "vuong";
        break;
    case 3:
        shape = "chu nhat";
        break;
    }

    float side1;
    float side2;
    float side3;

    float area;
    float perimeter;
    bool isValid = true;

    if (shapeId == 1)
    {
        do
        {
            if (!isValid)
            {
                printf("Invalid inputs, re-enter:\n");
            }
            printf("Enter side 1 number:\n");
            scanf("%f", &side1);
            printf("Enter side 2 number:\n");
            scanf("%f", &side2);
            printf("Enter side 3 number:\n");
            scanf("%f", &side3);

            isValid =
                side1 > 0 &&
                side2 > 0 &&
                side3 > 0 &&
                (side1 + side2) > side3 &&
                (side2 + side3) > side1 &&
                (side3 + side1) > side2;

        } while (!isValid);

        float semiArea = (side1 + side2 + side3) / 2.0;
        area = pow((semiArea * (semiArea - side1) * (semiArea - side2) * (semiArea - side3)), 0.5);
        perimeter = side1 + side2 + side3;
    }
    else if (shapeId == 2)
    {
        do
        {
            if (!isValid)
            {
                printf("Invalid inputs, re-enter:\n");
            }

            printf("Enter side number:\n");
            scanf("%d", &side1);

            isValid = side1 > 0;
        } while (!isValid);

        area = sqrt(side1);
        perimeter = side1 * 4;
    }
    else if (shapeId == 3)
    {
        do
        {
            if (!isValid)
            {
                printf("Invalid inputs, re-enter:\n");
            }

            printf("Enter length number:\n");
            scanf("%d", &side1);
            printf("Enter width number:\n");
            scanf("%d", &side2);

            isValid = side1 > 0 && side2 > 0 && side1 != side2;
        } while (!isValid);

        area = side1 * side2;
        perimeter = (side1 + side2) * 2;
    }

    printf("Result problem 1\n");
    printf("Area of %s: %.2f\n", shape, area);
    printf("Perimeter of %s: %.2f\n", shape, perimeter);
    printf("----------------------------------\n\n");
}

// *****************************************************************************
/*
    Bài 2: Viết chương trình nhập một số nguyên n sao cho 0 < n ≤ 100 (Nếu nhập sai thì yêu cầu nhập lại). Đếm và in ra màn hình số ước của n.
 */
void exercise2(void)
{
    int number;
    bool isValid = true;

    do
    {
        if (!isValid)
        {
            printf("Invalid inputs, re-enter:\n");
        }

        printf("Enter number > 0 and ≤ 100:\n");
        scanf("%d", &number);
        isValid = number > 0 && number <= 100;
    } while (!isValid);

    printf("Result problem 2\n");
    for (int i = 2; i < number; i++)
    {
        if (number % i == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("----------------------------------\n\n");
}

// *****************************************************************************
/*
    Bài 3: Giải phương trình bậc 2 một ẩn: ax^2 + bx + c = 0
 */
void exercise3(void)
{

    float a;
    float b;
    float c;

    bool isValid = true;

    do
    {
        if (!isValid)
        {
            printf("Invalid inputs, re-enter:\n");
        }

        printf("Enter a number:\n");
        scanf("%f", &a);
        printf("Enter b number:\n");
        scanf("%f", &b);
        printf("Enter c number:\n");
        scanf("%f", &c);

        isValid = a != 0;
    } while (!isValid);

    float x1, x2;
    float delta = pow(b, 2) - (4.0 * a * c);
    if (delta > 0)
    {
        x1 = (-b + pow(delta, 0.5)) / (2 * a);
        x2 = (-b - pow(delta, 0.5)) / (2 * a);
    }
    else if (delta == 0)
    {
        x1 = x2 = -(b / (2.0 * a));
    }
    else
    {
        printf("No value x1 and x2\n\n");
        return;
    }

    printf("Result problem 3\n");
    printf("Value x1: %.2f\n", x1);
    printf("Value x2: %.2f\n", x2);
    printf("----------------------------------\n\n");
}

// *****************************************************************************
/*
    Bài 4: Nhập vào 3 số nguyên dương a, b, c.
    Kiểm tra xem 3 số đó có lập thành tam giác không? Nếu có hãy cho biết tam giác đó thuộc loại nào? (Cân, đều). Tính chu vi và diện tích của tam giác.
 */
void exercise4(void)
{
    int a;
    int b;
    int c;

    bool isValid = true;

    do
    {
        if (!isValid)
        {
            printf("Invalid inputs, re-enter:\n");
        }

        printf("Enter a number:\n");
        scanf("%d", &a);
        printf("Enter b number:\n");
        scanf("%d", &b);
        printf("Enter c number:\n");
        scanf("%d", &c);

        isValid = a > 0 && b > 0 && c > 0;
    } while (!isValid);

    bool isTriangle =
        (a + b) > c &&
        (b + c) > a &&
        (c + a) > b;

    printf("Result problem 4\n");
    if (!isTriangle)
    {
        printf("Invalid triangle\n");
    }
    else if (a == b && a == c && a == c)
    {
        printf("Equilateral triangle\n");
    }
    else if (a == b || b == c || c == a)
    {
        printf("Isosceles triangle\n");
    }
    else
    {
        printf("Normal triangle\n");
    }
    printf("----------------------------------\n\n");
}

// *****************************************************************************
/*
    Bài 5: Viết chương trình nhập vào mảng 2 chiều m,n yêu cầu thực hiện:
 */
typedef int MatrixEleType;
void exercise5(void)
{
    // ***
    // a) Nhập các phần tử và xuất ra mảng vừa nhập
    // ***
    int rowNum;
    int colNum;
    printf("Enter row number:\n");
    scanf("%d", &rowNum);
    printf("Enter column number:\n");
    scanf("%d", &colNum);

    MatrixEleType matrix[rowNum][colNum];
    for (int i = 0; i < rowNum; i++)
    {
        printf("\nEnter elements of row %d:\n", i);
        for (int j = 0; j < colNum; j++)
        {
            printf("\nElement %d: ", j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Result problem 5\n");
    printf("Result of a question:\n");
    for (int i = 0; i < rowNum; i++)
    {
        printf("{ ");
        for (int j = 0; j < colNum; j++)
        {
            printf("%lld ", matrix[i][j]);
        }
        printf("}\n");
    }
    printf("----------------------------------\n");

    // ***
    // b) Các phần nào trong không phải là số chẵn thì chuyển thành 0
    // ***
    MatrixEleType matrixClone1[rowNum][colNum];
    for (int i = 0; i < rowNum; i++)
    {
        memcpy(matrixClone1[i], matrix[i], colNum * sizeof(MatrixEleType));
    }
    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 0; j < colNum; j++)
        {
            if (matrixClone1[i][j] % 2 != 0)
            {
                matrixClone1[i][j] = 0;
            }
        }
    }
    printf("Result of b question:\n");
    for (int i = 0; i < rowNum; i++)
    {
        printf("{ ");
        for (int j = 0; j < colNum; j++)
        {
            printf("%lld ", matrixClone1[i][j]);
        }
        printf("}\n");
    }
    printf("----------------------------------\n");

    // ***
    // c) Sắp xếp mảng giảm dần, sau đó thực hiện chèn X vào mảng làm sao mảng vẫn giảm dần. (X là số người dùng nhập vào)
    // ***

    // Generate flatted array
    int flatArrTotal = rowNum * colNum;
    MatrixEleType flatArr[flatArrTotal];
    int count1 = 0;
    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 0; j < colNum; j++)
        {
            flatArr[count1++] = matrix[i][j];
        }
    }

    // Sort flatted array
    int count2 = flatArrTotal - 1;
    while (count2--)
    {
        for (int i = flatArrTotal - 1; i > 0; i--)
        {
            int prev_i = i - 1;

            if (flatArr[prev_i] < flatArr[i])
            {
                int temp = flatArr[prev_i];
                flatArr[prev_i] = flatArr[i];
                flatArr[i] = temp;
            }
        }
    }

    // Convert flatted array to 2D array
    MatrixEleType matrixClone2[rowNum + 1][colNum];
    int count3 = 0;
    for (int i = 0; i < rowNum; i++)
    {
        for (int j = 0; j < colNum; j++)
        {
            matrixClone2[i][j] = flatArr[count3++];
        }
    }
    for (int i = 0; i < rowNum; i++)
    {
        printf("{ ");
        for (int j = 0; j < colNum; j++)
        {
            printf("%lld ", matrixClone2[i][j]);
        }
        printf("}\n");
    }
    printf("----------------------------------\n");

    int x;
    printf("Enter x number:\n");
    scanf("%d", &x);
    int flatArrCloneTotal = (rowNum + 1) * colNum;
    MatrixEleType flatArrClone[flatArrCloneTotal];
    memcpy(flatArrClone, flatArr, flatArrTotal * sizeof(MatrixEleType));
    MatrixEleType matrixClone3[rowNum + 1][colNum];

    // Append x into array in decreasing order
    for (int i = flatArrTotal - 1; i >= 0; i--)
    {

        if (x <= flatArrClone[i])
        {
            flatArrClone[i + 1] = x;
        }
        else
        {
            flatArrClone[i + 1] = flatArrClone[i];
        }
    }

    // Convert flatted array to 2D array
    int count4 = 0;
    for (int i = 0; i < rowNum + 1; i++)
    {
        for (int j = 0; j < colNum; j++)
        {
            matrixClone3[i][j] = flatArrClone[count4++];
        }
    }

    printf("Result of c question:\n");
    int count5 = 0;
    for (int i = 0; i < rowNum + 1; i++)
    {
        printf("{ ");
        for (int j = 0; j < colNum; j++)
        {
            if (count5 <= flatArrTotal)
            {
                printf("%lld ", matrixClone3[i][j]);
            }
            count5++;
        }
        printf("}\n");
    }
    printf("----------------------------------\n\n");
}

void main(void)
{
    int exerciseNum;
    while (true)
    {
        printf("Enter exercise number (1,2,3,4,5):\n");
        scanf("%d", &exerciseNum);

        switch (exerciseNum)
        {
        case 1:
            exercise1();
            break;

        case 2:
            exercise2();
            break;

        case 3:
            exercise3();
            break;

        case 4:
            exercise4();
            break;

        case 5:
            exercise5();
            break;
        }
    }
}