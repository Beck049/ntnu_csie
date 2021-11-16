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

int check(int);

int main()
{
    int a1 ,a2;
    int total = 0;

    printf("Please enter the 1st integer: ");
    scanf("%d", &a1);
    if(check(a1) == 1)
    {
        printf("Invalid input\n");
        return 0;
    }
    printf("Please enter the 2nd integer: ");
    scanf("%d", &a2);
    if(check(a2) == 1)
    {
        printf("Invalid input\n");
        return 0;
    }

    printf("Result: ");

    if(a1 == 0 && a2 == 0)
    {
        printf("00");
    }
    else if(a1 == 0 && a2 != 0)
    {
        while(a2 != 0)
        {
            printf("%d", a2%10);
            a2 /= 10;
        }
        printf("0");
    }
    else if(a2 == 0 && a1 != 0)
    {
        while(a1 != 0)
        {
            printf("%d", a1%10);
            a1 /= 10;
        }
        printf("0");
    }
    else
    {
        while(a1 != 0 || a2 != 0)
        {
            if( a1 % 10 > a2 % 10)
            {
                printf("%d", a1%10);
                a1 /= 10;
            }
            else
            {
                printf("%d", a2%10);
                a2 /= 10;
            }
        }
    }

    printf("\n");
    return 0;
}

int check(int a)
{
    if(a < 0)
    {
        return 1;
    }

    int temp, f, b;
    temp = a/10;
    f = a%10;
    while(temp != 0)
    {
        b = f;
        f = temp % 10;
        if(b < f)
        {
            return 1;
        }
        temp = temp / 10;
    }

    return 0;
}