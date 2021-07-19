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

int32_t array[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int32_t array_size = 10;

int compare1(const void*, const void*); // small to big
int compare2(const void*, const void*); // big to small

int main()
{
    printf("Before:\n");
    for(int i = 0; i < array_size; i++)
    {
        printf("%d ",array[i]);
    }

    printf("\nAfter:\n");

    int32_t* odd = (int32_t*)malloc(array_size*sizeof(int32_t));
    int32_t* even = (int32_t*)malloc(array_size*sizeof(int32_t));
    int32_t odd_size = 0, even_size = 0;

    for(int i = 0; i < array_size; i++)
    {
        if( abs(array[i]) % 2 == 0 ) // even
        {
            even[even_size] = array[i];
            even_size++;
        }
        else // odd
        {
            odd[odd_size] = array[i];
            odd_size++;
        }
    }

    qsort(odd, odd_size, sizeof(int32_t), compare1);
    for(int i = 0; i < odd_size; i++)
    {
        printf("%d ",odd[i]);
    }
    
    qsort(even, even_size, sizeof(int32_t), compare2);
    for(int i = 0; i < even_size; i++)
    {
        printf("%d ",even[i]);
    }
}

// small to big
int compare1(const void* a, const void* b)
{
    return ( *(int*)a - *(int*)b );
}

// big to small
int compare2(const void* a, const void* b)
{
    return ( *(int*)b - *(int*)a );
}