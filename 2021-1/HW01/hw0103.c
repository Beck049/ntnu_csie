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
    
    char hex[5] = {0};
    int len = 0;
    while(num!=0) {
        hex[len] = num%16;
        num /= 16;
        len++;
    }
    printf("  %d\n", len);

    num = 0;
    for(int i = 0; i < len; ++i) {
        num += hex[i] * pow(16, len-1-i);
        printf("%d\n", num);
    }

    printf("After  Flip:\n");
    printf("%d_10 = ", num);
    int i = 0; 
    while(hex[i] == 0) {
        i++;
    }
    for(i; i < len; i++) {
        if( 9 < hex[i] && hex[i] < 16 ) {
            printf("%c", 87+hex[i]);
        }
        else {
            printf("%d", hex[i]);
        }
    }
    printf("_16\n");
}

/*
Please enter an unsigned 16-bits number: 4660
Before Flip:
4660_10 = 1234_16
After  Flip:
17185_10 = 4321_16
*/