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

void print_answer(char*, char*);

int main()
{
    char *pStr01 = "Hello";
    char *pStr02 = "World";
    char* temp;

    temp = pStr01;
    pStr01 = pStr02;
    pStr02 = temp;

    printf("String 01:\n");
    printf("%s\n", pStr01);
    printf("String 02:\n");
    printf("%s\n", pStr02);

}