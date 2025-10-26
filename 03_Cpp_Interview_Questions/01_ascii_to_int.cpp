#include<iostream>
#include<vector>
using namespace std; 

vector<int> ascii_to_int(const string& s)
{
    vector<int> res;
    for(auto i : s)
    {
        res.push_back(static_cast<int>(i)); 
    }
    return res;
}

void display(const vector<int> &s)
{
    for(auto i : s)
        cout<<i; 
    cout<<endl;
}

int main(void)
{
    char s[] = "122456"; 
    auto res = ascii_to_int(s); 
    display(res);
    return 0;
}
