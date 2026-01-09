#include <iostream>
#include <thread>
#include <mutex>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;


bool ready = false;
mutex mtx;
condition_variable cv;

void worker()
{
	//Unique_lock can unlock and relock. First locks the variable here. 
	unique_lock<mutex> lock(mtx);
	
	cout<<"Wait for notification"<<endl;
	//Wait until ready is true, cv.wait() releases the lock and waits for a notification.When notified, it reacquires the lock.
	cv.wait(lock, []{return ready;});
	
	cout<<"worker thread processing"<<endl;

}


int main()
{	
	//Create thread 
	thread t(worker);
	
	//Simulate some work
	this_thread::sleep_for(chrono::seconds(1));
	//Enter critical section
	{
		//Lock to protec ready variable and no need to lock or unlock manualy, hence use lock_guard
		lock_guard<mutex> lock(mtx);
		ready = true;
	}
	
	//notify worker thread
	cout<<"Notify Worker thread"<<endl;
	cv.notify_one();
	
	t.join();
	return 0;
	
}