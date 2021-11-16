#include <stdio.h> 
#include <math.h>            
#include <ctype.h>    
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>	
#include <time.h>

int  find_the_digit(int, int64_t);
void print_num(int64_t, int, int, int);

int main()
{
    int64_t num1 = 0, num2 = 0;

    printf("Please enter the first  number: "); scanf("%ld", &num1);
    printf("Please enter the second number: "); scanf("%ld", &num2);

    if(num1 < 0 || num2 < 0)
    {
        printf("Please enter two positive number.\n");
        return 0;
    }
    else if(num1 > 2147483647 || num2 > 2147483647)
    {
        printf("Input Overflow\n");
        return 0;
    }

    int64_t sum = num1 + num2;

    int64_t overflow;
    overflow = 4294967295 - num1;
    if(num2 > overflow)
    {
        printf("Overflow Error\n");
        return 0;
    }

    int digit = 0, d1 = 0, d2 = 0, da = 0;

    d1 = find_the_digit(d1, num1);
    d2 = find_the_digit(d2, num2);
    if(d1 >= d2){ digit = d1; }
    else { digit = d2; }
//  printf("d1 = %d, d2 = %d, digit = %d\n", d1, d2, digit);

    print_num(num1, d1, digit, 1);
    print_num(num2, d2, digit, 2);

    for(int i = 0; i <= digit; i++)
    {
        printf("--");
    }
    printf("\n");


    da = find_the_digit(da, sum);
    if(da == digit)
    { print_num(sum, da, digit, 1); }
    else
    { print_num(sum, da, digit, 3); }

    return 0;
}

void print_num(int64_t number, int digit, int param, int position)
{
    if(position == 1)
    {
        printf("  ");
    }
    else if(position == 2)
    {
        printf("+)");
    }
    
    int ten = 1;

    for(int i = 1; i < digit; i++)
    {
        ten *= 10;
    }

    if(digit < param)
    {
        for(int i = 0; i < param-digit; i++)
        {
            printf("  ");
        }
    }
    else if(digit > param)
    {
        // do nothing //
    }

    while(ten != 0)
    {
        printf(" %ld", number/ten);
        number %= ten;
        ten /= 10;
    }
    printf("\n");
    return;
}

int find_the_digit(int digit, int64_t number)
{
    digit = 0;
    while( number/10 != 0 )
    {
        digit++;
        number /= 10;
    }
    digit++;

    return digit;
}