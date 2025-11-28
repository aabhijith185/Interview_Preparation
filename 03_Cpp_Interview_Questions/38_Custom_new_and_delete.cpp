#include<iostream> 
#include<cstdlib> 

void *operator new(size_t size)
{
    std::cout<<"[Custom new] allocating "<<size<<"bytes"<<std::endl;
    void *p = std::malloc(size); 
    if(!p)
        throw std::bad_alloc{}; 
    return p;
}

void operator delete(void *p)noexcept
{
    std::cout<<"[Custom delete]Freeing memory "<<std::endl;
    std::free(p);
}

int main()
{
    int *p = new int[10]; 
    delete p;

    return 0;
}