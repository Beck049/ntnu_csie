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

 int8_t cards[13] = {30, 18, 10, 13, 22, 1, 43, 48, 49, 36, 46, 42, 34};
// int8_t cards[13] = {41, 23, 25, 37, 51, 34, 42, 2, 16, 31, 50, 5, 43};
// int8_t cards[13] = {41, 23, 25, 37, 51, 34, 42, 2, 16, 41, 50, 5, 43};

int main()
{
    if(big_two_sort_2(cards) < 0)
    {
        printf("Error\n");
        return 0;
    }

    print( cards );
    
    return 0;
}