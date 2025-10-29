#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void swap(char *a ,char *b)
{
    if(a != b)
    {
        *a = *a^*b; 
        *b = *a^*b;
        *a = *a^*b;
    }
}

void sort(char *s)
{
    int len = strlen(s); 
    int i=0,j = len -1; 
    
    for(int i=0;i<len;i++)
    {
        for(int j = i+1;j<len;j++)
        {
            if(s[i]>s[j])
                swap(&s[i],&s[j]);
        }
    }
    
}

int main(void)
{
    char str1[10] = "Abhijith"; 
    
    printf("Before Sorting: %s\n",str1);
    sort(str1);
    printf("After Sorting %s\n",str1);
   
    return 0;
}