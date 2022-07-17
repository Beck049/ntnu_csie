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

//  1/1/1 is saturday(6)

int32_t lm[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int32_t nm[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap(int);
int weekdays(int, int, int);
int trans_date(int, int, int, int);
int check(int, int, int, int, int, int, int, int, int, int);
int first_day(int);
int last_day (int);

int main()
{
    int32_t start_date = 0, end_date = 0;
    int32_t y1, y2, m1, m2, d1, d2, h1, h2, min1, min2;

    printf("From: ");
    scanf("%d/%d/%d  %d:%d", &y1, &m1, &d1, &h1, &min1);
    printf("To: ");
    scanf("%d/%d/%d  %d:%d", &y2, &m2, &d2, &h2, &min2);

    int32_t t1 = 0, t2 = 0;
    t1 = h1*60 + min1;
    t2 = h2*60 + min2;
    // 0 ~ 540 ; 720 ~ 810 ; 1080 ~ 1440 -> doesn't count

    // inspired by excel DATE functions
    // end_date - start_date = the days that passes
    start_date = trans_date(y1, d1, m1, y1);
    end_date   = trans_date(y1, d2, m2, y2);

    int32_t t = 0;

    // check errors
    if( check(y1, m1, d1, h1, min1, y2, m2, d2, h2, min2) == 1 )
    {
        printf("ERROR\n");
        return 0;
    }

//Start
    //sameday
    if(y1 == y2 && m1 == m2 && d1 == d2)
    {
// printf("Same day\n");

        if(weekdays(d1, m1, y1) != 6 && weekdays(d1, m1, y1) != 0)
        {
            // seperate the time in the form of num line (min)
            if( (t1 >= 0 && t1 <= 540) && (t2 >= 720 && t2 <= 810) )
            {
                printf("Working Hours : 3 hours 0 mins\n");
                return 0;
            }
            else if( (t1 >= 540 && t1 <= 720) && (t2 >= 720 && t2 <= 810) )
            {
                printf("Working Hours : %d hours %d mins\n", (720-t1)/60, (720-t1)%60 );
                return 0;
            }
            else if( (t1 >= 0 && t1 <= 540) && (t2 >= 540 && t2 <= 720) )
            {
                printf("Working Hours : %d hours %d mins\n", (t2-540)/60, (t2-540)%60 );
                return 0;
            }
                else if( (t1 >= 540 && t1 <= 720) && (t2 >= 540 && t2 <= 720) )
            {
                printf("Working Hours : %d hours %d mins\n", (t2-t1)/60, (t2-t1)%60 );
                return 0;
            }
            else if( (t1 >= 720 && t1 <= 810) && (t2 >= 1110 && t2 <= 1440) )
            {
                printf("Working Hours : 5 hours 0 mins\n");
                return 0;
            }
            else if( (t1 >= 720 && t1 <= 810) && (t2 >= 810 && t2 <= 1110) )
            {
                printf("Working Hours : %d hours %d mins\n", (t2-810)/60, (t2-810)%60 );
                return 0;
            }
            else if( (t1 >= 810 && t1 <= 1110) && (t2 >= 1110 && t2 <= 1440) )
            {
                printf("Working Hours : %d hours %d mins\n", (1110-t1)/60, (1110-t1)%60 );
                return 0;
            }
            else if( (t1 >= 810 && t1 <= 1110) && (t2 >= 810 && t2 <= 1110) )
            {
                printf("Working Hours : %d hours %d mins\n", (t2-t1)/60, (t2-t1)%60 );
                return 0;
            }
            else if( (t1 >= 0 && t1 <= 540) && (t2 >= 1110 && t2 <= 1440) )
            {
                printf("Working Hours : 8 hours 0 mins\n");
                return 0;
            }
            else if( (t1 >= 540 && t1 <= 720) && (t2 >= 1110 && t2 <= 1440) )
            {
                printf("Working Hours : %d hours %d mins\n", (720-t1)/60 + 5, (720-t1)%60 );
                return 0;
            }
            else if( (t1 >= 0 && t1 <= 540) && (t2 >= 810 && t2 <= 1110) )
            {
                printf("Working Hours : %d hours %d mins\n", (t2-810)/60 + 3, (t2-810)%60 );
                return 0;
            }
            else if( (t1 >= 540 && t1 <= 720) && (t2 >= 810 && t2 <= 1110) )
            {
                printf("Working Hours : %d hours %d mins\n", (t2-t1-90)/60, (t2-t1-90)%60 );
                return 0;
            }
            else 
            {
                printf("Working Hours : 0 hours 0 mins\n" );
                return 0;
            }
        }
    }
    //two day
    else if( trans_date(y1, d1, m1, y1) +1 == trans_date(y1, d2, m2, y2) )
    {
// printf("Two days\n");

        int32_t th = 0, tt = 0;

// printf("date_value1 = %d\n", trans_date(y1, d2, m2, y2));
// printf("date_value2 = %d\n", trans_date(y1, d1, m1, y1));

        //th : the first day contains ?? min
        th = first_day(t1);

// printf("th : %d\n", th);
        //tt : the last day contains ?? min
        tt = last_day(t2);
        
// printf("tt : %d\n", tt);
        // ignore if tt, th are weekend
        t = 0;
        if(weekdays(d1, m1, y1) != 6 && weekdays(d1, m1, y1) != 0)
        {
            t += th;
        }
        if(weekdays(d2, m2, y2) != 6 && weekdays(d2, m2, y2) != 0)
        {
            t += tt;
        }
// printf("Working Hours : %d hours %d mins\n", th/60, th%60);
// printf("Working Hours : %d hours %d mins\n", tt/60, tt%60);
        printf("Working Hours : %d hours %d mins\n", t/60, t%60);
    }
    // others
    else
    {
// printf("Other\n");

        int32_t th = 0, tt = 0, dur = 0;
        //th : the first day contains ?? min
        th = first_day(t1);

        //tt : the last day contains ?? min
        tt = last_day(t2);

        // ignore if tt, th are weekend
        if(weekdays(d1, m1, y1) != 6 && weekdays(d1, m1, y1) != 0)
        {
            t += th;
        }
        if(weekdays(d2, m2, y2) != 6 && weekdays(d2, m2, y2) != 0)
        {
            t += tt;
        }

        dur = (trans_date(y1, d2, m2, y2) - trans_date(y1, d1, m1, y1) -1);
// printf("date_value1 = %d\n", trans_date(y1, d2, m2, y2));
// printf("date_value2 = %d\n", trans_date(y1, d1, m1, y1));
// printf("DUR : %d\n", dur);

        t += 60*8*5*(dur/7) ; // for every 7 days contains 40 hours

        // count the rest of the days from the second day
        int week = weekdays(d1, m1, y1);
        for(int i = 0; i < dur%7; i++);
        {
            if(week != 6 && week != 0)
            {
                t += 60*8;
            }
            week = (week+1)%7;
        }

        printf("Working Hours : %d hours %d mins\n", t/60, t%60);
    }

    return 0;
}

int first_day(int t1) {
    if(t1 <= 540)
    {
        return 480;
    }
    else if(t1 <= 720)
    {
        return 300 + (720 - t1);
    }
    else if(t1 <= 810)
    {
        return 300;
    }
    else if(t1 <= 1110)
    {
        return (1110 - t1);
    }
    else
    {
        return 0;
    }
}
int last_day(int t2) {
    if(t2 <= 540)
    {
        return 0;
    }
    else if(t2 <= 720)
    {
        return (t2 - 540);
    }
    else if(t2 <= 810)
    {
        return 300;
    }
    else if(t2 <= 1110)
    {
        return 300 + (t2 - 810);
    }
    else
    {
        return 480;
    }   
}
int leap(int year)
{
    if( year%400 == 0 || ( year%4 == 0 && year%1000 != 0 ) )
    {
        return 366; // yes
    }
    else
    {
        return 365; // no
    }
}

int weekdays(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

int trans_date(int con, int day, int month, int year)
{
    int32_t ret = 0;
    
    if(con == year)
    {
        if(leap(year) == 366)
        {
            for(int i = 1; i < month; i++)
            {
                ret += lm[i]; 
            }
        }
        else
        {
            for(int i = 1; i < month; i++)
            {
                ret += nm[i]; 
            }
        }

        ret += day;
    }
    else
    {
        while(year > con)
        {
            ret += leap(con);
            con++;
        }
        if(leap(year) == 366)
        {
            for(int i = 1; i < month; i++)
            {
                ret += lm[i]; 
            }
        }
        else
        {
            for(int i = 1; i < month; i++)
            {
                ret += nm[i]; 
            }
        }
        ret += day;
    }

    return ret;
}

int check(int y1, int m1, int d1, int h1, int min1, int y2, int m2, int d2, int h2, int min2)
{
    if(m1 > 12 || m1 < 1 || m2 > 12 || m2 < 1 )
    { return 1; }
    if(h1 > 23 || h1 < 0 || h2 > 23 || h2 < 0 )
    { return 1; }
    if(min1 > 60 || min1 < 0 || min2 > 60 || min2 < 0 )
    { return 1; }

    if(leap(y1) == 366)
    {
        if( d1 > lm[m1] || d1 < 0)
        { return 1; }
    }
    else if(leap(y1) == 365)
    {
        if( d1 > nm[m1] || d1 < 0)
        { return 1; }
    }

    if(leap(y2) == 366)
    {
        if( d2 > lm[m2] || d2 < 0)
        { return 1; }
    }
    else if(leap(y2) == 365)
    {
        if( d2 > nm[m2] || d2 < 0)
        { return 1; }
    }

    if(y1 > y2){ return 1; }
    else if(y1 == y2)
    {
        if(m1 > m2){ return 1; }
        else if(m1 == m2)
        {
            if(d1 > d2){ return 1; }
            else if(d1 == d2)
            {
                if(h1 > h2){ return 1; }
                else if(h1 == h2)
                {
                    if(min1 > min2){ return 1; }
                    else{ return 0; }
                }
                else{ return 0;}
            }
            else
            { return 0; }
        }
        else
        { return 0; }
    }
    else{ return 0; }

    return 0;
}