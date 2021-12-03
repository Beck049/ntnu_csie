#include <stdio.h> 
#include <math.h>            
#include <ctype.h>    
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>	
#include <time.h>

#include "poker.h"

int print(int8_t cards[])
{
    for(int i = 0; i < 13; i++)
    {
        int temp = cards[i];
        printf("%4d", temp);
    }
    printf("\n");

    return 0;
}

int print_all(int all[])
{
    for(int i = 0; i < 53; i++)
    {
        printf("%4d", all[i]);
        if(i%13 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}

int32_t big_two_sort( int8_t cards[] )
{
    int all[53] = {0};
    int length = 13;
// printf("%d\n", length);

    for(int i = 0; i < length; i++) // input & check input
    {
        int temp = cards[i];
        if(cards[i] > 52 || cards[i] <= 0) // invalid number
        {
            printf("Invalid Number\n");
            return -1;
        }

        all[temp]++;

        if(all[temp] >= 2) // duplicate number
        {
            printf("Duplicate Number\n");
            return -1;
        }
    }
// print_all(all);

    int count = 0;
    // spade
    for(int i = 2; i >= 1; i--)
    {
        if(all[i] == 1)
        {
            cards[count] = i;
            count++;
        }
    }
    for(int i = 13; i >= 3; i--)
    {
        if(all[i] == 1)
        {
            cards[count] = i;
            count++;
        }
    }
    // heart
    for(int i = 15; i >= 14; i--)
    {
        if(all[i] == 1)
        {
            cards[count] = i;
            count++;
        }
    }
    for(int i = 26; i >= 16; i--)
    {
        if(all[i] == 1)
        {
            cards[count] = i;
            count++;
        }
    }
    // diamond
    for(int i = 28; i >= 27; i--)
    {
        if(all[i] == 1)
        {
            cards[count] = i;
            count++;
        }
    }
    for(int i = 39; i >= 29; i--)
    {
        if(all[i] == 1)
        {
            cards[count] = i;
            count++;
        }
    }
    // leaf
    for(int i = 41; i >= 40; i--)
    {
        if(all[i] == 1)
        {
            cards[count] = i;
            count++;
        }
    }
    for(int i = 52; i >= 42; i--)
    {
        if(all[i] == 1)
        {
            cards[count] = i;
            count++;
        }
    }

    return 0;
}