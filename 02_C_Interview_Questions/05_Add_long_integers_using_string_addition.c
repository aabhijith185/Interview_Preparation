#include<stdio.h>
#include<string.h>
#define MAX 1000

void swap(char *x,char *y)
{
    if(x != y)
    {
        *x = *x ^ *y;
        *y = *x ^ *y;
        *x = *x ^ *y;
    }
}

//Function to reverse a string  
void reverse(char *str)
{
    int i =0; 
    int j = strlen(str) - 1;
    while(i<j)
    {
        swap(&str[i], &str[j]);
        i++;
        j--;
    }
}

//Function to add very large numbers represented as strings
void addLargeNumbers(const char* num1,const char* num2,char* res)
{
    char n1[MAX],n2[MAX]; 

    //copy the input to the buffer 
    strcpy(n1,num1);
    strcpy(n2,num2);

    //reverse the string( Addition happens from LSB-> MSB)
    reverse(n1); 
    reverse(n2); 

    int len1 = strlen(n1);
    int len2 = strlen(n2);

    int i=0,carry=0; 
    for(;i<len1 ||i<len2 || carry;i++)
    {
        //convert the char to digits 
        int digit1 = (i<len1) ? n1[i]-'0' : 0;
        int digit2 = (i<len2) ? n2[i]-'0' : 0;
        
        int sum = digit1 + digit2 + carry; 

        //convert int to char and store the result
        res[i] = (sum%10) + '0';
        carry     = sum / 10; 
    }
    res[i] = '\0'; 
    reverse(res);
}

int main()
{
    char num1[MAX],num2[MAX]; 
    char result[MAX];

    printf("Enter the first very long number: \n"); 
    scanf("%s",num1); 

    printf("Enter the second very long number: \n"); 
    scanf("%s",num2);

    addLargeNumbers(num1,num2,result);

    printf("Sum = %s\n",result);

    return 0;
}