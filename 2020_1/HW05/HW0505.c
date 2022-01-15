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

int enter_width (int, int); //(max, min)
int enter_height(int, int); //(max, min)
int enter_mine  (int, int); //(max, min)

int check_input (int, int, int); // check the input values (value, max, min)

int init_game (int*, int, int, int);// set mine, set number, print map
int set_mine  (int*, int, int, int);// randomly choose different numberto set the mine
int set_number(int*, int, int, int);// for every not mine block, check how many mines around

int open (int*, int, int, int, int);// if is mine then lose
                                    // if blank then open the block around
int flag (int*, int, int, int, int);

int check_mine(int*, int, int, int);// check if wins, else keep going

void print_map(int*, int, int); // closed(0) , flaged(-1) , opened(1)
void print_ans(int*, int, int); // print answers (numbers, blank, bomb==-1)

int main()
{
    int width = 0, height = 0, mine = 0;

    width  = enter_width (16, 10);
    height = enter_height(16, 10);
    mine   = enter_mine  (90, 30);
 // printf("%d %d %d", width, height, mine);

// open the map for game
    int *map = (int*)calloc(width*height*2,sizeof(int));
                            // use two digit to form a block ( status, opened? )
    init_game(map, width, height, mine);
    print_ans(map, width, height);

    int row, col; // i, j //
    int over = 0;
    int opt = 0;
    while( over != 1)
    {
    option:
        printf("Your option (1)Open (2)Flag :");
        scanf("%d", &opt);
        if(check_input(opt, 2, 1) == 1)
        {
            goto option;
        }
        
        switch(opt)
        {
            case 1:
                printf("Position to open (row, column) :");
                scanf("%d %d", &row, &col);
                if(check_input(col, width-1 , 0) == 1)
                {
                    break;
                }
                if(check_input(row, height-1, 0) == 1)
                {
                    break;
                }
                over = open(map, row, col, width, height);
                print_map(map, width, height);
                break;

            case 2:
                printf("Position to flag / unflag (row, column) :");
                scanf("%d %d", &row, &col);
                if(check_input(col, width-1 , 0) == 1)
                {
                    break;
                }
                if(check_input(row, height-1, 0) == 1)
                {
                    break;
                }
                over = flag(map, row, col, width, height);
                break;
        }

        if(over != 1)
        {
            over = check_mine(map, width, height, mine);
        }
    }
}

///////////////////////////////////////////////////////////////////////
int check_mine(int* map, int width, int height, int mine)
{
    int count = 0;
    int flaged_mine = 0;
    // winning condition
    // 1. open all the avaliable block
    // 2. flag all the mine

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            // 1. open all the avaliable block
            // if isOpened
            if( map[(j*width + i)*2 +1] == 1 )
            {
                count++;
            }
            // 2. flag all the mine
            // if isFlaged && isBomb , ++
            else if( map[(j*width + i)*2 +1] == -1 && map[(j*width + i)*2 ] == -1 )
            {
                flaged_mine++;
            }
            // if isFlaged && isNotBomb , --
            else if( map[(j*width + i)*2 +1] == -1 && map[(j*width + i)*2 ] != -1 )
            {
                flaged_mine--;
            }
        }
    }
    
// winning conditions
    // 1. open all the avaliable block
    if(count == width*height - mine)
    {
        printf("You Win !!");
        print_ans(map, width, height);
        return 1;
    }
    // 2. flag all the mine
    if(flaged_mine == mine)
    {
        printf("You Win !!");
        print_ans(map, width, height);
        return 1;
    }

    return 0;
}
int open(int* map, int row, int col, int width, int height)
{
    if( map[(row*width + col)*2 +1] == 0 ) // not opened yet
    {
        if( map[(row*width + col)*2] == -1 ) // a bomb
        {
            printf("You Lose ...");
            return 1;
        }
        else if( map[(row*width + col)*2] == 0 ) // value 0
        {
            map[(row*width + col)*2 +1] = 1;
    ////
            if(row == 0 && col == 0) // if 左上角
                {
                    // printf("left up\n");
                    // 6
                        if(map[((row)*width + (col+1))*2] == 0 && map[(row*width + (col+1))*2 +1] == 0)
                        { open(map, row, col+1, width, height); }
                        map[((row)*width + (col+1))*2 +1] = 1;
                    // 8
                        if(map[((row+1)*width + (col))*2] == 0 && map[((row+1)*width + col)*2 +1] == 0)
                        { open(map, row+1, col, width, height); }
                        map[((row+1)*width + (col))*2 +1] = 1;
                    // 9
                        if(map[((row+1)*width + (col+1))*2] == 0 && map[((row+1)*width + (col+1))*2 +1] == 0)
                        { open(map, row+1, col+1, width, height); }
                        map[((row+1)*width + (col+1))*2 +1] = 1;
                }
                else if(row == 0 && col == 9) // if 右上角
                {
                    // printf("right up\n");
                    // 4
                        if(map[((row)*width + (col-1))*2] == 0 && map[(row*width + (col-1))*2 +1] == 0)
                        { open(map, row, col-1, width, height); }
                        map[((row)*width + (col-1))*2 +1] = 1;
                    // 7
                        if(map[((row+1)*width + (col-1))*2] == 0 && map[((row+1)*width + (col-1))*2 +1] == 0)
                        { open(map, row+1, col-1, width, height); }
                        map[((row+1)*width + (col-1))*2 +1] = 1;
                    // 8
                        if(map[((row+1)*width + (col))*2] == 0 && map[((row+1)*width + col)*2 +1] == 0)
                        { open(map, row+1, col, width, height); }
                        map[((row+1)*width + (col))*2 +1] = 1;
                }
                else if(row == 9 && col == 0) // if 左下角
                {
                    // printf("left down\n");
                    // 2
                        if(map[((row-1)*width + (col))*2] == 0 && map[((row-1)*width + col)*2 +1] == 0)
                        { open(map, row-1, col, width, height); }
                        map[((row-1)*width + (col))*2 +1] = 1;
                    // 3
                        if(map[((row-1)*width + (col+1))*2] == 0 && map[((row-1)*width + (col+1))*2 +1] == 0)
                        { open(map, row-1, col+1, width, height); }
                        map[((row-1)*width + (col+1))*2 +1] = 1;
                    // 6
                        if(map[((row)*width + (col+1))*2] == 0 && map[(row*width + (col+1))*2 +1] == 0)
                        { open(map, row, col+1, width, height); }
                        map[((row)*width + (col+1))*2 +1] = 1;
                }
                else if(row == 9 && col == 9) // if 右下角
                {
                    // printf("right down\n");
                    // 1
                        if(map[((row-1)*width + (col-1))*2] == 0 && map[((row-1)*width + (col-1))*2 +1] == 0)
                        { open(map, row-1, col-1, width, height); }
                        map[((row-1)*width + (col-1))*2 +1] = 1;
                    // 2
                        if(map[((row-1)*width + (col))*2] == 0 && map[((row-1)*width + col)*2 +1] == 0)
                        { open(map, row-1, col, width, height); }
                        map[((row-1)*width + (col))*2 +1] = 1;
                    // 4
                        if(map[((row)*width + (col-1))*2] == 0 && map[(row*width + (col-1))*2 +1] == 0)
                        { open(map, row, col-1, width, height); }
                        map[((row)*width + (col-1))*2 +1] = 1;
                }
                else if(col == 0) // if 第一列
                {
                    // printf("col = 0\n");
                    // 2
                        if(map[((row-1)*width + (col))*2] == 0 && map[((row-1)*width + col)*2 +1] == 0)
                        { open(map, row-1, col, width, height); }
                        map[((row-1)*width + (col))*2 +1] = 1;
                    // 3
                        if(map[((row-1)*width + (col+1))*2] == 0 && map[((row-1)*width + (col+1))*2 +1] == 0)
                        { open(map, row-1, col+1, width, height); }
                        map[((row-1)*width + (col+1))*2 +1] = 1;
                    // 6
                        if(map[((row)*width + (col+1))*2] == 0 && map[(row*width + (col+1))*2 +1] == 0)
                        { open(map, row, col+1, width, height); }
                        map[((row)*width + (col+1))*2 +1] = 1;
                    // 8
                        if(map[((row+1)*width + (col))*2] == 0 && map[((row+1)*width + col)*2 +1] == 0)
                        { open(map, row+1, col, width, height); }
                        map[((row+1)*width + (col))*2 +1] = 1;
                    // 9
                        if(map[((row+1)*width + (col+1))*2] == 0 && map[((row+1)*width + (col+1))*2 +1] == 0)
                        { open(map, row+1, col+1, width, height); }
                        map[((row+1)*width + (col+1))*2 +1] = 1;
                }
                else if(row == 0) // if 第一排
                {
                    // printf("row = 0\n");
                    // 4
                        if(map[((row)*width + (col-1))*2] == 0 && map[(row*width + (col-1))*2 +1] == 0)
                        { open(map, row, col-1, width, height); }
                        map[((row)*width + (col-1))*2 +1] = 1;
                    // 6
                        if(map[((row)*width + (col+1))*2] == 0 && map[(row*width + (col+1))*2 +1] == 0)
                        { open(map, row, col+1, width, height); }
                        map[((row)*width + (col+1))*2 +1] = 1;
                    // 7
                        if(map[((row+1)*width + (col-1))*2] == 0 && map[((row+1)*width + (col-1))*2 +1] == 0)
                        { open(map, row+1, col-1, width, height); }
                        map[((row+1)*width + (col-1))*2 +1] = 1;
                    // 8
                        if(map[((row+1)*width + (col))*2] == 0 && map[((row+1)*width + col)*2 +1] == 0)
                        { open(map, row+1, col, width, height); }
                        map[((row+1)*width + (col))*2 +1] = 1;
                    // 9
                        if(map[((row+1)*width + (col+1))*2] == 0 && map[((row+1)*width + (col+1))*2 +1] == 0)
                        { open(map, row+1, col+1, width, height); }
                        map[((row+1)*width + (col+1))*2 +1] = 1;
                }
                else if(row == 9) // if 最後一排
                {
                    // printf("row = 9\n");
                    // 1
                        if(map[((row-1)*width + (col-1))*2] == 0 && map[((row-1)*width + (col-1))*2 +1] == 0)
                        { open(map, row-1, col-1, width, height); }
                        map[((row-1)*width + (col-1))*2 +1] = 1;
                    // 2
                        if(map[((row-1)*width + (col))*2] == 0 && map[((row-1)*width + col)*2 +1] == 0)
                        { open(map, row-1, col, width, height); }
                        map[((row-1)*width + (col))*2 +1] = 1;
                    // 3
                        if(map[((row-1)*width + (col+1))*2] == 0 && map[((row-1)*width + (col+1))*2 +1] == 0)
                        { open(map, row-1, col+1, width, height); }
                        map[((row-1)*width + (col+1))*2 +1] = 1;
                    // 4
                        if(map[((row)*width + (col-1))*2] == 0 && map[(row*width + (col-1))*2 +1] == 0)
                        { open(map, row, col-1, width, height); }
                        map[((row)*width + (col-1))*2 +1] = 1;
                    // 6
                        if(map[((row)*width + (col+1))*2] == 0 && map[(row*width + (col+1))*2 +1] == 0)
                        { open(map, row, col+1, width, height); }
                        map[((row)*width + (col+1))*2 +1] = 1;
                }
                else if(col == 9) // if 最後一列
                {
                    // printf("col = 9\n");
                    // 1
                        if(map[((row-1)*width + (col-1))*2] == 0 && map[((row-1)*width + (col-1))*2 +1] == 0)
                        { open(map, row-1, col-1, width, height); }
                        map[((row-1)*width + (col-1))*2 +1] = 1;
                    // 2
                        if(map[((row-1)*width + (col))*2] == 0 && map[((row-1)*width + col)*2 +1] == 0)
                        { open(map, row-1, col, width, height); }
                        map[((row-1)*width + (col))*2 +1] = 1;
                    // 4
                        if(map[((row)*width + (col-1))*2] == 0 && map[(row*width + (col-1))*2 +1] == 0)
                        { open(map, row, col-1, width, height); }
                        map[((row)*width + (col-1))*2 +1] = 1;
                    // 7
                        if(map[((row+1)*width + (col-1))*2] == 0 && map[((row+1)*width + (col-1))*2 +1] == 0)
                        { open(map, row+1, col-1, width, height); }
                        map[((row+1)*width + (col-1))*2 +1] = 1;
                    // 8
                        if(map[((row+1)*width + (col))*2] == 0 && map[((row+1)*width + col)*2 +1] == 0)
                        { open(map, row+1, col, width, height); }
                        map[((row+1)*width + (col))*2 +1] = 1;
                }
                else
                {
                    // printf("other\n");
                    // 1
                        if(map[((row-1)*width + (col-1))*2] == 0 && map[((row-1)*width + (col-1))*2 +1] == 0)
                        { open(map, row-1, col-1, width, height); }
                        map[((row-1)*width + (col-1))*2 +1] = 1;
                    // 2
                        if(map[((row-1)*width + (col))*2] == 0 && map[((row-1)*width + col)*2 +1] == 0)
                        { open(map, row-1, col, width, height); }
                        map[((row-1)*width + (col))*2 +1] = 1;
                    // 3
                        if(map[((row-1)*width + (col+1))*2] == 0 && map[((row-1)*width + (col+1))*2 +1] == 0)
                        { open(map, row-1, col+1, width, height); }
                        map[((row-1)*width + (col+1))*2 +1] = 1;
                    // 4
                        if(map[((row)*width + (col-1))*2] == 0 && map[(row*width + (col-1))*2 +1] == 0)
                        { open(map, row, col-1, width, height); }
                        map[((row)*width + (col-1))*2 +1] = 1;
                    // 6
                        if(map[((row)*width + (col+1))*2] == 0 && map[(row*width + (col+1))*2 +1] == 0)
                        { open(map, row, col+1, width, height); }
                        map[((row)*width + (col+1))*2 +1] = 1;
                    // 7
                        if(map[((row+1)*width + (col-1))*2] == 0 && map[((row+1)*width + (col-1))*2 +1] == 0)
                        { open(map, row+1, col-1, width, height); }
                        map[((row+1)*width + (col-1))*2 +1] = 1;
                    // 8
                        if(map[((row+1)*width + (col))*2] == 0 && map[((row+1)*width + col)*2 +1] == 0)
                        { open(map, row+1, col, width, height); }
                        map[((row+1)*width + (col))*2 +1] = 1;
                    // 9
                        if(map[((row+1)*width + (col+1))*2] == 0 && map[((row+1)*width + (col+1))*2 +1] == 0)
                        { open(map, row+1, col+1, width, height); }
                        map[((row+1)*width + (col+1))*2 +1] = 1;
                }
    ////
        }
        else // = value
        {
            map[(row*width + col)*2 +1] = 1;
        }
    }
    else if( map[(row*width + col)*2 +1] == -1 ) // flag
    {
        printf(RED"Already flaged ...\n"RST);
    }
    else if( map[(row*width + col)*2 +1] == 1 ) // open
    {
        printf(RED"Already opened ...\n"RST);
    }

//  printf("%d %d = %d\n", row, col, map[(row*width + col)*2 +1]);
//  print_map(map, width, height);
    return 0;
}
int flag(int* map, int row, int col, int width, int height)
{
    if( map[(row*width + col)*2 +1] == 0 )
    {
        map[(row*width + col)*2 +1] = -1;
    }
    else if( map[(row*width + col)*2 +1] == -1 )
    {
        map[(row*width + col)*2 +1] = 0;
    }
    else if( map[(row*width + col)*2 +1] == 1 )
    {
        printf(RED"Already opened ...\n"RST);
    }

    print_map(map, width, height);
    return 0;
}
int init_game(int* map, int width, int height, int mine)
{
    set_mine(map, width, height, mine);
    // print_ans(map, width, height);
    set_number(map, width, height, mine);
    print_map(map, width, height);
    return 0;
}
int set_number(int* map, int width, int height, int mine)
{
    int count = 0;

    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            count = 0;
            if( map[(j*width+i)*2] == 0)
            {
                if(j == 0 && i == 0) // if 左上角
                {
                    // 9
                    if( map[((j+1)*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // 8
                    if( map[((j+1)*width + i)*2] == -1 ) 
                    {
                        count++;
                    }
                    // 6
                    if( map[(j*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(j == 0 && i == 9) // if 右上角
                {
                    // 4
                    if( map[((j)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 7
                    if( map[((j+1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 8
                    if( map[((j+1)*width + i)*2] == -1 ) 
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(j == 9 && i == 0) // if 左下角
                {
                    // 6
                    if( map[(j*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // 2
                    if( map[((j-1)*width + (i))*2] == -1 )
                    {
                        count++;
                    }
                    // 3
                    if( map[((j-1)*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(j == 9 && i == 9) // if 右下角
                {
                    // 1
                    if( map[((j-1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 2
                    if( map[((j-1)*width + (i))*2] == -1 )
                    {
                        count++;
                    }
                    // 4
                    if( map[((j)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(i == 0) // if 第一列
                {
                    // 9
                    if( map[((j+1)*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // 8
                    if( map[((j+1)*width + i)*2] == -1 )
                    {
                        count++;
                    }
                    // 6
                    if( map[(j*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // 2
                    if( map[((j-1)*width + (i))*2] == -1 )
                    {
                        count++;
                    }
                    // 3
                    if( map[((j-1)*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(j == 0) // if 第一排
                {
                    // 9
                    if( map[((j+1)*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // 8
                    if( map[((j+1)*width + i)*2] == -1 ) 
                    {
                        count++;
                    }
                    // 6
                    if( map[(j*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // 4
                    if( map[((j)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 7
                    if( map[((j+1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(j == 9) // if 最後一排
                {
                    // 6
                    if( map[(j*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // 2
                    if( map[((j-1)*width + (i))*2] == -1 )
                    {
                        count++;
                    }
                    // 3
                    if( map[((j-1)*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // 4
                    if( map[((j)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 1
                    if( map[((j-1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else if(i == 9) // if 最後一列
                {
                    // 1
                    if( map[((j-1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 4
                    if( map[((j)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 7
                    if( map[((j+1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 2
                    if( map[((j-1)*width + (i))*2] == -1 )
                    {
                        count++;
                    }
                    // 8
                    if( map[((j+1)*width + i)*2] == -1 ) 
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
                else
                {
                    // 9
                    if( map[((j+1)*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // 8
                    if( map[((j+1)*width + i)*2] == -1 ) 
                    {
                        count++;
                    }
                    // 6
                    if( map[(j*width + (i+1))*2] == -1 ) 
                    {
                        count++;
                    }
                    // 2
                    if( map[((j-1)*width + (i))*2] == -1 )
                    {
                        count++;
                    }
                    // 3
                    if( map[((j-1)*width + (i+1))*2] == -1 )
                    {
                        count++;
                    }
                    // 4
                    if( map[((j)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 7
                    if( map[((j+1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // 1
                    if( map[((j-1)*width + (i-1))*2] == -1 )
                    {
                        count++;
                    }
                    // count
                    map[(j*width +i)*2] = count;
                    count = 0;
                }
            }
        }
    }

    return 0;
}
int set_mine(int* map, int width, int height, int mine)
{
    int temp = 0;
    srand(time(NULL));

    for(int i = 0; i < mine; i)
    {
        temp = rand() % (width*height);
        // printf("%d ", temp);
        if( map[temp*2] != -1 )
        {
            map[temp*2] = -1;
            i++;
        /*
            if(i % 5 == 0)
            {
                printf("\n");
            }
        */
        }
        
    }

    return 0;
}
int enter_width (int max, int min)
{
    int value;
    do
    {
        printf("Please enter the width       (10-16) :");
        scanf("%d", &value);
    }
    while(check_input(value, max, min) != 0);

    return value;
}
int enter_height(int max, int min)
{
    int value;
    do
    {
        printf("Please enter the height      (10-16) :");
        scanf("%d", &value);
    }
    while(check_input(value, max, min) != 0);
    
    return value;
}
int enter_mine  (int max, int min)
{
    int value;
    do
    {
        printf("Please enter the mine number (30-90) :");
        scanf("%d", &value);
    }
    while(check_input(value, max, min) != 0);
    
    return value;
}
int check_input (int value, int max, int min)
{
    if(value < min || value > max)
    {
        printf(RED"ERROR\n"RST);
        return 1;
    }
    else
    {
        return 0;
    }
}
void print_ans(int* map, int width, int height)
{
    printf("   ");
    for(int i = 0; i < width; i++)
    {
        printf("%02d ", i);
    }
    printf("\n---");

    for(int i = 0; i < width; i++)
    {
        printf("---");
    }
    printf("\n");

    for(int i = 0; i < height; i++)
    {
        printf("%02d|", i);
        for(int j = 0; j < width; j++)
        {
            if( map[(i*width+j)*2] == -1)
            {
                printf(RED"%2d "RST, map[(i*width+j)*2] );
            }
            else
            {
                printf("%2d ", map[(i*width+j)*2] );
            }
        }
        printf("\n");
    }
}
void print_map(int* map, int width, int height)
{
    printf("   ");
    for(int i = 0; i < width; i++)
    {
        printf("%02d ", i);
    }
    printf("\n---");

    for(int i = 0; i < width; i++)
    {
        printf("---");
    }
    printf("\n");

    for(int i = 0; i < height; i++)
    {
        printf("%02d|", i);
        for(int j = 0; j < width; j++)
        {
            if( map[(i*width+j)*2 +1] == 0 ) // closed
            {
                printf(" * ");
            }
            else if( map[(i*width+j)*2 +1] == -1 ) // flaged
            {
                printf(RED" F "RST);
            }
            else if( map[(i*width+j)*2 +1] == 1 ) // opened
            {
                if( map[(i*width+j)*2] == 0 )
                {
                    printf("   ");
                }
                else if( map[(i*width+j)*2] == 1 )
                {
                    printf(BL"%2d "RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 2 )
                {
                    printf(GRN"%2d "RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 3 )
                {
                    printf(LRED"%2d "RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 4 )
                {
                    printf(MGT"%2d "RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 5 )
                {
                    printf(YLW"%2d "RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 6 )
                {
                    printf(CYN"%2d "RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 7 )
                {
                    printf(LMGT"%2d "RST, map[(i*width+j)*2] );
                }
                else if( map[(i*width+j)*2] == 8 )
                {
                    printf(GRY"%2d "RST, map[(i*width+j)*2] );
                }
                else
                {
                    printf("%2d ", map[(i*width+j)*2] );
                }
            }
        }
        printf("\n");
    }
}
