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

int chack_zero (int*);
void minus (int*, int*);
void divide(int*);
int compare(int*, int*);
int check_zero(int*);
void print_expo(int );
void print_frac(int*);

int main()
{
    char input[65] = {0};
    printf("Please enter a floating-point number (double precision) :");
    gets(input);

    int sign = 0, firstNum;
 // Sign 1
    if(input[0] == 45)
    {
        sign = 1;
        if(input[1] == 49)
        {
            firstNum = 1;
        }
    }
    else
    {
        if(input[0] == 49)
        {
            firstNum = 1;
        }
    }
    printf("Sign: %d\n", sign);
 // Exponent 11
    int exponent = 0;

    int i = 0;
    if(firstNum == 1){  i++;    }
    if(sign == 1){  i++;    }

    while(input[i] != 46)
    {
        i++;
        exponent++;
    }

    exponent = 1023 - exponent;

    print_expo(exponent);

 // Fraction 52
    int frac[20] = {0};
    int j = 0;

    i = 0;
    if(firstNum == 1){  i++;    }
    if(sign == 1){  i++;    }

    while( input[i] > 45 && input[i] < 58 )
    {
        if(input[i] == 46)
        {
            i++;
        }
        else
        {
            frac[j] = input[i] - 48;
            i++; j++;
        }
    }

    printf("Fraction: ");
    print_frac(frac);
        
/*
    // j = len
    printf("\n           (");
    for(int k = 0; k < j; k++)
    {
        printf("%d", frac[k]);
    }
    printf(")");
*/
    return 0;
}
void print_frac(int* frac)
{
    int num[20]; // 500000000
    int f  [20]; // 750000000
    int out[52]; // 110010100

    num[0] = 5;
    for(int i = 1; i < 20; i++)
    {
        num[i] = 0;
    }

    for(int i = 0; i < 20; i++)
    {
        f[i] = frac[i];
    }

    int count = 0;
    // for(int i = 0; i < 52; i++)
    // {
    //     out[i] = 0;
    // }

    int comp = -1;
    while(count < 52)
    {
        // compare num, f
        comp = compare(num, f);

        if(comp == 1) // num > f :1
        {
            divide(num);
            count++;
            printf("0");
        }
        else if(comp == 0) // num < f :0
        {
            minus(f, num); // f = f - num
            divide(num);   // num /= 2
            // out[count] = 1;
            count++;
            printf("1");
        }
    }

    // for(int i = 0; i < 52; i++)
    // {
    //     printf("%d", out[i]);
    // }
}
void minus(int* f, int*num)
{
    for(int i = 0; i < 20; i++)
    {
        f[i] -= num[i];
    }
    for(int i = 0; i < 20; i++)
    {
        if(f[19-i] < 0)
        {
            f[19-i] += 10;
            f[18-i] -=  1;
        }
    }
}
void divide(int* num)
{
    for(int i = 0; i < 20; i++)
    {
        if(num[i] % 2 == 1)
        {
            num[i+1] += 10;
        }
        num[i] /= 2;
    }
}
int compare(int* num, int* f)
{
    for(int i = 0; i < 20; i++)
    {
        if(num[i] > f[i])
        {
            return 1;
        }
        else if(num[i] < f[i])
        {
            return 0;
        }
        else // num[i] = f[i]
        {
            continue;
        }
    }
}
int check_zero(int* f)
{
    for(int i = 0; i < 20; i++)
    {
        if(f[i] != 0)
        {
            return 1;
        }
    }
    return 0;
}
void print_expo(int exponent)
{
    int num = 1024;
    int temp = exponent;
    printf("Exponent: ");
    while(temp > 0)
    {
        if(temp >= num)
        {
            temp -= num;
            num /= 2;
            printf("1");
        }
        else
        {
            num /= 2;
            printf("0");
        }
    }
    printf(" (%d)\n", exponent);
}