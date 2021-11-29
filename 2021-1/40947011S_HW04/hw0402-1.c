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

#include "func02.h"

int main()
{
    int n;

    printf("Please enter the disk number (2-20) : ");
    scanf("%d",&n);

    recursive_hanoi(n,'1','3','2');

    return 0;
}