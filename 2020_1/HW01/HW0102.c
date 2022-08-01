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

int main()
{
    int32_t number, count = 0, sum = 0;

    printf("Please enter a 5-digit integer: ");
    scanf("%d",&number);

    while(number!=0)
    {
        sum += number % 10;
        number = number / 10;

        count++; // how many digits
    }

    if(count == 5)
    {
        printf("Too many digit.\n");
    }
    else
    {
        printf("Result: %d\n", sum);
    }

    return 0;
}
