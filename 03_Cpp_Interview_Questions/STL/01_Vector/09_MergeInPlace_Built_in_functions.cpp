#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

void mergeInPlace(vector<int> &a,vector<int> &b)
{
    //append all elemeents of b into A 
    a.insert(a.end(),b.begin(),b.end());
    sort(a.begin(),a.end());
}

void display(const vector<int> &vec)
{
    for(auto i : vec)
        cout<<i<<" ";
    cout<<endl;
}
int main(void)
{
    vector<int> a = {1,3,5,7};
    vector<int> b = {2,4,6,8};

    mergeInPlace(a,b);
    display(a);
    return 0;
}