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

int check_input(int, int, int);

int main()
{
    char arr[20][80] = {0};
    int check = 0;
    int my_move = 0;
    int enemy_move[3] = {0}, enemy_vision[3] = {0}, enemy_location[3] = {0};

    while(check_input(3, 6, my_move) != 1)
    {
        printf("Your movement (3-6): "); scanf("%d", &my_move);
        if(check_input(3, 6, my_move) == 0)
        {
            printf("Invalid input!!\n");
        }
    }
    while(check_input(3, 6, enemy_move[1]) != 1)
    {
        printf("Enemy 1 movement (3-6): "); scanf("%d", &enemy_move[1]);
        if(check_input(3, 6, enemy_move[1]) == 0)
        {
            printf("Invalid input!!\n");
        }
    }
    while(check_input(2, 10, enemy_vision[1]) != 1)
    {
        printf("Enemy 1 vision (2-10): "); scanf("%d", &enemy_vision[1]);
        if(check_input(2, 10, enemy_vision[1]) == 0)
        {
            printf("Invalid input!!\n");
        }
    }
    while(check_input(2, 80, enemy_location[1]) != 1)
    {
        printf("Enemy 1 location (2-80): "); scanf("%d", &enemy_location[1]);
        if(check_input(2, 80, enemy_location[1]) == 0)
        {
            printf("Invalid input!!\n");
        }
    }
    while(check_input(3, 6, enemy_move[2]) != 1)
    {
        printf("Enemy 2 movement (3-6): "); scanf("%d", &enemy_move[2]);
        if(check_input(3, 6, enemy_move[2]) == 0)
        {
            printf("Invalid input!!\n");
        }
    }
    while(check_input(2, 10, enemy_vision[2]) != 1)
    {
        printf("Enemy 2 vision (2-10): "); scanf("%d", &enemy_vision[2]);
        if(check_input(2, 10, enemy_vision[2]) == 0)
        {
            printf("Invalid input!!\n");
        }
    }
    while(check_input(2, 80, enemy_location[2]) != 1)
    {
        printf("Enemy 2 location (2-80): "); scanf("%d", &enemy_location[2]);
        if(check_input(2, 80, enemy_location[2]) == 0)
        {
            printf("Invalid input!!\n");
        }
    }

    return 0;    
}

int check_input(int l, int h, int input)
{
    if( input > h || input < l )
    {
        return 0;
    }
    else
    {
        return 1;
    }
}