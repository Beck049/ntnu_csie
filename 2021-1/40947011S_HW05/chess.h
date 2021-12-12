#pragma once
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

#include "chess.c"

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

    // y  1  2  3  4  5  6  7  8
    //   +-----------------------+ x
    // 1 |00|01|02|03|04|05|06|07|
    //   +-----------------------+
    // 2 |08|09|10|11|12|13|14|15|
    //   +-----------------------+
    // 3 |16|17|18|19|20|21|22|23|
    //   +-----------------------+
    // 4 |24|25|26|27|28|29|30|31|
    //   +-----------------------+

void set_map  (int* map, int* situation, int* number);
void print_map(int* map, int* situation);
void print_ans(int* map);

void turn_on(int code);
// find and print the corresponding character
void check(int situation, int code);
// check the situation and print the sign

int get_situation(int* situation, int x, int y);
// return the situation
// 0 = covered // 1 = opened // -1 = blank //
int get_code(int* map, int x, int y);
// return the code

int get_position(int x, int y);
// return the position in 1D array
int get_situation(int* situation, int x, int y);
// given x,y return situation
int get_code(int* map, int x, int y);
// given x,y return code
int is_red(int code);
// given code, return is red or not
// 1 = red // 0 = black // -1 = error //

void what_color(int* color, int i);
// tell the player what color they are

int moveable(int x1, int y1, int x2, int y2);
// check if two point is adjust , true = 1

int edible(int code1, int code2);
// check if code1 can eat code2 , true = 1
int approachable(int* situation, int code1, int x1, int y1, int x2, int y2);
// check if approachable , true = 1

int end_game(int red, int black);
// print winner team , return 1 if end