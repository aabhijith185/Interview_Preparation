#include<iostream>
#include<vector>
using namespace std; 

void mergeInPlace(vector<int> &a,vector<int> &b)
{
    int m = a.size(); //original size of a 
    int n = b.size(); //original size of b 

    //Resize A so that it can hold the result 
    a.resize(m+n); 

    //Three pointers 
    int i = m-1; //last element of a
    int j = n-1; //last element of b
    int k = m+n-1; //last index of resized A (write Index)

    //Merge from end 
    while(i>=0 && j>=0)
    {
        if(a[i]>b[j])
        {
            a[k] = a[i]; 
            i--;
        }
        else 
        {
            a[k] = b[j];
            j--;
        }
        k--;
    }
    //Copy remaining elements in B 
    while(j>=0)
    {
        a[k] = b[j];
        j--;
        k--;
    }
}
void display(vector<int> &vec)
{
    for(auto i : vec)
        cout<<i<<" ";
    cout<<endl;
}
int main()
{
    vector<int> a = {1,3,5};
    vector<int> b = {2,4,6};

    mergeInPlace(a,b);

    display(a);

    return 0;
}