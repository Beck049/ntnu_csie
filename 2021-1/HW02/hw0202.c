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

int check(int32_t, int32_t, int32_t, int32_t);

int main()
{
    int32_t x1, x2, y1, y2;
    printf("First point (x,y) :");
    scanf("%ld, %ld", &x1, &y1);

    printf("Second point (x,y):");
    scanf("%ld, %ld", &x2, &y2);

    if( check(x1, x2, y1, y2) == 1 )
    {
        printf("Error\nInput should not be vertical or horizontal line\n");
        return 0;
    }

    int64_t p = 0, a = 0;
    int32_t l = 0, w = 0;

    l = abs(x1-x2);
    w = abs(y1-y2);

    p = l + w;
    p *= 2;

    a = l * w;

    printf("Perimeter --> %ld\n", p);
    printf("Area --> %ld\n", a);

    return 0;
}

int check(int32_t x1, int32_t x2, int32_t y1, int32_t y2)
{
    if(x1 == x2)
    {
        return 1;
    }
    else if(y2 == y1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}