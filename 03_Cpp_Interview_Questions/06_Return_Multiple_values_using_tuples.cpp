#include<iostream>
#include<string>
#include<tuple>
using namespace std; 

//function returning tuple containing int char and string 
std::tuple<int,char,std::string> fun(bool flag)
{
    if(flag)
        return make_tuple(1,'x',"Abhijith"); 
    else 
        return make_tuple(2,'y',"Abhishek");
}

int main()
{
    int num; 
    char code;
    string name; 

    //unpack tuple and store the return value into 3 variables 
    tie(num,code,name) = fun(true); 
    cout<<"Num : "<<num<<", Code : "<<code<<", Name : "<<name<<endl;

    tie(num,code,name) = fun(false); 
    cout<<"Num : "<<num<<", Code : "<<code<<",Name : "<<name<<endl;

    return 0;
}

