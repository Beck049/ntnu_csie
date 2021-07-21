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

int value(char*, int);
int hex  (char*, int);

int main()
{
    char str[64] = {0};
    int temp = 0;
    printf("Please enter the hex string: ");
    gets(str);
    int len = strlen(str);

    int i = 0;
    for(int j = 0; j < len/2; j++)
    {
        temp = value(str, i);

        printf("%c", temp);
        i += 2;
    }

    // puts(str);
    return 0;
}

int value(char* str, int i)
{
    int k = 0;

    k = hex(str, i)*16 + hex(str, i+1);

    return k;
}

int hex(char* str, int i)
{
    int k = 0;
    if(str[i] > 47 && str[i] < 58)
    {
        k = str[i] - 48;
        return k;
    }
    else if(str[i] > 64 && str[i] < 71)
    {
        k = str[i] - 55;
        return k;
    }
    else if(str[i] > 96 && str[i] < 103)
    {
        k = str[i] - 87;
        return k;
    }
    else
    {
        return -1;
    }
}