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

void* the_realloc ( void* ptr, size_t before, size_t after )
{
    if(after == 0)
    {
        free(ptr);
        return NULL;
    }
    else if(!ptr)
    {
        return malloc(after);
    }
    else if(after <= before)
    {
        return ptr;
    }
    else
    {
        assert((ptr) && (after > before));
        void *ptrNew = malloc(after);
        if (ptrNew)
        {
            memcpy(ptrNew, ptr, before);
            free(ptr);
        }
        return ptrNew;
    }
}

void my_realloc ( void **pptr, size_t before, size_t after )
{
    *pptr = the_realloc(*pptr, before, after);

    return;
}
