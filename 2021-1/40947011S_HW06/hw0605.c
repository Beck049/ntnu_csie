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

#include "mymem.h"

int main()
{
    int size = 5;
    int** old = NULL;

    *old = (int*)malloc(sizeof(int)*5);

    for(int i = 0; i < 5; i++)
    {
        *old[i] = i*i;
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", *old[i]);
    }
    printf("\n\n");

    my_realloc( old, size, 10);

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", *old[i]);
    }
    printf("\n\n");
}