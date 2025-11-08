#include<iostream>
#include<vector> 
#include<algorithm> 

using namespace std; 

void reverse_vector(vector<int> &v)
{
    int i=0; 
    int j=v.size()-1; 
    while(i<j)
    {
        swap(v[i++],v[j--]);
    }
}
void display(vector<int> &v)
{
    for(auto i : v)
        cout<<i<<" "; 
    cout<<endl;
}

int main(void)
{
    vector<int> v = {1,2,3,4};
    reverse_vector(v); 
    display(v);
    return 0;
}