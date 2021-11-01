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
    int num = 0;
    printf("Please enter an unsigned 16-bits number: ");
    scanf("%d", &num);
    
    printf("Before Flip:\n");
    printf("%d_10 = %x_16\n", num, num);

    int flip = 0, ans = 0;
    while(num != 0)
    {
        flip += num%16;
        num = num/16;
        flip *= 10;
    }
    flip /= 10;
// num  = 4660
// flip = 4321
    int i = 0;
    int flip1 = flip; // 4321
    while(flip1 != 0)
    {
        ans += pow(16, i) * (flip1 % 10);
        flip1 /= 10;
        i++;
    }
    

    printf("After  Flip:\n");
    printf("%d_10 = %d_16\n", ans, flip);
}

/*
Please enter an unsigned 16-bits number: 4660
Before Flip:
4660_10 = 1234_16
After  Flip:
17185_10 = 4321_16
*/