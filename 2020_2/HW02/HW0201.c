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

struct _sMixedNumber{
    int a, b, c;
    int sign;
};
typedef struct _sMixedNumber sMixedNumber;
typedef sMixedNumber *link;

int gcd(int a, int b);

void mixed_set  (link r);
void mixed_print(link r);
void mixed_check(link r);
void mixed_add(link r1, link r2, link temp);
void mixed_sub(link r1, link r2, link temp);
void mixed_mul(link r1, link r2, link temp);
void mixed_div(link r1, link r2, link temp);

int main()
{
    int op = -1;
    for(int i = 0; i < 1; i)
    {
        printf("Please enter the number 1:\n");
        // mixed_set
        link r1 = (link)malloc(sizeof(sMixedNumber));
        mixed_set(r1);
        printf("Please enter the number 2:\n");
        // mixed_set
        link r2 = (link)malloc(sizeof(sMixedNumber));
        mixed_set(r2);
/*
mixed_print(r1);    mixed_print(r2);
*/
        while(op != 0)
        {
            link temp = (link)calloc(1,sizeof(sMixedNumber));
            printf("What do you want to do ?\n");
            printf("Operation: ");  scanf("%d", &op);

            switch(op)
            {
                case 1: // +
                    mixed_add(r1, r2, temp);
                    printf("The mixed addition is ");
                    break;
                case 2: // -
                    mixed_sub(r1, r2, temp);
                    printf("The mixed subtraction is ");
                    break;
                case 3: // *
                    mixed_mul(r1, r2, temp);
                    printf("The mixed multiple is ");
                    break;
                case 4: // /
                    mixed_div(r1, r2, temp);
                    printf("The mixed division is ");
                    break;
                case 0:
                    break;
                default:
                    printf("Error\n");
                    break;
            }
            mixed_print(temp);
            free(temp);
        }
        free(r1);
        free(r2);

        printf("Enter another numbers ?\n (Yes: 1) (Exit: 0)");
        scanf("%d", &op);
        if(op == 1)
        {   /**/   }
        else
        {   i++;   }
    }

    printf("Exit\n");
}

void mixed_add(link r1, link r2, link temp)
{
    if(r1->sign == r2->sign)
    {
        temp->c = r1->c * r2->c;
        temp->a = r1->a + r2->a;
        temp->b = r1->b*r2->c + r1->c*r2->b;

        temp->sign = r1->sign;
        mixed_check(temp);
    }
    else
    {
        mixed_sub(r1, r2, temp);
    }
}
void mixed_sub(link r1, link r2, link temp)
{
    if(r1->sign == r2->sign)
    {
        temp->c = r1->c * r2->c;
        temp->a = r1->a - r2->a;
        temp->b = r1->b*r2->c - r1->c*r2->b;
        mixed_check(temp);
    }
    else
    {
        mixed_add(r1, r2, temp);
    }
}
void mixed_mul(link r1, link r2, link temp)
{
    int b1 = 0, b2 = 0, b3 = 0;
    temp->a = r1->a * r2->a;
    b1 = r1->c * r1->a * r2->b;
    b2 = r2->c * r2->a * r1->b;
    b3 = r1->b * r2->b;
    temp->b = b1 + b2 + b3;
    temp->c = r1->c * r2->c;

    temp->a += temp->b / temp->c;
    temp->b = temp->b % temp->c;

    temp->sign = r1->sign * r2->sign;

    mixed_check(temp);
}
void mixed_div(link r1, link r2, link temp)
{
    temp->a = 0;

    temp->b = r2->c * (r1->a * r1->c + r1->b);
    temp->c = r1->c * (r2->a * r2->c + r2->b);

    temp->a += temp->b / temp->c;
    temp->b = temp->b % temp->c;

    temp->sign = r1->sign * r2->sign;

    mixed_check(temp);
}
void mixed_set(link r)
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    r->a = x;
    r->b = y;
    r->c = z;
    mixed_check(r);
}
void mixed_check(link r)
{
    if(r->c == 0)
    {
        if(r->b == 0)
        {/*( x, 0, 0 )*/
            r->c = 1;
        }
        else
        {/*( x, y, 0 )*/
            printf("Error ! Enter the number again.\n");
            mixed_set(r);
        }
    }
    else if(r->c <= 0)
    {    /*( x, y, -z )*/
        printf("Error ! Enter the number again.\n");
        mixed_set(r);
    }
    else
    {
        if(r->b < 0)
        {/*( x, -y, z )*/
            while(r->b < 0)
            {
                r->a -= 1;
                r->b += r->c;
            }
        }
        else
        {/*( x, y, z )*/
            if(r->c <= r->b)
            {
                r->a += r->b /r->c;
                r->b = r->b % r->c;
            }
        }
    }
// 質因數分解 b,c
    int g = gcd(r->b, r->c);
    r->b = r->b / g;
    r->c = r->c / g;

    if(r->a < 0)
    {
        r->sign = -1;
        r->a *= -1;
    }
    else
    {
        r->sign = 1;
    }
}
void mixed_print(link r)
{
    if(r->b == 0)
    {
        r->c = 0;
    }
    r->a = r->a * r->sign;
    printf("(%d, %d, %d)\n", r->a, r->b, r->c);
}
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    return gcd(b, a%b);
}