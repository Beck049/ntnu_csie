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
    int8_t card[5];
    
    printf("Please enter 5 cards: ");
    scanf("%d %d %d %d %d", &card[0], &card[1], &card[2], &card[3], &card[4]);

    for(int i = 0; i < 5; i++)
    {
        if(card[i] > 52 || card[i] < 1)
        {
            printf("ERROR");
            return 0;
        }
    }

    int8_t temp;
    for(int i = 0; i < 5; i++) // from small to big
    {
        for(int j = i; j < 5; j++)
        {
            if((card[i]-1)%13 > (card[j]-1)%13)
            {
                temp = card[i];
                card[i] = card[j];
                card[j] = temp;
            }
        }
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", (card[i]-1)%13);
    }

    if((card[0]-1)%13 == (card[1]-1)%13)
    {
        if((card[1]-1)%13 == (card[2]-1)%13)
        {
            if((card[2]-1)%13 == (card[3]-1)%13)
            {
                if((card[3]-1)%13 == (card[4]-1)%13)
                {
                    printf("Are you cheating ?");
                }
                else //(card[3] != card[4])
                {
                    printf("Four of a kind");
                }
            }
            else //(card[2] != card[3])
            {
                if((card[3]-1)%13 == (card[4]-1)%13)
                {
                    printf("Full house");
                }
                else //(card[3] != card[4])
                {
                    printf("Three of a kind");
                }
            }
        }
        else //(card[1] != card[2])
        {
            if((card[2]-1)%13 ==(card[3]-1)%13)
            {
                if((card[3]-1)%13 == (card[4]-1)%13)
                {
                    printf("Full house");
                }
                else //(card[3] != card[4])
                {
                    printf("Two pair");
                }
            }
            else //(card[2] != card[3])
            {
                if((card[3]-1)%13 == (card[4]-1)%13)
                {
                    printf("Two pair");
                }
                else //(card[3] != card[4])
                {
                    printf("One pair");
                }
            }
        }
    }
    else //(card[0] != card[1])
    {
       if((card[1]-1)%13 == (card[2]-1)%13)
        {
            if((card[2]-1)%13 == (card[3]-1)%13)
            {
                if((card[3]-1)%13 == (card[4]-1)%13)
                {
                    printf("Four of a kind");
                }
                else //(card[3] != card[4])
                {
                    printf("Tree of a kind");
                }
            }
            else //(card[2] != card[3])
            {
                if((card[3]-1)%13 ==(card[4]-1)%13)
                {
                    printf("Two pair");
                }
                else //(card[3] != card[4])
                {
                    printf("One pair");
                }
            }
        }
        else //(card[1] != card[2])
        {
            if((card[2]-1)%13 == (card[3]-1)%13)
            {
                if((card[3]-1)%13 == (card[4]-1)%13)
                {
                    printf("Tree of a kind");
                }
                else //(card[3] != card[4])
                {
                    printf("One pair");
                }
            }
            else //(card[2] != card[3])
            {
                if((card[3]-1)%13 == (card[4]-1)%13)
                {
                    printf("One pair");
                }
                else //(card[3] != card[4])
                {
                    if( (card[0]%13) + 4 == card[4] )
                    {
                        printf("Straight ");

                        if((card[0]-1)/13 == (card[4]-1)/13 && 
                           (card[1]-1)/13 == (card[3]-1)/13 && 
                           (card[2]-1)/13 == (card[3]-1)/13 && 
                           (card[0]-1)/13 == (card[2]-1)/13  )
                        {
                            printf("Flush");
                        }
                    }
                    else
                    {
                        if((card[0]-1)/13 == (card[4]-1)/13 && 
                           (card[1]-1)/13 == (card[3]-1)/13 && 
                           (card[2]-1)/13 == (card[3]-1)/13 && 
                           (card[0]-1)/13 == (card[2]-1)/13  )
                        {
                            printf("Flush");
                        }
                        else
                        {
                            printf("High card");
                        }
                    }
                }
            }
        }
    }
}