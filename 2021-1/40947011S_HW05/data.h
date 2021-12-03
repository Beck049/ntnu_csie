#pragma once
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

#include "data.c"

// The arithmetic average.
double  get_mean  ( const int32_t input[], size_t size );
// The middle value.
double  get_median( const int32_t input[], size_t size );
// The number that occurs most frequently.
int32_t get_mode  ( const int32_t input[], size_t size );
// The standard deviation.
double  get_stddev( const int32_t input[], size_t size );