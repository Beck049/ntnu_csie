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

#include "poker.h"

int8_t cards[13] = {51, 44, 32, 43, 33, 5, 25, 23, 12, 13, 6, 3, 1};

int main()
{
    if(big_two_sort(cards) < 0)
    {
        printf("invalid input\n");
        return 0;
    }

    print( cards );
    
    return 0;
}