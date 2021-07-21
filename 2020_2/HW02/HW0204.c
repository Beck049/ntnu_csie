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

// COMBINE

int combine(int n, int k);

int main()
{
    int n, k;
    int result;
    printf("Please enter (n, k) :");
    scanf("%d, %d", &n, &k);

    result = combine(n, k);

    printf("%d\n", result);
}

int combine(int n, int k)
{
    if(n == 0 && k == 0)
    {   return 1;   }
    else if(n == 1 && k == 0)
    {   return 1;   }
    else if(n == 0 && k == 1)
    {   return 1;   }
    else if(n == 0)
    {   return 0;   }
    else if(k == 0)
    {   return 1;   }
    else if(n == 1 && k == 1)
    {   return 1;   }
    else if(k == 1)
    {   return n;   }
    else if( k == n)
    {   return 1;   }
    else
    {
        return combine(n-1, k-1) + combine(n-1, k);
    }
}