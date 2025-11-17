#include<iostream> 
#include<cstring>
using namespace std; 

template <typename T> T maximum(T a ,T b)
{
    return (a>b)? a : b;
}
//template specialization for const char *
template<>
const char *maximum<const char*>(const char* a,const char* b)
{
    return (std::strcmp(a,b)>0)? a : b;
}


int main(void)
{
    int a{10},b{23}; 
    double c{34.7},d{23.4}; 
    std::string e{"hello"},f{"world"}; 

    int max_int = maximum(a,b); 
    double max_double = maximum(c,d); 
    std::string max_string = maximum(e,f); 

    std::cout<<"Max int : "<<max_int<<std::endl;
    std::cout<<"Max double : "<<max_double<<std::endl;
    std::cout<<"Max string: "<<max_string<<std::endl;

    const char *g{"Wild"};
    const char *h{"Animal"}; 

    //This wont do what you expect without temp specialization 
    std::cout<<"Max(const char*): "<<maximum(g,h)<<std::endl;
    return 0;
}
