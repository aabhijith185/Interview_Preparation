#include<iostream> 
#include<thread> 

using namespace std;

void recursiveThread(int d)
{
    if(d==0) return; 

    cout<<"Thread at depth: "<<d<<endl;

    std::thread t(recursiveThread,d-1); 
    t.join();
}

int main(void)
{
    recursiveThread(3);
    return 0;
}