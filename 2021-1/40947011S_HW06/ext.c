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

uint32_t f( uint32_t a, uint32_t b )
{ 
    if( b==0 )
        return a;
    return f( b, a%b );
}

int32_t ext_euclidean( uint32_t a, uint32_t b, uint32_t *c )
{
    // *c = a+b;
    if(a < b)
    {
        return -1;
    }
    else
    {
        if( f(a, b) == 1 )
        {
            uint32_t rem = 1, ans = 1;
            for(ans = 1; ;ans++)
            {
                if( (b*ans)%a == rem )
                {
                    break;
                }
            }
            *c = ans;
            return 1;
        }
        else
        {
            *c = f(a, b);
            return 0;
        }
    }
}