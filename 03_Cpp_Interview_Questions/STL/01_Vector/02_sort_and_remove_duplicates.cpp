#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 

void display(const vector<int> &v)
{
    for(auto i : v)
        cout<<i<<" "; 
    cout<<endl;
}


int main()
{
    vector<int> v = {1,4,2,3,3,2,2,5,4,7,7}; 

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());//erase from the iterator return by unique till end
    display(v);
    return 0;
}