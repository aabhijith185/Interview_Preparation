/* 
i/p: {5,5,5,2,2,9}
o/p: [(5,3),(2,2),(9,1)]
*/
//compress consecutive repeated values 
#include<iostream>
#include<vector> 
using namespace std; 

std::vector<std::pair<int,int>> compress(const std::vector<int> & v)
{
    std::vector<std::pair<int,int>> out; 
    if(v.empty()) return out; 

    int current = v[0]; 
    int count =1; 
    for(int i=1;i<v.size();i++)
    {
        if(current == v[i])
            count++;
        else 
        {
            out.push_back({current,count});//save the element and count 
            current = v[i]; //new value 
            count =1;
        }
    }

    out.push_back({current,count}); //Store the last group 
    return out;
}

void display(std::vector<std::pair<int,int>> &vec)
{
    for(auto i : vec)
    {
        cout<<"("<<i.first<<","<<i.second<<"), ";
    }
    cout<<endl;
}

int main(void)
{
    vector<int> v  = {5,5,5,2,2,9}; 
    auto res = compress(v);
    display(res);
    return 0;
}