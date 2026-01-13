#include "iostream"
#include "thread"
#include "chrono"
#include "mutex"
#include "atomic"
using namespace std;


atomic<bool> capture(false);
mutex mx;

void capture_image(int device_id)
{
	while(!capture)
	{
		this_thread::yield();     //CPU can execute other threads
	}
	
	unique_lock<mutex> lock(mx);
	cout<<"Camera "<<device_id<<" clicked at "<<chrono::system_clock::now().time_since_epoch().count()<<endl;
	
	lock.unlock();
	
	//Simulate any other work
	this_thread::sleep_for(chrono::seconds(2));
}

int main()
{	
	//Sync two camera devices. 
	thread t1(capture_image,1);
	thread t2(capture_image,2);
	
	cout<<"Image capturing is triggered at : " << chrono::system_clock::now().time_since_epoch().count()<<endl;
	capture = true;
	
	//Wait for treads to finish
	t1.join();
	t2.join();
	
	return 0;

}