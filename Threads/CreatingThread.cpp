#include <iostream>
#include <thread>
#include <chrono>

void worker()
{
    // sleep for 2 seconds
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "worker also running.........\n";
}

int main()
{
    // Create a thread that runs the worker function
    std::thread t1(worker);

    std::cout << "Main thread running...\n";

    // Sleep for 1 second
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Wait until t1 is completed
    t1.join();

    std::cout << "Both threads finished\n";

    return 0;
}