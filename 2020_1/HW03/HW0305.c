#include <stdio.h>
#include <math.h>

int main()
{

	double cost_y = 0;
	double temp = 0;
	
	int annual_pay;
	int i1,i2,i3,i4,i5;
	int fee_off;
	int fee;
	int age;
	int i = 1;
	int pay_year;
	int rate;
	int start_age ; 
	
	printf("SIP Plan\n");
	printf("Annually payment : ");
	scanf("%d",&annual_pay); 
	printf("Insurance fee in the first five years (0 is assumed afterwards):\n");
	scanf(" %d %d %d %d %d",&i1,&i2,&i3,&i4,&i5);
	if(i1 > 100 || i1 < 0){printf("Insurance fee should > 0 && < 100");return 0;}
	if(i2 > 100 || i2 < 0){printf("Insurance fee should > 0 && < 100");return 0;}
	if(i3 > 100 || i3 < 0){printf("Insurance fee should > 0 && < 100");return 0;}
	if(i4 > 100 || i4 < 0){printf("Insurance fee should > 0 && < 100");return 0;}
	if(i5 > 100 || i5 < 0){printf("Insurance fee should > 0 && < 100");return 0;}	
	printf("insurance fee off: ");
	scanf("%d",&fee_off);
	if(fee_off > 100 || fee_off < 0){printf("Insurance fee off should > 0 && < 100");return 0;}	
	printf("Monthly insurance processing fee: ");
	scanf("%d",&fee);
	printf("Age: ");
	scanf("%d",&age);
	if(age > 100 || age < 0){printf("Are you sure this is your age?");return 0;}
	start_age = age-1;
	printf("How many years of payment: ");
	scanf("%d",&pay_year);
	if(pay_year > 100 - start_age){printf("Are you sure to pay that long ?");return 0;}
	printf("Expected annual return on investment rate: ");
	scanf("%d",&rate);
	if(rate > 100 || rate < -100){printf("Annual return rate should > -100 && < 100");return 0;}	
	
	double rt_rate;	
//	rt_rate = cbrt( sqrt ( sqrt ( (rate/100.0)+1 ) ) );
	rt_rate =((rate/100.0)/12+1); 
//	printf("%d", 1 - (i1/100) + (fee_off/100));
	
	printf("\nYour Payment and Account Value Table \n");
	
	if(age <= 20)
	{cost_y = 2000 ;}
	else
	{cost_y = (100*(age-20) + 2000) ;}

	// 1st
	temp = annual_pay*( 1 - (i1/100.0) + (fee_off/100.0) ) - cost_y;
	for(int k = 0; k < 11; k++)
	{
	/*	if(age <= 20)
		{cost_y = 2000/12 ;}
		else
		{cost_y = (100*(age-20) + 2000)/12 ;}
	*/
		temp = ( temp - fee ) * rt_rate; 
	}
	
	printf("%3d: %7d, %12.2lf\n",age,annual_pay*i,temp);
	
	// 2nd
	i++;
	age++;
	if(age <= 20)
		{cost_y = 2000 ;}
	else
		{cost_y = (100*(age-20) + 2000) ;}
	temp = temp + ( annual_pay * ( 1 - (i2/100.0) + (fee_off/100.0) ) ) - cost_y;

	for(int k = 0; k < 12; k++)
	{
	/*	if(age <= 20)
		{cost_y = 2000/12 ;}
		else
		{cost_y = (100*(age-20) + 2000)/12 ;}
	*/
		temp = ( temp - fee ) * rt_rate ;
	}
		
	printf("%3d: %7d, %12.2lf\n",age,annual_pay*i,temp);
		
	// 3rd
	i++;
	age++;
	if(age <= 20)
		{cost_y = 2000 ;}
	else
		{cost_y = (100*(age-20) + 2000) ;}
	temp = temp + ( annual_pay * ( 1 - (i3/100.0) + (fee_off/100.0) ) ) - cost_y;
	
	for(int k = 0; k < 12; k++)
	{
	/*	if(age <= 20)
		{cost_y = 2000/12 ;}
		else
		{cost_y = (100*(age-20) + 2000)/12 ;}
	*/
		temp = ( temp - fee ) * rt_rate ;
	}
		
	printf("%3d: %7d, %12.2lf\n",age,annual_pay*i,temp);
		
	// 4th
	i++;
	age++;
	if(age <= 20)
		{cost_y = 2000 ;}
	else
		{cost_y = (100*(age-20) + 2000) ;}
	temp = temp + ( annual_pay * ( 1 - (i4/100.0) + (fee_off/100.0) ) ) - cost_y;
	
	for(int k = 0; k < 12; k++)
	{
	/*	if(age <= 20)
		{cost_y = 2000/12 ;}
		else
		{cost_y = (100*(age-20) + 2000)/12 ;}
	*/
		temp = ( temp - fee ) * rt_rate ;
	}
		
	printf("%3d: %7d, %12.2lf\n",age,annual_pay*i,temp);
		
	// 5th
	i++;
	age++;
	if(age <= 20)
		{cost_y = 2000 ;}
	else
		{cost_y = (100*(age-20) + 2000) ;}
	temp = temp + ( annual_pay * ( 1 - (i5/100.0) + (fee_off/100.0) ) ) - cost_y;
	
	for(int k = 0; k < 12; k++)
	{
	/*	if(age <= 20)
		{cost_y = 2000/12 ;}
		else
		{cost_y = (100*(age-20) + 2000)/12 ;}
	*/
		temp = ( temp - fee ) * rt_rate ;
	}
		
	printf("%3d: %7d, %12.2lf\n",age,annual_pay*i,temp);
	
	// 6th ~ 15th
	for(int j = 0; j < pay_year-5; j++)
	{
		i++;
		age++;
		if(age <= 20)
			{cost_y = 2000 ;}
		else
			{cost_y = (100*(age-20) + 2000) ;}
		temp = temp + annual_pay - cost_y;

		for(int k = 0; k < 12; k++)
		{
		/*	if(age <= 20)
			{cost_y = 2000/12 ;}
			else
			{cost_y = (100*(age-20) + 2000)/12 ;}
		*/
			temp = ( temp - fee ) * rt_rate ;
		}
		
		printf("%3d: %7d, %12.2lf\n",age,annual_pay*i,temp);
	}
	// 16th ~ age == 100
	for(int j = 0; j < 100-start_age-pay_year; j++)
	{
		age++;
		if(age <= 20)
			{cost_y = 2000 ;}
		else
			{cost_y = (100*(age-20) + 2000) ;}
		temp = temp - cost_y;
		
		for(int k = 0; k < 12; k++)
		{
		/*	if(age <= 20)
			{cost_y = 2000/12 ;}
			else
			{cost_y = (100*(age-20) + 2000)/12 ;}
		*/
			temp = ( temp - fee ) * rt_rate ;
		}
		
		printf("%3d: %7d, %12.2lf\n",age,annual_pay*i,temp);
	}
	
	return 0;
}
