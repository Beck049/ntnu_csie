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

/*
multiply
divide
combine
*/
int  set  (int*);
void print(int*, int);

int compare(int*, int*, int, int);

int addition (int*, int, int*, int, int*, int);
int substract(int*, int, int*, int, int*, int);
int multiply (int*, int, int*, int, int*, int);
int devide   (int*, int, int*, int, int*, int);

int main()
{
    int num1[20] = {0};
    int num2[20] = {0};
    int len1, len2;

    len1 = set(num1);
    len2 = set(num2);

    print(num1, len1);
    printf("\n");
    print(num2, len2);
    printf("\n");
    int big_len = 0;
    num1>=num2?num1:num2;
/*
    compare(num1, num2, len1, len2);
*/
/*
    int len_a = big_len+1;
    int *add = (int*)calloc(len_a,sizeof(int));
    len_a = addition(add, len_a, num1, len1, num2, len2);
    printf("\n");
*/
/*   
    int len_s = big_len+1;
    int *sub = (int*)calloc(len_s,sizeof(int));
    len_s = substract(sub, len_s, num1, len1, num2, len2);
    printf("\n");
*/
    int len_m = len1 + len2;
    int *mul = (int*)calloc(len_m,sizeof(int));
    len_m = multiply(mul, len_m, num1, len1, num2, len2);
    printf("\n");

    
    int len_d = len1 + len2;
    int *div = (int*)calloc(len_d,sizeof(int));
    len_d = devide(div, len_d, num1, len1, num2, len2);
    printf("\n");

    return 0;
}
int devide(int* div, int len_d, int* num1, int len1, int* num2, int len2)
{
    
}
int multiply(int* mul, int len_m, int* num1, int len1, int* num2, int len2)
{
    for(int i = 0; i < len1; i++)
    {
        for(int j = 0; j < len2; j++)
        {
            mul[i+j] = num1[i]*num2[j];
        }
    }
    for(int i = 0; i < len_m; i++)
    {
        mul[i+1] += mul[i] / 10;
        mul[i] = mul[i] % 10;
    }

    int count = 0;
    for(int i = 0; i < len_m-1; i++)
    {
        if(mul[len_m-2-i] == 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    len_m = len_m-1-count;
    // printf("%d\n", count);
    print(mul, len_m);

    return len_m;
}
int substract(int* sub, int len_s, int* num1, int len1, int* num2, int len2)
{
    for(int i = 0; i < len_s-1; i++)
    {
        sub[i] = num1[i] - num2[i];
    }

    for(int i = 0; i < len_s-1; i++)
    {
        if(sub[i] < 0)
        {
            sub[i+1] -= 1;
            sub[i] += 10;
        }
    }

    if(sub[len_s-1] == -1)
    {
        for(int i = 0; i < len_s-1; i++)
        {
            sub[len_s-1-i]--;
            sub[len_s-2-i] = 10 - sub[len_s-2-i];
        }
    }

    int count = 0;
    for(int i = 0; i < len_s-1; i++)
    {
        if(sub[len_s-2-i] == 0)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    len_s = len_s-1-count;
    // printf("%d\n", count);
    print(sub, len_s);

    return len_s;
}
int addition(int* add, int len_a, int* num1, int len1, int* num2, int len2)
{
    for(int i = 0; i < len_a; i++)
    {
        add[i] = num1[i] + num2[i];
    }

    for(int i = 0; i < len_a; i++)
    {
        add[i+1] += add[i] / 10;
        add[i]   = add[i] % 10;
    }

    if(add[len_a-1] != 0)
    {
        print(add, len_a);
        return len_a;
    }
    else
    {
        len_a--;
        print(add, len_a);
        return len_a;
    }
}
int compare(int* num1, int* num2, int len1, int len2)
{
    if(len1 > len2)
    {
        print(num1,len1);
        printf(" is a bigger number\n");
        return 1;
    }
    else if(len1 < len2)
    {
        print(num2,len2);
        printf(" is a bigger number\n");
        return 2;
    }
    else if(len1 == len2)
    {
        for(int i = len1-1; i >= 0; i--)
        {
            // printf("%d  %d\n",num1[i], num2[i]);
            if(num1[i] > num2[i])
            {
                print(num1,len1);
                printf(" is a bigger number\n");
                return 1;
            }
            else if(num1[i] < num2[i])
            {
                print(num2,len2);
                printf(" is a bigger number\n");
                return 2;
            }
            else
            {
                printf("They has the same value\n");
                return 1;
            }
            // keep going if num1[i] == num2[i]
        }
    }
}

int set(int* num)
{
    char temp[20];
    printf("Please enter the number: ");
    gets(temp);
    int len = strlen(temp);

    for(int i = 0; i < len; i++)
    {
        num[len-1-i] = (int)temp[i]-48;
    }
    // print(num, len);
    return len;
}

void print(int* num, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d", num[len-1-i]);
    }
}