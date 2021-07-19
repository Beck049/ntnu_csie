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
    int y1 = 0, y2 = 0, y3 = 0, y4 = 0;
    int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
    double a1, b1;
    double a2, b2;
    double x, y;
    char cc;

    printf("Please enter the first  line: ");
    scanf("(%d,%d),(%d,%d)", &x1, &y1, &x2, &y2);
    // (x2 - x1) * (Y - y1) = (X - x1) * (y2 - y1) 

	scanf("%c",&cc);

    printf("Please enter the sceond line: ");
    scanf("(%d,%d),(%d,%d)", &x3, &y3, &x4, &y4);
    // (x4 - x3) * (Y - y3) = (X - x3) * (y4 - y3) 

    // Y = aX + b
    a1 = (y2 - y1) / (x2 - x1);
    b1 = (x1 * (y1-y2)) + (y1 * (x2 - x1));
    b1 /= (x2 - x1);
    
    // Y = aX + b
    a2 = (y4 - y3) / (x4 - x3);
    b2 = (x3 * (y3-y4)) + (y3 * (x4 - x3));
    b2 /= (x4 - x3);

    if(a1 == a2) // 平行 or 重合 (斜率相同)
    {   printf("No intersection!"); return 0;   }

    x = (b2 - b1) / (a1 - a2);

    y = (a1 * x) + b1;

    printf("%.2lf, %.2lf", x, y);
}