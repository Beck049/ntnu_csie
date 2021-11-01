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
    double eco[4] = {0, 3.4, 1.4, 1.1};
    double std[4] = {0, 3.8, 2.0, 1.2};
    double fst[4] = {0, 4.2, 2.3, 1.5};
    double ddl[4] = {0, 4.6, 2.6, 2.0};
    double num = 0, fee = 0;

    int buf1 = 0, buf2 = 0;

    printf("Word Count\n  Please enter the word count : ");
    scanf("%lf", &num);

    printf("Service Level\n  1) Advanced service\n  2) Standard service\n  3) Basic service\n  Your choice : ");
    scanf("%d", &buf1);

    printf("Delivery Time\n  1) Economic\n  2) Standard\n  3) Fast\n  4) Deadline\n  Your choice : ");
    scanf("%d", &buf2);

    if(buf2 == 1)
    {
        fee = num * eco[buf1];
    }
    else if(buf2 == 2)
    {
        fee = num * std[buf1];
    }
    else if(buf2 == 3)
    {
        fee = num * fst[buf1];
    }
    else if(buf2 == 4)
    {
        fee = num * ddl[buf1];
    }

    if(buf1 == 1)
    {
        if(num >= 2000)
        {
            fee *= 0.75;
        }
    }
    else if(buf1 == 2)
    {
        if(num >= 6000)
        {
            fee *= 0.9;
        }
    }
    else if(buf1 == 3)
    {
        if(num >= 6000)
        {
            fee *= 0.95;
        }
    }

    printf("Proofreading fee --> %.0lf", fee);
    return 0;
}