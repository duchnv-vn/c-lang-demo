#include "stdio.h"
#include "string.h"
#include "conio.h"
#include "math.h"
#include "malloc.h"

void intToString(int value, char *str)
{
    sprintf(str, "%d", value);
}

char *convertHexaDecimalSymbol(int value)
{
    switch (value)
    {
    case 10:
        return "A";
    case 11:
        return "B";
    case 12:
        return "C";
    case 13:
        return "D";
    case 14:
        return "E";
    case 15:
        return "F";
    default:
        return "";
    }
}

void decimalToHexaDecimal(int value)
{
    char *reverseResults[sizeof(int) * 4 + 1];
    int quotient = value;
    int remainder;
    int count = 0;

    do
    {
        remainder = quotient % 16;
        quotient = quotient / 16;

        char *symbol = convertHexaDecimalSymbol(remainder);
        if (symbol != "")
        {
            reverseResults[count] = symbol;
        }
        else
        {
            char numberString[20];
            intToString(remainder, numberString);
            reverseResults[count] = numberString;
        }

        count++;
    } while (quotient > 0);

    char *result;
    for (int i = (count - 1); i >= 0; i--)
    {
        if (i == (count - 1))
        {
            sprintf(result, "%s", reverseResults[i]);
            continue;
        }

        sprintf(result, "%s%s", result, reverseResults[i]);
    }

    printf("10-base = %d -> 16-base = %s\n", value, result);
}

void decimalToOthers(int base, int value)
{
    int reverseResults[sizeof(int)] = {};
    int quotient = value;
    int remainder;
    int count = 0;

    do
    {
        remainder = quotient % base;
        quotient = quotient / base;
        reverseResults[count] = remainder;
        count++;
    } while (quotient > 0);

    int result = 0;
    for (int i = 0; i < count; i++)
    {
        result += reverseResults[i] * pow(10, i);
    }

    printf("10-base = %d -> %d-base = %d\n", value, base, result);
}

void main()
{
    int base, value;

    printf("Enter base:\n");
    scanf("%d", &base);

    printf("Enter value:\n");
    scanf("%d", &value);

    switch (base)
    {
    case 16:
        decimalToHexaDecimal(value);
        break;

    default:
        decimalToOthers(base, value);
        break;
    }
}