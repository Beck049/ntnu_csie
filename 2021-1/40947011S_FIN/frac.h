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

#include "frac.c"

int32_t frac_add ( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d );
int32_t frac_del ( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d );
int32_t frac_mul ( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d );
int32_t frac_div ( int32_t *x, int32_t *y, int32_t a, int32_t b, int32_t c, int32_t d );