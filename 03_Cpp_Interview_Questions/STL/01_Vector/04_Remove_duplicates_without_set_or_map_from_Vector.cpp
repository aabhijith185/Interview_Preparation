/* 
input : {1,2,3,2,4,1,5};
output : {1,2,3,4,5}; 
*/
#include<iostream> 
#include<vector> 
using namespace std; 

vector<int> removeDuplicates(vector<int> &v)
{
    for(size_t i=0;i<v.size();i++)
    {
        for(size_t j = i+1;j<v.size();j++)
        {
            if(v[i]==v[j])
                v.erase(v.begin() + j);//erase the duplicate element 
        }
    }
    return v;
}

void display(const vector<int> &vec)
{
    for(auto i : vec)
        cout<<i<<" "; 
    cout<<endl;
}

int main(void)
{
    vector<int> v = {1,2,3,2,4,1,5};
    auto res = removeDuplicates(v); 
    display(res); 

    return 0;
}