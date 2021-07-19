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

int main()
{
    float g = 9.8;// gravity
    float t = 0 ; // time
    float v = 0 ; // velocity
    float a = 0 ; // altitude

    printf("Please enter the acceleration due to gravity: ");
    scanf("%f", &g);
    printf("Please enter the time (s): ");
    scanf("%f", &t);

    v = g*t;

    // velocity = g * time
    printf("Final velocity: &02f", g*t);

    a = t * v / 2;

    // altitude = (time * velocity) /2
    printf("The altitude: %03f", a);
}