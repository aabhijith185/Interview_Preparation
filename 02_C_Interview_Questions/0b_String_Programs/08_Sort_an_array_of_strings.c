#include <stdio.h>
#include <string.h>


void sort(char A[][20],int n)
{
    char tmp[20];
    
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(strcmp(A[i],A[j])>0)
            {
                strcpy(tmp,A[i]); 
                strcpy(A[i],A[j]);
                strcpy(A[j],tmp);
            }
        }
    }
}

int main(void)
{
    char A[5][20] = {"carrot","banana","apple","grapes","apricot"};
    
    //Before sorting 
    for(int i=0;i<5;i++)
        printf("%s, ",A[i]);
    printf("\n");
    
    sort(A,5);
    //After sorting 
    for(int i=0;i<5;i++)
        printf("%s, ",A[i]);
    printf("\n");
    
    return 0;
}