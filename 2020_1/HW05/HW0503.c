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


void print_poly( int*, int);
int add_poly  (int*, int*, int*, int, int);
int minus_poly(int*, int*, int*, int, int);
int times_poly(int*, int*, int*, int, int);

int main()
{
    int deg1, deg2;
// p1
    printf("Please enter the p1 degree: ");
    scanf("%d", &deg1);

    if(deg1 < 0)
    {   printf("ERROR");    return 0;   }

    int* p1 = (int*)malloc((deg1+1)*sizeof(int)); 
    printf("please enter p1 coefficients: ");
    for(int i = deg1; i >= 0; i--)
    {
        scanf("%d", &p1[i]);
    }
    // for(int i = deg1; i >= 0; i--){ printf("%d ", p1[i]);   }
// p2
    printf("\nPlease enter the p2 degree: ");
    scanf("%d", &deg2);

    if(deg2 < 0)
    {   printf("ERROR");    return 0;   }

    int* p2 = (int*)malloc((deg2+1)*sizeof(int)); 
    printf("please enter p2 coefficients: ");
    for(int i = deg2; i >= 0; i--)
    {
        scanf("%d", &p2[i]);
    }
    // for(int i = deg2; i >= 0; i--){  printf("%d ", p2[i]);   }
//
    printf("P1: ");
    print_poly(p1, deg1);
    printf("P2: ");
    print_poly(p2, deg2);

    int count = 0;

    if(deg1 > deg2){count = deg1;}
    else{count = deg2;}
    int* add = (int*)calloc((count+1),sizeof(int));
    printf("P1 + P2: ");
    add_poly(add, p1, p2, deg1, deg2);

    if(deg1 > deg2){count = deg1;}
    else{count = deg2;}
    int* minus = (int*)calloc((count+1),sizeof(int));
    printf("P1 - P2: ");
    minus_poly(minus, p1, p2, deg1, deg2);

    count = deg1*deg2;
    int*times = (int*)calloc((count+1),sizeof(int));
    printf("P1 * P2: ");
    times_poly(times, p1, p2, deg1, deg2);
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

void print_poly( int* p, int deg)
{
    for(int i = deg; i > 0; i--)
    {
        if(i == 1)
         {
            if(p[i] == 0)
            {}
            else if(p[i] == 1)
            {   printf("x ");    }
            else if(p[i] < 0)
            {   printf("(%d)x ", p[i]);  }
            else
            {   printf("%dx ", p[i]);    }

            printf("+ ");
        }
        else
        {
            if(p[i] == 0)
            {}
            else if(p[i] == 1)
            {   printf("x^%d ", i);    }
            else if(p[i] < 0)
            {   printf("(%d)x^%d ", p[i], i);  }
            else
            {   printf("%dx^%d ", p[i], i);    }

            printf("+ ");
        }
    }
    printf("%d\n",p[0]);
}