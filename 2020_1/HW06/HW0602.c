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

void print_result(int*, int);

int main()
{
    int value = 1, rear = 0;
    int arr[10] = {0};
    int isUndo = 0;

    while(value != 0)
    {
        printf("input: ");
        scanf("%d", &value);

        if( value == -2 )
        {
            if(isUndo = 1)
            {
                rear++;
            }
            isUndo = 0;
        }
        else if( value == -1 )
        {
            rear--;
            isUndo = 1;
        }
        else if( value == 0 )
        {
            // exit //
        }
        else
        {
            arr[rear] = value;
            rear++;
            isUndo = 0;
        }
    }

    print_result(arr, rear);
}

void print_result(int* arr, int rear)
{
    printf("Result: ");
    for(int i = 0; i < rear; i++)
    {
        printf("%d ", arr[i]);
    }
}