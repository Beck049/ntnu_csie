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

int split(int);
int split_ans(int);

int main()
{
    int a = 0, b = 0;
    printf("Please enter the first  number: ");
    scanf("%d", &a);
    printf("Please enter the second number: ");
    scanf("%d", &b);
    int c = a+b;

    printf("   "); split(a);
    printf("+) "); split(b);
    printf("--------\n");
    split_ans(c);
    
}
int split_ans(int a)
{
    if(a < 10)
    {
        printf("        %d", a);
    }
    else if(a < 100)
    {
        printf("      %d %d", a/10, a%10);
    }
    else if(a < 1000)
    {
        int t1, t2, t3;
        t1 = a/100;
        a %= 100;
        t2 = a/10;
        t3 = a%10;
        printf("   %d %d %d", t1, t2, t3);
    }
    else
    {
        int t1, t2, t3, t4;
        t1 = a/1000;
        a %= 1000;
        t2 = a/100;
        a %= 100;
        t3 = a/10;
        t4 = a%10;

        printf(" %d %d %d %d", t1, t2, t3, t4);
    }

    printf("\n");
}
int split(int a)
{
    if(a < 10)
    {
        printf("    %d", a);
    }
    else if(a < 100)
    {
        printf("  %d %d", a/10, a%10);
    }
    else if(a < 1000)
    {
        int t1, t2, t3;
        t1 = a/100;
        a %= 100;
        t2 = a/10;
        t3 = a%10;
        printf("%d %d %d", t1, t2, t3);
    }

    printf("\n");
}