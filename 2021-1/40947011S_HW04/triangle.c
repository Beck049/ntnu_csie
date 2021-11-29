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

#include "triangle.h"

#define PI 3.14159265

double x11 = 0, x22 = 0, x33 = 0;
double y11 = 0, y22 = 0, y33 = 0;
int init1 = 0, init2 = 0, init3 = 0;


// int set_1_point(double x, double y)
// {
//     x11 = x;
//     y11 = y;
//     init1 = 1;

//     return 1;
// }
// int set_2_point(double x, double y)
// {
//     x22 = x;
//     y22 = y;
//     init2 = 1;

//     return 1;
// }
// int set_3_point(double x, double y)
// {
//     x33 = x;
//     y33 = y;
//     init3 = 1;

//     return 1;
// }


// Setup three points for a triangle.
// Success: return 1; Fail: return 0
int set_1_point(double x, double y)
{
    if(init2 == 1 && init3 == 1)
    {
        if( (x == x22) && (y == y22) )
        {
            printf("The new point is the same as point 2\n");
            printf("set 1 point fail\n");
            return 0;
        }
        else if( (x == x33) && (y == y33) )
        {
            printf("The new point is the same as point 3\n");
            printf("set 1 point fail\n");
            return 0;
        }
        else // on the same line
        {
            double s1 = 0, s2 = 0;

            if(y22 - y33 == 0 && y - y22 == 0)
            {
                return 0;
            }

            s1 = (x22 - x33)/(y22 - y33);
            s2 = ( x - x22) /( y - y22) ;

            if(s1 == s2)
            {
                printf("These three point is not a triangle\n");
                return 0;
            }
            else
            {
                x11 = x;
                y11 = y;
                init1 = 1;

                return 1;
            }
        }
    }
    else if(init2 == 1)
    {
        if( (x == x22) && (y == y22) )
        {
            printf("The new point is the same as point 2\n");
            printf("set 1 point fail\n");
            return 0;
        }
        else
        {
            x11 = x;
            y11 = y;
            init1 = 1;

            return 1;
        }
    }
    else if(init3 == 1)
    {
        if( (x == x33) && (y == y33) )
        {
            printf("The new point is the same as point 3\n");
            printf("set 1 point fail\n");
            return 0;
        }
        else
        {
            x11 = x;
            y11 = y;
            init1 = 1;

            return 1;
        }
    }
    else if((init2 == 0) && (init3 == 0))
    {
        x11 = x;
        y11 = y;
        init1 = 1;

        return 1;
    }
    else
    {
        printf("Some problem happen\n");
        return 0;
    }
}
int set_2_point(double x, double y)
{
    if((init1 == 1) && (init3 == 1))
    {
        if( (x == x11 )&& (y == y11) )
        {
            printf("The new point is the same as point 1\n");
            printf("set 2 point fail\n");
            return 0;
        }
        else if( (x == x33) && (y == y33) )
        {
            printf("The new point is the same as point 3\n");
            printf("set 2 point fail\n");
            return 0;
        }
        else // on the same line
        {
            double s1 = 0, s2 = 0;

            if((y11 - y33 == 0) && (y - y11 == 0))
            {
                return 0;
            }

            s1 = (x11 - x33)/(y11 - y33);
            s2 = ( x - x11) /( y - y11);

            if(s1 == s2)
            {
                printf("These three point is not a triangle\n");
                return 0;
            }
            else
            {
                x22 = x;
                y22 = y;
                init2 = 1;

                return 1;
            }
        }
    }
    else if(init1 == 1)
    {
        if( (x == x11) &&( y == y11) )
        {
            printf("The new point is the same as point 1\n");
            printf("set 2 point fail\n");
            return 0;
        }
        else
        {
            x22 = x;
            y22 = y;
            init2 = 1;

            return 1;
        }
    }
    else if(init3 == 1)
    {
        if( (x == x33) && (y == y33) )
        {
            printf("The new point is the same as point 3\n");
            printf("set 2 point fail\n");
            return 0;
        }
        else
        {
            x22 = x;
            y22 = y;
            init2 = 1;

            return 1;
        }
    }
    else if((init1 == 0) && (init3 == 0))
    {
        x22 = x;
        y22 = y;
        init2 = 1;

        return 1;
    }
    else
    {
        printf("Some problem happen\n");
        return 0;
    }
}
int set_3_point(double x, double y)
{
    if(init1 == 1 && init2 == 1)
    {
        if( x == x11 && y == y11 )
        {
            printf("The new point is the same as point 1\n");
            printf("set 3 point fail\n");
            return 0;
        }
        else if( x == x22 && y == y22 )
        {
            printf("The new point is the same as point 2\n");
            printf("set 3 point fail\n");
            return 0;
        }
        else // on the same line
        {
            double s1 = 0, s2 = 0;
            
            if(x22 - x11 == 0 && x - x22 == 0)
            {
                return 0;
            }

            s1 =  (y22 - y11)/(x22 - x11) ;
            s2 =  ( y - y22)/( x - x22) ;

            if(s1 == s2)
            {
                printf("These three point is not a triangle\n");
                return 0;
            }
            else
            {
                x33 = x;
                y33 = y;
                init3 = 1;

                return 1;
            }
        }
    }
    else if(init2 == 1)
    {
        if( x == x22 && y == y22 )
        {
            printf("The new point is the same as point 2\n");
            printf("set 3 point fail\n");
            return 0;
        }
        else
        {
            x33 = x;
            y33 = y;
            init3 = 1;

            return 1;
        }
    }
    else if(init1 == 1)
    {
        if( x == x11 && y == y11 )
        {
            printf("The new point is the same as point 1\n");
            printf("set 3 point fail\n");
            return 0;
        }
        else
        {
            x33 = x;
            y33 = y;
            init3 = 1;

            return 1;
        }
    }
    else if(init1 == 0 && init2 == 0)
    {
        x33 = x;
        y33 = y;
        init3 = 1;

        return 1;
    }
    else
    {
        printf("Some problem happen\n");
        return 0;
    }
}

// Check if the current setting is a valid triangle.
// Yes: return 1; No: return 0
int check (void)
{
    // not initialized
    if(init1 == 1 && init2 == 1 && init3 == 1)
    {
        return 1;
    }

    // same point
    if(x11 == x22 && y11 == y22)
    {
        return 0; // not a triangle
    }
    else if(x11 == x33 && y11 == y33)
    {
        return 0;
    }
    else if(x22 == x33 && y22 == y33)
    {
        return 0;
    }

    // same line
    double slope1 = 0, slope2 = 0;

    if( x11 - x22 == 0 && x11 - x33 == 0 )
    {
        return 0;
    }

    slope1 = (y11 - y22) / (x11 - x22);
    slope2 = (y11 - y33) / (x11 - x33);

    if(fabs(slope1) == fabs(slope2))
    {
        return 0;
    }

    return 1;
}

double get_distance12( void )
{
    double d = 0;
    d = sqrt( pow( fabs(x11 - x22), 2 ) + pow( fabs(y11 - y22), 2 ) );

    return d;
}
double get_distance13( void )
{
    double d = 0;
    d = sqrt( pow( fabs(x11 - x33), 2 ) + pow( fabs(y11 - y33), 2 ) );

    return d;
}
double get_distance23( void )
{
    double d = 0;
    d = sqrt( pow( fabs(x22 - x33), 2 ) + pow( fabs(y22 - y33), 2 ) );

    return d;
}

// Return the perimeter of the triangle.
// If the current setting is not a triangle , return < 0
double get_perimeter( void )
{
    if(check() == 0)
    {
        return -1;
    }
    double peri = 0;
    peri += get_distance12();
    peri += get_distance13();
    peri += get_distance23();

    return peri;
}

// Return the area of the triangle.
// If the current setting is not a triangle , return < 0
double get_area( void )
{
    if(check() == 0)
    {
        return -1;
    }
    double s = get_perimeter() / 2;
    double area = 0;

    area = sqrt( s * ( s - get_distance12() ) * ( s - get_distance13() ) * ( s - get_distance23() ) );

    return area;
}

// Get the degrees (0-360) of three angles
// If the current setting is not a triangle , return < 0
double get_1_degree( void )
{
    if(check() == 0)
    {
        return -1;
    }
    double degree = 0;

    degree  = pow( get_distance12(), 2 ) + pow( get_distance13(), 2 ) - pow( get_distance23(), 2 );
    degree /= 2 * get_distance12() * get_distance13();

    degree = acos(degree) * 180.0 / PI;

    return degree;
}
double get_2_degree( void )
{
    if(check() == 0)
    {
        return -1;
    }
    double degree = 0;

    degree  = pow( get_distance12(), 2 ) + pow( get_distance23(), 2 ) - pow( get_distance13(), 2 );
    degree /= 2 * get_distance12() * get_distance23();

    degree = acos(degree) * 180.0 / PI;

    return degree;
}
double get_3_degree( void )
{
    if(check() == 0)
    {
        return -1;
    }
    double degree = 0;

    degree  = pow( get_distance13(), 2 ) + pow( get_distance23(), 2 ) - pow( get_distance12(), 2 );
    degree /= 2 * get_distance13() * get_distance23();

    degree = acos(degree) * 180.0 / PI;

    return degree;
}

// Inscribed circle and Circumscribed circle of the triangle.
// If the current setting is not a triangle , the area functions return 0
// and the center functions return 0.
double get_inscribed_center_x( void )
{
    if(check() == 0)
    {
        return -1;
    }
    double ins_x = 0;
    ins_x  = ( get_distance12() * x33 ) + ( get_distance13() * x22 ) + ( get_distance23() * x11 );
    ins_x /= get_perimeter();

    return ins_x;
}
double get_inscribed_center_y( void )
{
    if(check() == 0)
    {
        return -1;
    }
    double ins_y = 0;
    ins_y  = ( get_distance12() * y33 ) + ( get_distance13() * y22 ) + ( get_distance23() * y11 );
    ins_y /= get_perimeter();

    return ins_y;
}
double get_inscribed_center_area( void )
{
    if(check() == 0)
    {
        return -1;
    }
    double area = 0;

    area  = 2 * get_area();
    area /= get_perimeter();

    area = area*area*PI;

    return area;
}

double get_circumscribed_center_x( void )
{
    if(check() == 0)
    {
        return -1;
    }
    double circ_x = 0;
    double temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
    if( (float)get_1_degree() == 90.0)
    {
        circ_x = ( x22 + x33 ) / 2;
        return circ_x;
    }
    else if ( (float)get_2_degree() == 90.0)
    {
        circ_x = ( x11 + x33 ) / 2;
        return circ_x;
    }
    else if ( (float)get_3_degree() == 90.0)
    {
        circ_x = ( x11 + x22 ) / 2;
        return circ_x;
    }
    else
    {
        temp1 = (x11 - x22) / (y11 - y22);
        temp2 = (x11 - x33) / (y11 - y33);

        temp3  = (x22*x22)+(y22*y22)-(x11*x11)-(y11*y11);
        temp3 /= 2 * (y22 - y11);

        temp4  = (x33*x33)+(y33*y33)-(x11*x11)-(y11*y11);
        temp4 /= 2 * (y33 - y11);

        circ_x  = temp3 - temp4;
        circ_x /= temp1 - temp2;

        return circ_x;
    }

    return -1;
}
double get_circumscribed_center_y( void )
{
    if(check() == 0)
    {
        return -1;
    }
    double circ_y = 0;
    double temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
    if( (float)get_1_degree() == 90.0)
    {
        circ_y = ( y22 + y33 ) / 2;
        return circ_y;
    }
    else if ( (float)get_2_degree() == 90.0)
    {
        circ_y = ( y11 + y33 ) / 2;
        return circ_y;
    }
    else if ( (float)get_3_degree() == 90.0)
    {
        circ_y = ( y11 + y22 ) / 2;
        return circ_y;
    }
    else
    {
        temp1 = (y11 - y22) / (x11 - x22);
        temp2 = (y11 - y33) / (x11 - x33);

        temp3  = (x22*x22)+(y22*y22)-(x11*x11)-(y11*y11);
        temp3 /= 2 * (x22 - x11);

        temp4  = (x33*x33)+(y33*y33)-(x11*x11)-(y11*y11);
        temp4 /= 2 * (x33 - x11);
        circ_y  = temp3 - temp4;
        circ_y /= temp1 - temp2;

        return circ_y;
    }

    return -1;
}
double get_circumscribed_center_area( void )
{
    if(check() == 0)
    {
        return -1;
    }
    double area = 0;
    double x = 0, y = 0;

    x = get_circumscribed_center_x() - x11;
    y = get_circumscribed_center_y() - y11;

    area = ( (x*x)+(y*y) ) * PI;

    return area;
}