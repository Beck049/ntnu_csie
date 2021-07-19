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
    int32_t a=0, b=0, c=0;
    int32_t judge;

    printf("Please enter a quadratic polynomial (a, b, c) : ");
    // ax^2 + bx + c  
    scanf("%d %d %d", &a, &b, &c);

    judge = (b * b) - (4 * a * c);

    if(judge < 0)
    {   printf("No real roots");    }
    else if(judge == 0)
    {   printf("One real root");    }
    else if(judge > 0)
    {   printf("Two distinct real roots");  }

    return 0;
}