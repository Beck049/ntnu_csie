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

#include "mirror.h"

int flag = 0;
double x11, x22, y11, y22;

void set_line(double x1, double y1, double x2, double y2)
{
    int slope = 0;
    if( x1 == x2 && y1 == y2 )
    {
        flag = 0;
        return;
    }
    else
    {
        flag = 1;
    }

    return;
}

int32_t get_mirror(double a, double b, double *c, double *d)
{
    if(flag == 0)
    {
        return -1;
    }

    if( (x11-x22) == 0 )
    {
        *c = (2*x11) - a;
        *d = b;
    }
    else
    {
        double slope = 0, con = 0;
        slope = (y11-y22) / (x11-x22) ;
        con = y11 - (slope * x11) ;

        double temp1 = 0, temp2 = 0;

        temp1 = a - ( 2*slope*(slope*a - b + con) / (slope*slope + 1) );
        *c = temp1;
        temp2 = b - ( 2*(-1) *(slope*a - b + con) / (slope*slope + 1) );
        *d = temp2;
    }

    return 0;
}

int32_t try(double a, double b, double *c, double *d)
{
    *c = a;
    *d = b;

    printf("%lf, %lf\n", *c, *d);

    return 0;
}