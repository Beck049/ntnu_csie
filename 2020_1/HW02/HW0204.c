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

int leap( int ); // leap year or not (Y/N)(1/0)
int range( int, int, int); // set the year  range between 1900 - 9999
                           //         month range between 1 - 12
                           //         date  range between 1 - 31
int check( int, int, int); // check if date is available
int month( int, int);      // the total days in each month

int main()
{
    int y1, y2, m1, m2, d1, d2;
    int s1 = 0, s2 = 0;
    int d; //duration 

    printf("Date Format: YYYY/MM/DD\n");

    printf("Start  Date:");
    scanf("%d/%d/%d", &y1, &m1, &d1);
    if(check(y1, m1, d1) == 1)
    {   printf("ERROR");    return 0;   }
// printf("%04d/%02d/%02d\n",y1, m1, d1);
    printf("End    Date:");
    scanf("%d/%d/%d", &y2, &m2, &d2);
// printf("%04d/%02d/%02d\n",y2, m2, d2);
    if(check(y2, m2, d2) == 1)
    {   printf("ERROR");    return 0;   }

    for(int i = 1900; i < y1; i++)
    {
        if(leap(i) == 1)
        {  s1 += 366; }
        else
        {  s1 += 365; }
    }
    for(int i = 0; i < m1; i++)
    {
        s1 += month(y1, i);
    }
    s1 += d1;
// printf("%d\n", s1);
    for(int i = 1900; i < y2; i++)
    {
        if(leap(i) == 1)
        {  s2 += 366; }
        else
        {  s2 += 365; }
    }
    for(int i = 0; i < m2; i++)
    {
        s2 += month(y2, i);
    }
    s2 += d2;
// printf("%d\n", s2);


    d = s2 - s1;

    printf("Duration: %d",d);
}

int leap(int y)
{
    if(y % 400 == 0)
    {   return 1;  }
    else if(y % 100 == 0)
    {   return 0;  }
    else if(y % 4 == 0)
    {   return 1;  }
    else
    {   return 0;  }
}

int range(int y, int m, int d)
{
    if(y < 1900 && y > 9999)
    {   printf("ERROR");    return 1;   }
    if(m < 1 && m > 12)
    {   printf("ERROR");    return 1;   }
    if(d < 1 && d > 31)
    {   printf("ERROR");    return 1;   }

    return 0;
}

int check(int y, int m, int d)
{
    // overall check
    if(range(y,m,d) == 1)
    {   printf("ERROR");    return 1;   }

    // check february days
    if(leap(y) == 1)
    {
        if(m == 2 && d > 29)
        {   printf("ERROR");    return 1;   }
    }
    else
    {
        if(m == 2 && d > 28)
        {   printf("ERROR");    return 1;   }
    }

    // check other month's days
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        if(d > 31) {    printf("ERROR");    return 1;   }
    }
    else if(m == 4 || m == 6 || m == 9 || m == 11)
    {
        if(d > 30) {    printf("ERROR");    return 1;   }
    }

    return 0;
}

// days for each months
int month(int y, int m)
{
    if(m == 1)
    {   return 30;  }
    if(m == 2)
    {
        if(leap(y) == 1)
        {   return 29;  }
        else
        {   return 28;  }
    }
    if(m == 3)
    {   return 31;  }
    if(m == 4)
    {   return 30;  }
    if(m == 5)
    {   return 31;  }
    if(m == 6)
    {   return 30;  }
    if(m == 7)
    {   return 31;  }
    if(m == 8)
    {   return 31;  }
    if(m == 9)
    {   return 30;  }
    if(m == 10)
    {   return 31;  }
    if(m == 11)
    {   return 30;  }
    if(m == 12)
    {   return 31;  }

    return 0;
}