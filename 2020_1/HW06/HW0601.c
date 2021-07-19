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


#define ASCII_ESC "\033"
#define RST ASCII_ESC"[0m"
#define RED ASCII_ESC"[31m"

void print_number(int*, int);
void print_char(int);

int main()
{
    int pos = 1;
    int value  = 0;
    int arr[8] = {0};

    printf("Please input an integer: ");
    scanf("%d", &value);
    if(value > 255 || value < 0) {  printf(RED"ERROR\n"RST);  }

    arr[pos-1] = value;

    for(int i = 0; i < 8; i++)
    {
        print_number(arr, i);
    }
    printf("\nPlease enter the position (1-8, 0: exit) : ");
    scanf("%d", &pos);
    if(value > 8 || value < 0) {  printf(RED"ERROR\n"RST);  }

    while(pos != 0)
    {
        printf("Please input new value (0-255): ");
        scanf("%d", &value);
        if(value > 255 || value < 0) {  printf(RED"ERROR\n"RST);  }

        arr[pos-1] = value;

        for(int i = 0; i < 8; i++)
        {
            print_number(arr, i);
        }
        printf("\nPlease enter the position (1-8, 0: exit) : ");
        scanf("%d", &pos);
        if(value > 8 || value < 0) {  printf(RED"ERROR\n"RST);  }
    }
}

void print_number(int* arr, int i)
{
    int temp = 0;

    printf("(%d) 0x", i+1);

    temp = arr[i] / 16;
    print_char(temp);

    temp = arr[i] % 16;
    print_char(temp);

    printf("  ");
}

void print_char(int value)
{
    if(value >= 0 && value <= 9)
    {
        printf("%d", value);
    }
    else if(value >= 10 && value <= 15)
    {
        printf("%c", 55+value);
    }
}