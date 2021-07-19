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

int32_t matrix[4][4] = {{2,0,0,0},{0,2,0,0},{0,0,1,0},{0,0,0,1}};

int32_t det22(int32_t*, int32_t, int32_t);
int32_t det33(int32_t*, int32_t);
int32_t det44(int32_t*);

int main()
{
    int32_t ans = 0;

    printf("The matrix is\n");
    printf("%2d %2d %2d %2d \n", matrix[0][0], matrix[0][1], matrix[0][2], matrix[0][3]);
    printf("%2d %2d %2d %2d \n", matrix[1][0], matrix[1][1], matrix[1][2], matrix[1][3]);
    printf("%2d %2d %2d %2d \n", matrix[2][0], matrix[2][1], matrix[2][2], matrix[2][3]);
    printf("%2d %2d %2d %2d \n", matrix[3][0], matrix[3][1], matrix[3][2], matrix[3][3]);
    ans = det44(*matrix);
    printf("The determinant is %d", ans);

}

int32_t det22(int32_t* matrix, int32_t i, int32_t j)
{
    int32_t sum = 0;

    sum += matrix[8+i] * matrix[12+j];
    sum -= matrix[8+j] * matrix[12+i];

    return sum;
}
int32_t det33(int32_t* matrix, int32_t num)
{
    int32_t sum = 0;

    if(num == 0)
    {
        sum += matrix[5] * det22(matrix, 2, 3);
        sum -= matrix[6] * det22(matrix, 1, 3);
        sum += matrix[7] * det22(matrix, 1, 2);
    }
    else if(num == 1)
    {
        sum += matrix[4] * det22(matrix, 2, 3);
        sum -= matrix[6] * det22(matrix, 0, 3);
        sum += matrix[7] * det22(matrix, 0, 2);
    }
    else if(num == 2)
    {
        sum += matrix[4] * det22(matrix, 1, 3);
        sum -= matrix[5] * det22(matrix, 0, 3);
        sum += matrix[7] * det22(matrix, 0, 1);
    }
    else if(num == 3)
    {
        sum += matrix[4] * det22(matrix, 1, 2);
        sum -= matrix[5] * det22(matrix, 0, 2);
        sum += matrix[6] * det22(matrix, 0, 1);
    }
    else
    {
        printf("ERROR");
        return 0;
    }

    return sum;
}
int32_t det44(int32_t* matrix)
{
    int32_t sum = 0;

    sum += matrix[0] * det33(matrix, 0);
    sum -= matrix[4] * det33(matrix, 1);
    sum += matrix[8] * det33(matrix, 2);
    sum -= matrix[12] * det33(matrix, 3);

    return sum;
}