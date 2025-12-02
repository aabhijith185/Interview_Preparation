#include<iostream> 
#include<map> 
using namespace std; 

int main()
{
    multimap<int,string> mp; 

    mp.insert({10,"apple"}); 
    mp.insert({10,"banana"}); 
    mp.insert({10,"apple"}); 
    mp.insert({20,"grapes"}); 

    cout<<"Contents of multimap(ordered)"<<endl; 

    for(auto &p : mp){
        cout<<p.first<<"->"<<p.second<<endl;
    }

    //Values with key 10 
    auto range = mp.equal_range(10); //returns pair<iterator,iterator> 

    /* range.first -> iterator to first element with key =10
       range.second -> iterator to the element after last element with key =10
    */
    for(auto it = range.first;it!=range.second;++it)
        cout<<it->second<<endl;

    return 0;
}