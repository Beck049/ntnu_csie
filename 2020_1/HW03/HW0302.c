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
    int num;

    printf("Please enter a natural number : ");
    scanf("%d", &num);

    while(num != 0)
    {
        printf("%d", num%10);
        num = num/10;
    }
}