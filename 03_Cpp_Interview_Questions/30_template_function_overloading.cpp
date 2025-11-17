#include<iostream> 
#include<cstring> 

//Function Template 
template<typename T> T maximum(T a,T b){
    std::cout<<"Template overload called(T) "<<std::endl;
    return (a>b)?a:b;
}
//A raw overload which takes precedence over any template instance 
/*
const char* maximum(const char* a,const char* b)
{
    std::cout<<"Raw overload called "<<std::endl;
    return (std::strcmp(a,b)>0)?a:b;
}
*/
//Overload through templates. Will take precedence over T 
template<typename T> T* maximum(T*a ,T*b)
{
    std::cout<<"Template overload called(T*) "<<std::endl;
    return(*a>*b)? a : b;
}

int main()
{
    const char* g{"Wild"};
    const char* h{"Animal"}; 

    std::cout<<"Max(const char*): "<<maximum(g,h)<<std::endl;
    return 0;
}

