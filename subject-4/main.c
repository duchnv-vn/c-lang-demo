#include "conio.h"
#include "stdio.h"

void passValueFunc(int value)
{
    value++;
}

void passAddressFunc(int *address)
{
    (*address)++;
}

void main()
{
    int value = 1;
    printf("value 1: %d\n", value); // value = 1
    passValueFunc(value);
    printf("value 2: %d\n", value); // value = 1

    int *address;
    address = &value;
    printf("address 2: %d\n", *address); // *address = 1
    passAddressFunc(address);
    printf("address 2: %d\n", *address); // *address = 2
    printf("value 3: %d\n", value);      // value = 2

    // getch();
}
