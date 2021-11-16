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
#include <float.h>

// 2.7182818284590452354

int main()
{
    int n = 0;
    printf("Please enter n : ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Please enter a positive number.\n");
        return 0;
    }

    int count = n;
    long double ans = 0.0L;

    for(int i = 0; i < count; i++)
    {
        if(ans != 0)
        {
            ans = 1.0L/ans;
        }
        ans += 2.0L*n;
        ans = 1.0L / ans;
        ans += 1.0L;
        ans = 1.0L / ans;
        ans += 1.0L;
        n--;
    }

    ans++;

    printf("Answer: %.19Lf\n", ans);
    return 0;
}