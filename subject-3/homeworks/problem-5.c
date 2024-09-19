/*
    Bài 5: Một số được gọi là số thuận nghịch độc nếu ta đọc từ trái sang phải hay từ phải sang trái số đó ta vẫn nhận được một số giống nhau.
    Hãy liệt kê tất cả các số thuận nghịch độc có sáu chữ số.
 */
#include "stdio.h"

#define numberLength 6

void main()
{
    for (int i = 100; i < 1000; i++)
    {
        char halfNumberString[sizeof(int)];
        sprintf(halfNumberString, "%d", i);

        char *numberString;
        sprintf(numberString, "%s", halfNumberString);

        for (int i = 2; i >= 0; i--)
        {
            sprintf(numberString, "%s%c", numberString, halfNumberString[i]);
        }

        printf("%s\n", numberString);
    }
}