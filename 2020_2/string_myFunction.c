#include<stdio.h>
#include<assert.h>
#include<string.h>
size_t my_strlen(const char *s) {
    size_t i;
    for (i = 0; s[i] != '\0'; i++) ;
    return i;
}
//////////////////////////////////////////////////////////////////////
char *my_strcat(char *dest, const char *src)
{
    char *ret = dest;
    while (*dest)
        dest++;
    while (*dest++ = *src++)
        ;
    return ret;
}
////////////////////////////////////////////////////////////////////
int my_strcmp(const char* s1, const char* s2)
{
    while(*s1 && (*s1==*s2))
        s1++,s2++;
    return *(const unsigned char*)s1-*(const unsigned char*)s2;
}
////////////////////////////////////////////////////////////////////
char *my_strchr(const char *s, int c)
{
    while (*s != (char)c)
        if (!*s++)
            return 0;
    return (char *)s;
}
////////////////////////////////////////////////////////////////////
///////////
char *my_strrchr(const char *s, int c)//!!!!!//
{
    char* ret=0;
    do {
        if( *s == (char)c )
            *ret = *s;
    } while(*s++);
    return ret;
}
/////////////////////////////////////////////////////////////////////
size_t strspn(const char *s1, const char *s2)
{
    size_t ret=0;
    while(*s1 && strchr(s2,*s1++))
        ret++;
    return ret;    
}
/////////////////////////////////////////////////////////////////////
size_t strcspn(const char *s1, const char *s2)
{
    size_t ret=0;
    while(*s1)
        if(strchr(s2,*s1))
            return ret;
        else
            s1++,ret++;
    return ret;
}
/////////////////////////////////////////////////////////////////////
char *my_strpbrk(const char *s1, const char *s2)
{
    while(*s1)
        if(my_strchr(s2, *s1++))
            return (char*)--s1;
    return 0;
}
////////////////////////////////////////////////////////////////////
char * my_strstr ( const char * str1, const char * str2)
{
    char *cp = (char *) str1;
    char *s1, *s2;
 
    if ( !*str2 ) 
    {
        return((char *)str1);
    }
    while (*cp)    
    {
        s1 = cp;
        s2 = (char *) str2;
        while ( *s1 && *s2 && (*s1==*s2) )
        {
            ++s1, ++s2;
        }
        if (!*s2) 
        {
            return(cp);
        }
        cp++;
    }
    return(NULL);
}
/////////////////////////////////////////////////////////////////////
char *my_strtok(char * str, const char * delim)
{
    static char* p=0;
    if(str)
        p=str;
    else if(!p)
        return 0;
    str=p+strspn(p,delim);
    p=str+strcspn(str,delim);
    if(p==str)
        return p=0;
    p = *p ? *p=0,p+1 : 0;
    return str;
}

int  main()
{
   
    //my_strchr//
    // char str[] = "This is a sample string";
    // char *pch;
    // printf("Search all  's' in \"%s\"\n",str);
    // pch = my_strchr(str,'s');
    // while(pch != NULL)
    // {
    //     printf("found at %d\n",pch-str+1);
    //     pch = strchr(pch+1,'s');
    // }
    // return 0;
    //my_strrchr//
    // char str[] = "This is a sample string";
    // char *pch;
    // printf("Search all  's' in \"%s\"\n",str);
    // pch = my_strrchr(str,'s');
    // printf("Last occurrence at %d\n",pch-str+1);
    // return 0;
    //strspn//
    //strcspn//
    //my_strpbrk//
    // char str[] = "This, is/a sample string.";
    // char *pch;
    // char key[] = "aeiou";
    // printf("the vowels : ");
    // pch = my_strpbrk(str, key);
    // while(pch != NULL)
    // {
    //     printf("%c",*pch);
    //     pch = my_strpbrk(pch+1, key);
    // }
    // return 0;
    //my_strstr//  sample string   //
    // char str[] = "This is a sample string";
    // char *p;
    // char sub[] = "sample";
    // p = my_strstr(str,sub);
    // printf("%s",p);
    // return 0;
    //strtok//
    // char str[] = "This, is/a sample string.";
    // char *pch;
    // pch = my_strtok(str,", /.");
    // while(pch != NULL)
    // {
    //     printf("%s\n",pch);
    //     pch = my_strtok(NULL,", /.");
    // }
    // return 0;
}
