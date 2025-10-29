#include<stdio.h>
#include<string.h>
#include<stdbool.h>


char firstNonRepeatingCharacter(char *str)
{
    int count[256] = {0}; 
    int len = strlen(str); 
    
    //Traverse through string and update HashTable 
    for(int i=0;i<len;i++)
    {
        count[str[i]]++; 
    }
    
    //Second pass 
    for(int i=0;i<len;i++)
    {
        unsigned char ch = str[i]; 
        if(count[ch]==1)
            return ch;
    }
    return '\0';
}

int main(void)
{
    char str[] = "swiss"; 
    printf("Original String: %s\n",str); 
   
    printf("First non-repeating character : %c\n",firstNonRepeatingCharacter(str)); 
    
    return 0;
}