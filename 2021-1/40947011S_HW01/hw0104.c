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
    float v = 1, a = 2, t = 1;
    float s = 0;
    printf("v_0: "); scanf("%f", &v);
    printf("a: ");   scanf("%f", &a);
    printf("t: ");   scanf("%f", &t);

    s = (v*t) + (a*t*t/2);
    printf("--> s = %f", s);
}