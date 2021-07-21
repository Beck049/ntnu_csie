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

int main()
{
    char str[128] = {0}; int strptr = 0;
    char strc[128] = {0};
    char key[16]  = {0}; int keylen;
    char new[16]  = {0};
    printf("Please enter the original text:\n");
    gets(str);
    printf("Key word:\n");
    gets(key);
    keylen = strlen(key);
    printf("New word:\n");
    gets(new);

    strcpy(strc, str);

    char *ptr;
    ptr = strtok(str, " ,.");
    int len;
    while(ptr != NULL)
    {
        len = strlen(ptr);
        if(strcmp(ptr, key) == 0)
        {
            printf(RED"%s"RST, new);
        }
        else
        {
            printf("%s", ptr);
        }
        strptr += len;
        printf("%c", strc[strptr]);
        strptr++;
        while(strc[strptr] == 32)
        {
            printf("%c", strc[strptr]);
            strptr++;
        }
        ptr = strtok(NULL, ", .");
    }
    return 0;
}