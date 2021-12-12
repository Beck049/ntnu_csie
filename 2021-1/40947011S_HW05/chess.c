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

#include "chess.h"

#define ASCII_ESC "\033"

#define BOLD ASCII_ESC"[1m"
#define FLASH ASCII_ESC"[5m"

#define RST ASCII_ESC"[0m"
#define RED ASCII_ESC"[31m"
#define GRN ASCII_ESC"[32m"
#define YLW ASCII_ESC"[33m"
#define BL ASCII_ESC"[34m" 
#define MGT ASCII_ESC"[35m"
#define CYN ASCII_ESC"[36m"
#define WHT ASCII_ESC"[37m"
#define GRY ASCII_ESC"[90m"
#define LRED ASCII_ESC"[91m"
#define LGRN ASCII_ESC"[92m"
#define LYLW ASCII_ESC"[93m"
#define LBL ASCII_ESC"[94m"
#define LMGT ASCII_ESC"[95m"
#define LCYN ASCII_ESC"[96m"
#define LWHT ASCII_ESC"[97m"

void turn_on(int code) // code is the destination in map
{
    char out = 0;
    if( 0 <= code && code < 7)
    {// black
        out = 49 + code;
        printf(BL"%c"RST, out); // 1 ~ 7
    }
    else if( 7 <= code && code < 14)
    {// red
        out = 65 + code - 7;
        printf(RED"%c"RST, out); // A ~ G
    }
    else
    {
        out = 35;
        printf(MGT"%c"RST, out);
    }
    return;
}

void check(int situation, int code) // code is the destination in map
{
    char out = 0;
    if(situation == 0)
    {
        out = 42;
        printf("%c", out);
    }
    else if(situation == 1)
    {
        turn_on(code);
    }
    else if(situation == -1)
    {
        out = 32;
        printf("%c", out);
    }
    else
    {
        out = 35;
        printf(MGT"%c"RST, out);
    }
    return;
}

void print_map(int* map, int* situation)
{
    printf("  1 2 3 4 5 6 7 8 \n");
    printf(" +---------------+\n");
    printf("1|");
    for(int i = 0; i < 8; i++)
    {
        check(situation[i], map[i]);
        printf("|");
    }
    printf("\n");
    printf(" |---------------|\n");
    printf("2|");
    for(int i = 8; i < 16; i++)
    {
        check(situation[i], map[i]);
        printf("|");
    }
    printf("\n");
    printf(" |---------------|\n");
    printf("3|");
    for(int i = 16; i < 24; i++)
    {
        check(situation[i], map[i]);
        printf("|");
    }
    printf("\n");
    printf(" |---------------|\n");
    printf("4|");
    for(int i = 24; i < 32; i++)
    {
        check(situation[i], map[i]);
        printf("|");
    }
    printf("\n");
    printf(" +---------------+\n");

    return;
}
void print_ans(int* map)
{
    printf("  1 2 3 4 5 6 7 8 \n");
    printf(" +---------------+\n");
    printf("1|");
    for(int i = 0; i < 8; i++)
    {
        turn_on(map[i]);
        printf("|");
    }
    printf("\n");
    printf(" |---------------|\n");
    printf("2|");
    for(int i = 8; i < 16; i++)
    {
        turn_on(map[i]);
        printf("|");
    }
    printf("\n");
    printf(" |---------------|\n");
    printf("3|");
    for(int i = 16; i < 24; i++)
    {
        turn_on(map[i]);
        printf("|");
    }
    printf("\n");
    printf(" |---------------|\n");
    printf("4|");
    for(int i = 24; i < 32; i++)
    {
        turn_on(map[i]);
        printf("|");
    }
    printf("\n");
    printf(" +---------------+\n");


    return;
}

void set_map  (int* map, int* situation, int* number)
{
    int temp = 0;
    srand(time(NULL));

    for(int i = 0; i < 32; i++)
    {
        while(1)
        {
            temp = rand() % 14;

            if(number[temp] > 0)
            {
                number[temp]--;
                map[i] = temp;
                break;
            }
        }
    }

    return;
}

int get_position(int x, int y)
{
    int pos;
    pos = (x-1) + ((y-1)*8);
    return pos;
}

int get_situation(int* situation, int x, int y)
{
    int s;
    s = situation[(x-1) + (y-1)*8];
    return s;
}
int get_code(int* map, int x, int y)
{
    int c;
    c = map[(x-1) + (y-1)*8];
    return c;
}
int is_red(int code)
{
    if( code >= 0 && code <= 6 )
    {
        return 0; // is_black
    }
    else if( code >= 7 && code <= 13 )
    {
        return 1; // is_red
    }
    else
    {
        return -1; // error
    }
}

void what_color(int* color, int i)
{
    if(color[i] == 1)
    {
        printf(RED"You are red\n"RST);
        return;
    }
    else if(color[i] == 0)
    {
        printf(BL"You are blue\n"RST);
        return;
    }
    else
    {
        printf(MGT"Error\n"RST);
        return;
    }
}

int moveable(int x1, int y1, int x2, int y2)
{
    int pos1 = get_position(x1, y1);
    int pos2 = get_position(x2, y2);

    if(pos1 == 0)
    { // up left
        if(pos2 == 1 || pos2 == 8)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(pos1 == 7)
    { // up right
        if(pos2 == 6 || pos2 == 15)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(pos1 == 24)
    { // down left
        if(pos2 == 16 || pos2 == 25)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(pos1 == 31)
    { // down right
        if(pos2 == 23 || pos2 == 30)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if( x1 == 1 )
    { // x == 1
        if( x2 == 1 && abs(y1 - y2) == 1)
        {
            return 1;
        }
        else if( y1 == y2 && x2 == 2 )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if( x1 == 8 )
    { // x == 8
        if( x2 == 8 && abs(y1 - y2) == 1)
        {
            return 1;
        }
        else if( y1 == y2 && x2 == 7 )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if( y1 == 1 )
    { // y == 1
        if( y2 == 1 && abs(x1 - x2) == 1 )
        {
            return 1;
        }
        else if( x1 == x2 && y2 == 2 )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if( y1 == 4 )
    { // y == 4
        if( y2 == 4 && abs(x1 - x2) == 1 )
        {
            return 1;
        }
        else if( x1 == x2 && y2 == 3 )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    { // in the middle
        if( x1 == x2 && abs(y1 - y2) == 1 )
        {
            return 1;
        }
        else if( y1 == y2 && abs(x1 - x2) == 1 )
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    return 0;
}

int edible(int code1, int code2)
{
    if( is_red(code1) == is_red(code2) )
    {
        return 0;
    }
    else
    {
        int c1 = (code1%7) +1;
        int c2 = (code2%7) +1;

        if(c1 == 1)
        {
            if(c2 != 7)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else if(c1 == 6)
        {
            return 1;
        }
        else if(c1 == 7)
        {
            if(c2 == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            if(c1 <= c2)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }

    return 0;
}

int approachable(int* situation, int code1, int x1, int y1, int x2, int y2)
{
    int c = (code1%7) +1;
    int ret = 0;
    if( c == 6 )
    {
        int count = 0;
        if(x1 == x2 && y1 == y2)
        {
            return 0;
        }
        else if( x1 == x2 )
        {
            if( y1 > y2 )
            {
                for(int i = y2+1 ; i < y1; i++)
                {
                    if( get_situation(situation, x1, i) != -1 )
                    {
                        count++;
                    }
                }
                return count;
            }
            else if( y1 < y2 )
            {
                for(int i = y1+1 ; i < y2; i++)
                {
                    if( get_situation(situation, x1, i) != -1 )
                    {
                        count++;
                    }
                }
                return count;
            }
        }
        else if( y1 == y2 )
        {
            if( x1 > x2 )
            {
                for(int i = x2+1 ; i < x1; i++)
                {
                    if( get_situation(situation, i, y1) != -1 )
                    {
                        count++;
                    }
                }
                return count;
            }
            else if( x1 < x2 )
            {
                for(int i = x1+1 ; i < x2; i++)
                {
                    if( get_situation(situation, i, y1) != -1 )
                    {
                        count++;
                    }
                }
                return count;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        ret = moveable(x1, y1, x2, y2);
        return ret;
    }

    return 0;
}

int end_game(int red, int black)
{
    if(red == 16)
    {
        printf(BL"Blue Wins ! \n"RST);
        return 1;
    }
    else if(black == 16)
    {
        printf(RED"Red Wins ! \n"RST);
        return 1;
    }
    else
    {
        return 0;
    }
}