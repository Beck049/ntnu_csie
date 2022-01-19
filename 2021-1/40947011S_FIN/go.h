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

#include "go.c"

void print_table(int32_t table[19][19]);
void set_group( int32_t board[][19], int32_t visit[19][19], int32_t black[19][19], int i, int j, int32_t group );
int32_t max_black_chain( int32_t board[][19] );