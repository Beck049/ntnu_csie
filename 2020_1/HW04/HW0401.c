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

int main()
{
    int  num;
    int th, hun, ten, one;

    printf("Please enter a number between 1 & 3000 : ");
    scanf("%d",&num);
//
    if(num > 3000 || num < 1)
    {
        printf("ERROR the number should between 1 & 3000");
        return 0;
    }
//
    th = num / 1000;
    if(th > 0)
    {
        for(int i = 0; i < th; i++)
        {
            printf("M");
        }
    }
    num = num % 1000;
//
    hun = num / 100;
    if(hun > 0)
    {
        if(hun >= 9)
        {
            printf("CM");
        }
        else if(hun > 5)
        {
            printf("D");
            for(int i = 0; i < hun-5; i++)
            {
                printf("C");
            }
        }
        else if(hun >= 4)
        {
            printf("CD");
        }
        else
        {
            for(int i = 0; i < hun; i++)
            {
                printf("C");
            }
        }
    }
    num = num % 100;
//
    ten = num / 10;
    if(ten > 0)
    {
        if(ten >= 9)
        {
            printf("XC");
        }
        else if(ten > 5)
        {
            printf("L");
            for(int i = 0; i < ten-5; i++)
            {
                printf("X");
            }
        }
        else if(ten >= 4)
        {
            printf("XL");
        }
        else
        {
            for(int i = 0; i < ten; i++)
            {
                printf("X");
            }
        }
    }
    num = num % 10;
//
    one = num / 1;
    if(one >= 9)
    {
        printf("IX");
    }
    else if(one >= 5)
    {
        printf("V");
        for(int i = 0; i < one-5; i++)
        {
            printf("I");
        }
    }
    else if(one >= 4)
    {
        printf("IV");
    }
    else
    {
        for(int i = 0; i < one; i++)
        {
            printf("I");
        }
    }
//
    return 0;
}
