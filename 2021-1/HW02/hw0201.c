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
    double a, b, c;
    printf("Please enter a quadratic polynomial (a, b, c): ");
    scanf("%lf,%lf,%lf", &a, &b, &c);

    double ans;
    ans = (b*b) - (4*a*c);

    if(ans == 0)
    {
        printf("One real root.\n");
    }
    else if(ans > 0)
    {
        printf("Two distinct real roots.\n");
    }
    else
    {
        printf("No real roots.\n");
    }
}