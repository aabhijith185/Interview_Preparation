#include<stdio.h> 
#include<string.h>

void* my_memcpy(void* dest,const void* src,int n)
{
    unsigned char* d = (unsigned char*)(dest);//Typecast for byte level access of dest 
    unsigned char* s = (unsigned char*)(src); 

    //copy n number fo bytes 
    for(int i=0;i<n;i++)
        d[i] = s[i]; 
    return dest;
}

int main(void)
{
    char src[] = "Abhijith will clear motorola interview"; 
    char dest[50]; 

    my_memcpy(dest,src,strlen(src)+1); //include '\0'
    
    printf("Source : %s\n",src);
    printf("Destination  : %s\n",dest);

    return 0;
}
