#include<stdio.h>

/* custom strcpy */

char* my_strcpy(char *dest,const char *src)
{
    char *ptr = dest; 
    //copy each character till null terminator 
    while(*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0'; //Add null terminator at the end 
    return ptr;//return pointer to the destination 
}

int main()
{
    char src[] = "Thundersoft Malaysia"; 
    char dest[50]; 

    my_strcpy(dest,src);

    printf("Source: %s\n",src); 
    printf("Copied: %s\n",dest);

    return 0;
}