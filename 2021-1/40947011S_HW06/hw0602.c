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

#include "ext.h"

int main()
{
    uint32_t a, b, c;
    scanf("%d %d", &a, &b);

    printf("%d\n", ext_euclidean(a, b, &c) );

    printf("%d\n", c);
}