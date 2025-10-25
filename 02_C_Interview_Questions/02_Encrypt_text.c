//return type void 
//a ,b,c,z -> b,c,d,a
//blowfish -> cmpxgjta
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define ALPHABET_LENGTH 26 
char* encrypt_char(char *x)
{
    char *res =(char *)malloc(strlen(x)); 
    
    for(int i=0;i<strlen(x);i++)
    {
        
        res[i] ='a'+((x[i]-'a'+1)%ALPHABET_LENGTH); 
    }
    res[strlen(res)+1] = '\0';
    return res;
}

int main(void)
{
    char *x = "blowfisz"; 
    printf("Encrypted text : %s",encrypt_char(x));
    return 0;
}