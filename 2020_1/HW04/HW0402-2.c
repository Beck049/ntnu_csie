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

#define N 1048576
int ni[N], ac[N];
int main() {
    int n, i, j, k;
    printf("Please enter the disk number (2-20) :");
    while(scanf("%d", &n) == 1) 
	{
        ni[0] = 1, ac[0] = 1;
        int len = 1;
        int g[6] = {1,0,4,5,2,3};
        int v[6] = {3,2,5,4,0,1};
        for(i = 2; i <= n; i++) 
		{
            ni[len] = i, ac[len] = 1;
            for(j = 0; j < len; j++)
            {
                ni[j+len+1] = ni[j], ac[j] = g[ac[j]];
        	}
			len = len*2+1;
            for(k = 0, j++; j < len; j++, k++)
            {
			    ac[j] = v[ac[k]];
    		}
		}
        for(i = 0; i < len; i++) 
		{
            int A, C;
            if(ac[i] == 0) 
			{
				A = 0, C = 1;
            }
			else if(ac[i] == 1) 
			{
				A = 0, C = 2;
            }
			else if(ac[i] == 2) 
			{
				A = 1, C = 0;
            }
			else if(ac[i] == 3) 
			{
				A = 1, C = 2;
            }
			else if(ac[i] == 4) 
			{
				A = 2, C = 0;
            }
			else if(ac[i] == 5) 
			{
				A = 2, C = 1;
        	}
        	
            int CH;

			if(C==0)
			{
				CH = 1;
			}
			else if(C==1)
			{
				CH = 3;
			}
			else if(C==2)
			{
				CH = 2;
			}
			
            printf("Move disk %d to %d\n", ni[i], CH);
        }
    }
    return 0;
}

