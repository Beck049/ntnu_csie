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

int main()
{
    int chess[14] = {1, 2, 2, 2, 2, 2, 5, 1, 2, 2, 2, 2, 2, 5};
    // save the amount of all kind
    // seq of 將士象車馬包卒 帥仕相車馬炮兵 // %7 +1
    int red   = 0; // count of eaten red
    int black = 0; // count of eaten black
    int situation[32] = {0};
    // 0 = covered // 1 = opened // -1 = blank //
    int map[32] = {0};
    // save the chess number , -1 to be blank

    set_map  (map, situation, chess);
    // print_ans(map);

    print_map(map, situation);

    // start game
    int x1, x2, y1, y2;
    int color[3] = {0}; // 0 = black ; 1 = red

    start:
        printf("Player 1 (x, y): ");
        if( scanf("%d, %d", &x1, &y1) == 2 && x1>0 && x1<=8 && y1>0 && y1<=4 )
        {
            situation[get_position(x1, y1)] = 1;
            if( is_red( get_code(map, x1, y1) ) == 1 )
            {
                color[1] = 1;
            }
            else if( is_red( get_code(map, x1, y1) ) == 0 )
            {
                color[2] = 1;
            }
            else
            {
                printf(YLW"Error\n"RST);
                return 0;
            }
        }
        else
        {
            printf("Wrong input 1\n");
            goto start;
        }

        print_map(map, situation);

    while(1)
    {
    player2:
        what_color(color, 2);
        printf("Player 2 (x, y): ");
        if( scanf("%d, %d", &x1, &y1) == 2 && x1>0 && x1<=8 && y1>0 && y1<=4 )
        {
            if( get_situation(situation, x1, y1) == -1 )
            { // blank
                printf("There\'s nothing here\n");
                goto player2;
            }
            else if( get_situation(situation, x1, y1) == 0 )
            { // covered -> open it
                situation[get_position(x1, y1)] = 1;
            }
            else
            { // is opened
                if( is_red( get_code(map, x1, y1) ) == color[2] )
                { // is your chess
                    printf("To (x, y): ");
                    if( scanf("%d, %d", &x2, &y2) == 2 && x1>0 && x1<=8 && y1>0 && y1<=4 )
                    {
                        if( get_situation(situation, x2, y2) == -1 )
                        { // blank
                            // check if moveable ///////////////////////
                            if( moveable(x1, y1, x2, y2) == 1 )
                            {
                                situation[ get_position(x2, y2) ] = situation[ get_position(x1, y1) ];
                                map[ get_position(x2, y2) ] = map[ get_position(x1, y1) ];
                                situation[ get_position(x1, y1) ] = -1;
                                map[ get_position(x1, y1) ] = -1;
                            }
                            else if( moveable(x1, y1, x2, y2) == 0 )
                            {
                                printf("You can\'t move here\n");
                                goto player2;
                            }
                        }
                        else if( get_situation(situation, x2, y2) == 0 )
                        { // closed
                            printf("Yoy can\'t do anything to it\n");
                            goto player2;
                        }
                        else if( color[2] == is_red( get_code(map, x1, y1) ) )
                        { // opened
                            if( is_red( get_code(map, x1, y1) ) == is_red( get_code(map, x2, y2) ) )
                            { // same color
                                printf("Yor can\'t eat your chess\n");
                                goto player2;
                            }
                            else
                            { // diff color
                                int eat = 0, approach = 0;
                                // eat
                                eat = edible( get_code(map, x1, y1), get_code(map, x2, y2) );
                                // approach
                                approach = approachable( situation, get_code(map, x1, y1), x1, y1, x2, y2 );


                                if( eat == 1 && approach == 1 )
                                { // can eat
                                    if( is_red( get_code(map, x2, y2) ) == 1 )
                                    {
                                        red++;
                                    }
                                    else if ( is_red( get_code(map, x2, y2) ) == 0 )
                                    {
                                        black++;
                                    }

                                    situation[ get_position(x2, y2) ] = situation[ get_position(x1, y1) ];
                                    map[ get_position(x2, y2) ] = map[ get_position(x1, y1) ];
                                    situation[ get_position(x1, y1) ] = -1;
                                    map[ get_position(x1, y1) ] = -1;
                                    
                                }
                                else if( eat != 1 )
                                {
                                    printf("You can\'t eat that chess\n");
                                    goto player2;
                                }
                                else if( approach != 1 )
                                {
                                    printf("You can\'t reach this far (%d)\n", approach);
                                    goto player2;
                                }
                                else
                                {
                                    printf(YLW"Error\n"RST);
                                    goto player2;
                                }
                            }
                        }
                        else
                        {
                            printf("You can only move your chess\n");
                            goto player2;
                        }
                    }
                    else
                    {
                        printf("Wrong input 2\n");
                        goto player2;
                    }
                }
                else
                { // not your chess
                    printf("This is not your chess\n");
                    goto player2;
                }
            }
        }
        else
        {
            printf("Wrong input 1\n");
            goto player2;
        }

        print_map(map, situation);

        if( end_game(red, black) == 1 )
        {
            break;
        }

    player1:
        what_color(color, 1);
        printf("Player 1 (x, y): ");

        if( scanf("%d, %d", &x1, &y1) == 2 && x1>0 && x1<=8 && y1>0 && y1<=4 )
        {
            if( get_situation(situation, x1, y1) == -1 )
            { // blank
                printf("There\'s nothing here\n");
                goto player1;
            }
            else if( get_situation(situation, x1, y1) == 0 )
            { // covered -> open it
                situation[get_position(x1, y1)] = 1;
            }
            else
            { // is opened
                if( is_red( get_code(map, x1, y1) ) == color[1] )
                { // is your chess
                    printf("To (x, y): ");
                    if( scanf("%d, %d", &x2, &y2) == 2 && x1>0 && x1<=8 && y1>0 && y1<=4 )
                    {
                        if( get_situation(situation, x2, y2) == -1 )
                        { // blank
                            // check if moveable ///////////////////////
                            if( moveable(x1, y1, x2, y2) == 1 )
                            {
                                situation[ get_position(x2, y2) ] = situation[ get_position(x1, y1) ];
                                map[ get_position(x2, y2) ] = map[ get_position(x1, y1) ];
                                situation[ get_position(x1, y1) ] = -1;
                                map[ get_position(x1, y1) ] = -1;
                            }
                            else if( moveable(x1, y1, x2, y2) == 0 )
                            {
                                printf("You can\'t move here\n");
                                goto player1;
                            }
                        }
                        else if( get_situation(situation, x2, y2) == 0 )
                        { // closed
                            printf("Yoy can\'t do anything to it\n");
                            goto player1;
                        }
                        else if( color[1] == is_red( get_code(map, x1, y1) ) )
                        { // opened
                            if( is_red( get_code(map, x1, y1) ) == is_red( get_code(map, x2, y2) ) )
                            { // same color
                                printf("Yor can\'t eat your chess\n");
                                goto player1;
                            }
                            else
                            { // diff color
                                int eat = 0, approach = 0;
                                // eat
                                eat = edible( get_code(map, x1, y1), get_code(map, x2, y2) );
                                // approach
                                approach = approachable( situation, get_code(map, x1, y1), x1, y1, x2, y2 );


                                if( eat == 1 && approach == 1 )
                                { // can eat
                                    if( is_red( get_code(map, x2, y2) ) == 1 )
                                    {
                                        red++;
                                    }
                                    else if ( is_red( get_code(map, x2, y2) ) == 0 )
                                    {
                                        black++;
                                    }

                                    situation[ get_position(x2, y2) ] = situation[ get_position(x1, y1) ];
                                    map[ get_position(x2, y2) ] = map[ get_position(x1, y1) ];
                                    situation[ get_position(x1, y1) ] = -1;
                                    map[ get_position(x1, y1) ] = -1;
                                    
                                }
                                else if( eat != 1 )
                                {
                                    printf("You can\'t eat that chess\n");
                                    goto player1;
                                }
                                else if( approach != 1 )
                                {
                                    printf("You can\'t reach this far (%d)\n", approach);
                                    goto player1;
                                }
                                else
                                {
                                    printf(YLW"Error\n"RST);
                                    goto player1;
                                }
                            }
                        }
                        else
                        {
                            printf("You can only move your chess\n");
                            goto player1;
                        }
                    }
                    else
                    {
                        printf("Wrong input 2\n");
                        goto player1;
                    }
                }
                else
                { // not your chess
                    printf("This is not your chess\n");
                    goto player1;
                }
            }
        }
        else
        {
            printf("Wrong input 1\n");
            goto player1;
        }

        print_map(map, situation);

        if( end_game(red, black) == 1 )
        {
            break;
        }

    }

    return 0;
}