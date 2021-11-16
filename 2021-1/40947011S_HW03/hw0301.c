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
    int row = 0, col = 0;
    char cc;

    printf("Please enter the width :"); scanf("%d", &col );
    scanf("%c", &cc);
    printf("Please enter the height:"); scanf("%d", &row);

    if(row < 0 || col < 0)
    {
        printf("Please enter two positive number\n");
        return 0;
    }
    else if(row == 0 || col == 0)
    {
        printf("Nothing will be printed.\n");
        return 0;
    }

    int *arr = (int*)malloc(row*col*sizeof(int));
	int rowtemp, coltemp, n = 0, count = 1;

    rowtemp = row;
	coltemp = col-1;

    while (1)
    {
	// down
        for(int i = 0; i < rowtemp; i++)
        {
            arr[n] = count;
            count++;
            n += col;
        }
        n = n - col + 1;
        
        if(coltemp == 0 || rowtemp == 0){ break; }
        rowtemp--;
    // right
        for(int i = 0; i < coltemp; i++)
        {
            arr[n] = count;
            count++;
            n++;
        }
        n = n - 1 - col;

        if(coltemp == 0 || rowtemp == 0){ break; }
        coltemp--;
    // up
        for(int i = 0; i < rowtemp; i++)
        {
            arr[n] = count;
            count++;
            n -= col;
        }
        n = n + col - 1;

        if(coltemp == 0 || rowtemp == 0){ break; }
        rowtemp--;
    // left
        for(int i = 0; i < coltemp; i++)
        {
            arr[n] = count;
            count++;
            n--;
        }
        n = n + 1 + col;

        if(coltemp == 0 || rowtemp == 0){ break; }
        coltemp--;
    }
    
    // print
	for(int i = 0; i < row*col; i++)
	{
		printf("%8d",arr[i]);
		
		if(i%col == col-1)
		{
			printf("\n");
		}
	}
    //
    free(arr);
    return 0;
}