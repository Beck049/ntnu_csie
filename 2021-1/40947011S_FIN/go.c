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

#include "go.h"

void print_table(int32_t table[19][19])
{
    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            printf("%3d |", table[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void set_group( int32_t board[][19], int32_t visit[19][19], int32_t black[19][19], int i, int j, int32_t group )
{
    if     (i !=  0) // !頂 
    {
        if(visit[i-1][j] == 0 && board[i-1][j] == 1)
        {
            black[i-1][j] = group;
            visit[i-1][j] = 1;
            set_group(board, visit, black, i-1, j, group);
        }
    }
    if(i != 18) // !底
    {
        if(visit[i+1][j] == 0 && board[i+1][j] == 1)
        {
            black[i+1][j] = group;
            visit[i+1][j] = 1;
            set_group(board, visit, black, i+1, j, group);
        }
    }
    if(j !=  0) // !左
    {
        if(visit[i][j-1] == 0 && board[i][j-1] == 1)
        {
            black[i][j-1] = group;
            visit[i][j-1] = 1;
            set_group(board, visit, black, i, j-1, group);
        }
    }
    if(j != 18) // !右
    {
        if(visit[i][j+1] == 0 && board[i][j+1] == 1)
        {
            black[i][j+1] = group;
            visit[i][j+1] = 1;
            set_group(board, visit, black, i, j+1, group);
        }
    }

    return;
}


int32_t max_black_chain( int32_t board[][19] )
{
    int32_t max = 0;
    int32_t group = -1;
    int32_t black[19][19] = {0};
    int32_t visit[19][19] = {0};
    // black 分組
    for(int i = 0; i < 19; i++)
    {
        for(int j = 0; j < 19; j++)
        {
            if(visit[i][j] == 0)
            {
                if (board[i][j] == 1)
                {
                    black[i][j] = group;
                    visit[i][j] = 1;

                    // start DFS
                    set_group(board, visit, black, i, j, group );

                    group--;
                }
                else
                {
                    black[i][j] = board[i][j];
                    visit[i][j] = 1;
                }
            }
        }
    }
//
// print_table(black);
// print_table(visit);
//
    // 找每個 group 的 liberty
    for(int g = -1; g > group; g--)
    {
        int count = 0;
        // find space
        for(int i = 0; i < 19; i++)
        {
            for(int j = 0; j < 19; j++)
            {
                if(black[i][j] == 0)
                {
                    int flag = 0;
                    // if a black exist -> flag = 1
                    if     (i !=  0) // !頂 
                    {
                        if(black[i-1][j] == g)
                        {
                            flag = 1;
                        }
                    }
                    if(i != 18) // !底
                    {
                        if(black[i+1][j] == g)
                        {
                            flag = 1;
                        }
                    }
                    if(j !=  0) // !左
                    {
                        if(black[i][j-1] == g)
                        {
                            flag = 1;
                        }
                    }
                    if(j != 18) // !右
                    {
                        if(black[i][j+1] == g)
                        {
                            flag = 1;
                        }
                    }
                    // if exist -> count++
                    if(flag == 1)
                    {
                        count++;
                    }
                }
            }
        }
        // compare max
        if(count > max)
        {
            max = count;
        }
    }

    return max;
}