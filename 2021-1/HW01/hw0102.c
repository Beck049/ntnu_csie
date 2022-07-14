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

int get_max(int, ...);
int get_digits(int);
int check(int);
void split(int, int);
void split_ans(int, int);

int main()
{
    int a = 0, b = 0;
    printf("Please enter the first  number: ");
    scanf("%d", &a);
    check(a);
    printf("Please enter the second number: ");
    scanf("%d", &b);
    check(b);
    int c = a+b;

    int len = 0;
    len = get_max( 2, get_digits(a), get_digits(b) );

    printf("   "); split(a, len);
    printf("+) "); split(b, len);
    for(int i = 1; i < len; ++i) {
        printf("---");
    }
    printf("-\n ");
    split_ans(c, len);
    
    return 0;
}
void split_ans(int n, int len) {
    if( get_digits(n) == len ) {
        printf("   "); split(n, len);
    }
    else if( get_digits(n) == len+1 ) {
        split(n, len+1);
    }
    else {
        printf("ERROR\n");
    }

    return;
}
void split(int n, int len) {
    for(int i = len; i > get_digits(n); --i) {
        printf("  ");
    }
    int ten = 1;
    for(int i = 1; i < get_digits(n); ++i) {
        ten *= 10;
    }
    for(int i = get_digits(n); i > 0; --i) {
        printf("%d ", n/ten);
        n = n%ten;
        ten /= 10;
    }
    printf("\n");

    return;
}
int get_max(int n, ...) {
    int max = 0;

    va_list ptr;
    va_start(ptr, n);

    for(int i = 0; i < n; ++i) {
        int tmp = va_arg(ptr, int);
        max = tmp > max ? tmp : max;
    }

    va_end(ptr);

    return max;
}
int get_digits(int num) {
    int ret = 0;
    while(num > 0) {
        num /= 10;
        ret++;
    }
    return ret;
}
int check(int c) {
    if(c <= 0)
    {
        printf("Error\n");
    }
    return 0;
}
