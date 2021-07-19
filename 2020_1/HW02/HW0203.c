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
	int gro,mar,fam,inc,sds,sdt,psc,dp;
	float set,tol;
	printf("Gross salary: ");
	/*
	0-540,000   5%       -0
	-1,210,000  12%      -37,800
	-2,420,000  20%      -134,600
	-4,530,000  30%      -376,600
	higher      40%      -829,600
	*/
	scanf("%d",&gro);
	if(gro < 0 || gro >INT_MAX)
	{
		printf("Number Invalid");
		return 0;
	}
	
	printf("\nMarried? (0/1): ");
	//120,000 || 240,000
	scanf("%d",&mar);
	if(mar != 1 && mar != 0)
	{
		printf("Number Invalid");
		return 0;
	}
	
	printf("\nHow many people are there in your family: ");
	//88,000 / person
	
	//gorss < 175,000 * fam --> free
	
	scanf("%d",&fam);
	if(fam < 0 || fam > INT_MAX)
	{
		printf("Number Invalid");
		return 0;
	}
	
	printf("\nHow many people in your family have income: ");
	//Special deduction for salary   200,000 / person
	scanf("%d",&inc);
	if(inc <= fam)
	{
		
	}
	else
	{
		printf("Number Invalid");
		return 0;
	}
	
	printf("\nSpecial Deduction for Savings and Investment: ");
	// 270,000
	scanf("%d",&sds);
	if (sds != 1 && sds != 0)
	{
		printf("Number Invalid");
		return 0;
	}
	
	printf("\nSpecial Deduction for Tuition: ");
	// 25,000 / person
	scanf("%d",&sdt);
	if(sdt < 0 || sdt > INT_MAX)
	{
		printf("Number Invalid");
		return 0;
	}
	
	printf("\nHow many preschool children: ");
	//120,000 / person
	scanf("%d",&psc);
	if(psc <= fam)
	{
	
	}
	else
	{
		printf("Number Invalid");
		return 0;
	}
	
	printf("\nHow many disable people:　");
	//200,000 / person
	scanf("%d",&dp);
	if(dp <= fam)
	{
	
	}
	else
	{
		printf("Number Invalid");
		return 0;
	}
	
	if(gro <= 175000*fam)
	{
		tol = 0;
	}
	else
	{
		set = (gro - (mar+1)*120000 - fam*88000 - inc*200000 - sds*270000 - sdt*25000 - psc*120000 - dp*200000);

		if(set > 0 && set <= 540000)
		{
			tol = set*0.05; 
		}
		else if(set <= 1210000)
		{
			tol = set*0.12 - 37800;
		}
		else if(set <= 2420000)
		{
			tol = set*0.2 - 134600;
		}
		else if(set <= 4530000)
		{
			tol = set*0.3 - 376600;
		}
		else
		{
			tol = set*0.4 - 829600;
		}
	}

	printf("set = %.2f",set);
	printf("\nTotal tax: %.2f",tol);
	printf("\n");
	return 0;
} 
