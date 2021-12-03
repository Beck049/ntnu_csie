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

#include "poly.h"

void print_poly( int* p, int deg)
{
    for(int i = deg; i > 0; i--)
    {
        if(i == 1)
         {
            if(p[i] == 0)
            {}
            else if(p[i] == 1)
            {   printf("x + ");    }
            else if(p[i] < 0)
            {   printf("(%d)x + ", p[i]);  }
            else
            {   printf("%dx + ", p[i]);    }
        }
        else
        {
            if(p[i] == 0)
            {}
            else if(p[i] == 1)
            {   printf("x^%d + ", i);    }
            else if(p[i] < 0)
            {   printf("(%d)x^%d + ", p[i], i);  }
            else
            {   printf("%dx^%d + ", p[i], i);    }
        }
    }
    printf("%d\n",p[0]);
}

int add_poly  (int* add, int* p1, int* p2, int deg1, int deg2)
{
    if(deg1 > deg2)
    {
        for(int i = 0; i <= deg1; i++)
        {
            add[i] += p1[i];
        }
        for(int i = 0; i <= deg2; i++)
        {
            add[i] += p2[i];
        }

        print_poly(add, deg1);
    }
    else
    {
        for(int i = 0; i <= deg2; i++)
        {
            add[i] += p2[i];
        }
        for(int i = 0; i <= deg1; i++)
        {
            add[i] += p1[i];
        }

        print_poly(add, deg2);
    }

}

int minus_poly(int* minus, int* p1, int* p2, int deg1, int deg2)
{
    if(deg1 > deg2)
    {
        for(int i = 0; i <= deg1; i++)
        {
            minus[i] += p1[i];
        }
        for(int i = 0; i <= deg2; i++)
        {
            minus[i] -= p2[i];
        }

        print_poly(minus, deg1);
    }
    else
    {
        for(int i = 0; i <= deg2; i++)
        {
            minus[i] -= p2[i];
        }
        for(int i = 0; i <= deg1; i++)
        {
            minus[i] += p1[i];
        }

        print_poly(minus, deg2);
    }
}

int times_poly(int* times, int* p1, int* p2, int deg1, int deg2)
{
    int count = deg1 * deg2;
    for(int i = 0; i <= deg1; i++)
    {
        for(int j = 0; j <= deg2; j++)
        {
            times[i+j] += p1[i] * p2[j];
        }
    }

    print_poly(times ,count);
}