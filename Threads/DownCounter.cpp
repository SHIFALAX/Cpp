#include <iostream>
#include <thread>
using namespace std;

void DownCounter(int num)
{
	cout<<"Staring countdownThread"<<endl;
	//Decrement num 
	while(num>0)
	{
		cout<<" Decrementing count from : " << num << " to : "<<--num<<endl;
	}
}

int main()
{
	
	cout<<"Staring main thread"<<endl;
	
	//Create thread
	thread countdownThread(DownCounter,5);
	
	//Wait for t1 to finish
	countdownThread.join();

	cout<<"Main and countdownThread finished"<<endl;
	
	return 0;
}