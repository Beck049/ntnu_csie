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

// char json[] = "{ \"firstName\": \"John\", \"lastName\": \"Smith\",\"sex\": \"male\", \"age\": 25 }";
// char json[] = "{ \"firstName\": \"John\", \"lastName\": \"Smith\",\"sex\": \"male\", \"age\": 125, \"address\": { \"streetAddress\": \"21 2nd Street\", \"city\": \"New York\", \"state\": \"NY\", \"postalCode\": \"10021\" } }";
char json[] = "{ \"firstName\": \"John\", \"lastName\": \"Smith\",\"sex\": \"male\", \"age\": 125, \"address\": { \"postalCode\": \"10021\", \"city\": \"New York\", \"state\": \"NY\", \"streetAddress\": \"21 2nd Street\" }, \"phoneNumber\": [ { \"type\": \"home\", \"number\": \"212 555-1234\"}, { \"type\": \"fax\", \"number\": \"646 555-4567\" } ] }";

// overall function 
void  get_value(char*, char*);

// show what to do
void  get_seq  (char*, int* );

// to get the first key
char* get_key  (char*, char*);

// find key in json
char* find_data(char*, char*);

// next key if dot
char* key_dot(char*, char*, char*);

// find the : of the key
char* dot_position(char*, char*, char*);

// get key2 (number in [])
char* key_array(char*, char*, char*);

// return key2 in integer
int find_number(char*);

// get the [ or ,
char* array_position(char*, char*, char*, int);

// print the value
char* print_value(char*, char*);

// turn value into readable format
void  open_value(char*);

int main()
{
    // char json[1024] = {0};
    // printf("Please enter the JSON string: \n");
    // gets(json);
    
    char key[32] = {0};

    int choice = 1;
    while( choice != 0 )
    {
        printf("Choice (0:Exit, 1:Get) : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Key: ");
                scanf("%30s", key);
                get_value(json, key);
                break;
            case 0:
                printf("bye\n");
                break;
            default:
                printf("Error choice\n");
        }
    }
}
////////////////////////////////////////////////////////////////////
void get_value(char* json, char* key)
{
    int error = 1;
    int sequence[8] = {0};
    int count = 0;
    get_seq(key, sequence); // to see what to do
                            // move till find sequence = 0
/*
for(int i = 0; i < 8; i++)
{   printf("%d", sequence[i]);  }
printf(" -> sequence\n");
*/
    char key1[15] = {0}; // key1 is the seperated from input
    char* key_pch;
    if(sequence[count] == 0)
    {
        strcpy(key1, key);
    }
    else
    {
        key_pch = get_key(key ,key1); // get the first key
    }
/*
printf("key1 is %s [%d]\n", key1, strlen(key1));
*/
    char key2[15] = {0}; // save the key in json
    char* data_pch;
    // find key in json
    data_pch = find_data(json, key2);
/*
printf("find  : %s\n", key2);
*/
    while(1)
    {
        if(strncmp(key1, key2, strlen(key1)) == 0)
        { // fine the key
            data_pch = strpbrk(data_pch, ":");
            error = 0;
            break;
        }
        else if(strpbrk(data_pch, ",") == NULL)
        { // find till the end
            error = 1;
            break;
        }
        else
        { // did not find the key
            data_pch = strpbrk(data_pch, ",");
            data_pch = find_data(data_pch, key2);
/*
printf("find : %s\n", key2);
*/
        }
    }
    if(error == 1)
    {
        printf("Cant find the key...\n");
        error = 0;
        return;
    }
    // get the : next to the key
/*
printf("%s\n", key2);
*/
while(sequence[count] != 0)
{
    // current pch = the address of . [
    // current data_pch = the address of :
    if(sequence[count] == 1) // .
    {
// printf(".\n");
        key_pch  = key_dot(key, key1, key_pch);
// printf("%s\n", key1);
        data_pch = dot_position(key1, key2, data_pch);
// printf("%s\n", key2);
        count++;
    }
    else if(sequence[count] == 2) // [
    {
        key_pch = key_array(key, key1, key_pch);
// printf("%s\n", key1);
        int num = find_number(key1);
// printf("%d\n", num);
        data_pch = array_position(key1, key2, data_pch, num);
// printf("%c\n", data_pch[0]);
        count++;
     }
}
    
    char value[32] = {0};
    // after asign data_pch = the address of :
    print_value(data_pch, value);
}

char* key_dot(char* key, char* key1, char* key_pch)
{ // current pch = the address of . [
    char* pch;
    pch = strpbrk(key_pch+1, ".[");
    
    int len = 0;
    if(pch == NULL)
    {
        len = strlen(key_pch+1);
    }
    else /*not tested*/
    {
        len = pch - key_pch -1;
    }

    strncpy( key1, key_pch+1, len);
    key1[len] = '\0';
    
    return key_pch + len +1;
}
char* dot_position(char* key1, char* key2, char* data_pch)
{ // current data_pch = the address of :
    data_pch = strpbrk(data_pch, "{");
    char* p_head; char* p_tail;

    while(1)
    {
        int len = 0;
        p_head = strpbrk(data_pch, "\"");
        p_tail = strpbrk( p_head+1 , "\"");
        len = p_tail - p_head -1;
        strncpy(key2, p_head+1, len);
        key2[len] = '\0';

        if( strncmp(key1, key2, strlen(key1)) == 0)
        {
            break;
        }
        else
        {
            data_pch = strpbrk(p_tail, ",}");
            if( data_pch[0] == 125)
            {
                printf("Can't find the key in dot...\n");
                break;
            }
        }
    }
    data_pch = strpbrk(p_tail, ":");

    return data_pch;
}
char* key_array(char* key, char* key1, char* key_pch)
{ // current pch = the address of . [
    char* pch;
    pch = strpbrk(key_pch+1, ".[");

    int len = 0;
    if(pch == NULL)
    {
        len = strlen(key_pch+1) -1;
    }
    else /*not tested*/
    {
        len = pch - key_pch -2;
    }

    strncpy( key1, key_pch+1, len);
    key1[len] = '\0';
    
    return key_pch + len +2;
}
int find_number(char* key1)
{
    int len = strlen(key1);
    int num = 0;

    for(int i = 0; i < len; i++)
    {
        num *= 10;
        num += key1[i] - 48;
    }

    return num;
}
char* array_position(char* key1, char* key2, char* data_pch, int num)
{ // current data_pch = the address of :
    data_pch = strpbrk(data_pch, "[");
    char* ptr;
    int brack = 0;

    for(int i = 0; i < num; i++)
    {
        int count = 0;
        while(1)
        {
            if(data_pch[count] == 123)
            {   brack++;    }
            else if(data_pch[count] == 125)
            {   brack--;    }
            else if(data_pch[count] == 44 && brack == 0)
            {
                data_pch += count;
                break;
            }
            count++;
        }
    }

    return data_pch;
}
char* print_value(char* data_pch, char* value)
{
    char *head, *tail;
    int len;
    
    head = data_pch +1; // the next char of : 
    if(strpbrk(head, ",") == NULL) // if last key
    {
        tail = strpbrk(head, "}");
    }
    else
    {
        tail = strpbrk(head, ",");
    }
    len = tail - head;

    strncpy(value, head, len);
    value[len] = '\0';

    open_value(value);

    return data_pch;
}

void open_value(char* value)
{
    int isString = 0;
    int count = 0;
    while(value[count] == 32 || value[count] == 34)
    { // SP "
        if(value[count] == 34)
        {   isString = 1;   break;  }
        count++;
    }
    if(isString == 0)
    {
    //    count--;    
    }
    int len = strlen(value);
    for(int i = 0; i < len - count -1; i++)
    {
        value[i] = value[i+count+1];
    }
    value[len-count] = '\0';
    len = len - count -1;

    while(value[len] == 125 || value[len] == 34 || value[len] == 32 || value[len] == 93)
    { //  }  "  SP  ]
        value[len] = '\0';
        len--;
        if(value[len] == 34)
        {   break;  }
    }
    len++;
// printf("%c %c\n", value[len-1], value[len]);

    if(isString == 0)
    {
        int num = 0;
        for(int i = 0; i < len; i++)
        {
            num *= 10;
            num += value[i] - 48;
        }
        printf("Value: %d\n", num);
    }
    else if (isString == 1)
    {
        printf("Value: ");
        for(int i = 0; i < len-1; i++)
        {
            printf("%c", value[i]);
        }
        printf("\n");
    }
/*potential struct
  {
    int isString (1,0)
    int num
    char value[]
  }    
*/
}

char* find_data(char* data_pch, char* key2)
{
    int len;
    char *p_head, *p_tail;
    p_head = strpbrk(data_pch, "\"");
    p_tail = strpbrk(p_head+1, "\"");

    len = p_tail - p_head -1;

    strncpy(key2, p_head+1, len);
    key2[len] = '\0';

    p_head = strpbrk(p_tail, ":");

    return p_head;
}

char* get_key(char* key_pch, char* key1)
{
    int len;
    char* pch;
    
    pch = strpbrk(key_pch, ".[");
    len = pch - key_pch;
    strncpy(key1, key_pch, len);
    key1[len] = '\0';

    return pch;
}

void get_seq(char* key, int* sequence)
{
    int count = 0;
    for(int i = 0; i < strlen(key); i++)
    {
        if(key[i] == 46) // .
        {
            sequence[count] = 1;
            count++;
        }
        else if(key[i] == 91) // [
        {
            sequence[count] = 2;
            count++;
        }
    }
}