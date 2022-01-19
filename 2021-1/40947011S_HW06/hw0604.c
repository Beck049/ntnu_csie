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

// this is how we call the function below
void (*funcS[110])();
void (*func1[110])();
void (*func2[110])();
void (*func5[110])();
void (*func6[110])();

void start();
void s1();
void s2();
void s3();
void s4();
void s5();
void s6();
void final();

int32_t inputNum() {
    printf( "Please enter an integer: " );
    int64_t n;
    scanf( "%ld", &n );
    // a really smart way to reduce the big number
    n = (n % 110) * (!(n / 110));
    return  (int32_t)n;
}

// initialise the function pointer that puts in the array
void init( void (*funcArr[])(), void (*func)() )
{
    for ( int i = 0; i < 110; i++ )
    {
        funcArr[i] = func;
    }
}

int main()
{
    init( funcS, start ); // all input goes to "start"
    init( func1, s1    ); // all input goes to "s1"
    init( func2, start ); // all input goes to "start"
    init( func5, start ); // all input goes to "start"
    init( func6, s5    ); // all input goes to "s5"
    
    start();
    
    return 0;
}


void start()
{
    printf( "Start\n" );
    // set special functions
    funcS[10] = funcS[35] = s1;
    funcS[11] = s3;
    funcS[20] = funcS[78] = s5;
    // call the function
    funcS[inputNum()]();
    
}

void s1()
{
    printf( "S1\n" );
    // set special functions
    func1[19] = s2;
    func1[12] = func1[36] = s6;
    // call the function
    func1[inputNum()]();
}

void s2()
{
    printf( "S2\n" );
    // set special functions
    func2[43] = s2;
    func2[99] = final;
    // call the function
    func2[inputNum()]();
}

void s3()
{
    printf( "S3\n" );
    // directly go to s4
    s4( inputNum() );
}

void s4()
{
    printf( "S4\n" );
    // directly gp to s6
    s6( inputNum() );
}

void s5()
{
    printf( "S5\n" );
    // set special functions
    func5[1] = s4;
    func5[2] = s6;
    // call the function
    func5[inputNum()]();
}

void s6()
{
    printf( "S6\n" );
    // set special functions
    func6[108] = final;
    // call the function
    func6[inputNum()]();
}

void final() 
{
    printf( "Final\n" );
}

