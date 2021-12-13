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

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

// The arithmetic average.
double  get_mean  ( const int32_t input[], size_t size )
{
    double mean = 0;

    for(int i = 0; i < size; i++)
    {
        mean += input[i];
    }

    return mean/size;
}
// The middle value.
double get_median( const int32_t inputs[], size_t size )
{
    double med = 0;
    int32_t *input = (int32_t*)malloc(size*sizeof(int32_t));
    for(int i = 0; i < size; i++)
    {
        input[i] = inputs[i];
    }
    qsort( input, size, sizeof(int), compare );

    if(size %2 == 1)
    {
        med = input[size/2];
    }
    else if(size %2 == 0)
    {
        med = input[size/2] + input[(size/2)-1];
        med /= 2;
    }

    return med;
}
// The number that occurs most frequently.
int32_t get_mode  ( const int32_t input[], size_t size )
{
    int32_t cnt =0,old_cnt =0;
    int32_t mode=0,old_mode=0;
    for( int32_t i=0 ; i<size ; ++i)
    {
        cnt=1;
        mode=input[i];
        for( int32_t y=i+1 ; y<size ; ++y )
        {
            if(input[i]==input[y])cnt++;
        }
        if(cnt>=old_cnt)
        {
            old_cnt=cnt  ;
            old_mode=mode;
        }
    }
    return old_mode;
}
int32_t get_mode_old  ( const int32_t inputs[], size_t size )
{
    int32_t mod = 0, count = 0, buff = 0;
    int32_t *input = (int32_t*)malloc(size*sizeof(int32_t));
    for(int i = 0; i < size; i++)
    {
        input[i] = inputs[i];
    }
    qsort( input, size, sizeof(int), compare );

    for(int i = 1; i <= size; i++)
    {
        if(input[i-1] == input[i])
        {
            count++;
        }
        else
        {
            buff = count;
            count = 1;
        }

        if(count >= buff)
        {
            mod = input[i];
        }
    }

    return mod;
}
// The standard deviation.
double  get_stddev( const int32_t input[], size_t size )
{
    double std = 0;
    double sum_xx = 0;

    for(int i = 0; i < size; i++)
    {
        sum_xx += input[i] * input[i];
    }

    std = (sum_xx/size) - (get_mean(input, size)*get_mean(input, size));

    std = sqrt(std);

    return std;
}