#include<iostream>
#include<vector> 
#include<algorithm>
#include<unordered_map>

using namespace std; 

int main(void)
{
    vector<int> v = {1,3,2,1,2,3,3,3,2,1,2};
    unordered_map<int,int> freq; 

    for(auto x : v) freq[x]++; 

    for(auto &p : freq)
        cout<<p.first<<" -> "<<p.second<<endl;

    return 0;
}