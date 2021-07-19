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

int time = 0;

void hanoi(int n, char a, char b, char c)
{
    if(n == 1)
    {
        printf("move disk %d to rod %c \n",n,c);
    }
    else
    {
        hanoi(n-1, a, c, b);
        printf("move disk %d to rod %c\n", n, c);
        hanoi(n-1, b, a, c);
    }
}

int main()
{
    int n;

    printf("Please enter the disk number (2-20) : ");
    scanf("%d",&n);

    if(n > 20 || n <= 0)
    {
        printf("n must between 2 and 20");
        return 0;
    }

    hanoi(n,'1','3','2');

    return 0;
}
