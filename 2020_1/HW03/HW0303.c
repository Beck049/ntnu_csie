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


int start(int in )
{
	if(in == 10 || in == 35)
	{	return 1;	}
	else if (in == 11)
	{	return 3;	}
	else if (in == 20 || in == 78)
	{	return 5;	}
	else
	{	return 0;	}
}

int s1(int in )
{
	if(in == 19)
	{	return 2;	}
	else if (in == 12 || in == 36)
	{	return 6;	}
	else
	{	return 1;	}
}

int s2(int in )
{
	if(in == 43)
	{	return 2;	}
	else if (in == 99)
	{	return 7;	}
	else 
	{	return 0;	}	
}

int s3(int in )
{
	return 4;
}

int s4(int in )
{
	return 6;
}

int s5(int in )
{
	if(in == 1)
	{	return 4;	}
	if(in == 2)
	{	return 6;	}
	else
	{	return 0;	}	
}

int s6(int in )
{
	if(in == 108)
	{	return 7;	}
	else 
	{	return 5;	}	
}

int main()
{
	int in;
	int set = 0;

	while(1)
	{
		switch(set)
		{
			case 0:
				printf("start\n");
				printf("Please enter an integer: ");
				scanf("%d",&in);
				set = start(in);
				break;
			case 1:
				printf("s1\n");
				printf("Please enter an integer: ");
				scanf("%d",&in);
				set = s1(in);
				break;
			case 2:
				printf("s2\n");
				printf("Please enter an integer: ");
				scanf("%d",&in);
				set = s2(in);
				break;
			case 3:
				printf("s3\n");
				printf("Please enter an integer: ");
				scanf("%d",&in);
				set = s3(in);
				break;
			case 4:
				printf("s4\n");
				printf("Please enter an integer: ");
				scanf("%d",&in);
				set = s4(in);
				break;
			case 5:
				printf("s5\n");
				printf("Please enter an integer: ");
				scanf("%d",&in);
				set = s5(in);
				break;
			case 6:
				printf("s6\n");
				printf("Please enter an integer: ");
				scanf("%d",&in);
				set = s6(in);
				break;
			case 7:
				printf("final\n");
				return 0;
			case 9:
				printf("Please enter a number");
				return 0;
		}
	}
	return 0;
} 
