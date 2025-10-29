#include<stdio.h>
#include<string.h>
void swap(char *x,char *y)
{
    if(x != y)
    {
        *x = *x ^ *y; 
        *y = *x ^ *y; 
        *x = *x ^ *y;
    }
}

void reverse_in_range(char *str,int start,int end)
{

    while(start<end)
    {
        swap(&str[start],&str[end]);
        start++; 
        end--;
    }
}

void reverse_words(char *str)
{
    int len = strlen(str);

    //reverse entire string 
    reverse_in_range(str,0,len-1);

    int start = 0; 
    for(int i=0;i<len;i++)
    {
        if(str[i]==' '||str[i]=='\0')
        {
            reverse_in_range(str,start,i-1);
            start= i+1;
        }
    }
}
int main() {
    char s[] = "I love C++ deeply";
    reverse_words(s);
    printf("Reversed string : %s\n",s);// Output: "deeply C++ love I"
    return 0;
}