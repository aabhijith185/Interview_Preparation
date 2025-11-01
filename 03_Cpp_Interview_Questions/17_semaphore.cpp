#include<iostream>
#include<thread>
#include<semaphore>
#include<vector>
#include<chrono>

std::counting_semaphore<3> connectionPool(3); //3 connection 
void useDatabase(int id)
{
    std::cout<<"Client "<<id<<"Waiting for db connection..."<<std::endl;

    connectionPool.acquire(); //Wait for available connection 

    std::cout<<"Client "<<id<<"got a db connection "<<std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2)); //simulate db work 
    std::cout<<"Client "<<id<<"releases  db connection "<<std::endl;

    connectionPool.release(); //release connection
}
int main()
{
    std::vector<std::thread> clients; 

    for(int i=0;i<6;i++)
        clients.emplace_back(useDatabase,i);

    for(auto &c : clients)
        c.join();
    return 0;
}