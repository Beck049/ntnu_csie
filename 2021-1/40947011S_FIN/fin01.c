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
    // 輸入
    int x[6] = {0}, y[6] = {0};
    for(int i = 1; i < 6; i++)
    {
        printf("Please enter P%d: ", i);
        scanf("%d,%d", &x[i], &y[i]);
    }

    double px = 0, py = 0;
    px = (x[1] + x[2] + x[3] + x[4] + x[5]) / 5;
    py = (y[1] + y[2] + y[3] + y[4] + y[5]) / 5;

    // 判是否五角
    int flag = 0;
        // 三點共點
        for(int i = 1; i < 5; i++)
        {
            for(int j = i+1; j < 6; j++)
            {
                if(x[i] == x[j] && y[i] == y[j])
                {
                    flag = 1;
                    printf("This is not a pentagon\n");
                    return 0;
                }
            }
        }

        if(x[1] == x[5] && y[1] == y[5])
        {
            flag = 1;
            printf("This is not a pentagon\n");
            return 0;
        }
        // 三點共線
        // 找斜率
        int able[6] = {0};
        double slope[6] = {0};
        for(int i = 1; i < 6; i++)
        {
            if(x[i] == 0)
            {
                able[i] = 0;
            }
            else
            {
                able[i] = 1;
            }

            if(able[i] == 1)
            {
                slope[i] = y[i] / x[i];
            }
            else
            {
                slope[i] = 0;
            }
        }

        int count = 0;
        // 垂直
        for(int i = 1; i < 6; i++)
        {
            if(able[i] == 0)
            { count++; }
        }
        if(count >= 3)
        {
            printf("This is not a pentagon\n");
            return 0;
        }
        // !垂直
        count = 0;
        for(int i = 1; i < 4; i++)
        {
            if( able[i] == 1 )
            {
                for(int j = i+1; j < 6; j++)
                {
                    if( able[j] == 1 && slope[i] == slope[j])
                    {
                        count++;
                    }
                }
            }

            if(count >= 3)
            {
                printf("This is not a pentagon\n");
                return 0;
            }
        }

    if(flag == 0)
    {
        // 算面積
        double area = 0;
        double s = 0, a = 0, b = 0, c = 0;

        // for(int i = 1; i < 5; i++)
        // {
        //     x[i] -= px;
        //     y[i] -= py;
        // }

        for(int i = 1; i < 5; i++)
        {
            a = sqrt( (x[i]*x[i]) + (y[i]*y[i]) );
            b = sqrt( (x[i+1]*x[i+1]) + (y[i+1]*y[i+1]) );
            c = sqrt( ( (x[i] - x[i+1]) * (x[i] - x[i+1]) ) + ( (y[i] - y[i+1]) * (y[i] - y[i+1]) ) );
            s = ( a + b + c ) / 2;

            area += sqrt( s * (s-a) * (s-b) * (s-c) );
            // printf("a = %lf\tb = %lf\tc = %lf\ts = %lf\n", a, b, c, s);
            // printf("%d : %lf\n", i, sqrt( s * (s-a) * (s-b) * (s-c) ) );
        }

            a = sqrt( (x[5]*x[5]) + (y[5]*y[5]) );
            b = sqrt( (x[1]*x[1]) + (y[1]*y[1]) );
            c = sqrt( ( (x[5] - x[1]) * (x[5] - x[1]) ) + ( (y[5] - y[1]) * (y[5] - y[1]) ) );
            s = ( a + b + c ) / 2;

            area += sqrt( s * (s-a) * (s-b) * (s-c) );
            // printf("%d : %lf\n", 5, sqrt( s * (s-a) * (s-b) * (s-c) ) );
        
            printf("%lf\n", area);
    }

    return 0;
}