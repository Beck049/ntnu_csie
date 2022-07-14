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
    double v = 1, a = 2, t = 1;
    double s = 0;
    printf("v_0: "); scanf("%lf", &v);
    printf("a: ");   scanf("%lf", &a);
    printf("t: ");   scanf("%lf", &t);

    s = (v*t) + (a*t*t/2);
    printf("--> s = %.2lf\n", s);
}