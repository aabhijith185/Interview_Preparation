#include<stdio.h> 

void *my_memset(void *ptr,int value,int n)
{
    unsigned char *p = (unsigned char *)(ptr); 
    unsigned char v = (unsigned char )(value); 

    for(int i=0;i<n;i++)
        p[i] = v; 
    return ptr;
}


int main()
{
    char buffer[20];

    //Fill buffer with 'A'
    my_memset(buffer,'A',sizeof(buffer));

    printf("Buffer content\n"); 
    for(int i=0;i<20;i++)
        printf("%c",buffer[i]); 
    printf("\n"); 
    
    return 0; 
}