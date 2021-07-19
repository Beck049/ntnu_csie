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

#define RED "\x1b[;31;1m"

#define BLU "\x1b[;34;1m"

#define YEL "\x1b[;33;1m"

#define GRN "\x1b[;32;1m"

#define CYAN "\x1b[;36;1;3m"

#define RESET "\x1b[0;m"


int turn = 1;
/////////////////////////////////////////////////////
int response(int *an,int *gus)
{
//find A
	int a = 0;
	for(int i = 0; i < 4; i++)
	{
		if(an[i] == gus[i])
		{
			a++;
		}
	}
printf("%d\n",a);
//find B
	int b = 0;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(an[i] == gus[j])
			{
				b++;
			}
		}
	}
// printf("%d\n",b);
	b = b-a;
// printf("%d\n",b);
	if(a == 4)
	{
		printf(YEL"Response: Bingo! Congradulations."RESET);
		return 1;
	}
	else
	{
		printf("Response: "BLU"%d A"RESET" "RED"%d B"RESET"\n",a,b);
		return 0;
	}
}
//////////////////////////////////////////////////////////
int check(int *gus)
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(gus[i] == gus[j])
			{
				printf(RED"Response: Invalid Guess\n"RESET);
				return 1;
			}
		}
	}	
	return 0;
}
//////////////////////////////////////////////////////////
int main()
{
    int ans[] = {1,7,5,4,3,6,2,0,9,8};

    srand(time(NULL));
//set answer and check

	for(int i = 0; i < 10; i++)
	{
		int r1,r2;
		r1 = rand()%10;
		r2 = rand()%8;
		int temp;
		temp = ans[r1];
		ans[r1] = ans[r2];
		ans[r2] = temp;
	}
	
	int an[4];
	for(int i = 0; i < 4; i++)
	{
		an[i] = ans[i];
	//	printf("%d ",an[i]);
	}

    printf(CYAN"Bulls and Cows Game\n"RESET);

	int input;
    int gus[4];
    int error = 0;
    int stop2 = 0;
//start round
    while(stop2 != 1)
    {
        printf("Round %d >>> \n\tYour Guess:",turn);
        scanf("%d",&input);
		for(int i = 3; i >= 0; i--)
		{
			gus[i] = input % 10;
			input = input / 10;	
		}

		error = check(gus);

		if(error == 1)
		{
			stop2 = 0;
		}
		else if(error == 0)
		{
			stop2 = response(ans, gus);
		}
		turn++;
    }

    return 0;
}
