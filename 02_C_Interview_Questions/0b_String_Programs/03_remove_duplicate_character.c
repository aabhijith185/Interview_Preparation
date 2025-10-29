#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define ASCII_LEN 256
void remove_duplicates(char *str)
{
    //Hash table for ascii characters 
    bool seen[ASCII_LEN]={0};
    int index = 0; 
    for(int i=0;i<strlen(str);i++)
    {
        char ch = str[i]; 
        if(!seen[ch])
        {
            //update the hash table 
            seen[ch] = true; 
            str[index++] = ch;
        }
    }
    //terminate with  a null character 
    str[index] = '\0';
}

int main()
{
    char str[] = "Programming"; 
    printf("Original : %s\n",str); 
    
    remove_duplicates(str); 
    printf("Without Duplicates : %s",str); 
    
    return 0;
}
