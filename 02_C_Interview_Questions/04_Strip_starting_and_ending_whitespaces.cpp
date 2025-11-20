
#include<stdio.h>
#include<string.h>

void strip_of_start_end_whitespaces(char *str)
{
    int start = 0; 
    int end = strlen(str)-1; 
    
    //skip leading spaces 
    while(str[start]==' ')
    {
        start++; 
    }
    
    //skip trailing spaces
    while(end>=start && str[end]==' ')
        end--;
    int k = 0 ; 
    for(int i = start ;i<=end;i++)
    {
        str[k++] = str[i];
    }
    str[k] ='\0';
}
int main()
{
    char str[] = "  my name is john ";
    strip_of_start_end_whitespaces(str); 
    printf("->%s<-",str); 
    return 0;
}
