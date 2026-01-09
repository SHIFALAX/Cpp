#include<iostream>
#include<thread>
#include<chrono>
using namespace std;

void printnums()
{
    cout<<"t1 thread started"<<endl;
    int num = 1;
	
	//Print numbers from 1 to 10
    while(num<=10)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout<<"Value of num is : "<<num<<endl;
        num++;
    }
}

int main()
{
	int count = 10;
	
	//Creating  thread
    std::thread t1(printnums);
	
    std::cout<<"Main running"<<endl;
	//Print numbers from 10 to 1 
    while(count>0)
    {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cout<<"Value of count is : "<< count<<std::endl;
        count--;
    }
	
	//Wait until thread is completed
    t1.join();
    cout<<"main thread and t1 thread finished"<<endl;
    
    return 0;
}