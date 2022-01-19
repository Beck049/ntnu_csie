#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main()
{
    int value = 0;

    printf("123456%n789ABC\n", &value);
    printf("value = %d\n", value);

    return 0;
}