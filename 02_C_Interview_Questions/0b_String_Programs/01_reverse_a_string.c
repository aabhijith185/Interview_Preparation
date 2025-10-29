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

void reverse_string(char *str)
{
    int i = 0; 
    int j = strlen(str)-1; 
    while(i<j)
    {
        swap(&str[i],&str[j]);
        i++; 
        j--;
    }
}
int main(void)
{
    char s[]= "abhijith";

    printf("Original string : %s\n",s);
    reverse_string(s);
    printf("Reversed string : %s\n",s);


	return 0;
}