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
	int row, col;
	char cc;
	
	printf("Please enter the width : ");
	scanf("%d",&col);
	scanf("%c",&cc);
	printf("Printf enter the height: ");
	scanf("%d",&row);
	
	if(col < 0 || row < 0)
	{
		printf("Please enter a positive number");
		return 0;
	}
	
	int *arr = (int*)malloc(row*col*sizeof(int));
	int rowtemp, coltemp;
	
	rowtemp = row-1;
	coltemp = col;
	
	int n = 0;     // number of array
	int count = 1; // value of array

	while(1)
	{

	//right	
		if(coltemp!=0 && rowtemp!=0)
		{
			for(int i = 0; i < coltemp; i++)
			{
				arr[n] = count;
				count++;
				n++;
			}
			n = n-1+col;
			coltemp--;
		}
		else if(coltemp==0 || rowtemp==0)
		{
			for(int i = 0; i < coltemp; i++)
			{
				arr[n] = count;
				count++;
				n++;
			}
			n = n-1+col;
			coltemp--;
			break;
		}
	//
	
	///down	
		if(coltemp!=0 && rowtemp!=0)
		{
			for(int i = 0; i < rowtemp; i++)
			{
				arr[n] = count;
				count++;
				n = n + col;
			}
			n = n-col-1;
			rowtemp--;
		}
		else if(coltemp==0 || rowtemp==0)
		{
			for(int i = 0; i < rowtemp; i++)
			{
				arr[n] = count;
				count++;
				n = n + col;
			}
			n = n-col-1;
			rowtemp--;
			break;
		}
	///

	////left
		if(coltemp!=0 && rowtemp!=0)
		{ 
			for(int i = 0; i < coltemp; i++)
			{
				arr[n] = count;
				count++;
				n--;
			}
			n = n+1-col;
			coltemp--;
		}
		else if(coltemp==0 || rowtemp==0)
		{
			for(int i = 0; i < coltemp; i++)
			{
				arr[n] = count;
				count++;
				n--;
			}
			n = n+1-col;
			coltemp--;
			break;
		}
	////
	
	/////up
		if(coltemp!=0 && rowtemp!=0)
		{
			for(int i = 0; i < rowtemp; i++)
			{
				arr[n] = count;
				count++;
				n = n - col;
			}
			n = n+col+1;
			rowtemp--;
		}
		else if(coltemp==0 || rowtemp==0)
		{
			for(int i = 0; i < rowtemp; i++)
			{
				arr[n] = count;
				count++;
				n = n - col;
			}
			n = n+col+1;
			rowtemp--;
			break;
		}
	/////
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
