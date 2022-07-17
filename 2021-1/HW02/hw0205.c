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
    int32_t n[14] = {0};
    int32_t hcp = 0, s = 0, h = 0, d = 0, c = 0;

    printf("1st card: ");     scanf("%d", &n[1]);
    printf("2nd card: ");     scanf("%d", &n[2]);
    printf("3rd card: ");     scanf("%d", &n[3]);
    printf("4th card: ");     scanf("%d", &n[4]);
    printf("5th card: ");     scanf("%d", &n[5]);
    printf("6ht card: ");     scanf("%d", &n[6]);
    printf("7th card: ");     scanf("%d", &n[7]);
    printf("8th card: ");     scanf("%d", &n[8]);
    printf("9th card: ");     scanf("%d", &n[9]);
    printf("10 th card: ");   scanf("%d", &n[10]);
    printf("11 th card: ");   scanf("%d", &n[11]);
    printf("12 th card: ");   scanf("%d", &n[12]);
    printf("13 th card: ");   scanf("%d", &n[13]);
    printf("---\n");

    for(int i = 1; i <= 13; i++)
    {
        if     ( n[i]/13 == 0 )   { s++; }
        else if( n[i]/13 == 1 )   { h++; }
        else if( n[i]/13 == 2 )   { d++; }
        else if( n[i]/13 == 3 )   { c++; }

        if     ( n[i]%13 == 1 )   {hcp += 4;}
        else if( n[i]%13 == 0 )   {hcp += 3;}
        else if( n[i]%13 == 12)   {hcp += 2;}
        else if( n[i]%13 == 11)   {hcp += 1;}
    }

    printf("HCP: %d pts\n", hcp);
    printf("Suit: %d-%d-%d-%d\n", s, h, d, c);
    printf("The bidding choice : ");

    if     (hcp >= 22)
    {
        printf("2C\n");
    }
    else if(hcp >= 13 && (s >= 5 || h >= 5) )
    {
        if(s >= h)
        {
            printf("1S\n");
        }
        else
        {
            printf("1H\n");
        }
    }
    else if(hcp <= 18 && hcp >= 16)
    {
        printf("1NT\n");
    }
    else if(hcp <= 21 && hcp >= 20)
    {
        printf("2NT\n");
    }
    else if(hcp >= 13 && (c >= 3 || d >= 3) )
    {
        if(d >= c)
        {
            printf("1D\n");
        }
        else
        {
            printf("1C\n");
        }
    }
    else if (hcp >= 10 && hcp <= 12 )
    {
        if     (s >= 7) { printf("3S\n"); }
        else if(h >= 7) { printf("3H\n"); }
        else if(d >= 7) { printf("3D\n"); }
        else if(c >= 7) { printf("3C\n"); }
        else if(s >= 6) { printf("2S\n"); }
        else if(h >= 6) { printf("2H\n"); }
        else if(d >= 6) { printf("2D\n"); }
    }
    else
    {
        printf("Pass\n");
    }

    return 0;
}