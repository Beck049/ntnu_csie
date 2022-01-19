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
int  get_number(int* arr);

int main()
{
    int pos = 1;
    int64_t value  = 0;
    int arr[8] = {0};

    printf("Please input an integer: ");
    scanf("%ld", &value);
    // if(value > 255 || value < 0) {  printf(RED"ERROR\n"RST);  }

    for(int i = 7; i >= 0; i--)
    {
        arr[i] = value % 256;
        value /= 256;

        if(value == 0)
        {
            break;
        }
    }

    get_number(arr); 
    for(int i = 0; i < 8; i++)
    {
        print_number(arr, i);
    }
    printf("\nPlease enter the position (1-8, 0: exit) : ");
    scanf("%d", &pos);
    if(pos > 8 || pos < 0) {  printf(RED"ERROR\n"RST);  }

    while(pos != 0)
    {
        printf("Please input new value (0-255): ");
        scanf("%ld", &value);
        if(value > 255 || value < 0) {  printf(RED"ERROR\n"RST);  }

        arr[pos-1] = value;

        printf("---\n");
        get_number(arr);
        for(int i = 0; i < 8; i++)
        {
            print_number(arr, i);
        }
        printf("\nPlease enter the position (1-8, 0: exit) : ");
        scanf("%d", &pos);
        if(pos > 8 || pos <= -1) {  printf(RED"ERROR\n"RST);  }
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

int get_number_new(int* arr)
{
    uint64_t ans = 0;
    ans += arr[0] * 72057594037927236;
    ans += arr[1] *   281474976710656;
    ans += arr[2] *     1099511627776;
    ans += arr[3] *        4294967296;
    ans += arr[4] *          16777216;
    ans += arr[5] *             65536;
    ans += arr[6] *               256;
    ans += arr[7] *                 1;

    printf("The integer: %ld\n", ans);

    return 0;
}

int get_number(int* arr)
{
    int32_t ans_1 = 0, ans_2 = 0, ans_3 = 0, ans_4 = 0;

    ans_4 += arr[7] * 1;
    
    ans_4 += arr[6] * 256;
    ans_3 += ans_4 / 100000;
    ans_4  = ans_4 % 100000;

    ans_4 += arr[5] *  65536;
    ans_3 += ans_4  / 100000;
    ans_4  = ans_4  % 100000;

    ans_4 += arr[4] *  77216;
    ans_3 += ans_4  / 100000;
    ans_4  = ans_4  % 100000;
    ans_3 += arr[4] *    167;
    ans_2 += ans_3  / 100000;
    ans_3  = ans_3  % 100000;

    ans_4 += arr[3] *  67296;
    ans_3 += ans_4  / 100000;
    ans_4  = ans_4  % 100000;
    ans_3 += arr[3] *  42949;
    ans_2 += ans_3  / 100000;
    ans_3  = ans_3  % 100000;

    ans_4 += arr[2] *  27776;
    ans_3 += ans_4  / 100000;
    ans_4  = ans_4  % 100000;
    ans_3 += arr[2] *  95116;
    ans_2 += ans_3  / 100000;
    ans_3  = ans_3  % 100000;
    ans_2 += arr[2] *    109;
    ans_1 += ans_2  / 100000;
    ans_2  = ans_2  % 100000;

    ans_4 += arr[1] *  10656;
    ans_3 += ans_4  / 100000;
    ans_4  = ans_4  % 100000;
    ans_3 += arr[1] *  49767;
    ans_2 += ans_3  / 100000;
    ans_3  = ans_3  % 100000;
    ans_2 += arr[1] *  28147;
    ans_1 += ans_2  / 100000;
    ans_2  = ans_2  % 100000;

    ans_4 += arr[0] *  27936;
    ans_3 += ans_4  / 100000;
    ans_4  = ans_4  % 100000;
    ans_3 += arr[0] *  40379;
    ans_2 += ans_3  / 100000;
    ans_3  = ans_3  % 100000;
    ans_2 += arr[0] *   5759;
    ans_1 += ans_2  / 100000;
    ans_2  = ans_2  % 100000;
    ans_1 += arr[0] *     72;

    int flag[5] = {0};

    printf("The integer: ");
    if(ans_1 != 0)
    {
        printf("%d", ans_1);
        flag[1] = 1;
    }
    if(ans_2 != 0)
    { 
        if(flag[1] == 1)
        { printf("%05d", ans_2); }
        else
        { printf("%d"  , ans_2); } 
        flag[2] = 1;
    }
    if(ans_3 != 0)
    { 
        if(flag[2] == 1)
        { printf("%05d", ans_3); }
        else
        { printf("%d"  , ans_3); }
        flag[3] = 1;
    }
    if(flag[3] == 1)
    { printf("%05d", ans_4); }
    else
    { printf("%d"  , ans_4); }
    printf("\n");

    return 0;
}