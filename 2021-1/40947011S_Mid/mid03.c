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

#define PI 3.14159265

int main()
{
    double in_angle = 0, sin_in = 0;
    int layer = 0;
    double ref_index = 0, height = 0, last_index = 0;
    double shift = 0;

    printf("Incidence angle: "); scanf("%lf", &in_angle);
    printf("How many layers: "); scanf("%d", &layer);

    printf("Layer 1\'s refractive index: "); scanf("%lf", &ref_index); // n
    printf("Layer 1\'s height: "); scanf("%lf", &height);
    if(ref_index == 0)
    {
        printf("The shift: %lf\n", shift);
        return 0;
    }
    else if(ref_index < 0)
    {
        printf("the refrective index should be positive\n");
        return 0;
    }
    else if(height < 0)
    {
        printf("the height should be positive\n");
        return 0;
    }

    last_index = ref_index; 
    shift += tan(in_angle* PI / 180.0) * height;
    sin_in = sin(in_angle* PI / 180.0);

    if(layer > 1)
    {
        for(int i = 2; i <= layer; i++)
        {
            printf("Layer %d\'s refractive index: ", i); scanf("%lf", &ref_index); // n
            printf("Layer %d\'s height: ", i); scanf("%lf", &height);
            if(ref_index == 0)
            {
                printf("The shift: %lf\n", shift);
                return 0;
            }
            else if(ref_index < 0)
            {
                printf("the refrective index should be positive\n");
                return 0;
            }
            else if(height < 0)
            {
                printf("the height should be positive\n");
                return 0;
            }

            double sin_out = 0;
            sin_out = last_index / ref_index * sin_in;

            shift += tan(asin(sin_out)) * height;
        }
    }

    printf("The shift: %lf\n", shift);
    return 0;
}