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

#define NEW_PAGE printf("%s", clear)
char* clear = "\e[H\e[2J\e[3J";

int hero_hp = 0, hero_atk = 0, hero_move = 0, hero_magic = 1; 
int dragon_hp = 0, dragon_atk = 0, dragon_move = 0;

void flush_buffer();
void title();
void menu();

void setup();
void print_init();
void init();
int check_flag(int, int);
void status(int, int);

void print_map(char *);
int attack_hero(int* , int*, int);
int magic(int* , int*, int );
int move(int*, char*);

int dragon_phase(int, int, int* , int* , char* );
//treasure();


int main()
{
    setvbuf(stdin, NULL, _IONBF, 0);

    NEW_PAGE;
    title();

    NEW_PAGE;
    menu();

    NEW_PAGE;
    init();

    int key  = 0;
    int flag = 0;

    int cur_d_hp;
    int cur_h_hp;

    cur_h_hp = hero_hp;
    cur_d_hp = dragon_hp;
//  printf("%d  %d",cur_h_hp, cur_d_hp);
    
    // current position =  { x, y }
    // x = arr%80  ;  y = arr/80  ; 
    int cur_h_position[2] = { 0, 0};
    int cur_d_position[2] = {79,19};
    char map[1600];
    for(int i = 0; i < 1600; i++)
    {
        map[i] = 20;
    }
    map[0] = 'H';
    map[1599] = 'D';

    while(1)
    {
        printf("1) Move\n2) Attack\n3) Magic\n4) Status\n5) Exit\n");
        printf("Your Choice (1-5): ");
        scanf("%d", &key);
        switch(key)
        {
            case 1:
                move(cur_h_position, map);
                flag = check_flag(cur_h_hp, cur_d_hp);
                if(flag == 1)
                {   break;  }
                dragon_phase( cur_d_hp, cur_h_hp, cur_h_position, cur_d_position, map);
                flag = check_flag(cur_h_hp, cur_d_hp);
                break;
    printf("%d\n",  flag);
            case 2:
                attack_hero(cur_h_position, cur_d_position, cur_d_hp);
                flag = check_flag(cur_h_hp, cur_d_hp);
                if(flag == 1)
                {   break;  }
                dragon_phase( cur_d_hp, cur_h_hp, cur_h_position, cur_d_position, map);
                flag = check_flag(cur_h_hp, cur_d_hp);
                break;
            case 3:
                if(hero_magic != 1)
                {
                    printf("You have no mana\n");
                    break;
                }
                magic(cur_h_position, cur_d_position, cur_d_hp);
                flag = check_flag(cur_h_hp, cur_d_hp);
                if(flag == 1)
                {   break;  }
                dragon_phase( cur_d_hp, cur_h_hp, cur_h_position, cur_d_position, map);
                flag = check_flag(cur_h_hp, cur_d_hp);
                break;
            case 4:
                status(cur_h_hp, cur_d_hp);
                break;
            case 5:
                flag = 1;
                break;
            default:
                printf("ERROR");
                break;
        }

    //  printf("%d\n",  flag);

        if(flag == 1)
        {
            break;
        }
        else
        {
            print_map(map);
        }
    }

}
////////////////////////////////////////////////////////////////////////////////////
int dragon_phase(int cur_d_hp, int cur_h_hp, int* cur_h_position, int* cur_d_position, char* map)
{
    if(cur_d_hp <= dragon_hp/2)
    {   dragon_move *= 2;    }
    if(cur_d_hp <= dragon_hp/4)
    {   dragon_atk  *= 2;    }

    srand(time(0));

    // current position =  { x, y }
    // x = arr%80  ;  y = arr/80  ;
    // map[ y*80 + x ] 
    int x = cur_d_position[0];
    int y = cur_d_position[1];
    int left = dragon_move;

    if(cur_d_hp == dragon_hp) // full health -> randomly move
    {
        int temp, step;

        while(left != 0)
        {
            temp = rand()%5 ;
            step = rand()%dragon_move;
            
            switch(temp)
            {
                case 1: // up
                    if(step > left)
                    {break;}
                    if(y < 6 && step > y)
                    {break;}

                    y -= step;
                    printf("Dragon goes up for %d step(s)\n",step);
                    left -= step;
                    break;
                    
                case 2: // down
                    if(step > left)
                    {break;}
                    if(y > 13 && step > 19-y)
                    {break;}

                    y += step;
                    printf("Dragon goes down for %d step(s)\n",step);
                    left -= step;
                    break;

                case 3: // left
                    if(step > left)
                    {break;}
                    if(x < 6 && step > x)
                    {break;}

                    x -= step;
                    printf("Dragon goes left for %d step(s)\n",step);
                    left -= step;
                    break;

                case 4: // right
                    if(step > left)
                    {break;}
                    if(x > 73 && step > 79-x)
                    {break;}

                    x += step;
                    printf("Dragon goes right for %d step(s)\n",step);
                    left -= step;
                    break;

                case 0:
                    left = 0;
                    break;

                default:
                    printf("ERROR\n");
                    break;
            }
        }
        
        map[ cur_d_position[1]*80 + cur_d_position[0] ] = ' ';
        map[ y*80 + x ] = 'D';

        cur_d_position[0] = x;
        cur_d_position[1] = y;

        char c = 0;

        printf("Press Enter to continue...");
        flush_buffer();
        c = getchar();

        NEW_PAGE;

        return 0;

    }
    else // start chasing and attack
    {
        // check if it can attack
        if( abs(cur_d_position[0]-cur_h_position[0]) + abs(cur_d_position[1]-cur_h_position[1]) < dragon_move )
        {
            // attack
            printf("Dragon attacked !\nPlayer get %d hurt\n",dragon_atk);
            cur_h_hp -= dragon_atk;

            char c = 0;

            printf("Press Enter to continue...");
            flush_buffer();
            c = getchar();

            NEW_PAGE;

            return 0;
        }
        // chase player
        else
        {
            int temp, step;

            while(left != 0)
            {
                temp = rand()%3 ;

                switch(temp)
                {
                    case 1: // up & down
                        if( cur_d_position[1] - cur_h_position[1] > 0 )
                        {   // goes up
                            if( abs(cur_d_position[1] - cur_h_position[1]) < dragon_move )
                            {
                                step =rand()%(abs(cur_d_position[1] - cur_h_position[1])) ;
                                
                                if(step > left)
                                {break;}

                                y -= step;
                                printf("Dragon goes up for %d step(s)\n",step);
                                left -= step;
                                break;   
                            }
                            else // goes down
                            {
                                step =rand()%dragon_move;
                                
                                if(step > left)
                                {break;}

                                y -= step;
                                printf("Dragon goes up for %d step(s)\n",step);
                                left -= step;
                                break;
                            }
                        }

                    case 2: // left & right
                        if( cur_d_position[0] - cur_h_position[0] > 0 )
                        {   // goes left
                            if( abs(cur_d_position[0] - cur_h_position[0]) < dragon_move )
                            {
                                step =rand()%(abs(cur_d_position[0] - cur_h_position[0])) ;
                                
                                if(step > left)
                                {break;}

                                x -= step;
                                printf("Dragon goes left for %d step(s)\n",step);
                                left -= step;
                                break;   
                            }
                            else // goes right
                            {
                                step =rand()%dragon_move;
                                
                                if(step > left)
                                {break;}

                                x += step;
                                printf("Dragon goes right for %d step(s)\n",step);
                                left -= step;
                                break;
                            }
                        }
                    case 0:
                        left = 0;
                        break;
                    default:
                        printf("ERROR\n");
                        break;
                }
            }
            
            map[ cur_d_position[1]*80 + cur_d_position[0] ] = ' ';
            map[ y*80 + x ] = 'D';

            cur_d_position[0] = x;
            cur_d_position[1] = y;

            char c = 0;

            printf("Press Enter to continue...");
            flush_buffer();
            c = getchar();

            NEW_PAGE;

            return 0;
        }
    }

    return 0;
}

int move(int* position, char* map)
{
    // current position =  { x, y }
    // x = arr%80  ;  y = arr/80  ;
    // map[ y*80 + x ] 
    int x = position[0];
    int y = position[1];

    int left = hero_move;
    int num, step;
    while(left != 0)
    {
        printf("1)UP\n2)DOWN\n3)LEFT\n4)RIGHT\n0)to Skip \nYour choice (%d step left):",left);
        scanf("%d",&num);

        switch(num)
        {
            case 1: // up
                printf("How many steps: ");
                scanf("%d", &step);

                if(step > left)
                {printf("You can't move that much\n");break;}
                if(y < 6 && step > y)
                {printf("You can't go that far\n");break;}

                y -= step;
                left -= step;
                break;
                
            case 2: // down
                printf("How many steps: ");
                scanf("%d", &step);

                if(step > left)
                {printf("You can't move that much\n");break;}
                if(y > 13 && step > 19-y)
                {printf("You can't go that far\n");break;}

                y += step;
                left -= step;
                break;

            case 3: // left
                printf("How many steps: ");
                scanf("%d", &step);

                if(step > left)
                {printf("You can't move that much\n");break;}
                if(x < 6 && step > x)
                {printf("You can't go that far\n");break;}

                x -= step;
                left -= step;
                break;

            case 4: // right
                printf("How many steps: ");
                scanf("%d", &step);

                if(step > left)
                {printf("You can't move that much\n");break;}
                if(x > 73 && step > 79-x)
                {printf("You can't go that far\n");break;}

                x += step;
                left -= step;
                break;

            case 0:
                left = 0;
                break;

            default:
                printf("ERROR\n");
                break;
        }
    }

    map[ position[1]*80 + position[0] ] = ' ';
    map[ y*80 + x ] = 'H';

    position[0] = x;
    position[1] = y;

    return 0;
}

int magic(int*h , int*d, int d_hp)
{
    if( (abs(h[0] - d[0]) + abs(h[1] - d[1])) <= 7)
    {
        printf("Atk success!\nDragon HP -50");
        d_hp -= 50;
    }
    else
    {
        printf("Attack Failed\nYou can't reach the dragon...\n");
    }
    return 0;
}

int attack_hero(int*h , int*d, int d_hp)
{
    if( (abs(h[0] - d[0]) + abs(h[1] - d[1])) <= hero_move)
    {
        printf("Atk success!\nDragon HP -%d", hero_atk);
        d_hp -= hero_atk;
    }
    else
    {
        printf("Attack Failed\nYou can't reach the dragon...\n");
    }
    return 0;
}

void setup()
{
    srand(time(NULL));

    hero_hp = rand()%206 + 50;
    hero_atk = rand()%50 + 1;
    hero_move = rand()%4 + 3;

    dragon_hp = rand()%925 + 100;
    dragon_atk = rand()%70 + 1;
    dragon_move = rand()%4 + 2;
}

void init()
{
    setup();
    print_init();
}


int check_flag(int hero, int dra)
{
    if( dra <= 0 )
    {
        printf("Dragon is dead...\n");
        return 1;
    }
    else if(hero <= 0)
    {
        printf("You are defeated...\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

void print_init()
{
    printf("Hero's HP  (50-255): %d\n", hero_hp);
    printf("Hero's ATK ( 1-50 ): %d\n", hero_atk);
    printf("Hero's MOVE( 3-6  ): %d\n", hero_move);

    printf("Dragon's HP  (100-1024): %d\n", dragon_hp);
    printf("Dragon's ATK ( 1 - 70 ): %d\n", dragon_atk);
    printf("Dragon's MOVE( 2 - 5  ): %d\n", dragon_move);
}

void status(int hero, int dra)
{
    printf("Hero Status\n");
    printf("HP : %d,\tMax HP : %d\n", hero, hero_hp);
    printf("Move   : %d\n", hero_move);
    printf("Attack : %d\n", hero_move);
    printf("Magic  : %d\n", hero_magic);
    printf("============================\n");
    printf("Dragon Status\n");
    printf("HP : %d,\tMax HP : %d\n", dra, dragon_hp);
    printf("Move   : %d\n", dragon_move);
    printf("Attack : %d\n", dragon_atk);
}

void print_map(char * map)
{
    printf("+--------------------------------------------------------------------------------+\n");
    for(int i = 0; i < 20; i++)
    {
        printf("|");
        for(int j = 0; j < 80; j++)
        {
            if(map[i*80 + j] == 'H' || map[i*80 + j] == 'D')
            {
                printf("%c", map[i*80 + j]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("+--------------------------------------------------------------------------------+\n");
}

void flush_buffer()
{
    char c = 0;
    while((c = getchar()) != '\n' && c != EOF);
}

void title()
{

    char c = 0;

    printf("Dragon and Dungeon\n");

    printf("Press Enter to continue...");
    c = getchar();

}

void menu()
{
    char c = 0;

    printf("Once upon a time...\n");

    printf("Press Enter to continue...");
    flush_buffer();
    c = getchar();

}