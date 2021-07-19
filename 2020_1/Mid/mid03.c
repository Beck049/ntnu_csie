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
    printf("Gashapon\n");

    int g, ex;
    char cc;
    int total = 0;

    printf("Please enter the Gashapon number: ");
    scanf("%d", &g);
    scanf("%c", &cc);
    printf("Please enter the exchange number: ");
    scanf("%d", &ex);

    total += g;

    while(g >= ex)
    {
        g = g - ex + 1;
        total += 1;
    }

    printf("You can totally open %2d Gashapon balls.", total);
}