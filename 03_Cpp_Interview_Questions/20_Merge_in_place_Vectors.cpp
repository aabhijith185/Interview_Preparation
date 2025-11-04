#include<iostream> 
#include<vector> 
using namespace std; 

void mergeInPlace(vector<int>&v1,const vector<int>&v2)
{
    int n1 = v1.size(); 
    int n2 = v2.size(); 

    //Make space in v1 to store the results 
    v1.resize(n1+n2); 

    int i = n1-1; //Last index of orginal v1
    int j = n2-1; //last index of orginal v2
    int k = n1+n2-1;//Last index of resized v1

    //Merge from the end 
    while(i>=0 && j>=0)
    {
        if(v1[i]>v2[j])
            v1[k--] = v1[i--]; 
        else 
            v1[k--] = v2[j--];
    }
    //copy the remaining elements of v2 if any 
    while(j>=0)
        v1[k--] = v2[j--];
}

int main(void)
{
    vector<int> v1 = {1,3,5,7}; 
    vector<int> v2 =  {2,4,6};

    mergeInPlace(v1,v2); 

    for(auto x  : v1)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}