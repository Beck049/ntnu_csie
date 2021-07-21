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


typedef union _uByte
{
    struct{
        unsigned char b1 : 1;
        unsigned char b2 : 1;
        unsigned char b3 : 1;
        unsigned char b4 : 1;
        unsigned char b5 : 1;
        unsigned char b6 : 1;
        unsigned char b7 : 1;
        unsigned char b8 : 1;
    }bits;
    unsigned char byte;
} uByte;

int main()
{
    uByte input;
    int32_t choice = 0;

    printf("Please enter a byte (0-255): ");
    scanf("%hhd",&input.byte);

    do
    {
        printf("Data: %d %d%d%d%d%d%d%d%d\n",input.byte, input.bits.b8, input.bits.b7, input.bits.b6, input.bits.b5, input.bits.b4, input.bits.b3, input.bits.b2, input.bits.b1);
        printf("Flip bit (1-8, 0: exit): ");
        scanf("%d",&choice);

        if(choice != 0)
        {
            if(choice == 1) input.bits.b8 = !input.bits.b8;
            if(choice == 2) input.bits.b7 = !input.bits.b7;
            if(choice == 3) input.bits.b6 = !input.bits.b6;
            if(choice == 4) input.bits.b5 = !input.bits.b5;
            if(choice == 5) input.bits.b4 = !input.bits.b4;
            if(choice == 6) input.bits.b3 = !input.bits.b3;
            if(choice == 7) input.bits.b2 = !input.bits.b2;
            if(choice == 8) input.bits.b1 = !input.bits.b1;
        }

    } while(choice != 0);
    printf("Bye\n");

    return 0;
}