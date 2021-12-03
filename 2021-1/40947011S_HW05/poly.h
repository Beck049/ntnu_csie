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

#include "poly.c"

void print_poly( int*, int);
int add_poly  (int*, int*, int*, int, int);
int minus_poly(int*, int*, int*, int, int);
int times_poly(int*, int*, int*, int, int);