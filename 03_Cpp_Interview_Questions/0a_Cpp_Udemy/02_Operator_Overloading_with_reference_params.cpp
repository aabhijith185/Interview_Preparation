#include<iostream> 
#include<string>

//Examples 
// void say_my_name(const std::string& name)
// {
//     std::cout<<"Your name is (ref): "<<name<<std::endl;
// }

// void say_my_name(std::string& name)
// {
//     std::cout<<"Your name is (non ref): "<<name<<std::endl;
// }

//Implicit conversions 
double max(double a,double b)
{
    std::cout<<"Double max called "<<std::endl;
    return (a>b)?a:b;
}

// int& max(int& a,int& b) 
const int& max(const int& a,const int& b)//Implicit conversions work only well with const referencesl
{
    std::cout<<"Int max called "<<std::endl;
    return (a>b)?a:b;
}




int main()
{
    // std::string name{"John"}; 
    // say_my_name(name);//non ref call
    // say_my_name("John");//ref call:- Implicit conversion from std::string to string literal 
    char a{6}; 
    char b{9};

    auto result = max(a,b);
    return 0;
}