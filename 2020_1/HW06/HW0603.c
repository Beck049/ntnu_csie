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

#define PI 3.14159/180

void rotate_right( double*, double*, double);
void rotate_left ( double*, double*, double);

int main()
{
    double x, y;
    double theta;
    char cc;

    printf("Please enter a point: ");
    scanf("%lf %lf", &x, &y);
    //scanf("%c", cc);
    printf("Please enter theta (0-360): ");
    scanf("%lf", &theta);

    rotate_right(&x, &y, theta);
    rotate_left (&x, &y, theta);
}

void rotate_right( double *xi, double *yi, double theta )
{
    double x = *xi;
    double y = *yi;
    double r = sqrt(x*x+y*y);
    double cos1 = x/r, sin1 = y/r;
    double cos2 = cos(theta*PI),sin2 = sin(theta*PI);

    x = r *(sin1*cos2 + cos1*sin2);
    y = r *(cos1*cos2 - sin1*sin2);

    printf("Result right: %lf, %lf",x, y);
}

void rotate_left ( double *xi, double *yi, double theta )
{
    double x = *xi;
    double y = *yi;
    double r = sqrt(x*x+y*y);
    double cos1 = x/r, sin1 = y/r;
    double cos2 = cos(theta*PI),sin2 = sin(theta*PI);

    x = r *(sin1*cos2 + cos1*sin2);
    y = r *(cos1*cos2 - sin1*sin2);

    printf("Result left : %lf, %lf",-x, -y);
}