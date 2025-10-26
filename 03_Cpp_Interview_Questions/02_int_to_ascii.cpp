#include<iostream>
#include<string>
#include<vector>
using namespace std; 

string int_to_ascii(const vector<int>& n)
{
    string res = "";
    for(auto i : n)
        res += static_cast<char>(i); 
    return res; 
}

int main(void)
{
    vector<int> num = {65,66,67,68};  
    cout<<int_to_ascii(num)<<endl;
    return 0;
}