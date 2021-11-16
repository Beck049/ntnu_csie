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
    int    count = 0;
    int    y = 0, sig_y = 0, sig_yy = 0; // y
    double t = 0; // x
    double avg_y = 0, avg_t = 0, sig_x = 0, sig_xx = 0, sig_xy = 0;

    while(y != -1)
    {
        printf("Please enter the year: "); scanf("%d", &y);
        if(y == -1)
        {
            break;
        }
        else if(y <= 1990 || y == (int)y )
        {
            printf("Please enter the valid year\n");
            return 0;
        }
        else
        {
            sig_y += y;
            sig_yy += y*y;
        }

        printf("Temperature: "); scanf("%lf", &t);
        if(t <= -273.15)
        {
            printf("Please enter the valid temperature\n");
            return 0; 
        }
        else
        {
            sig_x += t;
            sig_xx += t*t;
        }
        
        sig_xy += t*y;

        count++;
    }
// printf("Count: %d\n", count);
    if(count < 2)
    {
        printf("The amount of data is not enough to predict.\n");
        return 0;
    }

    avg_y = ((double)sig_y) / count;
    avg_t = sig_x / count;
// printf("average year = %lf\n", avg_y);
// printf("sigma y   = %d\n", sig_y);
// printf("sigma y^2 = %d\n", sig_yy);
// printf("average temp = %lf\n", avg_t);
// printf("sigma x   = %lf\n", sig_x);
// printf("sigma x^2 = %lf\n", sig_xx);
// printf("sigma xy  = %lf\n", sig_xy);

    double b = 0;
    double input = 0, output = 0 ;

    printf("Please enter the prediction year: "); scanf("%lf", &input);
    
// reduce y form
    // b =  ( sig_xy - (count*avg_y*avg_t) );
    // b /= ( sig_xx - (count*avg_t*avg_t) );
    // output = ( (input - avg_y) / b ) + avg_t;

// reduce x form
    b =  ( sig_xy - (count*avg_y*avg_t) );
    b /= ( sig_yy - (count*avg_y*avg_y) );
    output = ( (input - avg_y) * b ) + avg_t;

    printf("Temperature: %lf\n", output);

    return 0;
}