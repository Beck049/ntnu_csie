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

#define e 2.71828182846
int main()
{
    int num;
    double ans = 1;

    printf("k-th order Taylor polynomial for e\nPlease enter k : ");
    scanf("%d",&num);

    if(num <= 0)
    {
        printf("ERROR");
        return 0;
    }
    
    for(int i = 1; i <= num; i++)
    {
        double temp;
        double pow = 1;
        /*for(int j = 0; j < i; j++)
        {
            pow = 1*num;
        }*/
        double fact = 1;
        for(int j = 1; j <= i; j++)
        {
            fact = fact*j;
        }
      //printf("%lf,%lf\n",pow,fact);
        temp = pow/fact;
        ans = ans + temp;
    }

    printf("%lf",ans);
    //printf("%lf/%lf",ans,e);
    return 0;
}
