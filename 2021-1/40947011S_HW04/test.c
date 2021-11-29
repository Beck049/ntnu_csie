#include <stdio.h> 
#include <math.h>            
#include <ctype.h>    
#include <stdlib.h>
#include <assert.h>
#include <stdarg.h>
#include <limits.h>
#include <string.h>
#include <stdint.h>	
#include <time.h>

int main()
{
    int x = 0, y = 0, z = 0;

    // printf returns the total number of characters
    // if error, it returns negetive number
    printf("%d\n", printf("Hello World\n"));

    // scanf returns how many item is sucessfully read
    // if error, feof or ferror or EOF
    printf("%d\n", scanf("%d", &x));
    printf("%d\n", scanf("%d %d %d", &x, &y, &z));

    return 0;
}