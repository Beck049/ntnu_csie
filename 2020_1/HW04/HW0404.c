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
    int r,n;
    double ans;

    printf("Please enter the resistance (1-100) : ");
    scanf("%d",&r);
    printf("Please enter n (1-100) : ");
    scanf("%d",&n);

    if(r <= 0)
    {
        printf("resistance must between 1 and 100");
        return 0;
    }
    if(n <= 0)
    {
        printf("n must between 1 and 100");
        return 0;
    }

    double r1[2] = {1,1};
    double r2[2] = {1,1};
    double r3[2] = {r,1};

    for(int i = 1; i < n; i++)
    {
        r1[0] = r3[1];
        r1[1] = r3[1]+r3[0];
        r2[0] = r1[1];
        r2[1] = r1[1]+r1[0];
        r3[0] = r2[0];
        r3[1] = r2[1];
    }


    ans = ( r3[0]+r3[1] ) / r3[1];

    printf("Ans: %lf\n",ans);
  printf("Ans: %.0lf / %.0lf\n",r3[0]+r3[1],r3[1]);
}
