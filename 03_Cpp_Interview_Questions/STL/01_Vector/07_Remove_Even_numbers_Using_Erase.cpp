#include<iostream>
#include<vector> 
using namespace std; 

void removeEven(vector<int> &vec)
{
    for(auto it = vec.begin();it!=vec.end();)
    {
        if(*it % 2 == 0)
            it =vec.erase(it); //Erase returns the next iterator
        else 
            ++it;
    }
}

void display(const vector<int> &vec)
{
    for(auto i : vec)
        cout<<i<<" ";
    cout<<endl;
}
int main(void)
{
    vector<int> v = {1,2,3,4,5,6};
    removeEven(v);
    display(v);
    return 0;
}