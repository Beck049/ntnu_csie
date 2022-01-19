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

int main()
{
    double a, b, c, d;

    scanf("%lf %lf %lf %lf", &x11, &y11, &x22, &y22);

    set_line(x11, y11, x22, y22);

    printf("%d\n", flag);

    scanf("%lf %lf", &a, &b);

    get_mirror(a, b, &c, &d);

    printf("%lf, %lf\n", c, d);
    
    return 0;
}