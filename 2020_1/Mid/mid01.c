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
        printf("Invalid input");
        return 0;
    }
    printf("Please enter the 2nd integer: ");
    scanf("%d", &a2);
    if(check(a2) == 1)
    {
        printf("Invalid input");
        return 0;
    }

    while(a1 != 0 || a2 != 0)
    {
        if(a1 % 10 > a2 % 10)
        {
            total += a1%10;
            a1 = a1 / 10;
            total *= 10;
        }
        else
        {
            total += a2%10;
            a2 = a2 / 10;
            total *= 10;
        }
    }
//  printf("%d", total);

    total /= 10;
    while(total != 0)
    {
        printf("%d", total%10);
        total /= 10;
    }

    return 0;
}

int check(int a)
{
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