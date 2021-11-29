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

void resistance(void)
{
    int r,n;
    double ans = 0;

    printf("Please enter the resistance (1-100) : ");
    scanf("%d",&r);

    if(r <= 0 || r > 100)
    {
        printf("resistance must between 1 and 100\n");
        return;
    }
    printf("Please enter n (1-100) : ");
    scanf("%d",&n);
    if(n <= 0 || r > 100)
    {
        printf("n must between 1 and 100\n");
        return;
    }

    // double r1[2] = {1,1};
    // double r2[2] = {1,1};
    // double r3[2] = {r,1};

    // for(int i = 1; i < n; i++)
    // {
    //     r1[0] = r3[1];
    //     r1[1] = r3[1]+r3[0];
    //     r2[0] = r1[1];
    //     r2[1] = r1[1]+r1[0];
    //     r3[0] = r2[0];
    //     r3[1] = r2[1];
    // }

    // ans = ( r3[0]+r3[1] ) / r3[1];

    for(int32_t i=1 ; i<=n ; i++)
    {
        if(i==1)
        {
            ans=r*2;
        }        
        else
        {
            ans= ((ans*r)/(ans+r))+r;
        }    
    }

    printf("Ans: %lf\n",ans);
// printf("Ans: %.0lf / %.0lf\n",r3[0]+r3[1],r3[1]);
    return;
}