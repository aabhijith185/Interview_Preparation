/* 
i/p:- {1,2,3,4,5} k=2 
o/p:- {4,5,1,2,3}
*/
#include<iostream> 
#include<vector> 
#include<algorithm>
using namespace std; 

vector<int> rotate_by_right(vector<int> vec,int k)
{
    //reverse the entire vector 
    reverse(vec.begin(),vec.end()); // 5,4,3,2,1
    //reverse first k character 
    reverse(vec.begin(),vec.begin()+k); //4,5 ,3,2,1
    //reverse remaining characters 
    reverse(vec.begin()+k,vec.end());

    return vec;
}

vector<int> rotate_by_left(vector<int> vec,int k)
{
    int n = vec.size(); 
    return rotate_by_right(vec,n-k);
}

void display(const vector<int>& vec)
{
    for(auto i : vec)
        cout<<i<<" "; 
    cout<<endl;
}
int main(void)
{
    vector<int> vec = {1,2,3,4,5};
    auto res = rotate_by_right(vec,2);
    display(res); 
    res = rotate_by_left(vec,2); 
    display(res);

    return 0;
}