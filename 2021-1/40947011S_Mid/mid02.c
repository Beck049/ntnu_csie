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
    int32_t count = 0;
    int32_t success = 0;
    int num[500];

    printf("Please enter the integer: "); scanf("%d", &num[count]);

    while(num[count] != 0)
    {
        count++;
        printf("Please enter the integer: "); scanf("%d", &num[count]);
    }

    for(int i = 0; i < count; i++)
    {
        int j = 0;
        int position = i;
        success = 0;

        if(num[i] == 13 || num[i] == 27 || num[i] == 68)
        {
            if(num[i+1] == -5 || num[i+1] == 19 || num[i+1] == 103 || num[i+1] == 27)
            {
                if(num[i+2] == -5 || num[i+2] == 19 || num[i+2] == 103 || num[i+2] == 27)
                {
                    if(num[i+3] == -33)
                    {
                        j = i+4;
                        success = 1;
                    }
                }
                else if(num[i+2] == -33)
                {
                    j = i+3;
                    success = 1;
                }
            }
            else if(num[i+1] == -33)
            {
                j = i+2;
                success = 1;
            }
            // 1st done

            if(success == 1)
            {
                if(num[j] == 13 || num[j] == 27 || num[j] == 68)
                {
                    if(num[j+1] == -5 || num[j+1] == 19 || num[j+1] == 103 || num[j+1] == 27)
                    {
                        if(num[j+2] == -5 || num[j+2] == 19 || num[j+2] == 103 || num[j+2] == 27)
                        {
                            if(num[j+3] == -33)
                            {
                                success = 2;
                                printf("The first matching series is at position %d, integer %d.", position+1, num[position]);
                                return 0;
                            }
                        }
                        else if(num[j+2] == -33)
                        {
                            success = 2;
                            printf("The first matching series is at position %d, integer %d.", position+1, num[position]);
                            return 0;
                        }
                    }
                    else if(num[j+1] == -33)
                    {
                        success = 2;
                        printf("The first matching series is at position %d, integer %d.", position+1, num[position]);
                        return 0;
                    }
                }
                else if(num[j] == -5 || num[j] == 19 || num[j] == 103 || num[j] == 27)
                {
                    if(num[j+1] == -5 || num[j+1] == 19 || num[j+1] == 103 || num[j+1] == 27)
                    {
                        if(num[j+2] == -33)
                        {
                            success = 2;
                            printf("The first matching series is at position %d, integer %d.", position+1, num[position]);
                            return 0;
                        }
                    }
                    else if(num[j+1] == -33)
                    {
                        success = 2;
                        printf("The first matching series is at position %d, integer %d.", position+1, num[position]);
                        return 0;
                    }
                }
            }

        }
        else if(num[i] == -5 || num[i] == 19 || num[i] == 103 || num[i] == 27)
        {
            if(num[i+1] == -5 || num[i+1] == 19 || num[i+1] == 103 || num[i+1] == 27)
            {
                if(num[i+2] == -33)
                {
                    j = i+3;
                    success = 1;
                }
            }
            else if(num[i+1] == -33)
            {
                j = i+2;
                success = 1;
            }
            // 1st done

            if(success == 1)
            {
                if(num[j] == 13 || num[j] == 27 || num[j] == 68)
                {
                    if(num[j+1] == -5 || num[j+1] == 19 || num[j+1] == 103 || num[j+1] == 27)
                    {
                        if(num[j+2] == -5 || num[j+2] == 19 || num[j+2] == 103 || num[j+2] == 27)
                        {
                            if(num[j+3] == -33)
                            {
                                success = 2;
                                printf("The first matching series is at position %d, integer %d.", position+1, num[position]);
                                return 0;
                            }
                        }
                        else if(num[j+2] == -33)
                        {
                            success = 2;
                            printf("The first matching series is at position %d, integer %d.", position+1, num[position]);
                            return 0;
                        }
                    }
                    else if(num[j+1] == -33)
                    {
                        success = 2;
                        printf("The first matching series is at position %d, integer %d.", position+1, num[position]);
                        return 0;
                    }
                }
                else if(num[j] == -5 || num[j] == 19 || num[j] == 103 || num[j] == 27)
                {
                    if(num[j+1] == -5 || num[j+1] == 19 || num[j+1] == 103 || num[j+1] == 27)
                    {
                        if(num[j+2] == -33)
                        {
                            success = 2;
                            printf("The first matching series is at position %d, integer %d.", position+1, num[position]);
                            return 0;
                        }
                    }
                    else if(num[j+1] == -33)
                    {
                        success = 2;
                        printf("The first matching series is at position %d, integer %d.", position+1, num[position]);
                        return 0;
                    }
                }
            }
        }
    }

    printf("NONE\n");

    return 0;
}