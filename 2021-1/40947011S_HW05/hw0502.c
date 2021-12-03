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

#include "data.h"

// const int32_t input[5] = {1, 3, 2, 4, 5}; 
// size_t size = 5;

const int32_t input[5] = {4, 4, 2, 2, 3}; 
size_t size = 5;

int main()
{
    printf("the mean   is %lf\n", get_mean(input, size));
    printf("the median is %lf\n", get_median(input, size));
    printf("the mode   is %d \n", get_mode(input, size));
    printf("the stddev is %lf\n", get_stddev(input, size));

    return 0;
}