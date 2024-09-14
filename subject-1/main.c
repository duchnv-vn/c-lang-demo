#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "math.h"
#include "stdbool.h"

void main()
{
    printf("----- Start main function -----\n");
    char character = 'a';
    printf("%c\n", character);

    char text[] = "Hello World!";
    printf("%s\n", text);

    int intNumber = 10;
    long bigNumber = 99999L;
    float floatNumber = 19.99f;
    double doubleNumber = 12.99999999;

    bool isTrue = true;
    bool isFalse = false;

    int mutableVariable = 5;
    mutableVariable += 1;

    const int immutableVariable = 100;
    // immutableVariable = 5; // Can not change value

    int a;
    printf("Type value of a: ");
    scanf("%d", &a); // Receive input value typing from console
    printf("Value of variable a: %d\n", a);

    int b = 0;
    int c = b++; // Assign current value of b to c, then change b value = 1
    printf("Value of b: %d\n", b);
    printf("Value of c: %d\n", c);

    int d = ++b; // Change b value = 2, then assign current value of b to d
    printf("Value of b: %d\n", b);
    printf("Value of d: %d\n", d);

    int e = 1;
    int f = '1';
    int isEqual = e == f;
    printf("Is equal: %d\n", isEqual);

    printf("----- End main function -----\n");
}