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

#include "frac.h"

int32_t gcd(int32_t a1, int32_t b1)
{
    int t = 0;
    int a = abs(a1);
    int b = abs(b1);
    while( b != 0 )
    {
        t = b;
        b = a%b;
        a = t;
    }
    return a;
}

int32_t frac_add ( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d )
{
    if(b == 0 || d == 0)
    { return -1; }

    int32_t tempx = 0, tempy = 0;
    tempx = a*d + b*c;
    tempy = b*d;

    if(tempy <  0){ tempy *= (-1);  tempx *= (-1); }
    if(tempx == 0){ tempy = 1; }

    *x = tempx / gcd(tempx, tempy);
    *y = tempy / gcd(tempx, tempy);

    return 0; 
}
int32_t frac_del ( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d )
{
    if(b == 0 || d == 0)
    { return -1; }

    int32_t tempx = 0, tempy = 0;
    tempx = a*d - b*c;
    tempy = b*d;

    if(tempy <  0){ tempy *= (-1);  tempx *= (-1); }
    if(tempx == 0){ tempy = 1; }

    *x = tempx / gcd(tempx, tempy);
    *y = tempy / gcd(tempx, tempy);

    return 0; 
}
int32_t frac_mul ( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d )
{
    if(b == 0 || d == 0)
    { return -1; }

    int32_t tempx = 0, tempy = 0;
    tempx = a*c;
    tempy = b*d;

    if(tempy <  0){ tempy *= (-1);  tempx *= (-1); }
    if(tempx == 0){ tempy = 1; }

    *x = tempx / gcd(tempx, tempy);
    *y = tempy / gcd(tempx, tempy);

    return 0; 
}
int32_t frac_div ( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d )
{
    if(b == 0 || d == 0 || c == 0)
    { return -1; }

    int32_t tempx = 0, tempy = 0;
    tempx = a*d;
    tempy = b*c;

    if(tempy <  0){ tempy *= (-1);  tempx *= (-1); }
    if(tempx == 0){ tempy = 1; }

    *x = tempx / gcd(tempx, tempy);
    *y = tempy / gcd(tempx, tempy);

    return 0; 
}