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

#define BGRED ASCII_ESC"[41m" // bg red
#define BGGRN ASCII_ESC"[42m" // bg grn
#define BGYLW ASCII_ESC"[43m" // bg ylw
#define BGBL ASCII_ESC"[44m"  // bg bl
#define BGMGT ASCII_ESC"[45m" // bg mgt
#define BGCYN ASCII_ESC"[46m" // bg cyn
#define BGWHT ASCII_ESC"[47m" // bg wht

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
    printf(RED"red\n"RST);
    printf(GRN"grn\n"RST);
    printf(YLW"ylw\n"RST);
    printf(BL"bl\n"RST);
    printf(MGT"mgt\n"RST);
    printf(CYN"cyn\n"RST);
    printf(WHT"wht\n"RST);
    printf(GRY"gry\n"RST);
    printf(LRED"lred\n"RST);
    printf(LGRN"lgrn\n"RST);
    printf(LYLW"lylw\n"RST);
    printf(LBL"lbl\n"RST);
    printf(LMGT"lmgt\n"RST);
    printf(LCYN"lcyn\n"RST);
    printf(LWHT"lwht\n"RST);

    printf("return\n");

    printf(BOLD"bold\n"RST);
    printf(FLASH"flash\n"RST);

    printf("return");
}