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
    int32_t num = 0;
    int32_t temp;
    int32_t output[8] = {0,0,0,0,0,0,0,0};
    // its a 32-bit integer, so there are only 8 digits in hex

    printf("Please enter an integer: ");
    scanf("%d", &num);

    printf("%d: ", num);

    //printf("%c", num);

    for(int i = 0; i < 8; i++)
    {
        temp = num % 16;
//      printf("%d  ",temp);
        if(temp < 10)
        {   
        // integer convert to character
            output[i] = temp + 48;
        }
        else if( temp > 9)
        {   
        // integer convert to character
            output[i] = temp + 'A' - 10;
        }
//      printf("%c\n", output[i]);
        num = num / 16;
    }

    for(int i = 7; i >= 0; i--)
    {
        printf("%c", output[i] );
    }

    // repete 8 times num still != 0
    if(num > 0)
    {
        printf("  (overflow)");
    }

    return 0;
}