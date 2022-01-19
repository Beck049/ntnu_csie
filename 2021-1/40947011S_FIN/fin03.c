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

int main()
{
    int32_t x = 0, y = 0;
    int32_t a, b, c, d;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    // test(&x, &y, a, b, c, d);
    // printf("%d / %d\n", x, y);

    printf("add:\n");
    if(frac_add(&x, &y, a, b, c, d) == -1)
    { printf("Invalid\n"); }
    else
    { printf("%d / %d\n", x, y); }

    printf("del:\n");
    if(frac_del(&x, &y, a, b, c, d) == -1)
    { printf("Invalid\n"); }
    else
    { printf("%d / %d\n", x, y); }

    printf("mul:\n");
    if(frac_mul(&x, &y, a, b, c, d) == -1)
    { printf("Invalid\n"); }
    else
    { printf("%d / %d\n", x, y); }

    printf("div:\n");
    if(frac_div(&x, &y, a, b, c, d) == -1)
    { printf("Invalid\n"); }
    else
    { printf("%d / %d\n", x, y); }

    return 0;
}