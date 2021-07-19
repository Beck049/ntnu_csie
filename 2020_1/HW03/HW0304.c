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
	double a, b, c;  // ax^2+bx+c
	double s,t;	  // interval [s,t]

	// scan abc
	printf("Please enter a quadratic polynomial (ax^2+bx+c): ");
	scanf("%lf %lf %lf",&a,&b,&c);
	//

	/// print the polynomial
	printf("The polynomial is ");

	if     (a==1)	
	{printf("x^2 ");    	}
	else if(a==-1)  
	{printf("-x^2 ");		}
	else if(a==0)	
	{				      	}
	else if(a-(int)a==0)	
	{printf("%.0lfx^2 ",a); }
	else			
	{printf("%lfx^2 ",a);	}

	if(a!=0)
	{
		if	   (b==1)	
		{printf("+ x ");        }
		else if(b==-1)	
		{printf("+ -x ");		}
		else if(b==0)	
		{				        }
		else if(b-(int)b==0)
		{printf("+ %.0fx ",b);	}
		else			
		{printf("+ %lfx ",b);   }
	}
	else
	{
		if	   (b==1)	
		{printf("x ");       	}
		else if(b==-1)	
		{printf("-x ");			}
		else if(b==0)	
		{				        }
		else if(b-(int)b==0)
		{printf("%.0fx ",b);		}
		else			
		{printf("%lfx ",b);   	}
	}

	if(a==0 && b==0) 
	{
		if(c-(int)c==0)
		{printf("%.0lf",c);		}
		else
		{printf("%lf",c);		}
	}
	else
	{
		if(c-(int)c==0)
		{printf("+ %.0lf",c);	}
		else
		{printf("+ %lf",c);		}
	}
	///
	printf("\n");

	//// interval
	printf("Please enter the interval [s,t] : ");
	scanf("%lf %lf",&s,&t);
	////
	
	if(s > t)
	{
		printf("t must be larger than s");
		return 0;
	}
	
	///// mathametic integral
	double is,it;  //integral at s & t
	
	printf("The interval is ");
	
	it = (a*t*t*t/3)+(b*t*t/2)+(c*t);
	is = (a*s*s*s/3)+(b*s*s/2)+(c*s);
	
	printf("%lf\n",it-is);
	/////
	
	//////Riemann Sum
	double rs;
	
	for(int i = 2; i <= 65536; i*=2)
	{
		double x;    // f(x)
		double ans;
		double temp = 0; 
		printf("The Riemann sum of n=%d: ",i);
		
		
		for(int j = 0; j < i; j++)
		{
			x = s + ((t-s)/i)*j ;
			temp += ((a*x*x) + (b*x) + c );
		}
		ans = temp * (t-s)/i ;
		
		printf("%lf\n",ans);
	}
	//
	return 0;
}
