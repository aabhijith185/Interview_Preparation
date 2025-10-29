#include<stdio.h>
#include<stdbool.h>
#include<string.h>

//utility function to reverse character 
void reverse(char *str,int l,int h)
{
    while(l<h)
    {
        str[l] = str[l] ^ str[h]; 
        str[h] = str[l] ^ str[h]; 
        str[l] = str[l] ^ str[h];

        l++; 
        h--;
    }
}

//Left rotate by K positions 
void leftRotate(char *str,int k)
{
    int n = strlen(str); 
    k = k%n; //handles k >n; 
    //abcdefg k = 2 => cdefg ab
    //reverse first k characters 
    reverse(str,0,k-1);// ba cdefg
    //reverse the remaining character(k,n-1)
    reverse(str,k,n-1); //ba gfedc
    //reverse the entire string 
    reverse(str,0,n-1);
}

//Right rotate by k positions 
void rightRotate(char *str,int k)
{
    int n = strlen(str); 
    k = k%n;
    leftRotate(str,n-k);
}


int main(void)
{
    char str1[10] = "Abhijith"; 
    char str2[10] = "jithAbhi"; 
    
    leftRotate(str1,2); 
    rightRotate(str2,4);
    
    printf("Left Rotation (k=2): %s\n",str1);
    printf("Right Rotation (k=4): %s\n",str2);
   
    return 0;
}