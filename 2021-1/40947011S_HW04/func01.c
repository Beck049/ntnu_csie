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

void k(int n)
{
    if(n%2 == 0)
    {
        printf("The number must be odd\n");
        return;
    }
    else if(n == 1)
    {
        printf("(Im not sure if * is a k)\n");
    }

    int row = (n+1)/2 ;

    for(int i = 0; i < n/2; i++)
    {
        printf("*");
        for(int j = 0; j < row-i-2; j++)
        {
            printf(" ");
        }
        printf("*\n");
    }
    printf("*\n");
    for(int i = 0; i < n/2; i++)
    {
        printf("*");
        for(int j = 0; j < i; j++)
        {
            printf(" ");
        }
        printf("*\n");
    }

    return;
}