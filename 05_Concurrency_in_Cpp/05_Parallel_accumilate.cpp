#include<iostream> 
#include<thread> 
#include<vector> 
#include<algorithm>
#include<numeric>
#include<functional>

void sequential_accumulate_test()
{
    std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
    int sum = std::accumulate(v.begin(),v.end(),0);
    int product = std::accumulate(v.begin(),v.end(),1,std::multiplies<int>());
    //dash fold the vector 
    auto dash_fold = [](std::string a,int b)
    {
        return std::move(a) + "-" +std::to_string(b);
    };

    std::string s= std::accumulate(std::next(v.begin()),v.end(),std::to_string(v[0]),dash_fold);

    std::cout<<"Sum - "<<sum<<std::endl;
    std::cout<<"Product- "<<product<<std::endl;
    std::cout<<"Dashfold- "<<s<<std::endl;
}
template<typename iterator,typename T> 
void accumulate(iterator start,iterator end,T &ref)
{
    ref = std::accumulate(start,end,0);
}

#define MIN_BLOCK_SIZE 1000 
template<typename iterator,typename T>
T parallel_accumulate(iterator start,iterator end,T &ref)
{
    //get input size 
    int input_size = std::distance(start,end);
    //calculate number of threads 
    int allowed_threads_by_elements = (input_size)/MIN_BLOCK_SIZE;
    //parallel threads supported by hardware 
    int allowed_threads_by_hardware = std::thread::hardware_concurrency();

    //actual number of threads 
    int num_threads = std::min(allowed_threads_by_elements,allowed_threads_by_hardware);
    //block size passed on to each thread 
    int block_size = (input_size+1)/num_threads;

    std::vector<T> results(num_threads); 
    std::vector<std::thread> threads(num_threads-1);//stores the result returned by each thread

    //launch threads with correct data blocks 
    iterator last; 
    for(int i=0;i<num_threads-1;i++)
    {
        last = start; 
        std::advance(last,block_size);//increment the last iterator by block_size amount 
        threads[i] = std::thread(accumulate<iterator, T>,start,last,std::ref(results[i]));//updatest the result vector with result 
        //update start with the end pointer of current iteration 
        start = last; 
    }
    results[num_threads-1] = std::accumulate(start,end,0);

    //join the threads 
    std::for_each(threads.begin(),threads.end(),std::mem_fn(&std::thread::join));

    return std::accumulate(results.begin(),results.end(),ref);
}

int main(void)
{
    const int size = 8000; 
    int *my_array = new int[size]; 
    int ref = 0; 

    srand(0);

    for(size_t i =0;i<size;i++)
    {
        my_array[i] = rand()%10;
    }

    int rer_val = parallel_accumulate<int*,int>(my_array,my_array+size,ref); 
    std::cout<<"Accumilated value "<<rer_val<<std::endl;

    return 0;
}
